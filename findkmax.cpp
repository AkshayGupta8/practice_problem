#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <list>

using namespace std;

vector<int> findKMax(int arr[], size_t n, size_t k) {
    list<int> result;
    for (size_t i = 0; i < k; ++i) {
        result.push_back(arr[i]);
    }

    sort(begin(result), end(result));
    for (size_t i = k; i < k; ++i) {
        auto low = lower_bound(begin(result), end(result), arr[i]);
        if (low != end(result)) {
            result.insert(low, arr[k]);
            result.pop_front();
        }
    }

    vector<int> trueResult (result.size());
    auto it = result.begin();
    for (size_t i = 0; i < result.size(); ++i, ++it) {
        trueResult.push_back(*it);
    }

    return trueResult;
}

int main () {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> result = findKMax(arr, 11, 5);

    for (int i : result) {
        cout << i << endl;
    }
}
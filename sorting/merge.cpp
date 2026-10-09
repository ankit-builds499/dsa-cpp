#include <bits/stdc++.h>
using namespace std;

// Merge sorted arr[low..mid] and sorted arr[mid+1..high]
void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> merged;
    int i = low, j = mid + 1;

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) merged.push_back(arr[i++]);
        else                  merged.push_back(arr[j++]);
    }
    while (i <= mid)  merged.push_back(arr[i++]);
    while (j <= high) merged.push_back(arr[j++]);

    for (int k = 0; k < (int)merged.size(); k++) {
        arr[low + k] = merged[k];
    }
}

// Sort arr[low..high] (inclusive) recursively
void mergeSort(vector<int>& arr, int low, int high) {
    if (low >= high) return;             // 0 or 1 element is already sorted

    int mid = low + (high - low) / 2;    // avoids overflow of (low + high)
    mergeSort(arr, low, mid);            // sort first half
    mergeSort(arr, mid + 1, high);       // sort second half
    merge(arr, low, mid, high);          // merge both sorted halves
}

int main() {
    int n;
    cout << "enter the number of elements : ";
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cout << "enter the " << i + 1 << " element : ";
        cin >> arr[i];
    }

    if (n > 0) mergeSort(arr, 0, n - 1);

    cout << "sorted array : ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    return 0;
}
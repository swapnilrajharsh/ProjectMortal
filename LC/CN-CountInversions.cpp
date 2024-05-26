#include <bits/stdc++.h>

int merge(long long *arr, int low, int mid, int high) {
    int cnt = 0;
    vector<long long> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
            cnt += (mid - left + 1);
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
    return cnt;
}

int mergeSort(long long *arr, int low, int high) {
    int result = 0;
    if (low >= high) return result;
    int mid = (low + high) / 2 ;
    result += mergeSort(arr, low, mid);  // left half
    result += mergeSort(arr, mid + 1, high); // right half
    result += merge(arr, low, mid, high);  // merging sorted halves
    return result;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    int result = mergeSort(arr, 0, n-1);
    return result;
}
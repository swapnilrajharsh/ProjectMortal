class Solution {
public:
    void merge(vector<int> &arr, int low, int mid, int high) {
    
        vector<int> temp; // temporary array
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
    
    }

    int countReversePairs(vector<int> &arr, int low, int mid, int high) {
        int result = 0, right = mid+1;

        for (int i=low; i<=mid; i++) {
            while (right <= high && (long)arr[i] > 2*(long)arr[right]) right++;
            result += right - mid - 1;
        }

        return result;
    }
    
    int mergeSort(vector<int> &arr, int low, int high) {
        int result = 0;
        if (low >= high) return result;
        int mid = (low + high) / 2 ;
        result += mergeSort(arr, low, mid);  // left half
        result += mergeSort(arr, mid + 1, high); // right half
        result += countReversePairs(arr, low, mid, high);
        merge(arr, low, mid, high);  // merging sorted halves
        return result;
    }

    int reversePairs(vector<int>& nums) {
        int result = mergeSort(nums, 0, nums.size()-1);
        return result;
    }
};
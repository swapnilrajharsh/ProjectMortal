class Solution {
    // O(logN)
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // Initialize left and right Index
        int leftIndex = 1;
        int rightIndex = arr.size() - 1;

        // Array has 3 elements, then it is guaranteed 
        // that 2 element is the index of mountain
        if (leftIndex == rightIndex)
            return 1;
        int mid = (leftIndex + rightIndex)/2;
        while ( leftIndex < rightIndex ) {
            /** Total 3 Cases
            * 1. Peak
            * 2. Left to the Peak - Increasing Order
            * 3. Right to the Peak - Decreasing Order
            */
            mid = (leftIndex + rightIndex)/2;
            // Case 1
            if ( arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
                return mid;
            else if (arr[mid] > arr [mid - 1] && arr[mid] < arr[mid + 1]) { // Case 2 
                // Solution does not exist in left to mid index
                // hence, solve mid+1 to right
                leftIndex = mid;
            } else { // Case 3
                rightIndex = mid;
            }
        }
        return mid;
    }
};
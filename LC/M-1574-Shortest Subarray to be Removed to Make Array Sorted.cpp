class Solution {
public:
    void printLog(int value, string msg){
        bool debug = false;
        if (debug) {
            cout<<msg<< " : " << value<<endl;
        }
    }
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int len = arr.size();
        int leftSubArrayIndex = 0;
        int rightSubArrayIndex = len - 1;

        for (int i=0; i<len-1; i++) {
            if (arr[i]<=arr[i+1]){
                leftSubArrayIndex++;
            } else {
                break;
            }
        }
        printLog(leftSubArrayIndex, "Left ");
        if (leftSubArrayIndex == len - 1) {
            return 0; // Array already sorted
        }

        for (int i=len-1; i>0; i--) {
            if (arr[i]>=arr[i-1]){
                rightSubArrayIndex--;
            } else {
                break;
            }
        }
        printLog(rightSubArrayIndex, "Right ");
        // To decide what to choose between left & right subarray.
        int result = min(len-leftSubArrayIndex-1, rightSubArrayIndex);
        printLog(result, "Before Loop ");
        // Check if any overlapping Sub array between left and right
        // sub array is the desired array
        
        for (int i=0; i<=leftSubArrayIndex; i++) {
            while (i < leftSubArrayIndex && arr[i] == arr[i+1])
                i++;
            int j = rightSubArrayIndex;
            while (j <= len-1) {
                if (arr[i] <= arr[j]){
                    printLog(i, " L ");
                    printLog(arr[i], "Value L ");
                    printLog(j, " R ");
                    printLog(arr[j], "Value R ");
                    result = min(result, j-i-1);
                    printLog(result, "Within Loop : ");
                    j++;
                    break;
                }
                j++;
            }
            
        }

        return result;

    }
};
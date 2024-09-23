class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        int result = 0;
        int k = 0;
        unordered_map<long long, int> prefixSum;
        prefixSum[0] = -1;
        long long sum = 0;
        for (int i=0; i<arr.size(); i++) {
            sum += arr[i];
            
            if (prefixSum.find(sum-k) != prefixSum.end()) {
                int length = i - prefixSum[sum-k];
                result = max(result, length);
            }
            
            if (prefixSum.find(sum) == prefixSum.end())
                prefixSum[sum] = i;
        }
        
        return result;
    }
};
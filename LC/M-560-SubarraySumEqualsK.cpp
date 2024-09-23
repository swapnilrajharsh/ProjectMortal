class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefixSum = 0, resultCount = 0;
        unordered_map<int, int> resultMap; // (Sum, Count) pair

        resultMap[0] = 1;

        for (int num : nums) {
            prefixSum += num;

            resultCount += resultMap[prefixSum - k];
            resultMap[prefixSum] += 1;
            
        }

        return resultCount;
    }
};
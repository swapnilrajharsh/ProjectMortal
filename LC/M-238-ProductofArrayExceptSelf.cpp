class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size() == 1 || nums.size() == 0)
            return vector<int> {0};
        vector<int> result (nums.size(), 1);

        // Calculate product till (i-1)th position - Left
        int mul = 1;
        for (int index = 0; index < nums.size(); index++) {
            result[index] = mul;
            mul *= nums[index];
        }

        // Calculate product from (i+1)th position - Right
        mul = 1;
        for (int index = nums.size()-1; index >= 0; index--) {
            result[index] *= mul;
            mul *= nums[index];
        }

        return result;
    }
};
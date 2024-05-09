class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int chngIdx = -1;
        for (int idx = nums.size()-2; idx >= 0; idx-- ){
            if (nums[idx] < nums[idx+1]) {
                chngIdx = idx;
                break;
            }
        }
        if(chngIdx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int idx = nums.size()-1; idx > chngIdx; idx-- ){
            if (nums[idx] > nums[chngIdx]) {
                int temp = nums[idx];
                nums[idx] = nums[chngIdx];
                nums[chngIdx] = temp;
                break;
            }
        }

        reverse(nums.begin() + chngIdx + 1, nums.end());

        return;
    }
};
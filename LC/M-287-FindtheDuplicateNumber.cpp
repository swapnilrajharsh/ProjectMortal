class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slowPtr = nums[0], fastPtr = nums[0];

        do{
            slowPtr = nums[slowPtr];
            fastPtr = nums[nums[fastPtr]];
        } while (slowPtr != fastPtr);

        // After Point of collision
        fastPtr = nums[0];
        while (slowPtr != fastPtr) {
            slowPtr = nums[slowPtr];
            fastPtr = nums[fastPtr];
        }

        return fastPtr;
    }
};
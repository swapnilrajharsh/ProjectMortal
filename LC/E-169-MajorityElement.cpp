class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = nums[0], count = 0;

        for (int num : nums) {
            if (count == 0) {
                element = num;
            }

            if (element == num) {
                count++;
            } else {
                count--;
            }
        } 

        return element;
    }
};
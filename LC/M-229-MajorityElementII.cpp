class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int elem1 = INT_MIN, elem2 = INT_MIN+1, cnt1 = 0, cnt2 = 0;

        if (nums.size() == 1)
            return {nums[0]};

        for (int num : nums) {
            if (cnt1 == 0 && num != elem2) {
                elem1 = num;
                cnt1++;
            }
            else if (cnt2 == 0 && num != elem1){
                elem2 = num;
                cnt2++;
            }
            else if (elem1 == num)
                cnt1++;
            else if (elem2 == num)
                cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }

        int majority = nums.size()/3;
        cnt1=0, cnt2=0;
        for (int num : nums) {
            if(elem1 == num)
                cnt1++;
            else if(elem2 == num)
                cnt2++;
        }
        if (cnt1 > majority && cnt2 > majority)
            return {elem1, elem2}; 
        else if (cnt1 > majority && cnt2 <= majority)
            return {elem1};
        else if (cnt1 <= majority && cnt2 > majority)
            return {elem2};
        else
            return vector<int>(); 
    }
};
class Solution {
public:

    void findSubsetsWithDup(vector<vector<int>>& result, 
                vector<int> temp, int index, int size, vector<int>& nums) {

        result.push_back(temp);

        for(int i=index; i<size; i++) {
            if (i!=index && nums[i] == nums[i-1])
                continue;
            
            temp.push_back(nums[i]);
            findSubsetsWithDup(result, temp, i+1, size, nums);
            temp.pop_back();
        }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        findSubsetsWithDup(result, temp, 0, nums.size(), nums);

        return result;
    }
};
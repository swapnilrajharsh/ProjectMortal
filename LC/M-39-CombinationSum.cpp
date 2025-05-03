class Solution {
    public:
    
        void findCombination(int target, vector<int>& candidates, vector<int> temp,
         vector<vector<int>>& result, int index) {
            
            if(index == candidates.size()) {
                if (target == 0) result.push_back(temp);
                return;
            }
    
            if(candidates[index] <= target) {
                temp.push_back(candidates[index]);
                findCombination(target-candidates[index], candidates, temp, result, index);
                temp.pop_back();
            }
            
            findCombination(target, candidates, temp, result, index+1);
        }
    
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<int> temp;
            vector<vector<int>> result;
    
            findCombination(target, candidates, temp, result, 0);
            return result;
        }
    };
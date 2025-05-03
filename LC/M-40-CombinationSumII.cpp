#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
    public:
        Solution() = default;
        void findCombinationSum(vector<int>& candidates, int target, int index,
            vector<vector<int>>& result, vector<int>& elements){
                if (target == 0) {
                    result.push_back(elements);
                    return;
                }
            if (index == candidates.size()) return;
    
            for (int i=index; i<candidates.size(); i++) {
                if (i!=index && candidates[i] == candidates[i-1]) continue;
    
                if (candidates[i] > target) break;
    
                elements.push_back(candidates[i]);
                findCombinationSum(candidates, target-candidates[i], i+1, result, elements);
                elements.pop_back();
            }
    
        }
    
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            sort(candidates.begin(), candidates.end());
    
            vector<vector<int>> result;
            vector<int> elements;
    
            int index = 0;
            findCombinationSum(candidates, target, index, result, elements);
    
            return result;
        }
    };

int main() {

    Solution s1 = Solution{};
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;

    vector<vector<int>> result = s1.combinationSum2(candidates, target);
    for (auto elem : result) {
        cout<<"[ ";
        for (auto item : elem) {
            cout<<item<<" ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}
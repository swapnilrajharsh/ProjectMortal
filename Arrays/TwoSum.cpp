class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
        
        int size = nums.size();
        std::vector<int> result;
        //Using ordered map to store value and its index - find will take O(logN)
        //unordered map will find element in O(1)
        std::map<int, int> complementNumMap;
        
        for (int i=0; i<size; i++) { //O(N)
          
          if (complementNumMap.find(target-nums[i]) != complementNumMap.end()) { // O(logN)
            result.push_back(complementNumMap[target-nums[i]]);
            result.push_back(i);
            return result;
          }

          complementNumMap.insert({nums[i], i});
        
        }

        return {};

    }

    // Total TimeComplexity = O(NlogN)
};
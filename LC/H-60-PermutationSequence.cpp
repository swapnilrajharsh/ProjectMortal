#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
    public:
        int findFactorial(int n) {
            int factorial = 1;
    
            for (int i=1; i<=n; i++) {
                factorial *= i;
            }
    
            return factorial;
        }
    
        string getPermutation(int n, int k) {
    
            string result = "";
            int totalPermutation = findFactorial(n);
            int stringLength = n;
            k--; // 0 based indexing when taking modulo or divide
            
            vector<int> nums;
            for (int i=1; i<=n; i++) nums.push_back(i);
    
            int groupPermutationCount = totalPermutation;
            while(nums.size() > 1) {
                groupPermutationCount = groupPermutationCount/stringLength;
                int selectedIndex = k/groupPermutationCount;
    
                result += to_string(nums[selectedIndex]);
                nums.erase(nums.begin()+selectedIndex);
    
                k = k%groupPermutationCount;
                stringLength--;
            }
            result += to_string(nums[0]);
    
            return result;
            
        }
    };

int main() {

    Solution s1;
    cout<< "Answer: " << s1.getPermutation(4,12) << endl;

    return 0;
}
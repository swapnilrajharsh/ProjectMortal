#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
    private:
        bool isPalindrome(string s) {
            int startIndex = 0, endIndex = s.length()-1;
            while (startIndex <= endIndex) {
                if (s[startIndex] != s[endIndex]) return false;
    
                startIndex++;
                endIndex--;
            }
            
            return true;
        }
    
    public:
        void partitionStringToPalindrome(vector<vector<string>> &result, vector<string> &palindromes,
            int startIndex, string s) {
    
            int stringLength = s.length();
    
            if (startIndex == stringLength) {
                result.push_back(palindromes);
                return;
            }
    
            for(int i=startIndex; i<stringLength; i++){
                if (isPalindrome(s.substr(startIndex, i-startIndex+1))) {
                    palindromes.push_back(s.substr(startIndex, i-startIndex+1));
                    partitionStringToPalindrome(result, palindromes, i+1, s);
                    palindromes.pop_back();
                }
            }
    
        }
    
        vector<vector<string>> partition(string s) {
            vector<vector<string>> result;
            vector<string> palindromes;
    
            partitionStringToPalindrome(result, palindromes, 0, s);
    
            return result;
        }
    };

int main() {

    Solution s1;
    vector<vector<string>> result = s1.partition("aab");

    for (auto results : result) {
        cout<<"[ ";
        for (auto str : results) {
            cout<<str<<" ";
        }
        cout<<"] ";
    }
}
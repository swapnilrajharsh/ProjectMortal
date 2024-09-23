class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int currentLength = 0, result = 0;
        int left = 0, right = 0;
        unordered_map<char, int> characters;
        while (right < s.length()) {
            if (characters.find(s[right]) == characters.end()) {
                characters[s[right]]=right;
                
            } else {
                left=max(left, characters[s[right]]+1);
                characters[s[right]]=right;
                
            }
            currentLength = (right - left + 1);
            // cout<<"L : "<<left<<" & R : "<<right<<"Curr : "<<currentLength<<endl;
            
            right++;
            
            result = max(result, currentLength);

        }

        return result; 
    }
};
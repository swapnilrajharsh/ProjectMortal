class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sLength = s.size();

        int sIdx = 0;
        for (char ch : t) {
            if (ch == s[sIdx])
                sIdx++;
        }

        if (sIdx == sLength)
            return true;

        return false;
    }
};
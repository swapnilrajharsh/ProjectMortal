class Solution {
public:
    string breakPalindrome(string palindrome) {

        if (palindrome.length() == 1)
            return "";

        for (int idx = 0; idx < palindrome.length()/2; idx++) {
            if (palindrome[idx] != 'a') {
                palindrome[idx] = 'a';
                return palindrome;
            }
        }

        for (int idx = palindrome.length()-1; idx >= palindrome.length()/2; idx--){
            if (palindrome[idx] == 'a') {
                palindrome[idx] = 'b';
                return palindrome;
            }
        }
        return palindrome;


        
    }
};
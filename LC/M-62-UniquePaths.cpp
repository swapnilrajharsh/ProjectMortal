class Solution {
public:
    int calculateCombination(int n,int r) {
        
        long long int result = 1;
        for (int i=1; i<=r; i++){
            result *= (n-i+1);
            result /= i;
        }
        return (int)result;
    }
    int uniquePaths(int m, int n) {
        int totalSteps = m+n-2;

        int result = calculateCombination(m+n-2, min(m-1,n-1));
        return result;
    }
};
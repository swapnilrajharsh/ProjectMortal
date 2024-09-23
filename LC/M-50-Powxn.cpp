class Solution {
public:
    double myPow(double x, int n) {
        double result = 1;
        bool isNegative = n < 0 ? true : false ;
        if(n==0)
            return (double)1;
        long long power = n;
        power = power > 0 ? power : -1 * power ;
        while (power > 0) {
            if (power%2==0) {
                x *= x;
                power = power/2;
            } else {
                result *= x;
                power = power-1;
            }
        }

        return isNegative ? (1/result) : result ;

    }
};
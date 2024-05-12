class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, minTillI = INT_MAX;
        for(int price : prices){
            minTillI = min(minTillI, price);
            ans = max(ans, price - minTillI);
        }
        return ans;
    }
};
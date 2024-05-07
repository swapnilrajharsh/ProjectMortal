class Solution {
public:
    static bool lexicoSort(const int num1, const int num2) {
        std::string combOne = std::to_string(num1).append(std::to_string(num2));
        std::string combTwo = std::to_string(num2).append(std::to_string(num1));
        return combOne > combTwo;
    }
    string largestNumber(vector<int>& nums) {
        int numZeros = 0;
        for (int num : nums) {
            if (num == 0)
                numZeros++;
        }
        if (numZeros == nums.size())
            return "0";
            
        std::sort(nums.begin(), nums.end(), lexicoSort);
        std::string result = "";

        for (int num : nums){
            result += to_string(num);
        }

        return result;
    }
};
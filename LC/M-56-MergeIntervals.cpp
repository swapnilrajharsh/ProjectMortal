class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> results;
        results.push_back(intervals[0]);

        for (int idx= 1; idx < intervals.size(); idx++) {
            if (intervals[idx][0] <= results.back()[1]) {
                results.back()[1] = max(intervals[idx][1], results.back()[1]);
            } else {
                results.push_back(intervals[idx]);
            }
        }

        return results;
    }
};
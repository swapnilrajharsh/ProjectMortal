class Solution {
public:

    static bool compFunc(const vector<int>& v1, const vector<int>& v2){
        return v1[1] < v2[1];
    }

    void printFunc(vector<vector<int>> points, bool DEBUG) {
        if (DEBUG) {
            cout<<"[";  
            for (auto vec : points) {
                cout<<"["<<vec[0]<<","<<vec[1]<<"]";
            }
            cout<<"]";
        }
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        bool DEBUG = false;
        sort(points.begin(), points.end(), compFunc);
        printFunc(points, DEBUG);
        
        if (points.size() == 0)
            return 0;

        int answer = 1;
        int minXend = points[0][1];
        for(int i=1; i<points.size(); i++){
            if (points[i][0] <= minXend) {
                minXend = min(minXend, points[i][1]);
                continue;
            }
            minXend = points[i][1];
            answer+=1;
        }
        return answer;
    }
};
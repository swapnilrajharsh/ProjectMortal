//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    struct meeting{
            int startTime, endTime;
        };
        
    static bool compareMeetings(meeting m1, meeting m2) {
        if (m1.endTime < m2.endTime)
            return true;
        return false;
    }
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Creating vector of meetings
        
        vector<meeting> allMeetings;
        int totalMeeting = start.size();
        
        for (int i=0; i<totalMeeting; i++) {
            allMeetings.push_back({start[i], end[i]});
        }
        
        // Sort on the basis of end time
        sort(allMeetings.begin(), allMeetings.end(), Solution::compareMeetings);
        
        int meetCount = 0;
        int currEndTime = -1;
        
        for (auto meeting : allMeetings) {
            if (meeting.startTime > currEndTime) {
                meetCount++;
                currEndTime = meeting.endTime;
            }
        }
        
        return meetCount;
        
        
    }
    
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
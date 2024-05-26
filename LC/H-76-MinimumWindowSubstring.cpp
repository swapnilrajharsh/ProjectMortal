class Solution {
public:
    string minWindow(string s, string t) {
        int FP[256] = {0};
        int FS[256] = {0};

        for (char ch : t) {
            FP[ch]++;
        }

        int start = 0, start_idx = -1, cnt = 0, min_so_far = INT_MAX;
        int curr_window;

        for (int i=0; i<s.length(); i++) {
            FS[s[i]]++;

            if(FP[s[i]] != 0 && FS[s[i]]<= FP[s[i]]) {
                cnt++;
            }

            if(cnt == t.length()){
                while(FP[s[start]]==0 || FS[s[start]] > FP[s[start]]) {
                    FS[s[start]]--;
                    start++;
                }

                curr_window = i - start + 1;
                // cout<<"RECV - "<<s.substr(start, curr_window)<<endl;
                if (curr_window < min_so_far) {
                    start_idx = start;
                    min_so_far = curr_window;
                    // cout<<"ACK - "<<s.substr(start, min_so_far)<<endl;
                }
                
            }
        }

        if (start_idx == -1)
            return "";

        return s.substr(start_idx, min_so_far);
    }
};
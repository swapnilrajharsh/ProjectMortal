class Solution {
public:
    int compress(vector<char>& chars) {
        int answer = 0;
        int charsSize = chars.size();
        bool lastGroup = true;

        if(charsSize == 1)
            return 1;

        if(charsSize == 2 && chars[0] == chars[1] ) {
            chars[1] = '2';
            return 2;
        }

        int groupCount = 1, groupIdx = 1;
        for(int idx = 1; idx < charsSize; idx++ ) {
            
            if (chars[idx] == chars[idx-1] && (idx != (charsSize - 1)) ) {
                groupCount++;
            } else {
                if (idx == charsSize - 1) {
                    if (chars[idx] == chars[idx-1]) 
                        groupCount++;
                    else
                        lastGroup = false;
                }
                    
                if (groupCount > 1) {
                    string groupCountStr = std::to_string(groupCount);
                    // cout<<"Index : "<<idx<< " Val:" <<chars[idx]<<" GId : "<<groupIdx<<endl;
                    for (char c : groupCountStr) {
                        chars[groupIdx++] = c;
                        // cout<<"Index : "<<idx<< " Val:" <<chars[idx]<<" GId : "<<groupIdx<<endl;
                    }
                }
                groupCount = 1;
                if (groupIdx < charsSize ) 
                    chars[groupIdx++] = chars[idx];
                else
                    lastGroup = false;
            }

            
        }

        return lastGroup ? --groupIdx : groupIdx;
    }
};
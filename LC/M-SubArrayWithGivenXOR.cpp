int Solution::solve(vector<int> &A, int B) {
    unordered_map<int, int> preXor;
    preXor[0]=1;
    int mxor = 0, result = 0;
    for(int i=0; i<A.size(); i++) {
        mxor ^= A[i];
        int requiredXor = mxor ^ B;
        if (preXor.find(requiredXor) != preXor.end()) {
            result += preXor[requiredXor];
        } 
        if (preXor.find(mxor) == preXor.end())
            preXor[mxor] = 1;
        else
            preXor[mxor] += 1;
    }
    
    return result;
}

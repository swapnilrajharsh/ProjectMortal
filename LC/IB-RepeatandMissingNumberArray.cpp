vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int xr = 0;
    for(int i=0; i<A.size(); i++){
        xr = xr ^ A[i];
        xr = xr ^ (i+1);
    }
    // cout << "Xor " << xr <<endl;
    
    int diffBitNumber = xr & ~(xr - 1) ;
    // cout<< "Diff "<< diffBitNumber <<endl;
    
    int zeros = 0, ones = 0;
    
    for(int i=0; i<A.size(); i++){
        if((A[i] & diffBitNumber) == 0) { // Zeros Group
            zeros = zeros ^ A[i];
        } else {
            ones = ones ^ A[i];
        }
    }
    for(int i=0; i<A.size(); i++){
        if( ((i+1) & diffBitNumber) == 0 ) { // Zeros Group
            zeros = zeros ^ (i+1);
        } else {
            ones = ones ^ (i+1);
        }
    }
    int cnt = 0;
    for(int i=0; i<A.size(); i++) {
        if(zeros == A[i]) cnt++;
    }
    if(cnt == 2) return {zeros, ones};
    return {ones, zeros};
    
}

class Solution {
public:
     vector<int> getRow( int rowIndex) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector< int> v, v_last;
        rowIndex++;
        v.push_back(1);
        v_last = v;
        if(rowIndex == 1){
            return v;
        }
        for( int i=2; i<=rowIndex; i++){
            v.clear();
            v.push_back(1);
            for( int j=0; j<i-2; j++){
                v.push_back(v_last[j]+v_last[j+1]);
            }
            v.push_back(1);
            v_last = v;
        }
        return v;
    }

};
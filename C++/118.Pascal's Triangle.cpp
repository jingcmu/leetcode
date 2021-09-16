Second Try:
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<int> v;
        if(numRows == 0) {
            return res;
        }
        v.push_back(1);
        res.push_back(v);
        for(int i=1; i<numRows; i++) {
            v.clear();
            v.push_back(1);
            for(int j = 1; j<i; j++) {
                v.push_back(res.back()[j]+res.back()[j-1]);
            }
            v.push_back(1);
            res.push_back(v);
        }
        return res;
        
    }
private:
    vector<vector<int>> res;
};

class Solution {
public:
    vector<vector< int> > generate( int numRows) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector< int> > v_res;
        vector< int> v, v_last;
        if(numRows == 0){
            return v_res;
        }
        v.push_back(1);
        v_last = v;
        v_res.push_back(v);
        for( int i=2; i<=numRows; i++){
            v.clear();
            v.push_back(1);
            for( int j=0; j<i-2; j++){
                v.push_back(v_last[j]+v_last[j+1]);
            }
            v.push_back(1);
            v_last = v;
            v_res.push_back(v);
        }
        return v_res;
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = triangle.size();
        vector<int> v, v_lastrow;
        if(!n){
            return 0;
        }
        v.resize(n);
        v_lastrow.resize(n);
        v[0] = v_lastrow[0] = triangle[0][0];
        for(int i=1; i<n; i++){
            v[0] = triangle[i][0] + v_lastrow[0];
            for(int j=1; j<i; j++){
                v[j] = triangle[i][j] + (v_lastrow[j-1]>v_lastrow[j]?v_lastrow[j]:v_lastrow[j-1]);
            }
            v[i] = triangle[i][i] + v_lastrow[i-1];
            v_lastrow = v;
        }
        return *min_element(v.begin(), v.end());
    }
};
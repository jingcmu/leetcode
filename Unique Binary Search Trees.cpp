//dynamic programming
class Solution {
public :
    int numTrees( int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector< int> v;
        v.resize(n+1);
        if(!n) return 0;
        v[0] = 1;
        for( int i=1; i<=n; i++){
            v[i] = 0;
            for( int j=1; j<=i; j++){
                v[i] += v[j-1]*v[i-j];
            }
        }
        return v[n];
    }
};

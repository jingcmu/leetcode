My solution:
//动态规划+滚动数组
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> v(n, 1);
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                v[j] = v[j] + v[j-1];
            }
        }
        return v[n-1];
    }
};
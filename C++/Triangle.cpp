/*
这个题都做烂了，就是逐层递推，不知道这样的算不算动态规划
*/
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        vector<int> v(n), v_lastrow(n);
		if(n == 0) return 0;
        v[0] = v_lastrow[0] = triangle[0][0];
        for(int i=1; i<n; i++){
            v[0] = triangle[i][0] + v_lastrow[0]; //边上的没得选
            for(int j=1; j<i; j++){
				//选当前节点头顶上的两个节点当中那个小的
                v[j] = triangle[i][j] + min(v_lastrow[j-1],v_lastrow[j]);
            }
            v[i] = triangle[i][i] + v_lastrow[i-1]; //边上的节点
            v_lastrow = v;
        }
		//min_element是stl中的，求一个容器中最小的值，*跟解析指针的用法差不多
        return *min_element(v.begin(), v.end());
    }
};
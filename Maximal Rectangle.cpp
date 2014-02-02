/*
用一个二维数组记录每行到当前点连续1的个数，
然后以每个点为矩阵右下角去计算面积
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int one2now = 0, max_area = 0;
        vector<vector<int> > oneinline(n, vector<int>(m));
        
        for(int i=0; i<n; i++){
            one2now = 0;
            for(int j=0; j<m; j++){
                if(matrix[i][j] == '1'){
                    ++one2now;
                }
                else{
                    one2now = 0;
                }
                oneinline[i][j] = one2now;
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int width = oneinline[i][j];
                if(!width){
                    continue;
                }
                //从当前行往上推,一层层算出最大面积
                for(int k=i; k>=0; k--){
                    width = min(oneinline[k][j], width); //如果当前行的width小则更新width
                    if(!width) break; //width为0,则矩阵中断
                    max_area = max(max_area, width*(i-k+1));
                }
            }
        }
        return max_area;
    }
};
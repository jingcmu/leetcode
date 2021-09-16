/*
��һ����ά�����¼ÿ�е���ǰ������1�ĸ�����
Ȼ����ÿ����Ϊ�������½�ȥ�������
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
                //�ӵ�ǰ��������,һ������������
                for(int k=i; k>=0; k--){
                    width = min(oneinline[k][j], width); //�����ǰ�е�widthС�����width
                    if(!width) break; //widthΪ0,������ж�
                    max_area = max(max_area, width*(i-k+1));
                }
            }
        }
        return max_area;
    }
};
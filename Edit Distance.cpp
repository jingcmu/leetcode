/*
二维动态规划：
设状态为f[i][j]，表示A[0,i] 和B[0,j] 之间的最小编辑距离。
设A[0,i] 的形式是str1c，B[0,j] 的形式是str2d，
1. 如果c==d，则f[i][j]=f[i-1][j-1]；这种情况最简单
2. 如果c!=d，
(a) 如果将c 替换成d，则f[i][j]=f[i-1][j-1]+1； 这种情况第二简单
(b) 如果在c 后面添加一个d，则f[i][j]=f[i][j-1]+1；注意是在c后面添加d，不是前面
(c) 如果将c 删除，则f[i][j]=f[i-1][j]+1；
*/
class Solution {
public:
    #define min(a,b,c) min(a,min(b,c))
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        vector<vector<int> > matrix(len1+1, vector<int>(len2+1));
		//初始化，从word1的空串到word2的最小编辑距离
        for(int i=0; i<=len2; i++){
            matrix[0][i] = i;
        }
		//初始化，从word2的空串到word1的最小编辑距离
        for(int i=0; i<=len1; i++){
            matrix[i][0] = i;
        }
		//取4种情况的最小值
        for(int i=1; i<=len1; i++){
            for(int j=1; j<=len2; j++){
                int flag = (word1[i-1]==word2[j-1]?0:1);
                matrix[i][j] = min(matrix[i-1][j]+1,matrix[i][j-1]+1,
                                   matrix[i-1][j-1]+flag );
            }
        }
		//返回A[0,len1]到B[0,len2]的编辑距离
        return matrix[len1][len2];
    }
};
class Solution {
public:
    #define min(a,b,c) a>(b>c?c:b)?(b>c?c:b):a
    int minDistance(string word1, string word2) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len1 = word1.length(), len2 = word2.length();
        vector<vector<int> > matrix;
        vector<int> v;
        v.resize(len2+1);
        for(int i=0; i<=len1; i++){
            matrix.push_back(v);
        }
        for(int i=0; i<=len2; i++){
            matrix[0][i] = i;
        }
        for(int i=0; i<=len1; i++){
            matrix[i][0] = i;
        }
        for(int i=1; i<=len1; i++){
            for(int j=1; j<=len2; j++){
                int flag = (word1[i-1]==word2[j-1]?0:1);
                matrix[i][j] = min(matrix[i-1][j]+1,matrix[i][j-1]+1,
                                   matrix[i-1][j-1]+flag );
            }
        }
        return matrix[len1][len2];
    }
};
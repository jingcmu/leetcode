class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int row = matrix.size(), inrow = -1;
        if(row == 0) return false;
        int col = matrix[0].size();
        for(int i=0; i<row-1; i++) {
            if(matrix[i+1][0] > target) {
                inrow = i;
                break;
            }
        }
        if(inrow == -1) inrow = row-1;
        for(int i=0; i<col; i++) {
            if(matrix[inrow][i] > target) {
                return false;
            }
            else if(matrix[inrow][i] == target) {
                return true;
            }
        }
        return false;
    }
};
public class Solution {
    public void setZeroes(int[][] matrix) {
        int row = matrix.length;
        if(row == 0) return;
        int col = matrix[0].length;
        boolean flagRow = false, flagCol = false;
        for(int i=0; i<row; i++) {
            if(matrix[i][0] == 0) {
                flagCol = true;
                break;
            }
        }
        for(int j=0; j<col; j++) {
            if(matrix[0][j] == 0) {
                flagRow = true;
                break;
            }
        }
        for(int i=1; i<row; i++) {
            for(int j=1; j<col; j++) {
                if(matrix[i][j] == 0) {
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        for(int i=1; i<row; i++) {
            for(int j=1; j<col; j++) {
                if(matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if(flagRow) {
            for(int j=0; j<col; j++) {
                matrix[0][j] = 0;
            }
        }
        if(flagCol) {
            for(int i=0; i<row; i++) {
                matrix[i][0] = 0;
            }
        }
    }
}
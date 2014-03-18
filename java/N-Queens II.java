public class Solution {
    private int count = 0;
    private boolean check(int[] colArray, int row) {
        for(int i=0; i<row; ++i) {
            int diff = Math.abs(colArray[i] - colArray[row]);
            if(diff == 0 || diff == row - i) {
                return false;
            }
        }
        return true;
    }
    private void placeQueue(int[] colArray, int row, int n) {
        if(row == n) {
            ++count;
            return;
        }
        for(int i=0; i<n; ++i) {
            colArray[row] = i;
            if(check(colArray, row)) {
                placeQueue(colArray, row+1, n);
            }
        }
    }
    public int totalNQueens(int n) {
        int[] colArray = new int[n];
        placeQueue(colArray, 0, n);
        return count;
    }
}
public class Solution {
    public ArrayList<Integer> getRow(int rowIndex) {
        ArrayList<Integer> res = new ArrayList<Integer>();
        ArrayList<Integer> res_next = new ArrayList<Integer>();
        res.add(1);
        if(rowIndex == 0) return res;
        res.add(1);
        if(rowIndex == 1) return res;
        for(int i=2; i<=rowIndex; i++) {
            res_next.add(1);
            for(int j=1; j<i; j++) {
                res_next.add(res.get(j-1) + res.get(j));
            }
            res_next.add(1);
            res.clear();
            res.addAll(res_next);
            res_next.clear();
        }
        return res;
    }
}public class Solution {
    public int uniquePaths(int m, int n) {
        int v[][] = new int[m][n];
        for(int i=0; i<m; i++) {
            v[i][0] = 1;
        }
        for(int j=0; j<n; j++) {
            v[0][j] = 1;
        }
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                v[i][j] = v[i-1][j] + v[i][j-1];
            }
        }
        return v[m-1][n-1];
    }
}
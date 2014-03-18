public class Solution {
    public void help(ArrayList<String> res, String temp, int left, int right, int n) {
        if(left < right || left > n) {
            return;
        }
        if(left == right && left == n) {
            res.add(temp);
        }
        help(res, temp+"(", left+1, right, n);
        help(res, temp+")", left, right+1, n);
    }
    public ArrayList<String> generateParenthesis(int n) {
        ArrayList<String> res = new ArrayList<String>();
        help(res, "", 0, 0, n);
        return res;
    }
}
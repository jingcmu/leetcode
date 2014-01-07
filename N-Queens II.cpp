//省空间了，只用一个长度为n的数组记录每行选的列号，当然用vector也可以
//感觉N-Queens也可以这样做，省空间，而且速度可能更快

class Solution {
public:
	//参数：当前行row，记录每行放置列号的数组colArray
    bool check(int row, int* colArray) {  
		//遍历之前行的放置情况，检查当前
        for (int i = 0; i < row; ++i) {  
            int diff = abs(colArray[i] - colArray[row]); //diff记录列号差
            if (diff == 0 || diff == row - i) {          // int a row or line  
                return false;  
            }  
        }  
        return true;  
    }  
  
    void placeQueens(int row, int n, int &count, int* colArray) {  
        if (row == n) {  
            ++count;  
            return;  
        }  
          
        for (int col = 0; col < n; ++col) {  
            colArray[row] = col;  //尝试每列
            if (check(row, colArray)){ //如果合法则往下递归
                placeQueens(row+1, n, count, colArray);  
            }  
        }  
    }  
      
    int totalNQueens(int n) {  
        int *colArray = new int[n];  
        int count = 0;            
        placeQueens(0, n, count, colArray);            
        return count;  
    } 
};
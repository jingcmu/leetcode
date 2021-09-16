/*
只需要两个vector即可，
用v来进行计算，用v_last来存上一行的
rowIndex是从0th开始算的
*/
class Solution {
public:
     vector<int> getRow( int rowIndex) {
        vector< int> v, v_last;
        rowIndex++; //先加1，从1开始算，这样行数和元素数相等
        v.push_back(1);
        v_last = v;
        if(rowIndex == 1) return v;
        for( int i=2; i<=rowIndex; i++){ //从第2行到第rowIndex行
            v.clear();
            v.push_back(1);
            for( int j=0; j<i-2; j++) { //中间有i-2个元素
                v.push_back(v_last[j]+v_last[j+1]);
            }
            v.push_back(1);
            v_last = v;
        }
        return v;
    }
};
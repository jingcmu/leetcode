/*
首先想到的是O(N2) 的解法，对每个点进行模拟。
O(N) 的解法是，设置两个变量，sum 判断当前起点的有效性；total 则判断整个数组是否有解，
有就返回通过sum 得到的下标，没有则返回-1。
*/
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int len = gas.size(), total_gas=0, sum=0, index = -1;
        for(int i=0; i<len; i++){
            gas[i] -= cost[i];
            sum += gas[i];
            if(sum < 0) { //如果sum为0，说明当前起点无效
                sum = 0;
                index = i;
            }
            total_gas += gas[i]; //下面用来判断是否有解
        }
        return total_gas >= 0? index+1:-1;
    }
};

Second Try:
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if(accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) return -1;
        int index = 0, sum = 0;
        for(int i=0; i<gas.size(); i++) {
            sum += (gas[i] - cost[i]);
            if(sum < 0) {
                sum = 0;
                index = i+1;
            }
        }
        return index;
    }
};
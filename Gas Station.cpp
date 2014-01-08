class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = gas.size(), total_gas=0, sum=0, index = -1;
        for(int i=0; i<len; i++){
            gas[i] -= cost[i];
            sum += gas[i];
            if(sum < 0){
                sum = 0;
                index = i;
            }
            total_gas += gas[i];
        }
        return total_gas >= 0? index+1:-1;
    }
};
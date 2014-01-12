//跟2sum思路一样，2sum是线性复杂度，3sum是平方复杂度
//关于“一定要跳过重复元素”：例如, -2 -1 -1 0 1 2 中的-1，
//取过了第一个-1，则第二个-1完全没必要再取做第一个元素了
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        int len = num.size();
        vector<int> v, v_last;
        vector<vector<int> > v_res;
        if(len<3) return v_res;
		//为了后面用两头逼近法，先要排个序
        sort(num.begin(), num.end());
        for(int i=0; i<len-2; i++) {
            int target = 0-num[i]; //计算target
            int head = i+1, tail = len - 1;
			//一定要跳过重复元素
            if(i>0 && num[i] == num[i-1]){
                continue;
            }
			//这里用了2sum的算法
            while(head < tail){
                v.clear();
				//如果找到了一个结果
                if(num[head]+num[tail] == target){
                    v.push_back(num[i]);
                    v.push_back(num[head++]);
                    v.push_back(num[tail--]);
					//v_last记录上一个结果，因为有重复元素，所以需要判重
                    if(v_last != v){
                        v_res.push_back(v);
                        v_last = v;
                    }
                }
                else if(num[head]+num[tail] < target){
                    head++;
                }
                else if(num[head]+num[tail] > target){
                    tail--;
                }
            }
        }
        return v_res;
    }
};
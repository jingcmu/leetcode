class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        int len = num.size(), target2;
        vector<vector<int> > v_res;
        vector<int> v;
        if(len < 4) return v_res; //如果len小于4，则返回空vector
        sort(num.begin(), num.end()); //对数组排序

		//枚举的时候，位置不发生变化
        for(int i=0; i<len-3; i++){
            for(int j=i+1; j<len-2; j++){
                target2 = target - (num[i]+num[j]);
                int head = j+1, tail = len-1;
                while(head < tail){
                    if(num[head]+num[tail] < target2){
                        head++;
                    }
                    else if(num[head]+num[tail] > target2){
                        tail--;
                    }
                    else{
                        v.push_back(num[i]);
                        v.push_back(num[j]);
                        v.push_back(num[head]);
                        v.push_back(num[tail]);
                        v_res.push_back(v);
                        v.clear();
                        head++;
                        tail--;
                    }
                }
            }
        }
        set<vector<int> > s(v_res.begin(), v_res.end());
        v_res.assign(s.begin(), s.end());
        return v_res;
    }
};
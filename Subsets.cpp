class Solution {
public:
    int nextPermutation(int n, int cur){
        int b = cur&(-cur);
        int t = cur+b;
        int res = (((t^cur)>>2)/b)|t;
        if(res >= (1<<n)) return 0;
        else return res;
    }
    vector<vector<int> > subsets(vector<int> &S) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = S.size();
        int cur;
        vector<int> v;
        vector<vector<int> > v_res;
        v_res.push_back(v);  //先push一个空的
        sort(S.begin(), S.end());
        for(int i=1; i<=len; i++){
            cur = (1<<i)-1; //第一个组合
            do{
                for(int j=0; j<len; j++){
                    if(cur&(0x1<<j)){
                        v.push_back(S[j]);
                    }
                }
				v_res.push_back(v);
				v.clear();  
            } while(cur = nextPermutation(len, cur));
        }
        return v_res;
    }
};
class Solution {
public:
   int next(int n, int com){
	int t = com&(-com);
	int b = t+com;
	int res = (((b^com)>>2)/t)|b;
	if(res >= (1<<n)) return 0;
	else return res;
}
vector<vector<int> > combine(int n, int k) {
	// Note: The Solution object is instantiated only once and is reused by each test case.
	int com = (1<<k)-1;
	vector<vector<int> > v_res;
	while(com)
	{
		vector<int> v;
		for(int i=0; i<n; i++)
		{
			if(com&(0x1<<i)){
				v.push_back(i+1);
			}
		}
		v_res.push_back(v);
		com = next(n,com);
	}
	return v_res;
}
};
/*
��STL��prev_permutation�Ľⷨ
*/
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        int len = S.size();
        int cur;
		vector<int> v_judge(len, 0);
        vector<int> v;
        vector<vector<int> > v_res;
		//��pushһ���ռ��ϣ���Ϊ��ʹS�ǿռ��ϣ���ôv_resҲ����Ӧ�ð���һ���ռ���
        v_res.push_back(v);  
        sort(S.begin(), S.end()); //��S���򣬱�֤�������
        for(int i=1; i<=len; i++){
			fill_n(v_judge.begin(), i, 1); //��ʼ��v_judge
            do{
                for(int j=0; j<len; j++){
                    if(v_judge[j]){
                        v.push_back(S[j]);
                    }
                }
				v_res.push_back(v);
				v.clear();  
            } while(prev_permutation(v_judge.begin(), v_judge.end()));
			//prev_permutation���������һ�����᷵��true
        }
		//������ȥ�صĴ���
        sort( v_res.begin(), v_res.end() ); 
		//unique���ظ�Ԫ�ض��ŵ���󣬷��طֽ紦�ĵ�ַ
        v_res.erase( unique( v_res.begin(), v_res.end() ), v_res.end() );
        return v_res;
    }
};

/*
��λ����ʵ�ֵ�nextPermutation�Ľⷨ
*/
class Solution {
public:
    int nextPermutation( int n, int cur){
        int b = cur&(-cur);
        int t = cur+b;
        int res = (((t^cur)>>2)/b)|t;
        if(res >= (1<<n)) return 0;
        else return res;
    }
    vector<vector< int> > subsetsWithDup(vector< int> &S) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = S.size();
        int cur;
        vector< int> v;
        vector<vector< int> > v_res;
        v_res.push_back(v);  //��pushһ���յ�
        sort(S.begin(), S.end());
        for( int i=1; i<=len; i++){
            cur = (1<<i)-1; //��һ�����
            do{
                for( int j=0; j<len; j++){
                    if(cur&(0x1<<j)){
                        v.push_back(S[j]);
                    }
                }
                v_res.push_back(v);
                v.clear(); 
            } while(cur = nextPermutation(len, cur));
        }
        sort( v_res.begin(), v_res.end() );
        v_res.erase( unique( v_res.begin(), v_res.end() ), v_res.end() );
        return v_res;
    }
};
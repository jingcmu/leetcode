//��̬�滮
//�������������
class Solution {
public :
    int numTrees( int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> v(n+1,0);
        if(!n) return 0;
        v[0] = 1;
        for(int i=1; i<=n; i++){
			//�������ڵ������0��i-1
            for(int j=0; j<i; j++){
                v[i] += v[j]*v[i-j-1];
            }
        }
        return v[n];
    }
};

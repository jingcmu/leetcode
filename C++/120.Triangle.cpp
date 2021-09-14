//DP solution: from the bottom to the top
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        for(int i=triangle.size()-2; i>=0; --i) {
            for(int j=0; j<=i; ++j) {
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};

/*
����ⶼ�����ˣ����������ƣ���֪���������㲻�㶯̬�滮
*/
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        vector<int> v(n), v_lastrow(n);
		if(n == 0) return 0;
        v[0] = v_lastrow[0] = triangle[0][0];
        for(int i=1; i<n; i++){
            v[0] = triangle[i][0] + v_lastrow[0]; //���ϵ�û��ѡ
            for(int j=1; j<i; j++){
				//ѡ��ǰ�ڵ�ͷ���ϵ������ڵ㵱���Ǹ�С��
                v[j] = triangle[i][j] + min(v_lastrow[j-1],v_lastrow[j]);
            }
            v[i] = triangle[i][i] + v_lastrow[i-1]; //���ϵĽڵ�
            v_lastrow = v;
        }
		//min_element��stl�еģ���һ����������С��ֵ��*������ָ����÷����
        return *min_element(v.begin(), v.end());
    }
};
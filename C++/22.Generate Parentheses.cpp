My solution:
//С���Ŵ���һ���ݹ�ṹ�����������������ȵݹ�ṹһ���������뵽�õݹ顣
//һ���������ַ������������ų��ִ���< n ʱ���Ϳ��Է����µ������š��������ų��ִ���С
//�������ų��ִ���ʱ���Ϳ��Է����µ������š�
class Solution {
public:
    void gen(vector<string> &v, int left, int right, string tmp, int n){
        if(left < right || left > n) return;
        if(left == right && left == n) 
            v.push_back(tmp);
        gen(v, left+1, right, tmp+'(', n);
        gen(v, left, right+1, tmp+')', n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v_ret;
        gen(v_ret, 0, 0, "", n);
        return v_ret;
    }
};

/*
ֻ��Ҫ����vector���ɣ�
��v�����м��㣬��v_last������һ�е�
rowIndex�Ǵ�0th��ʼ���
*/
class Solution {
public:
     vector<int> getRow( int rowIndex) {
        vector< int> v, v_last;
        rowIndex++; //�ȼ�1����1��ʼ�㣬����������Ԫ�������
        v.push_back(1);
        v_last = v;
        if(rowIndex == 1) return v;
        for( int i=2; i<=rowIndex; i++){ //�ӵ�2�е���rowIndex��
            v.clear();
            v.push_back(1);
            for( int j=0; j<i-2; j++) { //�м���i-2��Ԫ��
                v.push_back(v_last[j]+v_last[j+1]);
            }
            v.push_back(1);
            v_last = v;
        }
        return v;
    }
};
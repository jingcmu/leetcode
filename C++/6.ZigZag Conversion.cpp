class Solution {
public:
    string convert(string s, int nRows) {
        vector<string> rows(nRows);
        string solution = "";
        int size = s.size(), cur = 0, dir = 0;
		//������ֹ����
        if(nRows == 1 || nRows > size) {
            return s;
        }
        for(int i=0; i<size; i++) {
            rows[cur]+=s[i];
            if(dir == 0){ //0�������£�1��������
                cur++;
                if(cur == nRows-1) {
                    dir = 1; //��ת
                }
            }
            else{
                cur--;
                if(cur == 0){
                    dir = 0; //��ת
                }
            }
        }
        for(int j=0; j<nRows; j++) {
            solution += rows[j];
        }
        return solution;
    }
};
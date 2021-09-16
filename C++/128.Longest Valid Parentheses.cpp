/*
last_valid������Ĺؼ������������������õ����壬
�����Ͷ���
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length(), last_valid = -1, max_len = 0;
        stack<int> left; //ֻ��������'('
        for(int i=0; i<len; i++){
            if(s[i] == '(') { 
                left.push(i);
            }
            else {  //�����')',��ջ������û�ж�Ӧ��'('
                if(left.empty()) {
                    last_valid = i;
                }
                else {
                    left.pop(); //�õ�һ��'('
                    if(left.empty()) { //���ջΪ��,˵����һֱƥ�䵽�ϸ�ƥ�䲻�˵�')'
                        max_len = max(max_len, i - last_valid);
                    }
                    else { //����,ֻ�����ϸ�'('��λ����
                        max_len = max(max_len, i - left.top());
                    }
                }
            }
        }
        return max_len;
    }
};
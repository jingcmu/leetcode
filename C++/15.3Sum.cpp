//��2sum˼·һ����2sum�����Ը��Ӷȣ�3sum��ƽ�����Ӷ�
//���ڡ�һ��Ҫ�����ظ�Ԫ�ء�������, -2 -1 -1 0 1 2 �е�-1��
//ȡ���˵�һ��-1����ڶ���-1��ȫû��Ҫ��ȡ����һ��Ԫ����
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        int len = num.size();
        vector<int> v, v_last;
        vector<vector<int> > v_res;
        if(len<3) return v_res;
		//Ϊ�˺�������ͷ�ƽ�������Ҫ�Ÿ���
        sort(num.begin(), num.end());
        for(int i=0; i<len-2; i++) {
            int target = 0-num[i]; //����target
            int head = i+1, tail = len - 1;
			//һ��Ҫ�����ظ�Ԫ��
            if(i>0 && num[i] == num[i-1]){
                continue;
            }
			//��������2sum���㷨
            while(head < tail){
                v.clear();
				//����ҵ���һ�����
                if(num[head]+num[tail] == target){
                    v.push_back(num[i]);
                    v.push_back(num[head++]);
                    v.push_back(num[tail--]);
					//v_last��¼��һ���������Ϊ���ظ�Ԫ�أ�������Ҫ����
                    if(v_last != v){
                        v_res.push_back(v);
                        v_last = v;
                    }
                }
                else if(num[head]+num[tail] < target){
                    head++;
                }
                else if(num[head]+num[tail] > target){
                    tail--;
                }
            }
        }
        return v_res;
    }
};

//Second Try: use C++ template
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {       
        if(num.size() < 3) return res;
        sort(num.begin(), num.end());
        for(int i=0; i<num.size()-2; i++) {
            if(i != 0 && num[i] == num[i-1]) continue;
            int target = 0 - num[i];
            get2sum(target, next(num.begin(), i+1), prev(num.end()));
        }
        set<vector<int>> s(res.begin(), res.end());
        res.assign(s.begin(), s.end());
        return res;
    }
private:
    vector<vector<int>> res;
    template<typename ForwardIterator, typename T>
    void get2sum(T target, ForwardIterator begin, ForwardIterator end) {
        vector<T> threesum;
        while(begin < end) {
            if(*begin + *end == target) {
                threesum.push_back(0-target);
                threesum.push_back(*begin);
                threesum.push_back(*end);
                begin++;
                end--;
                res.push_back(threesum);
                threesum.clear();
            }
            else if(*begin + *end < target) {
                begin++;
            }
            else {
                end--;
            }
        }
    }
};
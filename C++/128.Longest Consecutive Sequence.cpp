/*
��count�������ж��ؼ����Ƿ���֣���ȱ�����޷���λ���ݳ���λ��,��
����map������һ��һ��ӳ���ϵ���;�����count�����ķ���ֵֻ��������
Ҫô��0��Ҫô��1�����ֵ��������Ȼ�Ƿ���1��
unordered_map���������ظ�Ԫ�أ����������vectorȴ�����У������
��ʼ����ʱ����Ҫ���ж�num[i]�Ƿ���ֹ�
*/
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> map;
        int len = num.size();
		//��Ϊvector�������ظ�Ԫ�أ���unordered_map������
        for(int i=0; i<len; i++){
            if(map.count(num[i])){
                map[num[i]]++;
            }
            else{
                map[num[i]] = 1;
            }
        }
        int max_len = 0;
        for(int i=0; i<len; i++){
            int element1 = num[i]+1, element2 = num[i]-1;
            int count_biger = 0;//��¼��������Ľ��
            int count_smaller = 0;//��¼��������Ľ��
			//���ұ�����
            while(map.count(element1)){
                count_biger++;
                map.erase(element1++); //Ҫ��map��ȥ��
            }
			//���������
            while(map.count(element2)){
                count_smaller++;
                map.erase(element2--); //Ҫ��map��ȥ��
            }
            map.erase(num[i]);
            max_len = max(max_len, count_biger + count_smaller + 1);
        }
        return max_len;
    }
};

/*
�������O(n log n) �ĸ��Ӷȣ���ô���������򣬿��Ǳ���Ҫ��O(n)��
�����������Ԫ��������ģ���Ҫ��O(n)������Ҫ�뵽�ù�ϣ��
��һ����ϣ��unordered_map<int, bool> used ��¼ÿ��Ԫ���Ƿ�ʹ�ã���ÿ��Ԫ�أ��Ը�
Ԫ��Ϊ���ģ����������ţ�ֱ��������Ϊֹ����¼����ĳ��ȡ�
*/
class Solution {
public:
	int longestConsecutive(vector<int> const& num) {
		unordered_map<int, bool> used;
		for (auto i : num) used[i] = false;
		int longest = 0;
		for (auto i : num) {
			if (used[i]) continue; //������ʹ��˾�continue
			int length = 1;
			used[i] = true;
			//��unordered_map����find���Բ����ӳ�Ա������
			for (int j = i + 1; used.find(j) != used.end(); ++j) {
				used[j] = true;
				++length;
			}
			for (int j = i - 1; used.find(j) != used.end(); --j) {
				used[j] = true;
				++length;
			}
			longest = max(longest, length);
		}
		return longest;
	}
};

Third Try:
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, bool> m;
        for(int i=0; i<num.size(); i++) {
            m[num[i]] = true;
        }
        int max_res = 0, tmp = 0;
        for(int i=0; i<num.size(); i++) {
            if(m[num[i]]) {
                m[num[i]] = false;
                tmp = 1;
                int right = num[i] + 1;
                int left = num[i] - 1;
                while(m.find(right) != m.end()) {
                    m[right++] = false;
                    tmp++;
                }
                while(m.find(left) != m.end()) {
                    m[left--] = false;
                    tmp++;
                }
                max_res = max(max_res, tmp);
            }
        }
        return max_res;
    }
};

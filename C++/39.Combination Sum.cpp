//a little improvement
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        size = candidates.size();
        sort(candidates.begin(), candidates.end());
        count.resize(size);
        dfs(candidates, target, 0);
        return res;
    }
private:
    int size;
    vector<int> count;
    vector<vector<int>> res;
    void dfs(vector<int> &candidates, int target, int index) {
        if(index == size) {
            if(target == 0) {
                vector<int> vt;
                for(int i=0; i<size; i++) {
                    for(int j=0; j<count[i]; j++) {
                        vt.push_back(candidates[i]);
                    }
                }
                res.push_back(vt);
            }
            return;
        }
        int num = target/candidates[index];
        for(int i=0; i<=num; i++) {
            count[index] = i;
            dfs(candidates, target - i*candidates[index], index+1);
        }
    }
};

//�����������
//��һ���ö��鲻��������ΪҪ��¼
class Solution {
private:
    vector<vector<int> > ret;
    vector<int> count;          
public:
	//��������ǰ��������������currentIndex������ĳ���len��Ŀ���target������candidates
    void helper(int currentIndex, int len, int target, vector<int> &candidates){
        vector<int> v;
        if(target < 0) return; //�����������˳�
        if(currentIndex == len){ //�õ����˳�
            if(target == 0){ //����͵���0,�õ�һ���
                for(int i=0; i<currentIndex; i++){
                    for(int j=0; j<count[i]; j++){
                        v.push_back(candidates[i]);
                    }
                }
                ret.push_back(v);
            }
            return;
        }
		//
        int num = target/candidates[currentIndex]; //��ǰ������ѭ������
        for(int i=0; i<=num; i++) { //ѭ����0��ʼ������ȡ
            count[currentIndex] = i;
            helper(currentIndex+1, len, target-candidates[currentIndex]*i, candidates);
        }
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        int len = candidates.size();
        ret.clear();
        if(len == 0) ret;
        sort(candidates.begin(), candidates.end());
        count.resize(len);
        count.clear();
        helper(0, len, target, candidates);
        return ret;
    }
};


Second Try:

class Solution {
public:
    void helper(vector<vector<int> > &ret, vector<int> &count, int currentIndex, int len, int target, vector<int> &candidates){
       if(currentIndex == len) {
           if(target == 0) {
               vector<int> temp;
               for(int i=0; i<len; i++) {
                   for(int j=0; j<count[i]; j++) {
                      temp.push_back(candidates[i]);
                   }
               }
               ret.push_back(temp);
           }
           return;
       }
       int num = target/candidates[currentIndex];
       for(int i=0; i<=num; i++) {
           count[currentIndex] = i;
           helper(ret, count, currentIndex+1, len, target-i*candidates[currentIndex], candidates);
       }
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        int len = candidates.size();
        vector<int> count(len, 0);
        vector<vector<int> > ret;
        sort(candidates.begin(), candidates.end());
        if(len == 0) ret;
        helper(ret, count, 0, len, target, candidates);
        return ret;
    }
};
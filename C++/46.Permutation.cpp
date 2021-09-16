First Try:
//���ý�����DFS
class Solution {
public:    
    void permute(vector<vector<int> > &v_res, vector<int> &num, int k, int len){
        if(k == len){
            v_res.push_back(num);
        }
        else{
            for(int i=k; i<=len; i++){ 
                swap(num+k, num+i); //��k��Ԫ�ظ������������Ԫ��(����k)���ν���
                permute(v_res, num, k+1, len);
                swap(num+k, num+i); //���ν�������
            }
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > v_res;
        permute(v_res, num, 0, num.size()-1);
        return v_res;
    }
};

Second Try:
//����next_permutation
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        do {
            result.push_back(num);
        } while(next_permutation(num.begin(), num.end()));
        return result;
    }
};

Third Try:
//implement next_permutation by myself
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int>> res;
        res.push_back(num);
        while(next_permutation(num)) {
            res.push_back(num);
        }
        return res;
    }
private:
    bool next_permutation(vector<int> &num) {
        int size = num.size();
        int left, right;
        for(right=size-1, left=right-1; left >=0; left--, right--) {
            if(num[left] < num[right]) {
                break;
            }
        }
        if(left < 0) return false;
        for(int i=size-1; i<=right; i--) {
            if(num[i] > num[left]) {
                swap(num[i], num[left]);
            }
        }
        sort(num.begin()+right, num.end());
        return true;
    }
};
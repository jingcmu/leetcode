//跟3sum没什么不一样
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int len = num.size();
        int sum = 0, head, tail;
        int diff, diff_min = (1<<31)-1;
        if(len<=3){
            for(int i=0; i<len; i++){
                sum += num[i];
            }
            return sum;
        }
		//先排序
        sort(num.begin(),num.end());
        for(int i=0; i<len-2; i++){
            head = i+1;
            tail = len-1;
			//2sum左右逼近
            while(head < tail){
                sum = num[i]+num[head]+num[tail];
                diff = target - sum;
                if(diff == 0){
                    return target;
                }
                if(diff<0){
                    tail--;
                }
                else if(diff>0){
                    head++;
                }
				//更新最小差距
                if(abs(diff_min)>abs(diff)){
                    diff_min = diff;
                }
            }
        }
        return target - diff_min;
    }
};

//Second Try: use C++ template 
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int size = num.size();
        int min_diff = INT_MAX;
        if(size < 3) return 0;
        sort(num.begin(), num.end());
        for(int i=0; i<size-2; i++) {
            int new_target = target - num[i];
            int diff = twoSumClosest(num.begin()+i+1, num.end()-1, new_target);
            if(abs(diff) < abs(min_diff)) {
                min_diff = diff;
            }
        }
        return target - min_diff;
    }
private:
    template<typename BidirIterator, typename T>
    T twoSumClosest(BidirIterator first, BidirIterator last, T target) {
        T diff = (T)INT_MAX;
        while(first < last) {
            if(abs(diff) > abs(target - *first - *last)) {
                diff = target - (*first + *last);
            }
            if(*first + *last == target) {
                return (T)0;
            }
            else if(*first + *last < target) {
                first++;
            }
            else {
                last--;
            }
        }
        return diff;
    }
};
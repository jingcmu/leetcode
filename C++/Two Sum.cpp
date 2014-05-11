//Second try:
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int size = numbers.size();
        vector<int> num = numbers;
        vector<int> v_res;
        if(size == 0) return v_res;
        sort(numbers.begin(), numbers.end());
        int begin = 0, end = size-1;
        while(begin < end) {
            if(numbers[begin] + numbers[end] < target) {
                begin++;
            }
            else if(numbers[begin] + numbers[end] > target) {
                end--;
            }
            else {
                v_res.push_back(find(num.begin(), num.end(), numbers[begin])-num.begin()+1);
                if(numbers[begin] == numbers[end]) {
                    v_res.push_back(find(num.begin()+v_res[0], num.end(), numbers[end])-num.begin()+1);
                }
                else v_res.push_back(find(num.begin(), num.end(), numbers[end])-num.begin()+1);
                sort(v_res.begin(), v_res.end());
                break;
            }
        }
        return v_res;
    }
};


/*两头逼近的方法*/
class Solution {
public:
	int getIndex(vector<int> numbers, int num){
		for(int i=0; i<numbers.size(); i++){
			if(numbers[i] == num)
				return i+1;
		}
	}

	int getIndexRev(vector<int> numbers, int num){
		for(int i=numbers.size()-1; i>=0; i--){
			if(numbers[i] == num)
				return i+1;
		}
	}

    vector<int> twoSum(vector<int> &numbers, int target) {
        int head = 0, tail = numbers.size() - 1;
        int sum;
        vector<int> v;
		vector<int> number_sorted = numbers;
        sort(number_sorted.begin(), number_sorted.end());
        while(head<tail){
            sum = number_sorted[head] + number_sorted[tail];
            if(target == sum){
				head = getIndex(numbers, number_sorted[head]);
				tail = getIndexRev(numbers, number_sorted[tail]);
                v.push_back(head>tail?tail:head);
                v.push_back(head>tail?head:tail);
                return v;
            }
            if(sum < target) head++;
            else tail--;
        }
        return v;
    }
};
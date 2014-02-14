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
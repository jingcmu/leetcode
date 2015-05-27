/*
There is long motorway of length M. 
On the motorway at some points there are petrol stations (there is given integer array T[] of length N - the positions of petrol stations). 
We have funds to add at most K new petrol stations on this motorway. 
We want to minimize largest distance of motorway which is uncovered by petrol stations. 

You can only put petrol stations on integer positions. 

Example: 
N = 5, M = 20, K = 3, T = [3, 7, 15, 18, 1] 
Answer: 3 (obtainable for example by adding petrol stations at positions: 5, 10 and 13)
*/

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

int help(vector<int>& diff, int start, int end, int k) {
	int k_local = k;
	int guess = (start + end) / 2;
	int res = 0;
	for (int i = 0; i < diff.size(); ++i) {
		int count = 1;
		while ((double)diff[i] / count++ > guess) {
			--k_local;
		}
		res = max(res, diff[i] / (count - 1));
	}
	if (!k_local || start == end) return res;
	if (k_local > 0) {
		end = guess;
	}
	else if (k_local < 0)
		start = guess + 1;

	cout << "(" << start << "," << end << ")" << endl;
	return help(diff, start, end, k);
}

int petrol_station(vector<int>& v, int len, int k) {
	sort(v.begin(), v.end());
	v.push_back(len);
	vector<int> diff(v.size());
	adjacent_difference(v.begin(), v.end(), diff.begin());
	return help(diff, 0, len, k);
}

int main() {
	vector<int> v = { 1, 4, 5, 9, 20 };
	cout << petrol_station(v, 20, 5) << endl;
	return 0;
}

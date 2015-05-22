/*
- count the elements into a hash_map 
- populate a heap with (count,element) pairs 
- loop until output size reaches N: 
- - pop from heap (if the heap is empty before the output size has reached N, report failure) 
- - append element to output 
- - decrement count 
- - push (count,element) pair into a queue 
- - if queue's size has reached min_distance, pop from queue 
- - if the count we just got out of the queue has reached zero, discard it. otherwise, push it back into the heap. 
The heap operations dominate, and this algorithm runs in O(N*logM) time, where M is the number of distinct elements in the input. 

I have had 1-2 stellar candidates independently propose an O(N) solution: 
- after collecting element counts, construct an inverted multimap of counts to elements. 
- repeatedly emit the top min_distance elements, until we complete the output or emit a partial batch which does not complete the output 
The number of keys in this map is bounded by sqrt(N), so you can sort the keys in linear time. Once you've sorted the keys, emitting the top k elements and decrementing their counts (removing elements whose counts have hit zero) takes O(k) time. 
*/
// distance是任意的，用priority queue + queue重新构建string

#include <utility>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class ShuffleString {
public:
	explicit ShuffleString(string& s, int min_dist) {
		s_res_ = "";
		s_ = s;
		min_dist_ = min_dist;
	}
	bool CanShuffle();
	string GetShuffledString();
	void Shuffle();
private:
	// compare rule for priority queue
	struct cmp {
		bool operator()(pair<char, int> p1, pair<char, int> p2) {
			return p1.second < p2.second;
		}
	};
	void BuildPQ();
	void BuildShuffledString();
	priority_queue<pair<char, int>, vector<pair<char, int> >, cmp> pq_;
	queue<pair<char, int> > q_;
	string s_;       // sorted string
	string s_res_;   // result
	bool shuffled_;  // true: successful false: failed
	int min_dist_;   // min distance
};

bool ShuffleString::CanShuffle() {
	return shuffled_;
}

string ShuffleString::GetShuffledString() {
	return s_res_;
}

// Build priority queue
void ShuffleString::BuildPQ() {
	int first = 0, last = 0;
	while (last < s_.length()) {
		while (s_[last] == s_[first] && last < s_.length())
			last++;
		pq_.push(make_pair(s_[first], last - first)); // char and counts in priority queue
		first = last;
	}
}

void ShuffleString::BuildShuffledString() {
	int dist = 0;
	while (!pq_.empty()) {
		char c = pq_.top().first;
		// from priority queue to queue, discard if count is 0
		if (pq_.top().second > 1) {
			pair<char, int> p = pq_.top();
			p.second--;
			q_.push(p);
		}
		pq_.pop();
	  dist++;
		s_res_ += c;
		// from queue to priority queue
		if (dist >= min_dist_) {
			while (!q_.empty()) {
				pq_.push(q_.front());
				q_.pop();
			}
			dist = 0;
		}
	}
	shuffled_ = (s_res_.length() == s_.length());
}

void ShuffleString::Shuffle() {
	int len = s_.length();
	if (len == 0) {
		shuffled_ = false;
		return;
	}
	sort(s_.begin(), s_.end());
	BuildPQ();
	BuildShuffledString();
}

void main() {
	string s = "a";
	//string s = "aa";
	//string s = "abbbbccdddeeeeeff";
	//string s = "abcddddd";
	//string s = "abcdef";
	ShuffleString SS(s, 3);
	SS.Shuffle();
	if (SS.CanShuffle()) {
		cout << "source:" << s << endl;
		cout << "result:" << SS.GetShuffledString() << endl;
	}
	else
		cout << "Not possible!" << endl;
}

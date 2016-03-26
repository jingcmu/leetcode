#include <iostream>
#include <algorithm>
using namespace std;

string shortestPalindrome(string s) {
  string r = s;
  reverse(r.begin(), r.end());
  string t = s + "#" + r;
  // KMP
  vector<int> p(t.size(), 0);
  for (int i = 1; i < (int)t.size(); ++i) {
    int j = p[i - 1]; // 第i-1个位置不匹配要跳到的位置
    while (j > 0 && t[i] != t[j]) j = p[j - 1]; // 如果还是不匹配，跳到的位置
    p[i] = (j += t[i] == t[j]); // 如果t[i] == t[j], 则p[i]在j的基础上+1
  }
  return r.substr(0, s.size() - p[t.size() - 1]) + s;
}

// To execute C++, please define "int main()"
int main() {
  cout << shortestPalindrome("ababc") << endl;
  return 0;
}

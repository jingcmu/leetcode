My solution:
class Solution {
public:
    int romanToInt(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int res = 0;
        for(int j=0; j<s.length(); j++){
			switch (s[j])
			{
			case 'M':
				res += 1000;
				break;
			case 'D':
				res += 500;
				break;
			case 'L':
				res += 50;
				break;
			case 'V':
				res += 5;
				break;
			case 'C':
				if(j+1 < s.length() && ((s[j+1] == 'D')||(s[j+1] == 'M'))){
                    res -= 100;
                }
                else{
                    res += 100;
                }
				break;
			case 'X':
				if(j+1 < s.length() && ((s[j+1] == 'L') || (s[j+1] == 'C'))){
                    res -= 10;
                }
                else {
                    res += 10;
                }
				break;
			case 'I':
				if(j+1 < s.length() && ((s[j+1] == 'V') || (s[j+1] == 'X'))){
                    res -= 1;
                }
                else {
                    res += 1;
                }
				break;
			}
        }
        return res;
    }
};

Better solution:
class Solution {
public:
	inline int map(const char c) {
		switch (c) {
			case 'I': return 1;
			case 'V': return 5;
			case 'X': return 10;
			case 'L': return 50;
			case 'C': return 100;
			case 'D': return 500;
			case 'M': return 1000;
			default: return 0;
		}
	}

	int romanToInt(string s) {
		int result = 0;
		for (size_t i = 0; i < s.size(); i++) {
			if (i > 0 && map(s[i]) > map(s[i - 1])) {
				result += (map(s[i]) - 2 * map(s[i - 1]));
			} else {
				result += map(s[i]);
			}
		}
		return result;
	}
};
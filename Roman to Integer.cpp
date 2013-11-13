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
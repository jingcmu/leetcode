/*
记住find_first_of和substr的用法
*/
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        for (auto s : strs) {
            res += (to_string(s.size()) + '|' + s);
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        string s_tmp;
        char c[] = {'|'};
        auto it = find_first_of(s.begin(), s.end(), c, c+1);
        while (it != s.end()) {
            string s_num = s.substr(0, it - s.begin());
            int num = stoi(s_num);
            s_tmp = s.substr(it - s.begin() + 1, num);
            res.push_back(s_tmp);
            s = s.substr(it - s.begin() + 1 + num);
            it = find_first_of(s.begin(), s.end(), c, c+1);
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

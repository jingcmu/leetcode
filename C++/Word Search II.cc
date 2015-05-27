class TrieNode {
public:
#define MAXCHAR 26
	// Initialize your data structure here.
	TrieNode() {
		for (int i = 0; i < MAXCHAR; ++i) {
			next[i] = nullptr;  //不会默认为null 
		}
		reachable = true;
	}
	TrieNode* next[MAXCHAR];
	bool reachable;
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}
	// Inserts a word into the trie.
	void insert(string s) {
		TrieNode *p = root;
		for (int i = 0; i < s.length(); ++i) {
			int id = s[i] - 'a';  // 计算偏移
			if (p->next[id] == nullptr) {
				TrieNode* q = new TrieNode;
				p->next[id] = q;

			}
			p = p->next[id];
		}
	}
	TrieNode* searchNode(string key) {
		int len = key.length();
		TrieNode *p = root;
		for (int i = 0; i < len; ++i) {
			int id = key[i] - 'a';
			p = p->next[id];
			if (p == nullptr)
				return nullptr;
		}
		return p;
	}
	void propagate(TrieNode* t) {
	    for (int i = 0; i < MAXCHAR; ++i) {
	        if (t->next[i]) {
	            t->next[i]->reachable = false;
	            propagate(t->next[i]);
	        }
	    }
	}
private:
    TrieNode* root;
}; 

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> v_res;
        height = board.size();
        if (!height) return v_res;
        width = board[0].size();
        if (!width) return v_res;
        sort(words.begin(), words.end()); // 排序
        // 建trie树
        for (int i = 0; i < words.size(); ++i) {
            T.insert(words[i]);
        }
        vector<vector<bool>> visited(height, vector<bool>(width, false));
        for (int i = 0; i < words.size(); ++i) {
            bool found = false;
            reset(visited);
            for (int j = 0;  j < height; ++j){
                for (int k = 0; k < width; ++k){
                    if(search(board, j, k, words[i], 0, visited)) {
                        v_res.push_back(words[i]);
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }
        }
        set<string> s(v_res.begin(), v_res.end());
        v_res.assign(s.begin(), s.end());
        return v_res;
    }
private:
    bool search(vector<vector<char> > &board, int x, int y, string &word, int index, vector<vector<bool>> &visited){
        if(index == word.length()) return true;
        
        TrieNode* t = T.searchNode(word);
        if (!t->reachable) return false;

        if(x<0 || y<0 || x>=height || 
           y>=width || visited[x][y] ||
           board[x][y] != word[index] ) return false;  
		
        visited[x][y] = true;
        if(search(board, x+1, y, word, index+1, visited) ||
           search(board, x-1, y, word, index+1, visited) ||
           search(board, x, y+1, word, index+1, visited) ||
           search(board, x, y-1, word, index+1, visited) ) return true;
		
        visited[x][y] = false;
        t->reachable = false;
        T.propagate(t);
        return false;
    }
    void reset(vector<vector<bool>>& visited) {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                visited[i][j] = false;
            }
        }
    }
    Trie T;
    int height;
    int width;
};

class TrieNode {
public:
#define MAXCHAR 26
	// Initialize your data structure here.
	TrieNode() {
		for (int i = 0; i < MAXCHAR; ++i) {
			next[i] = nullptr;  //不会默认为null 
		}
		is_leaf = false;
	}
	TrieNode* next[MAXCHAR];
	bool is_leaf;
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
		p->is_leaf = true; // 标记为叶子
	}

	// Returns if the word is in the trie.
	bool search(string key) {
		TrieNode* p = searchNode(key);
		if (p != nullptr && p->is_leaf) {
			return true;
		}
		return false;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		return searchNode(prefix) != nullptr;
	}

private:
	TrieNode* root;
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
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key"); 

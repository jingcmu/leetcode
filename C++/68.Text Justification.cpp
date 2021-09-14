class Solution {
public:
	vector<string> fullJustify(vector<string> &words, int L) {
		vector<string> result;
		const int n = words.size();
		int begin = 0, len = 0; // ��ǰ�е���㣬��ǰ����
		for (int i = 0; i < n; ++i) {
			if (len + words[i].size() + (i - begin) > L) {
				result.push_back(connect(words, begin, i - 1, len, L, false));
				begin = i;
				len = 0;
			}
			len += words[i].size();
		}
		// ���һ�в���L
		result.push_back(connect(words, begin, n - 1, len, L, true));
		return result;
	}

	/**
	* @brief ��words[begin, end] ����һ��
	* @param[in] words �����б�
	* @param[in] begin ��ʼ
	* @param[in] end ����
	* @param[in] len words[begin, end] ���е��ʼ������ĳ���
	* @param[in] L ��Ŀ�涨��һ�г���
	* @param[in] is_last �Ƿ������һ��
	* @return �����ĵ�ǰ��
	*/
	string connect(vector<string> &words, int begin, int end, int len, int L, bool is_last) {
		string s;
		int n = end - begin + 1; //�����ӵĵ��ʸ���
		for (int i = 0; i < n; ++i) {
			s += words[begin + i];
			addSpaces(s, i, n - 1, L - len, is_last); //i�Ǽ��������n-1�Ǽ������
		}
		if (s.size() < L) s.append(L - s.size(), ' ');
		return s;
	}

	/**
	* @brief ��ӿո񣬽�L���ȵĿո������ȵķ��䵽n����϶����
	* @param[inout]s һ��
	* @param[in] i ��ǰ��϶�����
	* @param[in] n ��϶����
	* @param[in] L �ܹ���Ҫ��ӵĿն���
	* @param[in] is_last �Ƿ������һ��
	* @return ��
	*/
	void addSpaces(string &s, int i, int n, int L, bool is_last) {
		if (n < 1 || i > n - 1) return;
		//i < (L % n) ? 1 : 0 ���̫������
		int spaces = is_last ? 1 : (L / n + (i < (L % n) ? 1 : 0));
		s.append(spaces, ' ');
	}
};
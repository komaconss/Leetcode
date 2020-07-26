class Solution {
public:
    string reverseWords(string s) {
        //先翻转整个字符串，再依次翻转每个单词
        reverse(s.begin(), s.end());

        int idx = 0;
        int sz = s.size();
        for (int i = 0; i < sz; ++i) {
            if (s[i] != ' ') {
                if (idx != 0) {
                    s[idx++] = ' ';
                }
                int j = i;
                while (j < sz && s[j] != ' ') {
                    s[idx++] = s[j++];
                }
                reverse(s.begin() + idx - (j - i), s.begin() + idx);

                i = j;
            }
        }
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};

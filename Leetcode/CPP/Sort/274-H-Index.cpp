class Solution {
public:
    int hIndex(vector<int>& citations) {
        int sz = citations.size();
        sort(citations.begin(), citations.end());

        int i = 0;
        while (i < sz) {
            if (citations[sz - 1 - i] <= i) {
                break;
            }
            ++i;
        }
        return i;
    }
};

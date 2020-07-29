class Solution {
public:
    int hIndex(vector<int>& citations) {
        int sz = citations.size();
        int left = 0, right = citations.size() - 1;
        int mid = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (citations[mid] == sz - mid) {
                return sz - mid;
            } else if (citations[mid] > sz - mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return sz - left;
    }
};

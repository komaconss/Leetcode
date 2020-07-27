class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = 0;
        while (m < n) {
            n = n & (n - 1);
        }
        return m & n;
    }
};

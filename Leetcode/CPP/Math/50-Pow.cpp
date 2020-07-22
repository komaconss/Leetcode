class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        int k = abs(n);
        while (k > 0) {
            if (k & 1) {
                res *= x;
            }
            x *= x;
            k >>= 1;
        }
        return n > 0 ? res : 1 / res;
    }
};

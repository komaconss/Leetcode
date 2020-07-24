class Solution {
public:
    vector<int> grayCode(int n) {
        int shift = 1;
        vector<int> res;
        //找规律，参考一个答案：
        //n = 0, [0]
        //n = 1, [0,1] //新的元素1，为0+2^0
        //n = 2, [0,1,3,2] // 新的元素[3,2]为[0,1]->[1,0]后分别加上2^1
        //n = 3, [0,1,3,2,6,7,5,4] // 新的元素[6,7,5,4]为[0,1,3,2]->[2,3,1,0]后分别加上2^2->[6,7,5,4]
        while (n >= 0) {
            if (res.size() == 0) {
                res.push_back(0);
            } else {
                for (int i = shift - 1; i >= 0; --i) {
                    res.push_back(res[i] + shift);
                }
                shift *= 2;
            }
            --n;
        }
        return res;
    }
};

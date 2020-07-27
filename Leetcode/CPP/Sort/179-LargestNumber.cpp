class Solution {
public:
    string largestNumber(vector<int>& nums) {
        //设置一个比较函数，对数组进行排序
        int sz = nums.size();
        if (sz == 0) {
            return "";
        }
        if (sz == 1) {
            return to_string(nums[0]);
        }
        sort(nums.begin(), nums.end(), cmp);
        string res;
        for (int i = 0; i < sz; ++i) {
            res += to_string(nums[i]);
        }
        if (res[0] == '0') {
            return "0";
        }
        return res;
    }
private:
    static bool cmp(const int& a, const int& b) {
        string a_str = to_string(a);
        string b_str = to_string(b);
        //cout << "a_str = " << a_str << ", b_str = " << b_str << endl;
        return a_str + b_str > b_str + a_str;
    }
};

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_tank = 0;
        int cur_tank = 0;
        int start_pos = 0;
        int sz = gas.size();
        for (int i = 0; i < sz; ++i) {
            total_tank += gas[i] - cost[i];
            cur_tank += gas[i] - cost[i];
            if (cur_tank < 0) {
                cur_tank = 0;
                start_pos = i + 1;
            }
        }
        return total_tank >= 0 ? start_pos : -1;
    }
};

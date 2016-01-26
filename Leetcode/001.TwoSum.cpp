#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
    map<int,int> tmp;
    size_t n = nums.size();
    for(int i = 0; i < n; ++i)
    {
    	auto a = tmp.find(target-nums[i]); 
        if(a != tmp.end())
        {
            return {a->second+1, i+1};
        }
        tmp[nums[i]] = i;
	}		
}

int main()
{
	vector<int> nums{2, 7, 11, 15};
	int target = 9;
	vector<int> res = twoSum(nums, target);
	for (auto e : res)
	{
		cout << e << " ";
	}
	
	return 0;
}

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
	
    int pivotIndex(vector<int>& nums) {
        
        if(nums.size() == 0)
            return -1;
        
        int all_sum = accumulate(nums.begin(), nums.end(), 0);
        
        int left_sum = 0;
        for(int i = 0; i < nums.size(); i++ ){
            if(left_sum == (all_sum - left_sum - nums[i]))
                return i;
            left_sum += nums[i];
        }
    return -1;
    }
};

int main(int argc, char** argv)
{
	Solution s;
	vector<int> v= {1, 7, 3, 6, 5, 6};
	
	cout<< s.pivotIndex(v) <<endl;
	
return 0;
}
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

		vector<int>result;
		
        for(int index1 = 0; index1 < nums.size() - 1; ++index1) {
			for(int index2 = index1 + 1; index2 < nums.size(); ++index2) {
            	if( (nums.at(index1) + nums.at(index2)) == target ){
					result.push_back(index1 + 1); result.push_back(index2 + 1);
					return result;
				}
			}
        }
		return result;
    }
};

int main(int argc, char ** argv)
{
    Solution s;    
    vector<int> nums = {2, 7, 5, 11};
    int target = 9;
    
    vector<int>result = s.twoSum(nums, target);
	
	cout<<result.at(0)<<" "<<result.at(1)<<endl;
    
return 0;
}
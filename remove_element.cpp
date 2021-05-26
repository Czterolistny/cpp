#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
		for(int i = 0; i < nums.size(); ++i)
		{
			if(nums.at(i) == val)
				nums.erase(nums.begin() + i--);
		}
		return nums.size();
    }
};

int main(int argc, char ** argv)
{
	vector<int> digit = {3,3,3,3};
	int val = 2;
	Solution s;
	
	int len = s.removeElement(digit, val);
	cout<<len<<endl;
	
return 0;
}
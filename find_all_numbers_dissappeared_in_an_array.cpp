#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
		vector<int>disappNumber;
        int nums_size = nums.size();
		if(nums_size == 0)
			return disappNumber;
        sort(nums.begin(), nums.end());

		for(int i = 0; i < nums.size() - 1; i++)
			if( (nums.at(i + 1) - nums.at(i)) == 0)
				nums.erase(nums.begin() + i);
			
        for(int i = 1; i != nums.at(0); i++)
            disappNumber.push_back(i);
        
		for(int i = 0; i < nums.size() - 1; i++){
			int n = nums.at(i + 1) - nums.at(i);
            if(n > 1)
				while( --n )
            		disappNumber.push_back(nums.at(i) + n);
		}
		for(int i = *max_element(nums.begin(), nums.end()); i < nums_size; i++)
			disappNumber.push_back(i + 1);
			
    return disappNumber;
    }
};

int main(int argc, char **argv)
{
	Solution s;
	vector<int> n = {9,9,4,10,8,5,2,2,7,7};
	vector<int> out = s.findDisappearedNumbers(n);
	
	for(auto x : n)
		cout<<x<<" ";
	cout<<endl;
	for(auto x : out)
		cout<<x<<" ";
	
return 0;
}
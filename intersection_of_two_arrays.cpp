#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> inters;
		if( (nums1.size() == 0) || (nums2.size() == 0))
			return inters;
		
		sort(nums2.begin(), nums2.end());
        for(int i = 0; i < nums2.size() - 1; i++)
            if(nums2.at(i) == nums2.at(i+1))
                nums2.erase(nums2.begin() + i);
		
		for(auto x : nums2)
			if( find(nums1.begin(), nums1.end(), x) != nums1.end() )
				inters.push_back(x);
			
	return inters;
    }
};

int main(int argc, char **argv)
{
	Solution s;
	vector<int> num1 = {};
	vector<int> num2 = {};
	
	vector<int> inters = s.intersection(num1, num2);
	for(auto x : inters)
		cout<<x<<endl;
	
return 0;
}
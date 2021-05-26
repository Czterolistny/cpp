#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
		int unique = 0;
        for (auto x : nums )
            unique ^= x;
      
    return unique;
    }
};

int main(int argc, char **argv)
{
	Solution s;
	vector<int> v = {8,9,7,6,-2,6,3,7,8,9,-2};
	cout<<s.singleNumber(v)<<endl;
	
return 0;
}
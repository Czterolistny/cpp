#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    
    vector<int> plusOne(vector<int>& digits) {  
        
	int size = digits.size();
		
	for(int i = size; i >= 0; --i)
	{
		if( i == 0){
			digits.insert(digits.begin(), 1);
			return digits;
		}
		digits.at( i - 1 ) += 1;
		if( digits.at(i - 1) != 10 )
			return digits;
		else
			digits.at(i - 1) = 0;
	}
	return digits;
}
};

int main(int argc, char ** argv)
{
	vector<int> digit = {1,9,9,9};
	
	Solution s;
	s.plusOne(digit);
	for_each(digit.begin(), digit.end(), [](auto x){ cout<<x<<" "; });
	
return 0;
}
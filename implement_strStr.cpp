#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if((haystack.length() == 0) && (needle.length() == 0))
            return 0;
        
      	size_t idx = haystack.find(needle);
		if(idx == string::npos)
			return -1;
		return idx;
    }
};

int main(int argc, char ** argv)
{
    Solution s;    
    string haystack = "haystack";
	string needle = "sys";
	
	cout<< s.strStr(haystack, needle) <<endl;
    
return 0;
}
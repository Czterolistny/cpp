#include <iostream>
#include <vector>
#include <numeric>
#include <string>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        
        vector<int> letter_cnt(26,0);
        for(char c: s)
            letter_cnt[c - 'a']++;
        
        for(int i = 0; i < s.size(); i++)
            if( letter_cnt[s[i] - 'a'] == 1)
                return i;
        
    return -1;
    }
};

int main(int argc, char** argv)
{
	Solution s;
	string str = "loveleetcode";
	
	cout<< s.firstUniqChar(str) <<endl;
	
return 0;
}
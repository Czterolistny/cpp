#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        
        string s = move(a);
        string s1 = move(b);
        
        if(s.length() < s1.length())
            swap(s,s1);
        
        int s_end_indx = s.length() - 1;
        int s1_end_indx = s1.length() - 1;

        for(; s1_end_indx >= 0 ; )
        {
            s[s_end_indx] += s1[s1_end_indx--] - 0x30;
            int _s_end_indx = s_end_indx--;
			while(s[_s_end_indx] > '1')
            {
                s[_s_end_indx--] = '0';
                if(_s_end_indx < 0){
                    s.insert(0,1,'1');
                    s_end_indx++;
                    break;
                }
                else
                    s[_s_end_indx] += 1;
            }
        }
        return s;
    }
};

int main(int argc, char **argv)
{
	Solution s;
	
	string s1 = {"0"};
	string s2 = {"1110101100"};

	cout<< s.addBinary(s1, s2)<<endl;
	
return 0;
}


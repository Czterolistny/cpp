#include <string.h>
#include <iostream>

using namespace std;

class Solution {

public:
    string addStrings(string num1, string num2) {
        
        if(num1[0] == '\0')
            return num2;
        if(num2[0] == '\0')
            return num1;
        
        string s = move(num1); 
		string s1 = move(num2);
        
        if(s.length() < s1.length())
            swap(s, s1);
        
		int s_end_indx = s.length() - 1;
        int s1_end_indx = s1.length() - 1;

        while( s1_end_indx >= 0) {
			
            s[s_end_indx] += s1[s1_end_indx--] - 0x30;

            int _s_end_indx = s_end_indx--;
			
            while( s[_s_end_indx] > '9' ){
				
            	s[_s_end_indx--] -= 10;
                if(_s_end_indx < 0){
                	s.insert(0, 1, '1');
					s_end_indx++;
					break;
				}
                s[_s_end_indx] += 1;
            }
   		}
	return s;
	}
};

int main(int argc, char **argv)
{
	Solution s;
	
	string s1 = {"96423702883453279"};
	string s2 = {"72156405165936898"};

	cout<< s.addStrings(s1, s2)<<endl;
	
return 0;
}

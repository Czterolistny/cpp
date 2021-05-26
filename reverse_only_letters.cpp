#include <iostream>
#include <string.h>

using namespace std;

#include <string.h>

class Solution {
	public:
    bool IsLetter(char c){
        if( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') )
            return true;
        return false;
    }
public:
    string reverseOnlyLetters(string S) {
        
        int s_len = S.length();
        int s_end_indx = s_len - 1;
        int i = 0;
        
        for(; ;)
        {
            while( IsLetter(S[i]) == false )
                i++;

            while( IsLetter(S[s_end_indx]) == false )
                s_end_indx--;
            
            if(i < s_end_indx){
                
                char temp = S[i];
                S[i++] = S[s_end_indx];
                S[s_end_indx--] = temp;
                
            }else
                return S;
        }
    }
};

int main(int argc, char **argv)
{
	Solution s;
	string str = {"ab-cdu"};
	
	cout<<s.reverseOnlyLetters(str);

return 0;
}
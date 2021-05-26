#include <math.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
    void UpperLowerCase(string &s, vector<int> letter_indx, int perm_vector)
    {
        for(int i = 0; perm_vector ; ++i)
        {
            if( (perm_vector & 0x01) == true){
                char c = s[letter_indx[i]];
                if( (c >= 'a') && (c <= 'z') )
                    s[letter_indx[i]] = c - 0x20;
                else
                    s[letter_indx[i]] = c + 0x20;
            } 
            perm_vector >>= 1;
        }
    }
    
public:
    vector<string> letterCasePermutation(string S) {
    
        vector<int>letter_indx;
        vector<string> out;

        for(int i = 0; i < S.length(); ++i)
            if( (S[i] - 0x30) > 9)
                letter_indx.push_back(i);
        
        int perm_vect = 0;   
        int perm_cnt = pow(2, letter_indx.size());

        out.push_back(S);
        for(int i = 1; i < perm_cnt; ++i){
            UpperLowerCase(S, letter_indx, i^(i-1));
            out.push_back(S);
        }
        return out;
    }
};

int main(int argc, char** argv)
{
	Solution s;
	
	string str = {"a1b2cd"};
	
	vector<string> string_permutation = s.letterCasePermutation(str);
	
	for(auto s : string_permutation)
		cout<< s <<endl;
	
return 0;
}
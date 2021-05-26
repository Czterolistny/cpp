#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
    
    bool IsValidParentheses(char c1, char c2)
    {
        if( c1 == '(' && c2 == ')' ){}
        else if( c1 == '{' && c2 == '}' ){}
        else if( c1 == '[' && c2 == ']' ){}
        else
            return false;
        return true;
    }
	
    int FindNext(vector<bool> &v, int beg_indx)
	{
		for(int i = beg_indx; i < v.size(); ++i)
		{
			if(v.at(i) == false)
				return i;
		}
		return 0;
	}
	
public:
	
    bool isValid(string s) {
        
        size_t s_len = s.length();
        
        if( s_len == 0)
            return true;
        else if( s_len == 1)
			return false;
        if( s_len % 2 )
            return false;
        
        vector<bool> visited(s_len);
		bool IsChecked; bool found = true;
        
		auto disp = [](auto x){cout<<x<<" ";};
		
		while(found == true){	
			found = false;
			IsChecked = true;
				/* Search for nested parenthesis*/
				for(int i = 0; i < s_len - 1; ++i){
					if(visited.at(i) == false){
						
						for_each(visited.begin(), visited.end(), disp);
						cout<<endl;
						
						IsChecked = false;
						int next_indx = FindNext(visited, i + 1);
						if( next_indx != 0){		
							if( IsValidParentheses(s[i], s[next_indx]) ){
								cout<<s[i]<<" "<<s[next_indx]<<endl;
								
								visited[i] = true;
								visited[next_indx] = true;
								
								i = next_indx;
								found = true;
							}
							i = next_indx - 1;
						}
					}
				}
				if( IsChecked == true )
					return true;
			}
			return false;
    }
};
			   
int main(int argc, char ** argv)
{
    Solution s;    
    string str = "{}[()({[]()()})]()[{}[]]";
	
	cout<< s.isValid(str) <<endl;
    
return 0;
}
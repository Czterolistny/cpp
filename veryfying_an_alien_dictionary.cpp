#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
		for(int i = 0; i < words.size() - 1; ++i)
		{
			int j = 0; bool next_word = false;
			while( (words[i][j] != '\0') && (words[i+1][j] != '\0') )
			{
				int p1 = find(order.begin(), order.end(), words[i][j]) - order.begin();
				int p2 = find(order.begin(), order.end(), words[i+1][j]) - order.begin();

				if( p1 > p2 )
					return false;
				if( p1 < p2 ){
					next_word = true;
					break;
				}
				j++;
				
			}
			if(next_word == false)
				if( words[i].length() > words[i+1].length() )
					return false;
		}
		
		return true;
    }
};

int main(int argcl, char** argv)
{
	vector<string> words = {"kuvp","q"};
	string order = "ngxlkthsjuoqcpavbfdermiywz";
	
	Solution s;
	
	cout<< s.isAlienSorted(words, order) <<endl;
	
return 0;
}


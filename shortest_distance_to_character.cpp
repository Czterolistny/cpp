#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
	
    vector<int> shortestToChar(string S, char C) {
        
        vector<int> min_dist;
        
        vector<int> letter_indx;
        for(int i = 0; i < S.length(); i++){
            if(S[i] == C)
                letter_indx.push_back(i);
		}
        
        for(int i = 0; i < S.length(); i++){
			int _min = INT_MAX;
			for(auto x: letter_indx)
				_min = min( abs(i - x), _min );
			min_dist.push_back(_min);
		}
    return min_dist;                                    
    }
};

int main(int argc, char** argv)
{
	Solution s;
	string str = {"rzazolgxogbmcjjievdt"};
	char c = 'g';
	
	vector<int> out = s.shortestToChar(str, c);
	for(auto c: str)
		cout<<c<<" ";
	cout<<endl;
	for(auto x: out)
		cout<<x<<" ";
	cout<<endl;
	
return 0;
}
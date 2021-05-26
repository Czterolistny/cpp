#include <vector>
#include <iostream>
#include <string>
#include <limits>

using namespace std;

class Solution {
public:
    vector<int> shortestDistance(string S, char C) {
	
		vector<int> pos_idx, min_dist(S.length());
  		
		size_t idx = S.find_first_of(C);
 		while (idx != string::npos)
  		{
			pos_idx.push_back(idx++);
    		idx = S.find_first_of(C, idx);
  		} 
		
		//vector<int>::iterator it = pos_idx.begin();
		//for(int i = 0; i < S.length(); ++i){
		//	
		//	if(pos_idx.size() > 1){
		//		if( abs(i - *it) > abs(i - *(it + 1)) ){
		//			it++;
		//		}
		//	}
		//	min_dist[i] = abs(i - *it);
		//}
		
		for(int i = 0; i < S.length(); ++i){
			int max_dist = numeric_limits<int>::max();
			
			for(auto &x: pos_idx)
				max_dist = min( abs(i - x), max_dist );
			min_dist[i] = max_dist;
		}
		
	return min_dist;
	}
};

int main(int argc, char ** argv)
{
    Solution s;    
    string S = "abaaaaaaaaaaabaaaaaaaaaaaaaaab";
	char C = 'b';
    
	vector<int> out = s.shortestDistance(S, C);
	
	for(auto &x :out)
		cout<< x <<" ";
	cout<<endl;
	
return 0;
}
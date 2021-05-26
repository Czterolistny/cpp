#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int> &A) {
        
        vector<int> squares;
        for(auto &x: A)
            x = x * x;
        
        sort(A.begin(), A.end());
        
    return A;
    }
};

int main(int argc, char** argv)
{
	Solution s;
	vector<int> v = {-7,-3,2,3,11};
	
	vector<int> out = s.sortedSquares(v);
	
	for(auto &x: out)
		cout<< x <<" ";
	cout<<endl;
	
return 0;
}
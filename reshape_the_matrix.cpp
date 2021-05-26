#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        
        int N = nums[0].size();
        int M = nums.size();
		
        if( M * N != r * c)
            return nums;
        if( (M == r) && (N == c) )
			return nums;
		
		vector<vector<int>> out(r);
		
		for(int j = 0, x = 0; j < r; j++){
			for(int i = 0; i < c; i++){
				out[j].push_back(nums[ x++ / N ][ x % N] );
			}
		}			
    return out;
    }
};


int main(int argc, char** argv)
{
	Solution s;
	
	vector<vector<int>> matrix1 = {{1,2,3,4}, 
								   {5,6,7,8},
								   {9,10,11,12},
								   {13,14,15,16}};
	
	vector<vector<int>> out = s.matrixReshape(matrix1, 1, 16);
	
	for(int i = 0; i < out.size(); i++){
		for(auto x: out[i])
			cout<<x<<" ";
		cout<<endl;
	}
	
return 0;
}
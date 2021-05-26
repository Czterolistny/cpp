#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        
        int N = A[0].size();
        int M = A.size();
		
		vector<vector<int>> out(N, vector<int>(M));
		
		for(int j = 0; j < N; j++){
	        for(int i = 0; i < M; i++){
                out[j][i] = A[i][j]; 
            }
		}
    return out;
    }
};

int main(int argc, char** argv)
{
	Solution s;
	
	vector<vector<int>> matrix = {{1,2,3}, 
								   {5,6,7},
								   {9,10,11},
								   {13,14,15}};
	
	vector<vector<int>> out = s.transpose(matrix);
	
	for(int i = 0; i < out.size(); i++){
		for(auto x: out[i])
			cout<<x<<" ";
		cout<<endl;
	}
	
return 0;
}
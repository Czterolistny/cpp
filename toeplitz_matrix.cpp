#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        int M = matrix.size();
        int N = matrix[0].size();

        if((M < 2) || (N < 2))
            return true;
        
        int i = M - 2, j = 1;
        while(i >= 0){   
            for(int k = 0; k < j; ++k)
                if( matrix[i+k][k] != matrix[i+1+k][k+1] )
                    return false;
            if(j < N - 1)
				j++;
			i--;
        }
        
        i = N - 2; j = 1;
        while(i > 0){
            for(int k = 0; k < j; ++k){
                if( matrix[k][i+k] != matrix[k+1][i+1+k] )
                    return false;
			}
			if(j < M - 1)
				j++;
			i--;
        }
        return true;
    }
};

int main(int argc, char **argv)
{
	Solution s;
	vector<vector<int>> matrix = {{11,74,7,93}, 
								  {40,11,74,7}};
	vector<vector<int>> matrix2 = {{10,11},
								   {12,10},
								   {13,12},
								   {14,13}};
	
	cout<< s.isToeplitzMatrix(matrix) <<endl;
	cout<< s.isToeplitzMatrix(matrix2) <<endl;
	
return 0;	
}
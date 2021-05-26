#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
		
        bool is_increasing = true;
        bool is_decreasing = true;
		
        for (int i = 0; i < A.size()-1 ; ++i) {
            if (A[i] > A[i+1]) 
                   is_increasing = false; 
            if (A[i] < A[i+1])
                    is_decreasing = false;
        }
           
    return is_increasing || is_decreasing;
    }
};

int main(int argc, char **argv)
{
	Solution s;
	vector<int> A = {1,2,2,3};
	
	cout<< s.isMonotonic(A) <<endl;
	
return 0;
}
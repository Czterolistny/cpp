#include <string.h>
#include <iostream>

using namespace std;

class Solution {

	string addStrings(string num1, string num2) {
        
        if(num1[0] == '\0')
            return num2;
        if(num2[0] == '\0')
            return num1;
        
        string s = move(num1); 
		string s1 = move(num2);
        
        if(s.length() < s1.length())
            swap(s, s1);
        
		int s_end_indx = s.length() - 1;
        int s1_end_indx = s1.length() - 1;

        while( s1_end_indx >= 0) {
			
            s[s_end_indx] += s1[s1_end_indx--] - 0x30;

            int _s_end_indx = s_end_indx--;
			
            while( s[_s_end_indx] > '9' ){
				
            	s[_s_end_indx--] -= 10;
                if(_s_end_indx < 0){
                	s.insert(0, 1, '1');
					s_end_indx++;
					break;
				}
                s[_s_end_indx] += 1;
            }
   		}
	return s;
	}
	
public:
    string multiply(string num1, string num2) {
        
        if(num1[0] == '\0')
            return num2;
        if(num2[0] == '\0')
            return num1;
		if( (num1[0] == '0') || (num2[0] == '0') )
        	return "0";
		   
        string x = move(num1); 
		string y = move(num2);
        
        if(x.length() < y.length())
            swap(x, y);
        
		string mul_result;
		int x_end_indx = x.length() - 1;
        int y_end_indx = y.length() - 1;
		int _y_end_indx = y_end_indx;
		
		while( y_end_indx >= 0 ){
			
			string part_mul;
			int _y = y[y_end_indx] - 0x30;
			int mul = 0;
			for(int i = x_end_indx; i >= 0; i--) {
				
				mul += _y * (x[i] - 0x30);
				part_mul.insert(0, 1, (mul % 10) + 0x30 );
				mul /= 10;
			}
			if( mul > 0)
				part_mul.insert(0, 1, mul + 0x30);
			part_mul.insert( part_mul.end(), _y_end_indx - y_end_indx--, '0');
			mul_result = addStrings(mul_result, part_mul);
		}
	return mul_result;
	}
};

int main(int argc, char **argv)
{
	Solution s;
	
	string s1 = {"99990"};
	string s2 = {"0"};

	cout<< s.multiply(s1, s2)<<endl;
	
return 0;
}


#include <iostream>
#include <string.h>

using namespace std;

class Solution {
    
    void setPos(int *pos, char direct)
    {
        switch (direct){
            case 'U':
                *pos += 1;
                break;
            case 'D':
                *pos -= 1;
                break;
            case 'L':
                *(++pos) -= 1;
                break;
            case 'R':
                *(++pos) += 1;
                break;
            default:
                break;
        }
    }
public:
    bool judgeCircle(string moves) {
        
        int s_len = moves.length();
        int pos[2] = {0,0};
        
        for(int i = 0; i < s_len; ++i)
            setPos(&pos[0], moves[i]);
        
        if( (pos[0] == 0) && (pos[1] == 0) )
            return true;
        
        return false;      
    }
};

int main(int argc, char **argv)
{
	Solution s;
	string str = {"RRDD"};
	
	cout<<s.judgeCircle(str)<<endl;

return 0;
}
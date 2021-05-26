#include <iterator>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {

public:
    int numUniqueEmails(vector<string>& emails) {
        	
		int indx;
		unordered_set<string> parsed_mail;
		
		for(int i = 0; i < emails.size(); i++)
		{
			if( (indx = emails[i].find("+")) != string::npos)
				emails[i].erase(indx, emails[i].find("@") - indx);

			while( (indx = emails[i].find_first_of(".")) < emails[i].find("@") )
				emails[i].erase(indx, 1);
			parsed_mail.insert(move(emails[i]));
		}
		
    return  parsed_mail.size();
    }
};

int main(int argc, char **argv)
{
	Solution s;
	vector<string> emails = {{"test.email+alex@leetcode.com"},
							 {"test.e.mail+bob.cathy@leetcode.com"},
							 {"testemail+david@lee.tcode.com"}};
	
	cout<< s.numUniqueEmails(emails) <<endl;
	
return 0;
}
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>


#define USE_INPUT_FILE

using namespace std;

class ElephRunway
{
public:
	~ElephRunway();
	ElephRunway(){};

	uint32_t Solve(const vector<int>&a, const vector<int> &b, const vector<int> &cost);
};

uint32_t ElephRunway::Solve(const vector<int> &a, const vector<int> &b, const vector<int> &cost)
{
	int n = a.size();
	/* Permutation vector */
	vector<uint32_t> p(n);
	for(int i = 0; i < n; i++)
		p.at(b.at(i)-1) = a.at(i) - 1;

	/* Cycle's array */
	vector<vector<int>> C(n);
	/* Cycle counter */
	uint32_t cyc_cnt(0), x;
	vector<uint8_t> visit(n, false);
	
	for(uint32_t i = 0; i < n; i++) {
		if(visit[i] == false) {
			x = i;
			while(visit.at(x) == false)
			{
				visit.at(x) = true;
				x = p.at(x);
				C[cyc_cnt].push_back(p.at(x));
			}
			cyc_cnt++;
		}
	}

	uint32_t min_C;
	vector<uint32_t> sum_c(cyc_cnt), min_c(cyc_cnt, UINT_MAX);
	for(uint32_t i = 0; i < cyc_cnt; i++) { 
		for(auto x : C[i]) {
			sum_c.at(i) += cost.at(x);
			min_c.at(i) = min_c.at(i) < cost.at(x) ? min_c.at(i): cost.at(x);
		}
	}
	min_C = *min_element(begin(min_c), end(min_c));
	
	uint32_t res = 0;
	uint32_t m1_sum, m2_sum;
	for(uint32_t i = 0; i < cyc_cnt; i++){
		m1_sum = sum_c.at(i) + (C[i].size() - 2) * min_c.at(i);
		m2_sum = sum_c.at(i) + min_c.at(i) + (C[i].size() + 1) * min_C;
		res += (m1_sum < m2_sum) ? m1_sum: m2_sum;
	}

return res;
}

int main(int argc, char ** argv)
{
	
	int n;
	vector<int> a, b, cost;
	
	int tmp;
	string in;
	
	getline(cin, in);
	if( in.size() == 0 )
		return -1;
	n = stoi(in);
	if(n < 1)
		return -1;
	getline(cin, in); istringstream str_cost(in);
	while(str_cost >> tmp)
		cost.push_back(tmp);
	getline(cin, in); istringstream str_a(in);
	while(str_a >> tmp)
		a.push_back(tmp);
	getline(cin, in); istringstream str_b(in);
	while(str_b >> tmp)
		b.push_back(tmp);
	
	if( (a.size() != b.size()) || (cost.size() != n) )
		return -1;
		
	auto er = new ElephRunway();
	uint32_t res = er->Solve(a, b, cost);
	cout<<res<<endl;

return 0;
}
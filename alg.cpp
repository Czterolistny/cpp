#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

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
	
	if( argc < 2 )
		return -1;
	
	ifstream inFile;
	inFile.open(argv[1]);
	
	if( !(inFile.is_open()) )
		return -1;
	
	int n;
	inFile>>n; 
	vector<int> a(n);
	vector<int> b(n);
	vector<int> cost(n);
	
	int temp;
	for(int i = 0; i < n; i++){
		inFile >> temp; cost[i] = temp; }
	for(int i = 0; i < n; i++){
		inFile >> temp; a[i] = temp; }
	for(int i = 0; i < n; i++){
		inFile >> temp; b[i] = temp; }
	
	inFile.close();
	
	auto er = new ElephRunway();
				  
	uint32_t res = er->Solve(a, b, cost);
	cout<<res<<endl;
	
	/*string ResPath = argv[1];
	ResPath.replace(ResPath.end() - 2, ResPath.end(), "out");
	
	ifstream ResFile;
	ResFile.open(ResPath);
	uint32_t _res;  ResFile >> _res;
	if(_res == res)
		cout<<"OK"<<endl;
	else
		cout<<"nie OK"<<endl;
	ResFile.close();*/

return 0;
}
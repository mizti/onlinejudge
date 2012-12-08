#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <queue>
using namespace std;

class Knapsac {
public:
	vector<int> w;
	vector<int> p;
	int max_weight;
	int calc(int max_w, vector<int> ws, vector<int> ps){
		w = ws;
		p = ps;
		max_weight = max_w;
		return 1;
	}
	int max_value(){
		
	}
};

int main(){
	Knapsac knap;
	vector<int> ws;
	ws.push_back(3);
	ws.push_back(4);
	ws.push_back(1);
	ws.push_back(2);
	ws.push_back(3);
	
	vector<int> ps;
	ps.push_back(2);
	ps.push_back(3);
	ps.push_back(2);
	ps.push_back(3);
	ps.push_back(6);
	cout << knap.max_value(10, ws, ps);
}

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <queue>
using namespace std;

class InfiniteSequence2 {
public:
	int pv, qv, xv, yv;
	map<long, long> memo;
	long long calc(long long n, int p, int q, int x, int y){
		pv = p;
		qv = q;
		xv = x;
		yv = y;
		long long ret = a(n);
		return ret;
	}
	long long a(long long n){
		if(n <= 0){
			return 1;
		}
		if(memo[n] != 0) return memo[n];
		long long ret = a(n/pv - xv) + a(n/qv - yv);
		if(n < 10000000000){
			memo[n] = ret;
		}
		return ret;
	}
};

int main(){
	InfiniteSequence2 is;
	cout << is.calc(10000000000000, 2, 2, 0, 10131990);
}

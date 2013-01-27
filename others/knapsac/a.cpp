#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <queue>
#include <math.h>
//using namespace std;
int ws[5] = {3, 4, 1, 2, 3};
int ps[5] = {2, 3, 2, 3, 6};
int max = 10;
int dp[6][11];

int knapsack(int n, int w){
	if(w>max) return -1;
	if(n>=5) return 0;
	if(dp[n][w] >= 0) return dp[n][w];
	int a = knapsack(n+1, w);
	int b = knapsack(n+1, w+ ws[n]) + ps[n];
	if(a>b){
		dp[n][w] = a;
		return a; 
	}else{
		dp[n][w] = b;
		return b;
	}
}
int main(){
	for(int i=0; i<6 ; i++){
		for(int j=0; j<11; j++){
			dp[i][j] = -1;
		}
	}
	printf("%d", knapsack(0,0));	
}

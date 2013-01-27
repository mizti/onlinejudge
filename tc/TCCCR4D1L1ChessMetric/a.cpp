#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <iostream>
using namespace std;

class ChessMetric {
public:
	vector<int> start_place;
	vector<int> end_place;
	int sizeNum;
	
	long long howMany(int size, vector<int> start, vector<int> end, int numMoves){
		start_place = start;
		end_place = end;
		sizeNum = size;
		long long dp[110][110][55] = {0};
		vector<int> moveX {0,1,1,1 ,0, -1,-1,-1,2 , 1,-1,-2,-2,-1,1,2};
		vector<int> moveY {1,1,0,-1,-1,-1,0 , 1,-1,-2,-2,-1, 1, 2,2,1};
		long long patterns = 0;
		
		dp[start[0]][start[1]][0] = 1;
		for(int i=1; i <= numMoves ; i++){
			for(int x = 0; x <= size ; x++){
			for(int y = 0; y <= size ; y++){
				for(int j = 0; j < 16 ; j++){
					int px = x - moveX[j];
					int py = y - moveY[j];
					if(px<0||px>=size||py<0||py>=size) continue;
					dp[x][y][i] += dp[px][py][i-1];
					//cout<<x;
					//cout<<" ";
					//cout<<y;
					//cout<<" ";
					//cout<<i<<endl;
					//dp[100][17][1] += 1;
					//dp[x][y][i] += 1;
				}
			}
			}
		}
		return dp[end[0]][end[1]][numMoves];
	}
};

int main(){
	ChessMetric cm;
	int size = 100;
	vector<int> start{0,0};
	vector<int> end{0,99};
	int numMoves = 50;
	cout << cm.howMany(size, start, end, numMoves);
}

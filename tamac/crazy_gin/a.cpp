#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <math.h>
using namespace std;

class CrazyGin {
  public:
    long double possibility(int numMoves){
      long long case_num = 0;
      for(int m = 1; m <= numMoves ; m++){
	case_num += killAt(m, numMoves);
      }
      long double pos = (long double)case_num;
      for(int m = 1; m <= numMoves ; m++){
	pos = pos / 5;
      }
      return pos;
    }

    long long killAt(int m, int numMoves){
      if (m%2 == 1){
	return 0;
      }
      return untilKillKing(m) * afterKillKing(numMoves - m);
    }

    // 王をm手目にちょうど倒す場合の数
    long long untilKillKing(int m){
      vector<int> moveX = {-1, 0, 1,-1, 1};
      vector<int> moveY = {-1,-1,-1, 1, 1};
      long long board[9][9] = {0}; //board[x][y]
      long long nextBoard[9][9] = {0}; //次の内容
      vector<int> friendPosX = {4, 5, 7, 2, 5, 2, 3, 7, 0, 1, 6, 8, 3, 5, 0, 1, 2, 4,6, 7, 8}; //王と味方の位置
      vector<int> friendPosY = {0, 4, 3, 4, 4, 5, 5, 5, 6, 6, 6, 6, 7, 7, 8, 8, 8, 8,8, 8, 8}; //王と味方の位置
      board[4][4] = 1; //初期位置

      long long numPattern = 0;
      for(int i = 0; i < m ; i++){
	for(int x = 0; x < 9 ; x++){
	  for(int y = 0; y < 9 ; y++){
	    for(int j = 0; j < moveX.size(); j++){
	      if(x + moveX[j] >= 0 && x + moveX[j] < 9 
		  && y + moveY[j] >= 0 && y + moveY[j] < 9){
		nextBoard[x + moveX[j]][y + moveY[j]] += board[x][y];
	      }
	    }
	  }
	}
	numPattern = nextBoard[4][0];
	//nextBoardをboardにコピー。その際、味方等の位置は0に
	for(int y = 0; y < 9 ; y++){
	  for(int x = 0; x < 9 ; x++){
	    board[x][y] = nextBoard[x][y];
	    nextBoard[x][y] = 0;
	  }
	}
	for(int k = 0; k < friendPosX.size(); k++){
	  board[friendPosX[k]][friendPosY[k]] = 0;
	}
      }
      return numPattern;
    }

    // 王を倒したあとremainingSteps動く場合の数
    long long afterKillKing(int remainingSteps){
      vector<int> moveX = {-1, 0, 1,-1, 1};
      vector<int> moveY = {-1,-1,-1, 1, 1};
      long long board[9][9] = {0}; //board[x][y]
      long long nextBoard[9][9] = {0}; //次の内容
      vector<int> friendPosX = {5, 7, 2, 5, 2, 3, 7, 0, 1, 6, 8, 3, 5, 0, 1, 2, 4,6, 7, 8}; //味方の位置
      vector<int> friendPosY = {4, 3, 4, 4, 5, 5, 5, 6, 6, 6, 6, 7, 7, 8, 8, 8, 8,8, 8, 8}; //味方の位置
      board[4][0] = 1; //初期位置
      long long numPattern = 0;
      for(int i = 0; i < remainingSteps ; i++){
	for(int x = 0; x < 9 ; x++){
	  for(int y = 0; y < 9 ; y++){
	    for(int j = 0; j < moveX.size(); j++){
	      if(x + moveX[j] >= 0 && x + moveX[j] < 9 
		  && y + moveY[j] >= 0 && y + moveY[j] < 9){
		nextBoard[x + moveX[j]][y + moveY[j]] += board[x][y];
	      }
	    }
	  }
	}
	//nextBoardをboardにコピー。その際、味方等の位置は0に
	for(int y = 0; y < 9 ; y++){
	  for(int x = 0; x < 9 ; x++){
	    board[x][y] = nextBoard[x][y];
	    nextBoard[x][y] = 0;
	  }
	}
	for(int k = 0; k < friendPosX.size(); k++){
	  board[friendPosX[k]][friendPosY[k]] = 0;
	}
      }

      for(int y = 0; y < 9 ; y++){
	for(int x = 0; x < 9 ; x++){
	  numPattern += board[x][y];
	}
      }
      return numPattern;
    }
};

int main(){
  CrazyGin cg;
  int numMoves = 20;
  cout << cg.possibility(numMoves);
}

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <iostream>
using namespace std;

class MazeMaker {
public:
	int stepMap[50][50];
	vector <int> moveRows, moveCols;
	vector <string> mazeMap;
	int longestPath(vector <string> maze, int startRow, int startCol, vector <int> moveRow, vector <int> moveCol){
		moveRows = moveRow;
		moveCols = moveCol;
		mazeMap = maze;
		// stepMap配列を初期化
		for(int i=0; i<maze.size() ;i++){
			for(int j=0; j<maze[0].size() ; j++){
				if(maze[i].substr(j,1) == "."){
					stepMap[i][j] = INT_MAX;
				}else if(maze[i].substr(j,1) == "#"){
					stepMap[i][j] = -1;
				}
			}
		}
		stepMap[startRow][startCol] = 0;
		for(int i=0; i<moveRow.size() ; i++){
			jump(startRow, startCol, moveRow[i], moveCol[i], 1);
		}
		int maxStep = 0;
		for(int i=0; i<maze.size() ;i++){
			for(int j=0; j<maze[0].size(); j++){
				if(stepMap[i][j]>maxStep) maxStep = stepMap[i][j];
			}
		}
		if(maxStep == INT_MAX) maxStep = -1;
		return maxStep;
	}
	void jump(int startRow, int startCol, int moveY, int moveX, int num_step){
		int x = startCol + moveX;
		int y = startRow + moveY;
		if(y >= mazeMap.size() || y < 0){
			return;
		}
		if(x >= mazeMap[0].size() || x < 0){
			return;	
		}
		if(num_step >= stepMap[y][x]){
			return;
		}
		if(stepMap[y][x] == -1){
			return;
		}
		stepMap[y][x] = num_step;
		for(int i=0; i<moveRows.size() ; i++){
			jump(y, x, moveRows[i], moveCols[i], num_step+1);
	//		dump_stepMap();
		}
	}
	void dump_stepMap(){
		for(int i=0; i < mazeMap.size() ;i++){
			for(int j=0; j < mazeMap[0].size(); j++){
				cout << stepMap[i][j] << " ";
			}
			cout << endl;
		}
			cout << endl;
			cout << endl;
	}
};

int main(){
	MazeMaker mm;
	vector <string> maze;
	maze.push_back("..#");
	maze.push_back(".#.");
	maze.push_back(".#.");
	maze.push_back("...");
	int startRow = 0;
	int startCol = 1;
	vector <int> moveRow;
	moveRow.push_back(1);
	moveRow.push_back(0);
	moveRow.push_back(-1);
	moveRow.push_back(0);
	vector <int> moveCol;
	moveCol.push_back(0);
	moveCol.push_back(1);
	moveCol.push_back(0);
	moveCol.push_back(-1);
	cout << mm.longestPath(maze, startRow, startCol, moveRow, moveCol);
}

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <queue>
using namespace std;

class MazeMaker {
public:
	int stepMap[50][50];
	vector <int> moveRows, moveCols;
	vector <string> mazeMap;
	queue<int> queueX;
	queue<int> queueY;
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


		queueX.push(startCol);
		queueY.push(startRow);
		stepMap[startCol][startRow] = 0;
		while(queueX.size() > 0){
			//jump_from(queueX.pop(), queueY.pop());
			hoge(2,2);
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
	void hoge(int x, int y){
		cout <<"hoge"<<endl;
	}
	void jump_from(int x, int y){
		int current_step = stepMap[x][y];
		for(int i=0; i < moveRows.size(); i++){
			int next_x = x + moveCols[i];
			int next_y = y + moveRows[i];
			if(next_y >= mazeMap.size() || next_y < 0){
				continue;
			}
			if(next_x >= mazeMap[0].size() || next_x < 0){
				continue;	
			}
			if(stepMap[next_y][next_x] <= current_step + 1){
				continue;
			}
			if(stepMap[next_y][next_x] == -1){
				continue;
			}
			stepMap[next_y][next_x] = current_step + 1;
			queueX.push(next_x);
			queueY.push(next_y);
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

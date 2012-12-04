#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <iostream>
using namespace std;

class CrazyBot {
public:
	double p_east;
	double p_west;
	double p_south;
	double p_north;
	double getProbability(int n, int east, int west, int south, int north){
		double probability = 1.0;
		p_east = east/100.0;
		p_west = west/100.0;
		p_south = south/100.0;
		p_north = north/100.0;
		bool trail[30][30] = {0}; 
		trail[15][15] = true;
		//15, 15を原点として歩行開始
		double h = 0;
		h += walk(n-1, 15, 15, "south", trail, probability * p_south);
		h += walk(n-1, 15, 15, "north", trail, probability * p_north);
		h += walk(n-1, 15, 15, "east", trail, probability * p_east);
		h += walk(n-1, 15, 15, "west", trail, probability * p_west);
		return h;
	}

	void dump_trail(bool trail[30][30]){
		for(int i=29; i >= 0 ; i--){
			for(int j=29 ; j>=0 ; j--){
				cout << trail[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
	double walk(int remaining_steps, int x ,int y, string direction, bool trail[30][30], double probability){
		// 指示された方向に一歩進む
		if(direction == "east"){
			x += 1;
		}else if(direction == "west"){
			x -= 1;
		}else if(direction == "south"){
			y -= 1;
		}else if(direction == "north"){
			y += 1;
		}
		// 進んだ場所がすでに踏んだ場所なら探索を打ち切る、そうでなければフラグを立てる
		if(trail[y][x]){
			return 0;
		}else{
			trail[y][x] = true; //きちんと足あとを消す
			//dump_trail(trail);
		}
		if(remaining_steps == 0)
		{
			trail[y][x] = false; //きちんと足あとを消す
			return probability;
		}

		// 次の一歩をすすめる
		double h = 0;
		if(p_east > 0.0){
			h += walk(remaining_steps - 1, x, y, "east", trail, probability * p_east);
		}
		if(p_south > 0.0){
			h += walk(remaining_steps - 1, x, y, "south", trail, probability * p_south);
		}
		if(p_north > 0.0){
			h += walk(remaining_steps - 1, x, y, "north", trail, probability * p_north);
		}
		if(p_west > 0.0){
			h += walk(remaining_steps - 1, x, y, "west", trail, probability * p_west);
		}
		trail[y][x] = false; //きちんと足あとを消す
		return h;
	}
};

int main(){
	CrazyBot cb;
	cout << cb.getProbability(1, 25, 25, 25, 25) <<endl;
	CrazyBot cb2;
	cout << cb2.getProbability(2, 25, 25, 25, 25) <<endl;
	CrazyBot cb3;
	cout << cb3.getProbability(7, 50, 0, 0, 50) << endl;
	CrazyBot cb4;
	cout << cb4.getProbability(14, 50, 50, 0, 0) << endl;
	CrazyBot cb5;
	cout << cb5.getProbability(14, 25, 25, 25, 25) << endl;
}

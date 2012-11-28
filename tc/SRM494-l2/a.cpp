#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

class Painting {
public:
	int largestBrush(vector<string> picture)
	{
		int m = picture.size();
		if(picture.size() > picture[0].size()){
			m = picture[0].size();
		}
		int max = m;
		for(m+1;m >= 1;m--){
			max = m;
			int allblock_paintable = true;
			for(int y=0; y<picture.size();y++){
			for(int x=0; x<picture[0].size();x++){
				if(picture[y].substr(x,1) == "W") continue;
				if(!is_paintable(picture, x, y, m)){allblock_paintable = false;}
			}
			}
			if(allblock_paintable){ break;}
		}
		return max;
	}
	
	bool is_paintable(vector<string> pic, int x, int y, int m)
	{
		for(int i = 0; i < m ; i++){
			for(int j = 0; j < m ; j++){
				if(x-i>=0 && y-j>=0 && x-i + m-1<pic[0].size() && y-j + m-1<pic.size()){
					if(!is_containing_W(pic, x-i, y-j, m)){
						return true;
					}
				}
			}
		}
		return false;
	}
	// x, y を一番左上として、m*mの正方形内にWが含まれるかどうか
	bool is_containing_W(vector<string> pic, int x, int y, int m)
	{
		for(int i = y; i<y+m ; i++){
			for(int j=x;j<x+m;j++){
				if(pic[i].substr(j, 1) == "W"){
					 return true;
				}
			}
		}
		return false;
	}
};

int main(){
	vector <string> picture;
	picture.push_back("WWWW");
	picture.push_back("BBBW");
	picture.push_back("WBBW");
	picture.push_back("WBBW");
	picture.push_back("WBBW");
	picture.push_back("WWWW");
	Painting pt;

	cout << pt.largestBrush(picture);
}

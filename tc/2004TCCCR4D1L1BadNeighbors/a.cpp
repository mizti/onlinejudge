#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <iostream>
using namespace std;

class BadNeighbors {
public:
	vector<int> donation_list;
	bool zero_was_selected;
	map<bool, map<bool, map<int, map<int, int>>>> dp;

	int maxDonations(vector<int> donations){
		donation_list = donations;
		zero_was_selected = false;
		int j =  calc(0, 0, false);
		return j;
	}

	//i番目の要素が選ばれたときと選ばれてないときの大きい方を返す
	int calc(int i, int current_donation, bool was_selected){
		if(i == 1)
		{
			if(was_selected){zero_was_selected = true;}
			else{ zero_was_selected = false; }
		}
		if(i == donation_list.size()-1){
			if(zero_was_selected || was_selected){
				return current_donation;
			}
			return current_donation + donation_list[i];
		}
		if(dp[zero_was_selected][was_selected][current_donation][i] > 0) return dp[zero_was_selected][was_selected][current_donation][i];
		
		if(was_selected){
			return calc(i+1, current_donation, false);
		}else{
			int selected = calc(i+1, current_donation + donation_list[i], true);
			int no_selected = calc(i+1, current_donation, false);
			if(selected > no_selected){
				return dp[zero_was_selected][was_selected][current_donation][i] = selected;
			}else
			{
				return dp[zero_was_selected][was_selected][current_donation][i] = no_selected;
			}
		}
	}
};

int main(){
	BadNeighbors bn;
	vector<int> donations{1,2,3,4,5,1,2,3,4,5};
	cout << bn.maxDonations(donations);
}

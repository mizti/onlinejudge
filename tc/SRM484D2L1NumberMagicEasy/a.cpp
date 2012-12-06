#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <iostream>
using namespace std;

class NumberMagicEasy {
public:
	int theNumber(string answer){
		int result = 0;
		unsigned short cards[4];
		cards[0] = 0xFF00;
		cards[1] = 0xF0F0;
		cards[2] = 0xCCCC;
		cards[3] = 0xAAAA;

		for(int i = 0; i < answer.size() ; i++){
			if(answer.substr(i,1) == "Y") cards[i]=cards[i];
			if(answer.substr(i,1) == "N") cards[i]=~cards[i];
		} cout << endl;
		cards[0] = cards[0] & cards[1] & cards[2] & cards[3];
		unsigned short mask=1 << (sizeof(unsigned short)*8-1);
		int i;
		for(i = 0; i < sizeof(unsigned short)*8 ; i++){
			if(cards[0]&mask){
			//	printf("1");
				break;
			}else{
			//	printf("0");
			}
			mask >>= 1;
		}
		return i+1;
	}
};

int main(){
	NumberMagicEasy nm;
	cout << nm.theNumber("NNNN");
}

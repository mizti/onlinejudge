#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

class Cryptography {
public:
	long long encrypt(vector <int> numbers){
		int max = 0;
		for(int i = 0; i<numbers.size();i++){
			vector <int> copy(numbers);
			copy[i] = copy[i] + 1;
			for(int m=0; m<copy.size();m++){
				cout << copy[m];
				cout << endl;
			}
			if(multipler(copy)>max){
				max = multipler(copy);
			}
		}
		return max;
	}
	long long multipler(vector <int> numbers){
		int ans=1;
		for(int i = 0; i<numbers.size(); i++){
			ans *= numbers[i];
		}
		return ans;
	}
};

int main(){
	vector <int> numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	Cryptography cg;
	cout << cg.encrypt(numbers);
}

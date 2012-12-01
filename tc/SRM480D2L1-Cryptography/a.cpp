#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

class Cryptography {
public:
	long long encrypt(vector <int> numbers){
		long long max = 0;
		for(int i = 0; i<numbers.size();i++){
			vector <int> copy(numbers);
			copy[i] = copy[i] + 1;
			if(multipler(copy)>max){
				max = multipler(copy);
			}
		}
		return max;
	}
	long long multipler(vector <int> numbers){
		long long ans=1;
		for(int i = 0; i<numbers.size(); i++){
			ans *= numbers[i];
		}
		return ans;
	}
};

int main(){
	vector <int> numbers;
	numbers.push_back(1000);
	numbers.push_back(999);
	numbers.push_back(998);
	numbers.push_back(997);
	numbers.push_back(996);
	numbers.push_back(995);
	Cryptography cg;
	cout << cg.encrypt(numbers);
}

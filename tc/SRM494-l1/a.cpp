#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

class InterestingParty {
public:
	int fuga;
	int bestInvitation(vector <string> first, vector <string> second)
	{
		int max = 0;
		for(int i=0;i<first.size();i++){
			string word = first[i];
			int num_person = 0;
			for (int j=0;j<first.size();j++){
				if(first[j] == word || second[j] == word) num_person++;
			}
			if(num_person > max){
				max = num_person;
			}
		}

		for(int i=0;i<second.size();i++){
			string word = second[i];
			int num_person = 0;
			for (int j=0;j<first.size();j++){
				if(first[j] == word || second[j] == word) num_person++;
			}
			if(num_person > max){
				max = num_person;
			}
		}
		return max;
	}
};

int main(){
	vector <string> first;
	vector <string> second;
	first.push_back("a");
	first.push_back("b");
	first.push_back("c");
	first.push_back("d");

	second.push_back("e");	
	second.push_back("f");	
	second.push_back("g");	
	second.push_back("h");	
	InterestingParty ip;
	cout << ip.bestInvitation(first, second);

}

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

class InterestingParty {
public:
	int fuga;
	int bestInvitation(vector <string> first, vector <string> second)
	{
		map <string, int> dic;
		for(int i=0;i<first.size();i++){
			dic[first[i]] = 0;
			dic[second[i]] = 0;
		}
		
		for(int i=0;i<first.size();i++){
			dic[first[i]]++;
			dic[second[i]]++;
		}

		int ans=0;
		map <string, int>::iterator it;
		for( it = dic.begin(); it != dic.end(); it++){
			if(ans < it->second) ans = it->second;
		}

		return ans;
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
	second.push_back("a");	
	second.push_back("h");	
	InterestingParty ip;
	cout << ip.bestInvitation(first, second);

}

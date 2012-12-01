#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

class TheLuckyString {
public:
	map <string, int> dic;
	int count(string s){
		perm(s, "");
		//cout << dic.size() << endl;
		return dic.size();
	}
	bool is_lucky(string s){
		for(int i=0; i<s.size()-1 ;i++){
			if(s[i] == s[i+1]){
				return false;
			}
		}
		return true;
	}
	string perm(string s, string t){
		if(s.size()==0){
			if(is_lucky(t)){
				dic[t] = 1;
				//cout << t << "is lucky!" << endl;
			}
		}else{
			for(int i=0;i<s.size();i++){
				string new_s;
				string new_t;
				new_s = s;
				new_t = t + s.at(i);
				string space = "";
				perm(new_s.replace(i,1,space), new_t);
			}
		}
		return s;
	}
	int pow(int i){
		if(i==1 || i==0){
			return 1;
		}
		return i * pow(i-1);
	}
};

int main(){
	TheLuckyString ls;
	ls.count("123433");
}

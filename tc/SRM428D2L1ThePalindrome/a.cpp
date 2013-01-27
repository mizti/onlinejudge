#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

class ThePalindrome {
public:
	int find(string s){
		for(int i=0;i<=s.size();i++){
			if(is_palindrome(s + reverse(s.substr(0,i)))){
				return i + s.size();
			}
		}
		return 2 * s.size();
	}
	bool is_palindrome(string s){
		for(int i=0; i < s.size()/2 ; i++){
			if(s.substr(i, 1) != s.substr(s.size()-1-i, 1) ){
				return false;
			}
		}
		return true;
     	}
	string reverse(string s){
		string reversed = "";
		for(int i=s.size()-1; i>=0 ;i--){
			reversed = reversed + s.at(i);
		}
		return reversed;
	}
};

int main(){
	ThePalindrome pl;
	cout << pl.find("sboo");
}

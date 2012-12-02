#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <iostream>
using namespace std;

int main(){
	vector <string> friends;
        friends.push_back("NYNYY");
	map <int, int> direct_friends;
        for(int j = 0; j<friends[0].size() ; j++){
              if(friends[0].substr(j,1) == "Y"){
                    cout << j << "hoge" << endl;
                    direct_friends.insert( map<int, int>::value_type(j, 1));
              }
        }
        map <int, int> indirect_friends;
        map <int, int>::iterator it;
        for( it = direct_friends.begin() ; it != direct_friends.end() ;it++){
                  cout << it->first;
                  cout << "->";
                  cout << it->second << endl;
        } 
        cout << "num friends" << endl;
}


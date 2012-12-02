#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <iostream>
using namespace std;

class FriendScore {
public:
	int highestScore(vector <string> friends)
	{
		int max_friend = 0;
		for(int i = 0; i<friends.size() ; i++){
			map <int, int> direct_friends;
			int num_direct_friends = 0;
			for(int j = 0; j<friends[i].size() ; j++){
				if(friends[i].substr(j,1) == "Y"){
					//cout << j << "hoge" << endl;
					num_direct_friends += 1;
					direct_friends[j] = 1;
				}
			}
			map <int, int> indirect_friends;
			map <int, int>::iterator it;
			for( it = direct_friends.begin() ; it != direct_friends.end() ;it++){
				//cout << it->first;
				//cout << "->";
				//cout << it->second << endl;
				if(it->second == 0) continue;
				for(int m = 0; m < friends[0].size() ; m++){
					if(friends[it->first].substr(m,1)=="Y" && i!=m && direct_friends[m]!=1){
				//		cout << "indirect_friend: " << m << endl;
						indirect_friends[m] = 1;
					}
				}
			}
			//cout << "num friends" << endl;
			//cout << num_direct_friends << endl;
			//cout << indirect_friends.size() << endl;
			//cout << "--------" << endl;
			if(max_friend < num_direct_friends + indirect_friends.size()){
				max_friend = num_direct_friends + indirect_friends.size();
			}
		}
		return max_friend;
	}
};

int main(){
	FriendScore fs;
	vector <string> friends;
	friends.push_back("NYNNN");
	friends.push_back("YNYNN");
	friends.push_back("NYNYN");
	friends.push_back("NNYNY");
	friends.push_back("NNNYN");
	cout << fs.highestScore(friends) << endl;
cout << endl;
cout << endl;
cout << endl;
	FriendScore fs2;
	vector <string> friends2;
	friends2.push_back("NYNN");
	friends2.push_back("YNYY");
	friends2.push_back("NYNY");
	friends2.push_back("NYYN");
	cout << fs2.highestScore(friends2) << endl;
}

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <iostream>
using namespace std;

class CutSticks {
public:
	long long maxKth(vector<int> sticks, int C, int K){
    double low = 0;
    double high = 1000000000;
      cout << low << "," << high << endl;
    int i,j;
    for(i=0; i<100; i++) //この回数だけ2分探索
    {
      long count = 0;
      double mid = (low + high) / 2;
      long cut = 0;
      cout << mid << "," << low << "," << high << endl;

      //長さmidをとれる回数がK以上あるかどうかカウントする
      for (j=0; j < sticks.size(); j++)
      {
        long next = (long)(sticks[j] / mid); //j番目の枝からmidの長さを作れる回数
        cut += max((long)0, (next - 1)); //そのために要した切る回数
        count += next; //midの長さを切り出せた回数を足す
      }
      count -= max((long int)0, cut - C); //カットした回数が制限回数を超えていた場合、その回数分だけ切り出せた本数を減らしておく

      if(count >= K){
        low = mid; //このmidの長さでK本作れたら下限をmidに
      }else
      {
        high = mid; //このmidの長さでK本作れなかったら上限をmidに
      }
    }
    return low;
	}
};

int main(){
	CutSticks cs;

  //vector<int> sticks{1000000000,1000000000,1};
  //int C = 2;//Cut;
  //int K = 5;//Rank;
  // -> 1
  vector<int> sticks{76,594,17,6984,26,57,9,876,5816,73,969,527,49};
  int C = 789;//Cut;
  int K = 459;//Rank;
	cout << cs.maxKth(sticks, C, K);
}

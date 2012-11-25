#include <vector>
using namespace std;

class KiwiJuiceEasy
{
public:
	vector <int> thePouring(vector <int> capacities,
				vector <int> bottles,
				vector <int> fromId,
				vector <int> toId)
	{
		for(int i = 0 ; i<fromId.size(); i++)
		{
			int space = capacities[toId[i]] - bottles[toId[i]];
			if( space >= bottles[fromId[i]] ){
				bottles[toId[i]] = bottles[fromId[i]] + bottles[toId[i]];
				bottles[fromId[i]] = 0;
			} else {
				bottles[toId[i]] = capacities[toId[i]];
				bottles[fromId[i]] = bottles[fromId[i]] - space;
			}
		}
		return bottles;
	}
};

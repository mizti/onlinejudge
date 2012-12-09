#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <iostream>
using namespace std;

class CorporationSalary {
public:
	vector<string> relation;
	map <long, long> salaries;
	long totalSalary(vector<string> relations){
		long total = 0;
		relation = relations;
		
		for(int i = 0; i<relations.size() ;i++){
			total += salary_of(i);
		}
		return total;
	}
	long salary_of(int i){
		if(salaries[i] > 0) return salaries[i];
		long salary = 0;
		for(int j=0; j<relation[i].size() ; j++){
			if(relation[i].substr(j,1) == "Y"){
				salary += salary_of(j);
			}
		}
		if(salary == 0){
			salary = 1;
		}
		salaries[i] = salary;
		return salary;
	}
};

int main(){
	CorporationSalary cs;
	vector<string> relations;
	relations.push_back("NYNNYN");
	relations.push_back("NNNNNN");
	relations.push_back("NNNNNN");
	relations.push_back("NNYNNN");
	relations.push_back("NNNNNN");
	relations.push_back("NNNYYN");
	cout << cs.totalSalary(relations);
}

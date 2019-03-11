#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef std::vector<int> V;

int count_min(V tasks){
	int sum = 0;
	for_each(tasks.begin(), tasks.end(), [&](int n) {sum += n;} );
	return sum;
}

int sum_till(V tasks, int till) {
	int sum = 0;

	for (int i = 0; i <= till; i++) {
		sum += tasks[i];
	}
	return sum;
}

int count_max(V tasks) {
	//int sum_pop[] = {1,4,6,7};
	int point = tasks[0];

	for (int i = 0; i < tasks.size() ; i++) {

		point = max(sum_till(tasks,i), point);
		point += tasks[i];

		/*
		point = max(sum_pop[i], point);
		point += tasks[i];
		*/
	}
	return point;
}



int main()
{
	int Ctime = 0;
	int Ctime_min = 1000000;
	V tasks;

	tasks.push_back(1);
	tasks.push_back(3);
	tasks.push_back(2);
	tasks.push_back(1);

	for (int i = 0; i < tasks.size(); i++) {
		cout << sum_till(tasks, i) << endl;
	}



	do {
		cout << tasks[0] << " " << tasks[1] << " " << tasks[2] <<" " <<  tasks[3] <<endl;
		Ctime = count_max(tasks);
		cout << Ctime << endl;
		if (Ctime <= Ctime_min) { Ctime_min = Ctime; }
	}
	while (next_permutation(tasks.begin(), tasks.end()));


	cout << Ctime_min << endl;


}

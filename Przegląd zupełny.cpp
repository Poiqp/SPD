#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef std::vector<int> V;


int sum_till(V tasks, int till) {
	int sum = 0;

	for (int i = 0; i <= till; i++) {
		sum += tasks[i];
	}
	return sum;
}

int count_max(V tasks) {
	int sum_pop[] = {1,4,6,10};
	int point = tasks[0];
	V sum_vect;


	for (size_t i = 0; i < tasks.size(); i++) {
		sum_vect.push_back(sum_till(tasks, i));
	}


	for (size_t i = 0; i < tasks.size() ; i++) {
		
		//point = max(sum_till(tasks,i), point);
		//point += tasks[i];
/*	
		point = max(sum_pop[i], point);
		point += tasks[i];
	
		point = max(sum_vect[i], point);
		point += tasks[i];
*/		
		
		if (point < sum_vect[i]) { point = sum_vect[i]; }
		point += tasks[i];


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
	tasks.push_back(4);


	/*
	for (size_t i = 0; i < tasks.size(); i++) {
		cout << sum_till(tasks, i) << "   ";
	}*/
	cout << sum_till(tasks, 0);
	cout << sum_till(tasks, 1);
	cout << sum_till(tasks, 2);
	cout << sum_till(tasks, 3) << endl;


	do {
		cout << tasks[0] << " " << tasks[1] << " " << tasks[2] <<" " << tasks[3] <<endl;
		Ctime = count_max(tasks);
		cout << Ctime << endl;
		if (Ctime <= Ctime_min) { Ctime_min = Ctime; }
	}
	while (next_permutation(tasks.begin(), tasks.end()));


	cout << Ctime_min << endl;


}

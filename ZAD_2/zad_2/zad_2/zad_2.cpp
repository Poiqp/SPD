#include "pch.h"
#include <iostream>
#include "task.h"
using namespace std;


int main()
{	
	int NumOfMachines = 3;
	int NumOfTasks = 4;

	int time = 4;

	vector<task> VectorOfTasks;

	for (int i = 0; i <= NumOfTasks; i++) {
		task tmp(i + 1);

		for (int i2 = 0; i2 <= NumOfMachines; i2++) {
			time++;
			tmp.AddMachine(time);
		}
		
		VectorOfTasks.push_back(tmp);
	}











	return 0;

}

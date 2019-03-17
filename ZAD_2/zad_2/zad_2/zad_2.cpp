#include "pch.h"
#include <iostream>
#include "task.h"
using namespace std;

int LongestTask(vector<task> V, int NumOfTasks, int NumOfMachines) {
	int max_sum = 0;
	int sum = 0;
	int id  = 0;

	for (int i = 0; i <= NumOfTasks; i++) {

		for (int i2 = 0; i2 <= NumOfMachines; i2++) {
			sum += V[i].VectorOfMachines[i2];
		}

		if (sum > max_sum) {
			max_sum = sum;
			id = i;
		}

	}

	//tworzenie tabeli kolejnych id 

	return id;
}


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

	int longest_task = LongestTask(VectorOfTasks, 4, 3);
	cout<< longest_task;




	return 0;

}

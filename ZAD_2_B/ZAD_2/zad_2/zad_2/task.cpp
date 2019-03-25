#include "pch.h"
#include "task.h"
#include <iostream>
#include <vector>
using namespace std;


void task::AddMachine(int num)
{
	VectorOfMachines.push_back(num);
}


int task::CountSum()
{

/*
	int sum = 0;
	for (int i = 0; i < VectorOfMachines.size(); i++) {
		sum += VectorOfMachines[i];
	}
	return sum;
*/
	int sum_of_elems = 0;
	for (auto& n : VectorOfMachines)
		sum_of_elems += n;
	return sum_of_elems;

}

task::task()
{
	id = 0;
}

task::task(int num)
{
	id = num;
}


task::~task()
{
}

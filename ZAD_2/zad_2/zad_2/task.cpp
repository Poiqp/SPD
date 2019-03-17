#include "pch.h"
#include "task.h"
#include <iostream>


void task::AddMachine(int num)
{
	VectorOfMachines.push_back(num);
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

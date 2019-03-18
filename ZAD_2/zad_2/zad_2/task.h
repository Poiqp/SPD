#pragma once
#include <vector>


class task
{
public:
	std::vector<int> VectorOfMachines;
	int id;

	void AddMachine(int num);
	int CountSum();


	task();
	task(int num);
	~task();
};


#pragma once
#include <vector>
#include <atomic>

class task
{
public:
	std::vector<int> VectorOfMachines;
	int id;

	void AddMachine(int num);

	task();
	task(int num);
	~task();
};


#pragma once
class task
{
public:
	int time_1;
	int time_2;
	int id;

	task();
	task(int une, int deux);
	task(int une, int deux, int id);
	~task();
};

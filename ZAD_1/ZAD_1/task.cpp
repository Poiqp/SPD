#include "pch.h"
#include "task.h"


task::task()
{
	id = 0;
	time_1 = 0;
	time_2 = 0;
}

//task::task(z pliku )
//task::task(randomowo)

task::task(int une, int deux, int y ){
	id = y;
	time_1 = une;
	time_2 = deux;

}

task::~task()
{
}

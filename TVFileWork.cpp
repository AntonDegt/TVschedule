#include "TVFileWork.h"


void TVFileWork::WriteToFile(TVschedule schedule, std::string path)
{
	std::ofstream file;
	file.open(path);

	file << schedule;
	
	file.close();
}

TVschedule TVFileWork::ReadFromFile(std::string path)
{
	TVschedule schedule;

	std::ifstream file;
	file.open(path);

	if (file.is_open())
	{
		file >> schedule;

		file.close();
	}

	return schedule;
}

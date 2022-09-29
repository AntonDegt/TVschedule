#pragma once
#include <iostream>
#include <string>
#include <fstream>

#include "TVschedule.h"

namespace TVFileWork
{

	void WriteToFile(TVschedule schedule, std::string path);
	TVschedule ReadFromFile(std::string path);

}
#pragma once
#include <iostream>
#include <string>
#include <fstream>

#include "TVschedule.h"

// Пространство имён
namespace TVFileWork
{
	// Запись в файл
	void WriteToFile(TVschedule schedule, std::string path);
	// Чтение из файла
	TVschedule ReadFromFile(std::string path);

}

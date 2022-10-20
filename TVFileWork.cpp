#include "TVFileWork.h"

// Чтение из файла
void TVFileWork::WriteToFile(TVschedule schedule, std::string path)
{
	std::ofstream file; 
	file.open(path); // Открытие файла
	
	if (file.is_open()) // Проверка файла
	{
		file << schedule; // Запись в файл
	
		file.close(); // Закрытие файла
	}
	else throw "File can't be open.";
}

TVschedule TVFileWork::ReadFromFile(std::string path)
{
	TVschedule schedule;

	std::ifstream file;
	file.open(path); // Открываем файл

	if (file.is_open()) // Проверка файла
	{
		file >> schedule; // Чтение из файла

		file.close(); // Закрытие файла
		
		return schedule;
	}
	else throw "File can't be open.";
}

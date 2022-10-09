#pragma once
#include <iostream>
#include <fstream>

#include "Time.h"

// -------------------- Телепередача --------------------

// Телепередача
class Broadcast
{
private:
	std::string name; // Название
	Time start; // Время начала
	Time lenght; // Длительность
	
	// Доп. текст при выводе программы
	bool textInput;

public:
	// Полный контруктор
	Broadcast(std::string name, Time time, Time lenght, bool textInput);
	Broadcast(std::string name, Time time, Time lenght);
	// Конструктор по умолчанию  - "", 00:00, 01:00
	Broadcast();

	// Чтение телепередачи из консоли
	void Read();

	// Гетеры

	std::string getName();
	Time getStart();
	Time getLenght();
	bool getTextInput();

	// Сетеры

	void setName(std::string name);
	void setStart(Time start);
	void setLenght(Time lenght);
	void setTextInput(bool textInput);

	// Операторы ввода/вывода

	friend std::ostream& operator<< (std::ostream& out, Broadcast& broadcast);
	friend std::ofstream& operator<< (std::ofstream& out, Broadcast& broadcast);
	friend std::ifstream& operator>> (std::ifstream& in, Broadcast& broadcast);
};

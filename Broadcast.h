#pragma once
#include <iostream>
#include <fstream>

#include "Time.h"

// -------------------- ТЕЛЕПЕРЕДАЧА --------------------

// Телепередача
class Broadcast
{
private:
	std::string name;
	Time start;
	Time lenght;

	bool textInput;

public:
	// Конструктор
	Broadcast(std::string name, Time time, Time lenght, bool textInput);
	Broadcast(std::string name, Time time, Time lenght);
	// Пустой конструктор  - "", 00:00
	Broadcast();

	// Чтение из консоли

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

	// Перегрузка операторов

	friend std::ostream& operator<< (std::ostream& out, Broadcast& broadcast);
	friend std::ofstream& operator<< (std::ofstream& out, Broadcast& broadcast);
	friend std::ifstream& operator>> (std::ifstream& in, Broadcast& broadcast);
};

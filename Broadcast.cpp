#include "Broadcast.h"
#include <string>

// -------------------- Телепередача --------------------


// Конструктор
Broadcast::Broadcast(std::string name, Time time, Time end, bool textInput)
	: name{ name }, start{ time }, end{ end }, textInput{ textInput }
{}
Broadcast::Broadcast(std::string name, Time time, Time end)
	: Broadcast(name, time, end, false) // Дилегирование конструктора
{}
// Контруктор по умолчанию  - "", 00:00, 1:00
Broadcast::Broadcast()
	: Broadcast("", Time(0, 0), Time(1, 0))
{}

// Чтение из консоли
void Broadcast::Read()
{
	if (textInput) std::cout << "Name: ";
	std::cin.get();
	std::getline(std::cin, this->name);
	if (textInput) std::cout << "StartTime(HH MM): ";
	std::cin >> this->start;
	if (textInput) std::cout << "EndTime(HH MM): ";
	std::cin >> this->end;
}


// Гетеры

std::string Broadcast::getName()
{
	return name;
}
Time Broadcast::getStart()
{
	return start;
}
Time Broadcast::getEnd()
{
	return end;
}
bool Broadcast::getTextInput()
{
	return textInput;
}

// Сетеры

void Broadcast::setName(std::string name)
{
	this->name = name;
}
void Broadcast::setStart(Time start)
{
	this->start = start;
}
void Broadcast::setEnd(Time end)
{
	this->end = end;
}
void Broadcast::setTextInput(bool textInput)
{
	this->textInput = textInput;
}

// Операторы ввода/вывода

// Оператор вывода в консоль
std::ostream& operator<< (std::ostream& out, Broadcast& broadcast)
{
	out << broadcast.start << " -> " << broadcast.end << " - " << broadcast.name;
	return out;
}
// Оператор вывода в файл
std::ofstream& operator<< (std::ofstream& out, Broadcast& broadcast)
{
	out << broadcast.name << std::endl;
	out << broadcast.start << " ";
	out << broadcast.end;
	return out;
}
// Оператор ввода в файл
std::ifstream& operator>> (std::ifstream& in, Broadcast& broadcast)
{
	in.get();
	std::getline(in, broadcast.name);
	in >> broadcast.start;
	in >> broadcast.end;
	return in;
}

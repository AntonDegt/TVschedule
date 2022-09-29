#include "Broadcast.h"
#include <string>

// -------------------- ÒÅËÅÏÅÐÅÄÀ×À --------------------


// Êîíñòðóêòîð
Broadcast::Broadcast(std::string name, Time time, Time lenght, bool textInput)
	: name{ name }, start{ time }, lenght{ lenght }, textInput{ textInput }
{}
Broadcast::Broadcast(std::string name, Time time, Time lenght)
	: Broadcast(name, time, lenght, false)
{}
// Ïóñòîé êîíñòðóêòîð  - "", 00:00, 1:00
Broadcast::Broadcast()
	: Broadcast("", Time(0, 0), Time(1, 0))
{}

// ×òåíèå èç êîíñîëè

void Broadcast::Read()
{
	if (textInput) std::cout << "Name: ";
	std::cin.get();
	std::getline(std::cin, this->name);
	if (textInput) std::cout << "StartTime(HH MM): ";
	std::cin >> this->start;
	if (textInput) std::cout << "LenghtTime(HH MM): ";
	std::cin >> this->lenght;
}


// Ãåòåðû

std::string Broadcast::getName()
{
	return name;
}
Time Broadcast::getStart()
{
	return start;
}
Time Broadcast::getLenght()
{
	return lenght;
}
bool Broadcast::getTextInput()
{
	return textInput;
}

// Ñåòåðû

void Broadcast::setName(std::string name)
{
	this->name = name;
}
void Broadcast::setStart(Time start)
{
	this->start = start;
}
void Broadcast::setLenght(Time lenght)
{
	this->lenght = lenght;
}
void Broadcast::setTextInput(bool textInput)
{
	this->textInput = textInput;
}

// Ïåðåãðóçêà îïåðàòîðîâ

std::ostream& operator<< (std::ostream& out, Broadcast& broadcast)
{
	out << broadcast.start << " -> " << broadcast.start + broadcast.lenght << " - " << broadcast.name;
	return out;
}
std::ofstream& operator<< (std::ofstream& out, Broadcast& broadcast)
{
	out << broadcast.name << std::endl;
	out << broadcast.start << " ";
	out << broadcast.lenght;
	return out;
}
std::ifstream& operator>> (std::ifstream& in, Broadcast& broadcast)
{
	in.get();
	std::getline(in, broadcast.name);
	in >> broadcast.start;
	in >> broadcast.lenght;
	return in;
}

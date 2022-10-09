#include "Date.h"

// -------------------- Дата --------------------


// Проверка корректности даты
void Date::ErrorCheck()
{
	if (month <= 0 || month > 12)
		throw "Month out of range."; // Исключение - Месяц вне деапазона
	if (day > 0)
		if (month == 2) // проверка Февраля
		{
			if (year % 4 == 0)
			{
				if (day <= 29) 
					return;
			}
			else if (day < 29) 
				return;
		}
		else if (month % 2 == 0)
		{
			if (day <= 31) 
				return;
		}
		else if (day < 31) 
			return;

	throw "Day out of range.";
}

// Конструктор
Date::Date(int day, int month, int year)
	: day{ day }, month{ month }, year{ year }
{}
// Конструктор по умолчанию - 01.01.2000
Date::Date()
	: Date(01, 01, 2000)
{}

// Гетер

int Date::getDay()
{
	return day;
}
int Date::getMonth()
{
	return month;
}
int Date::getYear()
{
	return year;
}

// Сетер

void Date::setDay(int day)
{
	this->day = day;
	ErrorCheck();
}
void Date::setMonth(int month)
{
	this->month = month;
	ErrorCheck();
}
void Date::setYear(int year)
{
	this->year = year;
	ErrorCheck();
}

// Оператор ввода/вывода

// Оператор вывода в консоль
std::ostream& operator<< (std::ostream& out, Date& date)
{
	out << date.day << "/" << date.month << "/" << date.year;
	return out;
}
// Оператор ввода из консоли
std::istream& operator>> (std::istream& in, Date& date)
{
	in >> date.day;
	in >> date.month;
	in >> date.year;
	return in;
}
// Опертор вывода в файл
std::ofstream& operator<< (std::ofstream& out, Date& date)
{
	out << date.day << " " << date.month << " " << date.year;
	return out;
}
// Оператор ввода в файл
std::ifstream& operator>> (std::ifstream& in, Date& date)
{
	in >> date.day >> date.month >> date.year;
	return in;
}

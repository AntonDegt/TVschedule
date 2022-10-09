#pragma once
#include <iostream>
#include <fstream>

// -------------------- Дата --------------------

// Дата - День Месяц Год
class Date
{
private:
	int year;
	int month;
	int day;

	// Проверка Даты на корректность (иначе Исключение)
	void ErrorCheck();
public:
	// Конструктор
	Date(int day, int month, int year);
	// Конструктор по умолчанию - 01.01.2000
	Date();


	// Гетеры

	int getDay();
	int getMonth();
	int getYear();

	// Сетеры

	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);

	// Операторы

	friend std::ostream& operator<< (std::ostream& out, Date& date);
	friend std::istream& operator>> (std::istream& in, Date& date);
	friend std::ofstream& operator<< (std::ofstream& out, Date& date);
	friend std::ifstream& operator>> (std::ifstream& in, Date& date);
};

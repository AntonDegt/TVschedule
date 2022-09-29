#pragma once
#include <iostream>
#include <fstream>

// -------------------- ДАТА --------------------

// Дата - день месяц год
class Date
{
private:
	int year;
	int month;
	int day;

	// Проверка на коректность даты (либо вызов ошибки)
	void ErrorCheck();
public:
	// Конструктор
	Date(int day, int month, int year);
	// Пустой конструктор - 01.01.2000
	Date();


	// Гетеры

	int getDay();
	int getMonth();
	int getYear();

	// Сетеры

	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);

	// Перегрузка операторов

	friend std::ostream& operator<< (std::ostream& out, Date& date);
	friend std::istream& operator>> (std::istream& in, Date& date);
	friend std::ofstream& operator<< (std::ofstream& out, Date& date);
	friend std::ifstream& operator>> (std::ifstream& in, Date& date);
};
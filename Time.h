#pragma once
#include <iostream>
#include <fstream>

// -------------------- Время -------------------

// Время
class Time
{
private:
	int hour;
	int minute;

	// Проверка времени на корректность (иначе вызывает ошибку)
	void ErrorCheck();
public:
	// Конструктор
	Time(int hour, int minute);
	// Конструктор по умолчанию - 00:00
	Time();

	// Гетеры

	int getHour();
	int getMinute();

	// Сетеры

	void setHour(int hour);
	void setMinute(int minute);

	// Перегрузка операторов ввода/вывода

	friend std::ostream& operator<< (std::ostream& out, Time time);
	friend std::istream& operator>> (std::istream& in, Time& time);
	friend std::ofstream& operator<< (std::ofstream& out, Time time);
	friend std::ifstream& operator>> (std::ifstream& in, Time& time);

	// перегрузка бинарных операторов

	bool operator< (Time sec);
	bool operator> (Time sec);

	friend Time operator+ (Time one, Time two);
};

#include "Time.h"

// -------------------- Время -------------------


// Проверка времени на корректность
void Time::ErrorCheck()
{
	if (hour < 0 || hour >= 24)
		throw "Hour out of range."; // Исключение если количество Часов не корректно
	if (minute < 0 || minute >= 60)
		throw "Minute out of range."; // Исключение если количество Минут не корректно
}

// Конструктор
Time::Time(int hour, int minute)
	: hour{ hour }, minute{ minute }
{
	ErrorCheck();
}
// Конструктор по умолчанию - 00:00
Time::Time()
	: Time(0, 0) // Делегирование конструкторов
{}

// Гетеры

int Time::getHour()
{
	return hour;
}
int Time::getMinute()
{
	return minute;
}

// Сетеры

void Time::setHour(int hour)
{
	this->hour = hour;
	ErrorCheck();
}
void Time::setMinute(int minute)
{
	this->minute = minute;
	ErrorCheck();
}

// Перегрузка операторов ввода/вывода

// Вывод в консоль
std::ostream& operator<< (std::ostream& out, Time time) 
{
	out << time.hour << ":";
	if (time.minute < 10) out << "0";
	out << time.minute;
	return out;
}
// Ввод из консоли
std::istream& operator>> (std::istream& in, Time& time) 
{
	in >> time.hour;
	in >> time.minute;
	time.ErrorCheck();
	return in;
}
// Вывод в файл
std::ofstream& operator<< (std::ofstream& out, Time time)
{
	out << time.hour << " " << time.minute;
	return out;
}
// Ввод из файла
std::ifstream& operator>> (std::ifstream& in, Time& time)
{
	in >> time.hour;
	in >> time.minute;
	return in;
}

// Оператор сравнения
bool Time::operator< (Time sec)
{
	if (this->hour < sec.hour)
		return true;
	else if (this->hour == sec.hour)
		if (this->minute < sec.minute)
			return true;
	return false;
}
// Оператор сравнения
bool Time::operator> (Time sec)
{
	if (this->hour > sec.hour)
		return true;
	else if (this->hour == sec.hour)
		if (this->minute > sec.minute)
			return true;
	return false;
}

// Оператор сложения
Time operator+(Time one, Time two)
{
	Time t;

	t.minute = one.minute + two.minute;
	t.hour = one.hour + two.hour;
	t.hour += t.minute / 60;
	t.minute = t.minute % 60;
	t.hour = t.hour % 24;

	return t;
}

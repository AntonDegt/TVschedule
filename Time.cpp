#include "Time.h"

// -------------------- ВРЕМЯ -------------------


// Проверка на коректность времени (иначе вызов ошибки)
void Time::ErrorCheck()
{
	if (hour < 0 || hour >= 24)
		throw "Hour out of range.";
	if (minute < 0 || minute >= 60)
		throw "Minute out of range.";
}

// Конструктор
Time::Time(int hour, int minute)
	: hour{ hour }, minute{ minute }
{
	ErrorCheck();
}
// Пустой конструктор - 00:00
Time::Time()
	: Time(0, 0)
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

// Перегрузка операторов

std::ostream& operator<< (std::ostream& out, Time time)
{
	out << time.hour << ":" << time.minute;
	return out;
}
std::istream& operator>> (std::istream& in, Time& time)
{
	in >> time.hour;
	in >> time.minute;
	time.ErrorCheck();
	return in;
}
std::ofstream& operator<< (std::ofstream& out, Time time)
{
	out << time.hour << " " << time.minute;
	return out;
}
std::ifstream& operator>> (std::ifstream& in, Time& time)
{
	in >> time.hour;
	in >> time.minute;
	return in;
}

bool Time::operator< (Time sec)
{
	if (this->hour < sec.hour)
		return true;
	else if (this->hour == sec.hour)
		if (this->minute < sec.minute)
			return true;
	return false;
}
bool Time::operator> (Time sec)
{
	if (this->hour > sec.hour)
		return true;
	else if (this->hour == sec.hour)
		if (this->minute > sec.minute)
			return true;
	return false;
}


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

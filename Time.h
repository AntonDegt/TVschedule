#pragma once
#include <iostream>
#include <fstream>

// -------------------- ����� -------------------

// ����� - ���� : ������
class Time
{
private:
	int hour;
	int minute;

	// �������� �� ����������� ������� (����� ����� ������)
	void ErrorCheck();
public:
	// �����������
	Time(int hour, int minute);
	// ������ ����������� - 00:00
	Time();

	// ������

	int getHour();
	int getMinute();

	// ������

	void setHour(int hour);
	void setMinute(int minute);

	// ���������� ����������

	friend std::ostream& operator<< (std::ostream& out, Time time);
	friend std::istream& operator>> (std::istream& in, Time& time);
	friend std::ofstream& operator<< (std::ofstream& out, Time time);
	friend std::ifstream& operator>> (std::ifstream& in, Time& time);

	bool operator< (Time sec);
	bool operator> (Time sec);

	friend Time operator+ (Time one, Time two);
};
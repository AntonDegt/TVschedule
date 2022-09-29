#pragma once
#include <iostream>
#include <fstream>

// -------------------- ���� --------------------

// ���� - ���� ����� ���
class Date
{
private:
	int year;
	int month;
	int day;

	// �������� �� ����������� ���� (���� ����� ������)
	void ErrorCheck();
public:
	// �����������
	Date(int day, int month, int year);
	// ������ ����������� - 01.01.2000
	Date();


	// ������

	int getDay();
	int getMonth();
	int getYear();

	// ������

	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);

	// ���������� ����������

	friend std::ostream& operator<< (std::ostream& out, Date& date);
	friend std::istream& operator>> (std::istream& in, Date& date);
	friend std::ofstream& operator<< (std::ofstream& out, Date& date);
	friend std::ifstream& operator>> (std::ifstream& in, Date& date);
};
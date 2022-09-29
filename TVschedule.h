#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>

#include "Broadcast.h"
#include "Date.h"
#include "Time.h"


// -------------------- ���������� ����������� --------------------

// ���������� ����������� �� ����
class TVschedule
{
private:
	Date date;
	Broadcast* schedule;
	int size;

public:
	TVschedule(Date date);
	TVschedule();
	TVschedule(const TVschedule& copy);
	~TVschedule(void);

	// ������ � list

	// ������� � ������ �� �������
	void addBroadcast(Broadcast broadcast);
	void deleteBroadcast(int index);
	Broadcast getBroadcast(int index);


	// ������

	Date getDate();
	int getSize();

	// ������

	void setDate(Date date); 
	
	// ���������� ����������

	friend std::ostream& operator<< (std::ostream& out, TVschedule& schedule);
	friend std::ofstream& operator<< (std::ofstream& out, TVschedule& schedule);
	friend std::ifstream& operator>> (std::ifstream& in, TVschedule& schedule);
	TVschedule& operator= (TVschedule copy);
};

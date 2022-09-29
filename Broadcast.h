#pragma once
#include <iostream>
#include <fstream>

#include "Time.h"

// -------------------- ������������ --------------------

// ������������
class Broadcast
{
private:
	std::string name;
	Time start;
	Time lenght;

	bool textInput;

public:
	// �����������
	Broadcast(std::string name, Time time, Time lenght, bool textInput);
	Broadcast(std::string name, Time time, Time lenght);
	// ������ �����������  - "", 00:00
	Broadcast();

	// ������ �� �������

	void Read();

	// ������

	std::string getName();
	Time getStart();
	Time getLenght();
	bool getTextInput();

	// ������

	void setName(std::string name);
	void setStart(Time start);
	void setLenght(Time lenght);
	void setTextInput(bool textInput);

	// ���������� ����������

	friend std::ostream& operator<< (std::ostream& out, Broadcast& broadcast);
	friend std::ofstream& operator<< (std::ofstream& out, Broadcast& broadcast);
	friend std::ifstream& operator>> (std::ifstream& in, Broadcast& broadcast);
};

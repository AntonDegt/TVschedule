#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>

#include "Broadcast.h"
#include "Date.h"
#include "Time.h"


// -------------------- Программа телепередач --------------------

// Программа телепередач
class TVschedule
{
private:
	Date date; // Дата программы
	Broadcast* schedule; // Ссылойчный тип данных для дин. массива
	int size; // Количество элементов в массиве

public:
	TVschedule(Date date);
	TVschedule();
	
	// Конструктор копирования, деструктор и оператор присваивания поскольку в классе есть ссылчный тип данных
	
	TVschedule(const TVschedule& copy);
	// Деструктор
	~TVschedule(void);

	// Работа с дин. массивом
	
	void addBroadcast(Broadcast broadcast);
	void deleteBroadcast(int index);
	Broadcast getBroadcast(int index);


	// Гетеры

	Date getDate();
	int getSize();

	// Сетеры

	void setDate(Date date); 
	
	// Операторы ввода/вывода

	friend std::ostream& operator<< (std::ostream& out, TVschedule& schedule);
	friend std::ofstream& operator<< (std::ofstream& out, TVschedule& schedule);
	friend std::ifstream& operator>> (std::ifstream& in, TVschedule& schedule);
	
	// Оператор присваивания
	
	TVschedule& operator= (TVschedule copy);
};

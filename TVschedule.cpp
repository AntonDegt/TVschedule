#include "TVschedule.h"



// -------------------- Программа телепередач --------------------

// Конструкторы

TVschedule::TVschedule(Date date)
	: date{ date }, size{ 0 }, schedule{ nullptr }
{}
TVschedule::TVschedule()
	: TVschedule(Date()) // Делигирование конструктора
{}
TVschedule::TVschedule(const TVschedule& copy)
{
	this->date = copy.date;
	this->size = copy.size;
	schedule = new Broadcast[this->size];
	for (int i = 0; i < this->size; i++)
		this->schedule[i] = copy.schedule[i];
}
// Деструктор
TVschedule::~TVschedule(void)
{
	delete[] schedule;
}

// Управление дин. массиваом

// Добавить элемент
void TVschedule::addBroadcast(Broadcast broadcast)
{
	// Находим место для нового элемента учитывая время начала телепередачи
	int index = size;
	for (index; index > size; index++)
		if (index < size)
		{
			if (broadcast.getStart() > schedule[index].getStart())
				break;
		}
		else break;
	
	// Добавление элемента в массив
	size++;

	Broadcast* t = schedule; // Временная переменная
	schedule = new Broadcast[size]; // Новый массив
	
	// Копировние старого массива в новый
	int d = 0;
	for (int i = 0; i < size; i++)
	{
		if (i == index)
		{
			schedule[i] = broadcast;
			d++;
		}
		else schedule[i] = t[i - d];
	}

	// Очистка памяти от старого массива
	delete[] t;
}
// Удаление телепередачи по индексу
void TVschedule::deleteBroadcast(int index)
{
	Broadcast* t = schedule; // Временная переменная
	size--;
	schedule = new Broadcast[size]; // Новый массив размером на 1 меньше
	
	// Копирование данных в новый массив
	int d = 0;
	for (int i = 0; i < size; i++)
	{
		if (i == index)
			d++;
		schedule[i] = t[i+d];
	}

	// Очистка памяти от старого массива
	delete[] t;
}
// Получение телепередачи по массиву
Broadcast TVschedule::getBroadcast(int index)
{
	return schedule[index];
}



// Гетеры

Date TVschedule::getDate()
{ return date; }
int  TVschedule::getSize()
{
	return size;
}

// Сетеры

void TVschedule::setDate(Date date)
{
	this->date = date;
}

// Операторы ввода/вывода

// Оператор вывода в консоль
std::ostream& operator<< (std::ostream& out, TVschedule& schedule)
{
	out << schedule.date << std::endl;
	for (int i = 0; i < schedule.size; i++)
		out << schedule.schedule[i] << std::endl;
	return out;
}
// Оператор вывода в файл
std::ofstream& operator<< (std::ofstream& out, TVschedule& schedule)
{
	out << schedule.date << std::endl;
	out << schedule.size << std::endl;
	for (int i = 0; i < schedule.size; i++)
		out << schedule.schedule[i] << std::endl;
	return out;
}
// Оператор ввода из файла
std::ifstream& operator>> (std::ifstream& in, TVschedule& schedule)
{
	in >> schedule.date;
	in >> schedule.size;
	schedule.schedule = new Broadcast[schedule.size];
	for (int i = 0; i < schedule.size; i++)
		in >> schedule.schedule[i];
	return in;
}
// Оператор присваивания
TVschedule& TVschedule::operator= (TVschedule copy)
{
	this->date = copy.date;
	this->size = copy.size;
	schedule = new Broadcast[this->size];
	for (int i = 0; i < this->size; i++)
		this->schedule[i] = copy.schedule[i];

	return *this;
}

// Оператор индексации
Broadcast& TVschedule::operator[](const int index)
{
	return schedule[index];
}

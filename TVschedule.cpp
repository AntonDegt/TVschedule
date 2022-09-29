#include "TVschedule.h"



// -------------------- РАСПИСАНИЕ ТЕЛЕПЕРЕДАЧ --------------------

TVschedule::TVschedule(Date date)
	: date{ date }, size{ 0 }, schedule{ nullptr }
{}
TVschedule::TVschedule()
	: TVschedule(Date())
{}
TVschedule::TVschedule(const TVschedule& copy)
{
	this->date = copy.date;
	this->size = copy.size;
	schedule = new Broadcast[this->size];
	for (int i = 0; i < this->size; i++)
		this->schedule[i] = copy.schedule[i];
}
TVschedule::~TVschedule(void)
{
	delete[] schedule;
}

// Работа с list

void TVschedule::addBroadcast(Broadcast broadcast)
{
	// Поиск места для нового элемента
	int index = size;
	for (index; index > size; index++)
		if (index < size)
		{
			if (broadcast.getStart() > schedule[index].getStart())
				break;
		}
		else break;

	// Вставка нового элемента
	size++;

	Broadcast* t = schedule;
	schedule = new Broadcast[size];

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

	// Удаление прошлого массива
	delete[] t;
}
void TVschedule::deleteBroadcast(int index)
{
	// Копирования массиве с учётом удалёния элемента
	Broadcast* t = schedule;
	size--;
	schedule = new Broadcast[size];
	int d = 0;
	for (int i = 0; i < size; i++)
	{
		if (i == index)
			d++;
		schedule[i] = t[i+d];
	}

	// Удаление прошлого массива
	delete[] t;
}
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

// Перегрузка операторов

std::ostream& operator<< (std::ostream& out, TVschedule& schedule)
{
	out << schedule.date << std::endl;
	for (int i = 0; i < schedule.size; i++)
		out << schedule.schedule[i] << std::endl;
	return out;
}
std::ofstream& operator<< (std::ofstream& out, TVschedule& schedule)
{
	out << schedule.date << std::endl;
	out << schedule.size << std::endl;
	for (int i = 0; i < schedule.size; i++)
		out << schedule.schedule[i] << std::endl;
	return out;
}
std::ifstream& operator>> (std::ifstream& in, TVschedule& schedule)
{
	in >> schedule.date;
	in >> schedule.size;
	schedule.schedule = new Broadcast[schedule.size];
	for (int i = 0; i < schedule.size; i++)
		in >> schedule.schedule[i];
	return in;
}
TVschedule& TVschedule::operator= (TVschedule copy)
{
	this->date = copy.date;
	this->size = copy.size;
	schedule = new Broadcast[this->size];
	for (int i = 0; i < this->size; i++)
		this->schedule[i] = copy.schedule[i];

	return *this;
}
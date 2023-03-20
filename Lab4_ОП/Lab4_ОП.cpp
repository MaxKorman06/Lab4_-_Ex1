#include <iostream>
#include <Windows.h>

using namespace std;

struct TIMETABLE
{
	char NAZV[100];
	int NUMR;
	long double sort_h;
	struct 
	{
		int year, mon, day;
	}DATE;
	struct 
	{
		int hour, min;
	}TIME;
};

void str_cout(TIMETABLE TRAIN[100], int i)
{
	cout << "Назву пункту призначення: " << TRAIN[i].NAZV << '\n';
	cout << "Номер поїзда: " << TRAIN[i].NUMR << '\n';
	cout << "Дата відправлення\n" << "День: " << TRAIN[i].DATE.day << '\n' << "Місяць: " << TRAIN[i].DATE.mon << '\n' << "Рік: " << TRAIN[i].DATE.year << '\n';
	cout << "Час відправлення:\n" << "Година: " << TRAIN[i].TIME.hour << '\n' << "Хвилина: " << TRAIN[i].TIME.min << "\n\n";
}

int main() 
{
	SetConsoleOutputCP(1251);
	TIMETABLE TRAIN[100];
	int num_tra = 0;
	cout << "Ви ввійшли в програму розкладу поїздів\nВведіть інформацію про них:\n\n";
	for (size_t i = 0; i < 100; i++)
	{
		int num_h;
		num_tra++;
		cout << "Введіть назву пункту призначення\nНаприклад: Тернопіль\n";
		cin >> TRAIN[i].NAZV;
		cout << "\nВведіть номер поїзда\nНаприклад: 12355\n";
		cin >> TRAIN[i].NUMR;
		cout << "Увага слід вводити дату і час саме так як показано в прикладі інакше можливі збої в роботі програми\nВведіть дату відправленя\nДень місяць рік\nНаприклад: 26 09 2021\n";
		cin >> TRAIN[i].DATE.day >> TRAIN[i].DATE.mon >> TRAIN[i].DATE.year;
		cout << "\nВведіть час відправлення\nГодина хвилина\nНаприклад: 12 35\n";
		cin >> TRAIN[i].TIME.hour >> TRAIN[i].TIME.min;
		cout << "\nПродовжити ввід данних?\nТак = нажміть 1\tНі = інше число\n";
		cin >> num_h;
			if (num_h != 1)
			{
				break;
			}
	}
	for (size_t i = 0; i < num_tra; i++)
	{
		str_cout(TRAIN, i);
	}
	for (size_t i = 0; i < num_tra; i++)
	{
		TRAIN[i].sort_h = (1000000. * TRAIN[i].DATE.year) + (10000. * TRAIN[i].DATE.mon) + (100. * TRAIN[i].DATE.day) + TRAIN[i].TIME.hour + (0.01 * TRAIN[i].TIME.min);
	}
		
	TIMETABLE TRAIN_h;
	for (int i = 0; i < (num_tra + 3); i++) {
		for (int j = (num_tra - 1); j >= (i + 1); j--) {
			if (TRAIN[j].sort_h < TRAIN[j - 1].sort_h) {
				TRAIN_h = TRAIN[j];
				TRAIN[j] = TRAIN[j - 1];
				TRAIN[j - 1] = TRAIN_h;
			}
		}
	}

	cout << "Графік руху поїздів відсортований в порядку зростання\n";
	for (size_t i = 0; i < num_tra; i++)
	{
		str_cout(TRAIN, i);
	}
	cout << "Введіть назву населеного пункту щов вивести відповідний маршрут\n";
	for (size_t i = 0; i < 100; i++)
	{
		int num_serch = 0;
		string name;
		int num_h;
		cin >> name;
		for (size_t i = 0; i < 100; i++)
		{
			if (TRAIN[i].NAZV == name)
			{
				str_cout(TRAIN, i);
				num_serch++;
			}
		}
		if (num_serch == 0)
		{
			cout << "Таких маршрутів немає\n";
		}
		cout << "\nПродовжити пошук маршрутів за назвою населеного пункту?\nТак = нажміть 1\tНі = інше число\n";
		cin >> num_h;
		if (num_h != 1)
		{
			break;
		}
		num_serch = 0;
	}
}


#include <iostream>
#include <math.h>
#include <fstream>
#include <sstream>
using namespace std;

struct Datetime
{
	int second;
	int minute;
	int hour;
	int day;
	int month;
	int year;
	void Show();
	void Get_next_date();
	void Get_prev_date();
};

int main()
{
	setlocale(LC_ALL, "Russian");
	int n = 0;
	ifstream file("C:\\Users\\79236\\Desktop\\Универ\\Языки программирования\\Ivanov_204_semestr2_lab6\\Ivanov_204_semestr2_lab6\\laptop.txt");
	string line;

	while (getline(file, line))
	{
		n++;
	}
	Datetime* data = new Datetime[n];
	Datetime* data_next = new Datetime[n];
	int i = 0;
	int k = 0;
	file.clear();
	file.seekg(0, ios::beg);

	while (getline(file, line))
	{
		istringstream line_F(line);
		line_F >> data[i].second >> data[i].minute >> data[i].hour >> data[i].day >> data[i].month >> data[i].year;
		i++;
	}
	file.clear();
	file.seekg(0, ios::beg);

	string line_1;
	while (getline(file, line_1))
	{
		istringstream line_F(line_1);
		line_F >> data_next[k].second >> data_next[k].minute >> data_next[k].hour >> data_next[k].day >> data_next[k].month >> data_next[k].year;
		k++;
	}
	file.close();

	for (int L = 0; L < k - 1; L++)
	{
		if (((data_next[L].second < 1) || (data_next[L].second > 59)) || ((data_next[L].minute < 1) || (data_next[L].minute > 59)) || ((data_next[L].hour < 1) || (data_next[L].hour > 23)) || ((data_next[L].month < 1) || (data_next[L].month > 12)) || (data_next[L].year < 1) || (((data_next[L].month == 1) || (data_next[L].month == 3) || (data_next[L].month == 5) || (data_next[L].month == 7) || (data_next[L].month == 8) || (data_next[L].month == 10) || (data_next[L].month == 12)) && ((data_next[L].day > 31) || (data_next[L].day < 1))) || (((data_next[L].month == 4) || (data_next[L].month == 6) || (data_next[L].month == 9) || (data_next[L].month == 11)) && ((data_next[L].day > 30) || (data_next[L].day < 1))) || ((data_next[L].month == 2) && (data_next[L].year % 4 == 0) && ((data_next[L].day < 1) || (data_next[L].day > 29))) || ((data_next[L].month == 2) && (data_next[L].year % 4 != 0) && ((data_next[L].day < 1) || (data_next[L].day > 28))))
		{
			cout << "Неверно введены данные" << endl;
			return 0;
		}
	}

	cout << "Общие задания" << endl;
	cout << endl;
	for (int j = 0; j < i - 1; j++)
	{
		cout << "№" << j + 1 << "  " << "Текущие время и дата" << " ";
		data[j].Show();
		cout << "  " << "Следующая дата" << " ";
		data[j].Get_next_date();
		cout << data[j].day << "/" << data[j].month << "/" << data[j].year << "  " << "Предыдущая дата" << " ";
		data[j].Get_prev_date();
		cout << data[j].day << "/" << data[j].month << "/" << data[j].year << endl;
	}
	cout << endl;
	cout << "Вариант 2" << endl;
	cout << endl;
	for (int j = 0; j < i - 1; j++)
	{
		if ((data_next[j].month == 12))
		{
			if (data_next[j].day == 31)
			{
				cout << "№" << j + 1 << "  " << "Текущие время и дата" << " ";
				data_next[j].Show();
				cout << "  " << "Следующая дата" << " ";
				data_next[j].day = 1;
				data_next[j].month = 1;
				data_next[j].year += 1;
				cout << data_next[j].day << "/" << data_next[j].month << "/" << data_next[j].year << endl;
			}
		}
	}
	delete[] data_next;
	delete[] data;
	return 0;
}

void Datetime::Show()
{
	cout << hour << ":" << minute << ":" << second << " " << day << "/" << month << "/" << year;
}

void Datetime::Get_next_date()
{
	if (year % 4 == 0)
	{
		if (month == 2)
		{
			if (day == 29)
			{
				day = 1;
				month = 3;
			}
			else
			{
				day += 1;
			}
		}
		if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10))
		{
			if (day == 31)
			{
				day = 1;
				month += 1;
			}
			else
			{
				day += 1;
			}
		}
		if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
		{
			if (day == 30)
			{
				day = 1;
				month += 1;
			}
			else
			{
				day += 1;
			}
		}
		if ((month == 12))
		{
			if (day == 31)
			{
				day = 1;
				month = 1;
				year += 1;
			}
			else
			{
				day += 1;
			}
		}
	}
	else
	{
		if (month == 2)
		{
			if (day == 28)
			{
				day = 1;
				month = 3;
			}
			else
			{
				day += 1;
			}
		}
		if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10))
		{
			if (day == 31)
			{
				day = 1;
				month += 1;
			}
			else
			{
				day += 1;
			}
		}
		if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
		{
			if (day == 30)
			{
				day = 1;
				month += 1;
			}
			else
			{
				day += 1;
			}
		}
		if ((month == 12))
		{
			if (day == 31)
			{
				day = 1;
				month = 1;
				year += 1;
			}
			else
			{
				day += 1;
			}
		}
	}
}

void Datetime::Get_prev_date()
{
	if (year % 4 == 0)
	{
		if (month == 3)
		{
			if (day == 2)
			{
				day = 29;
				month = 2;
			}
			else
			{
				if (day == 1)
				{
					day = 28;
					month -= 1;
				}
				else
				{
					day -= 2;
				}
			}
		}
		else
		{
			if ((month == 2) || (month == 4) || (month == 6) || (month == 8) || (month == 9) || (month == 11))
			{
				if (day == 2)
				{
					day = 31;
					month -= 1;
				}
				else
				{
					if (day == 1)
					{
						day = 30;
						month -= 1;
					}
					else
					{
						day -= 2;
					}
				}
			}
			else
			{
				if ((month == 5) || (month == 7) || (month == 10) || (month == 12))
				{
					if (day == 2)
					{
						day = 30;
						month -= 1;
					}
					else
					{
						if (day == 1)
						{
							day = 29;
							month -= 1;
						}
						else
						{
							day -= 2;
						}
					}
				}
				else
				{
					if ((month == 1))
					{
						if (day == 2)
						{
							day = 31;
							month = 12;
							year -= 1;
						}
						else
						{
							if (day == 1)
							{
								day = 30;
								month = 12;
								year -= 1;
							}
							else
							{
								day -= 2;
							}
						}
					}
				}
			}
		}
	}
	else
	{
		if (month == 3)
		{
			if (day == 2)
			{
				day = 29;
				month = 2;
			}
			else
			{
				if (day == 1)
				{
					day = 28;
					month -= 1;
				}
				else
				{
					day -= 2;
				}
			}
		}
		else
		{
			if ((month == 2) || (month == 4) || (month == 6) || (month == 8) || (month == 9) || (month == 11))
			{
				if (day == 2)
				{
					day = 31;
					month -= 1;
				}
				else
				{
					if (day == 1)
					{
						day = 30;
						month -= 1;
					}
					else
					{
						day -= 2;
					}
				}
			}
			else
			{
				if ((month == 5) || (month == 7) || (month == 10) || (month == 12))
				{
					if (day == 2)
					{
						day = 30;
						month -= 1;
					}
					else
					{
						if (day == 1)
						{
							day = 29;
							month -= 1;
						}
						else
						{
							day -= 2;
						}
					}
				}
				else
				{
					if ((month == 1))
					{
						if (day == 2)
						{
							day = 31;
							month = 12;
							year -= 1;
						}
						else
						{
							if (day == 1)
							{
								day = 30;
								month = 12;
								year -= 1;
							}
							else
							{
								day -= 2;
							}
						}
					}
				}
			}
		}
	}
}


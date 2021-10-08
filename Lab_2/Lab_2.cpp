#include <iostream>
#include <math.h>
#include <fstream>
#include <sstream>
using namespace std;

class Datetime
{
public:
	int second;
	int minute;
	int hour;
	int day;
	int month;
	int year;

	Datetime()
	{
		second = NULL;
		minute = NULL;
		hour = NULL;
		day = NULL;
		month = NULL;
		year = NULL;
	}

	Datetime(int secondK, int minuteK, int hourK, int dayK, int monthK, int yearK)
	{
		second = secondK;
		minute = minuteK;
		hour = hourK;
		day = dayK;
		month = monthK;
		year = yearK;
	}

	~Datetime()
	{

	}

	void Get_next_date();
	void Get_prev_date();
};

class Application
{
public:
	void Run(string fileName);
	void Show(Datetime);

private:
	Datetime* ReadFileDate(string fileName);
	int ReadFileDate_n(string fileName);
};


int main()
{
	setlocale(LC_ALL, "Russian");

	Application main;
	main.Run("C:\\Users\\79236\\Desktop\\Универ\\Языки программирования\\Ivanov_204_semestr2_lab6\\Ivanov_204_semestr2_lab6\\laptop.txt");
	return 0;
}

void Application::Run(string fileName)
{

	int n;
	Datetime* prev = ReadFileDate(fileName);
	Datetime* next = ReadFileDate(fileName);
	n = ReadFileDate_n(fileName);


	cout << "Общие задания" << endl;
	cout << endl;
	for (int j = 0; j < n - 1; j++)
	{
		cout << "№" << j + 1 << "  " << "Текущие время и дата" << " ";
		Application::Show(prev[j]);
		cout << "  " << "Следующая дата" << " ";
		prev[j].Get_next_date();
		cout << prev[j].day << "/" << prev[j].month << "/" << prev[j].year << "  " << "Предыдущая дата" << " ";
		prev[j].Get_prev_date();
		cout << prev[j].day << "/" << prev[j].month << "/" << prev[j].year << endl;
	}
	cout << endl;
	cout << "Вариант 2" << endl;
	cout << endl;
	for (int j = 0; j < n - 1; j++)
	{
		if ((next[j].month == 12))
		{
			if (next[j].day == 31)
			{
				cout << "№" << j + 1 << "  " << "Текущие время и дата" << " ";
				Application::Show(next[j]);
				cout << "  " << "Следующая дата" << " ";
				next[j].day = 1;
				next[j].month = 1;
				next[j].year += 1;
				cout << next[j].day << "/" << next[j].month << "/" << next[j].year << endl;
			}
		}
	}

	delete[] prev;
	delete[] next;
}


Datetime* Application::ReadFileDate(string fileName)
{
	int second, minute, hour, day, month, year;
	int n = 0;
	ifstream file(fileName);
	string line;

	while (getline(file, line))
	{
		n++;
	}
	Datetime* data_next = new Datetime[n];
	int k = 0;
	file.clear();
	file.seekg(0, ios::beg);

	string line_1;
	while (getline(file, line_1))
	{
		istringstream line_F(line_1);
		line_F >> second >> minute >> hour >> day >> month >> year;
		data_next[k] = Datetime(second, minute, hour, day, month, year);
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

	return data_next;
}

int Application::ReadFileDate_n(string fileName)
{
	int x = 0;
	ifstream file(fileName);
	string line;

	while (getline(file, line))
	{
		x++;
	}
	return x;
}


void Application::Show(Datetime B)
{
	cout << B.hour << ":" << B.minute << ":" << B.second << " " << B.day << "/" << B.month << "/" << B.year;
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


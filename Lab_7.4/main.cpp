#include <iostream>
#include <string>
#include <map>
#include <ctime>
#include <Windows.h>
using namespace std;

struct Perekazy
{
	string r_platnyka, r_oderzhyvacha;
	double pererah_sum;
};


void add(map<int, Perekazy>& c)
{
	int pos = c.size();
	int tmp2;
	Perekazy tmp;

	cout << "Введіть розрахунковий рахунок платника: ";
	cin >> tmp.r_platnyka;
	cout << "Введіть розрахунковий рахунок одержувача: ";
	cin >> tmp.r_oderzhyvacha;
	cout << "Введіть перераховану суму в гривнях: ";
	cin >> tmp.pererah_sum;

	c.insert({ pos, tmp });
}




void display(map<int, Perekazy> c)
{
	for (int i = 0; i < c.size(); i++)
	{
		cout << "Розрахунковий рахунок платника " << c[i].r_platnyka << endl;
		cout << "Розрахунковий рахунок одержувача: " << c[i].r_oderzhyvacha << endl;
		cout << "Перерахована сума в гривнях: " << c[i].pererah_sum << endl;
		cout << endl;
	}
}


bool display(map<int, Perekazy> c, string r)
{
	for (int i = 0; i < c.size(); i++)
	{
		if (c[i].r_platnyka == r)
		{
			cout << "Сума, знята з розрахункового рахунку платника " << r << "дорівнює: " << c[i].pererah_sum << endl;
			return true;
		}
		else
		{
			cout << "Платника з розрахунковим рахунком " << r << "не знайдено." << endl;
			return false;
		}
	}
	
	
}


void sort(map<int, Perekazy>& c)
{
	for (int i = 0; i < c.size() - 1; i++)
		for (int j = i; j < c.size(); j++)
		{
			if (c[i].pererah_sum > c[j].pererah_sum)
			{
				Perekazy tmp;
				tmp = c[i];
				c.erase(i);
				c.insert({ i, c[j] });
				c.erase(j);
				c.insert({ j, tmp });
			}
		}
}


int main()
{
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251); 

	map<int, Perekazy> perekaz;
	int tmp2;
	string tmp3;
	do
	{
		cout << endl;
		cout << "[1] Додати переказ" << endl;
		cout << "[2] Вивести суму, зняту з вказаного розрахункового рахунку платника" << endl;
		cout << "[3] Вивести наявні перекази" << endl;
		cout << "[0] Вийти" << endl;
		do
		{
			cin >> tmp2;
		} while (tmp2 < 0 || tmp2 > 3);
		
		switch (tmp2)
		{
		case 1:
			add(perekaz);
			sort(perekaz);
			break;
		case 2:

			cout << "Розрахунковий рахунок платника: ";
				cin >> tmp3;

			display(perekaz, tmp3);
			break;
		case 3:
			display(perekaz);
			break;
		default:
			break;
		}
	} while (tmp2 != 0);
	return 0;
}

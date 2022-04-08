
#include <Windows.h>
#include<iostream>
#include<fstream>
#include<conio.h>
#include "classes.h"
#include<cmath>
using namespace std;

void wczytaj(player& P, settings& S, view& map, game& GameHub);

struct saves {
	int index;
	string nameSaved;
	string name;
	int wallet;
	int level;
	float multiplier;
	int winNumber;
	bool controlMode;
};

int main()
{
	string name = "";
	system("cls");
	view map(30, 30);
	player p1(1000, name, 1, 1, 0);
	game GameHub(1);
	settings config(0);

	int choice;
	system("CLS");
	cout << "1.Nowa gra\n"
		"2.Wczytaj gre\n"
		"3.Wyjdz\n"
		"\nwybor:";
	cin >> choice;
	switch (choice) {
	case 1:
		cout << "Podaj swoje imie: ";
		cin.get();
		getline(cin, name);
		p1.name = name;
		config.controlMode = 0;
		map.init(GameHub, p1);
		for (;;)
		{
			while (_kbhit())
			{
				map.updateMap(GameHub, p1, config);
			}
		}
		break;

	case 2:
		wczytaj(p1, config, map, GameHub);
		break;

	case 3:
		exit(0);
		break;

	default:
		system("cls");
		main();
		break;

		return 0;
	}
}

void wczytaj(player& P, settings& S, view& map, game& GameHub) {
	system("cls");
	int index = 0;
	fstream file("savedGames.txt", ios::in);
	saves arrSaves[3];
	while (!file.eof() && index < 3)
	{
		file >> arrSaves[index].nameSaved;
		file >> arrSaves[index].name;
		file >> arrSaves[index].wallet;
		file >> arrSaves[index].level;
		file >> arrSaves[index].multiplier;
		file >> arrSaves[index].winNumber;
		file >> arrSaves[index].controlMode;
		index++;
	}

	if (index == 1)
	{
		arrSaves[1].nameSaved = "Brak";
		arrSaves[2].nameSaved = "Brak";
	}
	else if (index == 2)
	{
		arrSaves[2].nameSaved = "Brak";
	}
	else if (index == 0)
	{
		arrSaves[0].nameSaved = "Brak";
		arrSaves[1].nameSaved = "Brak";
		arrSaves[2].nameSaved = "Brak";
	}
	for (int i = 0; i < index; i++)
	{
		cout << i + 1 << ". " << arrSaves[i].nameSaved << endl;
	}
	cout << index + 1 << ". " << "Wroc\n Wybierz: ";
	int choice;

	cin >> choice;
	switch (choice) {
	case 1:
		P.name = arrSaves[0].name;
		P.currentWallet = arrSaves[0].wallet;
		P.level = arrSaves[0].level;
		P.multiplier = arrSaves[0].multiplier;
		P.winNumber = arrSaves[0].winNumber;
		S.controlMode = arrSaves[0].controlMode;
		break;

	case 2:
		P.name = arrSaves[1].name;
		P.currentWallet = arrSaves[1].wallet;
		P.level = arrSaves[1].level;
		P.multiplier = arrSaves[1].multiplier;
		P.winNumber = arrSaves[1].winNumber;
		S.controlMode = arrSaves[1].controlMode;
		break;

	case 3:
		P.name = arrSaves[2].name;
		P.currentWallet = arrSaves[2].wallet;
		P.level = arrSaves[2].level;
		P.multiplier = arrSaves[2].multiplier;
		P.winNumber = arrSaves[2].winNumber;
		S.controlMode = arrSaves[2].controlMode;
		break;

	case 4:
		main();
		break;

	default:
		wczytaj(P, S, map, GameHub);
		break;

	}

	map.init(GameHub, P);
	for (;;)
	{
		while (_kbhit())
		{
			map.updateMap(GameHub, P, S);
		}
	}
	file.close();
}


#include "classes.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
/*Maps Functions*/

int view::checkMovePlayer(char direction)
{
	switch (direction)
	{
	case 'U':
		if (playerPositionY > 1)
			if (((playerPositionX >= widthMap / 4 && playerPositionX <= widthMap / 4 + 4) && (playerPositionY == heightMap / 4 * 3 + 5)) || (playerPositionX >= widthMap / 4 * 3 && playerPositionX <= widthMap / 4 * 3 + 4) && (playerPositionY == heightMap / 4 * 3 + 5) || (playerPositionX >= widthMap / 4 * 3 && playerPositionX <= widthMap / 4 * 3 + 4) && (playerPositionY == heightMap / 4 + 5) || (playerPositionX >= widthMap / 4 && playerPositionX <= widthMap / 4 + 4) && (playerPositionY == heightMap / 4 + 5) || ((playerPositionX >= widthMap / 2 - 2 && playerPositionX <= widthMap / 2 + 2) && (playerPositionY == heightMap / 2 + 3)))
				return 0;
			else
				return 1;
		break;
	case 'L':

		if (playerPositionX > 1)
			if ((playerPositionX == widthMap / 4 + 5) && (playerPositionY >= heightMap / 4 && playerPositionY <= heightMap / 4 + 4) || (playerPositionX == widthMap / 4 * 3 + 5) && (playerPositionY >= heightMap / 4 && playerPositionY <= heightMap / 4 + 4) || (playerPositionX == widthMap / 4 * 3 + 5) && (playerPositionY >= heightMap / 4 * 3 && playerPositionY <= heightMap / 4 * 3 + 4) || (playerPositionX == widthMap / 4 + 5) && (playerPositionY >= heightMap / 4 * 3 && playerPositionY <= heightMap / 4 * 3 + 4) || ((playerPositionX == widthMap / 2 + 3) && (playerPositionY >= heightMap / 2 - 2 && playerPositionY <= heightMap / 2 + 2)))
				return 0;
			else
				return 1;
		break;
	case 'R':
		if (playerPositionX < widthMap - 1)
			if ((playerPositionX == widthMap / 4 - 1) && (playerPositionY >= heightMap / 4 && playerPositionY <= heightMap / 4 + 4) || (playerPositionX == widthMap / 4 * 3 - 1) && (playerPositionY >= heightMap / 4 && playerPositionY <= heightMap / 4 + 4) || (playerPositionX == widthMap / 4 * 3 - 1) && (playerPositionY >= heightMap / 4 * 3 && playerPositionY <= heightMap / 4 * 3 + 4) || (playerPositionX == widthMap / 4 - 1) && (playerPositionY >= heightMap / 4 * 3 && playerPositionY <= heightMap / 4 * 3 + 4) || ((playerPositionX == widthMap / 2 - 3) && (playerPositionY >= heightMap / 2 - 2 && playerPositionY <= heightMap / 2 + 2)))
				return 0;
			else
				return 1;
		break;
	case 'D':
		if (playerPositionY < heightMap - 1)
			if (((playerPositionX >= widthMap / 4 && playerPositionX <= widthMap / 4 + 4) && (playerPositionY == heightMap / 4 * 3 - 1)) || (playerPositionX >= widthMap / 4 * 3 && playerPositionX <= widthMap / 4 * 3 + 4) && (playerPositionY == heightMap / 4 * 3 - 1) || (playerPositionX >= widthMap / 4 * 3 && playerPositionX <= widthMap / 4 * 3 + 4) && (playerPositionY == heightMap / 4 - 1) || (playerPositionX >= widthMap / 4 && playerPositionX <= widthMap / 4 + 4) && (playerPositionY == heightMap / 4 - 1) || ((playerPositionX >= widthMap / 2 - 2 && playerPositionX <= widthMap / 2 + 2) && (playerPositionY == heightMap / 2 - 3)))
				return 0;
			else
				return 1;
		break;
	case 'E':
		if ((playerPositionX == widthMap / 4 * 3 - 1) && (playerPositionY == heightMap / 4 * 3 + 2))
			return 1; //Poker
		else if ((playerPositionX == widthMap / 4 + 4 + 1) && (playerPositionY == heightMap / 4 * 3 + 2))
		{
			return 2;//Roulette
		}
		else if ((playerPositionX == widthMap / 4 + 5) && (playerPositionY == heightMap / 4 + 2))
		{
			return 3;//Slot Machine
		}
		else if ((playerPositionX == widthMap / 4 * 3 - 1) && (playerPositionY == heightMap / 4 + 2))
		{
			return 4;//Bets
		}
		else if ((playerPositionX == widthMap / 2) && (playerPositionY == heightMap / 2 + 3))
		{
			return 5;//Pub
		}
		break;
	}
}

void view::bye(player& P)
{
	cout << "\n===============================================================================================\n";
	cout << "Dzieki za gre, wychodzisz dzis z saldem " << P.wallet1 << "$";
	cout << "\n===============================================================================================\n";
}

void view::movePlayer(game GameList, player& P, settings& S)
{
	if (_kbhit())
	{
		if (S.controlMode == 0)
		{
			switch (_getch())
			{
			case 'w':
				if (view::checkMovePlayer('U') == 0);
				playerPositionY;
				if (view::checkMovePlayer('U') == 1)
					playerPositionY--;
				break;
			case 'a':
				if (view::checkMovePlayer('L') == 0)
					playerPositionX;
				if (view::checkMovePlayer('L') == 1)
					playerPositionX--;
				break;
			case 'd':

				if (view::checkMovePlayer('R') == 0)
					playerPositionX;
				if (view::checkMovePlayer('R') == 1)
					playerPositionX++;
				break;
			case  's':

				if (view::checkMovePlayer('D') == 0)
					playerPositionY;
				if (view::checkMovePlayer('D') == 1)
					playerPositionY++;
				break;
			case 13:
				if (view::checkMovePlayer('E') == 1)
				{
					GameList.startRoulette(P);
					system("pause");
					system("cls");
				}
				else if (view::checkMovePlayer('E') == 2)
				{
					GameList.startPoker(P);
					system("pause");
					system("cls");
				}
				else if (view::checkMovePlayer('E') == 3)
				{
					GameList.startSlotMachine(P);
					system("pause");
					system("cls");
				}
				else if (view::checkMovePlayer('E') == 4)
				{

					GameList.startZaklady(P);
					system("pause");
				}
				else if (view::checkMovePlayer('E') == 5)
				{
					GameList.startBar(P, S);
					system("pause");
					system("cls");
				}
				break;
			case 27:
				system("cls");
				bye(P);
				exit(0);
				break;
			}
		}
		else if (S.controlMode == 1)
		{
			switch (_getch())
			{
			case  72://'w':
				if (view::checkMovePlayer('U') == 0);
				playerPositionY;
				if (view::checkMovePlayer('U') == 1)
					playerPositionY--;
				break;
			case 75://'a':
				if (view::checkMovePlayer('L') == 0)
					playerPositionX;
				if (view::checkMovePlayer('L') == 1)
					playerPositionX--;
				break;
			case 77://'d':

				if (view::checkMovePlayer('R') == 0)
					playerPositionX;
				if (view::checkMovePlayer('R') == 1)
					playerPositionX++;
				break;
			case  80://'s':

				if (view::checkMovePlayer('D') == 0)
					playerPositionY;
				if (view::checkMovePlayer('D') == 1)
					playerPositionY++;
				break;
			case 13:
				if (view::checkMovePlayer('E') == 1)
				{
					GameList.startRoulette(P);
					system("pause");
					system("cls");
				}
				else if (view::checkMovePlayer('E') == 2)
				{
					GameList.startPoker(P);
					system("pause");
					system("cls");
				}
				else if (view::checkMovePlayer('E') == 3)
				{
					GameList.startSlotMachine(P);
					system("pause");
					system("cls");
				}
				else if (view::checkMovePlayer('E') == 4)
				{

					GameList.startZaklady(P);
					system("pause");
				}
				else if (view::checkMovePlayer('E') == 5)
				{
					GameList.startBar(P, S);
					system("pause");
					system("cls");
				}
				break;
			case 27:
				system("cls");
				bye(P);
				exit(0);
				break;
			}

		}
	}
}

void view::displayMap(game& GameList, player& P)
{

	cout << endl << endl << endl << endl;
	cout << " Gracz: " << P.name << endl << endl;
	cout << " Portfel: " << P.wallet1 << "\t Level: " << P.level << endl;
	for (int x = 0; x < widthMap + 18; x++)
	{
		cout << "--";
	}
	cout << endl;
	for (int y = 1, legend = 0; y < heightMap || legend < 20; y++, legend++)
	{
		cout << "|";
		for (int x = 1; x < widthMap; x++)
		{
			if (playerPositionX == x && playerPositionY == y)
				cout << "O ";
			else if ((x == widthMap / 4 + 4) && (y == heightMap / 4 + 2))
			{
				cout << "  ";
			}
			else if ((x == widthMap / 4 * 3) && (y == heightMap / 4 + 2))
			{
				cout << "  ";
			}
			else if ((x == widthMap / 4 * 3) && (y == heightMap / 4 * 3 + 2))
			{
				cout << "  ";
			}
			else if ((x == widthMap / 4 + 4) && (y == heightMap / 4 * 3 + 2))
			{
				cout << "  ";
			}
			else if ((x == widthMap / 2) && (y == heightMap / 2 + 2))
			{
				cout << "  ";
			}
			else if ((x >= widthMap / 4 && x <= (widthMap / 4 + 4)) && (y == heightMap / 4) || (x >= widthMap / 4 && x <= (widthMap / 4 + 4)) && (y == heightMap / 4 + 4) || (x >= (widthMap / 4 * 3) && x <= (widthMap / 4 * 3 + 4)) && (y == heightMap / 4) || (x >= (widthMap / 4 * 3) && x <= (widthMap / 4 * 3 + 4)) && (y == heightMap / 4 + 4) || (x >= widthMap / 4 && x <= (widthMap / 4 + 4)) && (y == heightMap / 4 * 3) || (x >= widthMap / 4 && x <= (widthMap / 4 + 4)) && (y == heightMap / 4 * 3 + 4) || (x >= widthMap / 4 * 3 && x <= (widthMap / 4 * 3 + 4)) && (y == heightMap / 4 * 3) || (x >= widthMap / 4 * 3 && x <= (widthMap / 4 * 3 + 4)) && (y == heightMap / 4 * 3 + 4) || ((x >= widthMap / 2 - 2 && x <= widthMap / 2 + 2) && (y == heightMap / 2 - 2)) || ((x >= widthMap / 2 - 2 && x <= widthMap / 2 + 2) && (y == heightMap / 2 + 2)))
			{
				cout << "* ";
			}
			else if ((x == widthMap / 4 + 2) && (y == heightMap / 4 + 2))
			{
				cout << "S ";
			}
			else if ((x == widthMap / 4 * 3 + 2) && (y == heightMap / 4 + 2))
			{
				cout << "Z ";
			}
			else if ((x == widthMap / 4 + 2) && (y == heightMap / 4 * 3 + 2))
			{
				cout << "K ";
			}
			else if ((x == widthMap / 4 * 3 + 2) && (y == heightMap / 4 * 3 + 2))
			{
				cout << "R ";
			}
			else if ((x == widthMap / 2) && (y == heightMap / 2))
			{
				cout << "B ";
			}
			else if ((x == widthMap / 4) && (y >= heightMap / 4 && y <= heightMap / 4 + 3) || (x == widthMap / 4 + 4) && (y >= heightMap / 4 && y <= heightMap / 4 + 3) || (x == widthMap / 4) && (y >= heightMap / 4 * 3 && y <= heightMap / 4 * 3 + 3) || (x == widthMap / 4 + 4) && (y >= heightMap / 4 * 3 && y <= heightMap / 4 * 3 + 3) || (x == widthMap / 4 * 3) && (y >= heightMap / 4 * 3 && y <= heightMap / 4 * 3 + 3) || (x == widthMap / 4 + 4) && (y >= heightMap / 4 * 3 + 4 && y <= heightMap / 4 * 3 + 3) || (x == widthMap / 4 * 3 + 4) && (y >= heightMap / 4 * 3 && y <= heightMap / 4 * 3 + 3) || (x == widthMap / 4 * 3 + 4) && (y >= heightMap / 4 && y <= heightMap / 4 + 3) || (x == widthMap / 4 * 3) && (y >= heightMap / 4 && y <= heightMap / 4 + 3) || ((x == widthMap / 2 - 2) && (y >= heightMap / 2 - 2 && y <= heightMap / 2 + 1)) || ((x == widthMap / 2 + 2) && (y >= heightMap / 2 - 2 && y <= heightMap / 2 + 1)))
			{
				cout << "* ";
			}
			else
				cout << "  ";
		}
		cout << "| ";
		if (legend < 20)
		{
			cout << marks[legend];
			for (int k = (marks[legend].size() + 1) / 2; k < 17; k++)
			{
				cout << "  ";
			}
			if ((marks[legend].size() + 1) % 2 != 1)
			{
				cout << " ";
			}
		}
		else
		{
			for (int k = 0; k < 17; k++)
			{
				cout << "  ";
			}
		}

		cout << "| " << endl;
	}
	for (int x = 1; x <= widthMap + 18; x++)
	{
		if ((widthMap / 2) >= x - 1 && (widthMap / 2) <= x + 1)
			cout << "  ";
		else
			cout << "--";
	}
	cout << endl;
}
/* General functions*/
void view::init(game GameList, player& P)
{
	system("cls");
	view::displayMap(GameList, P);
}
void view::updateMap(game GameList, player& P, settings& S)
{
	system("cls");
	view::movePlayer(GameList, P, S);
	view::displayMap(GameList, P);

}


/*Player*/
bool player::updateWallet(int wallet)
{
	if (wallet1 = wallet) return true;
	else return false;
}

bool player::checkWallet(int cost)
{
	if (wallet1 >= cost)
	{
		wallet1 -= cost;
		return true;
	}
	else
		return false;
}



void player::updatePlayer()
{
	winNumber++;
	if (winNumber < 5) level = 1;
	else if (winNumber >= 5 && winNumber < 10) level = 2;
	else if (winNumber >= 10 && winNumber < 20) level = 3;
	else if (winNumber >= 20 && winNumber < 35) level = 4;
	else if (winNumber >= 35 && winNumber < 50) level = 5;
}

/*Game*/
void game::money(player& obj)
{
	wallet = obj.wallet1;
}

/* Poker */
void game::nazwa(int x) {
	switch (x) {
	case 0:
		cout << "NIC";
		break;
	case 1:
		cout << "PARA";
		break;
	case 2:
		cout << "DWIE PARY";
		break;
	case 3:
		cout << "TROJKA";
		break;
	case 4:
		cout << "STRIT";
		break;
	case 5:
		cout << "FULL";
		break;
	case 6:
		cout << "KARETA";
		break;
	case 7:
		cout << "POKER";
		break;
	}
}

int game::losuj() {
	int random = (rand() % 6) + 1;
	return random;
}

void game::rzut(int x) {
	switch (x) {
	case 1:
		kosc1();
		break;
	case 2:
		kosc2();
		break;
	case 3:
		kosc3();
		break;
	case 4:
		kosc4();
		break;
	case 5:
		kosc5();
		break;
	case 6:
		kosc6();
		break;
	}
}

int game::uklad(int tab[5]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 1; j < 5 - i; j++)
			if (tab[j - 1] > tab[j])
				swap(tab[j - 1], tab[j]);
	}

	if (tab[0] == tab[1] && tab[1] == tab[2] && tab[2] == tab[3] && tab[3] == tab[4]) {
		return 7;
	}
	else if ((tab[0] == tab[1] && tab[1] == tab[2] && tab[2] == tab[3]) || (tab[1] == tab[2] && tab[2] == tab[3] && tab[3] == tab[4])) {
		return 6;
	}
	else if (tab[0] == tab[1] - 1 && tab[1] == tab[2] - 1 && tab[2] == tab[3] - 1 && tab[3] == tab[4] - 1) {
		return 4;
	}
	else if ((tab[0] == tab[1] && tab[1] == tab[2] && tab[3] == tab[4]) || (tab[1] == tab[2] && tab[2] == tab[3] && tab[0] == tab[4]) || (tab[2] == tab[3] && tab[3] == tab[4] && tab[0] == tab[1])) {
		return 5;
	}
	else if ((tab[0] == tab[1] && tab[1] == tab[2]) || (tab[1] == tab[2] && tab[2] == tab[3]) || (tab[2] == tab[3] && tab[3] == tab[4])) {
		return 3;
	}
	else if ((tab[0] == tab[1] && tab[2] == tab[3]) || (tab[1] == tab[2] && tab[3] == tab[4]) || (tab[0] == tab[1] && tab[3] == tab[4])) {
		return 2;
	}
	else if (tab[0] == tab[1] || tab[1] == tab[2] || tab[2] == tab[3] || tab[3] == tab[4]) {
		return 1;
	}
	else {
		return 0;
	}
}

void game::kosc1() {
	cout << "\n# # # # # # # # #\n#               #\n#               #\n#               #\n#       @       #\n#               #\n#               #\n#               #\n# # # # # # # # #\n";
}

void game::kosc2() {
	cout << "\n# # # # # # # # #\n#               #\n#               #\n#    @          #\n#               #\n#          @    #\n#               #\n#               #\n# # # # # # # # #\n";
}

void game::kosc3() {
	cout << "\n# # # # # # # # #\n#               #\n#   @           #\n#               #\n#       @       #\n#               #\n#           @   #\n#               #\n# # # # # # # # #\n";
}

void game::kosc4() {
	cout << "\n# # # # # # # # #\n#               #\n#   @       @   #\n#               #\n#               #\n#               #\n#   @       @   #\n#               #\n# # # # # # # # #\n";
}

void game::kosc5() {
	cout << "\n# # # # # # # # #\n#               #\n#   @       @   #\n#               #\n#       @       #\n#               #\n#   @       @   #\n#               #\n# # # # # # # # #\n";
}

void game::kosc6() {
	cout << "\n# # # # # # # # #\n#               #\n#   @       @   #\n#               #\n#   @       @   #\n#               #\n#   @       @   #\n#               #\n# # # # # # # # #\n";
}

void game::zasady() {
	cout << "KOSCIANY POKER ZASADY:\n1. wybranie stawki\n2. rzut piecioma koscmi\n3. mozliwosc ponownego rzutu 1 lub 2 koscmi\n4. porownanie ukladow z przeciwnikiem\n5. wygrana dwoch rund oznacza wygrana pieniezna\n\n";
	system("pause");
	system("CLS");
	cout << "MOZLIWE UKLADY (od najwyzszego):\n\n";
	system("pause");
	system("CLS");
	cout << "1. POKER (5 razy taka sama liczba oczek)\n";
	for (int i = 0; i < 5; i++) {
		kosc5();
	}
	cout << endl;
	system("pause");
	system("CLS");
	cout << "2. KARETA (4 razy taka sama liczba oczek)\n";
	for (int i = 0; i < 4; i++) {
		kosc4();
	}
	kosc1();
	cout << endl;
	system("pause");
	system("CLS");
	cout << "3. FULL (3 razy taka sama liczba oczek i 2 razy inna taka sama liczba oczek)\n";
	for (int i = 0; i < 3; i++) {
		kosc3();
	}
	for (int i = 0; i < 2; i++) {
		kosc2();
	}
	cout << endl;
	system("pause");
	system("CLS");
	cout << "4. STRIT (5 kolejnych liczb oczek):\n";
	kosc1();
	kosc2();
	kosc3();
	kosc4();
	kosc5();
	cout << endl;
	system("pause");
	system("CLS");
	cout << "lub:\n";
	kosc2();
	kosc3();
	kosc4();
	kosc5();
	kosc6();
	cout << endl;
	system("pause");
	system("CLS");
	cout << "5. TROJKA (3 razy taka sama liczba oczek):\n";
	for (int i = 0; i < 3; i++) {
		kosc3();
	}
	kosc1();
	kosc2();
	cout << endl;
	system("pause");
	system("CLS");
	cout << "6. DWIE PARY (2 razy taka sama liczba oczek dla dwoch roznych liczb):\n";
	kosc6();
	kosc6();
	kosc4();
	kosc4();
	kosc1();
	cout << endl;
	system("pause");
	system("CLS");
	cout << "7. PARA (2 razy taka sama liczba oczek):\n";
	kosc5();
	kosc5();
	kosc1();
	kosc2();
	kosc3();
	cout << endl;
	system("pause");
	system("CLS");
	cout << "8. NIC (na kazdej kosci inna liczba oczek, niewystepujacych po kolei):\n";
	kosc1();
	kosc2();
	kosc3();
	kosc5();
	kosc6();
	cout << endl;
	system("pause");
	system("CLS");
}

int game::startPoker(player& P)
{
	money(P);
	cout << "Portfel: " << wallet << endl;
	srand(time(NULL));
	int gracz[5];
	int bot[5];
	int stawka, runda = 1, gracz_reka, bot_reka;
	int gracz_pkt = 0, bot_pkt = 0;

	cout << "Czy chcesz wyswietlic zasady?(t/n) ";
	char czy_zasady;
	czy_zasady = getchar();
	if (czy_zasady == 't') {
		system("CLS");
		zasady();
	}
	system("CLS");

	cout << "Czy chcesz zagrac?(t/n) ";
	char czy_zagrac;
	cin >> czy_zagrac;
	if (czy_zagrac == 'n') {
		return 0;
	}
	system("CLS");

	cout << "Wybierz stawke: $";
	cin >> stawka;
	system("CLS");
	cout << "Stawka: $" << stawka << endl << endl;
	system("pause");

	while (gracz_pkt != 2 && bot_pkt != 2) {
		system("CLS");
		cout << "RUNDA " << runda << ".\n\n";
		system("pause");
		system("CLS");

		for (int i = 0; i < 5; i++) {
			gracz[i] = losuj();
			bot[i] = losuj();
		}

		cout << "Wylosowano:\n";
		for (int i = 0; i < 5; i++) {
			Sleep(500);
			rzut(gracz[i]);
		}

		cout << "\nCzy chcesz ponownie rzucic 1 lub 2 koscmi?(t/n) ";
		char czy;
		cin >> czy;
		if (czy == 'n') {
			cout << "\nNie zmieniasz rzutu\n";
		}
		else if (czy == 't') {
			int a = 0, b = 0;
			cout << "\nPodaj numer(y) kosci(w przypadku tylko jednej wpisz numer drugiej jako 0, kazdorazowo zatwierdzajac enterem) do ponownego rzutu:\n";
			cin >> a >> b;
			if (a == 0 && b == 0) {
				cout << "\nNie zmieniasz rzutu\n";
			}
			else {
				system("CLS");
				if (a != 0) {
					gracz[a - 1] = losuj();
					Sleep(1000);
					cout << "Ponowny rzut koscia " << a << ".:\n";
					Sleep(1000);
					rzut(gracz[a - 1]);
				}
				if (b != 0) {
					gracz[b - 1] = losuj();
					Sleep(1000);
					cout << "\nPonowny rzut koscia " << b << ".:\n";
					Sleep(1000);
					rzut(gracz[b - 1]);
				}
				cout << endl;
				system("pause");
				system("CLS");
				cout << "Aktualne zestawienie kosci:\n";
				for (int i = 0; i < 5; i++) {
					Sleep(500);
					rzut(gracz[i]);
				}
			}
		}

		gracz_reka = uklad(gracz);

		cout << endl;
		system("pause");
		system("CLS");
		cout << "Przeciwnik wylosowal:\n";
		for (int i = 0; i < 5; i++) {
			Sleep(500);
			rzut(bot[i]);
		}
		bot_reka = uklad(bot);

		cout << endl;
		system("pause");
		system("CLS");

		cout << "Twoj uklad: ";
		nazwa(gracz_reka);
		cout << "\n\n\nUklad przeciwnika: ";
		nazwa(bot_reka);

		if (gracz_reka > bot_reka) {
			gracz_pkt++;
			cout << "\n\n\nWYGRANA! Wynik: " << gracz_pkt << " : " << bot_pkt;
		}
		else if (gracz_reka < bot_reka) {
			bot_pkt++;
			cout << "\n\n\nPRZEGRANA! Wynik: " << gracz_pkt << " : " << bot_pkt;
		}
		else if (gracz_reka == bot_reka) {
			cout << "\n\n\nREMIS! Wynik: " << gracz_pkt << " : " << bot_pkt;
		}
		cout << endl << endl;
		system("pause");
		runda++;
	}

	system("CLS");
	if (gracz_pkt == 2) {
		wallet = wallet + stawka * (2 + P.mnoznik);
		P.updatePlayer();
		P.updateWallet(wallet);
		cout << "Koniec gry. Wygrywasz $" << wallet;
	}
	if (bot_pkt == 2) {
		wallet = wallet - stawka * P.mnoznik;
		cout << "Koniec gry. Przegrywasz $" << wallet;
		P.updateWallet(wallet);
	}
	cout << endl << endl;
	system("pause");
}

/* Roulette */
void game::rules()
{
	system("cls");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);
	cout << "\n===============================================================================================\n";
	cout << "\t\t\tZasady gry";
	cout << "\n===============================================================================================";
	cout << "\n1. Wybierz numer od 0 do 36 lub jeden z kolorow: czerwony, czarny lub zielony";
	cout << "\n2. Jezeli postawisz na czerwony lub czarny, mozesz pomnozyc fundusze x";
	cout << "\n3. Jezeli zgadniesz liczbe, pomnozysz fundusze x7";
	cout << "\n4. Jezeli postawisz na zielony, mozesz pomnozyc fundusze x10";
	cout << "\n5. Jezeli nie zgadniesz, kwota zakladu zostanie odjeta od Twojego konta";
	cout << "\n6. Powodzenia!";
	cout << "\n===============================================================================================\n";
	SetConsoleTextAttribute(hConsole, 7);
}

void game::thanks(int& x, player& P)
{
	cout << "\n===============================================================================================\n";
	if (P.updateWallet(x) == true)
		cout << "Dzieki za gre, w Twoim portfelu znajduje sie " << x << "$";
	else
		cout << "Dzieki za gre, wystapil problem z wyplata. Przepraszamy";
	cout << "\n===============================================================================================\n";
}

void game::sizeOfBet(int& x, int& y)
{
	do
	{
		cout << "Wprowadz kwote zakladu: $";
		cin >> x;
		if (x > y)
		{
			cout << "Masz za malo pieniedzy!\n"
				<< "\nWprowadz inna kwote! \n";
			system("pause");
			system("cls");
		}
	} while (x > y);
}

int game::startRoulette(player& P)
{
	int guess;
	int dice;
	int numberOrColor;
	char choice;



	srand(time(NULL));



	do
	{
		system("cls");
		money(P);

		rules();
		sizeOfBet(bet, wallet);

		cout << "\nWybierz typ zakladu:\n[1] Postaw na liczbe\n[2] Postaw na kolor\n[3] Wyjscie \nWybor: ";
		cin >> numberOrColor;

		switch (numberOrColor)
		{

			//stawianie na liczbe

		case 1:

			//sprawdzenie poprawnosci

			do
			{
				system("cls");
				rules();
				cout << "\nPostaw na liczbe od 0 do 36 :";
				cin >> guess;
				if (guess <= 0 || guess > 36)
					cout << "\nLiczba powinna sie miescic w przedziale od 0 do 36!\n"
					<< "\nPostaw na poprawna liczbe: ";
			} while (guess <= 0 || guess > 36);
			system("cls");
			initDraw();
			//losowanie

			dice = rand() % 37;

			Sleep(1000);
			displayRoulette(dice);
			if (dice == guess)
			{
				cout << "\nGratulacje, wygrales " << bet * 7 << "$";
				wallet = wallet + bet * 7;
				P.updatePlayer();
			}
			else
			{
				cout << "Niestety, przegrales " << bet << "$\n";
				wallet = wallet - bet;
			}

			cout << "\nWygrywajaca liczba to: " << dice << "\n";
			cout << "\n" << P.name << ", Twoje fundusze to " << wallet << "$\n";
			if (wallet == 0)
			{
				cout << "\nNiestety, nie masz pieniedzy do gry \n";
			}
			break;

			//stawianie na kolor

		case 2:

			//wybor koloru

			do
			{
				system("cls");
				rules();
				cout << "\nPostaw na kolor: czerwony(nieparzyste), czarny(parzyste) lub zielony(0): \n[1] Czerwony\n[2] Czarny\n[3] Zielony\nWybor: ";
				cin >> guess;
				if (guess <= 0 || guess > 3)
					cout << "\nWprowadz poprawny wybor\n"
					<< "\nPostaw na poprawna liczbe: ";
			} while (guess <= 0 || guess > 3);
			system("cls");
			initDraw();
			dice = rand() % 37;

			Sleep(1000);
			displayRoulette(dice);
			// 0 (zielone)

			if ((dice == 0) && (guess == 0))
			{
				cout << "\nSuper wygrana! Jestes legenda kasyna!";
				cout << "\nGratulacje, wygrales " << bet * 10 << "$";
				P.updatePlayer();
				wallet = wallet + bet * 10;

			}

			//nieparzyste (czerwone)

			else if ((dice % 2 != 0) && (guess == 1)) {
				cout << "\nGratulacje, wygrales " << bet * 2 << "$";
				P.updatePlayer();
				wallet = wallet + bet * 2;
			}

			// parzyste(czarne)

			else if ((dice % 2 == 0) && (guess == 2))
			{
				cout << "\nGratulacje, wygrales " << bet * 2 << "$";
				P.updatePlayer();
				wallet = wallet + bet * 2;
			}

			//przegrana

			else {
				cout << "Niestety, przegrales " << bet << "$\n";
				wallet = wallet - bet;
				if (dice % 2 == 0 && dice != 0) {
					cout << "\nWygrywajacy kolor to czarny!" << "\n";
				}

				if (dice % 2 != 0 && dice != 0) {
					cout << "\nWygrywajacy kolor to czerwony!" << "\n";
				}

				if (dice == 0) {
					cout << "\nWygrywajacy kolor to zielony!" << "\n";
				}
			}

			cout << "\n" << P.name << ", Twoje fundusze to " << wallet << "$\n";
			if (wallet == 0)
			{
				cout << "\nNiestety, nie masz pieniedzy do gry \n";
			}
			break;

			//wyjscie

		case 3:
			thanks(wallet, P);
			system("pause");
			return 0;
			break;
		default:
			cout << "\nWprowadz poprawny wybor!";
			break;
		}
		cout << "\nChcesz zagrac jeszcze raz(t/n)? ";
		cin >> choice;
	} while (choice == 't' || choice == 'T');

	thanks(wallet, P);
	system("pause");
}

void setColor(int i)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (i == 0)
	{
		SetConsoleTextAttribute(hConsole, 47);
	}
	else if (i % 2 == 0)
	{
		SetConsoleTextAttribute(hConsole, 15);
	}
	else
	{
		SetConsoleTextAttribute(hConsole, 79);
	}
}

void setColor(int i, int checkedNumber)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (checkedNumber == 7) SetConsoleTextAttribute(hConsole, 31);
	else if (i == 0)
	{
		SetConsoleTextAttribute(hConsole, 47);
	}
	else if (i % 2 == 0)
	{
		SetConsoleTextAttribute(hConsole, 15);
	}
	else
	{
		SetConsoleTextAttribute(hConsole, 79);
	}
}

void game::initDraw()
{
	// czarny - parzyste -=  set 15
	//zielony - 0 - 47 set
	// czerwony - nieparzyste - set 79
	//wybrany - 31
	int pom = 7;
	int pomStart = 0;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << " ";


	for (int start = 0; start <= 36; start++)
		pomStart = start;
	for (int i = 0; i <= 12; i++)
	{
		setColor(i);
		cout << setw(2);
		cout << i;
		SetConsoleTextAttribute(hConsole, 7);
		if (i == 12) cout << " ";
		cout << " ";
	}
	cout << endl;
	for (int i = 13, j = 36; i <= 19 && j >= 30; i++, j--)
	{
		setColor(j);
		cout << j;
		SetConsoleTextAttribute(hConsole, 7);
		if (i == 13)
			cout << "\t\t    ^\t\t     ";
		else if (i == 14)
			cout << "\t\t    |\t\t     ";
		else if (i == 15)
			cout << "\t\t    |\t\t     ";
		else if (i == 16)
			cout << "\t\t    o\t\t     ";
		else
			cout << "\t \t \t\t     ";
		setColor(i);
		cout << i;
		SetConsoleTextAttribute(hConsole, 7);
		cout << endl;
	}
	for (int i = 29; i >= 20; i--)
	{
		cout << setw(3);
		setColor(i);
		cout << i;
		SetConsoleTextAttribute(hConsole, 7);
		cout << " ";
	}
	SetConsoleTextAttribute(hConsole, 7);

	cout << endl;
	cout << endl << endl;

}



void game::displayRoulette(int winNumber)
{
	// czarny - parzyste -  15
	//zielony - 0 - 47 
	// czerwony - nieparzyste - 79
	//wybrany - 31
	int tempNum; // Zapisuje tymczasowa liczbe ktora jest pierwsza w gornej sciance
	int pomStart = 0;
	int o;//sprawdza czy petla wypisze rowne 13 liczb
	int a;//sprawdza na jakiej liczbie stanelo
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int j;// wypisuje lewa sciane ruletki
	int checkedNumber;// sprawdza ktora liczba na gornej sciance jest 7 z kolei poniewaz jest to liczba wybrana
	int times = 0;//mnoznik szybkosci animacji
	for (int twice = 0; twice < 2; twice++)
	{
		for (int z = 0; z <= 36; z++)
		{
			times += z * 0.5;
			Sleep(times);
			system("cls");
			checkedNumber = 0;
			o = 0;
			cout << " ";
			tempNum = 36 - z;
			for (a = 36 - z; a <= 36 && o <= 12; a++, o++)
			{

				if (checkedNumber <= 7) checkedNumber++;

				cout << setw(2);
				setColor(a, checkedNumber);
				cout << a;
				SetConsoleTextAttribute(hConsole, 7);
				cout << " ";



			}
			if (o < 13)
			{

				pomStart = 36 - z;
				for (a = 36 - pomStart; a < 12; a++)
				{
					if (checkedNumber <= 7) checkedNumber++;
					setColor(a - z, checkedNumber);
					cout << setw(2);
					cout << a - z;
					SetConsoleTextAttribute(hConsole, 7);
					if (a == 11)
					{
						pomStart = a - z + 1;
					}

					cout << " ";
				}
			}
			else
			{
				if (a == 37) pomStart = 0;
				else if (a == 36) pomStart = 36;
				else
				{
					pomStart = a % 36;
				}

			}

			cout << endl;



			for (int i = pomStart, j = pomStart + 23; i <= pomStart + 6 && j >= pomStart + 17; i++, j--)
			{
				if (j > 36)
				{
					cout << setw(2);
					setColor(j % 36 - 1);
					cout << j % 36 - 1;
				}
				else
				{
					cout << setw(2);
					setColor(j);
					cout << j;
				}
				SetConsoleTextAttribute(hConsole, 7);
				if (i == pomStart)
					cout << "\t\t    ^\t\t     ";
				else if (i == pomStart + 1)
					cout << "\t\t    |\t\t     ";
				else if (i == pomStart + 2)
					cout << "\t\t    |\t\t     ";
				else if (i == pomStart + 3)
					cout << "\t\t    o\t\t     ";
				else
					cout << "\t \t \t\t     ";
				if (i > 36)
				{
					cout << setw(2);
					setColor(i % 36 - 1);
					cout << i % 36 - 1;
				}
				else
				{
					cout << setw(2);
					setColor(i);
					cout << i;
				}

				SetConsoleTextAttribute(hConsole, 7);
				cout << endl;
			}

			if (pomStart == 0) pomStart = 6;
			else if (pomStart == 36) pomStart = 5;
			else if (pomStart == 30) pomStart = -1;
			else
			{
				pomStart = (pomStart + 6) % 36;
				if (pomStart >= 1 && pomStart <= 6) pomStart -= 1;
			}

			for (int i = pomStart + 10; i > pomStart; i--)
			{
				cout << setw(3);
				if (i > 36)
				{
					setColor(i % 36 - 1);
					cout << i % 36 - 1;
				}
				else
				{
					setColor(i);
					cout << i;
				}
				SetConsoleTextAttribute(hConsole, 7);
				cout << " ";
			}
			SetConsoleTextAttribute(hConsole, 7);

			cout << endl;
			cout << endl << endl;
			if (twice == 1)
			{
				if (winNumber == 36 && tempNum == 30) break;
				if (winNumber == 0 && tempNum == 31) break;
				if ((tempNum + 6) % 37 == winNumber) break;
			}
		}
	}


}

/*Slot Machine */

void game::drawMachine()
{
	cout << "\n\n";
	cout << "			---------------------------------" << endl;
	cout << "			|                               |" << endl;
	cout << "			|    S L O T   M A C H I N E    |" << endl;
	cout << "			|                               |" << endl;
	cout << "			|                               |" << endl;
	cout << "			|                               |" << endl;
	cout << "			|                               |" << endl;
	cout << "			|-------------------------------|" << endl;
	cout << "			|          |         |          |" << endl;
	cout << "			|          |         |          |" << endl;
	cout << "			|          |         |          |" << endl;
	cout << "			|-------------------------------|" << endl;
	cout << "			|                               |" << endl;
	cout << "			|                               |" << endl;
	cout << "			|                               |" << endl;
	cout << "			|                               |" << endl;
	cout << "			|                               |" << endl;
	cout << "			|                               |" << endl;
	cout << "			---------------------------------" << endl;
	cout << "\n\n\n\n";
}

void game::gotoxy(int x, int y)
{
	COORD coordinate;
	coordinate.X = x;
	coordinate.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}

void game::startSlotMachine(player& P)
{
	srand(time(NULL));
	char choice;
	int a, b, c;
	int tab[3];
	money(P);
	cout << "Portfel: " << wallet << endl;
	do
	{
		system("cls");
		sizeOfBet(bet, wallet);
		a = rand() % 4, b = rand() % 4, c = rand() % 4;

		if (a > b && a > c)
		{
			a -= 1;
		}
		else if (b > a && b > c)
		{
			b -= 1;
		}
		else if (c > b && c > a)
		{
			c -= 1;
		}
		else if (a < b && a < c)
		{
			a += 1;
		}
		else if (c < b && c < a)
		{
			c += 1;
		}
		else if (b < a && b < c)
		{
			b += 1;
		}

		tab[0] = a;
		tab[1] = b;
		tab[2] = c;

		cout << "\nWitaj podrozniku! Rzucisz wyzwanie jednorekiemu bandycie? \nNacisnij dowolny klawisz aby zakrecic i zatrzymac maszyne, powodzenia!\n\n";

		system("pause");

		drawMachine();

		for (; !_kbhit(); ) {
			Sleep(80);
			a++;
			b++;
			c++;

			gotoxy(20, 10);
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 10);
			cout << "\n\n\n\n\n\n\n			|     " << (char)(a + 2) << "    |    " << (char)(b + 2) << "    |    " << (char)(c + 2) << "     |    ";
			SetConsoleTextAttribute(hConsole, 7);
			if (a == 4) {
				a = 0;
			}
			if (b == 4) {
				b = 0;
			}
			if (c == 4) {
				c = 0;
			}
		}

		getchar();
		cout << "\n\t\t";

		if ((a == b) && (b == c)) {
			cout << "\n\n\n\n\n\n			|     GRATULACJE! WYGRANA!\n\n";
			P.updatePlayer();
			wallet = wallet + bet * 2;
		}

		else {
			cout << "\n\n\n\n\n\n			|     Niestety, PRZEGRANA\n\n";
			wallet = wallet - bet;
		}
		cout << "\n" << "Twoje fundusze to " << wallet << "$\n";
		cout << "\nChcesz zagrac jeszcze raz(t/n)? ";
		cin >> choice;
	} while (choice == 't' || choice == 'T');

	thanks(wallet, P);

	system("pause");
}

/*Zaklady */

int game::losujTeam()
{
	int x = (rand() % 20) + 1;
	return x;
}

string game::druzyna(int nr)
{
	string names[20] = { "Milan", "Inter Mediolan", "Roma", "Napoli", "Juventus", "Sassuolo", "Atalanta", "Hellas Werona","Lazio","Benevento","Sampdoria","Bologna","Udinese","Fiorentina","Cagliari","Parma","Torino","Spezia","Genoa","Crotone" };
	return names[nr];
}

int game::losuj_wynik()
{
	int x = rand() % 2;
	return x;
}

int game::wynik(int bet)
{
	int mecz = losuj_wynik();
	if (bet == mecz) {
		return 1;
	}
	else {
		return 0;
	}
}

void game::startZaklady(player& P)
{
	srand(time(NULL));
	money(P);
	int nr_druzyn[20];
	for (int i = 1; i <= 20; i++) {
		nr_druzyn[i - 1] = i;
	}
	string t1_name, t2_name, t3_name, t1_opp_name, t2_opp_name, t3_opp_name;
	int t1, t2, t3, t1_opp, t2_opp, t3_opp;
	int bet1, bet2, bet3;
	int winorlose;
	int ile_meczy;
	int stawka;

	cout << "==========================================================\n";
	cout << "WYBIERZ ILE MECZY CHCESZ OBSTAWIC\n";
	cout << "1.Jeden mecz\n";
	cout << "2.Dwa mecze\n";
	cout << "3.Trzy mecze\n";
	cout << "(aby wygrac wszystkie obstawione mecze musza byc trafione)\n";
	cout << "==========================================================\n";
	cout << "wybor:";
	cin >> ile_meczy;
	cout << "podaj stawke: $";
	cin >> stawka;
	system("CLS");
	winorlose = 1;

	switch (ile_meczy) {
	case 1:
		t1 = losuj();
		t1_opp = losuj();
		while (t1_opp == t1) {
			t1_opp = losuj();
		}
		t1_name = druzyna(t1);
		t1_opp_name = druzyna(t1_opp);
		cout << "MECZ 1: druzyna nr " << t1 << ". " << t1_name << " gra z druzyna nr " << t1_opp << ". " << t1_opp_name << endl;
		cout << "[1]-wygrana   [0]-przegrana\n";
		cout << "Podaj przewidywany wynik dla pierwszego meczu: ";
		cin >> bet1;
		winorlose = wynik(bet1);
		if (winorlose == 1) {
			cout << "mecz trafiony!\n";
			cout << "WYGRANA\n";
			P.updatePlayer();
			cout << "wygrywasz $" << stawka * 2;
		}
		else if (winorlose == 0) {
			cout << "mecz nietrafiony!\n";
			cout << "PRZEGRANA";
		}
		break;
	case 2:
		t1 = losuj();
		t1_opp = losuj();
		t2 = losuj();
		t2_opp = losuj();
		while (t1_opp == t1) {
			t1_opp = losuj();
		}
		while (t2 == t1_opp || t2 == t1) {
			t2 = losuj();
		}
		while (t2_opp == t2 || t2_opp == t1_opp || t2_opp == t1) {
			t2_opp = losuj();
		}
		t1_name = druzyna(t1);
		t1_opp_name = druzyna(t1_opp);
		t2_name = druzyna(t2);
		t2_opp_name = druzyna(t2_opp);
		cout << "MECZ 1: druzyna nr " << t1 << ". " << t1_name << " gra z druzyna nr " << t1_opp << ". " << t1_opp_name << endl;
		cout << "MECZ 2: druzyna nr " << t2 << ". " << t2_name << " gra z druzyna nr " << t2_opp << ". " << t2_opp_name << endl;
		cout << "[1]-wygrana   [0]-przegrana\n";
		cout << "Podaj przewidywany wynik dla pierwszego meczu: ";
		cin >> bet1;
		cout << "Podaj przewidywany wynik dla drugiego meczu: ";
		cin >> bet2;
		winorlose = wynik(bet1);
		if (winorlose == 1) {
			cout << "pierwszy mecz trafiony!\n";
			winorlose = wynik(bet2);
			if (winorlose == 1) {
				cout << "drugi mecz trafiony!\n";
				cout << "WYGRANA\n";
				cout << "wygrywasz $" << stawka * 4;
			}
			else if (winorlose == 0) {
				cout << "drugi mecz nietrafiony!\n";
				cout << "PRZEGRANA";
				break;
			}
		}
		else if (winorlose == 0) {
			cout << "pierwszy mecz nietrafiony!\n";
			cout << "PRZEGRANA";
		}
		break;
	case 3:
		t1 = losuj();
		t1_opp = losuj();
		t2 = losuj();
		t2_opp = losuj();
		t3 = losuj();
		t3_opp = losuj();
		while (t1_opp == t1) {
			t1_opp = losuj();
		}
		while (t2 == t1_opp || t2 == t1) {
			t2 = losuj();
		}
		while (t2_opp == t2 || t2_opp == t1_opp || t2_opp == t1) {
			t2_opp = losuj();
		}
		while (t3 == t2_opp || t3 == t2 || t3 == t1_opp || t3 == t1) {
			t3 = losuj();
		}
		while (t3_opp == t3 || t3_opp == t2_opp || t3_opp == t2 || t3_opp == t1_opp || t3_opp == t1) {
			t3_opp = losuj();
		}
		t1_name = druzyna(t1);
		t1_opp_name = druzyna(t1_opp);
		t2_name = druzyna(t2);
		t2_opp_name = druzyna(t2_opp);
		t3_name = druzyna(t3);
		t3_opp_name = druzyna(t3_opp);
		cout << "MECZ 1: druzyna nr " << t1 << ". " << t1_name << " gra z druzyna nr " << t1_opp << ". " << t1_opp_name << endl;
		cout << "MECZ 2: druzyna nr " << t2 << ". " << t2_name << " gra z druzyna nr " << t2_opp << ". " << t2_opp_name << endl;
		cout << "MECZ 3: druzyna nr " << t3 << ". " << t3_name << " gra z druzyna nr " << t3_opp << ". " << t3_opp_name << endl;
		cout << "[1]-wygrana   [0]-przegrana\n";
		cout << "Podaj przewidywany wynik dla pierwszego meczu: ";
		cin >> bet1;
		cout << "Podaj przewidywany wynik dla drugiego meczu: ";
		cin >> bet2;
		cout << "Podaj przewidywany wynik dla trzeciego meczu: ";
		cin >> bet3;
		winorlose = wynik(bet1);
		if (winorlose == 1) {
			cout << "pierwszy mecz trafiony!\n";
			winorlose = wynik(bet2);
			if (winorlose == 1) {
				cout << "drugi mecz trafiony!\n";
				winorlose = wynik(bet3);
				if (winorlose == 1) {
					cout << "trzeci mecz trafiony!\n";
					cout << "WYGRANA\n";
					cout << "wygrywasz $" << stawka * 8;
					P.wallet1 += stawka * 8;
				}
				else if (winorlose == 0) {
					cout << "trzeci mecz nietrafiony!\n";
					cout << "PRZEGRANA";
					break;
				}
			}
			else if (winorlose == 0) {
				cout << "drugi mecz nietrafiony!\n";
				cout << "PRZEGRANA";
				break;
			}
		}
		else if (winorlose == 0) {
			cout << "pierwszy mecz nietrafiony!\n";
			cout << "PRZEGRANA";
		}
		break;
	default:
		cout << "Wybrales nieprawidlowa opcje\n";
		break;
	}
	cout << endl;
	system("pause");
}

void game::sterowanie(player& P, settings& S)
{
	system("CLS");
	cout << "========================================\n"
		"1.Sterowanie za pomoca klawiszy WASD\n"
		"2.Sterowanie za pomoca strzalek\n"
		"3.Wroc\n"
		"========================================\n"
		"\nWybor:";
	int x;
	cin >> x;
	switch (x) {
	case 1:
		S.controlMode = 0;
		break;
	case 2:
		S.controlMode = 1;
		break;
	case 3:
		menu(P, S);
		break;
	default:
		cout << "\nPodano bledna wartosc, sprobuj jeszcze raz\n\n";
		system("pause");
		sterowanie(P, S);
		break;
	}
}

void game::zapisz(player& P, settings& S)
{
	system("CLS");
	string nameSaved;
	cin.get();
	cout << "Wprowadz nazwe save: ";
	getline(cin, nameSaved);
	cout << "Zapisywanie gry\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			Sleep(250);
			cout << ". ";
		}
		cout << "\r";
	}
	fstream file("savedGames.txt", ios::app);
	if (file << nameSaved << " " << P.name << " " << P.wallet1 << " " << P.level << " " << P.mnoznik << " " << P.winNumber << " " << S.controlMode << endl) cout << "\nGra zostala zapisana!\n\n";
	else cout << "\n Wystapil problem z zapisem gry :C \n\n";
	file.close();

	system("pause");
	menu(P, S);
}



void game::drinki(player& P, settings& S)
{
	system("CLS");
	cout << "==========================================================================\n"
		"1.Johnny Silverhand (mnoznik zwiekszajacy wygrana razy 2) - 1000$\n"
		"2.Jackie Welles (mnoznik zwiekszajacy wygrana razy 1.5 - 500$\n"
		"3.Adam Smasher (mnoznik zwiekszajacy wygrana razy 1.25) - 250$\n"
		"4.Panam Palmer (mnoznik zwiekszajacy wygrana razy 1.05) - 50$\n"
		"5.Wroc\n"
		"==========================================================================\n"
		"Mozesz kupic tylko jeden drink, ktory bedzie aktualny\n"
		"\nWybor:";
	int x;
	cin >> x;
	switch (x) {
	case 1:

		if (P.checkWallet(1000))
		{
			cout << "\nZakupiono drink: Johnny Silverhand; wszystkie wygrane zwiekszaja sie dwukrotnie\n\n";
			P.mnoznik = 2;
		}
		else
			cout << "Nie masz na tyle pieniedzy\n";
		system("pause");
		break;
	case 2:

		if (P.checkWallet(500))
		{
			cout << "\nZakupiono drink: Jackie Welles; wszystkie wygrane zwiekszaja sie o polowe\n\n";
			P.mnoznik = 1.5;
		}
		else
			cout << "Nie masz na tyle pieniedzy\n";
		system("pause");
		break;
	case 3:

		if (P.checkWallet(250))
		{
			cout << "\nZakupiono drink: Adam Smasher; wszystkie wygrane zwiekszaja sie o 1/4\n\n";
			P.mnoznik = 1.25;
		}
		else
			cout << "Nie masz na tyle pieniedzy\n";
		system("pause");
		break;
	case 4:
		if (P.checkWallet(50))
		{
			cout << "\nZakupiono drink: Panam Palmer; wszystkie wygrane zwiekszaja o 5 procent\n\n";
			P.mnoznik = 1.05;
		}
		else
			cout << "Nie masz na tyle pieniedzy\n";
		system("pause");
		break;
	case 5:
		menu(P, S);
		break;
	default:
		cout << "\nPodano bledna wartosc, sprobuj jeszcze raz\n\n";
		system("pause");
		drinki(P, S);
		break;
	}
}

void game::menu(player& P, settings& S)
{
	int bonus;
	int* wsk_bonus = &bonus;
	int ster;
	int* wsk_ster = &ster;
	system("CLS");
	cout << "=======================\n"
		"1.Zmiana sterowania\n"
		"2.Zapisz gre\n"
		"3.Menu drinkow\n"
		"4.Wyjdz\n"
		"=======================\n"
		"\nWybor:";
	int x;
	cin >> x;
	switch (x) {
	case 1:
		sterowanie(P, S);
		break;
	case 2:
		zapisz(P, S);
		break;
	case 3:
		drinki(P, S);
		break;
	case 4:
		system("cls");
		break;
	default:
		cout << "\nPodano bledna wartosc, sprobuj jeszcze raz\n\n";
		system("pause");
		break;
		menu(P, S);
	}
}

void game::startBar(player& P, settings& S)
{
	menu(P, S);
}



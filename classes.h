#pragma once
#include<string>
using  std::string;



class settings
{
	/* Sterowanie, zmiana has³a */
private:



public:
	bool controlMode;
	settings(bool controlMode)
	{
		this->controlMode = controlMode;
	}

};

class player
{
	/*
		Stan konta gracza, przelicznik na wygran¹ i przegran¹
	*/
public:
	float mnoznik;
	int wallet1;
	int winNumber;
	int level;
	string name;
	player(int wallet, string name, float mnoznik, int level, int winNumber)
	{
		this->wallet1 = wallet;
		this->name = name;
		this->mnoznik = mnoznik;
		this->level = level;
		this->winNumber = winNumber;
	}

	bool updateWallet(int wallet);

	bool checkWallet(int cost);
	void updatePlayer();

};

class game
{
	/*Opisy gier, metody do gier*/
private:
	int number;
	int wallet;
	int bet;
public:
	game(int number)
	{
		this->number = number;
	}

	///* Ogolne */
	void money(player& obj);

	/* Poker */
	void kosc1();
	void kosc2();
	void kosc3();
	void kosc4();
	void kosc5();
	void kosc6();
	int losuj();
	void rzut(int);
	int uklad(int[]);
	void zasady();
	void nazwa(int);
	int startPoker(player& P);

	/* Ruletka */
	void rules();
	void thanks(int& x, player& P);
	void sizeOfBet(int& x, int& y);
	int startRoulette(player& P);
	void displayRoulette(int winNumber);
	void initDraw();

	/* Slot Machine */
	void gotoxy(int x, int y);
	void drawMachine();
	void startSlotMachine(player& P);

	/* Bet */

	int losujTeam();
	int losuj_wynik();
	string druzyna(int);
	int wynik(int);
	void startZaklady(player& P);

	/* Bar */
	void menu(player& P, settings& S);
	void sterowanie(player& P, settings& S);
	void zapisz(player& P, settings& S);
	void drinki(player& P, settings& S);
	void startBar(player& P, settings& S);
};

class view
{
	/*
		Wyœwietlanie mapy, u¿ytkownika, stanowisk z grami , animacji, menu
	*/
private:
	int widthMap;
	int heightMap;
	int playerPositionX;
	int playerPositionY;
	string marks[20];
	void movePlayer(game GameList, player& P, settings& S);
	void displayMap(game& GameList, player& P);
	int checkMovePlayer(char direction);
public:
	view(int widthMap, int heightMap)
	{
		this->widthMap = widthMap;
		this->heightMap = heightMap;
		this->playerPositionX = widthMap / 2;
		this->playerPositionY = heightMap - 2;
		this->marks[0] = "LEGENDA";
		this->marks[1] = "S - Slot Machine";
		this->marks[2] = "K - Kosci";
		this->marks[3] = "B - Bar z drinkami";
		this->marks[4] = "Z - zaklady";
		this->marks[5] = "R - ruletka";
		this->marks[6] = "Wybrane sterowanie klawiszy: 0";
		this->marks[7] = "W - gora";
		this->marks[8] = "A - lewa";
		this->marks[9] = "D - prawo";
		this->marks[10] = "S - dol";
		this->marks[11] = "Wybrane sterowanie klawiszy: 1";
		this->marks[12] = "Strzalka w gore - gora";
		this->marks[13] = "Strzalka w lewo - lewa";
		this->marks[14] = "Strzalka w prawo - prawo";
		this->marks[15] = "Strzalka w dol - dol";
		this->marks[18] = "ENTER - start gry(przy wejsciu)";
		this->marks[19] = "ESC - wyjscie";
	}

	void init(game GameList, player& P);
	void updateMap(game GameList, player& P, settings& S);
	void bye(player& P);
};


class data
{
	/*
		Zapis gry
	*/

private:

public:
	int nrSave;
	bool saveToFile(player& P, settings& S, int index, string& nameSaved);

};









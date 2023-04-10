#include "Game.h"
#include <windows.h>
#include <string>
#include <conio.h>
#include <ctime>
#include <stdlib.h>
#include <iostream>
using namespace std;

void Game::rand_val() {
	srand(time(NULL));
	for (int k = 0; k < arr_size;) {
		if (k < 3)
			rand_arr[k] = (rand() % 3); //количество case вариантов 
		else
			rand_arr[k] = (rand() % level);
		if (rand_arr[k] >= 0) {
			k++;

		}
	}
}

void Game::task() {
	/*
	rand_arr[0] выбор левого выражения
	rand_arr[1] выбор среднего выражения
	rand_arr[2] выбор правого выражения
	*/
	int sum1 = 0;
	int sum2 = 0;
	int a = rand_arr[4];
	int b = rand_arr[5];
	int c = rand_arr[6];
	int d = rand_arr[7];

	Decoration::pic_game(points);
	system("color 02");
	cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t******************************************";
	cout << "\n\t\t\t\t\t\t\t|\t" << "Your points - " << points << " score - " << score << "       |";
	cout << "\n\t\t\t\t\t\t\t******************************************\n\n";
	HANDLE soh = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(soh, (((0 << 4) | 1)));

	switch (rand_arr[0]) {
	case 0: sum1 = a + b; cout << "\t\t\t\t\t\t\t\t     " << "(" << a << " + " << b << ")"; break;
	case 1: sum1 = a - b; cout << "\t\t\t\t\t\t\t\t     " << "(" << a << " - " << b << ")"; break;
	case 2: sum1 = a * b; cout << "\t\t\t\t\t\t\t\t     " << "(" << a << " * " << b << ")"; break;
	}
	switch (rand_arr[1]) {
	case 0:cout << " + "; break;
	case 1:cout << " - "; break;
	case 2:cout << " * "; break;
	}
	switch (rand_arr[2]) { //(a + b) + (c + d)
	case 0: sum2 = c + d; cout << "(" << c << " + " << d << ")"; break;
	case 1: sum2 = c - d; cout << "(" << c << " - " << d << ")"; break;
	case 2: sum2 = c * d; cout << "(" << c << " * " << d << ")"; break;

	}
	switch (rand_arr[1]) {
	case 0:total = sum1 + sum2; break;
	case 1:total = sum1 - sum2; break;
	case 2:total = sum1 * sum2; break;
	}

}

void Game::show_task(int time_s, int val) {
	time_sec = time_s;
	level = val;
	HANDLE soh = GetStdHandle(STD_OUTPUT_HANDLE);
	
	while (true) {
		Decoration::start();
		start();
		SetConsoleTextAttribute(soh, (((0 << 4) | 4)));
		cout << "\n\n\n\n\n\n\n\n";
		Decoration::pic_end();
		SetConsoleTextAttribute(soh, (((0 << 4) | 2)));
		cout << "\t\t\t\t\t\t\t\t       Your score - " << score << "\n\n";
		SetConsoleTextAttribute(soh, (((0 << 4) | 1)));
		cout << "\t\t\t\t\t\t\t\     press Enter to start the game again\n";
		cout << "\t\t\t\t\t\t\t\t        ESC to exit";
		Decoration::beep_end();
		Sleep(2000);
		int choice = _getch();
		if (choice == 13) {
			points = 100;
			score = 0;
			system("cls");
		}
		else
			break;
	}


}

void Game::start() {

	do {
		rand_val();
		task();
		cout << "\n\n\t\t\t\t\t\t\t\t     " << "Result = ";
		string name;
		char ch;
		if (wait_for_key(time_sec * 1000, ch)) {
			cout << ch;
			getline(cin, name);
			name = ch + name;
			if (stoi(name) == total) {
				score++;
			}
			else {
				points -= 10;
				cout << "\a";
			}
		}

		else {
			system("color 04");
			cout << "Time is out\a";
			Sleep(1000);
			points -= 10;
		}

		system("cls");
	} while (points != 0);

}



bool Game::wait_for_key(int timeout_milliseconds, char& ch) {
	HANDLE tui_handle = GetStdHandle(STD_INPUT_HANDLE);
	DWORD tui_evtc = 0;
	DWORD deadline = GetTickCount64() + timeout_milliseconds;
	INPUT_RECORD tui_inrec = { 0 };
	DWORD tui_numread = 0;

	while (GetTickCount64() < deadline) {
		if (tui_evtc > 0) {
			ReadConsoleInput(tui_handle, &tui_inrec, 1, &tui_numread);
			if (tui_inrec.EventType == KEY_EVENT) {
				if (tui_inrec.Event.KeyEvent.bKeyDown) {
					ch = tui_inrec.Event.KeyEvent.uChar.AsciiChar;
					return true;
				}
			}
		}
		YieldProcessor();
		GetNumberOfConsoleInputEvents(tui_handle, &tui_evtc);
	}

	return false;
}
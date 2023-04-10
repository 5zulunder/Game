#pragma once
#include"Decoration.h"

class Game:public Decoration
{
	int total;		  //результат выражения(реальный)
	int points;       //количество стартовых (жизней)
	int level;        //сложнось(максимальный размер случайного числа)
	int time_sec;	  //время на выполнения задания
	int score;        //правильные ответы
	int* rand_arr;    //размер массива рандомных чисел
	int arr_size;     //массив рандомных чисел
public:
	Game()
	{
		total = 0;
		points = 100;
		level = 0;
		score = 0;
		time_sec = 0;
		arr_size = 8;
		rand_arr = new int[arr_size];
	}
	~Game() {
		if (rand_arr != nullptr) {
			delete[] rand_arr;
			rand_arr = nullptr;
		}
	}
private:
	bool wait_for_key(int timeout_milliseconds, char& ch);

	void rand_val();

	void task();

	void start();
public:
	void show_task(int time_s, int val);
};


#pragma once
#include"Decoration.h"

class Game:public Decoration
{
	int total;		  //��������� ���������(��������)
	int points;       //���������� ��������� (������)
	int level;        //��������(������������ ������ ���������� �����)
	int time_sec;	  //����� �� ���������� �������
	int score;        //���������� ������
	int* rand_arr;    //������ ������� ��������� �����
	int arr_size;     //������ ��������� �����
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


#ifndef STUDENT_H
#define STUDENT_H

#include<iomanip>
#include<iostream>
#define N_TIMES 30
#define DOW 5
#define INTERVAL 2
using namespace std;

class Student {
public:
	int TimeTable[DOW][N_TIMES] = { 0 };	//���� �ð�ǥ
	void makeTimeTable(int day, float start, float end, int Priority);	//���� �ð�ǥ ä���
	void showTimeTable();	//���� �ð�ǥ ��� ( �׽�Ʈ ���� )
};

#endif
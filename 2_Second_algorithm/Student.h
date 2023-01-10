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
	int TimeTable[DOW][N_TIMES] = { 0 };	//개인 시간표
	void makeTimeTable(int day, float start, float end, int Priority);	//개인 시간표 채우기
	void showTimeTable();	//개인 시간표 출력 ( 테스트 목적 )
};

#endif
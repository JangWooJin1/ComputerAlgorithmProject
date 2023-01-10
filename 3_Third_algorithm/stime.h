#ifndef STIME_H
#define STIME_H
#include<iostream>

using namespace std;

//최적 시간을 나타내는 클래스
class STime {
private:
	int dow;	//요일
	float start;//시작시간
	float stop; //종료시간
public:
	STime(int _dow, float _start, float _stop) : dow(_dow), start(_start), stop(_stop) {}
	void PrintSTime();	//최적 시간 출력
};

#endif
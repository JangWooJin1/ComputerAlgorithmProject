#ifndef TIME_H
#define TIME_H
#include<string>
using namespace std;

//강의 시간을 의미하는 클래스
class Time {
public:
	string day;		//요일
	float start, end;	//시작, 종료시간
	Time(string _day, float _start, float _end) : day(_day), start(_start), end(_end) {}	//강의시간 생성
};

#endif
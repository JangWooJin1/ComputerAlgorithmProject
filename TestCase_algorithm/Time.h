#ifndef TIME_H
#define TIME_H
#include<string>
using namespace std;

//���� �ð��� �ǹ��ϴ� Ŭ����
class Time {
public:
	string day;		//����
	float start, end;	//����, ����ð�
	Time(string _day, float _start, float _end) : day(_day), start(_start), end(_end) {}	//���ǽð� ����
};

#endif
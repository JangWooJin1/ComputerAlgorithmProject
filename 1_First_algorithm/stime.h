#ifndef STIME_H
#define STIME_H
#include<iostream>

using namespace std;

//���� �ð��� ��Ÿ���� Ŭ����
class STime {
private:
	int dow;	//����
	float start;//���۽ð�
	float stop; //����ð�
public:
	STime(int _dow, float _start, float _stop) : dow(_dow), start(_start), stop(_stop) {}
	void PrintSTime();	//���� �ð� ���
};

#endif
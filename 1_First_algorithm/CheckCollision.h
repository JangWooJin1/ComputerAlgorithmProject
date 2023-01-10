#ifndef CHECKCOLLISION_H
#define CHECKCOLLISION_H

#include<vector>
#include<string>
#include<fstream>
#include"stime.h"
#include"Student.h"

class CheckCollision {
protected:
	vector<Student> people;			//���� �ð�ǥ���� ����
	vector<STime> available_times;	//���õ� ���� �ð����� ����
	int TimeTable[DOW][N_TIMES] = {0 };	//������� TimeTable�� ��� ��ģ ��
	int weightTable[DOW][N_TIMES - INTERVAL + 1] = {0 };	//�� TimeTalbe���� INTERVAL������ ����ġ�� ���� ��
public:
	int count = 0;
	int place = sizeof(this->TimeTable) + sizeof(this->weightTable);
	void addStudent(string filename);	//txt���Ͽ� ����Ǿ��ִ� ���� �ð�ǥ ���� ������ people�� �߰�
	int makeWeightTable();				//weightTable����� 
	virtual vector<STime> getOptimalTimes();	//�������weightTable���� �����ð��� ã�Ƽ� ��ȯ
	void showStudent();					//people�� �ִ� ���� �ð�ǥ�� ��� ( �׽�Ʈ )
};

#endif
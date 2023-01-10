#ifndef PERSON_H
#define PERSON_H
#include"CSVTable.h"
#include"Time.h"
#include"Lecture.h"

//����� �ǹ��ϴ� Ŭ����
class Person {
private:
	vector<Lecture> L;		//������ ������ �ִ� ���Ǹ��
	vector<Time> Times;		//�ð��浹Ȯ���� ���ؼ� ���� �ð����� Times�� ����
public:
	void addLecture(CSVTable& table);	//L�� ���� �߰�
	bool collision(Lecture l);			//�ð��浹������ ���� �Լ� ( true�� �浹 �߻� )
	void writeTable(CSVTable& table, string Filename);	//���� ���� �ð�ǥ ���� ���Ϸ� ���
};

#endif
#ifndef STUDENT_H
#define STUDENT_H

#include<iomanip>
#include<iostream>
#include"linked_node.h"
#define N_TIMES 30
#define DOW 5
#define INTERVAL 4
using namespace std;

class Student {
public:
	//������ ��ũ ����Ʈ�� ��带 �ֱ� ���� ����
	linked_node* end;
	//���ϸ��� ��ũ ����Ʈ�� ��������ϴ�
	linked_node linked_vector[DOW];
	//������ ��ũ����Ʈ�� �ְ� �ִ� ���ϰ� �ٸ��� ���ϱ� ���� ����
	int previous_day = -1;
	void makeTimeTable(int day, float start, float end, int Priority);	//���� �ð�ǥ ä���
	void set_end(int i);
	void set_next_node();
	linked_node* get_end();
};

#endif
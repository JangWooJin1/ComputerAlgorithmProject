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
	//요일의 링크 리스트에 노드를 넣기 위한 변수
	linked_node* end;
	//요일마다 링크 리스트르 만들었습니다
	linked_node linked_vector[DOW];
	//이전의 링크리스트에 넣고 있던 요일과 다른지 비교하기 위한 변수
	int previous_day = -1;
	void makeTimeTable(int day, float start, float end, int Priority);	//개인 시간표 채우기
	void set_end(int i);
	void set_next_node();
	linked_node* get_end();
};

#endif
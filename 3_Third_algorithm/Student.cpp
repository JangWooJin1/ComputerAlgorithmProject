#include"Student.h"

//개인 시간표 채우기
void Student::makeTimeTable(int day, float start, float end, int Priority) {
	//요일, 시작 시간, 끝 시간, 우선순위를 입력받는다.
	//받은 정보로 노드를 만들어서 링크 리스트의 끝에 넣는다.
	linked_node* cur = new linked_node(start, end, Priority);
	if (previous_day != day)
	{
		this->end = &linked_vector[day];
		previous_day = day;
	}
	this->end->next = cur;
	this->end = this->end->next;
}



void Student::set_next_node(){ end = end->next; }

void Student::set_end(int i){ end = linked_vector[i].next; }

linked_node* Student::get_end() { return end; }
#include"Student.h"

//���� �ð�ǥ ä���
void Student::makeTimeTable(int day, float start, float end, int Priority) {
	//����, ���� �ð�, �� �ð�, �켱������ �Է¹޴´�.
	//���� ������ ��带 ���� ��ũ ����Ʈ�� ���� �ִ´�.
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
#ifndef LECTURE_H
#define LECTURE_H
#include<string>
using namespace std;

//���Ǹ� �ǹ��ϴ� Ŭ����
class Lecture {
public:
	string category, num, name, credit, time, place, professor;	//�̼�����, �м����¹�ȣ, �������, ����, �ð�, ���ǽ�, ��米��

	//���� ����
	Lecture(string _category = " ", string _num = " ", string _name = " ", string _credit = " ", string _time = " ", string _place = " ", string _professor = " ") {
		category = _category;  num = _num;	name = _name; credit = _credit; time = _time; place = _place; professor = _professor;
	}
};

#endif
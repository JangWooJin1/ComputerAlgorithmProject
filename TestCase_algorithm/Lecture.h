#ifndef LECTURE_H
#define LECTURE_H
#include<string>
using namespace std;

//강의를 의미하는 클래스
class Lecture {
public:
	string category, num, name, credit, time, place, professor;	//이수구분, 학수강좌번호, 교과목명, 학점, 시간, 강의실, 담당교원

	//강의 생성
	Lecture(string _category = " ", string _num = " ", string _name = " ", string _credit = " ", string _time = " ", string _place = " ", string _professor = " ") {
		category = _category;  num = _num;	name = _name; credit = _credit; time = _time; place = _place; professor = _professor;
	}
};

#endif
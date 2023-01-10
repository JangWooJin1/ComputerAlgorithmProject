#ifndef PERSON_H
#define PERSON_H
#include"CSVTable.h"
#include"Time.h"
#include"Lecture.h"

//사람을 의미하는 클래스
class Person {
private:
	vector<Lecture> L;		//개인이 가지고 있는 강의목록
	vector<Time> Times;		//시간충돌확인을 위해서 강의 시간들을 Times에 저장
public:
	void addLecture(CSVTable& table);	//L에 강의 추가
	bool collision(Lecture l);			//시간충돌방지를 위한 함수 ( true면 충돌 발생 )
	void writeTable(CSVTable& table, string Filename);	//개인 랜덤 시간표 엑셀 파일로 출력
};

#endif
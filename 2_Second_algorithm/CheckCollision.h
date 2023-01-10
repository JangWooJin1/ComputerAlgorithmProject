#ifndef CHECKCOLLISION_H
#define CHECKCOLLISION_H

#include<vector>
#include<string>
#include<fstream>
#include"stime.h"
#include"Student.h"

class CheckCollision {
protected:
	vector<Student> people;			//개인 시간표들을 저장
	vector<STime> available_times;	//선택된 최적 시간들을 저장
	int TimeTable[DOW][N_TIMES] = { 0 };	//사람들의 TimeTable을 모두 합친 것
	int weightTable[DOW][N_TIMES - INTERVAL + 1] = { 0 };	//위 TimeTalbe에서 INTERVAL간격의 가중치를 더한 것
public:
	int count = 0;
	int place = sizeof(TimeTable) + sizeof(weightTable);
	void addStudent(string filename);	//txt파일에 저장되어있는 개인 시간표 정보 가져와 people에 추가
	int makeWeightTable();				//weightTable만들기 
	vector<STime> getOptimalTimes();	//만들어진weightTable에서 최적시간을 찾아서 반환
	void showStudent();					//people에 있는 개인 시간표들 출력 ( 테스트 )
};

#endif
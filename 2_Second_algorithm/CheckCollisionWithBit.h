#ifndef CHECKCOLLISIONWithBit_H
#define CHECKCOLLISIONWithBit_H
#include"CheckCollision.h"
#include<bitset>

class CheckCollisionWithBit : public CheckCollision {
private:
	std::bitset<N_TIMES> bits[DOW]; // 숫자 처리를 위한 비트열들
	std::bitset<N_TIMES> mask; // 최적 시간을 검사하는 비트열.
	// INTERVAL 만큼 1을 가진다.
	void setBit(int dow, float start, float end);
public:
	CheckCollisionWithBit();
	void addStudent(string filename);
	void addStudents(vector<string> filenames);
	//비트 마스크와 각 비트열을 & 연산하여 현재 자유 시간이 존재하는지 검사한다. => 존재하면 true, 존재하지 않으면 false을 반환한다.
	bool checkBit();							
	std::vector<STime> getOptimalTimes();	//checkBit을 통해 최적시간을 발견한 경우, 바로 반환한다.
};
#endif
#ifndef CHECKCOLLISIONWithBit_H
#define CHECKCOLLISIONWithBit_H
#include"CheckCollision.h"
#include<bitset>

class CheckCollisionWithBit : public CheckCollision {
private:
	std::bitset<N_TIMES> bits[DOW]; // ���� ó���� ���� ��Ʈ����
	std::bitset<N_TIMES> mask; // ���� �ð��� �˻��ϴ� ��Ʈ��.
	// INTERVAL ��ŭ 1�� ������.
	void setBit(int dow, float start, float end);
public:
	CheckCollisionWithBit();
	void addStudent(string filename);
	void addStudents(vector<string> filenames);
	//��Ʈ ����ũ�� �� ��Ʈ���� & �����Ͽ� ���� ���� �ð��� �����ϴ��� �˻��Ѵ�. => �����ϸ� true, �������� ������ false�� ��ȯ�Ѵ�.
	bool checkBit();							
	std::vector<STime> getOptimalTimes();	//checkBit�� ���� �����ð��� �߰��� ���, �ٷ� ��ȯ�Ѵ�.
};
#endif
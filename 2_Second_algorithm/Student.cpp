#include"Student.h"

//개인 시간표 채우기
void Student::makeTimeTable(int day, float start, float end, int Priority) {
	int s = static_cast<int>((start - 1) * 2);	//시작시간 인덱스값 구하기
	int e = static_cast<int>((end - 1) * 2);	//종료시간 인덱스값 구하기

	//요일과 시간을 개인 시간표(TimeTable)에 저장
	for (int i = s; i <= e; i++) TimeTable[day][i] = Priority;
}

//개인시간표 출력  ( 테스트 목적 )
void Student::showTimeTable() {
	string day[] = { "월", "화", "수", "목", "금" };
	cout << setw(7) << " ";
	for (int i = 0; i < DOW; i++) cout << day[i] << " ";

	cout << endl;

	for (int j = 0; j < N_TIMES; j++) {
		cout << setw(4) << static_cast<float>(j) / 2.0 + 1.0 << " : ";
		for (int i = 0; i < DOW; i++) cout << TimeTable[i][j] << "  ";
		cout << endl;
	}
}
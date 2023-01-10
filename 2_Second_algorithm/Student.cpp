#include"Student.h"

//���� �ð�ǥ ä���
void Student::makeTimeTable(int day, float start, float end, int Priority) {
	int s = static_cast<int>((start - 1) * 2);	//���۽ð� �ε����� ���ϱ�
	int e = static_cast<int>((end - 1) * 2);	//����ð� �ε����� ���ϱ�

	//���ϰ� �ð��� ���� �ð�ǥ(TimeTable)�� ����
	for (int i = s; i <= e; i++) TimeTable[day][i] = Priority;
}

//���νð�ǥ ���  ( �׽�Ʈ ���� )
void Student::showTimeTable() {
	string day[] = { "��", "ȭ", "��", "��", "��" };
	cout << setw(7) << " ";
	for (int i = 0; i < DOW; i++) cout << day[i] << " ";

	cout << endl;

	for (int j = 0; j < N_TIMES; j++) {
		cout << setw(4) << static_cast<float>(j) / 2.0 + 1.0 << " : ";
		for (int i = 0; i < DOW; i++) cout << TimeTable[i][j] << "  ";
		cout << endl;
	}
}
#include"stime.h"

//���� �ð� ���
void STime::PrintSTime() {
	if (dow == 0) cout << "������ ";
	else if (dow == 1) cout << "ȭ���� ";
	else if (dow == 2) cout << "������ ";
	else if (dow == 3) cout << "����� ";
	else if (dow == 4) cout << "�ݿ��� ";

	cout << start << " ~ " << stop << "����" << endl;
}

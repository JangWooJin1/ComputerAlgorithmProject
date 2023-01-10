#include"stime.h"

//최적 시간 출력
void STime::PrintSTime() {
	if (dow == 0) cout << "월요일 ";
	else if (dow == 1) cout << "화요일 ";
	else if (dow == 2) cout << "수요일 ";
	else if (dow == 3) cout << "목요일 ";
	else if (dow == 4) cout << "금요일 ";

	cout << start << " ~ " << stop << "교시" << endl;
}

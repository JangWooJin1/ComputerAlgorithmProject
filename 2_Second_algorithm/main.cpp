#include"CheckCollisionWithBit.h"

const int SIZE = 500;

int main() {
	CheckCollisionWithBit c;

	//반복문을 이용하여 SIZE크기 만큼의 개인 시간표가져오기
	string filename = "./files/data";
	for (int i = 1; i <= SIZE; i++) c.addStudent(filename + to_string(i) + ".txt");

	//최적시간들을 times에 저장 후 출력
	auto times = c.getOptimalTimes();
	cout << "총 " << SIZE << "명의 시간표에서 " << INTERVAL / 2.0 << "시간 간격의 최적시간이 " << times.size() << "개 존재합니다." << endl;
	for (int i = 0; i < times.size(); i++) times[i].PrintSTime();

	cout << c.count << "번의 비교, 산술연산이 발생하였습니다.\n";
	cout << c.place << "byte 크기의 공간을 사용했습니다.\n";

}
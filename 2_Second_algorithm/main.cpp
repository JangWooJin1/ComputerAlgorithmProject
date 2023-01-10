#include"CheckCollisionWithBit.h"

const int SIZE = 500;

int main() {
	CheckCollisionWithBit c;

	//�ݺ����� �̿��Ͽ� SIZEũ�� ��ŭ�� ���� �ð�ǥ��������
	string filename = "./files/data";
	for (int i = 1; i <= SIZE; i++) c.addStudent(filename + to_string(i) + ".txt");

	//�����ð����� times�� ���� �� ���
	auto times = c.getOptimalTimes();
	cout << "�� " << SIZE << "���� �ð�ǥ���� " << INTERVAL / 2.0 << "�ð� ������ �����ð��� " << times.size() << "�� �����մϴ�." << endl;
	for (int i = 0; i < times.size(); i++) times[i].PrintSTime();

	cout << c.count << "���� ��, ��������� �߻��Ͽ����ϴ�.\n";
	cout << c.place << "byte ũ���� ������ ����߽��ϴ�.\n";

}
#include"CheckCollision.h"

//txt���Ͽ� ����Ǿ��ִ� ���� �ð�ǥ ���� ������ people�� �߰�
void CheckCollision::addStudent(string filename) {
	ifstream fin(filename);	//���� ����

	if (fin.fail()) {	//���� ���� ����ó��
		cout << "�ش��ϴ� ������ �����ϴ�.\n";
		return;
	}

	string temp;		//������ �� ���� ����
	Student p;			//���� ��ü ����
	int day, Priority;	//����, �켱����
	float start, end;	//���۽ð�, ����ð�
	int index;			//���ڿ��� �ε��� ( ���ڿ� �Ľ̿� ��� )

	while (!fin.eof()) {
		fin >> temp;	//���� �� �� �о���� ( ex> 0,2.0,3.5,4 )

		index = temp.find(",");				//find�Լ��� �̿��� ','��ġ ã��
		day = stoi(temp.substr(0,index));	//substr�Լ��� �̿��� 0~index���� ����
		temp = temp.substr(index+1);		//����� ���� ������

		index = temp.find(",");				//find�Լ��� �̿��� ','��ġ ã��
		start = stof(temp.substr(0, index));//substr�Լ��� �̿��� 0~index���� ����
		temp = temp.substr(index + 1);		//����� ���� ������
				
		index = temp.find(",");				//find�Լ��� �̿��� ','��ġ ã��
		end = stof(temp.substr(0, index));	//substr�Լ��� �̿��� 0~index���� ����
		temp = temp.substr(index + 1);		//����� ���� ������

		index = temp.find("\n");				//find�Լ��� �̿��� '\n'��ġ ã��
		Priority = stoi(temp.substr(0, index)); //substr�Լ��� �̿��� 0~index���� ����

		p.makeTimeTable(day, start, end, Priority); //�о�� ������� ���� �ð�ǥ ä���
	}

	people.push_back(p);	//���� �ð�ǥ�� ��� ä������ CheckCollision::people�� �߰�
	this->place += sizeof(p.TimeTable);
	fin.close();	//���� �ݱ�
}

/*
����ġ�� ���� ������ ���̺��� �����.
�Ϲ� �˰��� 3�� �ݺ���
*/
//weightTable����� 
int CheckCollision::makeWeightTable() {
	int min = std::numeric_limits<int>::max(); // �ּҰ�
	const int last = N_TIMES - INTERVAL;
	for (int d = 0; d < DOW; d++) {
		for (int i = 0; i < last + 1; i++) {
			for (int w = 0; w < INTERVAL; w++) {
				weightTable[d][i] += TimeTable[d][i + w]; // ������ ���� ���̺�.
				count++;
			}
			count++;
			if (weightTable[d][i] < min)	min = weightTable[d][i];
		}
	}
	return min;
}


//������� weightTable���� �����ð��� ã�Ƽ� ��ȯ
vector<STime> CheckCollision::getOptimalTimes() {

	//�ݺ����� �̿��Ͽ� people�� ����Ǿ��ִ� ���� �ð�ǥ���� CheckCollision::TimeTable�� ��ġ��
	for (int d = 0; d < DOW; d++) {// ���� ��
		for (int i = 0; i < N_TIMES; i++) {// �� �ð��뺰�� ���ϱ�
			for (const auto& person : people) {
				count++;
				TimeTable[d][i] += person.TimeTable[d][i];
			}
		}
	}

	int min = makeWeightTable(); // �ϼ��� CheckCollision::TimeTable�� ������ ����ġ ���̺� ����

	//�ݺ����� �̿��Ͽ� ����ġ ���̺� Ž��
	for (int d = 0; d < DOW; d++) {
		for (int i = 0; i < N_TIMES - INTERVAL + 1; i++) {
			count++;
			if (weightTable[d][i] == min) {// Ž���� ���� �ּ� ����ġ�� ������ �������
				float start = static_cast<float>(0.5 * i + 1.0);				//���۽ð� ���
				float end = static_cast<float>(0.5 * (i + INTERVAL - 1) + 1.0);	//����ð� ���
				count+=2;
				//�����ð��� �����ϴ� STime ��ü ���� �� CheckCollision::available_times�� �߰� 
				available_times.push_back(STime(d, start, end));	
			}
		}
	}

	place += sizeof(available_times);
	return available_times;	//�ϼ��� available_times��ȯ
}

//people�� �ִ� ����� �ð�ǥ ��� ( �׽�Ʈ )
void CheckCollision::showStudent() {
	for (int i = 0; i < people.size(); i++) {
		cout << endl << i + 1 << "��° ����� �ð�ǥ : \n";
		people[i].showTimeTable();
	}
}
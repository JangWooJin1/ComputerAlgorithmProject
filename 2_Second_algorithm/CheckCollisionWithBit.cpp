#include"CheckCollisionWithBit.h"

void CheckCollisionWithBit::setBit(int dow, float start, float end) {
	int s_int = static_cast<int>((start - 1) * 2);
	int s_end = static_cast<int>((end - 1) * 2);

	for (int v = s_int; v <= s_end; v++)	bits[dow].set(v, true); // v��° ��Ʈ�� true�� �����Ѵ�.
}


CheckCollisionWithBit::CheckCollisionWithBit(){
	for (int i = 0; i < DOW; i++)	bits[i].reset(); // ��ü ��Ʈ�� 0���� �ʱ�ȭ.
	//mask.reset();
	//for (int i = 0; i < INTERVAL; i++)	mask.set(i, true); // INTERVAL ��ŭ�� ��Ʈ�� 1�� �ʱ�ȭ.
	place += sizeof(bits) + sizeof(mask);
	cout << mask << endl;
}


void CheckCollisionWithBit::addStudent(string filename) {
	place += sizeof(Student::TimeTable);

	ifstream fin(filename);	//���� ����

	string temp;		//������ �� ���� ����
	Student p;			//���� ��ü ����
	int day, Priority;	//����, �켱����
	float start, end;	//���۽ð�, ����ð�
	int index;			//���ڿ��� �ε��� ( ���ڿ� �Ľ̿� ��� )

	while (!fin.eof()) {
		fin >> temp;	//���� �� �� �о���� ( ex> 0,2.0,3.5,4 )

		index = temp.find(",");				//find�Լ��� �̿��� ','��ġ ã��
		day = stoi(temp.substr(0, index));	//substr�Լ��� �̿��� 0~index���� ����
		temp = temp.substr(index + 1);		//����� ���� ������

		index = temp.find(",");				//find�Լ��� �̿��� ','��ġ ã��
		start = stof(temp.substr(0, index));//substr�Լ��� �̿��� 0~index���� ����
		temp = temp.substr(index + 1);		//����� ���� ������

		index = temp.find(",");				//find�Լ��� �̿��� ','��ġ ã��
		end = stof(temp.substr(0, index));	//substr�Լ��� �̿��� 0~index���� ����
		temp = temp.substr(index + 1);		//����� ���� ������

		index = temp.find("\n");				//find�Լ��� �̿��� '\n'��ġ ã��
		Priority = stoi(temp.substr(0, index)); //substr�Լ��� �̿��� 0~index���� ����

		p.makeTimeTable(day, start, end, Priority); //�о�� ������� ���� �ð�ǥ ä���
		setBit(day, start, end); // ��Ʈ ���� �κ��� �ٸ�
	}

	people.push_back(p);	//���� �ð�ǥ�� ��� ä������ CheckCollision::people�� �߰�
	fin.close();
}


/*
* ��Ʈ ����ũ�� �� ��Ʈ���� & �����Ͽ� ���� ���� �ð��� �����ϴ��� �˻��Ѵ�.
* �����ϸ� true, �������� ������ false�� ��ȯ�Ѵ�.
*/
bool CheckCollisionWithBit::checkBit() {
	mask.reset();
	for (int i = 0; i < INTERVAL; i++)	mask.set(i, true);
	
	// ��Ʈ�� �˻��Ͽ� ������ ���� �����ϴ��� �˾ƺ���.
	for (int d = 0; d < DOW; d++) // ���� ���� �˻�
	{
		for (int i = 0; i < N_TIMES - INTERVAL + 1; i++) // �� �ð��� �˻�
		{
			auto result = bits[d] & (this->mask << i); // ��Ʈ �˻�. 
			// ���� �˻��ϴ� INTERVAL ��ġ�� & ������ ����� 0 �� �ȴٴ� ����
			// �ش� �ð��뿡 ������ �ִ� ����� ���ٴ� �ǹ̰� �ȴ�. 
			// �� ��� �ش� �ð���� ���� �ð��� �ǹǷ� �� �̻� ������ �ʿ䰡 ����.
			// �ƴ� ���, 0���� ó���� �κп� ���ؼ��� �������� �ʵ��� ó���Ѵ�.
			count++;
			cout <<d <<" " << i <<" "<< result << endl;
			if (result.none()) // ��� 0�̶�� == �ش� �ð��밡 ��� ������� ��ȿ�ϴٸ�
			{ // ���� �ð��븦 available_times �� �����Ѵ�.
				float start = static_cast<float>(0.5 * i + 1.0);
				float end = static_cast<float>(0.5 * (i + INTERVAL - 1) + 1.0);
				STime t(d, start, end);
				available_times.push_back(t);
			}
		}
	}
	return !available_times.empty(); // �ϳ��� �����ϸ� �̹� ���� �ð��� ã�� ���.
}


/*
	checkBit�� ���� �����ð��� �߰��� ���, �ٷ� ��ȯ�Ѵ�.
	*/
std::vector<STime> CheckCollisionWithBit::getOptimalTimes() {
	bool condition = checkBit(); // ���� �ð��� �����ϴ��� ���� �˻�.
	if (condition) { // ���� �ð�(interval ��ŭ ��� �ð�) �����ϸ�
		cout << "������ ã��!" << endl;
		place += sizeof(CheckCollision::available_times);
		return available_times; // ���� �ð� ��ȯ
	}


	for (int d = 0; d < DOW; d++) // ���� ��
	{
		for (int i = 0; i < N_TIMES; i++) // �� �ð��뺰�� ���ϱ�
		{
			count++;
			if (bits[d][i]) // �ش� �ð��뿡 ������ �ʿ��� ��츸 ���Ѵ�.
			{
				for (const auto& student : people)
				{
					TimeTable[d][i] += student.TimeTable[d][i];
					count++;
				}
			}
		}
	}
	int min = makeWeightTable(); // ����ġ ���̺� ����

	for (int d = 0; d < DOW; d++)
	{
		for (int i = 0; i < N_TIMES - INTERVAL + 1; i++)
		{
			count++;
			if (weightTable[d][i] == min) // ���õ� �ּ� �ð����� ���
			{
				float start = static_cast<float>(0.5 * i + 1.0);
				float end = static_cast<float>(0.5 * (i + INTERVAL - 1) + 1.0);
				count += 2;
				available_times.push_back(STime(d, start, end));
			}
		}
	}
	place += sizeof(CheckCollision::available_times);
	return available_times;
}

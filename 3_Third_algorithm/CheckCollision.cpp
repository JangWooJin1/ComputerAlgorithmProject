#include"CheckCollision.h"

//�л����� end������ head�� ������ �ش� ������ ���� �� ��带 ����Ű�� �Ѵ�.
void CheckCollision::set_students_end(int cur_DOW){
	for (int i = 0; i < people.size(); i++)
		people[i].set_end(cur_DOW);
}

void CheckCollision::addStudent(string filename){
	//�л����� �ð�ǥ�� ������ �ִ� ��ũ����Ʈ�� �����.
	ifstream fin(filename);

	string temp;		//������ �� ���� ����
	Student p;			//���� ��ü ����
	int day, Priority;	//����, �켱����
	float start, end;	//���۽ð�, ����ð�
	int index;			//���ڿ��� �ε��� ( ���ڿ� �Ľ̿� ��� )
	while (!fin.eof())
	{
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
		p.makeTimeTable(day, start, end, Priority);
		place += sizeof(linked_node);
	}

	people.push_back(p);
	fin.close();
}

int CheckCollision::makeWeightTable(){
	//���ϸ��� INTERVAL�� ������ ����ġ �迭�� �����.
	int min = std::numeric_limits<int>::max(); // �ּҰ�
	for (int i = 0; i < DOW; i++)
	{
		set_students_end(i);//�л����� end������ ������ ���� �� ���� �����Ѵ�.
		for (int j = 0; j < N_TIMES - INTERVAL + 1; j++)//weightTable�� �� ��ŭ �̵��Ѵ�.
		{
			//���� ���� �ִ� �ð��뿡 �ش��ϴ� ����ġ�� ���Ѵ�.
			for (int k = 0; k < people.size(); k++)
			{
				//���� ���� �ִ� �л��� end�� null�̶�� �ش� ������ �ð�ǥ�� ����ְų� �����ٴ� ���̱� ������ �Ѿ��.
				//�ð�ǥ�� ���ð��� �ð����� ���ð����� ũ�ٴ� ���� ���� �ð��밡 �ƴϱ� ������ �Ѿ��.
				if (!people[k].get_end())
				{
					count += 1; //�񱳿���
					continue;
				}
				else if (people[k].get_end()->start > j + INTERVAL - 1)
				{
					count += 2; //�񱳿���
					continue;
				}
				//�ð�ǥ�� ���� �ð��� �ð����� ���� �ð����� ���� ���
				//�ڿ� �˸��� �ð�ǥ�� �ð��밡 ���� �� �ֱ� ������ end�� ���� ���� �̵���Ű�� �ٽ� ��
				//�ٽ� ������ �� ���� ��尡 null�� �ƴϰ� �ð�ǥ�� ���۽ð��� �ð����� ���ð��뺸�� �۰ų� ���� ��� ����ġ�� ����
				else if (people[k].get_end()->end < j)
				{
					count += 3;	//�񱳿���
					people[k].set_next_node();
					count += 1;	//�񱳿���
					if (people[k].get_end() && people[k].get_end()->start <= j + INTERVAL - 1)
					{
						count += 1;	//�������
						weightTable[i][j] += people[k].get_end()->priority;
					}
				}
				//�׿��� ��� ����ġ�� ����
				else
				{
					count += 4;	//�񱳿���
					weightTable[i][j] += people[k].get_end()->priority;
					count += 1; //�������
				}
			}
			count += 1; //�񱳿���
			//���� �� ������ ����ġ�� ���� res���� ������ �� ���� ������ �����Ѵ�.
			if (min > weightTable[i][j]) min = weightTable[i][j];
		}
	}
	return min;
}

vector<STime> CheckCollision::getOptimalTimes()
{
	//min�� �ּ� ����ġ�� ����ȴ�.
	//available_times�� min�� ����ġ�� ���� ���ϰ� �ð��� ����ȴ�.
	int min = makeWeightTable();
	for (int d = 0; d < DOW; d++)	{
		for (int i = 0; i < N_TIMES - INTERVAL + 1; i++){
			count++; //�񱳿���
			if (weightTable[d][i] == min)			{
				float start = static_cast<float>(0.5 * i + 1.0);
				float end = static_cast<float>(0.5 * (i + INTERVAL - 1) + 1.0);
				count+=2; //�������
				available_times.push_back(STime(d, start, end));
			}
		}
	}

	return available_times;	//�ϼ��� available_times��ȯ
}
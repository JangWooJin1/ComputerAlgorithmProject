#include"Person.h"

//L�� ���� �߰�
void Person::addLecture(CSVTable& table) {
	srand(time(NULL));
	for (int i = 0; i < 5; i++) {
		int r = rand() % table.Lectures.size();	//table.Lectures�� ����Ǿ��ִ� �ð�ǥ�߿� �������� ����
		if (!collision(table.Lectures[r]))	L.push_back(table.Lectures[r]);	//�ð��浹�� Ȯ���غ��� �浹���� ������ �߰�
		else i--;	//�浹�ϸ� �ٽ� ����
	}
}

//�ð��浹������ ���� �Լ� ( true�� �浹 �߻� )
bool Person::collision(Lecture l) {
	string t = l.time;	//���� �����߿��� �ð� ������ t�� ����
	vector<Time> Tmps;	//l�� �ð��� �ӽ� �����ϴ� �迭

	int index = 0;
	string day;	//����
	float start, end;	//���۽ð�, ����ð�

	while (true) {
		//�Ľ��� ���� ����, ���۽ð�, ����ð� ����
		day = t.substr(0, 2);
		t = t.substr(2);

		index = t.find('-');
		start = stof(t.substr(0, index));
		t = t.substr(index + 1);

		index = t.find('/');
		end = stof(t.substr(0, index));

		Tmps.push_back(Time(day, start, end));

		//���� '/'�� �߰ߵȴٸ� �� ���ǿ� �ð��� 2���̻��̶�� �Ҹ��̹Ƿ� �ٽ� �ݺ�
		if (index == t.find("NOT FOUND")) break;
		else t = t.substr(index + 1);
	}


	for (int i = 0; i < Times.size(); i++) {
		for (int j = 0; j < Tmps.size(); j++) {
			if (Tmps[j].day == Times[i].day) {	//������ ���� ��쿡�� ���۽ð��� ����ð� ��
				if (Tmps[j].start < Times[i].end && Tmps[j].end > Times[i].start) return true;
			}
		}

	}

	//�浹�ϴ°� ������ ���� �߰�
	for (int i = 0; i < Tmps.size(); i++) Times.push_back(Tmps[i]);
	return false;

}

ostream& operator<<(ostream& o, CSVTable& table) {
	o << table.printTable();
	return o;
}

//���� ���� �ð�ǥ ���� ���Ϸ� ���
void Person::writeTable(CSVTable& table, string Filename) {
	ofstream out(Filename);

	table.putCell(new Cell("��ȣ", 0, 0, &table));
	table.putCell(new Cell("����", 0, 1, &table));
	table.putCell(new Cell("�̼�����", 0, 2, &table));
	table.putCell(new Cell("�м����¹�ȣ", 0, 3, &table));
	table.putCell(new Cell("�������", 0, 4, &table));
	table.putCell(new Cell("����", 0, 5, &table));
	table.putCell(new Cell("����/����", 0, 6, &table));
	table.putCell(new Cell("���ǽ�", 0, 7, &table));
	table.putCell(new Cell("��米��", 0, 8, &table));
	table.putCell(new Cell("����ķ�۽�", 0, 9, &table));
	table.putCell(new Cell("�����̼��бⱸ��", 0, 10, &table));


	for (int i = 0; i < L.size(); i++) {
		table.putCell(new Cell(to_string(i + 1), i + 1, 0, &table));
		table.putCell(new Cell("����", i + 1, 1, &table));
		table.putCell(new Cell(L[i].category, i + 1, 2, &table));
		table.putCell(new Cell(L[i].num, i + 1, 3, &table));
		table.putCell(new Cell(L[i].name, i + 1, 4, &table));
		table.putCell(new Cell(L[i].credit, i + 1, 5, &table));
		table.putCell(new Cell(L[i].time, i + 1, 6, &table));
		table.putCell(new Cell(L[i].place, i + 1, 7, &table));
		table.putCell(new Cell(L[i].professor, i + 1, 8, &table));
		table.putCell(new Cell("����", i + 1, 9, &table));
	}

	out << table;
	out.close();
}

#include"CSVTable.h"

//csv���Ͽ��� ����� ��� �� ũ�⸦ �����ϰ� ������ ũ�⿡ �ش��ϴ� dataTable����
CSVTable::CSVTable(int rowMax, int colMax) : rowMax(rowMax), colMax(colMax) {
	dataTable = new Cell**[rowMax];
	for (int i = 0; i < rowMax; i++) {
		dataTable[i] = new Cell * [colMax];
		for (int j = 0; j < colMax; j++) dataTable[i][j] = NULL;
	}
}

//�����Ҵ� ����
CSVTable::~CSVTable() {
	for (int i = 0; i < rowMax; i++) {
		for (int j = 0; j < colMax; j++) {
			if (dataTable[i][j]) delete dataTable[i][j];
		}
	}
	for (int i = 0; i < rowMax; i++) {
		delete[] dataTable[i];
	}
	delete[] dataTable;
}


//���ο� ���� �߰�
void CSVTable::putCell(Cell* c) {
	//���� �ش� ��ġ�� ��ȿ���� �ľ�
	if (c->row >= rowMax || c->col >= colMax) return;

	//�ش� ��ġ�� ���� �̹� �����Ѵٸ� ���� ���� �����
	if (dataTable[c->row][c->col]) delete dataTable[c->row][c->col];

	//���ο� ���� ����
	dataTable[c->row][c->col] = c;
}


//�ش� �ϴ� ���� ������(���ڿ�)�� ��ȯ
string CSVTable::getData(int row, int col) {
	//��ġ�� ��ȿ�ؾ��ϰ� and �ش� ���� ���� �����ϴ��� �ľ�
	if (row < rowMax && col < colMax && dataTable[row][col]) return dataTable[row][col]->getData();
	return "";
}

//�������� ��������
void CSVTable::readTable(string Filename) {
	ifstream in(Filename);
	string tmp[12];

	for (int j = 0; j < 12; j++) {	//ù���� �����Ϳ� ���� �����̹Ƿ� �ʿ� x
		getline(in, tmp[j], ',');	//csv���� Ư���� ,������ �̷�����ֱ⶧���� ,������ ��� �б�
	}

	while (!in.eof()) {
		tmp[0] = tmp[11].substr(tmp[11].find('\n') + 1, 1);
		for (int j = 1; j < 12; j++) {
			getline(in, tmp[j], ',');
		}

		//�о�� ������ �߿��� �ʿ��Ѱ͸� ���ǿ� ����
		Lectures.push_back(Lecture(tmp[1], tmp[2], tmp[3], tmp[4], tmp[7], tmp[8], tmp[9]));
	}

	in.close();
}

//csv�������
string CSVTable::printTable() {
	string s = "";
	for (int i = 0; i < rowMax; i++) {
		for (int j = 0; j < colMax; j++) {
			//CSV ���� Ư���� ���� , ����
			if (j >= 1) s += ",";
			
			string tmp;
			if (dataTable[i][j]) tmp = dataTable[i][j]->getData();

			for (int k = 0; k < tmp.length(); k++) {
				if (tmp[k] == '"') {
					// k �� ��ġ�� " �� �� �� �� ����ִ´�.
					tmp.insert(k, 1, '"');
					k++;	//k��ġ �̵�
				}
			}
			s += '"' + tmp + '"';
		}
		s += '\n';
	}
	return s;
}


//Lectures�� ���ǰ� ����� ����Ǿ����� Ȯ��
void CSVTable::test() {
	for (int i = 0; i < Lectures.size(); i++) {
		cout << i + 1 << " ���� " << Lectures[i].category << " " << Lectures[i].num << " " << Lectures[i].name << " " << Lectures[i].credit << " " << Lectures[i].time\
			<< Lectures[i].place << " ���� \n";
	}
}
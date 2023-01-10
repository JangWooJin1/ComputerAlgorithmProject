#include"CSVTable.h"

//csv파일에서 사용할 행과 열 크기를 설정하고 설정한 크기에 해당하는 dataTable생성
CSVTable::CSVTable(int rowMax, int colMax) : rowMax(rowMax), colMax(colMax) {
	dataTable = new Cell**[rowMax];
	for (int i = 0; i < rowMax; i++) {
		dataTable[i] = new Cell * [colMax];
		for (int j = 0; j < colMax; j++) dataTable[i][j] = NULL;
	}
}

//동적할당 해제
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


//새로운 셀을 추가
void CSVTable::putCell(Cell* c) {
	//먼저 해당 위치가 유효한지 파악
	if (c->row >= rowMax || c->col >= colMax) return;

	//해당 위치에 셀이 이미 존재한다면 기존 셀을 지우고
	if (dataTable[c->row][c->col]) delete dataTable[c->row][c->col];

	//새로운 셀을 연결
	dataTable[c->row][c->col] = c;
}


//해당 하는 셀의 데이터(문자열)를 반환
string CSVTable::getData(int row, int col) {
	//위치가 유효해야하고 and 해당 셀의 값이 존재하는지 파악
	if (row < rowMax && col < colMax && dataTable[row][col]) return dataTable[row][col]->getData();
	return "";
}

//강의정보 가져오기
void CSVTable::readTable(string Filename) {
	ifstream in(Filename);
	string tmp[12];

	for (int j = 0; j < 12; j++) {	//첫줄은 데이터에 대한 설명이므로 필요 x
		getline(in, tmp[j], ',');	//csv파일 특성상 ,단위로 이루어져있기때문에 ,단위로 끊어서 읽기
	}

	while (!in.eof()) {
		tmp[0] = tmp[11].substr(tmp[11].find('\n') + 1, 1);
		for (int j = 1; j < 12; j++) {
			getline(in, tmp[j], ',');
		}

		//읽어온 정보들 중에서 필요한것만 강의에 저장
		Lectures.push_back(Lecture(tmp[1], tmp[2], tmp[3], tmp[4], tmp[7], tmp[8], tmp[9]));
	}

	in.close();
}

//csv파일출력
string CSVTable::printTable() {
	string s = "";
	for (int i = 0; i < rowMax; i++) {
		for (int j = 0; j < colMax; j++) {
			//CSV 파일 특성에 따라 , 삽입
			if (j >= 1) s += ",";
			
			string tmp;
			if (dataTable[i][j]) tmp = dataTable[i][j]->getData();

			for (int k = 0; k < tmp.length(); k++) {
				if (tmp[k] == '"') {
					// k 의 위치에 " 를 한 개 더 집어넣는다.
					tmp.insert(k, 1, '"');
					k++;	//k위치 이동
				}
			}
			s += '"' + tmp + '"';
		}
		s += '\n';
	}
	return s;
}


//Lectures에 강의가 제대로 저장되었는지 확인
void CSVTable::test() {
	for (int i = 0; i < Lectures.size(); i++) {
		cout << i + 1 << " 대학 " << Lectures[i].category << " " << Lectures[i].num << " " << Lectures[i].name << " " << Lectures[i].credit << " " << Lectures[i].time\
			<< Lectures[i].place << " 서울 \n";
	}
}
#include"Person.h"

//L에 강의 추가
void Person::addLecture(CSVTable& table) {
	srand(time(NULL));
	for (int i = 0; i < 5; i++) {
		int r = rand() % table.Lectures.size();	//table.Lectures에 저장되어있는 시간표중에 무작위로 선택
		if (!collision(table.Lectures[r]))	L.push_back(table.Lectures[r]);	//시간충돌을 확인해보고 충돌하지 않으면 추가
		else i--;	//충돌하면 다시 진행
	}
}

//시간충돌방지를 위한 함수 ( true면 충돌 발생 )
bool Person::collision(Lecture l) {
	string t = l.time;	//강의 정보중에서 시간 정보를 t에 저장
	vector<Time> Tmps;	//l의 시간을 임시 저장하는 배열

	int index = 0;
	string day;	//요일
	float start, end;	//시작시간, 종료시간

	while (true) {
		//파싱을 통해 요일, 시작시간, 종료시간 저장
		day = t.substr(0, 2);
		t = t.substr(2);

		index = t.find('-');
		start = stof(t.substr(0, index));
		t = t.substr(index + 1);

		index = t.find('/');
		end = stof(t.substr(0, index));

		Tmps.push_back(Time(day, start, end));

		//만약 '/'가 발견된다면 한 강의에 시간이 2개이상이라는 소리이므로 다시 반복
		if (index == t.find("NOT FOUND")) break;
		else t = t.substr(index + 1);
	}


	for (int i = 0; i < Times.size(); i++) {
		for (int j = 0; j < Tmps.size(); j++) {
			if (Tmps[j].day == Times[i].day) {	//요일이 같을 경우에만 시작시간과 종료시간 비교
				if (Tmps[j].start < Times[i].end && Tmps[j].end > Times[i].start) return true;
			}
		}

	}

	//충돌하는게 없으면 강의 추가
	for (int i = 0; i < Tmps.size(); i++) Times.push_back(Tmps[i]);
	return false;

}

ostream& operator<<(ostream& o, CSVTable& table) {
	o << table.printTable();
	return o;
}

//개인 랜덤 시간표 엑셀 파일로 출력
void Person::writeTable(CSVTable& table, string Filename) {
	ofstream out(Filename);

	table.putCell(new Cell("번호", 0, 0, &table));
	table.putCell(new Cell("구분", 0, 1, &table));
	table.putCell(new Cell("이수구분", 0, 2, &table));
	table.putCell(new Cell("학수강좌번호", 0, 3, &table));
	table.putCell(new Cell("교과목명", 0, 4, &table));
	table.putCell(new Cell("학점", 0, 5, &table));
	table.putCell(new Cell("요일/교시", 0, 6, &table));
	table.putCell(new Cell("강의실", 0, 7, &table));
	table.putCell(new Cell("담당교원", 0, 8, &table));
	table.putCell(new Cell("수업캠퍼스", 0, 9, &table));
	table.putCell(new Cell("집중이수학기구분", 0, 10, &table));


	for (int i = 0; i < L.size(); i++) {
		table.putCell(new Cell(to_string(i + 1), i + 1, 0, &table));
		table.putCell(new Cell("대학", i + 1, 1, &table));
		table.putCell(new Cell(L[i].category, i + 1, 2, &table));
		table.putCell(new Cell(L[i].num, i + 1, 3, &table));
		table.putCell(new Cell(L[i].name, i + 1, 4, &table));
		table.putCell(new Cell(L[i].credit, i + 1, 5, &table));
		table.putCell(new Cell(L[i].time, i + 1, 6, &table));
		table.putCell(new Cell(L[i].place, i + 1, 7, &table));
		table.putCell(new Cell(L[i].professor, i + 1, 8, &table));
		table.putCell(new Cell("서울", i + 1, 9, &table));
	}

	out << table;
	out.close();
}

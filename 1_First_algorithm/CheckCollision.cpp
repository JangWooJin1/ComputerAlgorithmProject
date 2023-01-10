#include"CheckCollision.h"

//txt파일에 저장되어있는 개인 시간표 정보 가져와 people에 추가
void CheckCollision::addStudent(string filename) {
	ifstream fin(filename);	//파일 열기

	if (fin.fail()) {	//파일 열기 예외처리
		cout << "해당하는 파일이 없습니다.\n";
		return;
	}

	string temp;		//파일의 한 줄을 저장
	Student p;			//개인 객체 생성
	int day, Priority;	//요일, 우선순위
	float start, end;	//시작시간, 종료시간
	int index;			//문자열의 인덱스 ( 문자열 파싱에 사용 )

	while (!fin.eof()) {
		fin >> temp;	//파일 한 줄 읽어오기 ( ex> 0,2.0,3.5,4 )

		index = temp.find(",");				//find함수를 이용해 ','위치 찾기
		day = stoi(temp.substr(0,index));	//substr함수를 이용해 0~index까지 추출
		temp = temp.substr(index+1);		//추출된 내용 버리기

		index = temp.find(",");				//find함수를 이용해 ','위치 찾기
		start = stof(temp.substr(0, index));//substr함수를 이용해 0~index까지 추출
		temp = temp.substr(index + 1);		//추출된 내용 버리기
				
		index = temp.find(",");				//find함수를 이용해 ','위치 찾기
		end = stof(temp.substr(0, index));	//substr함수를 이용해 0~index까지 추출
		temp = temp.substr(index + 1);		//추출된 내용 버리기

		index = temp.find("\n");				//find함수를 이용해 '\n'위치 찾기
		Priority = stoi(temp.substr(0, index)); //substr함수를 이용해 0~index까지 추출

		p.makeTimeTable(day, start, end, Priority); //읽어온 정보들로 개인 시간표 채우기
	}

	people.push_back(p);	//개인 시간표를 모두 채웠으면 CheckCollision::people에 추가
	this->place += sizeof(p.TimeTable);
	fin.close();	//파일 닫기
}

/*
가중치를 더해 구성한 테이블을 만든다.
일반 알고리즘 3중 반복문
*/
//weightTable만들기 
int CheckCollision::makeWeightTable() {
	int min = std::numeric_limits<int>::max(); // 최소값
	const int last = N_TIMES - INTERVAL;
	for (int d = 0; d < DOW; d++) {
		for (int i = 0; i < last + 1; i++) {
			for (int w = 0; w < INTERVAL; w++) {
				weightTable[d][i] += TimeTable[d][i + w]; // 가중합 계산된 테이블.
				count++;
			}
			count++;
			if (weightTable[d][i] < min)	min = weightTable[d][i];
		}
	}
	return min;
}


//만들어진 weightTable에서 최적시간을 찾아서 반환
vector<STime> CheckCollision::getOptimalTimes() {

	//반복문을 이용하여 people에 저장되어있는 개인 시간표들을 CheckCollision::TimeTable에 합치기
	for (int d = 0; d < DOW; d++) {// 요일 별
		for (int i = 0; i < N_TIMES; i++) {// 각 시간대별로 더하기
			for (const auto& person : people) {
				count++;
				TimeTable[d][i] += person.TimeTable[d][i];
			}
		}
	}

	int min = makeWeightTable(); // 완성된 CheckCollision::TimeTable을 가지고 가중치 테이블 생성

	//반복문을 이용하여 가중치 테이블 탐색
	for (int d = 0; d < DOW; d++) {
		for (int i = 0; i < N_TIMES - INTERVAL + 1; i++) {
			count++;
			if (weightTable[d][i] == min) {// 탐색된 곳이 최소 가중치를 가지고 있을경우
				float start = static_cast<float>(0.5 * i + 1.0);				//시작시간 계산
				float end = static_cast<float>(0.5 * (i + INTERVAL - 1) + 1.0);	//종료시간 계산
				count+=2;
				//최적시간을 저장하는 STime 객체 생성 후 CheckCollision::available_times에 추가 
				available_times.push_back(STime(d, start, end));	
			}
		}
	}

	place += sizeof(available_times);
	return available_times;	//완성된 available_times반환
}

//people에 있는 사람들 시간표 출력 ( 테스트 )
void CheckCollision::showStudent() {
	for (int i = 0; i < people.size(); i++) {
		cout << endl << i + 1 << "번째 사람의 시간표 : \n";
		people[i].showTimeTable();
	}
}
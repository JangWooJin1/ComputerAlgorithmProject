#include"CheckCollisionWithBit.h"

void CheckCollisionWithBit::setBit(int dow, float start, float end) {
	int s_int = static_cast<int>((start - 1) * 2);
	int s_end = static_cast<int>((end - 1) * 2);

	for (int v = s_int; v <= s_end; v++)	bits[dow].set(v, true); // v번째 비트를 true로 설정한다.
}


CheckCollisionWithBit::CheckCollisionWithBit(){
	for (int i = 0; i < DOW; i++)	bits[i].reset(); // 전체 비트를 0으로 초기화.
	//mask.reset();
	//for (int i = 0; i < INTERVAL; i++)	mask.set(i, true); // INTERVAL 만큼의 비트를 1로 초기화.
	place += sizeof(bits) + sizeof(mask);
	cout << mask << endl;
}


void CheckCollisionWithBit::addStudent(string filename) {
	place += sizeof(Student::TimeTable);

	ifstream fin(filename);	//파일 열기

	string temp;		//파일의 한 줄을 저장
	Student p;			//개인 객체 생성
	int day, Priority;	//요일, 우선순위
	float start, end;	//시작시간, 종료시간
	int index;			//문자열의 인덱스 ( 문자열 파싱에 사용 )

	while (!fin.eof()) {
		fin >> temp;	//파일 한 줄 읽어오기 ( ex> 0,2.0,3.5,4 )

		index = temp.find(",");				//find함수를 이용해 ','위치 찾기
		day = stoi(temp.substr(0, index));	//substr함수를 이용해 0~index까지 추출
		temp = temp.substr(index + 1);		//추출된 내용 버리기

		index = temp.find(",");				//find함수를 이용해 ','위치 찾기
		start = stof(temp.substr(0, index));//substr함수를 이용해 0~index까지 추출
		temp = temp.substr(index + 1);		//추출된 내용 버리기

		index = temp.find(",");				//find함수를 이용해 ','위치 찾기
		end = stof(temp.substr(0, index));	//substr함수를 이용해 0~index까지 추출
		temp = temp.substr(index + 1);		//추출된 내용 버리기

		index = temp.find("\n");				//find함수를 이용해 '\n'위치 찾기
		Priority = stoi(temp.substr(0, index)); //substr함수를 이용해 0~index까지 추출

		p.makeTimeTable(day, start, end, Priority); //읽어온 정보들로 개인 시간표 채우기
		setBit(day, start, end); // 비트 설정 부분이 다름
	}

	people.push_back(p);	//개인 시간표를 모두 채웠으면 CheckCollision::people에 추가
	fin.close();
}


/*
* 비트 마스크와 각 비트열을 & 연산하여 현재 자유 시간이 존재하는지 검사한다.
* 존재하면 true, 존재하지 않으면 false을 반환한다.
*/
bool CheckCollisionWithBit::checkBit() {
	mask.reset();
	for (int i = 0; i < INTERVAL; i++)	mask.set(i, true);
	
	// 비트를 검사하여 최적의 값이 존재하는지 알아본다.
	for (int d = 0; d < DOW; d++) // 요일 별로 검사
	{
		for (int i = 0; i < N_TIMES - INTERVAL + 1; i++) // 각 시간대 검사
		{
			auto result = bits[d] & (this->mask << i); // 비트 검사. 
			// 현재 검사하는 INTERVAL 위치를 & 연산한 결과가 0 이 된다는 것은
			// 해당 시간대에 업무가 있는 사람이 없다는 의미가 된다. 
			// 이 경우 해당 시간대는 최적 시간이 되므로 더 이상 연산할 필요가 없다.
			// 아닌 경우, 0으로 처리된 부분에 대해서는 연산하지 않도록 처리한다.
			count++;
			cout <<d <<" " << i <<" "<< result << endl;
			if (result.none()) // 모두 0이라면 == 해당 시간대가 모든 사람에게 유효하다면
			{ // 최적 시간대를 available_times 에 삽입한다.
				float start = static_cast<float>(0.5 * i + 1.0);
				float end = static_cast<float>(0.5 * (i + INTERVAL - 1) + 1.0);
				STime t(d, start, end);
				available_times.push_back(t);
			}
		}
	}
	return !available_times.empty(); // 하나라도 존재하면 이미 최적 시간을 찾은 경우.
}


/*
	checkBit을 통해 최적시간을 발견한 경우, 바로 반환한다.
	*/
std::vector<STime> CheckCollisionWithBit::getOptimalTimes() {
	bool condition = checkBit(); // 최적 시간이 존재하는지 먼저 검사.
	if (condition) { // 최적 시간(interval 만큼 비는 시간) 존재하면
		cout << "최적값 찾음!" << endl;
		place += sizeof(CheckCollision::available_times);
		return available_times; // 가능 시간 반환
	}


	for (int d = 0; d < DOW; d++) // 요일 별
	{
		for (int i = 0; i < N_TIMES; i++) // 각 시간대별로 더하기
		{
			count++;
			if (bits[d][i]) // 해당 시간대에 연산이 필요한 경우만 더한다.
			{
				for (const auto& student : people)
				{
					TimeTable[d][i] += student.TimeTable[d][i];
					count++;
				}
			}
		}
	}
	int min = makeWeightTable(); // 가중치 테이블 생성

	for (int d = 0; d < DOW; d++)
	{
		for (int i = 0; i < N_TIMES - INTERVAL + 1; i++)
		{
			count++;
			if (weightTable[d][i] == min) // 선택된 최소 시간대인 경우
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

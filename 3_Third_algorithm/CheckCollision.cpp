#include"CheckCollision.h"

//학생들의 end변수를 head를 제외한 해당 요일의 가장 앞 노드를 가르키게 한다.
void CheckCollision::set_students_end(int cur_DOW){
	for (int i = 0; i < people.size(); i++)
		people[i].set_end(cur_DOW);
}

void CheckCollision::addStudent(string filename){
	//학생마다 시간표의 정보가 있는 링크리스트를 만든다.
	ifstream fin(filename);

	string temp;		//파일의 한 줄을 저장
	Student p;			//개인 객체 생성
	int day, Priority;	//요일, 우선순위
	float start, end;	//시작시간, 종료시간
	int index;			//문자열의 인덱스 ( 문자열 파싱에 사용 )
	while (!fin.eof())
	{
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
		p.makeTimeTable(day, start, end, Priority);
		place += sizeof(linked_node);
	}

	people.push_back(p);
	fin.close();
}

int CheckCollision::makeWeightTable(){
	//요일마다 INTERVAL를 적용한 가중치 배열을 만든다.
	int min = std::numeric_limits<int>::max(); // 최소값
	for (int i = 0; i < DOW; i++)
	{
		set_students_end(i);//학생들의 end변수를 요일의 가장 앞 노드로 지정한다.
		for (int j = 0; j < N_TIMES - INTERVAL + 1; j++)//weightTable의 열 만큼 이동한다.
		{
			//현재 보고 있는 시간대에 해당하는 가중치를 더한다.
			for (int k = 0; k < people.size(); k++)
			{
				//현재 보고 있는 학생의 end가 null이라면 해당 요일의 시간표가 비어있거나 끝났다는 뜻이기 떄문에 넘어간다.
				//시간표의 끝시간이 시간대의 끝시간보다 크다는 것은 지금 시간대가 아니기 때문에 넘어간다.
				if (!people[k].get_end())
				{
					count += 1; //비교연산
					continue;
				}
				else if (people[k].get_end()->start > j + INTERVAL - 1)
				{
					count += 2; //비교연산
					continue;
				}
				//시간표의 시작 시간이 시간대의 시작 시간보다 작은 경우
				//뒤에 알맞은 시간표의 시간대가 있을 수 있기 떄문에 end를 다음 노드로 이동시키고 다시 비교
				//다시 비교했을 때 현재 노드가 null이 아니고 시간표의 시작시간이 시간대의 끝시간대보다 작거나 같은 경우 가중치를 더함
				else if (people[k].get_end()->end < j)
				{
					count += 3;	//비교연산
					people[k].set_next_node();
					count += 1;	//비교연산
					if (people[k].get_end() && people[k].get_end()->start <= j + INTERVAL - 1)
					{
						count += 1;	//산술연산
						weightTable[i][j] += people[k].get_end()->priority;
					}
				}
				//그외의 경우 가중치를 더함
				else
				{
					count += 4;	//비교연산
					weightTable[i][j] += people[k].get_end()->priority;
					count += 1; //산술연산
				}
			}
			count += 1; //비교연산
			//만약 다 더해진 가중치의 합이 res보다 작으면 더 작은 값으로 갱신한다.
			if (min > weightTable[i][j]) min = weightTable[i][j];
		}
	}
	return min;
}

vector<STime> CheckCollision::getOptimalTimes()
{
	//min에 최소 가중치가 저장된다.
	//available_times에 min의 가중치와 같은 요일과 시간이 저장된다.
	int min = makeWeightTable();
	for (int d = 0; d < DOW; d++)	{
		for (int i = 0; i < N_TIMES - INTERVAL + 1; i++){
			count++; //비교연산
			if (weightTable[d][i] == min)			{
				float start = static_cast<float>(0.5 * i + 1.0);
				float end = static_cast<float>(0.5 * (i + INTERVAL - 1) + 1.0);
				count+=2; //산술연산
				available_times.push_back(STime(d, start, end));
			}
		}
	}

	return available_times;	//완성된 available_times반환
}
#ifndef CSVTABLE_H
#define CSVTABLE_H

#include"Cell.h"
#include"Lecture.h"
#include<iostream>
#include<fstream>
#include<vector>

//csv파일작업을 위한 클래스
class CSVTable {
private:
	int rowMax, colMax;							//행 및 열의 최대 크기
	Cell*** dataTable;							//데이터를 저장하는 테이블 ( Cell* 을 저장하는 2차원배열 )
public:
	vector<Lecture> Lectures;					//readTable함수를 이용해서 모든 강의를 Lectures에 저장

	CSVTable(int rowMax, int colMax);			//csv파일에서 사용할 행과 열 크기를 설정하고 설정한 크기에 해당하는 dataTable생성
	~CSVTable();								//동적할당 해제
	
	void putCell(Cell* c);						//새로운 셀을 추가
	string getData(int row, int col);			//해당 하는 셀의 데이터(문자열)를 반환

	void readTable(string Filename);			//강의정보 가져오기
	string printTable();						//csv파일출력

	void test();								//Lectures에 강의들이 제대로 저장되었는지 테스트
};

#endif
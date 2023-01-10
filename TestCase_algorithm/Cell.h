#ifndef CELL_H
#define CELL_H
#include<string>
using namespace std;

class CSVTable;

class Cell {
private:
	CSVTable* t;	//테이블
	int row, col;	//셀의 위치
	string data;	//셀에 저장된 데이터
public:
	Cell(string data, int row, int col, CSVTable* t);	//셀 생성
	string getData();	//셀에 저장된 데이터 반환
	friend CSVTable;
};

#endif
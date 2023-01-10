#include"Cell.h"
//셀 생성
Cell::Cell(string data, int row, int col, CSVTable* t) : data(data), row(row), col(col), t(t) {}

//셀에 저장된 데이터 반환
string Cell::getData() { return data; }

#include"Cell.h"
//�� ����
Cell::Cell(string data, int row, int col, CSVTable* t) : data(data), row(row), col(col), t(t) {}

//���� ����� ������ ��ȯ
string Cell::getData() { return data; }

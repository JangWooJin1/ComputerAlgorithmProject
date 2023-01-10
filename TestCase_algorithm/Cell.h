#ifndef CELL_H
#define CELL_H
#include<string>
using namespace std;

class CSVTable;

class Cell {
private:
	CSVTable* t;	//���̺�
	int row, col;	//���� ��ġ
	string data;	//���� ����� ������
public:
	Cell(string data, int row, int col, CSVTable* t);	//�� ����
	string getData();	//���� ����� ������ ��ȯ
	friend CSVTable;
};

#endif
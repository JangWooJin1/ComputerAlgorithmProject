#ifndef CSVTABLE_H
#define CSVTABLE_H

#include"Cell.h"
#include"Lecture.h"
#include<iostream>
#include<fstream>
#include<vector>

//csv�����۾��� ���� Ŭ����
class CSVTable {
private:
	int rowMax, colMax;							//�� �� ���� �ִ� ũ��
	Cell*** dataTable;							//�����͸� �����ϴ� ���̺� ( Cell* �� �����ϴ� 2�����迭 )
public:
	vector<Lecture> Lectures;					//readTable�Լ��� �̿��ؼ� ��� ���Ǹ� Lectures�� ����

	CSVTable(int rowMax, int colMax);			//csv���Ͽ��� ����� ��� �� ũ�⸦ �����ϰ� ������ ũ�⿡ �ش��ϴ� dataTable����
	~CSVTable();								//�����Ҵ� ����
	
	void putCell(Cell* c);						//���ο� ���� �߰�
	string getData(int row, int col);			//�ش� �ϴ� ���� ������(���ڿ�)�� ��ȯ

	void readTable(string Filename);			//�������� ��������
	string printTable();						//csv�������

	void test();								//Lectures�� ���ǵ��� ����� ����Ǿ����� �׽�Ʈ
};

#endif
#include"CSVTable.h"
#include"Person.h"
using namespace std;

const int SIZE = 100;

int main() {
	CSVTable table(500, 13);
	table.readTable("학과별강의목록.csv");

	Person P[SIZE];
	for (int i = 0; i < SIZE; i++) {
		P[i].addLecture(table);
		P[i].writeTable(table, "./files/data" + to_string(i+1) + ".csv");
	}

	return 0;
}
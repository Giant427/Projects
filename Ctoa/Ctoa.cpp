/*
	This C++ file can convert a .csv file into C++ data structure (multidimensional arrays)
*/

#include "iostream"
#include "fstream"
#include "string"
#include "vector"
using namespace std;

const string delimeter = ",";
int cell_space = 5;

vector<string> GetRow (string Row) {
	auto start = 0U;
	auto end = Row.find(delimeter);
	string cell_data;
	vector<string> row;
	while (end != string::npos) {
		// split row data by ","
		cell_data = Row.substr(start, end - start);
		row.push_back(cell_data);
		start = end + delimeter.length();
		end = Row.find(delimeter, start);
		// cell data too big for cell size
		if (cell_data.length() > cell_space) {
			cell_space = cell_space + (cell_data.length() - cell_space) + 2;
		}
	}
	cell_data = Row.substr(start, end);
	row.push_back(Row.substr(start, end));
	if (cell_data.length() > cell_space) {
		cell_space = cell_space + (cell_data.length() - cell_space) + 2;
	}

	return row;
}

void main () {
	string whitespace = " ";
	int whitespace_index = 0;
	string line;
	fstream myfile ("data.csv");
	vector<vector<string>> data;
	if (myfile.is_open())
	{
		while (getline(myfile, line)) {
			data.push_back(GetRow(line));
		}
		myfile.close();
	}
	for (const auto &Row : data) {
		for (const auto &Column : Row) {
			whitespace_index = cell_space - Column.length();
			for (int i = 1; i < whitespace_index; i++) {
				whitespace = whitespace + " ";
			}
			cout << Column << whitespace;
			whitespace_index = 0;
			whitespace = " ";
		}
		cout << "\n";
	}

	return;
}
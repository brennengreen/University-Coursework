//--------------------------------------------------------------------------
//								CS215-003 LAB4
//--------------------------------------------------------------------------
// Author: Brennen Green
// Date: 09/17/2019
// Description: A C++ Program that displays a box of selected size to the user
// filled with characters of a selected type
//--------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const double NUM_EXAMS = 2.0;
const double NUM_PROJS = 3.0;
const double EXAM_WEIGHT = 0.5;
const double PROJ_WEIGHT = 0.3;
const double ATTENDANCE_WEIGHT = 0.2;

int main() {
	std::cout << "---------------------------------" << std::endl;
	std::cout << "-             Grader            -" << std::endl;
	std::cout << "-        By: Brennen Green      -" << std::endl;
	std::cout << "---------------------------------" << std::endl;

	string input_file_name;
	string output_file_name;
	cout << "Enter input file: ";
	cin >> input_file_name;
	cout << "Enter output file: ";
	cin >> output_file_name;

	ifstream fin(input_file_name, ios::in);
	ofstream fout(output_file_name, ios::out);

	int num_students;
	fin >> num_students;
	double num_class_days;
	fin >> num_class_days;

	cout << num_students;

	if (!fout.fail()) {
		fout << "----------------------------------------------\n";
		fout << "               CLASS GRADES REPORT            \n";
		fout << "----------------------------------------------\n";
		fout << "      STUDENT       EXAM  PROJ  ATTN  OVERALL \n";
		fout << "------------------- ----- ----- ----- ------- \n";
		int i = 0;
		while (i < num_students) {
			string first_name;
			string last_name;
			string formatted_name;
			double exam1;
			double exam2;
			double proj1;
			double proj2;
			double proj3;
			double absent_days;

			fin >> first_name;
			fin >> last_name;
			fin >> exam1;
			fin >> exam2;
			fin >> proj1;
			fin >> proj2;
			fin >> proj3;
			fin >> absent_days;

			formatted_name = last_name + ", " + first_name;
			double exam_avg = (exam1 + exam2) / NUM_EXAMS;
			double proj_avg = (proj1 + proj2 + proj3) / NUM_PROJS;
			double attendance_avg = ((num_class_days - absent_days) / num_class_days) * 100;
			double weighted_avg = (exam_avg * EXAM_WEIGHT) + (proj_avg * PROJ_WEIGHT) + (attendance_avg * ATTENDANCE_WEIGHT);


			fout << left << setw(20) << formatted_name;
			fout << setprecision(1) << std::fixed << setw(5) << exam_avg << " ";
			fout << setprecision(1) << std::fixed << setw(5) << proj_avg << " ";
			fout << setprecision(1) << std::fixed << setw(5) << attendance_avg << " ";
			fout << setprecision(1) << std::fixed << setw(5) << weighted_avg << "\n";
			i++;
		}
	}
	else cout << "Unable to open file";


	fin.close();
	fout.close();
	std::system("pause");
	return 0;
}
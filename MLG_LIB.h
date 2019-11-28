#ifndef _MLG_LIB_H_
#define _MLG_LIB_H_

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "string"

using namespace std;

ifstream file_r;
ofstream file_w;

string f_name = "buff.txt";

int file_empty() {
	int empty = 0;
	string tmp;
	
	file_r.open(f_name);
	file_r >> tmp;
	file_r.close();

	if (tmp == "")
		empty = 1;
	else
		empty = 0;

	return empty;
}

void create_file() {
	file_w.open(f_name);
	file_w.close();
}

void read_file() {
	string out;
	file_r.open(f_name);
	file_r >> out;
	file_r.close();
	cout << out << endl;

	create_file();
}

void write_file(int numb) {	
	file_w.open(f_name);
	file_w << numb;
	file_w.close();	
}

void waiting(int numb) {
	srand(time(NULL));
	while (file_empty() == numb) {
		Sleep(rand()%150);
	}
}
#endif;
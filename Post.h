#pragma once
#include <string>
#include <iostream>

using namespace std;


typedef struct{
	int day;
	int month;
	int year;
	void print() { cout << '\t' <<  day  << '/' << month << '/' << year; }
	void set(int d, int m, int y) { day = d; month = m; year = y;}
}Date;

class Post {
private:
	string phrases[10] = {
		" Such a nice day!",
		" Having issues with the project.",
		" When is the next class?",
		" First.",
		" Could we submit post-due?",
		" Class will not happen today.",
		" There is no room in the bus. Any other ways of transportation?",
		" Wich students will the n+2 apply to?",
		" Which is better, java or c++?",
		" Hello everyone."
	};
	int id;
	string title;
	string creator;
	string text;
	Date date;
	Date generateDate();

public:
	Post();
	Post(int id, string title, string creator);
	~Post();

	string getTitle();
	string getCreator();
	void print();
	void printTitle();
};

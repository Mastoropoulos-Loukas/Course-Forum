#include<iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Post.h"

using namespace std;

string Post::getCreator(){
	return this->creator;
}

string Post::getTitle() {
	return title;
}

//generates random date
Date Post::generateDate() {
	Date d;
	int day, month, year;

	month = rand() % 12 + 1;

	//get a possible day for the chosen month
	if (month == 2)day = rand() % 28 + 1;
	else if (month == 4 || month == 6 || month == 9 || month == 11)day = rand() % 30 + 1;
	else day = rand() % 31 + 1;

	//get a year in the past decade
	year = rand() % 10 + 2010;

	d.set(day, month, year);
	return d;
}

//prints the title of the post
void Post::printTitle() {
	cout << "-" << title << endl;
}

//prints the post
void Post::print() {
	cout << "#" << id << ":\"" << title << "\", by " << creator;
	date.print();
	cout << endl << text << endl;
}

Post::Post() {
	id = 0;
	this->print();
}

Post::Post(int id, string title, string creator) {
	this->id = id;
	this->title = title;
	this->creator = creator;
	this->date = generateDate();
	
	//Building text randomly
	///////////////////////////////////////
	

	int choise, selection;

	selection = rand() % 10; //Select randomly one of the 10 phrases
	
	text += this->phrases[selection];

	choise = rand() % 2;
	while (choise == 1) {
		selection = rand() % 10;
		text += this->phrases[selection];
		choise = rand() % 2;
	}
	cout << '\n';
	///////////////////////////////////////


	this->print();
}

Post::~Post() {
	cout << "Post number: "<< id << " is about to be destroyed" << endl;
}
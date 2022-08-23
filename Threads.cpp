#include<iostream>
#include <string>
#include <stdlib.h>
#include "Post.h"
#include "Threads.h"

using namespace std;

//generates random date
Date Thread::generateDate() {
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

string Thread::getSubject() { return subject; }

//returns the size of the postList
int Thread::postN() {
	return postList->size();
}

Post Thread::getPost(int pos) {
	return postList->getPost(pos);
}

//print the subject of the thread
void Thread::printSubject() {
	cout << "\"" << subject << "\":" << endl << endl;
}

//print random post from the thread
void Thread::printRandomly() {
	postList->printRandomly();
	cout << endl << endl << endl;
}

//searches the thread for a post with title <str>
void Thread::search(string str) {
	postList->search(str); 
}

//Prints the title of this thread
void Thread::printTitle2(){
	cout << "-\"" << subject << "\", by " << creator;
	date.print();
}

//Prints the titles of the post in the thread
void Thread::printTitle() {
	postList->printTitles();
}

//prints the information of this thread
void Thread::print() {
	this->printTitle2();
	cout << ':' << endl << endl;
	this->showList();
}

//add a post element in the back of postList
void Thread::pushBack(Post p) {
	postList->add(p);
}

//print all post in the thread
void Thread::showList() {
	postList->print();
}

Thread::Thread() {
	postList = new PostList();
	cout << "Thread with subject : " << subject << " has just been created!" << endl;
}

Thread::Thread(string subject, string creator) {
	this->subject = subject;
	this->creator = creator;
	this->date = generateDate();
	this->postList = new PostList();
	cout << "Thread with subject : " << subject << " has just been created!" << endl;
}

Thread::~Thread() {
	cout << "Thread with subject: " << subject << " is about to be destroyed" << endl;
}
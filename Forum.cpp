#include<iostream>
#include <string>
#include "Forum.h"
#include "ThreadList.h"
#include "BTree.h"

using namespace std;

//prints all posts of the forum in alphabetical order
void Forum::print_sorted() {
	int size = threadList->size();
	if (size == 0) {
		cout << "No threads in the forum" << endl;
		return;
	}
	
	btree* base = new btree(threadList->getThread(1));
	for (int i = 2; i <= size; i++) {
		btree* temp = new btree(threadList->getThread(i));
		base->expand(temp);
	}
	base->print();
	delete base;
}

//prints random posts from random thread elements in threadList
void Forum::printRandomly() {
	threadList->printRandomly();
}

//searches the forum for a thread with subject <str>
void Forum::searchThread(string str) {threadList->search(str);}

//searches the forum for a post with title <str>
void Forum::searchPost(string str) { threadList->searchPost(str); }

//print the forum
void Forum::print() {
	threadList->printTitles();
}

//adding <t> element in the back of the threadList
void Forum::pushBack(Thread t) {
	threadList->add(t);
}

Forum::Forum() {
	threadList = new ThreadList();
	cout << "Forum with title: \"" << title << "\" has just been created!" << endl;
}

Forum::Forum(string title) {
	this->title = title;
	threadList = new ThreadList();
	cout << "Forum with title: \"" << title << "\" has just been created!" << endl;
}

Forum::~Forum() {
	cout << "Forum with title: \"" << title << "\" is about to be destroyed" << endl;
}
#include "ThreadList.h"
#include <iostream>
#include <cstdlib>

using namespace std;

ThreadList::ThreadList() {
	this->length = 0;
	this->head = NULL;
}

ThreadList::~ThreadList() {}

int ThreadList::size() { return length; }

//searches the list for a thread element with su bject <str>
void ThreadList::search(string str) {
	threadNode* head = this->head;
	for (int i = 1; i <= length; i++) {
		if (head->thread.getSubject().compare(str) == 0) {
			head->thread.print();
			return;
		}
		head = head->next;
	}
}

//searches each thread element for a post with title <str>
void ThreadList::searchPost(string str) {
	threadNode* head = this->head;
	for (int i = 1; i <= length; i++) {
		head->thread.search(str);
		head = head->next;
	}
}


//returns the address of the element in position <pos>
Thread* ThreadList::getThread(int pos) {
	if (pos > length) {
		cout << "List not big enough" << endl;
		return &head->thread;
	}

	int i;
	threadNode* head = this->head;

	for (i = 1; i < pos; i++)head = head->next;
	return &head->thread;
}

//add a Thread element at the end of the list
void ThreadList::add(Thread thread) {
	threadNode* node = new threadNode();
	node->thread = thread;

	if (length != 0) {
		threadNode* h = this->head;
		while (h->next != NULL)h = h->next;
		h->next = node;
	}
	else this->head = node;


	this->length++;
}

//prints random elements of this list
void ThreadList::printRandomly() {
	threadNode* head = this->head;
	while (head) {
		head->thread.printSubject();
		head->thread.printRandomly();
		head = head->next;
	}
}

//prints the titles of the thread elements of this list. Used in void Forum::print()
void ThreadList::printTitles() {
	threadNode* head = this->head;
	while (head) {
		head->thread.printTitle2();
		cout << endl; 
		head = head->next;
	}
}

//prints the information for the elements of this list
void ThreadList::print() {
	threadNode* head = this->head;
	while (head) {
		head->thread.print();
		head = head->next;
	}
	cout << endl << endl;
}
#pragma once
#include "Threads.h"

class threadNode {
public:
	threadNode* next;
	Thread thread;
};

using namespace std;

class ThreadList {
private:
	int length;
	threadNode* head;

public:
	ThreadList();
	~ThreadList();
	
	int size();
	Thread* getThread(int pos);
	void search(string str);
	void searchPost(string str);
	void printRandomly();
	void printTitles();
	void add(Thread post);
	void print();
};
#pragma once
#include<iostream>
#include <string>
#include  "ThreadList.h"
#include "Post.h"
#include "Threads.h"

using namespace std;

class Forum {
private:
	string title;
	ThreadList* threadList; //A list that contains all threads of the forum
public:
	Forum();
	Forum(string title);
	~Forum();

	void print_sorted();
	void printRandomly();
	void searchThread(string str);
	void searchPost(string str);
	void print();
	void pushBack(Thread t);

};


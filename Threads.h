#pragma once
#include <iostream>
#include "PostList.h"
#include "Post.h"
#include "Threads.h"

using namespace std;

class Thread {
private:
	string subject;
	string creator;
	Date date;
	PostList* postList; //A list that contains all posts of this thread

	Date generateDate();

public:
	Thread();
	Thread(string subject, string creator);
	~Thread();
	
	string getSubject();
	void search(string str);
	int postN();
	Post getPost(int pos);
	void printRandomly();
	void printSubject();
	void print();
	void printTitle2();
	void printTitle();
	void pushBack(Post p);
	void showList();


};
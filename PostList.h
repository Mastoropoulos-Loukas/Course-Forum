#pragma once
#include "Post.h"

class postNode {
public:
	postNode* next;
	Post post;
};

using namespace std;

class PostList {
private:
	int length;
	postNode* head;
public:
	PostList();
	~PostList();

	int lastseen;
	int size();
	Post extractPost();
	Post getPost(int pos);
	void add(Post post);
	void search(string str);
	void printRandomly();
	void printTitles();
	void print();
};
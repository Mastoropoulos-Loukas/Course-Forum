#pragma once
#include <iostream>
#include <string>
#include "PostList.h"
#include "Post.h"
#include "Threads.h"

using namespace std;

class node {
public:
	string creator_val;
	PostList* postList;
	node* left;
	node* right;

	node();
	~node();

	bool fullyRead();
	Post extractPost();
	void add(Post post);
	void setCreator(string creator);
	void print();
};

class btree {
	
private:
	void destroy_tree(node* leaf);
	void insert(Post post, node * leaf);
	void print(node* leaf);
	Post extract(node* leaf);

	node* root;
public:
	btree();
	btree(Thread* thread);
	~btree();

	node* getRoot();
	void expand(btree* second);
	void print();
	void insert(Post post);
	void destroy_tree();
};
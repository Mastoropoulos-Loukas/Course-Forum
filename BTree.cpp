#include <iostream>
#include "BTree.h"

using namespace std;

node::node() {
	postList = new PostList();
	left = NULL;
	right = NULL;
}

node::~node() {delete postList;}

void node::add(Post post) {postList->add(post);}

void node::setCreator(string creator) {this->creator_val = creator;}

//prints the contents of this node
void node::print() {
	cout << "From creator \" " << creator_val << "\" :" << endl;
	postList->print();
}

//returns the first unseen post of postList
Post node::extractPost() {
	return postList->extractPost();
}

//returns true if all post have been return by Post node::extractPost(), else false
bool node::fullyRead() {
	if (postList->lastseen < postList->size())return false;
	return true;
}

////////////////////////////////////////////////////////////////
btree::btree(Thread* thread) {
	root = NULL;
	int size = thread->postN();

	for (int i = 1; i <= size; i++) {
		insert(thread->getPost(i));
	}
}

btree::btree() {root = NULL;}

btree::~btree() {destroy_tree();}

//lets memory held for btree free
void btree::destroy_tree() { destroy_tree(root); }
void btree::destroy_tree(node* leaf) {
	if (leaf != NULL) {
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

node* btree::getRoot() { return root; }

//extracts one unseen post from this btree
Post btree::extract(node* leaf) {
	if (leaf->left != NULL && !leaf->left->fullyRead()) return extract(leaf->left);
	if (leaf->right != NULL && !leaf->right->fullyRead()) return extract(leaf->right);
	return leaf->extractPost();
}

//expands this btree with the contents of a <second> btree. <second> btree is destroyed in the end. 
void btree::expand(btree* second) {
	node* head = second->getRoot();
	while(head != NULL && !head->fullyRead())this->insert(extract(head));
	delete second;
}

//prints the contents of this btree (inorder traversal)
void btree::print() {
	if (root)print(root);
}
void btree::print(node* leaf) {
	if (leaf->left != NULL)print(leaf->left);
	leaf->print();
	if (leaf->right != NULL)print(leaf->right);
}

//insets a post in the PostList of the node <*leaf>
void btree::insert(Post post, node* leaf) {

	if (leaf->creator_val.compare(post.getCreator()) > 0)
	{
		if (leaf->left != NULL)insert(post, leaf->left);
		else
		{
			node* a = new node();
			a->add(post);
			a->setCreator(post.getCreator());
			leaf->left = a;
		}
	}
	else if (leaf->creator_val.compare(post.getCreator()) < 0)
	{
		if (leaf->right != NULL)insert(post, leaf->right);
		else
		{
			node* a = new node();
			a->add(post);
			a->setCreator(post.getCreator());
			leaf->right = a;
		}
	}
	else leaf->add(post);	
}
void btree::insert(Post post)
{
	if (root != NULL)
		insert(post, root);
	else
	{
		root = new node;
		root->setCreator(post.getCreator());
		root->add(post);
		root->left = NULL;
		root->right = NULL;
	}
}






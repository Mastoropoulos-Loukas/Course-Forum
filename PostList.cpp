#include "PostList.h"
#include <iostream>
#include <cstdlib>

using namespace std;

PostList::PostList() {
	this->length = 0;
	this->lastseen = 0;
	this->head = NULL;
}

PostList::~PostList() {}

//returns the size of the list
int PostList::size() { return length; }

//returns the first unseen post of the list
Post PostList::extractPost() {
	lastseen++;
	return getPost(lastseen);
}

//returns the post in position <pos> of the list
Post PostList::getPost(int pos) {
	if (pos > length) {
		cout << "List not big enough" << endl;
		return head->post;
	}
	
	int i;
	postNode* head = this->head;

	for (i = 1; i < pos; i++)head = head->next;
	return head->post;
}

//adds a post element at the end of the list
void PostList::add(Post post) {
	postNode* node = new postNode();
	node->post = post;

	if (length != 0) {
		postNode* h = this->head;
		while (h->next != NULL)h = h->next;
		h->next = node;
	}
	else this->head = node;


	this->length++;
}

//searches the list for a post element with title <str>
void PostList::search(string str) {
	postNode* head = this->head;

	while (head) {
		if (head->post.getTitle().compare(str) == 0)head->post.print();
		head = head->next;
	}
}

//prints random elements from the list
void PostList::printRandomly() {
	postNode* head = this->head;
	int choise = rand() % 2;

	while (head) {
		if (choise == 0)head->post.print();
		head = head->next;
		choise = rand() % 2;
	}
	cout << endl;
}

//prints the titles of the elements in this list
void PostList::printTitles() {
	postNode* head = this->head;
	while (head) {
		head->post.printTitle();
		head = head->next;
	}
	cout << endl << endl;
}

//prints the information for the elements of this list
void PostList::print() {
	postNode* head = this->head;
	int i = length;
	while (i > 0) {
		head->post.print();
		head = head->next;
		i--;
	}
	cout << endl << endl;
}
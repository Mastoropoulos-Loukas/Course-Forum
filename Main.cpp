#include<iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Post.h"
#include "Threads.h"
#include "Forum.h"
#include "PostList.h"
#include "ThreadList.h"
#include "BTree.h"


using namespace std;

int main() {
	srand((unsigned int)time(NULL));

	//Creating Forum
	///////////////////////////////////////////////////////////////////////
	Forum f("Antikeimenostrafis Programmatismos");

	Thread t1("Mathimatika", "Psouni");
	Thread t2("Kanones kai xrisimes plirofories", "DIT");
	Thread t3("Logismiko", "TheNewBoston");
	Thread t4("Diktiosi", "Telusko");

	Post p1(1, "Analysi", "Petros56");
	Post p2(2, "Grammiki Algebra", "Katia24");
	Post p3(3, "Grammiki Algebra", "Dimitris13");

	Post p4(4, "Eggrafi se mathima", "Petros56");
	Post p5(5, "Dilosi mathimaton", "Stela98");
	Post p6(6, "Orario grammatias", "Marios9");
	Post p7(7, "Aytaireti anartisi pano", "Katia24");
	Post p8(8, "Metagrafes", "Takis73");
	Post p9(9, "Eudoxos", "Marios9");

	Post p10(10, "C#", "Makis13");
	Post p11(11, "Python", "Petros56");
	Post p12(12, "Java", "Elli04");
	Post p13(13, "HTML5", "Marios9");
	Post p14(14, "Javascript", "Petros56");

	Post p15(15, "PTP", "Petros56");
	Post p16(16, "Simata kai Systimata", "Katia24");

	t1.pushBack(p1);
	t1.pushBack(p2);
	t1.pushBack(p3);

	t2.pushBack(p4);
	t2.pushBack(p5);
	t2.pushBack(p6);
	t2.pushBack(p7);
	t2.pushBack(p8);
	t2.pushBack(p9);

	t3.pushBack(p10);
	t3.pushBack(p11);
	t3.pushBack(p12);
	t3.pushBack(p13);
	t3.pushBack(p14);

	t4.pushBack(p15);
	t4.pushBack(p16);

	f.pushBack(t1);
	f.pushBack(t2);
	f.pushBack(t3);
	f.pushBack(t4);
	////////////////////////////////////////////////////////


	//Meros 2
	cout << "//////////////////////////////////////////////////" << endl
		<< "ektypose to forum me ti xrisi tis print_sorted(): " << endl << endl;
	f.print_sorted();

	return 0;
}
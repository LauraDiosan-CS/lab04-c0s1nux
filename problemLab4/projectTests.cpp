#include <iostream>
#include "projectObjectHeader.h"
#include <assert.h>


using namespace std;

void creationProjectTest() {
	cout << "-------------------------------------------------------------\n";
	cout << "Beginning tests for creation of projects...\n";
	Project p1("xd", 1, 2);
	Project p100;
	char* b = new char[10];
	strcpy_s(b, sizeof "xd", "xd");
	assert(strcmp(p1.getPath(), b) == 0);
	assert(p1.getBranches() == 1);
	assert(p1.getCommits() == 2);
	delete[]b;
	b = NULL;
	p100 = p1;
	assert(p100 == p1);
	cout << "Success!\n";
	cout << "-------------------------------------------------------------\n";
}
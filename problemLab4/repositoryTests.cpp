#include "repositoryTests.h"
#include "projectObjectHeader.h"
#include <assert.h>
#include "repositoryArray.h"
#include <string.h>
#include <iostream>

using namespace std;

void testRepository() {
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
	p100 = p1;
	assert(p100 == p1);
	Project p2("xdd", 3, 4);
	Project p3("TEST!", 10, 10);
	cout << "Success!\n";
	RepositoryArray repo;
	cout << "-------------------------------------------------------------\n";
	cout << "Beginning tests for adding projects to the repository...\n";
	repo.addElem(p1);
	repo.addElem(p2);
	assert(repo.dim() == 2);
	assert(repo.getItemFromPos(0) == p1);
	assert(repo.getItemFromPos(1) == p2);
	cout << "Success!\n";
	cout << "-------------------------------------------------------------\n";
	cout << "Beginning tests for removing projects from the repository...\n";
	repo.delElem(p2);
	assert(repo.dim() == 1);
	cout << "Success!\n";
	cout << "-------------------------------------------------------------\n";
	cout << "Beginning tests for updating projects from the repository...\n";
	char* a = new char[10];
	strcpy_s(a, 10, "TEST!");
	repo.updateElem(p1, a, 10, 10);
	assert(repo.getItemFromPos(0) == p3);
	delete[]a;
	cout << "Success!\n";
	cout << "-------------------------------------------------------------\n";
	cout << "Tests finished successfully!\n";
	cout << "-------------------------------------------------------------\n";
}
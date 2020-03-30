#include <iostream>
#include "service.h"
#include "serviceTests.h"
#include <assert.h>
using namespace std;

void serviceTests() {
	cout << "-------------------------------------------------------------\n";
	cout << "Beginning tests for adding projects through the service...\n";
	Service serv;
	char* b = new char[10];
	strcpy_s(b, sizeof "xd", "xd");
	serv.addProject(b, 3, 4);
	assert(serv.sizeOfList() == 5);
	cout << "Success!\n";
	cout << "-------------------------------------------------------------\n";
	cout << "Beginning tests for updating projects through the service...\n";
	Project* listOfProjects = serv.getAllProjects();
	char* a = new char[10];
	strcpy_s(a, sizeof "xDD", "xDD");
	serv.updateProject(b, 3, 4, a, 4, 5);
	listOfProjects = serv.getAllProjects();
	assert(strcmp(listOfProjects[4].getPath(), "xDD") == 0);
	assert(listOfProjects[4].getBranches() == 4);
	assert(listOfProjects[4].getCommits() == 5);
	delete[] b;
	b = NULL;
	cout << "Success!\n";
	cout << "-------------------------------------------------------------\n";
	cout << "Beginning tests for removing projects through the service...\n";
	listOfProjects = serv.getAllProjects();
	serv.removeProject(a, 4, 5);
	assert(serv.sizeOfList() == 4);
	delete[] a;
	a = NULL;
	cout << "Success!\n";
	cout << "-------------------------------------------------------------\n";
	cout << "Beginning tests for property 1...\n";
	char* c = new char[10];
	strcpy_s(c, sizeof "xd", "xd");
	char* d = new char[10];
	strcpy_s(d, sizeof "xdlol", "xdlol");
	char* e = new char[10];
	strcpy_s(e, sizeof "yeet", "yeet");
	serv.addProject(c, 3, 4);
	serv.addProject(d, 0, 1);
	serv.addProject(e, 1, 0);
	serv.filterProjectsWithZeroBranchesOrCommits();
	assert(serv.sizeOfList() == 6);
	cout << "Success!\n";
	cout << "-------------------------------------------------------------\n";
	cout << "Beginning tests for property 2...\n";
	int m = 0;
	Project listOfGoodProjects[100];
	serv.findAllProjectsWithAtLeastKBranchesAndLCommits(3, 4, listOfGoodProjects, m);
	assert(m == 3);
	listOfProjects = serv.getAllProjects();
	assert(listOfGoodProjects[2] == listOfProjects[4]);
	cout << "Success!\n";
	cout << "-------------------------------------------------------------\n";
	cout << "All services tests are met!\n";
	cout << "-------------------------------------------------------------\n";
}
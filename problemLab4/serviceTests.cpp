#include <iostream>
#include "service.h"
#include "serviceTests.h"
#include <assert.h>
using namespace std;

void serviceTests() {
	cout << "-------------------------------------------------------------\n";
	cout << "Beginning tests for adding projects through the service...\n";
	RepositoryArray aRepo;
	Service service;
	service.addProject(aRepo, "xd", 3, 4);
	assert(service.sizeOfList(aRepo) == 1);
	cout << "Success!\n";
	cout << "-------------------------------------------------------------\n";
	cout << "Beginning tests for updating projects through the service...\n";
	Project* listOfProjects = service.getAllProjects(aRepo);
	service.updateProject(aRepo, listOfProjects[0], "xDD", 4, 5);
	listOfProjects = service.getAllProjects(aRepo);
	assert(strcmp(listOfProjects[0].getPath(), "xDD") == 0);
	assert(listOfProjects[0].getBranches() == 4);
	assert(listOfProjects[0].getCommits() == 5);
	cout << "Success!\n";
	cout << "-------------------------------------------------------------\n";
	cout << "Beginning tests for removing projects through the service...\n";
	listOfProjects = service.getAllProjects(aRepo);
	service.removeProject(aRepo, listOfProjects[0]);
	assert(service.sizeOfList(aRepo) == 0);
	cout << "Success!\n";
	cout << "-------------------------------------------------------------\n";
	cout << "Beginning tests for property 1...\n";
	service.addProject(aRepo, "xd", 3, 4);
	service.addProject(aRepo, "xdlol", 0, 1);
	service.addProject(aRepo, "yeet", 1, 0);
	service.filterProjectsWithZeroBranchesOrCommits(aRepo);
	assert(service.sizeOfList(aRepo) == 1);
	cout << "Success!\n";
	cout << "-------------------------------------------------------------\n";
	cout << "Beginning tests for property 2...\n";
	int m = 0;
	Project listOfGoodProjects[100];
	service.findAllProjectsWithAtLeastKBranchesAndLCommits(aRepo, 3, 4, listOfGoodProjects, m);
	assert(m == 1);
	listOfProjects = service.getAllProjects(aRepo);
	assert(listOfGoodProjects[0] == listOfProjects[0]);
	cout << "Success!\n";
	cout << "-------------------------------------------------------------\n";
	cout << "All services tests are met!\n";
	cout << "-------------------------------------------------------------\n";
}
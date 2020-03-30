#pragma once
#include "repositoryArray.h"

class Service {
private:
	RepositoryArray repository;
public:
	Service();
	void addProject(char*, int, int);
	void removeProject(char*, int, int);
	void updateProject(char*, int, int, char*, int, int);
	Project* getAllProjects();
	int sizeOfList();
	void filterProjectsWithZeroBranchesOrCommits();
	void findAllProjectsWithAtLeastKBranchesAndLCommits(int, int, Project[], int&);
	~Service();
};
#pragma once
#include "repositoryArray.h"

class Service {
public:
	void addProject(RepositoryArray&, const char*, int, int);
	void removeProject(RepositoryArray&, Project);
	void updateProject(RepositoryArray&, Project, const char*, int, int);
	Project* getAllProjects(RepositoryArray&);
	int sizeOfList(RepositoryArray&);
	void filterProjectsWithZeroBranchesOrCommits(RepositoryArray&);
	void findAllProjectsWithAtLeastKBranchesAndLCommits(RepositoryArray&, int, int, Project[], int&);
};
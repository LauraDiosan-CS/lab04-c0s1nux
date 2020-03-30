#pragma once
#include "service.h"

class Console {
private:
	Service service;
public:
	Console();
	void showMenu();
	void addProjectConsole();
	void removeProjectConsole();
	void updateProjectConsole();
	void showAllProjects();
	void showProjectsThatHaveAGivenAmountOfBranchesAndCommits();
	void removeAllProjectsThatHaveZeroBranchesOrCommits();
	void runApplication();
	~Console();
};
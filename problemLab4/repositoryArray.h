#pragma once

#include "projectObjectHeader.h"

class RepositoryArray {
private:
	Project elem[100];
	int size;
public:
	RepositoryArray();
	void addElem(Project);
	int findElem(Project);
	Project getItemFromPos(int);
	void delElem(Project);
	void updateElem(Project, char*, int, int);
	Project* getAll();
	int dim();
	~RepositoryArray();
};
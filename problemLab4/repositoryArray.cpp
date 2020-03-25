#include "repositoryArray.h"

RepositoryArray::RepositoryArray() { size = 0; }

void RepositoryArray::addElem(Project p) {
	elem[size++] = p;
}

int RepositoryArray::findElem(Project p) {
	int i = 0;

	while (i < size) {
		if (elem[i] == p) return i;
		i++;
	}
	return -1;
}

void RepositoryArray::delElem(Project p) {
	int i = findElem(p);
	if (i != -1)
		elem[i] = elem[size - 1];
	size--;
}

void RepositoryArray::updateElem(Project p, const char* newPath, int newBranches, int newCommits) {
	int i = findElem(p);
	elem[i].setPath(newPath);
	elem[i].setBranches(newBranches);
	elem[i].setCommits(newCommits);

}

Project* RepositoryArray::getAll() {
	return elem;
}
int RepositoryArray::dim() {
	return size;
}
RepositoryArray::~RepositoryArray() {
}

Project RepositoryArray::getItemFromPos(int i) {
	return elem[i];
}

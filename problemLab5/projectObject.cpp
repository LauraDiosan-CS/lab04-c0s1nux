#include "projectObjectHeader.h"
#include <string.h>

Project::Project() {
	path = NULL;
	branches = 0;
	commits = 0;
}

Project::Project(const char* path, int branches, int commits) {
	this->path = new char[strlen(path) + 1];
	strcpy_s(this->path, strlen(path) + 1, path);
	this->branches = branches;
	this->commits = commits;
}

Project::Project(const Project& p) {
	this->path = new char[strlen(p.path) + 1];
	strcpy_s(this->path, strlen(p.path) + 1, p.path);
	this->branches = p.branches;
	this->commits = p.commits;
}

char* Project::getPath() {
	return path;
}

int Project::getBranches() {
	return branches;
}

int Project::getCommits() {
	return commits;
}

void Project::setPath(char* n) {
	if (path) delete[]path;
	path = new char[strlen(n) + 1];
	strcpy_s(path, strlen(n) + 1, n);
}

void Project::setBranches(int newBranches) {
	branches = newBranches;
}

void Project::setCommits(int newCommits) {
	commits = newCommits;
}

Project::~Project() {
	if (path) delete[]path;
	path = NULL;
	branches = -1;
	commits = -1;
}

Project& Project::operator=(const Project& p) {
	if (this == &p) return *this;
	if (path) delete[] path;
	path = new char[strlen(p.path) + 1];
	strcpy_s(path, strlen(p.path) + 1, p.path);
	branches = p.branches;
	commits = p.commits;
	return *this;
}

bool Project::operator==(const Project& p) {
	return (strcmp(path, p.path) == 0) and (branches == p.branches) and (commits = p.commits);
}
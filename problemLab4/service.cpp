#include "Service.h"

Service::Service() {
	Project projectOne("yo", 1, 2), projectTwo("yo dude", 2, 3), projectThree("sup", 3, 4), projectFour("no u", 4, 5);
	repository.addElem(projectOne);
	repository.addElem(projectTwo);
	repository.addElem(projectThree);
	repository.addElem(projectFour);
}

void Service::addProject(char* path, int branches, int commits) {
	Project newProject(path, branches, commits);
	repository.addElem(newProject);
}

void Service::removeProject(char* path, int branches, int commits) {
	Project projectWeAreRemoving(path, branches, commits);
	repository.delElem(projectWeAreRemoving);
}

void Service::updateProject(char* pathWeAreUpdating, int branchesWeAreUpdating, int commitsWeAreUpdating, char* newPath, int newBranches, int newCommits) {
	Project projectWeAreUpdating(pathWeAreUpdating, branchesWeAreUpdating, commitsWeAreUpdating);
	repository.updateElem(projectWeAreUpdating, newPath, newBranches, newCommits);
}

Project* Service::getAllProjects() {
	return repository.getAll();
}

void Service::filterProjectsWithZeroBranchesOrCommits() {
	for (int i = 0; i < repository.dim(); i++)
	{
		Project currentProject = repository.getItemFromPos(i);
		if (currentProject.getBranches() == 0 || currentProject.getCommits() == 0)
			repository.delElem(currentProject);
	}
}

int Service::sizeOfList() {
	return repository.dim();
}

void Service::findAllProjectsWithAtLeastKBranchesAndLCommits(int k, int l, Project goodList[], int &m) {
	for (int i = 0; i < repository.dim(); i++)
	{
		Project currentProject = repository.getItemFromPos(i);
		if (currentProject.getBranches() >= k && currentProject.getCommits() >= l)
			goodList[m++] = currentProject;
	}
}

Service::~Service() {
}
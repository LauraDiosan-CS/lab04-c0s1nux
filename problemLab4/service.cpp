#include "Service.h"

void Service::addProject(RepositoryArray& repo, const char* path, int branches, int commits) {
	Project newProject(path, branches, commits);
	repo.addElem(newProject);
}

void Service::removeProject(RepositoryArray& repo, Project projectWeAreRemoving) {
	repo.delElem(projectWeAreRemoving);
}

void Service::updateProject(RepositoryArray& repo, Project projectWeAreUpdating, const char* newPath, int newBranches, int newCommits) {
	repo.findElem(projectWeAreUpdating);
	repo.updateElem(projectWeAreUpdating, newPath, newBranches, newCommits);
}

Project* Service::getAllProjects(RepositoryArray& repo) {
	return repo.getAll();
}

void Service::filterProjectsWithZeroBranchesOrCommits(RepositoryArray& repo) {
	for (int i = 0; i <= repo.dim(); i++)
	{
		Project currentProject = repo.getItemFromPos(i);
		if (currentProject.getBranches() == 0 || currentProject.getCommits() == 0)
			repo.delElem(currentProject);
	}
}

int Service::sizeOfList(RepositoryArray& repo) {
	return repo.dim();
}

void Service::findAllProjectsWithAtLeastKBranchesAndLCommits(RepositoryArray& repo, int k, int l, Project goodList[], int &m) {
	for (int i = 0; i <= repo.dim(); i++)
	{
		Project currentProject = repo.getItemFromPos(i);
		if (currentProject.getBranches() >= k && currentProject.getCommits() >= l)
			goodList[m++] = currentProject;
	}
}
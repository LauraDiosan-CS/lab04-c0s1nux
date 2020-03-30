#include <iostream>
#include "console.h"
#include "windows.h" 

using namespace std;

Console::Console() {
}

void Console::showMenu() {
	cout << "-------------------------------------------------------------\n";
	cout << "1. Add project.\n";
	cout << "2. Remove project.\n";
	cout << "3. Update project.\n";
	cout << "4. Show all projects.\n";
	cout << "5. Show all projects that have a given amount of branches and commits.\n";
	cout << "6. Eliminate all projects that have 0 branches or 0 commits.\n";
	cout << "7. Exit.\n";

}

void Console::addProjectConsole() {
	int branches, commits;
	char* path = new char[20];
	cout << "-------------------------------------------------------------\n";
	cout << "Dati path-ul proiectului: ";
	cin >> path;
	cout << "Dati numarul de branches al proiectului: ";
	cin >> branches;
	cout << "Dati numarul de commits al proiectului: ";
	cin >> commits;
	service.addProject(path, branches, commits);
	delete[]path;
	cout << "-------------------------------------------------------------\n";
	cout << "Ai adaugat cu succes proiectul!\n";
	cout << "-------------------------------------------------------------\n";
	Sleep(3000);
	system("CLS");
}

void Console::removeProjectConsole() {
	int branches, commits;
	char* path = new char[20];
	cout << "-------------------------------------------------------------\n";
	cout << "Dati path-ul proiectului pe care vreti sa il stergeti: ";
	cin >> path;
	cout << "Dati numarul de branches al proiectului pe care vreti sa il stergeti: ";
	cin >> branches;
	cout << "Dati numarul de commits al proiectului pe care vreti sa il stergeti: ";
	cin >> commits;
	service.removeProject(path, branches, commits);
	delete[]path;
	cout << "-------------------------------------------------------------\n";
	cout << "Ai sters cu succes proiectul!\n";
	cout << "-------------------------------------------------------------\n";
	Sleep(3000);
	system("CLS");
}

void Console::updateProjectConsole() {
	int branches, commits;
	char* path = new char[20];
	cout << "-------------------------------------------------------------\n";
	cout << "Dati path-ul proiectului pe care vreti sa il updatati: ";
	cin >> path;
	cout << "Dati numarul de branches al proiectului pe care vreti sa il updatati: ";
	cin >> branches;
	cout << "Dati numarul de commits al proiectului pe care vreti sa il updatati: ";
	cin >> commits;
	int newBranches, newCommits;
	char* newPath = new char[20];
	cout << "Dati noul path al proiectului: ";
	cin >> newPath;
	cout << "Dati noul numar de branches al proiectului: ";
	cin >> newBranches;
	cout << "Dati noul numar de commits al proiectului: ";
	cin >> newCommits;
	service.updateProject(path, branches, commits, newPath, newBranches, newCommits);
	delete[]path;
	delete[]newPath;
	cout << "-------------------------------------------------------------\n";
	cout << "Proiectul a fost updatat cu succes!\n";
	cout << "-------------------------------------------------------------\n";
	Sleep(3000);
	system("CLS");
}

void Console::showAllProjects() {
	Project* listOfProjects = service.getAllProjects();
	int size = service.sizeOfList();
	cout << "-------------------------------------------------------------\n";
	for (int i = 0; i < size; i++)
	{
		cout << "| Path: " << listOfProjects[i].getPath()
			<< " | Branches: " << listOfProjects[i].getBranches()
			<< " | Commits: " << listOfProjects[i].getCommits() << " |\n";
	}
	cout << "-------------------------------------------------------------\n";
	Sleep(6000);
	system("CLS");
}

void Console::showProjectsThatHaveAGivenAmountOfBranchesAndCommits() {
	int branches, commits, n=0;
	cout << "-------------------------------------------------------------\n";
	cout << "Dati numarul minim de branches pe care proiectele sa il aiba: ";
	cin >> branches;
	cout << "Dati numarul minim de commits pe care proiectele sa il aiba: ";
	cin >> commits;
	Project listOfProjects[100];
	service.findAllProjectsWithAtLeastKBranchesAndLCommits(branches, commits, listOfProjects, n);
	cout << "-------------------------------------------------------------\n";
	for (int i = 0; i < n; i++)
	{
		cout << "| Path: " << listOfProjects[i].getPath()
			<< " | Branches: " << listOfProjects[i].getBranches()
			<< " | Commits: " << listOfProjects[i].getCommits() << " |\n";
	}
	cout << "-------------------------------------------------------------\n";
	Sleep(6000);
	system("CLS");
}

void Console::removeAllProjectsThatHaveZeroBranchesOrCommits() {
	service.filterProjectsWithZeroBranchesOrCommits();
	cout << "-------------------------------------------------------------\n";
	cout << "Toate proiectele cu 0 branches sau commits au fost sterse!\n";
	cout << "-------------------------------------------------------------\n";
	Sleep(3000);
	system("CLS");
}

void Console::runApplication() {
	int option;
	bool isRunning = true;
	while (isRunning)
	{
		showMenu();
		cout << "-------------------------------------------------------------\n";
		cout << "Optiunea pe care o aleg este: ";
		cin >> option;
		while (option > 7 || option < 1)
		{
			cout << "-------------------------------------------------------------\n";
			cout << "Alegeti o optiune valida!\n";
			cout << "Optiunea pe care o aleg este: ";
			cin >> option;
			cout << "-------------------------------------------------------------\n";
		}
		if (option == 1)
			addProjectConsole();
		else
			if (option == 2)
				removeProjectConsole();
			else
				if (option == 3)
					updateProjectConsole();
				else
					if (option == 4)
						showAllProjects();
					else
						if (option == 5)
							showProjectsThatHaveAGivenAmountOfBranchesAndCommits();
						else
							if (option == 6)
								removeAllProjectsThatHaveZeroBranchesOrCommits();
							else
								if (option == 7)
									break;


	}

}

Console::~Console() {
}
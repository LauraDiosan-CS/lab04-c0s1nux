#include <iostream>
#include "console.h"

using namespace std;

void showMenu() {
	cout << "-------------------------------------------------------------\n";
	cout << "1. Add project.";
	cout << "2. Remove project.";
	cout << "3. Update project.";
	cout << "4. Show all projects.";
	cout << "5. Show all projects that have a given amount of branches and commits.";
	cout << "6. Eliminate all projects that have 0 branches or 0 commits.";
	cout << "7. Exit.";
}


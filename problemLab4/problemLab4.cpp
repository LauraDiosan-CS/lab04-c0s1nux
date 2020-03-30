#include <iostream>
#include "repositoryTests.h"
#include "serviceTests.h"
#include "windows.h" 
#include "console.h"
#include "projectTestsHeader.h"

using namespace std;

int main()
{
    cout << "Testing the app!\n";
    Sleep(4000);
    system("CLS");
    creationProjectTest();
    Sleep(4000);
    system("CLS");
    testRepository();
    Sleep(4000);
    system("CLS");
    serviceTests();
    Sleep(4000);
    system("CLS");
    cout << "All tests passed! Running the app!\n";
    cout << "Clearing the screen...\n";
    Sleep(5000);
    system("CLS");
    Console console;
    console.runApplication();
    return 0;
}
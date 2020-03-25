#include <iostream>
#include "repositoryTests.h"
#include "serviceTests.h"
using namespace std;

int main()
{
    cout << "-------------------------------------------------------------\n";
    cout << "Starting the app!\n";
    testRepository();
    serviceTests();
    cout << "App is still WIP! ( Only Live requirements are met! )\n";
    cout << "-------------------------------------------------------------\n";
    return 0;
}
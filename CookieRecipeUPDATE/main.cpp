#include <iostream>
#include <string>
#include <set>
#include <vector>

#include "ListData.cpp"
#include "Interface.cpp"

using namespace std;

int main()
{
    CookieList cList;
    createCookieList(cList);
    // cList.clearList();  // delete after testing if list is empty
    displayMenu();
    processChoice(cList);

        cout << endl;
        return 0;
}
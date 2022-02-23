#ifndef INTERFACE_H
#define INTERFACE_H

#include "CookieList.h"

int validateSelection(CookieList& cookieList);
char validateYNInput();
void displayMenu();
void processChoice(CookieList& cookieList);

#endif


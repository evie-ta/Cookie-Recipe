#include "CookieList.h"
#include "Cookie.cpp"

#include <algorithm>
#include <iostream>

using namespace std;

CookieList::CookieList()
{
    cookieList = new list<Cookie>;
}

void CookieList::addCookie(const Cookie& aCookie)
{
    cookieList->push_back(aCookie);
}

void CookieList::addCookie(const string& newName, size_t newCalories,
	const set<string>& newIngredients, size_t newServings, const string& newInstructions)
{
    // FIXED
    Cookie aCookie(newName, newCalories, newIngredients,
                    newServings, newInstructions);

    cookieList->push_back(aCookie);
}

size_t CookieList::getCount() const
{
    return cookieList->size();
}

bool CookieList::isEmpty() const
{
    return cookieList->empty();
}

void CookieList::printAllCookies() const
{
    // for choice 'a'
    for (const auto& cookies : *cookieList)
        cout << "    " << cookies.getName() << endl;

    cout << endl;
}

void CookieList::printCookiesSelection() const
{
    // for choice 'b'
    int i = 1;
    for (const auto& cookies : *cookieList)
    {
         cout << "    " << i << ": " << cookies.getName() << endl;
         ++i;
    }
    cout << endl;
}

void CookieList::printRecipe(size_t selection)
{
    // for choice 'b' but with specific cookie
    auto iter = cookieList->begin();
    size_t i = 1;
    while (i < selection)
    {
      ++iter;
      ++i;
    }
    iter->printRecipe();
    cout << "        Calories: " << iter->getCalories() << endl;
    iter->printIngredients();
    iter->printInstructions();
}

void CookieList::printCalories(size_t selection)
{
    auto iter = cookieList->begin();
    size_t i = 1;
    while (i < selection)
    {
      ++iter;
      ++i;
    }
    iter->printCalories();
}

void CookieList::printLimitedCalories(size_t maxCalories)
{
    //choice d
    for (const auto& cookies : *cookieList)
    {
        if (cookies.getCalories() <= maxCalories)
            cookies.printCalories();
    }
}

void CookieList::printServingSize(size_t selection)
{
    auto iter = cookieList->begin();
    size_t i = 1;
    while (i < selection)
    {
      ++iter;
      ++i;
    }
    iter->printRecipe();
}

void CookieList::clearList()
{
    cookieList->clear();
}

CookieList::CookieList(const CookieList& otherCookieList)
{
    cookieList = new list<Cookie>;
    *cookieList = *otherCookieList.cookieList;
}

CookieList& CookieList::operator=(const CookieList& otherCookieList)
{
    if (this == &otherCookieList)
        cerr << "Cannot do self-assignment." << endl;
    else
    {
        *cookieList = *otherCookieList.cookieList;
    }
    return *this;
}

CookieList::~CookieList()
{
    delete cookieList;
    cookieList = nullptr;
}




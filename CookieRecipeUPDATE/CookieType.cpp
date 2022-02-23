#include "CookieType.h"

using namespace std;

CookieType::CookieType(const string& cookieName, size_t cookieCalories)
{
    nameOfCookie = cookieName;
    numOfCalories = cookieCalories;
}

string CookieType::getName() const
{
    return nameOfCookie;
}

size_t CookieType::getCalories() const
{
    return numOfCalories;
}

void CookieType::setName(const string& cookieName)
{
    nameOfCookie = cookieName;
}

void CookieType::setCalories(size_t calories)
{
    numOfCalories = calories;
}
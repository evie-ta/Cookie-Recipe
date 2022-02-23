#ifndef COOKIETYPE_H
#define COOKIETYPE_H

#include <iostream>
#include <string>

class CookieType
{
public:

    CookieType() : numOfCalories(0) {}
    CookieType(const std::string& cookieName, size_t cookieCalories);

    std::string getName() const;
    size_t getCalories() const;

    void setName(const std::string& cookieName);
    void setCalories(size_t calories);

    ~CookieType() {};

private:
    std::string nameOfCookie;
    size_t numOfCalories;
};

#endif
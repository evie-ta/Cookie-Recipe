#ifndef COOKIELIST_H
#define COOKIELIST_H

#include "Cookie.h"

#include <list>

class CookieList
{
public:
	CookieList();

	void addCookie(const Cookie& aCookie);
	void addCookie(const std::string& newName, size_t newCalories,
		const std::set<std::string>& newIngredients, size_t newServings,
		const std::string& instruction);

	size_t getCount() const;

	bool isEmpty() const;

	void printAllCookies() const;

	void printCookiesSelection() const;
	void printRecipe(size_t selection);
	void printCalories(size_t selection);
	void printLimitedCalories(size_t maxCalories);
	void printServingSize(size_t selection);

	void clearList();

	CookieList(const CookieList & otherCookieList);
	CookieList& operator=(const CookieList& otherCookieList);
	~CookieList();

private:
	std::list<Cookie> * cookieList;
};

#endif

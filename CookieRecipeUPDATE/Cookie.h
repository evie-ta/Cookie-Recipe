#ifndef COOKIE_H
#define COOKIE_H

#include <iostream>
#include <string>
#include <set>
#include <vector>

#include "CookieType.cpp"


class Cookie : public CookieType
{
public:

    Cookie() : numOfServings(0) {}
    Cookie(const std::string& cookieName, size_t cookieCalories,
        const std::set<std::string>& ingredients, size_t servings,
        const std::string& instruction);

    //accessor
    size_t getServings() const;
    std::set<std::string> getIngredients();
    std::string getInstructions() const;
    const Cookie& getCookie() const;

    //mutator
    void setServings(size_t servingSize);
    void setIngredients(const std::vector<std::string>&
                            listOfIngredients);
    void setInstructions(const std::string& instruction);

    //print
    void printRecipe() const;
    void printIngredients() const;
    void printCalories() const;
    void printInstructions() const;

    ~Cookie() {}

private:
    std::set<std::string> ingredientsList;
    std::string instructionSteps;
    size_t numOfServings;

};

#endif
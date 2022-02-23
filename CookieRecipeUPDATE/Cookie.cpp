#include <set>
#include <vector>
#include <string>

#include "Cookie.h"

using namespace std;


Cookie::Cookie(const string& cookieName, size_t cookieCalories,
        const set<string>& ingredients, size_t servings, const string& instruction)
        : CookieType(cookieName, cookieCalories)
        {
            ingredientsList = ingredients;
            numOfServings = servings;
            instructionSteps = instruction;
        }

//accessor
size_t Cookie::getServings() const
{
    return numOfServings;
}

set<string> Cookie::getIngredients()
{
    return ingredientsList;
}

string Cookie::getInstructions() const
{
    return instructionSteps;
}

const Cookie& Cookie::getCookie() const
{
    return *this;
}

//mutator
void Cookie::setServings(size_t servingSize)
{
    numOfServings = servingSize;
}

void Cookie::setIngredients(const vector<string>& listOfIngredients)
{
    int vectorSize = static_cast<int>(listOfIngredients.size());
    ingredientsList.clear();
    for (int i = 0; i < vectorSize; ++i)
        ingredientsList.insert(listOfIngredients[i]);
}

void Cookie::setInstructions(const string& instruction)
{
    instructionSteps = instruction;
}

void Cookie::printRecipe() const
{
    cout << "    Recipe for " << getName()
        << endl << "        Servings: "
        << numOfServings << endl;
    // PRINT INSTRUCTION HERE
}

void Cookie::printIngredients() const
{
    cout << "        Ingredients: ";

    auto iter = ingredientsList.begin();
    cout << *iter;
    ++iter;

    auto iterEnd = ingredientsList.end();

    for (iter; iter != iterEnd; ++iter)
    {
        cout << ", " << *iter;
    }
    cout << endl;
}

void Cookie::printCalories() const
{
    cout << "    " << getName()
        << " " << "(calories: "
        << getCalories() << ")" << endl;
}

void Cookie::printInstructions() const
{
    string temp = instructionSteps;
    string delim = ".";
    int pos = temp.find(delim);
    string result;

    cout << "        Instructions: ";

    result += temp.substr(0, pos) + ".\n";
    temp.erase(0, pos + delim.size());

    while ((pos = temp.find(delim)) != std::string::npos)
      {
          result += ("                     " + temp.substr(0, pos) + ".\n");
          temp.erase(0, pos + delim.size());
      }
      result += (temp.substr(0, pos));
      cout << result;
}


#include "CookieDB.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;



void getData(string& newName, size_t& newCalories,
	set<string>& newIngredients, size_t& newServings,
	size_t idx, string& newInstructions)

{
  string line;
  string trash;
  vector<string> names;
  vector<size_t> calories;
  vector<size_t> servings;
  vector<set<string>> ingredients;
  vector<string> instructions;

    ifstream myfile ("DB.txt");

  if (myfile.is_open())
  {
    while (getline(myfile, line))
    {
      istringstream in{line};
      getline(in, newName, '<');
      //add to vector<string> names;
      names.push_back(newName);

      //add to calories, servings
      in >> newCalories >> trash >> newServings >> trash >> ws;
      calories.push_back(newCalories);
      servings.push_back(newServings);


      //isolate the ingredients
      string temp;
      getline(in, temp, '<');
      string delim = ", ";
      string token;
      int pos = 0;

      set<string> ingrList;
      while ((pos = temp.find(delim)) != std::string::npos)
      {
          token = temp.substr(0, pos); //flour
          ingrList.insert(token);
          temp.erase(0, pos + delim.size());
      }
      ingrList.insert(temp.substr(0, pos));
      ingredients.push_back(ingrList);

      in >> ws;

      string instr;
      getline(in, instr);
      instructions.push_back(instr);

    }
    myfile.close();
  }
  else
    cout << "Unable to open file";


	newName = names[idx];
	newCalories = calories[idx];
	newIngredients = ingredients[idx];
	newServings = servings[idx];
	newInstructions = instructions[idx];
}



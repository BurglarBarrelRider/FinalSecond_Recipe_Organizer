
#include <iostream> // library iostream to use basic data structures
#include <string> // library string to use classes string
#include <vector>
using namespace std;

struct Recipe {
    string name;
    string category;
    vector<string> ingredients;
    string directions;
};

void displayRecipe(const Recipe& recipe) { // this function is to display event details after user fill it
    cout << "Recipe Name: " << recipe.name << endl; 
    cout << "Category: " << recipe.category << endl;
    cout << "Ingredients:" << endl;
    // for (const auto& ingredient : recipe.ingredients) { 
    //     cout << "- " << ingredient << endl;
    // }
    for (int i = 0; i < recipe.ingredients.size(); ++i) {
        cout << " * " << recipe.ingredients[i] << endl;
    }
    cout << "Directions: " << recipe.directions << endl;
}

void addRecipe(Recipe& recipe) {
    cout << "------------------------" << endl;
    cout << "Enter recipe name: ";
    getline(cin, recipe.name);
    cout << "Enter recipe category: ";
    getline(cin, recipe.category);

    int numIngredients;
    cout << "Enter number of ingredients: ";
    cin >> numIngredients;
    cin.ignore(); // используется для очистки буфера ввода после ввода числовых значений с помощью cin.
    // Это предотвращает нежелательное поведение при использовании getline после cin. Error handling

    recipe.ingredients.clear();
    for (int i = 0; i < numIngredients; i++) {
        string ingredient;  
        // ingredient создается внутри пределов цикла. Каждый раз, когда цикл выполняется, создается новая локальная переменная ingredient
        cout << "Enter ingredient " << i + 1 << ": ";
        getline(cin, ingredient);
        recipe.ingredients.push_back(ingredient); // метод вектора
    }

    cout << "Enter directions: ";
    getline(cin, recipe.directions);
}

void displayAllRecipes(const vector<Recipe>& recipes) {
    if (recipes.empty()) {
        cout << "------------------------" << endl;
        cout << "No recipes found. Add your recipes " << endl;
        return;
    }

    for (const auto& recipe : recipes) { // const auto& мы не создаем копию, а ссылку
        displayRecipe(recipe);
        cout << "------------------------" << endl;
    }
}

// void displayAllRecipes(const vector<Recipe>& recipes) {
//     if (recipes.empty()) {
//         cout << "------------------------" << endl;
//         cout << "No recipes found. Add your recipes " << endl;
//         return;
//     }

//     for (auto j = recipes.begin(); j != recipes.end(); ++j) {
//         const Recipe& recipe = recipes[j - recipes.begin()]; // были ошибки при объявлении recipe=recipes[j - recipes.begin()] 
//         displayRecipe(recipe);                               // минусуем чтобы достать текущий индекс j элемента recipes            
//         cout << "------------------------" << endl;
//     }
// }


void searchRecipeByName(const vector<Recipe>& recipes, const string& name) {
    vector<Recipe> matchedRecipes;
    for (const auto& recipe : recipes) {
        if (recipe.name == name) {
            matchedRecipes.push_back(recipe);
        }
    }

    if (matchedRecipes.empty()) {
        cout << "------------------------" << endl;
        cout << "No recipes found when searching the name: " << name << endl;
    } else {
        cout << "Recipes with the name '" << name << "':" << endl;
        for (const auto& recipe : matchedRecipes) {
            displayRecipe(recipe);
            cout << "------------------------" << endl;
        }
    }
}

void deleteRecipeByName(vector<Recipe>& recipes, const string& name) {
    for (size_t i = 0; i < recipes.size(); ++i) {
        if (recipes[i].name == name) {
            recipes.erase(recipes.begin() + i);
            cout << "Recipe '" << name << "' deleted successfully." << endl;
            return;
        }
    }
    cout << "No recipe found with the name: " << name << endl;
}

int main() {
    
    vector<Recipe> recipes;

    char answer = 'Y';
    while (answer == 'Y' || answer == 'y') {
        int userSelect;
        cout << endl;
        cout << " -------| W e l c o m e |------- "<< endl;
        cout << "Recipe Collection Organizer:" << endl;
        cout << "1. Display all recipes" << endl;
        cout << "2. Search for a recipe by name" << endl;
        cout << "3. Delete a recipe by name" << endl;
        cout << "4. Add a new recipe" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> userSelect;
        cin.ignore();

        switch (userSelect) {
            case 1:
                displayAllRecipes(recipes);
                break;
            case 2: {
                string name;
                cout << "Enter the name of the recipe you wantto search: ";
                getline(cin, name);
                searchRecipeByName(recipes, name);
                break;
            }
            case 3: {
                string name;
                cout << "Enter the name of the recipe you want to delete: ";
                getline(cin, name);
                deleteRecipeByName(recipes, name);
                break;
            }
            case 4: {
                Recipe newRecipe;
                addRecipe(newRecipe);
                recipes.push_back(newRecipe);
                break;
            }
            case 5:
                cout << "Programm ends here." << endl;
                return 0;
            default:
                cout << "Can not read userSelect. Error/invalid input. Enter a num between 1 and 5 " << endl;
        }

        cout << "\nDo you want to continue? Y/N: ";
        cin >> answer;
        cin.ignore(); // тут тоже были ошибки с инпутом вылетает за границы
    }

    return 0;
}



// #include <iostream>
// #include <fstream>
// #include <string>
// #include <vector>
// using namespace std;

// struct Recipe {
//     string name;
//     string category;
//     vector<string> ingredients;
//     string directions;
// };

// void displayRecipe(const Recipe& recipe) {
//     cout << "Recipe Name: " << recipe.name << endl; 
//     cout << "Category: " << recipe.category << endl;
//     cout << "Ingredients:" << endl;
//     for (const auto& ingredient : recipe.ingredients) {
//         cout << " * " << ingredient << endl;
//     }
//     cout << "Directions: " << recipe.directions << endl;
// }

// void addRecipe(Recipe& recipe) {
//     cout << "------------------------" << endl;
//     cout << "Enter recipe name: ";
//     getline(cin, recipe.name);
//     cout << "Enter recipe category: ";
//     getline(cin, recipe.category);

//     int numIngredients;
//     cout << "Enter number of ingredients: ";
//     cin >> numIngredients;
//     cin.ignore();

//     recipe.ingredients.clear();
//     for (int i = 0; i < numIngredients; i++) {
//         string ingredient;
//         cout << "Enter ingredient " << i + 1 << ": ";
//         getline(cin, ingredient);
//         recipe.ingredients.push_back(ingredient);
//     }

//     cout << "Enter directions: ";
//     getline(cin, recipe.directions);
// }

// void displayAllRecipes(const vector<Recipe>& recipes) {
//     if (recipes.empty()) {
//         cout << "------------------------" << endl;
//         cout << "No recipes found. Add your recipes." << endl;
//         return;
//     }

//     for (const auto& recipe : recipes) {
//         displayRecipe(recipe);
//         cout << "------------------------" << endl;
//     }
// }

// void searchRecipeByName(const vector<Recipe>& recipes, const string& name) {
//     vector<Recipe> matchedRecipes;
//     for (const auto& recipe : recipes) {
//         if (recipe.name == name) {
//             matchedRecipes.push_back(recipe);
//         }
//     }

//     if (matchedRecipes.empty()) {
//         cout << "------------------------" << endl;
//         cout << "No recipes found with the name: " << name << endl;
//     } else {
//         cout << "Recipes with the name '" << name << "':" << endl;
//         for (const auto& recipe : matchedRecipes) {
//             displayRecipe(recipe);
//             cout << "------------------------" << endl;
//         }
//     }
// }

// void deleteRecipeByName(vector<Recipe>& recipes, const string& name) {
//     for (size_t i = 0; i < recipes.size(); ++i) {
//         if (recipes[i].name == name) {
//             recipes.erase(recipes.begin() + i);
//             cout << "Recipe '" << name << "' deleted successfully." << endl;
//             return;
//         }
//     }
//     cout << "No recipe found with the name: " << name << endl;
// }

// void saveRecipesToFile(const vector<Recipe>& recipes, const string& filename) {
//     ofstream outFile(filename);
//     if (outFile.is_open()) {
//         for (const auto& recipe : recipes) {
//             outFile << recipe.name << endl;
//             outFile << recipe.category << endl;
//             outFile << recipe.ingredients.size() << endl;
//             for (const auto& ingredient : recipe.ingredients) {
//                 outFile << ingredient << endl;
//             }
//             outFile << recipe.directions << endl;
//             outFile << "-----" << endl; // separator between recipes
//         }
//     }
// }

// void loadRecipesFromFile(vector<Recipe>& recipes, const string& filename) {
//     ifstream inFile(filename);
//     if (inFile.is_open()) {
//         recipes.clear();
//         while (!inFile.eof()) {
//             Recipe recipe;
//             string line;
//             getline(inFile, recipe.name);
//             if (recipe.name.empty()) break; // handle last empty line
//             getline(inFile, recipe.category);
//             int numIngredients;
//             inFile >> numIngredients;
//             inFile.ignore(); // ignore the newline character after number of ingredients
//             recipe.ingredients.resize(numIngredients);
//             for (int i = 0; i < numIngredients; ++i) {
//                 getline(inFile, recipe.ingredients[i]);
//             }
//             getline(inFile, recipe.directions);
//             getline(inFile, line); // read the separator line (-----)
//             recipes.push_back(recipe);
//         }
//     }
// }

// int main() {
//     vector<Recipe> recipes;
//     const string filename = "recipes.txt";
//     loadRecipesFromFile(recipes, filename);

//     char answer = 'Y';
//     while (answer == 'Y' || answer == 'y') {
//         int userSelect;
//         cout << endl;
//         cout << " -------| W e l c o m e |------- "<< endl;
//         cout << "Recipe Collection Organizer:" << endl;
//         cout << "1. Display all recipes" << endl;
//         cout << "2. Search for a recipe by name" << endl;
//         cout << "3. Delete a recipe by name" << endl;
//         cout << "4. Add a new recipe" << endl;
//         cout << "5. Exit" << endl;
//         cout << "Enter your choice (1-5): ";
//         cin >> userSelect;
//         cin.ignore();

//         switch (userSelect) {
//             case 1:
//                 displayAllRecipes(recipes);
//                 break;
//             case 2: {
//                 string name;
//                 cout << "Enter the name of the recipe you want to search: ";
//                 getline(cin, name);
//                 searchRecipeByName(recipes, name);
//                 break;
//             }
//             case 3: {
//                 string name;
//                 cout << "Enter the name of the recipe you want to delete: ";
//                 getline(cin, name);
//                 deleteRecipeByName(recipes, name);
//                 break;
//             }
//             case 4: {
//                 Recipe newRecipe;
//                 addRecipe(newRecipe);
//                 recipes.push_back(newRecipe);
//                 break;
//             }
//             case 5:
//                 saveRecipesToFile(recipes, filename);
//                 cout << "Program ends here." << endl;
//                 return 0;
//             default:
//                 cout << "Invalid input. Enter a number between 1 and 5." << endl;
//         }

//         cout << "\nDo you want to continue? Y/N: ";
//         cin >> answer;
//         cin.ignore();
//     }

//     saveRecipesToFile(recipes, filename);
//     return 0;
// }

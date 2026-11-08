#include <ftxui/ftxui.hpp>
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;
using namespace ftxui;

int main()
{
    ofstream outputFile;
    ifstream inputFile;

    inputFile.open("Test Map.txt");
    if (inputFile.fail()) {
        perror("Test Map.txt");
        return 1;
    }

    string line;
    vector<string> lines;

    while (getline(inputFile, line)) {
        lines.push_back(line);
    }

    Elements mapData;
    for (const auto& item : lines) {
        mapData.push_back(text(item));
    }

    Element document = vbox(move(mapData)) | border;

    //auto document = vbox(mapData) | border;

    // Create a screen with full width and height fitting the document.
    auto screen = Screen::Create(
        Dimension::Full(), // Width
        Dimension::Fit(document) // Height
    );

    // Render document to the screen
    Render(screen, document);

    // Print screen to the console
    screen.Print();

    std::cout << lines[2][14];

    return 0;
}


//Game Challenge 3
//
//HINTS:
//
//1. Store your game level in a vector of strings! Each string is a row in your level.You can treat this vector of strings as a 2D array.
//For instance,
//
//vector <string> levelData;
//
//and if you want to get the object at 3, 3 you call
//
//char object = levelData[3][3];
//
//2. Whenever your player or a monster wants to move in a direction, first check to see what char is on the board in that direction, and use a switch statement to evaluate what should happen.
//
//3. Use an ifstream and the getline function to load your level from a.txt file!Load one row at a time and put them in a string, then push back each string to your vector.
//
//4. Surround your player with walls '#' so the player can't try to walk off the edge. 
//
//5. Create a Monster class and store the monsters in a vector <Monster> monsters;
//Then, each time you loop through the main game loop, you can loop through this monsters array and randomly move each one.You can also check to see if the player is nearby, and attack the player if he is!


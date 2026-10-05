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

    //auto document =
    //    vbox({
    //        text("ROGUELIKE") | bold | center,
    //        separator(),
    //        text("FTXUI IS WORKING"),
    //        text(""),
    //        text("@ . . . # . G"),
    //        text(". . . . # . ."),
    //        text(". . . . . . ."),
    //        })
    //        | border;

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

    return 0;
}
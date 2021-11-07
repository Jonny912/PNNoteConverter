// PNNotesConverver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "pugixml.hpp"
#include "../packages/nlohmann.json.3.10.4/build/native/include/nlohmann/json.hpp"

int main()
{
    std::cout << "Notes Converter for Pacific Network (888poker.com) client (v 0.1 pre-release)\n";

    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("Notes.xml");
    if (!result)
        return -1;


    const auto& notes = doc.child("PlayerNotes").children("Note");
    int count = 0;
    for (const auto& note : notes)
    {
        std::cout << "Node #" << ++count << std::endl;

        nlohmann::json noteJson;
        noteJson["chatDisabled"] = note.child_value("disableChat") ? true : false;
        noteJson["playerNickname"] = note.child_value("playerName");
        noteJson["tagIndex"] = atol(note.child_value("playerMark"));
        noteJson["text"] = note.child_value("quickNote");

        auto dump = noteJson.dump(4);

        std::ofstream jsonOut("out.json", std::ifstream::app);
        
        jsonOut << dump << "," << std::endl;
    }
}

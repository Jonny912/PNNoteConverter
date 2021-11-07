// PNNotesConverver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "pugixml.hpp"

int main()
{
    std::cout << "Notes Converter for Pacific Network (888poker.com) client (v 0.1 pre-release)\n";

    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("Notes.xml");
    if (!result)
        return -1;

    //auto notes = doc.children("PlayerNotes");
    auto notes = doc.document_element();
    
    for (auto note : notes)
    {
        auto player = doc.children("Note");
        for (auto attr : player)
            std::cout << note.attribute("playerName").value() << std::endl;
    }
}


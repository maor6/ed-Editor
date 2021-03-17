#include <iostream>
#include <fstream>
#include "Editor.h"
using namespace editor;

int main(int argc, char **argv)
{
    Editor *editor;
    std::ifstream myfile;
    switch (argc) // Check if initialized with text
    {
    case 1:
        editor = new Editor();
        break;

    case 2:
        myfile.open(argv[1]);
        editor = new Editor(myfile);
        myfile.close();
        break;

    default:
        break;
    }

    editor->loop();

    return 0;
}
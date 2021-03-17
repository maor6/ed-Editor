#include "Editor.h"

namespace editor
{
    Editor::Editor(/* args */)
    {
        this->doc = new Document();
    }

    Editor::Editor(istream &file)
    {
        vector<string> temp;
        string line;
        while (getline(file, line)) // Output the text from the file  
        {
            temp.push_back(line);
            line.clear();
        }

        this->doc = new Document(temp);
    }

    Editor::~Editor()
    {
        delete(this->doc);
    }

    void Editor::loop()
    {
        string currectComand;
        regex PMNumber ("[+|-][1-9]+");
        regex onlyNumber ("[1-9]+");
        regex findText (R"(/(\w+)/)");
        regex switchWord (R"(s/(.+)/(.*)/)");
        regex writeToFile (R"(w\s(\w+).txt)");
        getline(cin, currectComand);

        while (currectComand != "q") { // TODO activate appropriate function from Document class
            if (regex_match (currectComand, onlyNumber)) {
                this->doc->moveRowTo(currectComand);
            }

            else if (regex_match (currectComand, PMNumber)) {
                this->doc->moveRow(currectComand);
            }

            else if (regex_match  (currectComand, findText)) {
                this->doc->searchText(currectComand.substr(1, currectComand.size()-2));
            }

            else if (regex_match  (currectComand, switchWord)) {
                int cutFrom = 2;
                this->doc->switchWord(currectComand.substr(cutFrom, currectComand.size()-3));
            }

            else if (regex_match (currectComand, writeToFile)) {
                this->doc->writeToFile(currectComand.substr(2, currectComand.size()));
            }

            else {
                if (currectComand == "a") {
                    this->doc->addRowAfter();
                }

                else if (currectComand == "i") {
                    this->doc->addRowBefore();
                }

                else if (currectComand == "c") {
                    this->doc->switchRow();
                }

                else if (currectComand == "d") {
                    this->doc->deleteCurrentRow();
                }

                else if (currectComand == "j") {
                    this->doc->ConnectRow();
                }

                else if (currectComand == "$") {
                    this->doc->moveToLastRow();
                }
                else {
                    cout << "?" << endl;
                }
            }

            fflush(stdin);
            getline(cin, currectComand);
        }
    }
}
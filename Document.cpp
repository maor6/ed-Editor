#include "Document.h"

namespace document
{
    Document::Document()
    {
        this->text = *new vector<string>;
        this->linePointer = 1;
    }

     Document::Document(vector<string> &text)
    {
        this->text = text;
        this->linePointer = 1;
    }

    Document::~Document()
    {
        delete(&this->text);
        delete(&this->linePointer);
    }

    void Document::moveRowTo(string &rowNumber) { //TODO fix if i dont have a tet yet
        int tempRow = stoi(rowNumber);
        if (this->text.size() != 0 &&  tempRow <= this->text.size()) {
            this->linePointer = tempRow;
        }
    }

    void Document::moveRow(string &PMRow) { // PMRow: plus minus row
        int firstLine = 1;
        int tempRow = stoi(PMRow.substr(1, PMRow.size())); // get the number
        if (PMRow[0] == '-') {
            tempRow = this->linePointer - tempRow; // substruct the current row with the number
            if (tempRow >= firstLine) {
                this->linePointer = tempRow;
            }
        }

        else {
            tempRow = this->linePointer + tempRow; // Add the current row with the number
            if (tempRow <= this->text.size()) {
            this->linePointer = tempRow;
            }
        }
        
        if (this->text.size() == 0) {
            tempRow = firstLine;
        }
    }

    void Document::addRowAfter() {
        string textRow = "";
        getline(cin, textRow);
        while (textRow != ".") {
            if (this->text.empty()) {
                this->text.insert(this->text.begin(), textRow);
            }
            else {
                auto inPos = this->text.begin() + this->linePointer++;
                this->text.insert(inPos, textRow);     
            }
            getline(cin, textRow);
        }

        fflush(stdin);
    }

    void Document::addRowBefore() {
        string textRow = "";
        getline(cin, textRow);
        while (textRow != ".") {
            auto inPos = this->text.begin() + this->linePointer++ - 1;
            this->text.insert(inPos, textRow);
            getline(cin, textRow);
        }

        fflush(stdin);
        this->linePointer--;
    }

    void Document::deleteCurrentRow() {
        if (this->text.size() != 0) {
            this->text.erase(this->text.begin() + this->linePointer-1);
            if (this->linePointer-1 != 0) {
                this->linePointer--;
            }
        }
    }

    void Document::moveToLastRow() {
        if (this->text.size() != 0) {
        this->linePointer = this->text.size();
        }

        if (this->text.at(this->linePointer-1) == "") {
            this->linePointer--;
        }
    }

    void Document::switchRow() {
        this->deleteCurrentRow();
        this->addRowAfter();
    }

    void Document::switchWord(string wordOldNew) {
        int cutPoint = wordOldNew.find('/');
        string old = wordOldNew.substr(0, cutPoint);
        string new1 = wordOldNew.substr(cutPoint+1, wordOldNew.size());
        if (this->text.at(this->linePointer-1).find(old) != string::npos && this->text.size() != 0) {
            this->text.at(this->linePointer-1).
                replace(this->text.at(this->linePointer-1).find(old), old.size() ,new1);
        }
            
    }

    void Document::searchText(const string text) {
        int i = (this->linePointer % this->text.size()) + 1;
        while (this->text.at(i-1).find(text) == string::npos && i != this->linePointer) {
            i = (i % this->text.size()) + 1;
        }

        this->linePointer = i;
    }

    void Document::ConnectRow() {
        if (this->linePointer != this->text.size()) {
            this->text.at(this->linePointer-1) += this->text.at(this->linePointer);
            this->text.erase(this->text.begin() + this->linePointer);
        }
    }

    void Document::writeToFile(const string fileName) {
        ofstream newFile (fileName);
        if (newFile.is_open()) {
            for(vector<string>::iterator row = this->text.begin(); row != this->text.end(); ++row) {
                newFile << *row << endl;
            }
        }

        newFile.close();
    }
}
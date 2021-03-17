#ifndef _DOCUMENT_
#define _DOCUMENT_

#include <vector>
#include <string>
#include <iostream>
#include <regex>
#include <fstream>

using namespace std;

namespace document
{
    class Document
    {
    private:
       /* data */
       
    public:
        int linePointer;
        vector<string> text;
        Document(/* args */);
        Document(vector<string> &text);
        ~Document();
        void moveRowTo(string &rowNumber);
        void moveRow(string &PMRow);
        void addRowAfter();
        void addRowBefore();
        void switchRow();
        void deleteCurrentRow();
        void ConnectRow();
        void moveToLastRow();
        void switchWord(string wordOldNew);
        void searchText(const string text);
        void writeToFile(const string fileName);
    };
}

#endif
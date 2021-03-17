#ifndef _EDITOR_
#define _EDITOR_
#include "Document.h"
#include <iostream>

using namespace document;

namespace editor
{
    class Editor
    {
    private:
    /* data */
    
    public:
        Document *doc;
        Editor(/* args */);
        Editor(istream &file);
        ~Editor();
        void loop();
    };
}
#endif
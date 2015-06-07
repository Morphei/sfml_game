
#include "parser.h"
#include <iostream>
#include <X11/Xlib.h>


int main()
{
XInitThreads();
Parser parser;

parser.run();

}


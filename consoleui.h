#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "scientistservice.h"

class ConsoleUI
{
public:
    ConsoleUI();
    void run ();

private:
    void displayListOfScientists ();
    ScientistService _service;
};

#endif // CONSOLEUI_H

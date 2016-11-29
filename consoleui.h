#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "scientistservice.h"

class ConsoleUI
{
public:
    ConsoleUI();
    void run ();

private:
    void displayListOfPerfmers ();
    PerformerService _service;
};

#endif // CONSOLEUI_H

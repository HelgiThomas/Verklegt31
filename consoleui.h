#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "scientstservice.h"

class ConsoleUI
{
public:
    ConsoleUI();
    void run ();

private:
    void displayListOfPerfmers ();
private:
    PerformerService _service;
};

#endif // CONSOLEUI_H

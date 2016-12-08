#include "ui/consoleui.h"
#include <iostream>
#include <stdlib.h>
#define RESET   "\033[0m"
#define LIGHTBLUE   "\033[96m"

using namespace std;

void frontPage();
/*
 * The main function of the program which only calles the first menu function.
 */
int main()
{
    frontPage();

    ConsoleUI ui;
    ui.run();

    return 0;
}

void frontPage()
{
    system("Color");

        cout << LIGHTBLUE << endl << endl;
        cout << "\t\t\t" << "HHHHHHHHH     HHHHHHHHH                   lllllll lllllll    " << endl;
        cout << "\t\t\t"  <<"H:::::::H     H:::::::H                   l:::::l l:::::l      " << endl;
        cout << "\t\t\t"  <<"H:::::::H     H:::::::H                   l:::::l l:::::l       " << endl;
        cout << "\t\t\t"  <<"HH::::::H     H::::::HH                   l:::::l l:::::l          " << endl;
        cout << "\t\t\t"  <<"  H:::::H     H:::::H      eeeeeeeeeeee    l::::l  l::::l    ooooooooooo" << endl;
        cout << "\t\t\t"  <<"  H:::::H     H:::::H    ee::::::::::::ee  l::::l  l::::l  oo:::::::::::oo " << endl;
        cout << "\t\t\t"  <<"  H::::::HHHHH::::::H   e::::::eeeee:::::eel::::l  l::::l o:::::::::::::::o" << endl;
        cout << "\t\t\t"  <<"  H:::::::::::::::::H  e::::::e     e:::::el::::l  l::::l o:::::ooooo:::::o" << endl;
        cout << "\t\t\t"  <<"  H:::::::::::::::::H  e:::::::eeeee::::::el::::l  l::::l o::::o     o::::o" << endl;
        cout << "\t\t\t"  <<"  H::::::HHHHH::::::H  e:::::::::::::::::e l::::l  l::::l o::::o     o::::o" << endl;
        cout << "\t\t\t"  <<"  H:::::H     H:::::H  e::::::eeeeeeeeeee  l::::l  l::::l o::::o     o::::o" << endl;
        cout << "\t\t\t"  <<"  H:::::H     H:::::H  e:::::::e           l::::l  l::::l o::::o     o::::o" << endl;
        cout << "\t\t\t"  <<"HH::::::H     H::::::HHe::::::::e         l::::::ll::::::lo:::::ooooo:::::o" << endl;
        cout << "\t\t\t"  <<"H:::::::H     H:::::::H e::::::::eeeeeeee l::::::ll::::::lo:::::::::::::::o" << endl;
        cout << "\t\t\t"  <<"H:::::::H     H:::::::H  ee:::::::::::::e l::::::ll::::::l oo:::::::::::oo" << endl;
        cout << "\t\t\t"  <<"HHHHHHHHH     HHHHHHHHH    eeeeeeeeeeeeee llllllllllllllll   ooooooooooo " << endl << endl << endl;

        cout << "Authors: " << endl;
        cout << "Benedikt Thorri Thorarinsson" << endl;
        cout << "Emil Hjaltason" << endl;
        cout << "Helgi Hallgrimsson" << endl;
        cout << "Kolbrun Hafdisardottir" << endl;
        cout << "Sigrun Elva Reynisdottr" << endl;
        cout << "Thorsteinn Saemundsson" << endl;
        string input;
        cout << "Press Enter to continue...";
        getline(cin, input);
        cout << RESET;

}

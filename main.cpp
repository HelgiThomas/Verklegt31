#include "gui/consolegui.h"
#include <iostream>
#include <stdlib.h>
#define RESET   "\033[0m"   //We define the colors here.
#define LIGHTBLUE   "\033[96m"
#include <QApplication>

using namespace std;

void clearScreen();
void frontPage();

/**
 * The main function of the program calles the menu function.
 */
int main(int argc, char *argv[])
{   
    QApplication app(argc, argv);
    consolegui w;
    w.show();

    return app.exec();
}

/**
 * @brief This is the frontpage of our program.
 */
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
/**
 * @brief this clears the screen.
 */
void clearScreen()
{
#ifdef _WIN32
    system ("cls");
#endif
#ifdef __APPLE__
    system("clear");
#endif
}

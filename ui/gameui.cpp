#include "gameui.h"

#include <stdlib.h>

GameUI::GameUI()
{
    score = 0;
}

/**
 * @brief plays a game with the user, guessing who owns the citation.
 */
void GameUI::playCitation(){

    _util.clearScreen();

    vector<Scientist> Scientists = _serviceSci.getScientists();

    int r = rand() % (Scientists.size()) + 0;

    string guess;
    string quote = Scientists[r].getCitation();

    cout << "----------------------------------------------------------------" << endl;
    cout << "Let's play a little game, guess who owns the following citation!" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << quote << endl;
    cout << "Answer: ";
    getline (cin,guess);
    getline (cin,guess);
    cout << endl;

    if (guess == Scientists[r].getName())
    {
        cout << "You Guessed Correctly!!" << endl;
        score++;
        cout << "Your score is: " << score << endl;
        cout << endl;
    }
    else
    {
        cout << "Wrong answer!" << endl;
        cout << "The correct answer is: " << Scientists[r].getName() << endl;
        cout << endl;
    }
}

void GameUI::playRelation()
{
    _util.clearScreen();
    
    vector<int>ScientistID = _serviceSci.allScientistID();
    vector<int>ComputerID = _serviceComp.allComputerID();

    vector<Computer> Computers = _serviceComp.getComputers();
    vector<Scientist> Scientists = _serviceSci.getScientists();
    vector<Computer> lengthComputer;
    vector<Scientist> lengthScientist;
    vector<Scientist> tempSci;

    for (unsigned int i = 0 ; i < ComputerID.size(); i++)
    {
        for (unsigned int k = 0; k < Computers.size(); k++)
        {
            if(ComputerID[i] == Computers[k].getId())
            {
                lengthComputer.push_back(Computers[k]);
                break;
            }
        }
    }

    for (unsigned int i = 0 ; i < ScientistID.size(); i++)
    {
        for (unsigned int k = 0; k < Scientists.size();k++)
        {
            if(ScientistID[i] == Scientists[k].getId())
            {
                lengthScientist.push_back(Scientists[k]);
            }
        }
    }

    int sci = rand() % (lengthScientist.size()) + 0;
    int comp = rand() % (lengthComputer.size()) + 0;

    string question1 = lengthScientist[sci].getName();
    string question2 = lengthComputer[comp].getName();
    string guess, choice;

    cout << "Do you want to guess a particular scientist or computer?? " << endl;
    cin >> choice;
    if(choice == "scientists" || choice == "Scientists" || choice == "1")
    {
        cout << "------------------------------------------------------------------------" << endl;
        cout << "Let's play a little game, which scientist is connected to this computer!" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        cout << question1 << endl;
        cout << "Answer: ";
        getline (cin,guess);
        getline (cin,guess);
        cout << endl;

        if (guess == lengthScientist[sci].getName())
        {
            cout << "You Guessed Correctly!!" << endl;
            score++;
            cout << "Your score is: " << score << endl;
            cout << endl;
        }
        else
        {
            cout << "Wrong answer!" << endl;
            cout << "The correct answer is: " << lengthScientist[sci].getName() << endl;
            cout << endl;
        }
    }
    else if(choice == "computers" || choice == "Computers" || choice == "2")
    {
        cout << "------------------------------------------------------------------------" << endl;
        cout << "Let's play a little game, which computer is connected to this scientist!" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        cout << question2 << endl;
        cout << "Answer: ";
        getline (cin,guess);
        getline (cin,guess);
        cout << endl;

        if (guess == lengthComputer[comp].getName())
        {
            cout << "You Guessed Correctly!!" << endl;
            score++;
            cout << "Your score is: " << score << endl;
            cout << endl;
        }
        else
        {
            cout << "Wrong answer!" << endl;
            cout << "The correct answer is: " << lengthComputer[comp].getName() << endl;
            cout << endl;
        }
    }
    else
    {
        _util.clearScreen();
        cout << "Invalid command!" << endl << endl;
    }

}

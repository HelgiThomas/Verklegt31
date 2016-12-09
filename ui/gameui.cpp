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
    
    //vector<Scientist>
    
}

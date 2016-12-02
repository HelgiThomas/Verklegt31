# Verklegt31
Verklegt námskeið 1</br></br>


# Authors:
Benedikt Þorri Þórarinsson </br>
Emil Hjaltason </br>
Helgi Hallgrimsson </br>
Kolbrún Hafdísardóttir </br>
Sigrún Elva Reynisdóttir </br>
Þorsteinn Sæmundsson </br>

# About:
This program is used for storing and reading data about computer scientists. User should be able to enter name, sex, birth, death and citations. The program should list all the computer scientists. The program should also be error proof and should have a good overall functionality. The list of computer scientists should be based on the Alan Turing awards recipients and a .txt file is included with 10 computer scientists already added.</br></br>

The program offers the required features: add, list, search and sort along with a couple of extra features. These extra features include reverse sorting, removing scientist from the list, playing a quiz and quitting the program.</br>

# Instructions:
The instructions for this program are quite simple. The user is presented with a main menu were 7 commands are listed.
The brackets behind each command below contain possible input to enter each command.</br></br>
1. Add ("add", "Add", "1") - Adds scientist to the list.</br>
     Name: -User can enter name that contains alphabetical characters. First letter of each name (first, middle and last) will      become capital automatically. A blank, a space or any other characters that are not alphabetical will result in an error      message (Icelandic letters are allowed). </br></br>
     Sex: -User can input "m", "M", "male" or "Male" if the scientist is a male and "f", "F", "female" or "Female" if the          scientist is a female. User can also type "yes". User will have to see for him/herself what happens.</br></br>
     Birth:/Death: -User can type an integer that's below 2016(current year) for both input lines. For death the user can only      input an integer that's greater or equal than the year of birth. Any other characters as input will result in an error.
     (Sidenote: the user is prompted for whether the scientist being entered is dead before prompted for year of death).</br></br>
     Citation: -User is first prompted for whether desired to enter citation. The input for the citation can be of any kind        and any length.</br></br>
     
2. Remove ("remove", "Remove", "2")</br>
      User is asked which scientist is desired for removal from the list. The input for the removal is the full name of the         scientist. All data on the scientist will be removed after Enter key is pressed.</br></br>
     
3. List ("list", "List", "3")</br>
      Displays all scientists stored in the database in a table.</br></br>
      
4. Sort ("sort", "Sort", "4")</br>
      Displays a table containing sorted information about the scientists.</br>
      1. Name ("name", "Name", "1")</br>
          List is displayed in an alphabetical order.</br>
      2. Sex ("sex", "Sex", "2")</br>
          List is displayed by sex. Females first, males second.</br>
      3. Birth ("birth", "Birth", "3")</br>
          List is displayed by year of birth. Youngest first, oldest last.</br>
      4. Death ("death", "Death", "4")</br>
          List is displayed by year of death. Those who died first, first and those who died last, last.</br></br>
5. Reversed Sort</br>
      Displays the list in the opposite order of what the Sort command does.</br></br>
6. Search</br>
      User can search for scientist on the list by name, sex, birth, death.</br>
      1. Name ("name", "Name", "1")</br>
           User inputes correct, full name of the scientist in order for him/her to be located.</br>
      2. Sex ("sex", "Sex", "2")</br>
           User inputs "f", "F", "female" or "Female" to locate all females and "m", "M", "male" or "Male" to locate all                  males.</br>
      3. Birth ("birth", "Birth", "3")</br>
           User inputs year to locate all scientists born in that particular year.</br>
      4. Death ("death", "Death", "4")</br>
           User inputs year to locate all scientists that died in that particular year.</br></br>
7. Game ("game", "Game", "7")</br>
      User is presented with a game, or more accurately, a quiz. The quiz presents a citation to which the user must name the       scientist to whom the citation matches. For a single question answered correctly, the user gets 1 point. For as long as       the program is running the score will be saved.</br></br>
      
8. Quit ("quit", "Quit", "8")</br>
      Exits the program.</br></br>





# The Program:
The program is divided into four classes to do its purpose.</br>
The classes are as follows:</br>
  
Class:</br>
  ConsoleUI -> Handles the user interface and prints requested data onto the console.</br>
  Scientist -> Handles the different variables stored withing the program, i.e. name, sex, year of birth etc.</br>
  ScientistService -> Handles the logic which the ConsoleUI function uses for its various functions.</br>
  DataAccess - > Handles writing and reading of information from and to a .txt file.</br>
  Main -> Runs the program</br></br>

# Work
The authors divded themself into three teams and worked together on seperate classes to achieve maximum functionality in the program and to learn how to divide tasks into subtasks, divide them between the team and them link them alltogether.
The following authors worked on the following classes:</br>

  Consoleui (Benedikt Þorri Þórarinsson, Þorsteinn Sæmundsson)</br>
  Scientist (All Authors)</br>
  ScientisService (Kolbrún Hafdísardóttir, Sigrún Elva Reynisdóttir)</br>
  Dataacess (Emil Hjaltason, Helgi Hallgrimsson)</br></br>

The team succesfully worked together and members contributed equally.


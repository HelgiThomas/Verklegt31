# Verklegt31
Verklegt námskeið 1


# Authors:
Benedikt Þorri Þórarinsson </br>
Emil Hjaltason </br>
Helgi Hallgrimsson </br>
Kolbrún Hafdísardóttir </br>
Sigrún Elva Reynisdóttir </br>
Þorsteinn Sæmundsson </br>

# About:
This program is used for storing and reading data about computer scientists. User should be able to enter name, sex, birth, death and citations. The program should list all the computer scientists. The program should also be error proof and should have a good overall functionality. The list of computer scientists should be based on the Alan Turing awards recipients and a .txt file is included with 10 computer scientists already added.

The program offers the required features: add, list, search and sort along with a couple of extra features. These extra features include reverse sorting, removing scientist from the list, playing a quiz and quitting the program.

# Instructions:
The instructions for this program are quite simple. The user is presented with a main menu were 7 commands are listed.
The brackets behind each command below contain possible input to enter each command.
1. Add ("add", "Add", "1") - Adds scientist to the list.
     Name: -User can enter name that contains alphabetical characters. First letter of each name (first, middle and last) will      become capital automatically. A blank, a space or any other characters that are not alphabetical will result in an error      message (Icelandic letters are allowed).
     Sex: -User can input "m", "M", "male" or "Male" if the scientist is a male and "f", "F", "female" or "Female" if the          scientist is a female. User can also type "yes". User will have to see for him/herself what happens.
     Birth:/Death: -User can type an integer that's below 2016(current year) for both input lines. For death the user can only      input an integer that's greater or equal than the year of birth. Any other characters as input will result in an error.
     (Sidenote: the user is prompted for whether the scientist being entered is dead before prompted for year of death).
     Citation: -User is first prompted for whether desired to enter citation. The input for the citation can be of any kind        and any length.
     
2. Remove ("remove", "Remove", "2")
      User is asked which scientist is desired for removal from the list. The input for the removal is the full name of the         scientist. All data on the scientist will be removed after Enter key is pressed.
     
3. List ("list", "List", "3")
      Displays all scientists stored in the database in a table.
      
4. Sort ("sort", "Sort", "4")
      Displays a table containing sorted information about the scientists.
      1. Name ("name", "Name", "1")
          List is displayed in an alphabetical order.
      2. Sex ("sex", "Sex", "2")
          List is displayed by sex. Females first, males second.
      3. Birth ("birth", "Birth", "3")
          List is displayed by year of birth. Youngest first, oldest last.
      4. Death ("death", "Death", "4")
          List is displayed by year of death. Those who died first, first and those who died last, last.
5. Reversed Sort
      Displays the list in the opposite order of what the Sort command does.
6. Search
      User can search for scientist on the list by name, sex, birth, death.
      1. Name ("name", "Name", "1")
           User inputes correct, full name of the scientist in order for him/her to be located.
      2. Sex ("sex", "Sex", "2")
           User inputs "f", "F", "female" or "Female" to locate all females and "m", "M", "male" or "Male" to locate all                  males.
      3. Birth ("birth", "Birth", "3")
           User inputs year to locate all scientists born in that particular year.
      4. Death ("death", "Death", "4")
           User inputs year to locate all scientists that died in that particular year.
7. Game ("game", "Game", "7")
      User is presented with a game, or more accurately, a quiz. The quiz presents a citation to which the user must name the       scientist to whom the citation matches. For a single question answered correctly, the user gets 1 point. For as long as       the program is running the score will be saved.
      
8. Quit ("quit", "Quit", "8")
      Exits the program.





# The Program:
The program is divided into four classes to do its purpose.
The classes are as follows:
  
Class:
  ConsoleUI -> Handles the user interface and prints requested data onto the console.
  Scientist -> Handles the different variables stored withing the program, i.e. name, sex, year of birth etc.
  ScientistService -> Handles the logic which the ConsoleUI function uses for its various functions.
  DataAccess - > Handles writing and reading of information from and to a .txt file.
  Main -> Runs the program

# Work
The authors divded themself into three teams and worked together on seperate classes to achieve maximum functionality in the program and to learn how to divide tasks into subtasks, divide them between the team and them link them alltogether.
The following authors worked on the following classes:

  Consoleui (Benedikt Þorri Þórarinsson, Þorsteinn Sæmundsson)
  Scientist (All Authors)
  ScientisService (Kolbrún Hafdísardóttir, Sigrún Elva Reynisdóttir)
  Dataacess (Emil Hjaltason, Helgi Hallgrimsson)

The team succesfully worked together and members contributed equally.


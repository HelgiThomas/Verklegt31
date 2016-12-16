# Verklegt31
Verklegt námskeið 1</br></br>


# Authors:
Benedikt Þorri Þórarinsson </br>
Emil Hjaltason </br>
Helgi Hallgrímsson </br>
Kolbrún Hafdísardóttir </br>
Sigrún Elva Reynisdóttir </br>
Þorsteinn Sæmundsson </br>

# About:
This program is used for storing and reading data about computer scientists and computers. User should be able to enter name, sex, birth, death and citations for scientists and name, build year, type and whether a computer was built or not ("Yes" or "No") for computers. The program should list all the computer scientists and computers, depending on which is chosen to list. The program should also be error proof and should have a good overall functionality. </br></br>

The program offers the required features: add, list, search and sort along with a couple of extra features. These extra features include reverse sorting, removing or editing a scientist or a computer from the list, playing a quiz and quitting the program.</br>

# Instructions:
The instructions for this program are quite simple. The user is presented with main menu where user can either click on List or play one of three games.</br></br>

When list is clicked the user is presented with a dialog window. The window has three tabs at the top which, when clicked, provide different options for what they include (Scientists, Computers and relations).</br></br>

The Scientists tab:</br>
Below the tabs is a search box where user can search for anything in the table below which displays the scientists            currently active in the database. It's possible to sort the scientists, ascending or descending by clicking the name of        desired sorting column. Below the table are the commands explained below.</br></br>
     
Add:
Available input: Name, sex, year of birth, year of death and citation. Citation is optional and user can enter                 whether the user is alive or not before entering death year is required. Names can not include numbers or special             characters, only alphabetical characters and whitespaces. Citations can include anything. If Name, Sex or Year of             birth are left empty the user is presented with an error and can not continue.</br></br></br>
          
Information:
When this button is clicked the user is presented with information about the chosen scientist from the table                   (Already displayed information, plus citation) in a more clean way.</br></br></br>
Remove:
This button is greyed out, until user chooses a scientist from the list. Then the button becomes clickable and user           can click it to remove scientist from the list(it will remain in the database, but can not be displayed in the                 program)
          
Edit:
This button is greyed out, until user chooses a scientist from the list. Then the button becomes clickable and user           can click it to edit a scientist from the list. User can choose which attribute(s) to edit, and edit them (theres a           checkbox for each attribute and input fields become available when checked).</br></br></br>
          
The Computers tab:</br>
Below the tabs is a search box where user can search for anything in the table below which displays the computers              currently active in the database. It's possible to sort the computers, ascending or descending by clicking the name of        desired sorting column. Below the table are the commands explained below.
     
Add:
Available input: Name, type, whether it was built or not (Yes or No) and build year. The name can be any input                 (numbers, alphabetical characters and special characters). User can choose between three computer types, or choose             the "Other" option. When that is selected a line input will become available where user can input the computer type           which can only contain alphabetical characters.
          
Information:
When this button is clicked the user is presented with information about the chosen computer from the table                   (Already displayed information) in a more clean way.
          
Remove:
This button is greyed out, until user chooses a computer from the list. Then the button becomes clickable and user             can click it to remove computer from the list(it will remain in the database, but can not be displayed in the                 program)
          
Edit:
This button is greyed out, until user chooses a computer from the list. Then the button becomes clickable and user             can click it to edit a computer from the list. User can choose which attribute(s) to edit, and edit them (theres a             checkbox for each attribute and input fields become available when checked).
          
The Relations tab:</br>
Below the tabs is a search box where user can search for anything in the table below which displays the relations              currently active in the database. It's possible to sort the relations, ascending or descending by clicking the name of        desired sorting column. Below the table are the commands explained below.
     
Add:
User is presented with a list of all computers and scientists currently stored in the database. User can then choose           scientists and computers to make a relation between(as many as desired, by selecting computer/scientist name and               clicking "Confirm selected scientist/computer" and when finished, clicking "Add relation to database"). A relation             will be made between all selected elements.
          
Remove:
This button is greyed out, until user chooses a relation from the presented list of relations stored in the                   database. Then the button becomes clickable and user can select a relation and remove it.

# The Program:
The program is divided into four classes to do its purpose.</br>
The classes are as follows:</br>
  
     Class:
     Graphical user interface layer:
          addrel: Handles functions related to adding new relations between computers and scientists.
          addcomp: Handles functions related to adding new computers to the database.
          addsci: Handles functions related to adding new scientists to the database.
          
          editcomp: Handles functions related to editing computers that are stored in the database.
          editsci: Handles functions related to editing scientists that are stored in the database.
          
          citationgame: Handles functions related to a game users can play, that uses scientist citations for a quiz.
          gamegui: Handles logic for games that are in the program.
          relationgame: Handles functions relate to a game users can play, that uses relations for a quiz.
          
          infocomp: Handles functions for displaying cleaner info about each computer.
          infosci: Handles functions for displaying cleaner info about each scientist.
          listgui: Handles functions for displaying tables the include computers, scientists and relations and their                              attributes.
          
          removecomp: Handles functions related to removing computers from the database.
          removerelation: Handles functions related to removing relations from the database.
          removescigui: Handles functions related to removing scientists from the database.
     Models:           
          Computer: Stores different variables for all computer elements which the service layer uses to transfer between                         layers while the program is running.
          Scientist: Stores different variables for all scientist elements which the service layer uses to transfer between                        layers while the program is running. 
     Business logic layer:
          computerservice: Handles data transfer between layers and logic for computer elements.
          generalservice: Handles data transfer between layers and logic for relation elements.
          scientistservice: Handles data transfer between layers and logic for scientist elements.
     Data layer:
          computeraccess: Handles the reading and writing of data to SQL database for computers.
          linkaccess: Handles the reading and writing of data to SQL database for relations.
          scientistaccess: Handles the reading and writing of data to SQL database for scientists.
          
          
       ConsoleUI -> Handles the user interface and prints requested data onto the console.
       Scientist -> Handles the different variables stored within the program for scientists, i.e. name, sex, year of birth                       etc.
       ScientistService -> Handles the logic for the scientist class which the ConsoleUI class uses for its various                                      functions.
       Computer -> Handles the different variables stored within the program for computers, i.e. name, build year, type etc.
       ComputerService -> Handles the logic for the computer class which the ConsoleUI class uses for its various                                       functions.
       GeneralService -> Handles logic which are both usable for the scientists class and the computer class. Mostly for                                relation related functions.
       ScientistAccess -> Handles writing and reading of information to an sql database for the scientist class.
       ComputerAccess -> Handles writing and reading of information to an sql database for the computer class.
       LinkAccess -> Handles writing and reading of information to an sql database for the relation between computers and                          scientists.
       
       Main -> Runs the program

# Work
The authors divded themself into three teams and worked together on seperate classes to achieve maximum functionality in the program and to learn how to divide tasks into subtasks, divide them between the team and them link them alltogether.
The following authors worked on the following classes (atleast in the start, we changed it up when the project went along):</br>

       Every member of the group wrote some code in each of the classes.
       ReadMe File (Benedikt Þorri Þórarinsson, Helgi Hallgrímsson)

The team succesfully worked together and members contributed equally.


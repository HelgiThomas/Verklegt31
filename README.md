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
The instructions for this program are quite simple. The user is presented with a main menu where 8 commands are listed.
The brackets behind each command below contain possible input to enter each command.</br></br>

1. Add ("add", "Add", "1") - Adds scientist/computers/relations to the list.</br>
     1. Scientist ("scientist", "Scientist", "1")</br></br>
          Name: -User can enter name that contains alphabetical characters. First letter of each name (first, middle and last)           will become capital automatically. A blank, a space or any other characters that are not alphabetical will result in           an error message. </br></br></br>
     
          Sex: -User can input "m", "M", "male" or "Male" if the scientist is a male and "f", "F", "female" or "Female" if the           scientist is a female. User can also type "yes". User will have to see for him/herself what happens.</br></br>
     
          Birth:/Death: -User can type an integer that's below 2016(current year) for both input lines. For death the user can           only input an integer that's greater or equal than the year of birth. Any other characters as input will result in             an error.
          (Sidenote: the user is prompted for whether the scientist being entered is dead before prompted for year of death).            </br></br></br>
     
          Citation: -User is first prompted for whether desired to enter citation. The input for the citation can be of any             kind and any length.</br></br></br>
    
     2. Computer ("computer", "Computer", "2") </br></br>
          Name: -User can enter name that can contain any type of input. First letter is made capital, if alphabetical.</br>             </br></br>
          
          Build year: -User can input any year that is below 2016(current year). Any other input will result in an error.</br>           </br></br>
          
          Computer type: -User can enter a computer type that can contain any type of input.</br></br></br>
          
          WasBuilt: -User is asked whether the input computer was built or not. The input may be either Y for "Yes" or N for             "No". Any other input will result in an error.</br></br></br>
          
     3. Relation ("relation", "Relation", "3")</br></br>
          User is presented with a list of scientists and is asked to pick a scientist desired to make a relation with. The             input is the corresponding line number. After that, user is asked if it's desired to add another relation, to which           can replied a Y for yes or an N for "No". Then the user is presented with a list of computers which the user can               relate to the scientist that was chosen earlier. The user can relate a single or multiple computers with a single,             or multiple scientists vice versa.
     
     4. Back ("back", "Back", "4")
          Takes user back to main menu.
     
     
2. Remove ("remove", "Remove", "2") - Removes scientists/computers/relations from the list.</br>
     When one of the first three commands is selected, the user is presented with a list of elements (of what the user chose        to remove) all of whom are numbered. The user should then input a number of which element is desired to remove. It is          then removed from the list. The fourth command removes all scientists and the fifth command takes user back to the main        menu. Any other input then the ones mentioned between the brackets below will result in an error. </br></br>
     1. Scientist("scientist", "Scientist", "1") </br></br>
     2. Computer("computer", "Computer", "2")</br></br>
     3. Relation("relation", "Relation", "3")</br></br>
     4. Everyone("everyone", "Everyone", "4")</br></br>
     5. Back("back", "Back", "5")</br></br>
     
      
     
3. List ("list", "List", "3")</br>
     When one of the first three commands is selected it will display all elements of the chosen sort in the database in a          table. Any other input then the ones mentioned between the brackets below will result in an error.</br></br>
     1. Scientists("scientist", "Scientist", "1")</br></br>
     2. Computer("computer", "Computer", "2")</br></br>
     3. Relations("relations", "Relations", "3")</br></br>
     4. Back("back", "Back", "4")</br></br>
     
4. Edit ("edit", "Edit", "4")
     When one of the first three commands below is selected, the user is presented with a list of the elements that were            chosen, and is prompted for which of these elements the user desires to edit. The user is then presented with a prompt to      which attributes of that particular element is desired to change. The input for each element is its line number and the        input for the attribute is either its name or the number displayed in front of it. The last command takes the user back        to the main menu.</br></br>
     1. Scientist ("scientist", "Scientists", "1")</br></br>
     2. Computer ("computer", "Computer", "2")</br></br>
     3. Relation ("relation", "Relation", "3")</br></br>
     4. Back ("back", "Back", "4")</br></br>
     
     
      
5. Sort ("sort", "Sort", "4")</br>
      Displays a table containing sorted information about the scientists.</br></br>
      
      1. Scientists("scientist", "Scientist", "1")</br></br>
          
          1. Name ("name", "Name", "1")
               List is displayed in an alphabetical order.</br></br></br>
          2. Sex ("sex", "Sex", "2")
               List is displayed by sex. Females first, males second.</br></br></br>
          3. Birth ("birth", "Birth", "3")
               List is displayed by year of birth. Youngest first, oldest last.</br></br></br>
          4. Death ("death", "Death", "4")
               List is displayed by year of death. Those who died first, first and those who died last, last.</br></br></br>
      
      2. Computer("computer", "Computer", "2")</br></br>
          
          1. Name ("name", "Name", "1")
               List is displayed with computers in an alphabetical order. </br></br></br>    
          2. Year ("year", "Year", "2")
               List is displayed with oldest computers first, latest last.</br></br></br>
          3. Type ("type", "Type", "3")
               List is displayed with type in an alphabetical order.</br></br></br>
          4. Built ("built", "Built", "4")
               List is displayed by whether computers were built or not. Those that weren't built come first, then those that                weren't.</br></br></br>
          
      3. Back ("back", "Back", "3")</br></br>
          Takes user back to the main menu.</br></br></br>
               
6. Reversed Sort</br>
      Displays the list in the opposite order of what the Sort command does.</br></br>
      
7. Search</br>
      User can search for scientists on the list by name, sex, birth, death and for computers by name, build year, type and         whether it was built or not.</br></br>
      1. Scientist ("scientist", "Scientist", "1")</br></br>
          1. Name ("name", "Name", "1")
               User inputs part of name, from beginning, and gets all result that match that search query.</br></br>
          2. Sex ("sex", "Sex", "2")
               User inputs "f", "F", "female" or "Female" to locate all females and "m", "M", "male" or "Male" to locate all                  males.</br></br>
          3. Birth ("birth", "Birth", "3")
               User inputs year, and is prompted whether it's desired to get results that match years that are greater than,                  less than or equal to the input birth year. </br></br>
          4. Death ("death", "Death", "4")
               See: 3. Birth - same output, but for years that scientists died.</br></br>
      2. Computer ("computer", "Computer", "2")</br></br>
          1. Name ("name", "Name", "1")</br></br></br>
          2. Build year ("year", "Year", "2")</br></br></br>
          3. Computer type ("type", "Type", "3")</br></br></br>
          4. If it was built ("built", "Built", "4")</br></br></br>
          
      3. Back ("back", "Back", "3")</br></br>
          Takes user back to the main menu.</br></br></br>
          
          
8. Game ("game", "Game", "8")</br>  
     User can play two different games, one that lets you connect a scientist to a citation. And the other lets you connect computers and scientists.</br></br>
     1. Citation game("citation", "Citation", "1")</br></br>
          User plays a game where a citation is shown and the user has to connect the correct scientist to that citation. If he puts in the wrong answer, they correct answer will be shown.</br>
     2. Computer-Scientist Relation("relation", "Relation", "2")</br></br>
          User plays a game where he can connect the correct scientist to a computer or the correct computer to a scientist.</br>
               
9. Quit ("quit", "Quit", "9")</br>
      Exits the program.</br></br>





# The Program:
The program is divided into four classes to do its purpose.</br>
The classes are as follows:</br>
  
     Class:
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

       Consoleui (All authors, more or less)
       Scientist (All authors, more or less) 
       Computer (All authors, more or less)
       ScientistService (All authors, more or less)
       ComputerService (All authors, more or less)
       ScientistAccess (All authors, more or less)
       ComputerAccess (All authors, more or less)
       LinkAccess (Helgi Hallgrímsson, Emil Hjaltason)
       ReadMe File (Benedikt Þorri Þórarinsson, Helgi Hallgrímsson)

The team succesfully worked together and members contributed equally.


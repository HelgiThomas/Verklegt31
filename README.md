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

The program offers the required features: add, list, search and sort along with a couple of extra features. These extra features include reverse sorting, removing a scientist or a computer from the list, playing a quiz and quitting the program.</br>

# Instructions:
The instructions for this program are quite simple. The user is presented with a main menu were 9 commands are listed.
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
     When one of the first three commands is selected it will display all elements of the chosen sort in the database in a          table. Any other input then the ones mentioned between the brackets below will result in an error.
     1. Scientists("scientist", "Scientist", "1")</br></br>
     2. Computer("computer", "Computer", "2")</br></br>
     3. Relations("relations", "Relations", "3")</br></br>
     4. Back("back", "Back", "4")</br></br>
     
4. Edit ("edit", "Edit", "4")
     
      
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
          Takes user back to the main menu.
               
6. Reversed Sort</br>
      Displays the list in the opposite order of what the Sort command does.</br></br>
      
7. Search</br>
      User can search for scientist on the list by name, sex, birth, death.</br></br>
      1. Scientist ("scientist", "Scientist", "1")
          1. Name ("name", "Name", "1")
               User inputs part of name, from beginning, and gets all result that match that search query.
          2. Sex ("sex", "Sex", "2")
               User inputs "f", "F", "female" or "Female" to locate all females and "m", "M", "male" or "Male" to locate all                  males.
          3. Birth ("birth", "Birth", "3")
               User inputs year, and is prompted whether it's desired to get results that match years that are greater than,                  less than or equal to the input birth year. 
          4. Death ("death", "Death", "4")
               See: 3. Birth - same output, but for years that scientists died.
      2. Computer ("computer", "Computer", "2")
          1. Name ("name", "Name", "1")
          2. Build year ("", "", "2")
          3. Computer type ("", "", "3")
          4. If it was built ("", "", "4")
          
      3. Back ("back", "Back", "3")
          Takes user back to the main menu.
          
          
                
8. Game ("game", "Game", "7")</br>
      User is presented with a game, or more accurately, a quiz. The quiz presents a citation to which the user must name the       scientist to whom the citation matches. For a single question answered correctly, the user gets 1 point. For as long as       the program is running the score will be saved.</br></br>
      
9. Quit ("quit", "Quit", "8")</br>
      Exits the program.</br></br>





# The Program:
The program is divided into four classes to do its purpose.</br>
The classes are as follows:</br>
  
     Class:
       ConsoleUI -> Handles the user interface and prints requested data onto the console.
       Scientist -> Handles the different variables stored withing the program, i.e. name, sex, year of birth etc.
       ScientistService -> Handles the logic which the ConsoleUI function uses for its various functions.
       DataAccess - > Handles writing and reading of information from and to a .txt file.
       Main -> Runs the program

# Work
The authors divded themself into three teams and worked together on seperate classes to achieve maximum functionality in the program and to learn how to divide tasks into subtasks, divide them between the team and them link them alltogether.
The following authors worked on the following classes (atleast in the start, we changed it up when the project went along):</br>

       Consoleui (Benedikt Þorri Þórarinsson, Þorsteinn Sæmundsson)
       Scientist (All Authors)
       ScientisService (Kolbrún Hafdísardóttir, Sigrún Elva Reynisdóttir)
       Dataacess (Emil Hjaltason, Helgi Hallgrimsson)

The team succesfully worked together and members contributed equally.


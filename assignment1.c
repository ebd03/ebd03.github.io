/**********************************************************************************************************
 Program Description:
 Assignment 1 - Mathematics Quiz Game
 
 Program that will simulate a mathematics quiz game.
 The game will include various features.
 Program will be menu-driven and will display a main menu when run.
 The menu will include the following options:
 1. Enter the number of questions to be asked for this round of the quiz (maximum of 5 questions allowed).
 2. Start quiz
 3. Display the number of questions that were answered (i) correctly and (ii) incorrectly for this round.
 4. Exit Program
 
 Author:
 Eoghan Byrne
 C17315336
 
 Editor Used:                           Compiler Used:
 Sublime Text                           Xcode
 Version 3.0                            Version 9.0.1
 
 Created:                               Updated:
 1st November 2017                      10th November 2017
 
 Due:
 12th November 2017
 **********************************************************************************************************/



#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Using <time.h> to allow the random number generator to function
#define ROUND_MAX 5 // Using a define such that the rounds maximum can be altered quickly if the need arises
#define ERROR_CHECK 3 // Using a define such that the amount of error checks can be altered quickly if the need arises
#define RANDOM 3 // Using a define to create array



/**********************************************************************************************************
 Using the int clear_input_value() to reset the users input in the case of an error
 **********************************************************************************************************/

int clear_input_value()
{
    while (getchar()!='\n');
    return 1;
}



/**********************************************************************************************************
 Using the int main as the main body of the program
 **********************************************************************************************************/

int main()
{
    // Declaring all the necessary variables for the program to function
    // Every variables name is as such to be self explanatory of their purpose
    char menu_input;
    int amount_of_questions;
    int amount_of_questions_confirmation;
    int user_input;
    int questions_correct;
    int questions_incorrect;
    int round_complete;
    char error_check[ERROR_CHECK] = {'0'};
    int random[RANDOM] = {0};
    int i;
    
    
    
    // Initiating all of the above variables to the nessecary values
    // be it an integer or character
    menu_input = '0';
    amount_of_questions = 1;
    amount_of_questions_confirmation = 0;
    user_input = 0;
    questions_correct = 0;
    questions_incorrect = 0;
    round_complete = 0;
    i = 0;
    
    
    
    // Calling the srand command to create the random numbers
    srand(time(NULL));
    
    
    
    /**********************************************************************************************************
     Using a DO WHILE LOOP, this loop allows the program to run at least once
     This loop is also set to exit if the user enters 4 during the menu
     (As per the program requirements, entering 4 should exit the program)
     **********************************************************************************************************/
    
    do{
        // Resetting the required variables
        menu_input = '0';
        error_check[0] = '0';
        
        // Asking the user to input a number from the menu using printf and scanf
        printf("_____________________________________________________________________________\nWelcome to the Mathematics Quiz Game!\n\nPlease select one of the 4 options below:\n1.\tSelect the number of questions in the round (Default of 1 question)\n2.\tStart the Mathematics Game with %d round/s\n3.\tSee how many questions you got correct or incorrect\n4.\tEXIT the game\n_____________________________________________________________________________\n\n\n", amount_of_questions);
        
        // Using an IF ELSE statement for error checking
        // The IF condition is exspecting the user to enter a single string value followed by a non numeric character
        if((scanf("%1s%c", &menu_input, &error_check[0])!=2 || error_check[0]!='\n') && clear_input_value())
        {
            printf("You entered an Invaild Character\n\n\n\n");
        }
        else
        {
            /**********************************************************************************************************
             ----- Main body of the program -----
             **********************************************************************************************************/
            
            // State the SWITCH statement to allow the program to goto different sequences
            switch(menu_input)
            {
                /************** Case 1 **************/
                // Case '1' is user input 1 which is equivalent to the programs requirements for round selection
                case '1':
                {
                    // Resetting the required variables
                    amount_of_questions = 0;
                    amount_of_questions_confirmation = 0;
                    error_check[1] = '0';
                    
                    // Using a DO WHILE loop to ensure the users selection is between the min and max values
                    while (amount_of_questions_confirmation != 1)
                    {
                        // Asking the user to input the number of rounds for the game
                        printf("\n\n\n\nEnter the number of questions to be asked for this round of the quiz (Maximum of %d questions allowed)\n", ROUND_MAX);
                        
                        // Using an IF ELSE statement for error checking
                        // The IF condition is exspecting the user to enter a single integer value followed by a non numeric character
                        if((scanf("%d%c", &amount_of_questions, &error_check[1])!=2 || error_check[1]!='\n') && clear_input_value())
                        {
                            printf("You entered an Invaild Character\n");
                        }
                        else
                        {
                            // IF statement for ensuring the users selection
                            if (amount_of_questions <= ROUND_MAX && amount_of_questions > 0)
                            {
                                printf("\n\n\n\n");
                                amount_of_questions_confirmation++;
                            }
                            else
                            {
                                printf("You entered an Invaild Round Quanitity\n");
                            } // end inner if
                        } // end outer if
                    } // end while
                    
                    break;
                } // end case '1'
                    
                
                /************** Case 2 **************/   
                // Case '2' is user input 2 which is equivalent to the programs requirements for playing the round
                case '2':
                {
                    // Resetting the required variables
                    round_complete = 0;
                    questions_correct = 0;
                    questions_incorrect = 0;
                    error_check[2] = '0';
                    
                    // Presenting the user with the rounds instructions
                    printf("\n\n\n\nThis game will consist of %d rounds.\nAll answers will be whole numbers (Meaning no remainders)\n\n", amount_of_questions);
                    
                    // FOR LOOP to ask the number of rounds for the game
                    for (i = 0; i < amount_of_questions; ++i)
                    {
                        // Randomaly generating 2 numbers and adding them
                        random[0] = rand() % 21;
                        random[1] = rand() % 21;
                        random[2] = random[0] + random[1];
                        
                        // Presenting the user with the rounds questions
                        printf("Question %d.\t%d + %d =\n", i+1, random[0], random[1]); // Using i+1 to display the currect question round but increasing it by 1 due to the requirements of int being 0
                        
                        // Using an IF ELSE statement for error checking
                        // The IF condition is exspecting the user to enter a single integer value followed by a non numeric character
                        if((scanf("%d%c", &user_input, &error_check[2])!=2 || error_check[2]!='\n') && clear_input_value())
                        {
                            printf("You entered an Invaild Character\n\n\n");
                            i = i-1; // Subtracting 1 after a mistake to allow for a second chance without lose of points
                        }
                        else
                        {
                            // IF statment to see if the user got the round correct or incorrect
                            if (user_input == random[2])
                            {
                                printf("\nWell done you got that correct\n\n\n\n\n");
                                questions_correct++; // Increasing correct answers by 1
                            }
                            else
                            {
                                printf("\nSorry that was incorrect\n\tThe correct answer was %d\n\n\n\n\n", random[2]);
                                questions_incorrect++; // Increasing incorrect answers by 1
                            } // end inner if
                        } // end outer if
                        
                        // Setting the variable to 1, meaning the user has completed a round
                        round_complete = 1;
                    } // end for
                    
                    break;
                } // end case '2'
                    
                
                /************** Case 3 **************/    
                // Case '3' is user input 3 which is equivalent to the programs requirements for displaying the number of correct or incorrect rounds
                case '3':
                {
                    // IF statement to check if the user has completed a round or not
                    if (round_complete == 1)
                    {
                        printf("\n\n\n\n\nYou've just completed a game of %d round/s\nOut of those %d round/s\n\n", amount_of_questions, amount_of_questions);
                        printf("You got:\n\t\t %d Correct\t\t%d Incorrect\n\n\n\n\n", questions_correct, questions_incorrect);
                    }
                    else
                    {
                        printf("You have not completed a round\n\n\n\n");
                    } // end if
                    
                    break;
                } // end case '3'
                    
                
                /************** Case 4 **************/    
                // Case '4' is user input 4 which is equivalent to exiting the game
                // This section functions due to the printf occuring prior to the return 0; meaning the program will enter the
                //  switch statement, print the goodbye message, then exit the switch and exit the program
                case '4':
                {
                    printf("\n\n\n\n\n\n****************************************************************************\n*\n*  Thank you for playing the Mathematics Quiz Game\n*\tGoodbye\n*\n****************************************************************************\n\n");
                    
                    break;
                } // end case '4'
                    
                
                /************** Default **************/    
                // Telling the user they have entered an incorrect option from the menu list
                default:
                {
                    printf("\nYou entered an Invaild Option\n\n\n\n");
                } // end default
                
            } // end switch
        } // end if (menu error checking) 
    } // end do
    while(menu_input != '4');
    
    return 0;
    
} // end main
//
// Created by matth on 12/27/2017.
// The Mathematics Program by
// Matthew Strong, CU Boulder.
//

#include <iostream>
#include <fstream>
#include <random>
#include <math.h>
#include <string>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <cstdlib>
#include <stdlib.h>    /* srand, rand */
#include <ctime>       /* time */
#include "Mathematics.h"
#include <vector>
using namespace std;

// --------------------MATTHEW STRONG MATH PROGRAM----------------------------------------------------------------------


int Mathematics::Menu()
{
    // showing the user what they need to do

    cout << "++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "THE MATTHEW STRONG MATH PROGRAM VERSION 1.0" << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "Welcome to the Matthew Strong Math Program" << endl;
    cout << "This program will test out the math skills for those" << endl;
    cout << "" << endl;
    cout << "Wanting to hone their skills in math. Here we go." << endl;
    cout << "" << endl;
    cout << "First, we will create the Mathematics package, and if" << endl;
    cout << "" << endl;
    cout << "If you have any saved progress, you will able to load it on." << endl;
    cout << "" << endl;
    cout << "Here are the following options: " << endl;
    cout << "" << endl;
    cout << "Multiplication Practice (1)" << endl;
    cout << "" << endl;
    cout << "Division Practice (2)" << endl;
    cout << "" << endl;
    cout << "Addition Practice (3)" << endl;
    cout << "" << endl;
    cout << "Subtraction Practice (4)" << endl;
    cout << "" << endl;
    cout << "Insane Factorial Practice (5)" << endl;
    cout << "" << endl;
    cout << "Matrix Operations (6)" << endl;
    cout << "" << endl;
    cout << "Import Math (7)" << endl;
    cout << "" << endl;
    cout << "Exit (8)" << endl;
    cout << "If you want to load saved progress onto this platform, type in, 'yes'" << endl;
    cout << "Anything else that is typed will be ignored and assumed that you have no progress. " << endl;
    cout << "It is recommended, though, that you type no in this case." << endl;

    string entry;
    cin >> entry;
    if (entry == "yes")
    {
        // the user enters in the entry, if it is yes, then they can enter the filename of the saved progress
        // it will be a text file
        
        cout << "Alright, now enter the filename of your saved progress." << endl;
        cout << "For example, write 'progress.txt'." << endl;
        string file;
        cin >> file;
        ifstream myfile;
        myfile.open(file);
        string line;
        // opening a file with ifstream.
        if (myfile.is_open())
        {
            // if the file is open, set the amount of lines equal to 0; and get each line.
            int linet;
            linet = 0;
            cout << "The file successfully opened." << endl;
            while (!myfile.eof())
            {
                // if the linet variable is divisible by 2, then that means that we are importing a name, so we push back 
                // the line into the Names vector, or the database.
                // Otherwise, we have the line as a score, so we convert that to an int,
                // and put that into the other part of the database, the scores vector.
                getline(myfile, line);
                if (linet %2 == 0)
                {
                    Names.push_back(line);
                }
                else if (linet %2 == 1)
                {
                    int liner = stoi(line);
                    Scores.push_back(liner);
                }
                linet = linet +1;
            }
            cout << "We were able to load your saved progress of all the " << endl;
            cout << "participants into the database." << endl;
        }
        else
        {
            // outputs these statements if the file does not open.
            cout << "Uh oh, it looks like the file did not open." << endl;
            cout << "We will now move on." << endl;
        }
    }
    else
    {
        // that happens if the user does not say "yes" when asked about if they want to load saved progress.
        cout << "No need to enter in any files." << endl;
        cout << "" << endl;
    }

    int choice = 0;
    // now the user must choose the option in the program.

    while(choice == 0)
    {
        // while the choice is 0, the loops keeps iterating. 
        // The user enters in the number, and I use a switch statement here to select each option
        int number = 0;
        cout << "Now please enter the option you would like with the program." << endl;
        cin >> number;
        switch (number)
        {
            case 1:
            {
                cout << "Multiplication Practice Selected." << endl;

                choice = 1;
                // this break only breaks out of the switch statement, so we need to change the choice to break
                // out of the while loop.
                break;
            }

            case 2:
            {
                cout << "Division Practice Selected." << endl;
                choice = 2;
                break;
            }
            case 3:
            {
                cout << "Addition Practice Selected." << endl;
                choice = 3;
                break;
            }
            case 4:
            {
                cout << "Subtraction Practice Selected." << endl;
                choice = 4;
                break;
            }
            case 5:
            {
                cout << "Insane Factorial Practice Selected." << endl;
                choice = 5;
                break;
            }
            case 6:
            {
                cout << "Insanity Practice Selected." << endl;
                choice = 6;
                break;
            }
            case 7:
            {
                cout << "Import Math Selected." << endl;
                choice = 7;
                break;
            }
            case 8:
            {
                cout << "Exit Selected." << endl;
                choice = 8;
                break;
            }
            case 9:
            {
                cout << "Statistics Selected." << endl;
                choice = 9;
                break;
            }
            case 10:
            {
                cout << "Testing Selected." << endl;
                choice = 10;
                break;
            }

            default:
            {
                cout << "Invalid Choice Selected, try again." << endl;
                break;

            }
        }
    }
    cout << "Here we go!" << endl;
    // based on choice goes to different methods of the class
    if (choice == 1)
    {
        Multiplication();

    }
    else if (choice == 2)
    {
        Division();

    }
    else if (choice == 3)
    {
        Addition();

    }
    else if (choice == 4)
    {
        Subtraction();

    }
    else if (choice == 5)
    {
        Factorials();

    }
    else if (choice == 6)
    {
        Percents();

    }
    else if (choice == 7)
    {
        Import();

    }
    else if (choice == 8)
    {
        // this is the exit choice, will end the program
        cout << "Bye!" << endl;
        return 0;

    }
    else if (choice == 9)
    {
        Stats();

    }
    else if (choice == 10)
    {
        Testing();

    }
    return 0;

}

// constructor
Mathematics::Mathematics()
{
    cout << "New object successfully created!" << endl;
    cout << "Get ready as the program runs!" << endl;


}


// percent test
void Mathematics::Percents()
{
    cout << "This is the bonus part of this program." << endl;
    cout << "Here, every question  will be worth 4 points, they will be hard." << endl;
    cout << "Here, the questions are much harder than you would expect " << endl;
    cout << "Because they have percents to them. Good luck." << endl;
    cout << "How many questions would you like to have?" << endl;
    int amount;
    cin >> amount;
    // asks for user's amount
    cout << "Good choice, you choose " << amount << " questions. Good luck!" << endl;
    cout << "First however, enter in the name of the person that is doing these questions." << endl;
    cout << "If the person cannot be found, that means that this person is new, and as such, " << endl;
    cout << "Will be entered in the database." << endl;
    
    string person;
    cin >> person;
    // user writes in person's name
    cout << "" << endl;
    // index is the index of the current user
    
    int index;
    bool found = false;
    for (int i =0; i<int(Names.size()); i++)
    {
        // looping through the vector of Names, looking for the person entered in by the user.
        if (Names[i] == person)
        {
            cout << "Success! Person found in database!" << endl;
            cout << "No more needs to be done." << endl;
            index = i;
            found = true;
            // breaks the for loop if the person is found.
            break;
        }
    }
    if (found == false)
    {
        cout << "We were not able to find this person, so" << endl;
        cout << "This person will now be entered into the database." << endl;
        Names.push_back(person);
        Scores.push_back(0);
        index = int(Names.size())-1;
        // puts the new person into vectors, along with the starting score of 0
        // the index is the end of the vector, which is the size - 1.
        cout << person << " was successfully added to the database." << endl;
        cout << "Also, the default score for " << person << " is 0." << endl;
    }
    cout << "Alright, " << person << " the legend, here we go." << endl;
    int score = 0;
    // random seed
    srand(time(NULL));
    for (int i=0; i<amount; i++)
    {
        int rando;
        rando = rand() % 101;
        //random number between 0 and 100
        int sando;
        sando = rand() % 1001;
        // random number between 0 and 999
        float percent;
        percent = rando / 100.0;
        // percent is rando divided by 100
        float answer = sando * percent;
        // answer can be found by multiplying sando by percent
        cout << "What is " << rando << " percent of " << sando << "?" << endl;
        float result;
        cin >> result;
        // user enters their answer
        if (result == answer)
        {
            // if the actual answer and user's answer match, points are given
            cout << "Very impressive, getting the right answer" << endl;
            cout << "Takes a lot of strong math and attention to detail." << endl;
            cout << "You have earned 4 points!" << endl;
            // increases the score for the round and the overall score in the score vector at the user's 
            // specific index by 4
            Scores[index] = Scores[index] + 4;
            score = score +4;
        }
        else
        {
            // no points given
            cout << "We are sorry, that was not correct. Good try though." << endl;
        }


    }
    
    // displays score
    cout << "Alright, " << person << ", your score for this round was " << score << " points." << endl;
    cout << "You survived the madness of percents!" << endl;
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
    cout << "All of the scores will be saved onto a text file, so that you can reload progress" << endl;
    cout << "Whenever you want." << endl;
    cout << "First write a file to write your saved progress to: " << endl;
    string file;
    cin >> file;
    // ofstream where a user enters a file, text file, to save their progress to.
    ofstream myfile;
    myfile.open(file);
    // if the text file can be opened, we write all of the scores and user names to a file, every user
    if (myfile.is_open())
    {
        for (int z=0; z< int(Names.size()); z++)
        {
            myfile << Names[z] << endl;
            myfile << Scores[z] << endl;
        }
        cout << "Successfully Saved!" << endl;

    }
    else
    {
        // if file is not found, progress will not be saved for later
        cout << "File was not able to open, we are sorry." << endl;
        cout << "Progress was not saved." << endl;

    }


    cout << "Now, you will be sent back to the loading screen." << endl;
    // VERY important below: going to menu function so user can choose whatever they want, every method has this,
    // so that a user could play for as long as they want.
    Menu();






}

// multiplies random numbers between 0 and 12.
void Mathematics::Multiplication()
{
    //same methods as the other methods at the beginning
    cout << "How many questions would you like to have?" << endl;
    int amount;
    cin >> amount;
    cout << "Good choice, you choose " << amount << " questions. Good luck!" << endl;
    cout << "First however, enter in the name of the person that is doing these questions." << endl;
    cout << "If the person cannot be found, that means that this person is new, and as such, " << endl;
    cout << "Will be entered in the database." << endl;
    string person;
    cin >> person;
    cout << "" << endl;
    int index;
    bool found = false;
    for (int i =0; i<int(Names.size()); i++)
    {
        if (Names[i] == person)
        {
            cout << "Success! Person found in database!" << endl;
            cout << "No more needs to be done." << endl;
            index = i;
            found = true;
            break;
        }
    }
    if (found == false)
    {
        cout << "We were not able to find this person, so" << endl;
        cout << "This person will now be entered into the database." << endl;
        Names.push_back(person);
        Scores.push_back(0);
        index = int(Names.size())-1;
        cout << person << " was successfully added to the database." << endl;
        cout << "Also, the default score for " << person << " is 0." << endl;
    }
    cout << "Alright, " << person << " the legend, here we go." << endl;
    int score = 0;
    srand(time(NULL));
    // random seed


    for (int b=0; b<amount; b++)
    {
        int rando;
        rando = rand() % 13;
        // number between 0 and 12
        int first = rando;
        rando = rand() % 13;
        // another number between 0 and 12
        int second = rando;
        int answer;
        answer = first * second;
        // answer is just the first value times the second value
        cout << "What is " << first << " times " << second << "?" << endl;
        int result;
        cin >> result;
        if (answer == result)
        {
            cout << "Great job, correct!" << endl;
            if (answer >=100)
            {
                // harder question yields 2 points for a correct answer
                cout << "Because this was a harder question, 2 points will be added." << endl;
                Scores[index] = Scores[index] + 2;
                score = score +2;
            }
            else
            {
                cout << "One point will be added" << endl;
                Scores[index] = Scores[index] + 1;
                score = score + 1;
            }
        }
        else
        {
            cout << "Sorry, but the answer was not correct." << endl;
        }
    }

    cout << "Alright, " << person << ", your score for this round was " << score << " points." << endl;
    cout << "All of the scores will be saved onto a text file, so that you can reload progress" << endl;
    cout << "Whenever you want." << endl;
    cout << "First write a file to write your saved progress to: " << endl;
    // file to save progress for later
    string file;
    cin >> file;
    ofstream myfile;
    myfile.open(file);
    if (myfile.is_open())
    {
        for (int z=0; z< int(Names.size()); z++)
        {
            myfile << Names[z] << endl;
            myfile << Scores[z] << endl;
        }
        cout << "Successfully Saved!" << endl;

    }
    else
    {
        cout << "File was not able to open, we are sorry." << endl;
        cout << "Progress was not saved." << endl;

    }


    cout << "Now, you will be sent back to the loading screen." << endl;
    Menu();






}

// divides two values
void Mathematics::Division()
{
    cout << "How many questions would you like to have?" << endl;
    int amount;
    cin >> amount;
    cout << "Good choice, you choose " << amount << " questions. Good luck!" << endl;
    cout << "First however, enter in the name of the person that is doing these questions." << endl;
    cout << "If the person cannot be found, that means that this person is new, and as such, " << endl;
    cout << "Will be entered in the database." << endl;
    string person;
    cin >> person;
    cout << "" << endl;
    int index;
    bool found = false;
    for (int i =0; i<Names.size(); i++)
    {
        if (Names[i] == person)
        {
            cout << "Success! Person found in database!" << endl;
            cout << "No more needs to be done." << endl;
            index = i;
            found = true;
            break;
        }
    }
    if (found == false)
    {
        cout << "We were not able to find this person, so" << endl;
        cout << "This person will now be entered into the database." << endl;
        Names.push_back(person);
        Scores.push_back(0);
        index = int(Names.size())-1;
        cout << person << " was successfully added to the database." << endl;
        cout << "Also, the default score for " << person << " is 0." << endl;
    }
    cout << "Alright, " << person << " the legend, here we go." << endl;
    int score = 0;
    srand(time(NULL));
    for (int b=0; b<amount; b++)
    {
        int rando;
        // random value between 0 and 12
        rando = rand() % 13;
        // to avoid confusing division by 0
        rando = rando +1;
        int first = rando;
        rando = rand() % 13;
        
        // random value between 0 and 12
        int second = rando;
        int answer;
        // answer is first times second, so divisor is second if I ask for answer divided by first.
        answer = first * second;
        int divisor = second;
        cout << "What is " << answer << " divided by " << first << "?" << endl;
        int result;
        cin >> result;
        if (divisor == result)
        {
            cout << "Great job, correct!" << endl;
            if (divisor >=10)
            {
                // if answer is hard, more points given
                cout << "Because this was a harder question, 2 points will be added." << endl;
                Scores[index] = Scores[index] + 2;
                score = score +2;

            }
            else
            {
                cout << "One point will be added" << endl;
                Scores[index] = Scores[index] + 1;
                score = score + 1;
            }
        }
        else
        {
            // wrong answer gives no points
            cout << "Sorry, but the answer was not correct." << endl;
        }

    }


    cout << "Alright, " << person << ", your score for this round was " << score << " points." << endl;
    cout << "All of the scores will be saved onto a text file, so that you can reload progress" << endl;
    cout << "Whenever you want." << endl;
    cout << "First write a file to write your saved progress to: " << endl;
    string file;
    cin >> file;
    ofstream myfile;
    myfile.open(file);
    // saving progress onto file
    if (myfile.is_open())
    {
        for (int z=0; z< int(Names.size()); z++)
        {
            myfile << Names[z] << endl;
            myfile << Scores[z] << endl;
        }
        cout << "Successfully Saved!" << endl;

    }
    else
    {
        cout << "File was not able to open, we are sorry." << endl;
        cout << "Progress was not saved." << endl;

    }




    cout << "Now, you will be sent back to the loading screen." << endl;
    // goes onto file
    Menu();




}

// adds two random values
void Mathematics::Addition()
{
    cout << "How many questions would you like to have?" << endl;
    int amount;
    cin >> amount;
    cout << "Good choice, you choose " << amount << " questions. Good luck!" << endl;
    cout << "First however, enter in the name of the person that is doing these questions." << endl;
    cout << "If the person cannot be found, that means that this person is new, and as such, " << endl;
    cout << "Will be entered in the database." << endl;
    string person;
    cin >> person;
    cout << "" << endl;
    int index;
    bool found = false;
    for (int i =0; i<Names.size(); i++)
    {
        if (Names[i] == person)
        {
            cout << "Success! Person found in database!" << endl;
            cout << "No more needs to be done." << endl;
            index = i;
            found = true;

            break;
        }
    }
    if (found == false)
    {
        cout << "We were not able to find this person, so" << endl;
        cout << "This person will now be entered into the database." << endl;
        Names.push_back(person);
        Scores.push_back(0);
        index = int(Names.size())-1;
        cout << person << " was successfully added to the database." << endl;
        cout << "Also, the default score for " << person << " is 0." << endl;
    }
    cout << "Alright, " << person << " the legend, here we go." << endl;
    int score = 0;
    srand(time(NULL));
    for (int b=0; b<amount; b++)
    {
        // random value between 0 and 100
        int rando;
        rando = rand() % 101;
        int first = rando;
        rando = rand() % 101;
        int second = rando;
        int answer;
        answer = first + second;
        cout << "What is " << answer << " added to " << first << "?" << endl;
        int result;
        cin >> result;
        if (answer == result)
        {
            cout << "Great job, correct!" << endl;
            if (answer >=100)
            {
                // if the answer is hard and the user gets it right, more points are awarded
                cout << "Because this was a harder question, 2 points will be added." << endl;
                Scores[index] = Scores[index] + 2;
                score = score +2;

            }
            else
            {
                // easier question answered correctly yields 1 point
                cout << "One point will be added" << endl;
                Scores[index] = Scores[index] + 1;
                score = score + 1;
            }
        }
        else
        {
            cout << "Sorry, but the answer was not correct." << endl;
        }


    }


    cout << "Alright, " << person << ", your score for this round was " << score << " points." << endl;
    cout << "All of the scores will be saved onto a text file, so that you can reload progress" << endl;
    cout << "Whenever you want." << endl;
    cout << "First write a file to write your saved progress to: " << endl;
    string file;
    cin >> file;
    ofstream myfile;
    myfile.open(file);
    if (myfile.is_open())
    {
        for (int z=0; z< int(Names.size()); z++)
        {
            myfile << Names[z] << endl;
            myfile << Scores[z] << endl;
        }
        cout << "Successfully Saved!" << endl;

    }
    else
    {
        cout << "File was not able to open, we are sorry." << endl;
        cout << "Progress was not saved." << endl;

    }




    cout << "Now, you will be sent back to the loading screen." << endl;
    Menu();







}


// subtracts two random values, is harder than addition

void Mathematics::Subtraction()
{
    cout << "How many questions would you like to have?" << endl;
    int amount;
    cin >> amount;
    cout << "Good choice, you choose " << amount << " questions. Good luck!" << endl;
    cout << "First however, enter in the name of the person that is doing these questions." << endl;
    cout << "If the person cannot be found, that means that this person is new, and as such, " << endl;
    cout << "Will be entered in the database." << endl;
    string person;
    cin >> person;
    cout << "" << endl;
    int index;
    bool found = false;
    for (int i =0; i<Names.size(); i++)
    {
        if (Names[i] == person)
        {
            cout << "Success! Person found in database!" << endl;
            cout << "No more needs to be done." << endl;
            index = i;
            found = true;
            break;
        }
    }
    if (found == false)
    {
        cout << "We were not able to find this person, so" << endl;
        cout << "This person will now be entered into the database." << endl;
        Names.push_back(person);
        Scores.push_back(0);
        index = int(Names.size())-1;
        cout << person << " was successfully added to the database." << endl;
        cout << "Also, the default score for " << person << " is 0." << endl;
    }
    cout << "Alright, " << person << " the legend, here we go." << endl;
    int score = 0;
    srand(time(NULL));
    for (int b=0; b<amount; b++)
    {
        // random values between 0 and 100
        int rando;
        rando = rand() % 101;
        int first = rando;
        rando = rand() % 101;
        int second = rando;
        int answer;
        answer = first - second;
        cout << "What is " << answer << " subtracted from " << first << "?" << endl;
        int result;
        cin >> result;
        if (answer == result)
        {
            cout << "Great job, correct!" << endl;
            if (answer >=20)
            {
                // harder answer answered correctly gives 2 points
                cout << "Because this was a harder question, 2 points will be added." << endl;
                Scores[index] = Scores[index] + 2;
                score = score +2;

            }
            else
            {
                // else, one point is given
                cout << "One point will be added" << endl;
                Scores[index] = Scores[index] + 1;
                score = score + 1;
            }
        }
        else
        {
            // or wrong answer leads to points
            cout << "Sorry, but the answer was not correct." << endl;
        }


    }


    cout << "Alright, " << person << ", your score for this round was " << score << " points." << endl;
    cout << "All of the scores will be saved onto a text file, so that you can reload progress" << endl;
    cout << "Whenever you want." << endl;
    cout << "First write a file to write your saved progress to: " << endl;
    string file;
    cin >> file;
    ofstream myfile;
    myfile.open(file);
    // saves progress
    if (myfile.is_open())
    {
        for (int z=0; z< int(Names.size()); z++)
        {
            myfile << Names[z] << endl;
            myfile << Scores[z] << endl;
        }
        cout << "Successfully Saved!" << endl;

    }
    else
    {
        cout << "File was not able to open, we are sorry." << endl;
        cout << "Progress was not saved." << endl;

    }




    cout << "Now, you will be sent back to the loading screen." << endl;
    Menu();





}

// one of the hardest - factorials!

void Mathematics::Factorials()
{
    cout << "How many questions would you like to have?" << endl;
    int amount;
    cin >> amount;
    cout << "Good choice, you choose " << amount << " questions. Good luck!" << endl;
    cout << "First however, enter in the name of the person that is doing these questions." << endl;
    cout << "If the person cannot be found, that means that this person is new, and as such, " << endl;
    cout << "Will be entered in the database." << endl;
    string person;
    cin >> person;
    cout << "" << endl;
    int index;
    bool found = false;
    for (int i =0; i<Names.size(); i++)
    {
        if (Names[i] == person)
        {
            cout << "Success! Person found in database!" << endl;
            cout << "No more needs to be done." << endl;
            index = i;
            found = true;
            break;
        }
    }
    if (found == false)
    {
        cout << "We were not able to find this person, so" << endl;
        cout << "This person will now be entered into the database." << endl;
        Names.push_back(person);
        Scores.push_back(0);
        index = int(Names.size())-1;
        cout << person << " was successfully added to the database." << endl;
        cout << "Also, the default score for " << person << " is 0." << endl;
    }
    cout << "Alright, " << person << " the legend, here we go." << endl;
    int score = 0;
    srand(time(NULL));
    for (int b=0; b<amount; b++)
    {
        int rando;
        rando = rand() % 11;
        // random value between 0 and 10
        // adds one 
        rando = rando +1;
        int answer = 1;
        for (int i=1; i<=rando; rando++)
        {
       
            answer = answer * i;
            // loops to find the factorial of the random value 

        }
        cout << "What is the factorial of " << rando << "?" << endl;
        int result;
        cin >> result;
        if (result == answer)
        {
            if (rando >=7)
            {
                cout << "Wow! Great job! Here are two points for you1 " << endl;
                Scores[index] = Scores[index] + 2;
                score = score + 2;
                // more points for the user
            }
            else
            {
                cout << "Nice, here is a point!" << endl;
                Scores[index] = Scores[index] + 1;
                score = score + 1;
                // one point for the user

            }
        }
        else
        {
            cout << "That answer was not correct." << endl;

        }

    }

    cout << "Alright, " << person << ", your score for this round was " << score << " points." << endl;
    cout << "All of the scores will be saved onto a text file, so that you can reload progress" << endl;
    cout << "Whenever you want." << endl;
    cout << "First write a file to write your saved progress to: " << endl;
    string file;
    cin >> file;
    ofstream myfile;
    myfile.open(file);
    // saving progress
    if (myfile.is_open())
    {
        for (int z=0; z< int(Names.size()); z++)
        {
            myfile << Names[z] << endl;
            myfile << Scores[z] << endl;
        }
        cout << "Successfully Saved!" << endl;

    }
    else
    {
        cout << "File was not able to open, we are sorry." << endl;
        cout << "Progress was not saved." << endl;

    }




    cout << "Now, you will be sent back to the loading screen." << endl;
    Menu();





}

// Imports questions and answers of a textbook from a text file to vectors


void Mathematics::Import()
{
    cout << "Welcome to the Import section of the Mathematics Program." << endl;
    cout << "Here, the primary purpose of this section is to allow teachers or tutors to enter in" << endl;
    cout << "Their own questions to test students." << endl;
    cout << "To clarify, there is a specific format for each text file submitted to this part of the program." << endl;
    cout << "All of the questions and answers will be stored in a database and saved at the end of the running" << endl;
    cout << "Of this function." << endl;
    // clarifying the right format for a text file in the Import Method

    cout << "Here is what a sample text file should look like," << endl;
    cout << "Otherwise, the program will not run as desired." << endl;

    cout << "For example, we have: " << endl;
    cout << "Baby Bobby's Math Fun Book" << endl;
    cout << "What is the derivative of sin(x)?" << endl;
    cout << "cos(x)" << endl;
    cout << "What is 2 +2?" << endl;
    cout << "4" << endl;
    cout << "If a matrix has a non-zero determinant, is it invertible?" << endl;
    cout << "Yes" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "As you can see, this is necessary format. The first line is the title" << endl;
    cout << "For the other lines, they alternate with the question, followed by the answer." << endl;
    cout << "Now, please enter in the text file that you wish to put inside the database." << endl;
    // the user user enters the file and I use ifstream so that the file can be opened
    string filename;
    cin >> filename;
    cout << "We will now see if we can retrieve this file." << endl;
    ifstream myfile;
    myfile.open(filename);
    string line;
    if (myfile.is_open())
    {
        int linem = 0;
        getline(myfile, line);
        // reads the first line and puts it into the books vector before encountering any questions or answers
        Books.push_back(line);
        cout << "It looks like that the title of this book is " << line << "." << endl;
        while (! myfile.eof())
        {
            getline(myfile, line);
            if (linem %2 == 0)
            {
                // if the line is divisible by 2, then we are at a question, so the line, or question is added to the questions
                // vector
                
                Questions.push_back(line);
            }
            else if (linem %2 == 1)
            {
                Answers.push_back(line);
                // otherwise adding the answer line
            }
            linem = linem +1;

        }
        cout << "We were successful in putting the questions and the answers into the database." << endl;
        cout << "Now to send you back to the menu." << endl;
        Menu();
        //going to menu if file is open

    }
    else
    {
        // if file does not open
        cout << "We were not able to retrieve the file." << endl;
        cout << "Please try again." << endl;


    }

}


void Mathematics::Stats()
{
    cout << "Here is the statistics portion of the program." << endl;
    cout << "Here, you can look up the stats for a person." << endl;
    cout << "Also, you will able to see a leaderboard of who is leading" <<  endl;
    cout << "All of the mathematicians" << endl;
    cout << "This being said, would you like to (1) look up a user's statistics or" << endl;
    cout << "(2) see the current standing of top users by score?" << endl;
    cout << "Please enter 1 or 2." << endl;
    int answer;
    cin >> answer;
    bool valid = false;
    while (valid == false)
    {

        if (answer == 1)
        {
            cout << "Nice, who would you like to look up?" << endl;
            string user;
            cin >> user;
            bool found = false;
            for (int i=0; i<int(Names.size()); i++)
            {
                if (user == Names[i])
                {
                    // looks up for the user based on what the person types in
                    // outputs the user and their score
                    cout << "User found" << endl;
                    int scoreindex = i;
                    int scorer;
                    scorer = Scores[scoreindex];
                    cout << "The score for " << user << " is " << scorer << endl;
                    found = true;
                    valid = true;
                    break;
                }
            }
            if (found == false)
            {
                // if the user is not found, no scores or anything data-wise can be displayed
                cout << "We were not able to found this user; they have" << endl;
                cout << "Not been entered in the database." << endl;
                cout << "We would recommend going to another aspect of the program" << endl;
                cout << "And enter in the user. The only way to have a new user is for them" << endl;
                cout << "To engage in one of the mathematics activities." << endl;
            }
            valid = true;
            break;


        }
        else if (answer == 2)
        {
            // leaderboard for all the users
            cout << "Here are all of the users ranked so far." << endl;
            vector<string> Namer;
            vector<int> Scorer;
            for (int i=0; i<int(Names.size()); i++)
            {
                Namer.push_back(Names[i]);
                Scorer.push_back(Scores[i]);
                // creates copies of name and score vectors
            }
            int fix;
            string change;
            for (int b=0; b<Namer.size(); b++)
            {
                for (int z=0; z<Namer.size(); z++)
                {
                    if (Namer[z] < Namer[z+1])
                    {
                        // bubble sort to sort the name and score vectors
                        fix = Scorer[z+1];
                        Scorer[z+1] = Scorer[z];
                        Scorer[z] = fix;

                        change = Namer[z+1];
                        Namer[z+1] = Namer[z];
                        Namer[z] = change;
                    }
                }
            }
            int n =1;
            for (int c = 0; c<Namer.size(); c++)
            {
                // this way, the highest values are at the front, so we can display it leaderboard style
                cout << n << ". " << Namer[c] << ": " << Scorer[c] << endl;
                n = n +1;
            }


            valid = true;
            break;

        }
        else
        {
            // if valid choice not selected, not 1 or 2
            cout << "Valid choice not selected, try again." << endl;
        }

    }
    cout << "Now, you will be taken to the main menu. Hopefully, " << endl;
    cout << "This section was helpful for you!" << endl;
    Menu();
    // going back to the menu

}

// method that is similar to the import method in the sense that it takes all of the questions from the
// the question and answer vectors and asks these questions to users
void Mathematics::Testing()
{
    cout << "Time to test your true skills with the questions from the " << endl;
    cout << "" << endl;
    cout << "Database! Good luck, these questions might be hard!" << endl;
    cout << "In this case, two points are given for each correctly answered question." << endl;

    cout << "First,how many questions would you like to have?" << endl;
    int amount;
    cin >> amount;
    cout << "Good choice, you choose " << amount << " questions. Good luck!" << endl;
    cout << "First however, enter in the name of the person that is doing these questions." << endl;
    cout << "If the person cannot be found, that means that this person is new, and as such, " << endl;
    cout << "Will be entered in the database." << endl;
    string person;
    cin >> person;
    cout << "" << endl;
    int index;
    // looking up or creating new user
    bool found = false;
    for (int i =0; i<Names.size(); i++)
    {
        if (Names[i] == person)
        {
            cout << "Success! Person found in database!" << endl;
            cout << "No more needs to be done." << endl;
            index = i;
            found = true;
            break;
        }
    }
    if (found == false)
    {
        cout << "We were not able to find this person, so" << endl;
        cout << "This person will now be entered into the database." << endl;
        Names.push_back(person);
        Scores.push_back(0);
        index = int(Names.size())-1;
        cout << person << " was successfully added to the database." << endl;
        cout << "Also, the default score for " << person << " is 0." << endl;
    }
    cout << "Alright, " << person << " the legend, here we go." << endl;
    cout << "-------------------------------------------" << endl;
    cout << "You will be given randomly assigned questions from the databases." << endl;
    int score = 0;
    srand(time(NULL));
    for (int b=0; b<amount; b++)
    {
        // this random number is based on a random index in the questions vector
        
        int rando;
        rando = rand() % (int(Questions.size()));
        cout  << Questions[rando] << endl;
        // asks  random question
        cout << "This question is for TWO points!" << endl;
        cout << "Please enter in your answer in correct English format." << endl;
        cout << "My answer is: " << endl;
        // asks for user's answer
        string ans;
        cin >> ans;
        // if answer is same as the answer to that random question
        if (ans == Answers[rando])
        {
            cout << "Impressive! You got it right! That's 2 points for you!" << endl;
            // two points
            Scores[index] = Scores[index] + 2;
            score = score +2;

        }
        else
        {
            // ... or no points
            cout << "That is incorrect. Sorry, " << person << "." << endl;

        }

    }







    cout << "Alright, " << person << ", your score for this round was " << score << " points." << endl;
    cout << "All of the scores will be saved onto a text file, so that you can reload progress" << endl;
    cout << "Whenever you want." << endl;
    cout << "First write a file to write your saved progress to: " << endl;
    // saving progress, as with the other methods in the Mathematics class
    string file;
    cin >> file;
    ofstream myfile;
    myfile.open(file);
    if (myfile.is_open())
    {
        for (int z=0; z< int(Names.size()); z++)
        {
            myfile << Names[z] << endl;
            myfile << Scores[z] << endl;
        }
        cout << "Successfully Saved!" << endl;

    }
    else
    {
        cout << "File was not able to open, we are sorry." << endl;
        cout << "Progress was not saved." << endl;

    }


    cout << "Now, you will be sent back to the loading screen." << endl;
    Menu();




}

// That is all 
// BAC


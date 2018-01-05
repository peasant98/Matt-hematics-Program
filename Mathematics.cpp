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
        if (myfile.is_open())
        {
            int linet;
            linet = 0;
            cout << "The file successfully opened." << endl;
            while (!myfile.eof())
            {
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
            cout << "Uh oh, it looks like the file did not open." << endl;
            cout << "We will now move on." << endl;
        }
    }
    else
    {
        cout << "No need to enter in any files." << endl;
        cout << "" << endl;
    }

    int choice = 0;

    while(choice == 0)
    {
        int number = 0;
        cout << "Now please enter the option you would like with the program." << endl;
        cin >> number;
        switch (number)
        {
            case 1:
            {
                cout << "Multiplication Practice Selected." << endl;

                choice = 1;
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


Mathematics::Mathematics()
{
    cout << "New object successfully created!" << endl;
    cout << "Get ready as the program runs!" << endl;


}



void Mathematics::Percents()
{
    cout << "This is the bonus part of this program." << endl;
    cout << "Here, every question  will be worth 4 points, they will be hard." << endl;
    cout << "Here, the questions are much harder than you would expect " << endl;
    cout << "Because they have percents to them. Good luck." << endl;
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
    for (int i=0; i<amount; i++)
    {
        int rando;
        rando = rand() % 101;
        int sando;
        sando = rand() % 1000;
        float percent;
        percent = rando / 100.0;
        float answer = sando * percent;
        cout << "What is " << rando << " percent of " << sando << "?" << endl;
        float result;
        cin >> result;
        if (result == answer)
        {
            cout << "Very impressive, getting the right answer" << endl;
            cout << "Takes a lot of strong math and attention to detail." << endl;
            cout << "You have earned 4 points!" << endl;
            Scores[index] = Scores[index] + 4;
            score = score +4;
        }
        else
        {
            cout << "We are sorry, that was not correct. Good try though." << endl;
        }


    }
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


void Mathematics::Multiplication()
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


    for (int b=0; b<amount; b++)
    {
        int rando;
        rando = rand() % 13;
        int first = rando;
        rando = rand() % 13;
        int second = rando;
        int answer;
        answer = first * second;
        cout << "What is " << first << " times " << second << "?" << endl;
        int result;
        cin >> result;
        if (answer == result)
        {
            cout << "Great job, correct!" << endl;
            if (answer >=100)
            {
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
        rando = rand() % 13;
        int first = rando;
        rando = rand() % 13;
        int second = rando;
        int answer;
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
        rando = rando +1;
        int answer = 1;
        for (int i=1; i<=rando; rando++)
        {
            answer = answer * i;

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
            }
            else
            {
                cout << "Nice, here is a point!" << endl;
                Scores[index] = Scores[index] + 1;
                score = score + 1;

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


void Mathematics::Import()
{
    cout << "Welcome to the Import section of the Mathematics Program." << endl;
    cout << "Here, the primary purpose of this section is to allow teachers or tutors to enter in" << endl;
    cout << "Their own questions to test students." << endl;
    cout << "To clarify, there is a specific format for each text file submitted to this part of the program." << endl;
    cout << "All of the questions and answers will be stored in a database and saved at the end of the running" << endl;
    cout << "Of this function." << endl;

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
        Books.push_back(line);
        cout << "It looks like that the title of this book is " << line << "." << endl;
        while (! myfile.eof())
        {
            getline(myfile, line);
            if (linem %2 == 0)
            {
                Questions.push_back(line);
            }
            else if (linem %2 == 1)
            {
                Answers.push_back(line);
            }
            linem = linem +1;

        }
        cout << "We were successful in putting the questions and the answers into the database." << endl;
        cout << "Now to send you back to the menu." << endl;
        Menu();

    }
    else
    {
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
            cout << "Here are all of the users ranked so far." << endl;
            vector<string> Namer;
            vector<int> Scorer;
            for (int i=0; i<int(Names.size()); i++)
            {
                Namer.push_back(Names[i]);
                Scorer.push_back(Scores[i]);
            }
            int fix;
            string change;
            for (int b=0; b<Namer.size(); b++)
            {
                for (int z=0; z<Namer.size(); z++)
                {
                    if (Namer[z] < Namer[z+1])
                    {
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
                cout << n << ". " << Namer[c] << ": " << Scorer[c] << endl;
                n = n +1;
            }


            valid = true;
            break;

        }
        else
        {
            cout << "Valid choice not selected, try again." << endl;
        }

    }
    cout << "Now, you will be taken to the main menu. Hopefully, " << endl;
    cout << "This section was helpful for you!" << endl;
    Menu();

}


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
        int rando;
        rando = rand() % (int(Questions.size()));
        cout  << Questions[rando] << endl;
        cout << "This question is for TWO points!" << endl;
        cout << "Please enter in your answer in correct English format." << endl;
        cout << "My answer is: " << endl;
        string ans;
        cin >> ans;
        if (ans == Answers[rando])
        {
            cout << "Impressive! You got it right! That's 2 points for you!" << endl;
            Scores[index] = Scores[index] + 2;
            score = score +2;

        }
        else
        {
            cout << "That is incorrect. Sorry, " << person << "." << endl;

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


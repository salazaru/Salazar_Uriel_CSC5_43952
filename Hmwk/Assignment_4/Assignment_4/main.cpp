//File: main.cpp
//==========================================================================
//Programmer: Uriel Salazar
//==========================================================================
//Created: April 6, 2015, 10:17 AM
//==========================================================================
//Purpose: 10 problems utilizing a menu with a do-while loop and a switch
//==========================================================================

//System Libraries
#include <iostream>     //Input/Output Library
#include <iomanip>      //Parametric Library
#include <string>       //String Library
#include <cstdlib>      //General Utilites Library
#include <ctime>        //Time Library
using namespace std;    //Input/Output Library under standard name space

//User Libraries

//Global Constants
const short MONTHS = 12;        // Number of months in a year  
const float CNVPCNT = 100.0f;   //Convert to a percentage

//Function Prototypes
void dst_tld();
void pen_pay();
void a_rnfal();
void poplatn();
void sl_chrt();
void numGame();
void sqDsply();

//Execution Begins
int main()
{
    //Declare menu variable choice
    char choice, another;
    
    //Repeat the menu
    do
    {
        //Display the menu
        cout << "\n";
        cout << setw(25) << "* CSC5 Assignment 4 *\n";
        cout << setw(25) << "---------------------\n";
        cout << "A. \"Distance Traveled\"\n";
        cout << "B. \"Pennies for Pay\"\n";
        cout << "C. \"Average Rainfall\"\n";
        cout << "D. \"Population\"\n";
        cout << "E. \"Sales Bar Chart\"\n";
        cout << "F. \"Random Number Guessing Game\"\n";
        cout << "G. \"Square Display\"\n";
        cout << "H. \"Pattern Displays\"\n";
        cout << "I. \"Gravitational Force\"\n";
        cout << "J. \"Deep-Fried Twinkie Vending Machine\"\n";
        cout << "\nEnter any other key to exit the program.\n\n";
        
        //Prompt for input
        cout << "Which problem would you like to solve? ";
        cin >> choice;        
        
        //Conditions for exiting the program
        if (choice != 'A' && choice != 'a' && choice != 'B' && choice != 'b' &&
            choice != 'C' && choice != 'c' && choice != 'D' && choice != 'd' &&
            choice != 'E' && choice != 'e' && choice != 'F' && choice != 'f' &&
            choice != 'G' && choice != 'g' && choice != 'H' && choice != 'h' &&
            choice != 'I' && choice != 'i' && choice != 'J' && choice != 'j')
        {
            cout << "\nGood-bye!" << endl;
            return 0;
        }
        else
        {
            cout << "\n\n";
        }
        
        //Solve a problem that has been chosen
        switch (choice)
        {           
            case 'A' : dst_tld(); break;
            case 'a' : dst_tld(); break;
            case 'B' : pen_pay(); break;
            case 'b' : pen_pay(); break;
            case 'C' : a_rnfal(); break;
            case 'c' : a_rnfal(); break;
            case 'D' : poplatn(); break;
            case 'd' : poplatn(); break;
            case 'E' : sl_chrt(); break;
            case 'e' : sl_chrt(); break;
            case 'F' : numGame(); break;
            case 'f' : numGame(); break;
            case 'G' : sqDsply(); break;
            case 'g' : sqDsply(); break;
        };
        
       //Prompt for another solution
       cout << "\nWould you like to solve another problem? (Y/N) ";
       cin >> another;
    } while (another == 'Y' || another == 'y');
    if (another != 'Y' || another != 'y')
    {
        cout << "\nGood-bye!" << endl;
    }
    
    //Exit Program
    return 0;
}

//************************** Distance Traveled *******************************//
void dst_tld()
{
    //Declare Variables
    float vSpeed, hrs, dstance;

    //prompt user for input & validate
     cout << setw(43) << "* Distance Traveled *\n";
     cout << setw(43) << "---------------------\n";
     cout << "This program breaks up a vehicle's journey into intervals based"
             "\non the speed and amount of time traveled.\n";
     cout << "\nPlease enter the speed of the vehicle in miles per hour: ";
     while (!(cin >> vSpeed) || (vSpeed < 0))
     {
         cout << "\nERROR: Speed must be a nonnegative number: ";
         cin.clear();
         cin.ignore(1e9, '\n');
     }
     cout << "\nPlease enter the total time traveled in hours: ";
     while (!(cin >> hrs) || (hrs < 1))
     {
         cout << "\nERROR: Time traveled must be greater than 1 hour: ";
         cin.clear();
         cin.ignore(1e9, '\n');
     }
     cout << "\n";
     cout << setw(43) << "Hour   Distance Traveled\n";
     cout << setw(43) << "----   -----------------\n";
     
     //Loop to break the hours into intervals
     for (int i = 1; i <= hrs; i++)
     {
         //Calculate distance
         dstance = vSpeed * i;
         
         //Output the results
         cout << setw(21) << i << setw(14) << dstance << endl;
     }
     cout << "\n";
}

//************************** Pennies for Pay *******************************//
void pen_pay()
{
    //Declare Variables
    int nDays;
    double salary, total;

    //prompt user for input & validate
    cout << setw(39) << "* Pennies for Pay *\n";
    cout << setw(39) << "-------------------\n";
    cout << "Due to the new \"Penny Act\" proposed by the US Federal Government"
            ",\nyour salary will start out at 1 penny, and double for each day"
            "\nworked. This program will display your payment schedule.\n";
    cout << "\nPlease enter the number of days you plan to work: ";
    while (!(cin >> nDays) || (nDays < 0))
    {
        cout << "\nERROR: Days worked must be a nonnegative number: ";
        cin.clear();
        cin.ignore(1e9, '\n');
    }
    cout << "\n";
    cout << setw(39) << "Day        Salary \n";
    cout << setw(39) << "---       --------\n";
    
    //Initialize "salary" and "total"
    salary = 0.01, total = 0;
       
    //Loop the number of days
    for (int i = 1; i <= nDays; i++)
    {   
        cout << setprecision(2) << fixed;
        cout << setw(22) << i << setw(10) << "$" << salary << endl;
        
        //Add all payments
        total += salary;
        
        //Double the salary each day
        salary *= 2;
    }
    
    //Output the total pay
    cout << "\nYour total amount earned over " << nDays << " days will be: $" 
         << total << endl;
    cout << "\n";
}

//************************** Average Rainfall *******************************//
void a_rnfal()
{
    //Declare Variables
    short nYears, nMonths;
    float inches, tRain, aveRain;
    string mNames[MONTHS] =
    {
        "January", "February", "March", "April", "May", "June", "July",
        "August", "September", "October", "November", "December"
    };
    
    //prompt user for input & validate
     cout << setw(38) << "* Average Rainfall *\n";
     cout << setw(38) << "--------------------\n";
     cout << "California is currently undergoing the greatest drought in"
             "\nhistory. This program calculates the average rainfall in"
             "\nrecent years. Enter any amount of years before 2015: ";
     while (!(cin >> nYears) || (nYears < 1))
     {
         cout << "\nERROR: You must enter at least one year."
                 "\nRe-enter the amount of years: ";
         cin.clear();
         cin.ignore(1e9, '\n');
     }
     
     //Initialize the total rainfall
     tRain = 0;
     
     //Loop the amount of years and months
     for (int i = 1; i <= nYears; i++)
     {
         cout << "\nYear " << i << ":\n";
         for (int j = 0; j < MONTHS; j++)
         {
             cout << "How many inches of rainfall did it rain in " << mNames[j]
                  << "? ";
             while (!(cin >> inches) || (inches < 0))
             {
                 cout << "\nERROR: Inches must be a positive value."
                         "\nRe-enter the amount of inches: ";
                 cin.clear();
                 cin.ignore(1e9, '\n');
             }
             //Count the total amount of rain 
             tRain += inches;
         } 
     }
     
     //calculate the number of months and the average rainfall
     nMonths = nYears * 12;
     aveRain = tRain / nMonths;
     
     //Output the results
     cout << setprecision(2) << fixed;
     cout << "\n";
     cout << "Number of months: " << nMonths << endl;
     cout << "Total inches of rainfall: " << tRain << endl;
     cout << "California's average rainfall for the past " << nYears <<
             " years: " << aveRain << " in./month." << endl;
     cout << "\n";
}

//****************************** Population *********************************//
void poplatn()
{
    //Declare Variables
    float cPopltn;      //Current population
    float dIncrse;      //Daily Increase
    float nDays;        //Number of days to multiply by
    float pGrowth;      //Population Growth

    //prompt user for inputs & validate
    cout << setw(37) << "* Population *\n";
    cout << setw(37) << "--------------\n";
    cout << "The population of Sphaerodactylus ariasae (Dwarf Gecko) is"
            "\nsuspected to have a large increase in population over the next"
            "\nfew years. This program will calculate and display the rise of"
            "\norganisms per day.";
    cout << "\nEnter the current population size to the nearest gecko: ";
    while (!(cin >> cPopltn) || (cPopltn < 2))
    {
        cout << "\nERROR: The current population can be no less than 2: "
                "\nRe-enter the current population size: ";
        cin.clear();
        cin.ignore(1e9, '\n');
    }
    cout << "\nEnter the average percentage of the daily growth rate: ";
    while (!(cin >> dIncrse) || (dIncrse < 0))
    {
        cout << "\nERROR: The average percentage must be a positive value: "
                "\nRe-enter the average percentage: ";
        cin.clear();
        cin.ignore(1e9, '\n');
    }
    cout << "\nEnter the number of days to calculate: ";
    while (!(cin >> nDays) || (nDays < 0))
    {
        cout << "\nERROR: The number of days can be no less than 1: "
                "\nRe-enter the number of days: ";
        cin.clear();
        cin.ignore(1e9, '\n');
    }
    
    //Display table
    cout << "\n";
    cout << setw(41) << "Day      Population\n";
    cout << setw(41) << "---      ----------\n";
    cout << setprecision(0) << fixed;
    
    //Loop the calculation of the population for each day
    for (int i = 1; i <= nDays; i++)
    {
        //Calculate population growth
        pGrowth = cPopltn + (dIncrse / CNVPCNT * cPopltn);
        
        //The current population is now the population Growth
        cPopltn = pGrowth;
        
        //Output the results
        cout << setw(23) << i << setw(14) << pGrowth << endl;
    }
    cout << "\n";
}

//************************* Sales Bar Chart **********************************//
void sl_chrt()
{
    //Declare Variables
    int sales1 = 1, sales2 = 1, sales3 = 1, sales4 = 1, sales5 = 1;
    int div1, div2, div3, div4, div5;
    
    //Prompt user for inputs
    cout << setw(38) << "* Sales Bar Chart *\n";
    cout << setw(38) << "-------------------\n";
    cout << "\"Orange Software, Inc.\" has 5 divisions located in the U.S. This"
            "\nprogram creates a visual representation of the daily sales for"
            "\neach location." << endl;
    cout << "Enter today's sales for the San Francisco division: $";
    cin >> div1;
    cout << "Enter today's sales for the Chicago division: $";
    cin >> div2;
    cout << "Enter today's sales for the Seattle division: $";
    cin >> div3;
    cout << "Enter today's sales for the New York division: $";
    cin >> div4;
    cout << "Enter today's sales for the Austin division: $";
    cin >> div5;
    cout << "\n";
    
    //Format inputs
    sales1 = div1 / 100;
    sales2 = div2 / 100;
    sales3 = div3 / 100;
    sales4 = div4 / 100;
    sales5 = div5 / 100;
    
    //Loop each division to determine amount of asterisks
    cout << setw(38) << "ORANGE SOFTWARE, INC" << endl;
    cout << setw(36) << "(Each * = $100)" << endl;
    cout << setw(26) << "San Francisco: ";
    while (sales1 >= 1)
    {
        cout << "*";
        sales1--;
    }
    cout << "\n";
    cout << setw(26) << "Chicago: ";
    while (sales2 >= 1)
    {
        cout << "*";
        sales2--;
    }
    cout << "\n";
    cout << setw(26) << "Seattle: ";
    while (sales3 >= 1)
    {
        cout << "*";
        sales3--;
    }
    cout << "\n";
    cout << setw(26) << "New York: ";
    while (sales4 >= 1)
    {
        cout << "*";
        sales4--;
    }
    cout << "\n";
    cout << setw(26) << "Austin: ";
    while (sales5 >= 1)
    {
        cout << "*";
        sales5--;
    }
    cout << "\n";
}

//************************* Sales Bar Chart **********************************//
void numGame()
{
    //Declare Variables
    unsigned short rNumber;     //Random number
    unsigned short guess;       //User's input (guess)

    //Seed the random number generator
    srand(time(0));
    
    //Generate random number
    rNumber = (rand() % 99) + 1;
    
    
    //Prompt user for input
    cout << setw(42) << "* Random Number Guessing Game *\n";
    cout << setw(42) << "-------------------------------\n";
    cout << "A secret number has been generated! This program will determine"
            "\nwhether your input is greater than or less than that of the"
            "\nsecret number.";
    cout << "\nEnter a number form 1 - 100: ";
    cin >> guess;
    
    //Loop until number is guessed correctly
    do
    {
        if (guess > rNumber)
        {
            cout << "Too High, try again: ";
            cin >> guess;
        }
        else if (guess < rNumber)
        {
            cout << "Too low, try again: ";
            cin >> guess;
        } 
    } while (guess != rNumber);
    
    //Display winning message
    cout << "\nCongratulations! You've successfully guessed the secret number!";
    cout << "\n";
}

//***************************** Square Display *******************************//
void sqDsply()
{
    //Declare Variables
    short size;
    
    //Prompt user for input
    cout << setw(42) << "* Square Display *\n";
    cout << setw(42) << "------------------\n";
    cout << "This program displays the shape of a square whose length and width"
            "\nis determined by the user's input.";
    cout << "\nEnter a number from 1 - 15: ";
    
    //Validate Input
    while (!(cin >> size) || (size < 1) || (size > 15))
    {
        cout << "\nERROR: Value is not an integer from 1 - 15."
                "\nRe-enter the number: ";
        cin.clear();
        cin.ignore(1e9, '\n');
    }

    //Begin Looping the character "X"
    cout << endl;
    for (int i = 1; i <= size; i++)
    {
        cout << setw(30);
        for (int j = 1; j <= size; j++)
        {
            cout << "X";
        }
        cout << endl;
    }
}
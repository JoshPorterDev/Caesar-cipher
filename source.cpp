#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>

/*
Name: Josh Porter
Date: 10/10/20
Description: Allows the user to encrypt and decrypt messages using ceasar
*/

using namespace std;

void encode();
// Encodes a string message from the user and outputs the encoded message

void decode();
// Prompts the user for and encoded message and displays all possible (25)
// Decoded plain text 

int main()
{
    string choice;

    do
    {
        cout << "++++++++Caesar Cypher++++++++\n\n";
        cout << "1. \tEncode\n";
        cout << "2. \tDecode\n";
        cout << "3. \tQuit\n\n";
        cout << "Select a menu option: ";

        // Read in user's choice
        getline(cin, choice);

        if (choice == "1")
        {
            encode();
        }
        else if (choice == "2")
        {
            decode();
        }
        else if (choice == "3")
        {
            exit(3);
        }
        else
        {
            cout << "Invalid choice. Choose 1 2 or 3.\n";
        }
        
    } while (choice != "3");
    

    return 0;
}

void encode()
{
    // Declare variables
    string message;
    srand(time(0));
    int randomNum = rand() % 25 + 1;
    char c;

    // Test
    // cout << "The random number is: " << randomNum << endl;

    // Prompt user for message
    cout << endl;
    cout << "Type a message to encode: ";
    getline(cin, message);

    for (int i = 0; i < message.length(); i++)
    {
        // get rid of spaces
        if(isalpha(message.at(i)))
        {
            c = toupper(message.at(i));
            c = (((c - 65) + randomNum) % 26) + 65;
        }
        else 
        {
            c = message.at(i);
        }

        cout << c;
    }

    cout << endl << endl;
}

void decode()
{
    int possibleDecodeNums = 26;
    string message;
    char c;

    // Prompt user for message
    cout << endl;
    cout << "Type a message to decode: \n";
    getline(cin, message);

    // Start loop with j at one
    // Zero would just print back the decoded message with no change
    for (int j = 1; j < possibleDecodeNums; j++)
    {
        for (int i = 0; i < message.length(); i++)
        {
            // Get rid of spaces
            if (isalpha(message.at(i)))
            {
                c = toupper(message.at(i));
                c = (((c - 65) + j) % 26) + 65;
            }
            else 
            {
                c = message.at(i);
            }

            cout << c;
        }

        cout << endl;
    }


    cout << endl << endl;
}
/*
 Trang Hoang
 CS110B
 Dave Harden
 10/6/20
 a6_1.cpp
 
 Assignment 6.1
 
 Program illustrates the use of different ways that string data (e.g., C-strings) can be
 handled in C++ without using the string library.
 
 Created by nyccowgirl on 10/6/20.
 Copyright © 2020 nyccowgirl. All rights reserved.
*/

#include <iostream>
#include <cctype>
#include <utility>
using namespace std;


int lastIndexOf(const char* inString, char target);
void reverse(char* inString);
int replace(char* inString, char target, char replacementChar);
bool isPalindrome(const char* inString);
void toupper(char* inString);
int numLetters(const char* inString);


int main(int argc, const char * argv[]) {
    char str1[] = "Hello World!";            // To define test character arrays
//    char str2[] = "C++ is fun!";
//    char str3[] = "racecar";
//    char str4[] = "aBBA";
    char target = 'o', replacement = 'z';   // To set default target and replacement char
    int userOpt1 = 0, userOpt2 = 0;         // To set default user options to input
    char userStr[100];                      // To define array to hold user input C-string
    char *inString;                         // To point to a character array
    
//    cout << strlen(str1) << endl;
//    cout << sizeof(str1) << endl;
    // Asks if user wants to provide customized string
//    do {
//        cout << "Do you want to enter your own string?: (0 = No; 1 = Yes) ";
//        cin >> userOpt1;
//        cin.ignore();
//
//        if (!(userOpt1 == 0 || userOpt1 == 1)) {
//            cout << "Invalid input: Please enter 0 for No and 1 for Yes." << endl;
//        }
//    } while (!(userOpt1 == 0 || userOpt1 == 1));
    
    // If yes, gets user's input limited to 99 characters
    if (userOpt1 == 1) {
        cout << "Enter your test string (limited to less than 100 characters): ";
        cin.get(userStr, 100, '\n');
        cin.ignore();
//        cout << userStr << endl;
//        cout << strlen(userStr) << endl;
        inString = userStr;
    } else {
        inString = str1;                    // Modify array from options above to test
//        inString = str2;
//        inString = str3;
//        inString = str4;
    }
    
//    cout << "Test string: " << inString << endl;
    // Asks if user wants to modify target and replacement characters from default
//    do {
//        cout << "Do you want to enter your own target and replacement characters?:";
//        cout << "(0 = No; 1 = Yes) ";
//        cin >> userOpt2;
//        cin.ignore();
//
//        if (!(userOpt2 == 0 || userOpt2 == 1)) {
//            cout << "Invalid input: Please enter 0 for No and 1 for Yes." << endl;
//        }
//    } while (!(userOpt2 == 0 || userOpt2 == 1));
//
    // If yes, gets user's inputs for both
    if (userOpt2 == 1) {
        cout << "Enter your target character: ";
        cin >> target;
        cin.ignore();
        cout << "Enter your replacement character: ";
        cin >> replacement;
        cin.ignore();
    }
    
//    cout << "Target - Replacement: " << target << " - " << replacement << endl;
    
    for (int x = 0; x < strlen(inString); x++) {
        cout << x << ": " << inString[x] << endl;
    }
    
    // Tests function lastIndexOf
    cout << "\nThe last index with character '" << target << "': ";
    cout << lastIndexOf(inString, target) << endl;
    
    // Tests function reverse (and returns string back to original for other test functions)
    reverse(inString);
    cout << "\nThe reverse of the string: " << inString << endl;
    reverse(inString);                      // To restore to original string
    
    // Tests function replace (and returns string back to original for other test functions)
    cout << "\nNumber of times the character '" << target;
    cout << "' was replaced by '" << replacement << "': ";
    cout << replace(inString, target, replacement) << endl;
    cout << "The modified string: " << inString << endl;
    replace(inString, replacement, target); // To restore to original string

    // Tests function isPalindrome
    cout << "\nIs the string a palindrome? ";
    if (isPalindrome(inString)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    // Tests function toupper
    toupper(inString);
    cout << "\nThe string in all UPPER CASE letters: ";
    cout << inString << endl;
    
    // Tests function numLetters
    cout <<"\nThe number of letters in the string is: " << numLetters(inString) << endl;
    
    return 0;
}






/*
 Definition of function lastIndexOf. The function passes in a pointer to a string (stored
 in a character array) and a target character and returns the last index in the string where
 the target character can be found. It returns -1 if the character is not in the string.
*/

int lastIndexOf(const char* inString, char target) {
    int index = -1;
    int x = 0;
    
//    cout << strlen(inString) << endl;
//    for (int x = 0; x < strlen(inString); x++) {
//        if (*(inString + x) == target) {
//            index = x;
//        }
//    }
    
    // using while loop
    while (*inString != '\0') {
        if (*inString == target) {
            index = x;
        }
        x++;
        inString++;
    }
    
//    while (inString[x] != '\0') {
//        if (inString[x] == target) {
//            index = x;
//        }
//        x++;
//    }
    return index;
}






/*
 Definition of function reverse. The function passes in a pointer to a string (stored in a
 character array) and reverses the string.
 */

void reverse(char* inString) {
    int backwards = (int)strlen(inString);
    
    for (int x = 0; x < (backwards / 2); x++) {
        swap(*(inString + x), *(inString + backwards - x - 1));
    }
}






/*
 Definition of function replace. The function passes in a pointer to a string (stored in a
 character array), a target character and a replacement character. It searchs the string for
 each target character and replaces it with the replacement character. It returns the number
 of times the character was replaced.
 */

int replace(char* inString, char target, char replacementChar) {
    int count = 0;
//    int x = 0;
    
//    for (int x = 0; x < strlen(inString); x++) {
//        if (*(inString + x) == target) {
//            *(inString + x) = replacementChar;
//            count++;
//        }
//    }
    
    // using while loop
    while (*inString != '\0') {
        if (*inString == target) {
            *inString = replacementChar;
            count++;
        }
        inString++;
    }
    
//    while (inString[x] != '\0') {
//        if (inString[x] == target) {
//            inString[x] = replacementChar;
//            count++;
//        }
//        x++;
//    }
    return count;
}






/*
 Definition of function isPalindrome. The function passes in a pointer to a string (stored
 in a character array). It returns true if the string is a palindrome and false if not. The
 function is not case sensitive.
 */

bool isPalindrome(const char* inString) {
    int backwards = (int)strlen(inString);
    
    for (int x = 0; x < (backwards / 2); x++) {
        if (toupper(*(inString + x)) != toupper(*(inString + backwards - x - 1))) {
            return false;
        }
    }
    return true;
}






/*
 Definition of function toupper. The function passes in a pointer to a string (stored in a
 character array) and converts the string to all upper case letters.
 */

void toupper(char* inString) {
//    int x = 0;
    
//    for (int x = 0; x < strlen(inString); x++) {
//        *(inString + x) = toupper(*(inString + x));
//    }
    
    //using while loop
    while (*inString != '\0') {
        *inString = toupper(*inString);
        inString++;
    }
    
//    while (inString[x] != '\0') {
//        *(inString + x) = toupper(*(inString + x));
//        x++;
//    }
}






/*
 Definition of numLetters. The function passes in a pointer to a string (stored in a
 character array) and returns the number of letters in the string.
 */

int numLetters(const char* inString) {
    int count = 0;
//    int x = 0;
    
//    for (int x = 0; x < strlen(inString); x++) {
//        if (isalpha(*(inString + x))) {
//            count++;
//        }
//    }
    
    // using while loop
    while (*inString != '\0') {
        if (isalpha(*inString)) {
            count++;
        }
        inString++;
    }
    
//    while (inString[x] != '\0') {
//        if (isalpha(inString[x])) {
//            count++;
//        }
//        x++;
//    }
    return count;
}


/*
 
 Do you want to enter your own string?: (0 = No; 1 = Yes) 1
 Enter your test string (limited to less than 100 characters: People say nothing is impossible but I do nothing every day.
 Do you want to enter your own target and replacement characters?:(0 = No; 1 = Yes) 0

 The last index with character 'a': 57

 The reverse of the string: .yad yreve gnihton od I tub elbissopmi si gnihton yas elpoeP

 Number of times the character 'a' was replaced by 'z': 2
 The modified string: People szy nothing is impossible but I do nothing every dzy.

 Is the string a palindrome? No

 The string in all UPPER CASE letters: PEOPLE SAY NOTHING IS IMPOSSIBLE BUT I DO NOTHING EVERY DAY.

 The number of letters in the string is: 49
 Program ended with exit code: 0
 
 *****
 
 Do you want to enter your own string?: (0 = No; 1 = Yes) 0
 Do you want to enter your own target and replacement characters?:(0 = No; 1 = Yes) 0

 The last index with character 'a': 0

 The reverse of the string: ABBa

 Number of times the character 'a' was replaced by 'z': 1
 The modified string: zBBA

 Is the string a palindrome? Yes

 The string in all UPPER CASE letters: ABBA

 The number of letters in the string is: 4
 Program ended with exit code: 0
 
 */

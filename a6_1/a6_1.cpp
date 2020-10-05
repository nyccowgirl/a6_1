/*
 Trang Hoang
 CS110B
 Dave Harden
 10/6/20
 a6_1.cpp
 
 Assignment 6.1
 
 Program illustrates the use of different ways that string data can be handled in C++
 without using the string library.
 
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
//    char str1[] = "Hello World!";            // To define test character arrays
    char str2[] = "C++ is fun!";
//    char str3[] = "racecar";
//    char str4[] = "aBBA";
    char target = 'a', replacement = 'z';
    int userOpt1 = 0, userOpt2 = 0;
    long userLength;
    char userStr[100];
    char *inString;                         // To point to a character array
    
    do {
        cout << "Do you want to enter your own string?: (0 = No; 1 = Yes) ";
        cin >> userOpt1;
        cin.ignore();
        
        if (!(userOpt1 == 0 || userOpt1 == 1)) {
            cout << "Invalid input: Please enter 0 for No and 1 for Yes." << endl;
        }
    } while (!(userOpt1 == 0 || userOpt1 == 1));
    
    if (userOpt1 == 1) {
        cout << "Enter your test string: ";
        cin.get(userStr, 100, '\n');
        cin.ignore();
        userLength = strlen(userStr);
//        cout << userStr << endl;
//        cout << strlen(userStr) << endl;
        inString = userStr;
    } else {
//        inString = str1;                    // Modify array name from options above to test
        inString = str2;
//        inString = str3;
//        inString = str4;
    }
    
//    cout << "Test string: " << inString << endl;
    
    do {
        cout << "Do you want to enter your own target and replacement characters?:";
        cout << "(0 = No; 1 = Yes) ";
        cin >> userOpt2;
        cin.ignore();
        
        if (!(userOpt2 == 0 || userOpt2 == 1)) {
            cout << "Invalid input: Please enter 0 for No and 1 for Yes." << endl;
        }
    } while (!(userOpt2 == 0 || userOpt2 == 1));
    
    if (userOpt2 == 1) {
        cout << "Enter your target character: ";
        cin >> target;
        cin.ignore();
        cout << "Enter your replacement character: ";
        cin >> replacement;
        cin.ignore();
    }
    
//    cout << "Target - Replacement: " << target << " - " << replacement << endl;
    cout << "\nThe last index with character '" << target << "': ";
    cout << lastIndexOf(inString, target) << endl;
    
    reverse(inString);
    cout << "\nThe reverse of the string: " << inString << endl;
    reverse(inString);                      // To restore original string
    
    cout << "\nNumber of times the character '" << target;
    cout << "' was replaced by '" << replacement << "': ";
    cout << replace(inString, target, replacement) << endl;
    cout << "The modified string: " << inString << endl;
    replace(inString, replacement, target); // To restore original string
    
    cout << "\nIs the string a palindrome? ";
    if (isPalindrome(inString)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    toupper(inString);
    cout << "\nThe string in all UPPER CASE letters: ";
    cout << inString << endl;
    
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
    
    for (int x = 0; x < strlen(inString); x++) {
        if (*(inString + x) == target) {
            index = x;
        }
    }
    return index;
}






/*
 Definition of function reverse. The function passes in a pointer to a string (stored in a
 character array) and reverses the string.
 */

void reverse(char* inString) {
    long backwards = strlen(inString);
    
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
    
    for (int x = 0; x < strlen(inString); x++) {
        if (*(inString + x) == target) {
            *(inString + x) = replacementChar;
            count++;
        }
    }
    return count;
}






/*
 Definition of function isPalindrome. The function passes in a pointer to a string (stored
 in a character array). It returns true if the string is a palindrome and false if not. The
 function is not case sensitive.
 */

bool isPalindrome(const char* inString) {
    long backwards = strlen(inString);
    
    for (int x = 0; x < (backwards / 2); x++) {
        if (toupper(*(inString + x)) != toupper(*(inString + backwards - x -1))) {
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
    for (int x = 0; x < strlen(inString); x++) {
        *(inString + x) = toupper(*(inString + x));
    }
}






/*
 Definition of numLetters. The function passes in a pointer to a string (stored in a
 character array) and returns the number of letters in the string.
 */

int numLetters(const char* inString) {
    int count = 0;
    
    for (int x = 0; x < strlen(inString); x++) {
        if (isalpha(*(inString + x))) {
            count++;
        }
    }
    return count;
}



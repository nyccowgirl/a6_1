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
//    char str1[] = "Hello World!";            // To define test character arrays
//    char str2[] = "C++ is fun!";
//    char str3[] = "racecar";
//    char str4[] = "aBBA";
    char str5[] = "O!o";
    char target = 'o', replacement = 'z';   // To set default target and replacement char
    int userOpt1 = 0, userOpt2 = 0;         // To set default user options to input
    char userStr[100];                      // To define array to hold user input C-string
    char *inString;                         // To point to a character array
    
    // Asks if user wants to provide customized string
    do {
        cout << "Do you want to enter your own string?: (0 = No; 1 = Yes) ";
        cin >> userOpt1;
        cin.ignore();

        if (!(userOpt1 == 0 || userOpt1 == 1)) {
            cout << "Invalid input: Please enter 0 for No and 1 for Yes." << endl;
        }
    } while (!(userOpt1 == 0 || userOpt1 == 1));
    
    // If yes, gets user's input limited to 99 characters
    if (userOpt1 == 1) {
        cout << "Enter your test string (limited to less than 100 characters): ";
        cin.getline(userStr, 100);
//        cin.ignore();
        inString = userStr;
    } else {
//        inString = str1;                    // Modify array from options above to test
//        inString = str2;
//        inString = str3;
//        inString = str4;
        inString = str5;
    }
    
    // Asks if user wants to modify target and replacement characters from default
    do {
        cout << "Do you want to enter your own target and replacement characters?:";
        cout << "(0 = No; 1 = Yes) ";
        cin >> userOpt2;
        cin.ignore();

        if (!(userOpt2 == 0 || userOpt2 == 1)) {
            cout << "Invalid input: Please enter 0 for No and 1 for Yes." << endl;
        }
    } while (!(userOpt2 == 0 || userOpt2 == 1));

    // If yes, gets user's inputs for both
    if (userOpt2 == 1) {
        cout << "Enter your target character: ";
        cin >> target;
        cin.ignore();
        cout << "Enter your replacement character: ";
        cin >> replacement;
        cin.ignore();
    }
    
    // Displays original string to test
    cout << "\nThe original string: " << inString << endl;
    
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
    int lastIndex = -1, index = 0;
    
    while (inString[index] != '\0') {
        if (inString[index] == target) {
            lastIndex = index;
        }
        index++;
    }
    return lastIndex;
}






/*
 Definition of function reverse. The function passes in a pointer to a string (stored in a
 character array) and reverses the string.
 */

void reverse(char* inString) {
    int backwards = (int)strlen(inString);
    
    for (int x = 0; x < (backwards / 2); x++) {
        swap(inString[x], inString[backwards - x - 1]);
    }
}






/*
 Definition of function replace. The function passes in a pointer to a string (stored in a
 character array), a target character and a replacement character. It searchs the string for
 each target character and replaces it with the replacement character. It returns the number
 of times the character was replaced.
 */

int replace(char* inString, char target, char replacementChar) {
    int count = 0, index = 0;
    
    while (inString[index] != '\0') {
        if (inString[index] == target) {
            inString[index] = replacementChar;
            count++;
        }
        index++;
    }
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
        if (toupper(inString[x]) != toupper(inString[backwards - x - 1])) {
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
    int index = 0;

    while (inString[index] != '\0') {
        inString[index] = toupper(inString[index]);
        index++;
    }
}






/*
 Definition of numLetters. The function passes in a pointer to a string (stored in a
 character array) and returns the number of letters in the string.
 */

int numLetters(const char* inString) {
    int count = 0, index = 0;
    
    while (inString[index] != '\0') {
        if (isalpha(inString[index])) {
            count++;
        }
        index++;
    }
    return count;
}


/*
 
 The original string: Hello World!

 The last index with character 'o': 7

 The reverse of the string: !dlroW olleH

 Number of times the character 'o' was replaced by 'z': 2
 The modified string: Hellz Wzrld!

 Is the string a palindrome? No

 The string in all UPPER CASE letters: HELLO WORLD!

 The number of letters in the string is: 10
 Program ended with exit code: 0
 
 *****
 
 The original string: C++ is fun!

 The last index with character 'o': -1

 The reverse of the string: !nuf si ++C

 Number of times the character 'o' was replaced by 'z': 0
 The modified string: C++ is fun!

 Is the string a palindrome? No

 The string in all UPPER CASE letters: C++ IS FUN!

 The number of letters in the string is: 6
 Program ended with exit code: 0
 
 *****
 
 The original string: racecar

 The last index with character 'o': -1

 The reverse of the string: racecar

 Number of times the character 'o' was replaced by 'z': 0
 The modified string: racecar

 Is the string a palindrome? Yes

 The string in all UPPER CASE letters: RACECAR

 The number of letters in the string is: 7
 Program ended with exit code: 0
 
 *****
 
 The original string: aBBA

 The last index with character 'o': -1

 The reverse of the string: ABBa

 Number of times the character 'o' was replaced by 'z': 0
 The modified string: aBBA

 Is the string a palindrome? Yes

 The string in all UPPER CASE letters: ABBA

 The number of letters in the string is: 4
 Program ended with exit code: 0
 
 *****
 
 The original string: O!o

 The last index with character 'o': 2

 The reverse of the string: o!O

 Number of times the character 'o' was replaced by 'z': 1
 The modified string: O!z

 Is the string a palindrome? Yes

 The string in all UPPER CASE letters: O!O

 The number of letters in the string is: 2
 Program ended with exit code: 0
 
 *****
 
 The original string: Aa

 The last index with character 'o': -1

 The reverse of the string: aA

 Number of times the character 'o' was replaced by 'z': 0
 The modified string: Aa

 Is the string a palindrome? Yes

 The string in all UPPER CASE letters: AA

 The number of letters in the string is: 2
 Program ended with exit code: 0
 
 *****
 
 Do you want to enter your own string?: (0 = No; 1 = Yes) 1
 Enter your test string (limited to less than 100 characters): Sit on a potato pan Otis
 Do you want to enter your own target and replacement characters?:(0 = No; 1 = Yes) 0
 
 The original string: Sit on a potato pan Otis

 The last index with character 'o': 14

 The reverse of the string: sitO nap otatop a no tiS

 Number of times the character 'o' was replaced by 'z': 3
 The modified string: Sit zn a pztatz pan Otis

 Is the string a palindrome? No

 The string in all UPPER CASE letters: SIT ON A POTATO PAN OTIS

 The number of letters in the string is: 19
 Program ended with exit code: 0
 
 *****
 
 Do you want to enter your own string?: (0 = No; 1 = Yes) 1
 Enter your test string (limited to less than 100 characters): (o)|(o)
 Do you want to enter your own target and replacement characters?:(0 = No; 1 = Yes) 0

 The original string: (o)|(o)

 The last index with character 'o': 5

 The reverse of the string: )o(|)o(

 Number of times the character 'o' was replaced by 'z': 2
 The modified string: (z)|(z)

 Is the string a palindrome? No

 The string in all UPPER CASE letters: (O)|(O)

 The number of letters in the string is: 2
 Program ended with exit code: 0
 
 *****
 
 Do you want to enter your own string?: (0 = No; 1 = Yes) 1
 Enter your test string (limited to less than 100 characters): I aM mAdAm mA i
 Do you want to enter your own target and replacement characters?:(0 = No; 1 = Yes) 1
 Enter your target character: a
 Enter your replacement character: W

 The original string: I aM mAdAm mA i

 The last index with character 'a': 2

 The reverse of the string: i Am mAdAm Ma I

 Number of times the character 'a' was replaced by 'W': 1
 The modified string: I WM mAdAm mA i

 Is the string a palindrome? Yes

 The string in all UPPER CASE letters: I AM MADAM MA I

 The number of letters in the string is: 11
 Program ended with exit code: 0
 
 */

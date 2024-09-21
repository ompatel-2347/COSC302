// Challenge 06: Palindrome Permutation
// Om Patel opatel11
/* This program will determine if a given line
   of text CAN be rearranged to be a palindrome. 
   A palindrome is a word that reads the same backwards */


#include <iostream>
#include <unordered_map>
#include <string>
#include <cctype>
using namespace std;

bool is_palindrome(string& s) {
    
    //declare unordered map
    unordered_map<char, int> charCount;
    
    //check if character is alphanumeric, 
	//if so add to map and increment value by 1
    for (size_t i = 0; i < s.length(); ++i) {
        char c = s[i];
        if (isalnum(c)) {
            charCount[tolower(c)]++;
        }
    }

	//check if there is more than 1 character with odd appearances
    int odd_count = 0;
    for (pair<char, int> pair : charCount) {
        if (pair.second % 2 != 0) {
            odd_count++;
        }
        
        // return false if more than one character has an odd count
        if (odd_count > 1) {
            return false;
        }
    }
    return true;
}

int main() {
    
    string s;
    while (getline(cin, s))
        if (is_palindrome(s) == true) {
            cout << "\"" << s << "\"" << " is a palindrome permutation" << endl;
        } else {
            cout << "\"" << s << "\"" << " is not a palindrome permutation" << endl;
        }
    return 0;
}

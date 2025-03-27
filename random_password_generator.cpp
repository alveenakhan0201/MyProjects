#include <iostream>
#include <cstdlib> //for rand function 
#include <ctime>

using namespace std;

// Function definition to generate random password
string generatePassword() 
{
    string password;
    const string charSet[] = 
{
        "0123456789", // Numbers
        "abcdefghijklmnopqrstuvwxyz", // Lowercase letters
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ" // Uppercase letters
    };

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < 12; ++i) 
	{
        // Choose one of the character sets randomly
        int setIndex = rand() % 3;
        const string& selectedSet = charSet[setIndex];

        // Get random index position within the selected character set
        int charIndex = rand() % selectedSet.length();

        // Append the randomly chosen character to the password
        password += selectedSet[charIndex];
    }

    return password;
}

int main() 
{
    string password = generatePassword();

    cout << "Generated Password: " << password << endl;

    return 0;
}

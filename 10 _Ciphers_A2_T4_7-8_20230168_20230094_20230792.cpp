/*FCAI - Structured Programming - 2024 - Assignment 2
Program Name: CS112_A2_T2_7-8_20230168_20230094_20230792.cpp
Program Description: This program includes eight different ciphers.
There is also deciphering option for them all
Last Modification Date: 19/3/2024
Author 1 and ID and Group: Sara Yasser Ahmed Meshrif - 20230168 - Group A
Author 2 and ID and Group: Omar Nour Al-Deen Al-Masri - 20230792 - Group A
Author 3 and ID and Group: Bassant Ahmed Talaat Mohammed - 20230094 - Group A
Teaching Assistant: Belal Tarek Hasan
Who did what: Sara Yasser did xor cipher - Bassant Ahmed did baconian, Polybius Square  cipher - Omar Nour did atbash cipher -
Sara Yasser did morse code cipher - sara yasser did affine cipher - bassant ahmed did simple substitution cipher -
omar nour did vigenere cipher - omar nour did rail fence cipher*/

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <limits>
#include <algorithm>
#include <unordered_map>
#include<string.h>
#include<stdlib.h>
#include <bits/stdc++.h>

using namespace std;

// Function prototypes
void xorCipher();
bool isValidInput(const string& input);
bool isValidHex(const string& hexString);
void encryptMessage(string& key);
void decryptMessage(string& key);
void atbashCipher();
void cypherExcuting();
void decypherExcuting();
void wholeAlphabetCyphering();
void divideAlphabetInto2Halves();
void baconianCipher();
bool isValid(string& messg, char& choice);
void morseCodeCipher();
bool isAlphabetic(char c);
bool isMorseCharacter(char c);
void cipherMessage(const unordered_map<char, string>& AlphabetToMorse);
void decipherMessage(const unordered_map<string, char>& MorseToAlphabet);
void affineCipher();
string encryptedMessage(string originalMessage);
string decryptedMessage(string encryptedText);
void simpleSubstCipher();
bool is_valid(string& key);
void M_cipher_alpha( string& alpha , string& cipher_alpha , string& key);
string simple_cip_dis(string& list_from ,string& list_to ,string& messg);
void railFenceCipher();
void railFenceEncrypt(const string& plainText, int rails, string& cipheredText);
void vigenereCipher(string& input);
void userInput();
void userKey();
void vigenereEncrypt();
void vigenereDecrypt();
void PolybiusCipher();
bool is_valid_p (string& key);
void cipher(string& messg, char alpha[5][5] , string& key);
void Decipher(string& messg , char alpha[5][5] , string& key);


int main() {
    string input;
    char choice;
    cout << "\nWelcome to our cipher program!!\n\n";

    do {
        // Display menu options
        cout << "\nChoose the cipher you want to use:\n\nA) XOR Cipher\nB) Atbash Cipher\nC) Bocanian Cipher\nD) Morse Code Cipher\n";
        cout << "E) Affine Cipher\nF) Simple Substitution Cipher\nG) Rail Fence Cipher\nH) Vigenere Cipher\nI) Polybius Square Cipher\nJ) Exit\n";
        cout << "\nPlease enter your choice: ";

        cin >> choice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        choice = toupper(choice);

        switch (choice) {
            case 'A':
                xorCipher();
                break;
            case 'B':
                atbashCipher();
                break;
            case 'C':
                baconianCipher();
                break;
            case 'D':
                morseCodeCipher();
                break;
            case 'E':
                affineCipher();
                break;
            case 'F':
                simpleSubstCipher();
                break;
            case 'G':
                railFenceCipher();
                break;
            case 'H':
                vigenereCipher(input);
                break;
            case 'I':
                PolybiusCipher();
                break;
            case 'J':
                cout << "\nExiting program. Goodbye!\n";
                break;
            default:
                cout << "\n**Invalid choice. Please try again**\n";
                continue;
        }

    } while (choice != 'E');

    return 0;
}

void baconianCipher() {
    //  Author and ID: Bassant Ahmed Talat Mohamed - 20230094

    // List to make Cipher and Decipher
    char letters[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    string cipher[26] = {"aaaaa","aaaab","aaaba","aaabb","aabaa","aabab","aabba","aabbb","abaaa","abaab","ababa","ababb","abbaa","abbab","abbba","abbbb","baaaa","baaab","baaba","baabb","babaa","babab","babba","babbb","bbaaa","bbaab"};
    cout << "\n\nWelcome to Baconian Cipher\n";
    while (true) {
        cout << "\nA) Cipher a message\nB) Decipher a message\nC) Exit\n";
        cout << "\nPlease enter your choice: ";

        char choice;
        cin >> choice;
        choice = toupper(choice); // To accept small letter

        string messg;
        cin.ignore();

        if (choice == 'C') {
            cout << "\nExiting ...\n";
            break;
        } else if (choice != 'A' && choice != 'B') {
            cout << "\n** This is an invalid choice **\n ";
            continue; // Go back to the beginning of the menu loop
        }

        while (true) {
            cout << "Enter your message: ";
            getline(cin, messg);

            // Error messages if messge is wrong
            if (!isValid(messg, choice) && choice == 'A'){
                cout << "\n** All letters must be capital **\n\n";
                continue;
            }
            else if (!isValid(messg, choice) && choice == 'B'){
                cout << "\n** Letters must be 'a' or 'b' only in groups of five digits **\n\n";
                continue;
            }

            if (choice == 'A') {
                cout << "\nYour cipher message:";
                // To get the character number in the list and get its counterpart in encryption
                for (int i = 0; i < messg.length(); i++) {
                    for (int g = 0; g < 26; g++)
                        if (messg[i] == letters[g])
                            cout << " " << cipher[g];
                }
                cout << endl;

            } else if (choice == 'B') {
                string one_word="";  // To save all five letters in it
                cout << "\nYour Decipher message:";
                // To get the encryption number in the list and get its counterpart in the letters
                for (int k = 0; k < messg.length(); k++) {
                    one_word += messg[k];
                    if (one_word.length() == 5) {   // To take all five letters together
                        for (int i = 0; i < 26; i++) {
                            if (one_word == cipher[i])
                                cout << " " << letters[i];
                        }
                        one_word.clear();   // Make it empty to take next five letters
                    }
                }
                cout << endl;
            }
            break;
        }
    }
}

// chack the letter in message is correct
bool isValid(string& messg, char& choice) {
    messg.erase(remove_if(messg.begin(), messg.end(), ::isspace), messg.end()); // To remove space

    for (int h = 0; h < messg.length(); h++) {
        char letter = messg[h];
        if (choice == 'A') {
            // A => 65 and Z => 90 any thing not in [65,90] is not a capilal letter
            if (int(letter) > 90 || int(letter) < 65 )
                return false;
        }
        if (choice == 'B') {
            // chack all letter is a or b only and all 5 letter reprisent a letter
            if (letter != 'a' && letter != 'b' || messg.length()% 5 != 0)
                return false;
        }
    }
    return true;
}

void atbashCipher() {
    // Author 2 and ID: Omar Nour Al-Deen Al-Masri - 20230792
    char choose;
    cout << "\n\nWelcome to Atbash Cipher\n";
    // Main menu loop
    do {
        // Display menu options
        cout << "\nA. Cipher \nB. Decipher \nC. Exit\n";
        cout << "\nEnter your choice: ";

        // Input choice from user
        cin >> choose;

        // Check for non-numeric input
        if (cin.peek() != '\n') {
            cout << "\nInvalid choice. Please try again.\n";
            cin.clear(); // Clear the error flag on cin
            while (cin.get() != '\n') // Discard remaining input until newline is encountered
                continue;
            continue; // Restart the loop
        }

        // Convert lowercase input to uppercase
        if (choose == 'a' || choose == 'b' || choose == 'c') {
            choose = toupper(choose);
        }

        // Validate choice
        if (choose != 'A' && choose != 'B' && choose != 'C') {
            cout << "\nInvalid choice. Please try again.\n";
            cin.clear();
            cin.ignore();
            continue;
        }

        cin.ignore();

        // Execute the chosen program or feature
        switch (choose) {
            case 'A':
                cypherExcuting();
                break;
            case 'B':
                decypherExcuting();
                break;
            case 'C':
                cout << "\nExiting ...\n";
                break;
            default:
                cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choose != 'C');
}

// Function for executing the ciphering process
void cypherExcuting() {
    char choice;

    // Sub-menu loop for ciphering options
    do {
        // Display ciphering menu options
        cout << "\nChoose The Atbash Cipher You Want:\n";
        cout << "\nA. Whole Alphabet Ciphering \nB. Divide Alphabet Into 2 Halves Ciphering \nC. Back \n";
        cout << "\nEnter your choice: ";

        // Input choice from user
        cin >> choice;

        // Check for non-numeric input
        if (cin.peek() != '\n') {
            cout << "\nInvalid choice. Please try again.\n";
            cin.clear(); // Clear the error flag on cin
            while (cin.get() != '\n') // Discard remaining input until newline is encountered
                continue;
            continue; // Restart the loop
        }

        // Convert lowercase input to uppercase
        if (choice == 'a' || choice == 'b' || choice == 'c') {
            choice = toupper(choice);
        }

        // Validate choice
        if (choice != 'A' && choice != 'B' && choice != 'C') {
            cout << "\nInvalid choice. Please try again.\n";
            cin.clear();
            cin.ignore();
            continue;
        }

        cin.ignore();

        // Execute the chosen program or feature
        switch (choice) {
            case 'A':
                wholeAlphabetCyphering();
                break;
            case 'B':
                divideAlphabetInto2Halves();
                break;
            case 'C':
                break;
            default:
                cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 'C');
}

// Function for executing the deciphering process
void decypherExcuting() {
    char choice;

    // Sub-menu loop for deciphering options
    do {
        // Display deciphering menu options
        cout << "\nChoose The Atbash Decipher You Want:\n";
        cout << "\nA. Whole Alphabet Deciphering \nB. Divide Alphabet Into 2 Halves Deciphering \nC. Back \n";
        cout << "\nEnter your choice: ";

        // Input choice from user
        cin >> choice;

        // Check for non-numeric input
        if (cin.peek() != '\n') {
            cout << "\nInvalid choice. Please try again.\n";
            cin.clear(); // Clear the error flag on cin
            while (cin.get() != '\n') // Discard remaining input until newline is encountered
                continue;
            continue; // Restart the loop
        }

        // Convert lowercase input to uppercase
        if (choice == 'a' || choice == 'b' || choice == 'c') {
            choice = toupper(choice);
        }

        // Validate choice
        if (choice != 'A' && choice != 'B' && choice != 'C') {
            cout << "\nInvalid choice. Please try again.\n";
            cin.clear();
            cin.ignore();
            continue;
        }

        cin.ignore();

        // Execute the chosen program or feature
        switch (choice) {
            case 'A':
                wholeAlphabetCyphering();
                break;
            case 'B':
                divideAlphabetInto2Halves();
                break;
            case 'C':
                break;
            default:
                cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 'C');
}

// Function for ciphering the whole alphabet
void wholeAlphabetCyphering() {
    cout << "\nRunning Cypher Whole Alphabet from A - Z ...\n";
    cout << "\nNote: If You Entered a Non-Alphabet Character, It Will Be Ignored\n";
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string words;

    cout << "\nEnter the words you want to cipher: ";

    // Input words from user
    getline(cin, words);

    string cipheredWords = "";

    // Ciphering process
    for (char letter : words) {
        if (isalpha(letter)) {
            int position = alphabet.find(toupper(letter)) + 1;
            int positionReversed = 26 - position + 1;
            char letterReversed = alphabet[positionReversed - 1];
            cipheredWords += letterReversed;
        }
    }

    // Output ciphered words
    cout << "The ciphered words is: " << cipheredWords << endl;
}

// Function for ciphering alphabet into two halves
void divideAlphabetInto2Halves() {
    cout << "Running Cypher With Dividing Alphabet Into 2 Halves ...\n";
    cout << "Note: If You Entered a Non-Alphabet Character, It Will Be Ignored\n";
    string alphabetHalve1 = "ABCDEFGHIJKLM";
    string alphabetHalve2 = "NOPQRSTUVWXYZ";
    string words;

    cout << "\nEnter the words you want to cipher: ";

    // Input words from user
    getline(cin, words);

    string cipheredWords = "";

    // Ciphering process
    for (char letter: words) {
        if (isalpha(letter)) {
            if ((letter >= 'A' && letter <= 'M') || (letter >= 'a' && letter <= 'm')) { // First half of the alphabet
                int position = alphabetHalve1.find(toupper(letter)) + 1;
                int positionReversed = 13 - position + 1;
                char letterReversed = alphabetHalve1[positionReversed - 1];
                cipheredWords += letterReversed;
            } else if (letter >= 'N' && letter <= 'Z' ||
                       (letter >= 'n' && letter <= 'z')) { // Second half of the alphabet
                int position = alphabetHalve2.find(toupper(letter)) + 1;
                int positionReversed = 13 - position + 1;
                char letterReversed = alphabetHalve2[positionReversed - 1];
                cipheredWords += letterReversed;
            }
        }
    }

    // Output ciphered words
    cout << "The ciphered words is: " << cipheredWords << endl;
}

void xorCipher() {
    // Author and ID: Sara Yasser Ahmed Meshrif - 20230168

    cout << "\n\nWelcome to XOR Cipher\n";
    while (true) {
        // Main menu options
        cout << "\nA) Cipher a message\nB) Decipher a message\nC) Exit\n";
        cout << "\nPlease enter your choice: ";

        char choice;
        cin >> choice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        choice = toupper(choice); // Convert choice to uppercase

        string key;

        if (choice == 'A') {
            // Encryption process
            encryptMessage(key);
        } else if (choice == 'B') {
            // Decryption process
            decryptMessage(key);
        } else if (choice == 'C') {
            // Exit the program
            cout << "\nExiting ..." << endl;
            break;
        } else {
            // Invalid choice
            cerr << "\n**Invalid choice. Please choose a valid option**" << endl;
        }
    }
}

// Function to check if the input is non-empty
bool isValidInput(const string& input) {
    return !input.empty();
}

// Function to check if a hexadecimal string is valid
bool isValidHex(const string& hexString) {
    for (char c : hexString) {
        if (!isxdigit(c) && c != ' ') {
            return false;
        }
    }
    return true;
}

// Function to encrypt a message
void encryptMessage(string& key) {
    string inputText;
    // Get the key
    do {
        cout << "\nEnter your special key: ";
        getline(cin, key);
        if (!isValidInput(key)) {
            cerr << "\n**Key cannot be empty. Please enter a valid key**\n";
        }
    } while (!isValidInput(key));

    // Get the message to cipher
    do {
        cout << "\nEnter the message to cipher: ";
        getline(cin, inputText);
        if (!isValidInput(inputText)) {
            cerr << "\n**Text cannot be empty. Please enter a valid message**\n";
        }
    } while (!isValidInput(inputText));

    // Ciphering the input text
    string encryptedText = "", hexRepresentation = "";
    cout << "\n**Note: Unprintable characters will be replaced with spaces (' ')**\n";
    for (size_t i = 0; i < inputText.size(); ++i) {
        char encryptedChar = inputText[i] ^ key[i % key.size()]; // XOR operation with the key
        encryptedText += isprint(encryptedChar) ? encryptedChar : ' '; // Check for printable characters

        // Convert the ciphered character to its hexadecimal representation
        stringstream hexStream;
        hexStream << hex << uppercase << setw(2) << setfill('0') << static_cast<int>(static_cast<unsigned char>(encryptedChar));
        hexRepresentation += hexStream.str() + ' ';
    }

    cout << "\nYour ciphered message: " << encryptedText << endl;
    cout << "Your ciphered message (hexa): " << hexRepresentation << endl;
}

// Function to decrypt a message
void decryptMessage(string& key) {
    char decryptOption;
    do {
        cout << "\nA) Text\nB) Hexadecimal\n";
        cout << "\nDo you want to decipher using text or hexadecimal?: ";
        cin >> decryptOption;
        cin.ignore();
        decryptOption = toupper(decryptOption);

        if (decryptOption == 'A') {
            // Decryption process with text input
            string inputText;
            do {
                cout << "\nEnter your special key: ";
                getline(cin, key);
                if (!isValidInput(key)) {
                    cerr << "\n**Key cannot be empty. Please enter a valid key**\n";
                }
            } while (!isValidInput(key));

            do {
                cout << "\nEnter the message to decipher: ";
                getline(cin, inputText);
                if (!isValidInput(inputText)) {
                    cerr << "\n**Text cannot be empty. Please enter a valid message**\n";
                }
            } while (!isValidInput(inputText));

            // Deciphering the input text
            string decryptedText = "";
            for (size_t i = 0; i < inputText.size(); ++i) {
                char decryptedChar = inputText[i] ^ key[i % key.size()]; // XOR operation with the key
                decryptedText += decryptedChar;
            }

            cout << "Your deciphered message: " << decryptedText << endl;
            break;
        } else if (decryptOption == 'B') {
            // Decryption process with hexadecimal input
            string hexInput;
            do {
                cout << "\nEnter your special key: ";
                getline(cin, key);
                if (!isValidInput(key)) {
                    cerr << "\n**Key cannot be empty. Please enter a valid key**\n";
                }
            } while (!isValidInput(key));

            do {
                cout << "\nEnter the hexadecimal message to decipher: ";
                getline(cin, hexInput);
                istringstream hexStream(hexInput);
                hexInput = "";
                string hexPart;
                while (hexStream >> hexPart) {
                    hexInput += hexPart;
                }
                // Check if the hexadecimal input is valid
                if (!isValidHex(hexInput)) {
                    cerr << "\n**Invalid hexadecimal input. Please enter a valid hexadecimal number**" << endl;
                }
            } while (!isValidHex(hexInput));

            // Deciphering the hexadecimal input
            string decryptedText = "";
            for (size_t i = 0; i < hexInput.size(); i += 2) {
                string hexPair = hexInput.substr(i, 2);
                int hexValue = stoi(hexPair, nullptr, 16);
                char decryptedChar = static_cast<char>(hexValue ^ key[i / 2 % key.size()]);
                decryptedText += decryptedChar;
            }

            cout << "Your deciphered message: " << decryptedText << endl;
            break;
        } else {
            cerr << "\n**Invalid choice. Please choose 'A' or 'B'**" << endl;
        }
    } while (true);
}

void morseCodeCipher(){

    // Initialize maps for ciphering and deciphering
    unordered_map<char, string> AlphabetToMorse = {
        {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."},
        {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
        {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."},
        {'S', "..."}, {'T', "-"}, {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
        {'Y', "-.--"}, {'Z', "--.."}
    };

    // Initialize reverse map for deciphering
    unordered_map<string, char> MorseToAlphabet;
    for (const auto& pair : AlphabetToMorse) {
        MorseToAlphabet[pair.second] = pair.first;
    }

    // Main menu loop
    while (true) {
        cout << "\nA) Cipher a message\nB) Decipher a message\nC) Exit\n";
        cout << "\nPlease enter your choice: ";

        char choice;
        cin >> choice;
        choice = toupper(choice);
        cin.ignore(); // Clear input buffer

        // Process user choice
        if (choice == 'A') {
            cipherMessage(AlphabetToMorse);
        } else if (choice == 'B') {
            decipherMessage(MorseToAlphabet);
        } else if (choice == 'C') {
            cout << "\nExiting ..." << endl;
            break;
        } else {
            // Invalid choice
            cerr << "\n**Invalid choice. Please choose a valid option**" << endl;
        }
    }
}

// Function to check if a character is alphabetic
bool isAlphabetic(char c) {
    return isalpha(c);
}

// Function to check if a character is Morse character
bool isMorseCharacter(char c) {
    return c == '.' || c == '-';
}

// Function to cipher a message
void cipherMessage(const unordered_map<char, string>& AlphabetToMorse) {
    string input_text;
    while (true) {
        // Prompt user to enter message
        cout << "\nEnter your message to cipher: ";
        getline(cin, input_text);

        // Check for empty input
        if (input_text.empty()) {
            cout << "\n**Empty input. Please enter some Morse code to cipher**" << endl;
            continue;
        }

        string encrypted_text = ""; // Encrypted message
        bool hasError = false; // Flag to track errors

        // Process each character in the input text
        for (char character : input_text) {
            // Check if the character is alphabetic
            if (isAlphabetic(character)) {
                char upper_char = toupper(character);
                encrypted_text += AlphabetToMorse.at(upper_char) + " "; // Convert character to Morse code
            }
            else {
                cout << "\n**Invalid input. Please enter only alphabetic characters**" << endl; // Error for non-alphabetic characters
                hasError = true;
                break;
            }
        }

        // Output encrypted text or error message
        if (!hasError) {
            cout << "Your ciphered message: " << encrypted_text << endl;
            break;
        }
    }
}

// Function to decipher a message
void decipherMessage(const unordered_map<string, char>& MorseToAlphabet) {
    string input_text;
    while (true) {
        // Prompt user to enter message
        cout << "\nEnter your message to decipher: ";
        getline(cin, input_text);

        // Check for empty input
        if (input_text.empty()) {
            cout << "\n**Empty input. Please enter some Morse code to decipher**" << endl;
            continue;
        }

        string decrypted_text = ""; // Decrypted message
        string morse_code = ""; // Morse code sequence
        bool hasError = false; // Flag to track errors

        // Process each character in the input text
        for (char character : input_text) {
            // Check if the character is Morse character or space
            if (isMorseCharacter(character) || character == ' ') {
                // If it's a space, try to decipher Morse code sequence
                if (character == ' ') {
                    if (!morse_code.empty()) {
                        // Check if Morse code exists in the reverse map
                        if (MorseToAlphabet.find(morse_code) != MorseToAlphabet.end()) {
                            decrypted_text += MorseToAlphabet.at(morse_code); // Add decoded character to decrypted text
                            morse_code = ""; // Reset Morse code sequence
                        }
                        else {
                            hasError = true; // Set error flag
                            break;
                        }
                    }
                }
                else {
                    morse_code += character; // Add Morse character to Morse code sequence
                }
            }
            else {
                cout << "\n**Invalid Morse code. Please enter only '.' and '-' characters**" << endl; // Error for invalid Morse code characters
                hasError = true;
                break;
            }
        }

        // Check if there was an error during decryption
        if (!hasError) {
            // Check if there's remaining Morse code to decipher
            if (!morse_code.empty()) {
                // Check if Morse code exists in the reverse map
                if (MorseToAlphabet.find(morse_code) != MorseToAlphabet.end()) {
                    decrypted_text += MorseToAlphabet.at(morse_code); // Add decoded character to decrypted text
                }
                else {
                    cout << "\n**Invalid Morse code. Please enter Morse code characters separated by spaces**" << endl; // Error for incomplete Morse code sequence
                    continue;
                }
            }
            cout << "Your deciphered message: " << decrypted_text << endl;
            break;
        }
    }

}

void affineCipher(){
    cout << "\nWelcome to Affine Cipher!!\n\n";
    while (true) {
        cout << "\nA) Cipher a message\nB) Decipher a message\nC) Exit\n";
        cout << "\nPlease enter your choice: ";
        char choice;
        cin >> choice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        choice = toupper(choice);
        string key;
        if (choice == 'A') {
            cout << "\nEnter the message to cipher: ";
            string message;
            getline(cin, message);
            cout << "\nYour ciphered message: " << encryptedMessage(message);
        } else if (choice == 'B') {
            cout << "\nEnter the message to decipher: ";
            string message;
            getline(cin, message);
            cout << "\nYour deciphered message: " << decryptedMessage(encryptedMessage(message));
        } else if (choice == 'C') {
            cout << "\nExiting ..." << endl;
            break;
        } else {
            cout << "\nInvalid choice. Please choose a valid option\n" << endl;
        }
    }
}

string encryptedMessage(string originalMessage)
{
    string encryptedText = "";
    int a = 5;
    int b = 8;
    for (int i = 0; i < originalMessage.length(); i++)
    {
        if(isalpha(originalMessage[i])){
            encryptedText = encryptedText + (char) ((((a * (originalMessage[i] - 'A')) + b) % 26) + 'A');
        } else {
            encryptedText += originalMessage[i];
        }
    }
    return encryptedText;
}

string decryptedMessage(string encryptedText)
{
    string decryptedText = "";
    int a = 5;
    int b = 8;
    int a_inv = 0;
    int flag = 0;
    for (int i = 0; i < 26; i++)
    {
        flag = (a * i) % 26;
        if (flag == 1)
        {
            a_inv = i;
        }
    }
    for (int i = 0; i < encryptedText.length(); i++)
    {
        if(isalpha(encryptedText[i])){
            decryptedText = decryptedText + (char) (((a_inv * ((encryptedText[i] - 'A' - b + 26)) % 26)) + 'A');
        } else {
            decryptedText += encryptedText[i];
        }
    }
    return decryptedText;
}

void simpleSubstCipher(){
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    string cipher_alpha = "";

    while (true) {
        cout << "\n\nWelcome to Simple Substitution Cipher.\n";
        cout << "\nA) Cipher a message\nB) Decipher a message\nC) Exit\n";
        cout << "\nPlease enter your choice: ";

        char choice;
        cin >> choice;
        choice = toupper(choice); // To accept small letter

        string key;
        string messg;
        cin.ignore();

        while (choice == 'A' || choice == 'B') {

            cout << "\nEnter a key: ";
            getline(cin,key);
            key.erase(remove_if(key.begin(), key.end(), ::isspace), key.end()); // To remove space 
            for (char& c: key)
                c = tolower(c);
            if ( ! is_valid( key )){
                cout << "\n** Key must be 5 unique letters **\n";
                continue;
            }
            cipher_alpha.clear();
            M_cipher_alpha(alpha , cipher_alpha , key);
            cout << "\nEnter your message: ";
            getline(cin, messg);
            cout << alpha << "\n" << cipher_alpha;
            for (char& c: messg)
                c = tolower(c);

            if (choice == 'A')
                cout << "\nYour cipher message: " << simple_cip_dis( alpha , cipher_alpha , messg);
            else if (choice == 'B')
                cout << "\nYour Decipher message: " << simple_cip_dis(cipher_alpha , alpha , messg);
        }
        if (choice == 'C') {
            cout << "\nExiting ...\n";
            break;
        } else if (choice != 'A' && choice != 'B' && choice != 'C')
            cout << "\n** This is an invalid choice **\n ";
    }
}

bool is_valid(string& key){
    bool flag = true;
    for (int k = 0 ; k<key.length() ; k++){
        for (int i = k+1 ; i< key.length();i++){
            if ( key[k] == key[i] || key . length() != 5){
                flag = false;
                cout<<"   " <<key[k]  << key[i] << "   ";
            }
        }
    }
    return flag;
}
void M_cipher_alpha( string& alpha , string& cipher_alpha , string& key){
    cipher_alpha += key;
    for ( char& c : alpha ){
        bool flag = true;
        for ( char& k : key){
            if ( c == k )
                flag = false;
        }
        if (flag)
            cipher_alpha += c;
    }
}
string simple_cip_dis(string& list_from ,string& list_to ,string& messg){
    string result = "";
    for (int i = 0; i < messg.length(); i++) {
        if (messg[i] == ' ')
            result += messg[i];
        for (int g = 0; g < list_from.length(); g++){
            if (messg[i] == list_from[g])
                result += list_to[g];

        }
    }
    return result;
}


void railFenceCipher() {
    // Welcome message
    cout << "Welcome to the Rail Fence Cipher program!\n";
    cout << "note: if the rails number is >= input length, the ciphered text will be the same as the input\n";

    // Input gathering
    string input;
    int rails;
    string cipheredText;
    cout << "Enter the input: ";
    getline(cin, input);
    cout << "Enter the number of rails: ";
    cin >> rails;

    // Perform Rail Fence Cipher encryption
    railFenceEncrypt(input, rails, cipheredText);

}

// Function to perform Rail Fence Cipher encryption
void railFenceEncrypt(const string& plainText, int rails, string& cipheredText) {
    // Create a 2D vector to represent the rail fence structure
    vector<vector<char>> fence(rails, vector<char>(plainText.length(), ' '));

    int row = 0;
    bool down = false;

    // Fill the fence with characters from the plaintext
    for (int i = 0; i < plainText.length(); ++i) {
        fence[row][i] = plainText[i];
        // Change direction if reaching the top or bottom rail
        if (row == 0 || row == rails - 1)
            down = !down;
        row += down ? 1 : -1;
    }

    // Construct the ciphered text by reading off characters from the fence
    cipheredText.clear();
    for (int i = 0; i < rails; ++i) {
        for (int j = 0; j < plainText.length(); ++j) {
            // Only append non-empty characters to the ciphered text
            if (fence[i][j] != ' ')
                cipheredText += fence[i][j];
        }
    }

    // Output the ciphered text
    cout << "The Ciphered Text Is: " << cipheredText << endl;
}

string input;

void vigenereCipher(string& input) {
    cout << "\nWelcome to the Vigenere Cipher!\n\n";

    char choose;

    // Main menu loop
    do {
        // Display menu options
        cout << "Choose if You Want to Cipher or Decipher or Exit:\n";
        cout << "A. Cipher \n";
        cout << "B. Decipher \n";
        cout << "C. Exit\n";
        cout << "Enter your choice: ";

        // Input choice from user
        cin >> choose;

        // Check for non-numeric input
        if (cin.peek() != '\n') {
            cout << "Invalid choice. Please try again.\n";
            cin.clear(); // Clear the error flag on cin
            while (cin.get() != '\n') // Discard remaining input until newline is encountered
                continue;
            continue; // Restart the loop
        }

        // Convert lowercase input to uppercase
        if (choose == 'a' || choose == 'b' || choose == 'c') {
            choose = toupper(choose);
        }

        // Validate choice
        if (choose != 'A' && choose != 'B' && choose != 'C') {
            cout << "Invalid choice. Please try again.\n";
            cin.clear();
            cin.ignore();
            continue;
        }

        cin.ignore();

        // Execute the chosen program or feature
        switch (choose) {
            case 'A':
                userInput();
                userKey();
                vigenereDecrypt();
                break;
            case 'B':
                userInput();
                userKey();
                vigenereEncrypt();
                break;
            case 'C':
                cout << "Exiting ...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choose != 'C');
}

const int maxInputLetters = 80;
const int maxKeyLetters = 8;

string key;

void userInput() {
    cout << "Enter the message: ";
    getline(cin, input);
    for(char letter : input) {
        if (input.length() > maxInputLetters) {
            cout << "Too many letters entered. Please limit to " << maxInputLetters << " letters." << endl;
            userInput();
        }
    }
}

void userKey() {
    cout << "Enter the key: ";
    getline(cin, key);
    for(char letter : key){
        if (key.length() > maxKeyLetters){
            cout << "Too many letters entered. Please limit to " << maxKeyLetters << " letters." << endl;
            userKey();
        }
    }
    transform(key.begin(), key.end(), key.begin(), ::toupper); // Convert key to uppercase
}

void vigenereEncrypt() {
    string encryptedMessage = "";
    int keyIndex = 0;

    for (char c : input) {
        c = toupper(c);
        if (isalpha(c)) {  // Check if the character is a letter
            int shift = (key[keyIndex % key.length()] - 'A') * (true ? 1 : -1);
            char encryptedChar = ((c - 'A' + shift + 26) % 26) + 'A';
            encryptedMessage += encryptedChar;
            keyIndex++;
        } else {
            encryptedMessage += c;
            keyIndex++;
        }
    }
    cout << "Encrypted message: " << encryptedMessage << endl;
}

void vigenereDecrypt() {
    string decryptedMessage = "";
    int keyIndex = 0;

    for (char c : input) {
        c = toupper(c);
        if (isalpha(c)) {  // Check if the character is a letter
            int shift = (key[keyIndex % key.length()] - 'A') * -1;
            char decryptedChar = ((c - 'A' + shift + 26) % 26) + 'A';
            decryptedMessage += decryptedChar;
            keyIndex++;
        } else {
            decryptedMessage += c;
            keyIndex++;
        }
    }
    cout << "Decrypted message: " << decryptedMessage << endl;
}
void PolybiusCipher(){
    char alpha [5][5] = {{'A','B','C','D','E'},{'F','G','H','I','K'},{'L','M','N','O','P'},{'Q','R','S','T','U'},{'V','W','X','Y','Z'}};
    while (true) {
        cout << "\n\nWelcome to Polybius Square Cipher\n";
        cout << "\nA) Cipher a message\nB) Decipher a message\nC) Exit\n";
        cout << "\nPlease enter your choice: ";

        char choice;
        cin >> choice;
        choice = toupper(choice); // To accept small letter

        string key;
        string messg;
        cin.ignore();

        while (choice == 'A' || choice == 'B') {
        
            cout << "\nEnter a key: ";
            getline(cin,key);
            key.erase(remove_if(key.begin(), key.end(), ::isspace), key.end()); // To remove space 
            if ( !is_valid_p (key) ){
                cout << "\n** This is not valid , key mest be 1,2,3,4,5 with any order **\n";
                continue;
            }
            
            cout << "\nEnter your message: ";
            getline(cin, messg);
            
            for (char& c: messg)
                c = toupper(c);
            break;
        }
        if (choice == 'A')
            cipher(messg , alpha , key);
        else if (choice == 'B')
            Decipher(messg , alpha , key); 
        else if (choice == 'C')
            cout << "\nExiting ...\n";    
        else 
            cout << "\n** This is an invalid choice **\n ";
        
        
    }
}
bool is_valid_p (string& key){
    bool valid = true;
    for (char& c: key){
        if ( c !='1'&&c !='2' && c !='3' && c !='4' && c !='5' || key.length() !=5){
            valid = false;
        }
    }
    return valid;
}

void cipher(string& messg, char alpha[5][5] , string& key){
    cout << "\nYour cipher message: " ;
    for (char& c : messg){
        if (c == 'J')
            c = 'I';
        for(int i=0 ; i<5 ; i++){
            for (int k =0 ; k<5 ; k++){
                if ( c == alpha[i][k])
                    cout << key[i] << key[k];
            }
        }
        if (c == ' ')
            cout << c;
    }
}
void Decipher(string& messg , char alpha[5][5] , string& key){
    cout << "\nYour Decipher message: " ;
    string TWO_char = "";
    int i = 0, k = 0;
    for (char c : messg){
        if (c == '1' || c == '2' || c == '3' || c == '4' || c == '5' ){
            while (TWO_char.length()<3){
                TWO_char += c;
                if (TWO_char.length() == 2){
                    while ( i < 5 ){
                        if (TWO_char[0] == key [i])
                            break;
                        else i++;
                    }
                    while ( k < 5 ){
                        if (TWO_char[1] == key [k]) 
                            break; 
                        else k++;
                    }
                    cout << alpha[i][k] ;
                    TWO_char.clear();
                    i=0,k=0;
                }
                break;
            }
        }
       if (c == ' ')
            cout << c;
    }
}
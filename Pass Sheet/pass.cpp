#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Function to generate codes recursively
void generateCodes(string prefix, const string& characters, int length, vector<string>& codes) {
    if (prefix.length() == length) {
        codes.push_back(prefix);
        return;
    }
    
    for (char ch : characters) {
        generateCodes(prefix + ch, characters, length, codes);
    }
}

// Function to save generated codes to a file
void saveToFile(const vector<string>& codes, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const string& code : codes) {
            file << code << endl;
        }
        file.close();
        cout << "Generated codes saved to " << filename << endl;
    } else {
        cerr << "Unable to open file: " << filename << endl;
    }
}

int main() {
    try {
        int length;
        char includeTextChoice, includeNumbersChoice;
        bool includeText, includeNumbers;

        cout << "Enter the length of the code: ";
        cin >> length;

        cout << "Include text (y/n): ";
        cin >> includeTextChoice;
        includeText = (tolower(includeTextChoice) == 'y');

        cout << "Include numbers (y/n): ";
        cin >> includeNumbersChoice;
        includeNumbers = (tolower(includeNumbersChoice) == 'y');

        if (length <= 0) {
            cerr << "Invalid length! Please enter a positive number." << endl;
            return 1;
        }

        // Create character set based on user input
        string characters;
        if (includeText) {
            characters += "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"; // A-Z, a-z
        }
        if (includeNumbers) {
            characters += "0123456789"; // 0-9
        }

        if (characters.empty()) {
            cerr << "No characters selected! Please include text or numbers." << endl;
            return 1;
        }

        // Generate codes
        vector<string> codes;
        generateCodes("", characters, length, codes);

        // Save codes to file
        saveToFile(codes, "codes.txt");
        
    } catch (exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}

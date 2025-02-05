#include <iostream>
using namespace std;

int main() {
    const int SIZE = 100;  // Size of the buffer
    char string[SIZE];     // Buffer to hold the input

    cout << "Enter a line of text: ";
    cin.getline(string, SIZE);  // Read a line of text from the user

    cout << "You entered: " << string << endl;

        char buffer[SIZE];

    cout << "Enter a line of text (ending with ';'): ";
    cin.getline(buffer, SIZE, ';');  // Read input until ';' is encountered     here ; is custom delimator

    cout << "You entered: " << buffer << endl;

    return 0;
    return 0;
}

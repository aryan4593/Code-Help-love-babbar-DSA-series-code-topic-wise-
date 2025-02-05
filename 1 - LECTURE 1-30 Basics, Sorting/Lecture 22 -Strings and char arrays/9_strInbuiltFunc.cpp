#include <iostream>
#include <string>

using namespace std;

int main() {
    // Creating and initializing strings
    string str1 = "Hello, ";
    string str2 = "world!";
    
    // Concatenation
    string str3 = str1 + str2;
    cout << "Concatenated string: " << str3 << endl;
    
    // Length of the string
    cout << "Length of str3: " << str3.length() << endl;
    
    // Substring
    string str4 = str3.substr(7, 5); // Extracts "world"
    cout << "Substring of str3: " << str4 << endl;

    // comparing 
    
    
    // Find
    size_t pos = str3.find("world");
    
    if (pos != string::npos) {
        cout << "'world' found at position: " << pos << endl;
    } else {
        cout << "'world' not found" << endl;
    }

    // Replace
    str3.replace(7, 5, "C++");
    cout << "After replacement: " << str3 << endl;
    
    // Erase
    str3.erase(5, 4); // Erase ", C++"
    cout << "After erasing: " << str3 << endl;
    
    // Insert
    str3.insert(5, " amazing");
    cout << "After insertion: " << str3 << endl;
    
    // Compare
    if (str1 == "Hello, ") {
        cout << "str1 equals 'Hello, '" << endl;
    }
    
    // Converting to C-string
    const char* cstr = str3.c_str();
    cout << "C-string representation: " << cstr << endl;

    

    return 0;
}

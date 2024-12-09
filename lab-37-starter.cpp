#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
using namespace std;

void menu();

int gen_hash_index(string chars);

int main() {
    map <int, list<string>> hash_table;
    // Read from data file.
    ifstream file("lab-37-data.txt");
    string line;
    int choice;

    if (file.is_open()) {
        while (getline(file, line)) {
            // Store hash index and string into file.
            int index = gen_hash_index(line);
            hash_table[index].push_back(line);
        }
        file.close();
    }
    else {
        cout << "Unable to open file" << endl;
    }

    menu();
    cout << "Your choice: ";
    cin >> choice;

    while (choice != 6) {
        switch (choice) {
            case 1: {
                // Output first 100 map entries.
                int count = 0;
                int count2 = 0;
                // Loop through the hash indexes.
                for (const auto& pair : hash_table) {
                    cout << count << endl;
                    if (count == 100) {
                        break;
                    }
                    cout << "Hash Index: " << pair.first << ", Value: ";
                    // Loop through the list of string codes.
                    for (const auto& code : pair.second) {
                        while(count2 != 100) {
                            cout << code << " ";
                            count2++;
                        }
                    }
                    count2 = 0;
                    cout << endl;

                    count++;
                }
                break;
            }
            case 2: {
                // Search for a key.
                string key = " ";
                cout << "Enter a key to search for: ";
                cin >> key;
                bool found = false;
                // Loop through map container.
                for (const auto&pair : hash_table){
                    // Loop through hash_table keys in list container.
                    for (const auto& code : pair.second) {
                        if (code == key) {
                            cout << "Key found!" << endl;
                            found = true;
                            break;
                        }
                    }
                    if (found) {
                        break;
                    }
                }
                if (!found) {
                    cout << "Key not found." << endl;
                }
                break;
            }
            default:
                cout << "Invalid choice, try again." << endl;
                break;
            
        }
        menu();
        cout << "Your choice: ";
        cin >> choice;
    }

    return 0;
}

int gen_hash_index(string chars) {
    int sum = 0;
    for (char c: chars) {
        sum += (int) c;
    }
    return sum;
}

void menu() {
    cout << "Select an option: " << endl;
    cout << "\t[1] Display first 100 entries." << endl;
    cout << "\t[2] Search for a key." << endl;
    cout << "\t[3] Add a key." << endl;
    cout << "\t[4] Remove a key." << endl;
    cout << "\t[5] Modify a key." << endl;
    cout << "\t[6] Exit." << endl;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/

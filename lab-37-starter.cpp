#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
using namespace std;

int gen_hash_index(string chars);

int main() {
    map <int, list<string>> hash_table;
    // Read from data file.
    ifstream file("lab-37-data.txt");
    string line;

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

    // Output first 100 map entries.
    int count = 0;
    for (const auto& pair : hash_table) {
        if (count >= 100) {
            break;
        }
        cout << "Hash Index: " << pair.first << ", Value: ";
        for (const auto& code : pair.second) {
            cout << code << " ";
        }
        cout << endl;
        count++;
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

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/

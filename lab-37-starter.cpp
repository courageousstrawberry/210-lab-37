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
            int index = gen_hash_index(line);
            hash_table[index].push_back(line);
        }
        file.close();
    }
    else {
        cout << "Unable to open file" << endl;
    }

    return 0;
}

int gen_hash_index(string chars) {
    int sum = 0;
    for (char c: chars) {
        sum += ((char) c);
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

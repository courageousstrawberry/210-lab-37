#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int sum_ascii(string chars);

int main() {
    int total;
    // Read from data file.
    ifstream file("lab-37-data.txt");
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            total += sum_ascii(line);
        }
        file.close();
    }
    else {
        cout << "Unable to open file" << endl;
    }

    cout << total;
    return 0;
}

int sum_ascii(string chars) {
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

#include <iostream>
using namespace std;

int sum_ascii(string chars);

int main() {
    char a = 'A';
    cout << a << endl;
    cout << (int) a << endl;
    int b = 66;
    cout << b << endl;
    cout << (char) b << endl;
    

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

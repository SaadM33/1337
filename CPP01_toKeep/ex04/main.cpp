#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream file("output.txt");
    string line;

    if (!file) {
        cerr << "Cannot open file.\n";
        return 1;
    }

    while (getline(file, line))
        cout << line ;

    file.close();
}

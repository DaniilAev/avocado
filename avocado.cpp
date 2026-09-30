#include <fstream>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <string>
using namespace std;
int main(int argc, char** argv){
    fstream file("C:\\avocado\\timeline.txt", ios::app);
    string path = argv[0];
    if (!file){
        cout << "Unable to open the file.";
        return 1;
    }

    const auto now = chrono::system_clock::now();
    const time_t time = chrono::system_clock::to_time_t(now);
    file << put_time(localtime(&time), "%Y-%m-%d %H:%M:%S\n");
    file.close();
    return 0;

}
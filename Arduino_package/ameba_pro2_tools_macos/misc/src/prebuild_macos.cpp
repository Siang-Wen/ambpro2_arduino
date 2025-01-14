/*

Compile:

windows:
mingw32-g++.exe -o prebuild_windows.exe prebuild_windows.cpp -static

linux:
g++ -o prebuild_linux prebuild_linux.cpp -static

macos:
g++ -o prebuild_macos prebuild_macos.cpp

*/

#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <unistd.h>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    stringstream cmdss;
    string cmd;

    chdir(argv[1]);
    chdir("..");

    cmdss.clear();
//    cmdss << "cp -r ./" << argv[3] << "/* " << argv[2] << " 2> /dev/null " ;
//    cmdss << "find ./ -mindepth 1 -maxdepth 1 -type d -name \"" << argv[3] << "\" | xargs -i cp -r {}/*" << " ./"<< argv[2];
    cmdss << "find ./" << argv[3] << " -mindepth 1 -maxdepth 1 -type d -name \"*\" 2>/dev/null | xargs -i cp -r {}" << " ./"<< argv[2];
    getline(cmdss, cmd);
    cout << cmd << endl;
    system(cmd.c_str());

    cmdss.clear();
    cmdss << "rm -rf " << argv[3] <<"/*";
    getline(cmdss, cmd);
    //cout << cmd << endl;
    system(cmd.c_str());

    return 0;
}

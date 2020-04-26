///....DH....///
#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#include "testlib.h"
#define task                ""
#define fi(a)               freopen(a, "r", stdin)
#define fo(a)               freopen(a, "w", stdout)
#define IO                  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

string filegen, filerun, filebai, fileinp, fileout, from;
clock_t start, finish;
int numoftest;
double timelimit;
bool novalid, nocheck;

void Inc(string &from) {
    int ram = 0, sum = 0;
    for(int i = from.size() - 1; i >= 0; i--) {
        if(i == from.size() - 1)
            sum = (from[i] - '0') + 1 + ram;
        else
            sum = (from[i] - '0') + ram;
        ram = sum / 10;
        sum %= 10;
        from[i] = char(sum + '0');
    }
    if(ram > 0)
        from.insert(0, 1, char(ram + '0'));
    return ;
}

int main() {
    /// Write all of the necessary things in maketest.txt
    /// If you don't know how to use it, see here: https://github.com/tacongnam/Generate-Test-and-Checker

    fi("maketest.txt");
    cin >> filegen;
    cerr << "filegen: " << filegen << "\n";
    cin >> filerun;
    cerr << "filerun: " << filerun << "\n";
    cin >> filebai;
    cerr << "filebai: " << filebai << "\n";
    cin >> fileinp;
    cerr << "fileinp: " << fileinp << "\n";
    cin >> fileout;
    cerr << "fileout: " << fileout << "\n";
    cin >> from;
    cerr << "from: " << from << "\n";
    cin >> numoftest;
    cerr << "numoftest: " << numoftest << "\n";
    cin >> timelimit;
    cerr << "timelimit: " << timelimit << "\n";
    cin >> novalid;
    cerr << "novalid: " << novalid << "\n";
    cin >> nocheck;
    cerr << "nocheck: " << nocheck << "\n";

    cerr << "\nGet input...\n";
    system(("mkdir \"" + filebai + "\"").c_str());
    this_thread::sleep_for(5s);
    system("cls");

    ofstream file;
    file.open("logs.txt");
    while(numoftest--) {
        cerr << "\nGenerate test...";
        if(system(filegen.c_str()) != 0) {
            file << "Something are error. It can be your generator. Fix them and try again.\nError code: -1";
            file.close();
            return -1;
        }
        else
            cerr << "\nGenerated!";

        /// Check input using validator:
        /// If you don't know how to make a validator, see here: https://github.com/tacongnam/Generate-Test-and-Checker
        if(novalid == true) {
            cerr << "\nCheck input...";
            if(system("validator.exe") != 0) {
                file << "Something are error. It can be your input or your validator. Fix them and try again.\nError code: 1";
                file.close();
                return 1;
            }
            else
                cerr << "\nChecked!";
        }

        /// Run code:
        cerr << "\nRunning code...";
        start = clock();
        if(system(filerun.c_str()) != 0) {
            file << "Something are error. Your solution doesn't return 0. Fix it and try again.\nError code: 2";
            file.close();
            return 2;
        }
        finish = clock();
        if(double(finish - start) / CLOCKS_PER_SEC > timelimit) {
            file << "Something are error. Your code has TLE verdict. Fix it and try again.\nError code: 3";
            file.close();
            return 3;
        }
        else
            cerr << "\nRan ok!";

        /// When input and output are already:
        cerr << "\nMake directory and copy test...";
        /// Make a new directory
        system(("mkdir \"Test" + from + "\"").c_str());
        /// Copy file input and output into this new directory:
        system(("copy " + fileinp + " Test" + from).c_str());
        system(("copy " + fileout + " Test" + from).c_str());
        system(("move Test" + from + " " + filebai + "\"").c_str());
        cerr << "\nTest " + from << ": ok\n";
        Inc(from);
        this_thread::sleep_for(1s);
        system("cls");
    };

    system(("Rar.exe a " + filebai + ".rar " + filebai).c_str());
    file << "OK!\n";
    file.close();
    cout << "OK!";
    return 0;
}

/*

By: Jo�o Neves (SHIVAYL)

*/

#include <iostream>
#include <cstdio>
#include <clocale>
using namespace std;

#include "./includes/exerciseSelector.hpp"

int main(int argc, char** argv) {
    setlocale(LC_ALL, "");
    
    cout << "Pragram made by: Jo�o Neves (shivayl)" << endl << endl;
    cout << "Hello" << endl;
    
    // Event loop (the program engine).
    int selector = 1;
    while(selector) {
        exerciseSelector(selector);
    }
    
    /* system("pause"); */
	return 0;
}


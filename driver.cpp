/**
	-CS219 PP3, Driver-
    Starts titlescreen, processes the txt file, and begins all
	other functions.
    @file driver.cpp
    @author Robb Northrup
    @version 1.0 4/5/2022
*/

#include <iostream>
#include <fstream>
#include <string>
#include "start.h"
#include "hexoperations.h"

using std::endl, std::cout;

int main() {
	TitleScreen();

	try {
		Processor(LoadFile("input.txt"));
		//std::cout << "PROCESSED FILE" << std::endl;
	}
	catch (const char* msg) {
		std::cerr << msg << std::endl;
	}
	std::cout << "==========================================" << std::endl;
	std::cout << std::endl;

	return 0;
}
/**
	-CS219 PP3, Start File-
    Will process the "operations.txt" file using the processes from
	the hexoperations.cpp file and basic file I/O.  Title screen
	included.
    @file start.cpp
    @author Robb Northrup
    @version 1.0 4/5/2022
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "start.h"
#include "hexoperations.h"

using std::endl, std::cout;

/**
    Loads file, ensures it can open.
    @param fileName - given by Start() function when called
    @return inFile - file to be decoded and perform the 
					 appropriate functions
*/

std::ifstream LoadFile(std::string fileName) {
	std::ifstream inFile;
	
	inFile.open(fileName);
	if (inFile.fail()) { //throw if fails to open the file
		throw ("FAILED TO OPEN \"" + fileName + "\"!");
	}
	
	return inFile;
}

/**
    Writes file to the console
    @param inFile
*/

void DisplayFile(std::ifstream &inFile) {
	while(!inFile.eof()) {
			std::string temp;
			inFile >> temp;
			std::cout << temp << std::endl;
		} //doesn't display the doc with tabs, only spaces . . . so far
}

/**
    Converts hexidecimal number to decimal.
    @param inFile - file with commands to perform the functions
					already designated to the program.
*/

void Processor(std::ifstream inFile) {
	uint32_t r[8];
	std::string op;
	std::string arg1;
	std::string arg2;
	std::string arg3;
	std::string temp; //used to store other arg
	bool useStoredValue = false;

	//std::cout << "IN PROCESSOR" << std::endl;
	int i = 1;
	do {
		//std::cout << "reading line " << i << std::endl;
		if (useStoredValue == false)
			inFile >> op;
		else {
			op = temp;
			useStoredValue = false;
		}
		if (op == "ADD" || op == "AND" || op == "ORR" || op == "SUB" || op == "XOR") { //operations that require 3 operators
			inFile >> arg1;
			inFile >> arg2;
			inFile >> arg3;

			if (!(((arg1[0] == 'r' || arg1[0] == 'R') && (arg1.length() == 2)) && (arg2.substr(0,3) == "#0x" || ((arg2.substr(0,1) == "r" || arg2.substr(0,1) == "R") && arg2.length() == 2)) && (arg3.substr(0,3) == "#0x" || ((arg3.substr(0,1) == "r" || arg3.substr(0,1) == "R") && arg3.length() == 2)))) //checks to see that the arguments (operands) are within bounds as an immediate hex number, or a specified register
				throw ("THE FILE IS FORMATTED INCORRECTLY!\nOPERANDS AREN'T IN CORRECT HEX FORM OR NUMBER OF OPERANDS IS INCORRECT");

			if ((arg1[0] == 'r' || arg1[0] == 'R')) { //check for register in scope
				if (!isdigit(arg1[1]) || ((((arg1[1] - '0') > 7)) || ((arg1[1] - '0') < 0)))
					throw ("INVALID REGISTER ACCESSED");
			}
			if ((arg2[0] == 'r' || arg2[0] == 'R')) {
				if (!isdigit(arg2[1]) || ((((arg2[1] - '0') > 7)) || ((arg1[1] - '0') < 0)))
					throw ("INVALID REGISTER ACCESSED");
			}
			else if ((arg3[0] == 'r' || arg3[0] == 'R')) {
				if (!isdigit(arg3[1]) || ((((arg3[1] - '0') > 7)) || ((arg1[1] - '0') < 0)))
					throw ("INVALID REGISTER ACCESSED");
			}

			if (isalpha(arg2[0])) //if arg2 is register
				arg2 = ConvertDecimalToHex((r[arg2[1] - '0']));
			else if (arg2[0] == '#')
				arg2 = arg2.substr(1,arg2.length() - 1);
			if (isalpha(arg3[0])) //if arg3 is register
				arg3 = ConvertDecimalToHex((r[arg3[1] - '0']));
			else if (arg3[0] == '#')
				arg3 = arg3.substr(1,arg2.length() - 1);
				
			if (op == "ADD") { //should the operator be "ADD", will add the two hex numbers and spew an answer also to register in uint32_t
				r[arg1[1] - '0'] = ADD(ConvertHexToDecimal(arg2), ConvertHexToDecimal(arg3));
			}
			else if (op == "AND") { //bitwise "AND" on both operands
				r[arg1[1] - '0'] = AND(ConvertHexToDecimal(arg2), ConvertHexToDecimal(arg3));
			}
			else if (op == "ORR") { //bitwise "AND" on both operands
				r[arg1[1] - '0'] = ORR(ConvertHexToDecimal(arg2), ConvertHexToDecimal(arg3));
			}
			else if (op == "SUB") { //bitwise "AND" on both operands
				r[arg1[1] - '0'] = SUB(ConvertHexToDecimal(arg2), ConvertHexToDecimal(arg3));
			}
			else if (op == "XOR") { //bitwise "AND" on both operands
				r[arg1[1] - '0'] = XOR(ConvertHexToDecimal(arg2), ConvertHexToDecimal(arg3));
			}
		}
		else if (op == "ASR" || op == "LSR" || op == "LSL" || op == "NOT" || op == "MOV") { //if operator that only utilizes two operands
			inFile >> arg1;
			inFile >> arg2;

			if (!(((arg1[0] == 'r' || arg1[0] == 'R') && arg1.length() == 2) && (arg2.substr(0,3) == "#0x" || ((arg2[0] == 'r' || arg2[0] == 'R') && arg2.length() == 2)))) //checks to see that the arguments (operands) are within bounds as an immediate hex number, or a specified register
				throw ("THE FILE IS FORMATTED INCORRECTLY!\nOPERANDS AREN'T IN CORRECT HEX FORM OR NUMBER OF OPERANDS IS INCORRECT");

			if ((arg1[0] == 'r' || arg1[0] == 'R')) { //check for register in scope
				if (!isdigit(arg1[1]) || ((((arg1[1] - '0') > 7)) || ((arg1[1] - '0') < 0)))
					throw ("INVALID REGISTER ACCESSED");
			}
			if ((arg2[0] == 'r' || arg2[0] == 'R')) {
				if (!isdigit(arg2[1]) || (std::stoi((arg2.substr(1, arg2.length() - 1))) > 7))
					throw ("INVALID REGISTER ACCESSED");
			}

			if (isalpha(arg2[0])) //if arg2 is register
				arg2 = ConvertDecimalToHex((r[arg2[1] - '0']));
			else
				arg2 = arg2.substr(1,arg2.length());
			inFile >> temp;
			if (temp.substr(0,3) == "#0x" || temp[0] == 'r' || temp[0] == 'R') //if three operands for two-operand-specific operation
				{ }
			else
				useStoredValue = true;
			
			if (op == "ASR") {
				r[arg1[1] - '0'] = ASR(ConvertHexToDecimal(arg2));
			}
			else if (op == "LSR") {
				r[arg1[1] - '0'] = LSR(ConvertHexToDecimal(arg2));
			}
			else if (op == "LSL") {
				r[arg1[1] - '0'] = LSL(ConvertHexToDecimal(arg2));
			}
			else if (op == "NOT") {
				r[arg1[1] - '0'] = NOT(ConvertHexToDecimal(arg2));
			}
			else if (op == "MOV") {
				r[arg1[1] - '0'] = ConvertHexToDecimal(arg2);
			}
		}
		else { //operator doesn't exist?
			throw ("THE FILE IS FORMATTED INCORRECTLY!\nOPERANDS AREN'T IN CORRECT HEX FORM OR NUMBER OF OPERANDS IS INCORRECT");
		}
	} while(!inFile.eof()); //until end of doc

	for (auto y : r)
		std::cout << y << "\n";
}

/**
    Displays title
*/

void TitleScreen() {
	std::cout << "================================" << std::endl;
	std::cout << "----PROGRAMMING ASSIGNMENT 3----" << std::endl;
	std::cout << "================================" << std::endl; //yup
}
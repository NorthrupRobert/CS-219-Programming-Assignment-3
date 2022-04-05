#ifndef START_H
#define START_H

#include <fstream>

std::ifstream LoadFile(std::string fileName);
void Processor(std::ifstream inFile);
void DisplayFile(std::ifstream &inFile);
void TitleScreen();

#endif
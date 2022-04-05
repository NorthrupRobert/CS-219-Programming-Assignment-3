#ifndef HEXOPERATIONS_H
#define HEXOPERATIONS_H

#include <string>

uint32_t ConvertHexToDecimal(std::string hexFig);
std::string ConvertDecimalToHex(uint32_t decimalFig);
uint32_t ADD(uint32_t num1, uint32_t num2);
uint32_t AND(uint32_t num1, uint32_t num2);
uint32_t ASR(uint32_t num);
uint32_t LSR(uint32_t num);
uint32_t LSL(uint32_t num);
uint32_t NOT(uint32_t num);
uint32_t ORR(uint32_t num1, uint32_t num2);
uint32_t SUB(uint32_t num1, uint32_t num2);
uint32_t XOR(uint32_t num1, uint32_t num2);

#endif
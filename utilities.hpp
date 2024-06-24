#pragma once

#include <sstream>
#include <string>
#include <iostream>
#include <regex>

extern std::regex numPattern;
std::string getChoice(std::string, int, int);
std::string getMatrixInput(std::string, std::string, std::string);
std::string getVectorInput(std::string, std::string, std::string);
bool isNumber(const std::string&);
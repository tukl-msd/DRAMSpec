#ifndef ARGUMENTSPARSER_H
#define ARGUMENTSPARSER_H

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class ArgumentsParser {
public:
    ArgumentsParser(int argc, char** argv);

    vector<string> technologyFileName;
    vector<string> architectureFileName;
    unsigned int nConfigurations;
    bool IOTerminationCurrentFlag;

    ostringstream helpMessage;

    void runArgParser();

private:
    int cpargc;
    char** cpargv;
    int argvID;

    bool getTechFileName();
    bool getArchFileName();

};

#endif // ARGUMENTSPARSER_H

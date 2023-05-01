#ifndef LOG_HPP
#define LOG_HPP

#include <stdio.h>
#include <iostream>


#define $ fprintf(stdout, "Here on \"%d\" line in func:\"%s\"\n", __LINE__, __FUNCTION__);

#define $$ printLogFuncVar(__LINE__, __FUNCTION__);

#define LOG_MSG(text) fprintf(stdout, "%s\n", text);

#define LOG_CUR_VAR(var) CurLogMsg(__FUNCTION__, #var, var);

#define LOG_OBJECT(id, name) objectLogMsg(id, #name);

template <typename T>
void logPrintVar(T var)
{
    std::cout << "Var = " << var << "on line = " << __LINE__ << std::endl;
}

FILE* startLogging();

void  closeLogging();

void printLogFuncVar(int line, const char* funcName);

void CurLogMsg(const char* funcName, const char* varName, int varValue);

void objectLogMsg(int id, const char* name);

#endif
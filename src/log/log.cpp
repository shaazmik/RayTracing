#include "log.hpp"

FILE* PSlogfile = startLogging();

FILE* startLogging()
{
    FILE* logger = fopen("./log/log.txt", "w");

    if (!logger)
    {
        fprintf(stderr, "Logger can't launch. Something with creating file.\n");
        return nullptr;
    }

    atexit(closeLogging);

    return logger;
}

void closeLogging()
{   
    if (!PSlogfile)
    {
        fprintf(stderr, "Can't close \"log.txt\", func gets |nullptr|\n");
        return;
    }

    fclose(PSlogfile);
}

void printLogFuncVar(int line, const char* funcName)
{
    fprintf(PSlogfile, "Here on \"%d\" line in func:\"%s\"\n", line, funcName);
}

void CurLogMsg(const char* funcName, const char* varName, int varValue)
{
    fprintf(PSlogfile, "CUR VAR:|%s = %d| in func:\"%s\"\n\n",varName, varValue, funcName);
}

void objectLogMsg(int id, const char* name)
{
    fprintf(PSlogfile, "OBJECT |%s| and ID:%d\n", name, id);
}
#include "Execute.h"
#include "Arguments.h"

bool isCmd(char *line);

int main(void)
{
    Execute execute;
    Arguments arguments;
    char line[MAX_LINE];


    char **arg = arguments.init();


    while(true)
    {
        printf("> ");   fflush(stdout);

        memset(line, 0, MAX_LINE);
        arguments.reset();

        if(NULL == fgets(line, MAX_LINE, stdin))
            continue;
        if(0 == strcmp(line, "quit\n"))
            break;
        if(!isCmd(line))
            continue;

        arguments.format(line);

        execute.run(*arg, arg);

    }
    return 0;
}

bool isCmd(char *line)
{
    bool isCmdLine = false;
    char *p = line;
    while('\0' != *(p++))
    {
        if(' '!=*p && '\n'!=*p && '\t'!=*p)
        {
            isCmdLine = true;
            break;
        }
    }
    return isCmdLine;
}

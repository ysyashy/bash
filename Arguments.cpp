#include "Arguments.h"

char *ArgPool::get()
{
    int idx;
    for(idx=0; idx<ARG_NUM; idx++)
        if(_status[idx] == false)   /* idx处的空间未被使用 */
            break;
    _status[idx] = true;
    return _mem_arg[idx];
}

void ArgPool::put(char *ptr)
{
    int idx;
    for(idx=0; idx<ARG_NUM; idx++)
        if(_status[idx] == true)    /* idx处的空间正在被使用中 */
            break;
    _mem_arg[idx] = ptr;
}

char **Arguments::init()
{
    for(int i=0; i<ARG_NUM; i++)
        arg[i] = NULL;
    return this->arg;
}

void Arguments::reset()
{
    for(int i=0; i<ARG_NUM; i++)
    {
        if(NULL != arg[i])
        {
            argPool.put(arg[i]);
            arg[i] = NULL;
        }
    }
}

void Arguments::format(char *line)
{
    char *pLine = line;

    while('\0' != *(pLine++))      /* 去除行尾换行符 */
        if('\n' == *pLine)
        {
            *pLine = '\0';  break;
        }
    pLine = line;


    while(' '==*pLine && '\0'!=*pLine)  /* 忽略行首空格 */
        pLine++;

    int n = 0;



    while('\0' != *pLine)
    {
        if(' ' == *pLine)
        {
            pLine++; continue;
        }
        *(arg+n) = argPool.get();
        char *pArg = *(arg+n);
        while(' '!=*pLine && '\0'!=*pLine)
            *(pArg++) = *(pLine++);
        n++;
    }
}
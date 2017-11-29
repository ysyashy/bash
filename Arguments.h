#ifndef BASH_ARGUMENTS_H
#define BASH_ARGUMENTS_H

#include "public_header.h"
#include <stdlib.h>

#define ARG_NUM 128
#define ARG_LEN 128
typedef char * charPtr;

class ArgPool
{
private:
    char *_mem_arg[ARG_NUM];
    bool _status[ARG_NUM];
public:
    ArgPool()
    {
        for(int i=0; i<ARG_NUM; i++)
        {
            _mem_arg[i] = new char[ARG_LEN];
            _status[i] = false;
        }
    }
    char *get();
    void put(char *ptr);
    ~ArgPool()
    {
        for(int i=0; i<ARG_NUM; i++)
            delete[] _mem_arg[i];
    }
};

class Arguments
{
private:
    char *arg[ARG_NUM];
    ArgPool argPool;
public:
    char **init();
    void reset();
    void format(char *line);

};


#endif

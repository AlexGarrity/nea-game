#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
#include <string>


class Debug
{

    public:
        enum type {Warning, Error, Critical, Fatal};
        static void Log(std::string message, type errorType);


    protected:

    private:
};

#endif // DEBUG_H

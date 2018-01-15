/**     Alex Garrity, 2017      **/

#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
#include <string>
#include <cstdlib>

/*
Using this as a log level guide:
https://stackoverflow.com/questions/2031163/when-to-use-the-different-log-levels
Not flawless, but the first and third most voted-for answers are good
*/

class Debug {

public:
    //Kinda stole this idea from Unity, but it works, so I don't mind...
    enum type {Trace, Dbg, Info, Warn, Error, Fatal};
    static void Log(std::string message, type errorType);

protected:

private:
};

#endif // DEBUG_H

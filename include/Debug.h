/**     Alex Garrity, 2018      **/

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

/**
    The debug library is a useful development library that allows for enhanced logging
    and trace capabilities.
**/

class Debug {

public:
    //Kinda stole this idea from Unity, but it works, so I don't mind...
    enum type {Trace, Dbg, Info, Warn, Error, Fatal};
    static void Log ( std::string message, type errorType );

protected:

private:
};

#endif // DEBUG_H

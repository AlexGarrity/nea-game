#include "Debug.h"

void Debug::Log(std::string message, type errorType)
{
    std::string prefix;
    switch (errorType)
    {
    case Trace:
        prefix = "Trace";
        break;
    case Dbg:
        prefix = "Debug";
        break;
    case Info:
        prefix = "Information";
        break;
    case Warn:
        prefix = "Warning";
        break;
    case Error:
        prefix = "Error";
        break;
    case Fatal:
        std::cout << "A fatal error has occured: " << message << "The application will now terminate." << std::endl;
        return;
        break;
    }
    std::cout << prefix << ": " << message << std::endl;
}

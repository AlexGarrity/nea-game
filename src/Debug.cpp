#include "Debug.h"

void Debug::Log(std::string message, type errorType)
{
    std::string prefix;
    switch (errorType)
    {
    case Warning:
        prefix = "Warning";
        break;
    case Error:
        prefix = "Error";
        break;
    case Critical:
        prefix = "Critical";
        break;
    case Fatal:
        prefix = "Fatal";
        break;
    }
    std::cout << prefix << ": " << message << std::endl;
}

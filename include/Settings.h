/**     Alex Garrity, 2018      **/

#ifndef SETTINGS_H_INCLUDED
#define SETTINGS_H_INCLUDED

#include <string>
#include <SFML/Network/IpAddress.hpp>
#include <SFML/System/Vector2.hpp>

/**
    Settings are a bunch of global variables that are used in a variety of places.
**/

struct Settings {
public:

    /** Display stuff **/
    static sf::Vector2i screenResolution;   //2D integer storing screen resolution
    static unsigned char bitDepth;          //The game bit depth (should be 32)
    static std::string windowName;         //The name of the window

    /** Network stuff **/
    static const char UUID[];               //The player's UUID

    static sf::IpAddress serverAddress;     //Address of the server
    static unsigned short gameUDPPort;      //The port which the game server uses to receive UDP on
    static unsigned short loginTCPPort;     //The port which the login server uses to receive TCP on

    static bool LoggedIn;                   //Whether or not the player is logged in

    static std::string userHash;                 //A hash of the user's username
    static std::string passHash;                 //A hash of the user's password
};

#endif // SETTINGS_H_INCLUDED

#ifndef SETTINGS_H_INCLUDED
#define SETTINGS_H_INCLUDED

struct Settings {
public:

    /** Display stuff **/
    static sf::Vector2i screenResolution;   //2D integer storing screen resolution
    static unsigned char bitDepth;          //The game bit depth (should be 32)
    static const char windowName[];         //The name of the window

    /** Network stuff **/
    static const char UUID[];               //The player's UUID

    static sf::IpAddress serverAddress;     //Address of the server
    static unsigned short gameUDPPort;      //The port which the game server uses to receive UDP on
    static unsigned short gameTCPPort;      //The port which the game server uses to receive TCP on
    static unsigned short loginTCPPort;     //The port which the login server uses to receive TCP on

    static bool LoggedIn;                   //Whether or not the player is logged in
};

#endif // SETTINGS_H_INCLUDED

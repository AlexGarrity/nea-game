/**     Alex Garrity, 2018      **/

#include "GS_Initialise.h"

void GS_Initialise::Draw()
{
    WindowManager::CreateWindow (Settings::screenResolution.x, Settings::screenResolution.y, Settings::bitDepth, Settings::windowName.c_str() );
}

void GS_Initialise::Input()
{
    //Nothing because the game doesn't need input to initialise
}

void GS_Initialise::Update()
{
    NetworkManager::InitialiseSockets (Settings::serverAddress, Settings::loginTCPPort, Settings::gameUDPPort);
    ResourceManager::LoadManifest ("assets/manifest.xml");
}

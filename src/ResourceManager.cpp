/**     Alex Garrity, 2018      **/

#include "ResourceManager.h"

std::map<std::string, std::unique_ptr<sf::Texture>> ResourceManager::textureMap;
std::map<std::string, std::unique_ptr<Entity*>> ResourceManager::entityMap;

std::string Resource::GenerateName()
    {
        unsigned short startMarker = 0;

        for ( unsigned int i = filePath.size(); i > 0; i-- ) {
            if ( filePath[i] == '/' ) {
                startMarker = i + 1;
                break;
            }
        }

        std::string prefix;

        switch ( type ) {
        case Graphic:
            prefix = "gr_";
            break;

        case SFX:
            prefix = "se_";
            break;

        case Music:
            prefix = "mu_";
            break;

        case GUI:
            prefix = "ui_";
            break;
        }

        std::string internalName = prefix + filePath.substr ( startMarker, filePath.size() - startMarker - 4 );
        return internalName;            //Wouldn't let me do this with a single constructor for some reason...
}


void ResourceManager::Load ( const char* filePath, const char* texName )
{
    //Create a unique pointer to a new texture
    std::unique_ptr<sf::Texture> texture ( new sf::Texture() );
    //Load a texture from a file
    texture->loadFromFile ( filePath );
    //Add the texture to the texture map
    textureMap.insert ( std::make_pair ( texName, std::move ( texture ) ) );
}

sf::Texture& ResourceManager::Get ( const char* texName )
{
    //Create an auto, and set it to the value of the texture found at texName
    auto tex = textureMap.find ( texName );
    //Return the texture pointer
    return *tex->second;
}

Entity* ResourceManager::GetEntity ( std::string n )
{
    auto obj = entityMap.find ( n );
    return *obj->second;
}


//I should have commented this stuff when I wrote it...

void ResourceManager::LoadManifest ( const char* filePath )
{
    std::ifstream fileReader ( filePath, std::ifstream::in );


    while ( fileReader.good() ) {
        std::string currentLine;
        std::getline ( fileReader, currentLine );

        //If the line is worth reading...
        if ( currentLine.size() > 3 ) {
            XMLTypes currentTag = GetTag ( currentLine );

        }
    }

    fileReader.close();
}


XMLTypes ResourceManager::GetTag ( std::string currentLine )
{
    unsigned short startMarker = 0;
    unsigned short endMarker = 0;

    for ( unsigned int i = 1; i < currentLine.size(); i++ ) {
        if ( currentLine[i] == '<' ) {
            startMarker = i + 1;
        }

        if ( currentLine[i] == '>' )
            endMarker = i - 1;

        break;      //Prematurely end because the tag has been found
    }

    std::string markerText = currentLine.substr ( startMarker, endMarker - startMarker );

    if ( markerText == "Type" ) {
        return Type;
    } else if ( markerText == "Filepath" ) {
        return FilePath;
    }

    return Invalid;
}

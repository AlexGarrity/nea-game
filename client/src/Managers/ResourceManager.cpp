#include "Managers/ResourceManager.h"

std::map<std::string, Entity*> ResourceManager::entityMap;
std::map<std::string, sf::Texture*> ResourceManager::textureMap;
sf::Font ResourceManager::font;


ManifestParser::ManifestParser (std::string fPath)
{
    filepath = fPath;
}

ManifestParser::~ManifestParser()
{

}

void ManifestParser::Parse ()
{
    std::ifstream reader;
    std::string currentLine = "";

    unsigned int indentationLevel = 0;

    while (std::getline (reader, currentLine) ) {
        ParseLine(currentLine);
    }
}

void ManifestParser::ParseLine(std::string line) {
    for (char c : line) {
        if (c == '{' && indentationLevel < 1) {
            indentationLevel += 1;
        }
        if (c == '}' && indentationLevel < 0) {
            indentationLevel -= 1;
        }
    }
}


Entity *ResourceManager::GetEntity (std::string entityName)
{
    std::map<std::string, Entity*>::iterator entity = entityMap.find (entityName);

    if (entity != entityMap.end() ) {
        return entity->second;
    }
    else {
        return nullptr;
    }
}

sf::Texture &ResourceManager::GetTexture (std::string textureName)
{
    std::map<std::string, sf::Texture*>::iterator texture = textureMap.find (textureName);

    if (texture != textureMap.end() ) {
        return *texture->second;
    }
    return *textureMap.at ("texture");
}

sf::Font &ResourceManager::GetFont()
{
    return font;
}


bool ResourceManager::LoadEntity (Entity* entity, std::string entityName)
{
    if (entity != nullptr) {
        entityMap.insert (std::make_pair (entityName, entity) );
        return true;
    }

    return false;
}

bool ResourceManager::LoadTexture (std::string filePath, std::string textureName)
{
    sf::Texture* tex = new sf::Texture();

    if (tex->loadFromFile(filePath)) {
        textureMap.insert (std::make_pair (textureName, tex) );
        return true;
    }

    return false;
}

bool ResourceManager::LoadFromManifest (std::string filePath)
{
    ManifestParser mParser (filePath);
    mParser.Parse();

    return true;
}

void ResourceManager::Initialise()
{
    LoadTexture("res/texture.png", "texture");

    //LoadTexture("res/textures/error/error_not_found.png", "error_not_found");        Unused
    LoadTexture("res/textures/error/error_no_connection.png", "error_no_connection");

    LoadTexture("res/textures/UI/button_login.png", "UI_Button_Login");
    LoadTexture("res/textures/UI/text_field.png", "UI_Text_Field");
    LoadTexture("res/textures/UI/splash.png", "UI_Splash");
    LoadTexture("res/textures/UI/status.png", "UI_Status_Bar");

    font.loadFromFile("res/fonts/Handlee-Regular.ttf");

}

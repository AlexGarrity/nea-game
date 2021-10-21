#include "Utilities/Timing.h"

sf::Clock Timing::clock;
float Timing::deltaTime;

void Timing::Update()
{
    deltaTime = clock.restart().asSeconds();
}

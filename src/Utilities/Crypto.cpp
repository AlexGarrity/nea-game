#include "Crypto.h"

uint32_t Crypto::length = 0;
uint32_t Crypto::totalLength = 0;

uint32_t Crypto::RotateLeft ( uint32_t m, unsigned char d )
{
    return ( m << d ) | ( m >> ( 32 - d ) );
}

uint32_t Crypto::RotateRight ( uint32_t m, unsigned char d )
{
    return ( m >> d ) | ( m << ( 32 - d ) );
}

std::string Crypto::sha2 ( std::string message )
{
    length = sizeof ( message );

    return message;
}

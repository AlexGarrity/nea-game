/**     Alex Garrity, 2018      **/

#ifndef CRYPTO_H
#define CRYPTO_H

// Library used for hashing and cryptography.
// Still undecided as to whether to create my own algorithms,
// or just borrow MD5 and SHA-2

class Crypto {
public:
    static std::string HashSHA1(std::string M);
protected:
private:

};

#endif // CRYPTO_H

#pragma once

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"

#pragma warning( push )

extern "C" {
    #include "bech32/segwit_addr.h"
}

#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma warning( disable : 6287  )
#pragma warning( disable : 4267  )
#pragma warning( disable : 26495 )
#include "bls.hpp"
#include "elements.hpp"
#include "schemes.hpp"
#include "util.hpp"
#pragma GCC diagnostic pop
#pragma warning( pop )


#define CHINILLA_PUZZLE_HASH_SIZE   32
#define CHINILLA_ADDRESS_MAX_LENGTH 63 // 4 (hrp) + 1 (divisor) + 52 (data) + 6 (checksum)
                                   // hrp is either hcx or thcx

 #define CHINILLA_ADDRESS_LENGTH         62
 #define CHINILLA_TESTNET_ADDRESS_LENGTH 63

struct HcxAddress : NBytes<CHINILLA_ADDRESS_LENGTH+1>
{};

struct PuzzleHash : NBytes<CHINILLA_PUZZLE_HASH_SIZE>
{
    static bool FromAddress( PuzzleHash& hash, const char address[CHINILLA_ADDRESS_MAX_LENGTH+1] );

    void ToAddress( char address[CHINILLA_ADDRESS_MAX_LENGTH+1] );
    std::string ToAddressString();

    void ToHex( char hex[CHINILLA_PUZZLE_HASH_SIZE+1] ) const;
    std::string ToHex() const;

    static bool FromHex( const char hex[CHINILLA_PUZZLE_HASH_SIZE*2+1], PuzzleHash& outHash );

};

class KeyTools
{
public:
    static bool HexPKeyToG1Element( const char* hexKey, bls::G1Element& pkey );

    static bls::PrivateKey MasterSkToLocalSK( bls::PrivateKey& sk );

    static void PrintPK( const bls::G1Element&  key );
    static void PrintSK( const bls::PrivateKey& key );
};


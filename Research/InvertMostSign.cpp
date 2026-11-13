#pragma once
#include <iostream>
#include <bitset>

unsigned short InvertMostSign(unsigned short val)
{
    int mostSignBit = -1;
    for(int i = 15; i >= 0; i--)
    {
        if (val & (1 << i))
        {
            mostSignBit = i;
            break;
        }
    }
    if (mostSignBit != -1)
    {
        return (val ^ (1 << mostSignBit));
    }
    return -1;
}

void InvertMostSign_Test()
{
   using namespace std;
   unsigned short val = 36453;
   std::cout << std::bitset<16>( val) << std::endl << std::bitset<16>(~val) << std::endl << std::bitset<16>(InvertMostSign(val)) << std::endl;
}


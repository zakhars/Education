#include <iostream>
#include <cstdint>
#include <vector>
#include <bitset>
#include <limits>
using namespace std;

inline void setbit(int& value, unsigned bit)
{
   value |= 1ul << bit;
}

inline void resetbit(int& value, unsigned bit)
{
   value &= ~(1ul << bit);
}

inline void togglebit(int& value, unsigned bit)
{
   value ^= 1ul << bit;
}

inline bool checkbit(int& value, unsigned bit)
{
   return (value >> bit) & 1ul;
}

inline void setbitto(int& value, unsigned bit, char to)
{
   value ^= (-to ^ value) & (1ul << bit);
}

int main()
{
   int a = 1;  // 0b00000000000000000000000000000001
   a++;        // 0b00000000000000000000000000000010 or 2
   int b = -1; // 0b11111111111111111111111111111111
   int c = -2; // 0b11111111111111111111111111111110
   int d = -3; // 0b11111111111111111111111111111101

   unsigned int e = numeric_limits<unsigned int>::max(); // also you can use UINT64_MAX, e = 0b11111111111111111111111111111111 or 4294967295
   e++; //overflow: 0b00000000000000000000000000000000
   unsigned int f = 0;
   f--; //underflow: 0b11111111111111111111111111111111 or 4294967295

   signed int g = numeric_limits<signed int>::max(); // 0b01111111111111111111111111111111 or 2147483647
   g++; // 0b10000000000000000000000000000000 or -2147483648

   unsigned char h = numeric_limits<unsigned char>::max(); // 0b11111111 or 255
   h++; // overflow: 0
   unsigned char k = numeric_limits<unsigned char>::min(); // 0b00000000
   k--; // underflow: 0b11111111

   char m = numeric_limits<char>::max(); // 0b01111111 or 127
   m++; // overflow: 0b10000000 or -128
   char n = numeric_limits<char>::min(); // 10000000 or -128
   n--; // underflow: 0b01111111 or 127

   // Bit operations: & | ~ ^  logic:  && || ! 

   // Xor:
   // 1 1 -> 0
   // 0 0 -> 0
   // 1 0 -> 1
   // 0 1 -> 1
   //
   // Xor property: xor ax, ax ; = 0
   //
   // Find only one single value in array: [2,3,3,2,8]


   a = 1;
   setbit(a, 1);
   a = 1;
   setbit(a, 0);
   //m = 1;
   //setbit(m, 8);

   a = 2;
   resetbit(a, 1);

   a = 3;
   togglebit(a, 0);

   a = 2;
   bool bit_val = checkbit(a, 1);
   bit_val = checkbit(a, 2);

   a = 0;
   setbitto(a, 1, 1);
   a = numeric_limits<unsigned int>::max();
   setbitto(a, 1, 0);


   uint32_t v = 195267;

   // Little Endian (as it is on my local box):
   // 11000011 11111010 00000010 00000000
   //
   // Big Endian (natural order)
   // 00000000 00000010 11111010 11000011

   auto change_endianess = [] (uint32_t val)
   {
      return ((val >> 24) & 0x000000ff) |
             ((val <<  8) & 0x00ff0000) |
             ((val >>  8) & 0x0000ff00) |
             ((val << 24) & 0xff000000);
   };

   v = change_endianess(v);

   unsigned char* pdata = reinterpret_cast<unsigned char*>(&v);
   unsigned char p3 = *(pdata + 3); // less significant byte is +3

   // std::bitset
   //
   // template<size_t _Bits> 
   //    class bitset ...
   //       _Ty _Array[_Words + 1]; // the set of bits
   bitset<100> b1;
   // Can't put really large bitsets on stack 
   bitset<1000000> b2; // still ok
   //bitset<10000000> b3; // fails
   // must create large bitset on heap
   bitset<100000000>* b4 = new bitset<100000000>();



   //
   // bitset provides internal public class reference
   // Any reads or writes to a bitset that happen via a std::bitset::reference potentially read or write to the entire underlying bitset.
   //
   //vector<bool> specialization
   //vector<bool> vb;
   //bool* iter = &vb[0];
   //
   //vector<char> regular vector

   return 0;
}



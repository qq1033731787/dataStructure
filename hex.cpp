//
// Created by lzk on 2019-12-27.
//
#include <iostream>

int char2int(char input)
{
    if(input >= '0' && input <= '9')
        return input - '0';
    if(input >= 'A' && input <= 'F')
        return input - 'A' + 10;
    if(input >= 'a' && input <= 'f')
        return input - 'a' + 10;
    throw std::invalid_argument("Invalid input string");
}

void hex2bin(const char* src, unsigned char* target)
{
    while(*src && src[1])
    {
        *(target++) = static_cast<char>(char2int(*src)*16 + char2int(src[1]));
        src += 2;
    }
}

int main(){
    const char* in = "8100020e7979792e7a7a7a0c00ff0b00010000000008000200000000000000";
    int totalBytesRead = static_cast<int>(strlen(in)) / 2;
    unsigned char* tmp = new unsigned char[totalBytesRead];
    hex2bin(in, tmp);
    for(int i = 0; i < totalBytesRead; i++){
        printf("%x\n", tmp[i]);
    }
}

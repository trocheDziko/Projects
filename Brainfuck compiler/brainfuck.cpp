#include<stdint.h>
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<vector>
#include<stdio.h>
using namespace std;

int main(int argc, char *argv[])
{
    uint8_t mem[32678]; 
    int ptr;
    int pc = 0;
    char znak;
    char A;

    FILE *f = fopen(argv[1], "r");
    if(f == NULL){
        printf("File not found");
        return 2;
        }
    
    fseek(f, 0, SEEK_END);
    size_t sz = ftell(f);
    fseek(f, 0, SEEK_SET);

    vector<char> bf;
    bf.resize(sz+1);
    fread(&bf[0], 1, sz, f);
    fclose(f);

    for(int i =0; i<sz;i++) cout<<bf[i];
    while(bf[pc] != '\0')
    {
   // cout<<bf[pc];
    switch(bf[pc]){
        case  '>': ptr++; break;
        case  '<':  ptr--; break;
        case  '+': mem[ptr]++; break;
        case  '-': mem[ptr]--; break;
        case  '.':
        {
            putchar(mem[ptr]); 
            break;
        }
        case  ',': mem[ptr] = getchar(); break;
        case '[':
            {
            if(mem[ptr] != 0) break;
            int counter = 1;
            pc++;
            while(counter!=0) {
                if(bf[pc] == ']') counter--;
                if(bf[pc] == '[') counter++;    
                pc++;
                 }
            continue;
            }
        case ']':
            {
            int counter = -1;
            while(counter!=0) {
                pc--;
                if(bf[pc] == ']') counter--;
                if(bf[pc] == '[') counter++;    
                 }
            continue;
            }

        default:
            break;
        }
        pc += 1;
    }
    return 0;
}


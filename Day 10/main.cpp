#include <iostream>
#include <inttypes.h>
#include <vector>
#include <iostream>
#include <string>
#include <inttypes.h>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <math.h>

std::vector<std::string> split(std::string str, char delimiter);

typedef struct Parenthesis{
    char type;
    char opposite;
};
Parenthesis things[] = {
    {'(',')'},
    {'[',']'},
    {'{','}'},
    {'<','>'}
};
int main(int argc, const char * argv[]) {
    bool next = false;
    std::vector<char> stuff;
    std::ifstream ifs;
    size_t points = 0;
    ifs.open("./../Inputs/10.txt", std::ifstream::in);
    std::string str ( (std::istreambuf_iterator<char>(ifs) ),(std::istreambuf_iterator<char>()));
    std::vector<std::string> test = split(str, '\n');
    
    for (auto str1 : test) {
        for (size_t i = 0; i < str1.size(); i++) {
            for (size_t o = 0; o < 4; o++) {
                if (str1[i] == things[o].type) {
                    stuff.push_back(things[o].opposite);
                    break;
                }
                
                if (str1[i] == things[o].opposite) {
                    if (stuff.back() != str1[i]) {
                        next = true;
                        points += (str1[i] == ')') * 3 + (str1[i] == ']') * 57 + (str1[i] == '}') * 1197 + (str1[i] == '>') * 25137;
                    }else{
                        stuff.pop_back();
                        break;
                    }
                }
                
            }
            if(next){
                next = false;
                break;
            }
        }
    }
    std::cout << points<<std::endl;
        return 0;
    }
    std::vector<std::string> split(std::string str, char delimiter) {
        std::vector<std::string> internal;
        std::stringstream ss(str);
        std::string tok;
        
        while(getline(ss, tok, delimiter)) {
            internal.push_back(tok);
        }
        
        return internal;
    }

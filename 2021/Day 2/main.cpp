#include <iostream>
#include <string>
#include <inttypes.h>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <sstream>

int32_t depth = 0;
int32_t horizontal = 0;

std::vector<std::string> split(std::string str, char delimiter);

int main(void){
    std::ifstream ifs;

    ifs.open("./../Inputs/02.txt", std::ifstream::in);
    std::string str ( (std::istreambuf_iterator<char>(ifs) ), (std::istreambuf_iterator<char>()) );
    std::vector<std::string> Instructions = split(str, '\n');
    
    for (size_t i = 0; i < Instructions.size(); i++)
    {
        std::vector<std::string> instruction = split(Instructions[i], ' ');
        if (instruction[0] == "up")
        {
            depth -= std::stoi(instruction[1]);
        }
        else if (instruction[0] == "down")
        {
            depth += std::stoi(instruction[1]);
        }
        else if (instruction[0] == "forward")
        {
            horizontal += std::stoi(instruction[1]);
        }
        
        instruction.clear();
        instruction.shrink_to_fit();
    }
    
    std::cout << "Result: " << horizontal * depth << std::endl;
    
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

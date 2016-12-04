#include <iostream>
#include <c++/4.8.3/cstring>
#include <fstream>
#include <c++/4.8.3/vector>

using namespace std;

class Room{
public:
    Room(std::string input){

    }

    bool isReal(){
        return checksum == process(this->roomCode);
    }

    int getNumber(){
        return this->number;
    }

private:
    std::string checksum;
    std::string roomCode;
    int number;

    std::string process(std::string ){

    }
};

std::string readFile(std::string fileName){
    std::ifstream file(fileName);
    std::string str;
    std::string result;
    while (std::getline(file, str))
    {
        result += str + "\n";
    }
    return result;
}

int main()
{
    int count = 0;

    std::string input = readFile("C:\\kochetov\\adventofcode2016\\day4.input");

    std::string line = "";
    for (int i=0; i < input.size(); i++){
            if (input[i] == '\n') {
                Room *r = new Room(line);
                if (r->isReal()) count += r->getNumber();
                line.clear();
            }
    line += input[i];
    }

    cout << count;
    return 0;
}


#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <regex>
#include <map>


using namespace std;

class Room{
public:
    Room(std::string input){
        std::string part = "";
        std::string numb = "";

        for (int i=0; i < input.size(); i++){
            if (input[i] == '\n'){
                continue;
            }
            if (input[i] == '['){
                this->checksum = input.substr(i+1,5);
                break;
            }
            if (isNumber(input[i])){
                numb += input[i];
                continue;
            }
                part += input[i];
        }
            this->roomCode =  part;
            this->number =  std::stoi(numb);

    }

    bool isReal(){
        return checksum == process();
    }

    int getNumber(){
        return this->number;
    }
    
        
    std::string decode(){
        std::string result = "";
        int alfabetLen = 26;
        int offset = this->number % alfabetLen;
        char c;
        for (int i = 0; i < this->roomCode.size(); i++){
            
            if (this->roomCode.at(i) == '\n') {
                continue;
            }
            
            if (this->roomCode.at(i) == '-') {
                result += ' ';
                continue;
            }
            c = roomCode[i];
            if ((int(c)+offset) > 122) {
                result += char((int(c)+offset)-alfabetLen);
            } else {
                result += char((int(c)+offset));
            }
        }
        return result;
    }

private:
    std::string checksum;
    std::string roomCode;
    int number;

    std::string process(){
        map<char, int> alphabet;
        for (int i = 0; i < this->roomCode.size(); i++){
            if (roomCode[i] != '-') alphabet[roomCode[i]]++;
        }
        std::vector<std::pair<char, int>> charArray;
        for(auto it = alphabet.begin(); it != alphabet.end(); it++){

                charArray.push_back(std::make_pair(it->first, it->second));
        }
        auto cmp = [](std::pair<char,int> const & a, std::pair<char,int> const & b)
        {
            return a.second != b.second?  a.second > b.second : a.first < b.first;
        };

        std::sort(charArray.begin(), charArray.end(),cmp);

        std::string result = "";
        for (int i=0; i < 5; i++){
            result += charArray[i].first;
        }
        return result;
    }

    bool isNumber(char c){
        int x = c;
        return  (x >= 48) && (x <= 57);
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

    std::string input = readFile("./day4.input");

    std::string line = "";
    for (int i=0; i < input.size(); i++){
            if (input[i] == '\n') {
                Room *r = new Room(line);
                if (r->isReal()) cout << r->decode() << " : " << r->getNumber() << endl;
                line.clear();
                delete (r);
            }
    line += input[i];
    }



    return 0;
}


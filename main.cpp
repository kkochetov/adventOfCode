#include <iostream>
#include <c++/4.8.3/cstring>
#include <fstream>
#include <c++/4.8.3/vector>
#include <regex>
#include <c++/4.8.3/map>


using namespace std;

class Room{
public:
    Room(std::string input){
        std::string part = "";
        std::string numb = "";

        for (int i=0; i < input.size(); i++){
            if (input[i] == '['){
                this->checksum = input.substr(i+1,5);
                break;
            }
            if (isNumber(input[i])){
                numb += input[i];
                continue;
            }
            if (input[i] != '-'){
                part += input[i];
            }
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
        cout << this->roomCode << " ! " << this->checksum << " ! " << result << " ! " << endl;
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


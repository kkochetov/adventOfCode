#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <regex>
#include <map>


using namespace std;

    class Row{
        public:
        Row(){

        };
        
        void add(char c){
            this->alphabet[c]++;
        }
        
        char getUpChar(){
        std::vector<std::pair<char, int>> charArray;
        for(auto it = alphabet.begin(); it != alphabet.end(); it++){
                charArray.push_back(std::make_pair(it->first, it->second));
        }
        auto cmp = [](std::pair<char,int> const & a, std::pair<char,int> const & b)
        {
            return a.second != b.second?  a.second > b.second : a.first < b.first;
        };

        std::sort(charArray.begin(), charArray.end(),cmp);

        
        return charArray[0].first;
        }
        
        private:
        map<char, int> alphabet;
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
    std::string input = readFile("./day6.input");
    
    Row* password[8] = {new Row(), new Row(),new Row(),new Row(),new Row(),new Row(),new Row(),new Row() };
    
    std::string line = "";
    for (int i=0; i < input.size(); i++){
            if (input[i] == '\n') {
               for (int j = 0; j < 8; j++){
                    password[j]->add(line.at(j));                   
               }
                line.clear();
                continue;
            }
    line += input[i];
    }

    for (int j = 0; j < 8; j++){
        cout << password[j]->getUpChar();
    }
    cout << endl;    

    return 0;
}


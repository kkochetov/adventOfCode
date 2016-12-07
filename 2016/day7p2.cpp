#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <regex>
#include <map>


using namespace std;

class Ipv7{
    public:
        Ipv7(std::string linez){
            this->line = linez;
            process();
        }

        bool isSSL(){
            if ((inside.size() == 0) || (inside.size() == 0)) return false;
            
            for (std::vector<std::string>::iterator insideInt = inside.begin(); insideInt !=inside.end(); ++insideInt){
                for (std::vector<std::string>::iterator outsideInt = outside.begin(); outsideInt !=outside.end(); ++outsideInt){
                    if (((*insideInt)[0] == (*outsideInt)[1]) && ((*insideInt)[1] == (*outsideInt)[0])) return true;
                }
            }
            return false;
        }

    private:
    std::string line;

    vector<std::string> inside;
    vector<std::string> outside;
    
    void process(){
        this->line; 
        std::string part = "";
        for (int i=0; i < this->line.size(); i++){
            if (this->line[i] == '['){
                addTo(part, &outside);
                part.clear();
                continue;
            }
            if (this->line[i] == ']'){
                addTo(part, &inside);
                part.clear();
                continue;
            }
            if (this->line[i] == '\n'){
                addTo(part, &outside);
                part.clear();
                break;
            }
         part += this->line[i];   
        }
    }
    
    void addTo(std::string line, vector<std::string> *lineVector){
        for (int i=0; i < line.size() - 2; i++){
            if ((line[i] == line[i+2]) && (line[i] != line[i+1])){
                lineVector->push_back( line.substr(i,3) );
            }
        }
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
    std::string input = readFile("./day7.input");
    int count = 0;
    std::string line = "";
    for (int i=0; i < input.size(); i++){
            if (input[i] == '\n') {
                Ipv7 *addr = new Ipv7(line + "\n");
                if (addr->isSSL()) count++;
                line.clear();
                delete addr;
                continue;
            }
    line += input[i];
    }

    cout << count << endl;
     return 0;
}


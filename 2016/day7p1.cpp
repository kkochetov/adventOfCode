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
            this->inside = false;
            this->outside = false;
            process();
        }
        
        bool isInside(){
            return this->inside;
        }
        
        bool isOutside(){
            return this->outside;
        }
        
    private:
    std::string line;

    bool inside;
    bool outside;
    
    void process(){
        this->line; 
        std::string part = "";
        for (int i=0; i < this->line.size(); i++){
            if (this->line[i] == '['){
                if (!outside) outside = hasPolindrome(part);
                part.clear();
                continue;
            }
            if (this->line[i] == ']'){
                if (!inside) inside = hasPolindrome(part);
                part.clear();
                continue;
            }
            if (this->line[i] == '\n'){
                if (!outside) outside = hasPolindrome(part);
                part.clear();
                break;
            }
            
         part += this->line[i];   
        }
    }
    
    bool hasPolindrome(std::string line){
        
        for (int i=0; i < line.size() - 3; i++){
            if ((line[i] == line [i+3]) && (line[i+1] == line [i+2]) && (line[i] != line [i+1])) {
                return true;
            }
        }
        return false;
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
                if ((addr->isOutside()) && (!addr->isInside())){
                    count++;
                }
                line.clear();
                continue;
            }
    line += input[i];
    }

    cout << count << endl;
     return 0;
}


#include <iostream>
#include "./thirdPaty/md5.cpp"


using namespace std;
bool isCorrectNumber(char c){
        int x = c;
        return  (x >= 48) && (x <= 55);
    }


int main()
{
    std::string input = "abbhdwsy";
    std::string password = "________";

     int i = 0;
     int index = 0;
     while (i < 8) {
         std::string hash = md5(input + std::to_string(index));
         if ((hash.substr(0,5) == "00000")){
                if (isCorrectNumber(hash.substr(5,1).at(0))) {
                        int pos = std::stoi(hash.substr(5,1));
                        if (password.at(pos) == '_') {
                            password[pos] = hash.at(6);    
                            i++;
                            cout << password << endl;    
                        }
                }
         }    
         index++;
     }
   cout << password << endl; //424a0197
    return 0;
}


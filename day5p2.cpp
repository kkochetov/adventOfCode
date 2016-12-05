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
    char password[8] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};

     int i = 0;
     int index = 0;
     while (i < 8) {
         std::string hash = md5(input + std::to_string(index));
         if ((hash.substr(0,5) == "00000") && isCorrectNumber(hash.substr(5,1))){
                int pos = std::stoi(hash.substr(5,1));
                if (password[pos] != NULL) {
                    password[pos] = hash.substr(6,1);    
                    i++;
                }
         }    
         index++;
     }
   cout << password << endl;
    return 0;
}


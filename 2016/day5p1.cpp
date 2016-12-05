#include <iostream>
#include "../thirdPaty/md5.cpp"


using namespace std;

int main()
{
    std::string input = "abbhdwsy";
    std::string password = "";


     int i = 0;
     int index = 0;
     while (i < 8) {
         std::string hash = md5(input + std::to_string(index));
         if (hash.substr(0,5) == "00000"){
             password += hash.substr(5,1);
             i++;
         }    
         index++;
     }
   cout << password << endl;
    return 0;
}


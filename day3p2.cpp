#include <iostream>
#include <c++/4.8.3/cstring>
#include <fstream>
#include <c++/4.8.3/vector>

using namespace std;

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
bool isTriangle(int f, int s, int t){
    return (f + s > t) && (s + t > f) && (f + t > s);
}

int main()
{
    int count = 0;

    std::string input = readFile("C:\\kochetov\\adventofcode2016\\day3.input");
    std::string line = "";
    int block[3][3];
    int endBlock = 0;
    for (int i=0; i < input.size(); i++){
           if (input[i] == '\n') {
            int f = std::stoi( line.substr(0,5) );
            int s = std::stoi( line.substr(5,5) );
            int t = std::stoi( line.substr(10,5) );
            block[0][endBlock] = f;
            block[1][endBlock] = s;
            block[2][endBlock] = t;
               if (endBlock == 2){
                   if (isTriangle(block[0][0],block[0][1],block[0][2])) count++;
                   if (isTriangle(block[1][0],block[1][1],block[1][2])) count++;
                   if (isTriangle(block[2][0],block[2][1],block[2][2])) count++;
                   endBlock = 0;
               } else {
                   endBlock++;
               }
            line.clear();
            continue;

        }
        line += input[i];
    }

    cout << count;
    return 0;
}


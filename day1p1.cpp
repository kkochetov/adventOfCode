#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

char input[] = "L4, L3, R1, L4, R2, R2, L1, L2, R1, R1, L3, R5, L2, R5, L4, L3, R2, R2, L5, L1, R4, L1, R3, L3, R5, R2, L5, R2, R1, R1, L5, R1, L3, L2, L5, R4, R4, L2, L1, L1, R1, R1, L185, R4, L1, L1, R5, R1, L1, L3, L2, L1, R2, R2, R2, L1, L1, R4, R5, R53, L1, R1, R78, R3, R4, L1, R5, L1, L4, R3, R3, L3, L3, R191, R4, R1, L4, L1, R3, L1, L2, R3, R2, R4, R5, R5, L3, L5, R2, R3, L1, L1, L3, R1, R4, R1, R3, R4, R4, R4, R5, R2, L5, R1, R2, R5, L3, L4, R1, L5, R1, L4, L3, R5, R5, L3, L4, L4, R2, R2, L5, R3, R1, R2, R5, L5, L3, R4, L5, R5, L3, R1, L1, R4, R4, L3, R2, R5, R1, R2, L1, R4, R1, L3, L3, L5, R2, R5, L1, L4, R3, R3, L3, R2, L5, R1, R3, L3, R2, L1, R4, R3, L4, R5, L2, L2, R5, R1, R2, L4, L4, L5, R3, L4,";
//1 -- north, 2 -- east, 3 -- south, 4 -- west
int currentDir = 1;

//1 -- north, 2 -- east, 3 -- south, 4 -- west
int turn(char turn)
{
    int newDir;
    if (turn == 'L') {
        newDir = currentDir - 1;
    } else {
        newDir = currentDir + 1;
    }
    if (newDir == 0) {
        newDir = 4;
    }
    if (newDir == 5) {
        newDir = 1;
    }

    return newDir;
}


int main()
{
    int x = 0;
    int y = 0;

    std::vector<char> vec(0);

    for (int i = 0; i < strlen(input); i++){
        if (input[i] == ' ') continue;
        if ((input[i] == 'L') || (input[i] == 'R')) {
            currentDir = turn(input[i]);
            continue;
        };
        if (input[i] == ','){
            std::string s( vec.begin(), vec.end() );
            int step = std::stoi(s);
            switch (currentDir) {
                case 1:
                    x += step;
                    break;
                case 2:
                    y += step;
                    break;
                case 3:
                    x -= step;
                    break;
                case 4:
                    y -= step;
                    break;
            }
            vec.clear();
            continue;
        }
        vec.push_back(input[i]);


    }

    cout << abs(x) + abs(y) << endl;

    return 0;
}



#include <iostream>
#include <c++/4.8.3/cstring>
#include <c++/4.8.3/vector>

using namespace std;

class Point {
public:
    int x;
    int y;
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
};


char input[] = "L4, L3, R1, L4, R2, R2, L1, L2, R1, R1, L3, R5, L2, R5, L4, L3, R2, R2, L5, L1, R4, L1, R3, L3, R5, R2, L5, R2, R1, R1, L5, R1, L3, L2, L5, R4, R4, L2, L1, L1, R1, R1, L185, R4, L1, L1, R5, R1, L1, L3, L2, L1, R2, R2, R2, L1, L1, R4, R5, R53, L1, R1, R78, R3, R4, L1, R5, L1, L4, R3, R3, L3, L3, R191, R4, R1, L4, L1, R3, L1, L2, R3, R2, R4, R5, R5, L3, L5, R2, R3, L1, L1, L3, R1, R4, R1, R3, R4, R4, R4, R5, R2, L5, R1, R2, R5, L3, L4, R1, L5, R1, L4, L3, R5, R5, L3, L4, L4, R2, R2, L5, R3, R1, R2, R5, L5, L3, R4, L5, R5, L3, R1, L1, R4, R4, L3, R2, R5, R1, R2, L1, R4, R1, L3, L3, L5, R2, R5, L1, L4, R3, R3, L3, R2, L5, R1, R3, L3, R2, L1, R4, R3, L4, R5, L2, L2, R5, R1, R2, L4, L4, L5, R3, L4,";
//1 -- north, 2 -- east, 3 -- south, 4 -- west
int currentDir = 1;

int x = 0;
int y = 0;



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

    std::vector<Point> places;
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

            for(int i=0; i < step; i++){
                switch (currentDir) {
                    case 1:
                        x += 1;
                        break;
                    case 2:
                        y += 1;
                        break;
                    case 3:
                        x -= 1;
                        break;
                    case 4:
                        y -= 1;
                        break;
                };
                Point *point = new Point(x,y);
                places.push_back(*point);
            }

            vec.clear();
            continue;
        }
        vec.push_back(input[i]);
    }

    int s = 1;
    for (std::vector<Point>::iterator it = places.begin(); it != places.end(); ++it) {
        int etX = it->x;
        int etY = it->y;

        for (std::vector<Point>::iterator itInt = places.begin() + s; itInt != places.end(); ++itInt){
            if ((etX == itInt->x) && (etY == itInt->y)) {
                cout <<abs(etX) + abs(etY)  << endl;
                return 0;
            }
        }
        s++;
    }
    return 0;
}


 #define CURRENT true

#ifdef CURRENT

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

struct Position {
    int x;
    int y;

    explicit Position(string deskCell) : x(deskCell[0] - 97), y(deskCell[1] - 49) { };
    Position(int x, int y) : x(x), y(y) { };

    void print(bool asDeskCellName = true, bool withEndl = true) {
        if (asDeskCellName) {
            cout << char(x + 97) << char(y + 49);
        } else {
            cout << '(' << x << ';' << y << ')';
        }

        if (withEndl) {
            cout << '\n';
        }
    }
};

const vector<vector<int>> possibleDeltas = {
    { 2, 1 },
    { 1, 2 },
    { -1, 2 },
    { -2, 1 },
    { -2, -1 },
    { -1, -2 },
    { 1, -2 },
    { 2, -1 },
};

bool isCorrectPosition(Position position) {
    cout << "check: ";
    position.print();
    return position.x >= 0 && position.x < 8 && position.y >= 0 && position.y < 8;
}

Position nextPositionIfCorrect(Position current, int deltaIndex, vector<vector<bool>>& visited) {
    auto deltaToCheck = possibleDeltas[deltaIndex];
    int dX = deltaToCheck[0];
    int dY = deltaToCheck[1];
    Position positionToCheck = {current.x + dX, current.y + dY};

    if (isCorrectPosition(positionToCheck) && !visited[positionToCheck.x][positionToCheck.y]) {
        return positionToCheck;
    }

    throw "position is incorrect";
}

int main() {
    string fromCell, toCell;
    while (cin >> fromCell >> toCell) {
        Position from(fromCell);
        Position to(toCell);
    }
}

#endif

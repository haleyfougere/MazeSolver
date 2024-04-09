#ifndef ASSIGNMENT_2_POSITION_H
#define ASSIGNMENT_2_POSITION_H

class Position {
public:
    int _row, _col;

    Position(int x, int y);
    bool operator==(const Position &other) const;
};

#endif

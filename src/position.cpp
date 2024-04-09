#include "position.h"

Position::Position(int r, int c) {
    _row = r;
    _col = c;
}

bool Position::operator==(const Position &other) const {
    return _row == other._row && _col == other._col;
}


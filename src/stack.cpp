#include <iostream>
#include <filesystem>
#include "stack.h"
#include "position.h"

Stack::Stack() : _top(nullptr) {}

void Stack::push(Position position) {
    /// push the position to the stack

    auto node = std::make_unique<Node>(position);
    node->_next = std::move(_top);
    _top = std::move(node);
}

void Stack::pop() {
    /// pop the position from the stack

    if (_top != nullptr) {
        _top = std::move(_top->_next);
    }
}

bool Stack::empty() const {
    /// check if the stack is empty, if it is empty set the top to nullptr

    return _top == nullptr;
}

Position Stack::top() const {
    /// get the top position of the stack

    if (!empty()) {
        return _top->_position;
    }
    // if the stack is empty, return an invalid position
    return Position{-1, -1};
}

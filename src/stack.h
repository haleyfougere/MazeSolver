#ifndef ASSIGNMENT_2_STACK_H
#define ASSIGNMENT_2_STACK_H
#include <iostream>
#include <memory>
#include "position.h"

class Stack {
    struct Node {
        Position _position;
        std::unique_ptr<Node> _next;

        Node(Position position) : _position(position), _next(nullptr) {}
    };

    std::unique_ptr<Node> _top;

public:
    Stack();
    void push(Position position);
    void pop();
    [[nodiscard]] bool empty() const;
    [[nodiscard]] Position top() const;
};

#endif

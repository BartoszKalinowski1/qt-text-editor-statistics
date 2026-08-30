#ifndef NODE_H
#define NODE_H

#include <QString>

class node {
public:
    node(const QString &s) : word(s), count(1), next(nullptr) {}

    QString word;
    int count;
    node* next;
};

#endif // NODE_H

using namespace std;
#include <iostream>
#include "../includes/StringTabNode.h";

StringTabNode::StringTabNode() {
    // TODO: implement
}

StringTabNode::~StringTabNode() {
    // Delete here everything in case heap memory is allocated with keyword "new"
}

char* StringTabNode::getVector() {
    // TODO: implement
}

StringTabNode* StringTabNode::getNext() {
    // TODO: implement
    return this->next;
}

void StringTabNode::setNext(StringTabNode* next) {
    // TODO: implement
    this->next = next;
}
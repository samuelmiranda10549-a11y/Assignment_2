#ifndef STACKNODE_HPP
#define STACKNODE_HPP

#include "RGBPixelXY.hpp"  

class StackNode {

    RGBPixelXY* pixel;
    StackNode* next;
public:
    StackNode(RGBPixelXY* p);
    ~StackNode();

    StackNode* getNext();
    void setNext(StackNode* pnext);
    RGBPixelXY* getPixel();
    

    
};

#endif // STACKNODE_HPP
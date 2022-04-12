#ifndef CASE_H
#define CASE_H

class Case{
public :
    Case(int posX, int posY){
        posX_ = posX;
        posY_ = posY;
    };
    ~Case();
private :
    int posX_, posY_;
};
#endif // CASE_H

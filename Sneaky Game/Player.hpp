#include<iostream>
#include<fstream>
#include<cstring>
#include<conio.h>
#include<cmath>
using namespace std;
class Player : public Monster{
    int points;
public:
    Player() : points(0) {}
    Player(int h, int d, int r, int x, int y, char l, int pts) : Monster(h,d,r,x,y,l),points(pts){}
    int getPoints(){return points;}
    void setPoints(int p){points=p;}
    bool isAlive() override {return health>0;}
    friend ostream & operator<<(ostream &out, const Player &M);
    friend istream & operator>>(istream &in, Player &P);
};
ostream & operator<<(ostream &out, const Player &P){
    cout<<static_cast<const Monster&>(P);
    cout<<P.points;
    return out;
}
istream & operator>>(istream &in, Player &P){
    in>>static_cast<Monster&>(P);
    in>>P.points;
    return in;
}

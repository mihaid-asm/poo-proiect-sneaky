#include<iostream>
#include<fstream>
#include<cstring>
#include<conio.h>
#include<cmath>
using namespace std;
class Item{
    int points,coord_x,coord_y;
public:
    ~Item(){}
    int getPoints(){return points;}
    int getCoordX(){return coord_x;}
    int getCoordY(){return coord_y;}
    void setPoints(int p){points=p;}
    Item(Item &IT){points=IT.points; coord_x=IT.coord_x; coord_y=IT.coord_y;}
    Item(): points(0), coord_x(0), coord_y(0){}
    friend ostream & operator<<(ostream &out, const Item &I);
    friend istream & operator>>(istream &in, Item &I);
    Item& operator=(Item &I1){points=I1.points; coord_x=I1.coord_x; coord_y=I1.coord_y; return I1;}
};
ostream & operator<<(ostream &out, const Item &I){
    cout<<I.points<<"PTS at ("<<I.coord_x<<", "<<I.coord_y<<")\n";
    return out;
}
istream & operator>>(istream &in, Item &I){
    in>>I.points>>I.coord_x>>I.coord_y;
    return in;
}

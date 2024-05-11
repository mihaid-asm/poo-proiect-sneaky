#include<iostream>
#include<fstream>
#include<cstring>
#include<conio.h>
#include<cmath>
using namespace std;
class Level{
    static int no_levels;
    int height,width;
    Player ONE;
    int no_monsters;
    Monster M[20];
    int no_items;
    Item I[20];
    int target;
    bool over;
public:
    int getHeight(){return height;}
    int getWidth(){return width;}
    int getNumberOfMonsters(){return no_monsters;}
    int getNumberOfItems(){return no_items;}
    int getTarget(){return target;}
    bool getOver(){return over;}
    static int getLevels(){return no_levels;}
    Player& getPlayer(){return ONE;}
    Monster& getMonster(int index){return M[index];}
    Item& getItem(int index){return I[index];}
    static void setLevels(int lev){no_levels=lev;}
    void setNumberOfMonsters(int m){no_monsters=m;}
    void setNumberOfItems(int i){no_items=i;}
    void setOver(bool o){over=o;}
    void setPlayer(Player P){ONE=P;}
    void setMonster(Monster MO, int index){M[index]=MO;}
    void setItem(Item IT, int index){I[index]=IT;}
    Level(): height(0), width(0), ONE(0, 0, 0, 0, 0, ' ', 0), no_monsters(0), no_items(0), target(0){}
    friend ostream & operator<<(ostream &out, const Level &L);
    friend istream & operator>>(istream &in, Level &L);
};
ostream & operator<<(ostream &out, const Level &L){
    out<<L.height<<" "<<L.width<<endl;
    if(L.height>50||L.width>50||L.height<5||L.width<5){
        throw invalid_argument("Length and width have to be between 5 and 50.");
    }
    out<<L.ONE<<endl;
    out<<L.no_monsters<<endl;
    for(int i=0;i<L.no_monsters;i++){
        out<<L.M[i]<<endl;
    }
    out<<L.no_items<<endl;
    for(int i=0;i<L.no_items;i++){
        out<<L.I[i]<<endl;
    }
    cout<<L.target;
    return out;
}
istream & operator>>(istream &in, Level &L){
    in>>L.height>>L.width;
    in>>L.ONE;
    in>>L.no_monsters;
    for(int i=0;i<L.no_monsters;i++){
        in>>L.M[i];
    }
    in>>L.no_items;
    for(int i=0;i<L.no_items;i++){
        in>>L.I[i];
    }
    in>>L.target;
    return in;
}

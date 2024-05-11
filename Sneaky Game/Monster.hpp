#include<iostream>
#include<fstream>
#include<cstring>
#include<conio.h>
#include<cmath>
using namespace std;
class Monster{
protected:
    int health,atk_dmg,atk_rng;
    int coord_x,coord_y;
    char look;
    Monster(int h,int d,int r,int x,int y, char l){}
public:
    int getHealth(){return health;}
    int getAttackDamage(){return atk_dmg;}
    int getAttackRange(){return atk_rng;}
    int getCoordX(){return coord_x;}
    int getCoordY(){return coord_y;}
    char getLook(){return look;}
    void setHealth(int h){health=h;}
    void setAttackDamage(int d){atk_dmg=d;}
    void setCoordX(int x){coord_x=x;}
    void setCoordY(int y){coord_y=y;}
    void setLook(char l){look=l;}
    Monster(Monster &MO){health=MO.health; atk_dmg=MO.atk_dmg; atk_rng=MO.atk_rng; coord_x=MO.coord_x; coord_y=MO.coord_y; look=MO.look;}
    Monster(): health(0), atk_dmg(0), atk_rng(0), coord_x(0), coord_y(0), look(' '){}
    virtual bool isAlive(){return health>0;}
    friend ostream & operator<<(ostream &out, const Monster &M);
    friend istream & operator>>(istream &in, Monster &M);
};
ostream & operator<<(ostream &out, const Monster &M){
    out<<M.look<<": ";
    out<<M.health<<"HP ";
    out<<M.atk_dmg<<"DMG ";
    out<<M.atk_rng<<"RNG ";
    out<<"("<<M.coord_x<<", "<<M.coord_y<<") ";
    return out;
}
istream & operator>>(istream &in, Monster &M){
    in>>M.health>>M.atk_dmg>>M.atk_rng>>M.coord_x>>M.coord_y>>M.look;
    if(M.coord_x<1||M.coord_y<1){
        throw invalid_argument("Monster/Player is out of the map");
    }
    return in;
}

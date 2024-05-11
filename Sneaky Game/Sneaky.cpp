#include<iostream>
#include<fstream>
#include<cstring>
#include<conio.h>
#include<cmath>
#include "Monster.hpp"
#include "Player.hpp"
#include "Item.hpp"
#include "Level.hpp"

using namespace std;

///Monster

///Player

///Item

///Level

int Level::no_levels = 3;
int main(){
    int choice;
    Level::setLevels(3);
    try{
        cout<<"Choose a level between 1 and 3: ";
        cin>>choice;
        if(choice<1||choice>Level::getLevels()){
            throw invalid_argument("This level does not exist.");
        }
    }
    catch(const invalid_argument &e){
        cout<<"Error: "<<e.what()<<endl;
        return 0;
    }
    char nolevel[10];
    nolevel[0]='0'+choice;
    strcat(nolevel,"joc.in");
    ifstream fin(nolevel);
    Level L1;
    fin>>L1;
    char harta[52][52];
    L1.setOver(false);
        while(!L1.getOver()){
            system("cls");
            if(L1.getTarget()<=L1.getPlayer().getPoints()){
                L1.setOver(true);
                cout<<"YOU WON\n";
            }
            else if(!L1.getPlayer().isAlive()){
                L1.setOver(true);
                cout<<"YOU LOST\n";
            }
            for(int i=0;i<=L1.getHeight()+1;i++){
                for(int j=0;j<=L1.getWidth()+1;j++){
                    harta[i][j]=' ';
                }
            }
            for(int i=0;i<=L1.getHeight()+1;i++){
                for(int j=0;j<=L1.getWidth()+1;j++){
                    if(i==0 || j==0 || i==L1.getHeight()+1 || j==L1.getWidth()+1) harta[i][j]='#';
                    for(int k=0;k<L1.getNumberOfMonsters();k++){
                        harta[L1.getMonster(k).getCoordX()][L1.getMonster(k).getCoordY()]=L1.getMonster(k).getLook();
                    }
                    for(int k=0;k<L1.getNumberOfItems();k++){
                        if(L1.getItem(k).getPoints()>0)
                            harta[L1.getItem(k).getCoordX()][L1.getItem(k).getCoordY()]='0'+L1.getItem(k).getPoints();
                        else
                            harta[L1.getItem(k).getCoordX()][L1.getItem(k).getCoordY()]=' ';
                    }
                    harta[L1.getPlayer().getCoordX()][L1.getPlayer().getCoordY()]=L1.getPlayer().getLook();
                }
            }
            for(int i=0;i<=L1.getHeight()+1;i++){
                for(int j=0;j<=L1.getWidth()+1;j++){
                    cout<<harta[i][j];
                }
                cout<<endl;
            }
            cout<<L1.getPlayer()<<"/"<<L1.getTarget()<<"PTS "<<endl;
            for(int i=0;i<L1.getNumberOfMonsters();i++){
                cout<<L1.getMonster(i)<<endl;
            }
            if(toupper(getch())=='W' && L1.getPlayer().getCoordX()>1){
                int x=L1.getPlayer().getCoordX();
                x--;
                L1.getPlayer().setCoordX(x);
            }
            if(toupper(getch())=='A' && L1.getPlayer().getCoordY()>1){
                int y=L1.getPlayer().getCoordY();
                y--;
                L1.getPlayer().setCoordY(y);
            }
            if(toupper(getch())=='S' && L1.getPlayer().getCoordX()<L1.getHeight()){
                int x=L1.getPlayer().getCoordX();
                x++;
                L1.getPlayer().setCoordX(x);
            }
            if(toupper(getch())=='D' && L1.getPlayer().getCoordY()<L1.getWidth()){
                int y=L1.getPlayer().getCoordY();
                y++;
                L1.getPlayer().setCoordY(y);
            }
            for(int i=0;i<L1.getNumberOfItems();i++){
                if(L1.getPlayer().getCoordX() == L1.getItem(i).getCoordX()){
                    if(L1.getPlayer().getCoordY() == L1.getItem(i).getCoordY()){
                        int p=L1.getPlayer().getPoints();
                        p+=L1.getItem(i).getPoints();
                        L1.getPlayer().setPoints(p);
                        int n=L1.getNumberOfItems();
                        n--;
                        L1.setNumberOfItems(n);
                        for(int j=i;j<n;j++){
                            Item aux(L1.getItem(j+1));
                            L1.setItem(aux,j);
                        }
                        L1.getItem(n).setPoints(0);
                    }
                }
            }
            for(int i=0;i<L1.getNumberOfMonsters();i++){
                if(abs(L1.getPlayer().getCoordX()-L1.getMonster(i).getCoordX())<=L1.getMonster(i).getAttackRange()){
                    if(abs(L1.getPlayer().getCoordY()-L1.getMonster(i).getCoordY())<=L1.getMonster(i).getAttackRange()){
                        int HP=L1.getPlayer().getHealth();
                        HP-=L1.getMonster(i).getAttackDamage();
                        L1.getPlayer().setHealth(HP);
                    }
                }
            }
            for(int i=0;i<L1.getNumberOfMonsters();i++){
                if(abs(L1.getPlayer().getCoordX()-L1.getMonster(i).getCoordX())<=L1.getPlayer().getAttackRange()){
                    if(abs(L1.getPlayer().getCoordY()-L1.getMonster(i).getCoordY())<=L1.getPlayer().getAttackRange()){
                        int HP=L1.getMonster(i).getHealth();
                        HP-=L1.getPlayer().getAttackDamage();
                        L1.getMonster(i).setHealth(HP);
                    }
                }
                if(!L1.getMonster(i).isAlive()){
                    int n=L1.getNumberOfMonsters();
                    n--;
                    L1.setNumberOfMonsters(n);
                    for(int j=i;j<n;j++){
                        Monster aux(L1.getMonster(j+1));
                        L1.setMonster(aux,j);
                    }
                    L1.getMonster(n).setAttackDamage(0);
                    L1.getMonster(n).setLook(' ');
                }
            }
        }
    fin.close();
    return 0;
}

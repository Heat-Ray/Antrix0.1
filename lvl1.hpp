
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include "gal.hpp"
#define PI 3.14159265

using namespace std;
using namespace sf;

class gal::ai
{
    vector <anim*> *a;

public:
    ai(string str1, vector <anim*> *a1)
    {
        anim *h1 = new anim(str1,65,65,"enem1");
        h1->setPos(1000,1000);
        a1->push_back(h1);
        a = a1;
    }
    void think()
    {
        
    }
    
};

float yaan_ki_gatix=0,yaan_ki_gatiy=0;
int gati=-5;
float tvaran=0.005;
float disha=0.0;
double more=0;
float dhruv_x,dhruv_y,dhruv_x1,dhruv_y1;

void gal::lvl1()
{
    win = new RenderWindow(sf::VideoMode(1200, 600), "PR!");
    anim *h1 = new anim("Yaan1.png",65,65, "player");
    h1->setPos(600,300);
    a1.push_back(h1);
    b1.push_back(new bg("spacebg.png"));
    b1.push_back(new bg("star.png"));

    v1 = win->getDefaultView();

    //putting ai
    ai1.push_back(new ai("Yaane.png", &a1));
};

void gal::suno()
{
    bool k1,k2,k3,k4,k5,k6,k7;
    k1 = keyb1.isKeyPressed(Keyboard::Up);
    k2 = keyb1.isKeyPressed(Keyboard::Down);
    k3 = keyb1.isKeyPressed(Keyboard::Left);
    k4 = keyb1.isKeyPressed(Keyboard::Right);
    k5 = keyb1.isKeyPressed(Keyboard::Z);
    k6 = keyb1.isKeyPressed(Keyboard::X);
    k7 = keyb1.isKeyPressed(Keyboard::Space);

    if(k1)
    {
        ctrl.push_back(10);
    }
    else if(k2)
    {
        ctrl.push_back(11);
    }
    else if(k3)
    {
        ctrl.push_back(12);
    }
    else if(k4)
    {
        ctrl.push_back(13);
    }
    else if(k5)
    {
        ctrl.push_back(50);
    }
    else if(k6)
    {
        ctrl.push_back(51);
    }
    else if(k7)
    {
        ctrl.push_back(101);
    }
}

void gal::socho()
{
    if(ctrl.size()>0)
    {
        switch(ctrl[0])
        {
            case 10:    if(yaan_ki_gatiy>gati)
                        {
                            yaan_ki_gatiy-=tvaran;
                        }
                        
                        if(disha!=a1[0]->getRotation())
                        {
                            if(disha-a1[0]->getRotation()<0.8 && disha-a1[0]->getRotation()>-0.8)
                            {
                                disha=a1[0]->getRotation();
                            }
                            if(disha>a1[0]->getRotation())
                            {
                                if(disha-a1[0]->getRotation()>180)
                                {
                                    disha+=0.8;
                                }
                                else
                                {
                                    disha-=0.8;
                                }
                                
                            }
                            else
                            {
                                if(a1[0]->getRotation()-disha>180)
                                {
                                    disha-=0.8;
                                }
                                else
                                {
                                    disha+=0.8;
                                }
                            }
                            if(disha<0)
                            {
                                disha=360.0;
                            }
                            if(disha>360)
                            {
                                disha=0.0;
                            }
                        }
                        dhruv_x1=-yaan_ki_gatiy*sin(disha*PI/180);
                        dhruv_y1=yaan_ki_gatiy*cos(disha*PI/180);
                        break;
                
            case 11:    if(yaan_ki_gatiy<0)
                        {
                            yaan_ki_gatiy+=tvaran;
                        }
                        else
                        {
                            yaan_ki_gatiy=0.0;
                        }
                        dhruv_x1=-yaan_ki_gatiy*sin(disha*PI/180);
                        dhruv_y1=yaan_ki_gatiy*cos(disha*PI/180);
                        break;

            case 12:    a1[0]->rotate(-1.3);
                        if(yaan_ki_gatiy==0)
                        {
                            disha=a1[0]->getRotation();
                        }
                        break;

            case 13:    a1[0]->rotate(1.3);
                        if(yaan_ki_gatiy==0)
                        {
                            disha=a1[0]->getRotation();
                        }
                        break;

            case 101:   string s1 = "blt.png";
                        if(p1.size()>0 && p1[p1.size()-1]->dist>200)
                        {
                            p1.push_back(new projectile(s1, a1[0]->getRotation(), 16.0, 1000, a1[0]->getPosition().x, a1[0]->getPosition().y));
                        }
                        
                        if(p1.size()<1)
                        {
                            p1.push_back(new projectile(s1, a1[0]->getRotation(), 16.0, 1000, a1[0]->getPosition().x, a1[0]->getPosition().y));
                        }
                        break;

        }
        ctrl.erase(ctrl.begin());
    }
    if(atrl.size()>0)
    {

    }
}

void gal::karo()
{
    a1[0]->move(dhruv_x1,dhruv_y1);
    a1[0]->putspd(dhruv_x1, dhruv_y1);
    v1.move(dhruv_x1,dhruv_y1);
    b1[1]->move(dhruv_x1/2,dhruv_y1/2);
    win->setView(v1);
    for (size_t i = 0; i < p1.size(); i++)
    {
        if(p1[i]->endol(&a1)) p1.erase(p1.begin()+i);
        else p1[i]->exec(a1[0]->dhruv_x1, a1[0]->dhruv_y1);
    }
    
}

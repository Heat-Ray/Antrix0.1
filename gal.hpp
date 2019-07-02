#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#define PI 3.14159265

using namespace std;
using namespace sf;

class gal
{
    // routines to be loaded by main gal class
    void lvl1();
    void suno();
    void socho();
    void karo();
    //

    //class dec
    class ai;
    //

    // background class starts here
    class bg
    {
        Sprite s1;
        sf::IntRect *retc;
        Texture brd;
        
    public:

        bg(string st1)
        {
            brd.loadFromFile(st1);
            brd.setRepeated(true);
            retc = new IntRect(FloatRect(-500000,-500000,1000000,1000000));
            s1.setTexture(brd);
            s1.setTextureRect(*retc);
            s1.setPosition(-500000,-500000);
        }
        void move(float x1, float y1)
        {
            s1.move(x1,y1);
        }
        Sprite draw()
        {
            return s1;
        }

    };
    //background class ends here


    //animation class starts here
    class anim
    {
        Clock clk;
        Sprite s1;
        int anim_st = 1;
        int tx_sz;
        sf::IntRect *retc;
        int x1,y1;
        Texture yan;
        
    
    public:
        //public var declaration
        float dhruv_x1 = 0,dhruv_y1 = 0;
        string naam;

        anim(string st1, int sz1 , int sz2, string n)
        {
            x1 = sz1;
            y1 = sz2;

            yan.loadFromFile(st1);
            yan.setSmooth(true);
            tx_sz = yan.getSize().x;
            s1.setTexture(yan);
            if(sz1 == -1)
            {
                anim_st = -1;
            }
            else
            {
                retc = new IntRect(0, 0, sz1, sz2);
                s1.setTextureRect(*retc);
            }
            s1.setOrigin(33,33);
            naam = n;
        }
         
        Sprite draw()
        {
            if(anim_st == -1)
            {
                return s1;
            }
            else
            {
                if (clk.getElapsedTime().asSeconds() > 0.09f)
                {
                    if (retc->left == tx_sz-x1)
                    retc->left = 0;
                    else
                        retc->left += x1;

                    s1.setTextureRect(*retc);
                    clk.restart();
                    return s1;
                }
                return s1;
            }
            
        }
        float getRotation()
        {
            return s1.getRotation();
        }
        void rotate(float x)
        {
            s1.rotate(x);
        }
        void move(float x, float y)
        {
            s1.move(x,y);
        }
        void setPos(int x, int y)
        {
            s1.setPosition(x,y);
        }
        Vector2f getPosition()
        {
            return s1.getPosition();
        }
        void putspd(float x,float y)
        {
            dhruv_x1 = x;
            dhruv_y1 = y;
        }
    };
    // animation class ends here


    //projectile starts here
    class projectile
    {
        Sprite s1;
        Texture tx;
        float spd;
        float rng;

        
    public:
        
        float dist = 0;

        projectile(string str1, float orint, float speed, float range, float x, float y)
        {
            tx.loadFromFile(str1);
            s1.setTexture(tx);
            s1.setOrigin(3,3);
            s1.setRotation(orint);
            s1.setPosition(Vector2f(x,y));
            spd = speed;
            rng = range;
        }

        Sprite draw()
        {
            return s1;
        };

        void exec(float d_x, float d_y)
        {
            float x = spd*cos((s1.getRotation()+90)*PI/180);
            float y = spd*sin((s1.getRotation()+90)*PI/180);
            s1.move(-x + d_x, -y + d_y);
            dist +=spd;
        };

        bool endol()
        {
            if(dist > rng) return true;
            else return false;
        };

    };
    // projectile class ends here




    // containers to store resources and variables
    RenderWindow *win;
    Keyboard keyb1;
    vector <int> ctrl;
    vector <int> atrl;
    vector < anim* > a1;
    vector < bg* > b1;
    vector < projectile* > p1;
    vector < ai* > ai1;
    View v1;
    //

    


public:
    //constructor
    gal()
    {
        lvl1();
        rendr();
    }
    //
private:

    // renderloop
    void rendr()
    {
        win->setFramerateLimit(80);
        while(win->isOpen())
        {
            sf::Event event;
            while (win->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    win->close();
                }
            }
            suno();
            socho();
            karo();

            win->clear();

            for (size_t i = 0; i < b1.size(); i++)
            {
                win->draw(b1[i]->draw());
            }

            for (size_t i = 0; i < p1.size(); i++)
            {
                win->draw(p1[i]->draw());
            }

            for (size_t i = 0; i < a1.size(); i++)
            {
                win->draw(a1[i]->draw());
            }
            
            win->display();
        }
    };
    //

};

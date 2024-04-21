
/**
* @file ennemi.c
* @brief Testing Program.
* @author Chedly
* @version 0.1
* @date Apr 22 , 2022
*
* Testing program for colision *
*/


#include "entity.h"

/**
* @brief To initialize ENNEMI .
* @param e is the ennemi
* @return Nothing
*/


void initEnnemi(Ennemi *e)
{
    int i;

    //g is el ghoul
    /*
        e->en.g[0] =IMG_Load("graphic/menu/.png");//standing
        e->en.g[1] =IMG_Load("graphic/menu/.png");//dead

        e->en.posg[0].x=0;
        e->en.posg[0].y=0;
        e->en.posg[0].h=e->en.g[0]->h;
        e->en.posg[0].w=e->en.g[0]->w/3;

        e->en.posg[1].x=0;
        e->en.posg[1].y=0;
        e->en.posg[1].h=e->en.g[1]->h;
        e->en.posg[1].w=e->en.g[1]->w/3;
    */





    //a is azouzet estoot


    e->en.a[0]=e->en.a[1]=IMG_Load("image/a/as.png");    // going right and left
    e->en.a[2] =IMG_Load("image/a/ashitt.png");//attack
    e->en.a[3] =IMG_Load("image/a/asdead.png");//dead



    e->en.pos[0].x=0;
    e->en.pos[0].y=0;
    e->en.pos[0].h=e->en.a[0]->h;
    e->en.pos[0].w=e->en.a[0]->w/10;

    e->en.pos[1].x=0;
    e->en.pos[1].y=0;
    e->en.pos[1].h=e->en.a[1]->h;
    e->en.pos[1].w=e->en.a[1]->w/10;

    e->en.pos[2].x=0;
    e->en.pos[2].y=0;
    e->en.pos[2].h=e->en.a[2]->h;
    e->en.pos[2].w=e->en.a[2]->w/5;

    e->en.pos[3].x=0;
    e->en.pos[3].y=0;
    e->en.pos[3].h=e->en.a[3]->h;
    e->en.pos[3].w=e->en.a[3]->w/5;

   


   

  
}

/**
* @brief To show ENNEMI .
* @param e is the ennemi
* @param screen is the screen
* @return Nothing
*/



void afficherEnnemi(Ennemi e, SDL_Surface * screen)

{
   

          SDL_BlitSurface(e.en.a[e.etat], &e.en.pos[e.etat], screen, &e.pos[e.etat]);
   

    }



/**
* @brief To animate ENNEMI .
* @param e is the ennemi
* @param screen is the screen
* @return Nothing
*/

void animerEnnemi( Ennemi * e)

{

   
        switch(e->etat)
        {
        case 0:
            if(e->en.pos[e->etat].x <1800)
                e->en.pos[e->etat].x +=  e->en.pos[e->etat].w;
            else
            {
                e->en.pos[e->etat].x =0;
            }
        break;   

        case 1:
            if(e->en.pos[e->etat].x <1800)
                e->en.pos[e->etat].x +=  e->en.pos[e->etat].w;
            else
            {
                e->en.pos[e->etat].x =1000;

            }
            SDL_Delay(230);

            break;
        case 2:
            if(e->en.pos[e->etat].x <800)
                e->en.pos[e->etat].x +=  e->en.pos[e->etat].w;
            else
            {
                e->en.pos[e->etat].x =0;

            }
            SDL_Delay(120);

            break;
        case 3:
            if(e->en.pos[e->etat].x <1000)
            {
                e->en.pos[e->etat].x +=  e->en.pos[e->etat].w;
            }

            SDL_Delay(400);

            break;

        }
 
    
}
/**
* @brief To deplace ENNEMI .
* @param e is the ennemi
* @return nothing
*/

void deplacer(Ennemi *e) {
    if (e->etat != 0) {
        switch (e->etat) {
            case 1:
                e->pos->x -= 5;
                break;

            case 2:
                if ((e->pos->x <= 1000) && (e->pos->x >= 400)) {
                    e->pos->x -= 15;
                }
                break;

            
        }
    }
}

void deplacerIA(Ennemi *e) {
    if (e->etat != 0) {
        switch (e->etat) {
            case 1:
                e->en.pos[0].x -= 5; // Move left
                break;

            case 2:
                if (e->en.pos[0].x > 1000)
                    e->en.pos[0].x -= 15; // Move left
                else if (e->en.pos[0].x < 400)
                    e->en.pos[0].x += 15; // Move right
                break;

            default:
                break;
        }
    }
}
/**
* @brief To show ENNEMI .
* @param a is the ennemi
* @param b is the player
* @return if there is a colision or not
*/

int collisionBox(SDL_Rect a, SDL_Rect b)
{
    if(a.x+a.w<b.x || a.x>b.x+b.w ||a .y+a.h<b.y || a.y>b.y+b.h)
        return 0;
    else
        return 1;
}

void updateEnnemi (Ennemi* E, SDL_Rect posHero )
{
     if (E->etat != 3) {
        if ((E->en.pos[E->etat].x - posHero.x) >= 200)
            E->etat = 1;
    
      
    }


}

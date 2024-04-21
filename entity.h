/** 
* @file ennemi.h 
* @brief .h. 
* @author CHEDHLY 
* @version 0.1 
* @date Apr 22, 2022
* 
* Testing program for colision * 
*/
#ifndef ENTITY_H_INCLUDED2
#define ENTITY_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>					


/** 
* @struct ennemi
* @brief struct for ennemi 
*/ 

typedef struct 
{
		SDL_Rect pos[4];
			SDL_Surface *a[4];
}ennemi;

/** 
* @struct Ennemi
* @brief struct for different type of enemies
*/ 

typedef struct 
{

	ennemi en;
	SDL_Rect pos[4];
	int etat;/*!< ETAT D'ENNEMIE */
	
}Ennemi;

/** 
* @struct image
* @brief struct for just showing the persone
*/ 
	
	typedef struct
{
	SDL_Rect pos;
	SDL_Surface *img;
}image;
	
void initEnnemi(Ennemi *e);
void afficherEnnemi(Ennemi e, SDL_Surface * screen);
void animerEnnemi( Ennemi * e);
void deplacer( Ennemi * e);
void deplacerIA(Ennemi *e);
int collisionBox(SDL_Rect a, SDL_Rect b);
void updateEnnemi (Ennemi* E, SDL_Rect posHero );


#endif

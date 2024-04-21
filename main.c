/**
* @file mainennemi.c
* @brief Testing Program.
* @author CHEDHLY
* @version 0.1
* @date Apr 22 , 2022
*
* Testing program for EVERYTHING *
*/
#include "entity.h"

int main() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Unable to initialize SDL: %s\n", SDL_GetError());
        return 1; // Return 1 to indicate an error
    }

    // Set window caption
    SDL_WM_SetCaption("ENNEMI", NULL);
    
    // Create the screen surface
    SDL_Surface *screen = SDL_SetVideoMode(1380, 700, 32, SDL_HWSURFACE | SDL_SWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);
    if (screen == NULL) {
        printf("Error: %s\n", SDL_GetError());
        return 1; // Return 1 to indicate an error
    }

    // Load images
    image back, colision;
    colision.img = IMG_Load("w");
    if (colision.img == NULL) {
        printf("Error loading w image: %s\n", IMG_GetError());
        return 1; // Return 1 to indicate an error
    }
    colision.pos.x = 0;
    colision.pos.y = 350;
    colision.pos.h = colision.img->h; // Height of the image
    colision.pos.w = colision.img->w; // Width of the image

    back.img = IMG_Load("file.jpg");
    if (back.img == NULL) {
        printf("Error loading file.jpg image: %s\n", IMG_GetError());
        return 1; // Return 1 to indicate an error
    }
    back.pos.x = 0;
    back.pos.y = 0;

    // Initialize enemy
    Ennemi e;
    initEnnemi(&e);
    e.etat = 0;

    // Initialize loop variables
    int cont = 1, ched = 0, ed = 0;
    SDL_Event event;

    // Main loop
    while (cont) {
        // Handle events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                cont = 0; // Exit the loop
            } else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
                ched = 1; // Set the exit flag
            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    ched = 1; // Set the exit flag
                    e.etat = 3; // Set enemy state
                }
            }
        }
	 colision.pos.x += 10;
        // Perform other tasks
        SDL_BlitSurface(back.img, NULL, screen, &back.pos);
        SDL_BlitSurface(colision.img, NULL, screen, &colision.pos);
        
        if ((ed == 1) && (collisionBox(e.en.pos[0], colision.pos) != 1)) {
            e.etat = 0;
            ed = 0;
        }
        
        if (ched == 0) {
            animerEnnemi(&e);
            afficherEnnemi(e, screen);
            deplacer(&e);
            
            if (collisionBox(e.en.pos[0], colision.pos)) {
                e.etat = 2;
                ed = 1;
            }
            
            if (e.etat != 2)
                updateEnnemi(&e, colision.pos);
        }

        // Update the screen
        SDL_Flip(screen);
    }

    // Free surfaces
    SDL_FreeSurface(back.img);
    SDL_FreeSurface(colision.img);
    
    // Quit SDL
    SDL_Quit();

    return 0; // Return 0 to indicate successful execution
}

/*****************************************************************************************
/* File: IO.cpp
/* Desc: Class for handling inpung & drawing, it uses SDL for the rendering. Change the methods
/* of this class in order to use a different renderer
/*
/*
/* gametuto.com - Javier Lopez Lopez (javilop.com)
/*
/*****************************************************************************************
/*
/* Creative Commons - Attribution 3.0 Unported
/* You are free:
/*	to Share - to copy, distribute and transmit the work
/*	to Remix - to adapt the work
/*
/* Under the following conditions:
/* Attribution. You must attribute the work in the manner specified by the author or licensor
/* (but not in any way that suggests that they endorse you or your use of the work).
/*
/*****************************************************************************************/

#include "IO.h"

/*
* ------------------------------------------------------------------*
*						     IO CPP File							*
* ------------------------------------------------------------------*
*/

// Static Variables
static SDL_Surface* mScreen;
static Uint32 mColors [COLOR_MAX] = {0x000000ff, 0xff0000ff, 0x00ff00ff, 0x0000ffff,
                                     0x00ffffff, 0xff00ffff, 0xffff00ff, 0xffffffff };

/*
* =========================================================================
* Initialization.
* =========================================================================
*/
IO::IO() {
    InitGraph();
}

/*
* =========================================================================
* Clears the screen to black
* =========================================================================
*/
void IO::ClearScreen() {
    boxColor(mScreen, 0, 0, mScreen->w - 1, mScreen->h - 1, mColors[BLACK]);
}

/*
* =========================================================================
* Draws a rectangle of the given color.
* 
* Parameters:
* 
* >> pX1, pY1:          upper left corner of the rectangle
* >> pX2, pY2:          lower right corner of the rectangle
* >> pC:                color of the rectangle
* =========================================================================
*/
void IO::DrawRect(int pX1, int pY1, int pX2, int pY2, enum color pC) {
    boxColor(mScreen, pX1, pY1, pX2, pY2 - 1, mColors[pC]);
}

/*
* =========================================================================
* Returns the height of the screen.
* =========================================================================
*/
int IO::GetScreenHeight() {
    return mScreen->h;
}

/*
* =========================================================================
* Updates the screen.
* =========================================================================
*/
void IO::UpdateScreen() {
    SDL_Flip(mScreen);
}

/*
* =========================================================================
* Searches for keyboard input.
* =========================================================================
*/
int IO::Pollkey() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_KEYDOWN:
                return event.key.keysym.sym;
            case SDL_QUIT:
                exit(3);
        }
    }

    return -1;
}

/*
* =========================================================================
* Gets the keyboard input.
* =========================================================================
*/
int IO::Getkey() {
    SDL_Event event;

    while (true) {
        SDL_WaitEvent(&event);

        if (event.type == SDL_KEYDOWN) {
            break;
        }

        if (event.type == SDL_QUIT) {
            exit(3);
        }
    };

    return event.key.keysym.sym;
}

/*
* =========================================================================
* Checks if keyboard input is active.
* =========================================================================
*/
int IO::IsKeyDown(int pKey) {
    Uint8* mKeytable;
    int mNumKeys;
    
    SDL_PumpEvents();
    mKeytable = SDL_GetKeyState(&mNumKeys);
    
    return mKeytable[pKey];
}

/*
* =========================================================================
* Initializes SDL Graphics
* =========================================================================
*/
int IO::InitGraph() {
    const SDL_VideoInfo* info;
    Uint8 video_bpp;
    Uint32 videoflags;

    // initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Couldn't initialize SDL: %s\n", SDL_GetError());
        return 1;
    }
    atexit(SDL_Quit);

    // alpha blending doesn't work well in 8-bit color
    info = SDL_GetVideoInfo();
    if (info->vfmt->BitsPerPixel > 8) {
        video_bpp = info->vfmt->BitsPerPixel;
    }
    else {
        video_bpp = 16;
    }

    videoflags = SDL_SWSURFACE | SDL_DOUBLEBUF;

    // set video mode to 640x480
    if ((mScreen = SDL_SetVideoMode(640, 480, video_bpp, videoflags)) == NULL) {
        fprintf(stderr, "Couldn't set %ix%i video mode: %s\n", 640, 480, SDL_GetError());
        return 2;
    }

    return 0;
}
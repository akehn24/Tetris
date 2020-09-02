/*****************************************************************************************
/* File: Game.h
/* Desc: General class for the game
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

#pragma once
#ifndef _GAME_
#define _GAME_

// Includes
#include "Board.h"
#include "Pieces.h"
#include "IO.h"
#include <time.h>

// Defines
#define WAIT_TIME 700			// Number of milliseconds before the piece moves


/*
* ------------------------------------------------------------------*
*						Game Header File							*
* ------------------------------------------------------------------*
* 
* __Notes__
* Initializes the Tetris clone game. Draws the board and pieces by 
* drawing the blocks as rectangles. Creates random pieces from those
* available. 
* 
* * ------------------------------------------------------------------*
*/

class Game {

public:

	Game						(Board* pBoard, Pieces* pPieces, IO* pIO, int pScreenHeight);
	void DrawScene				();
	void CreateNewPiece			();
	
	int mPosX, mPosY;			// Position of the active piece
	int mPiece;					// What kind of piece is active
	int mRotation;				// Which rotation of the active piece

private:

	int mScreenHeight;			// Screen height in pixels
	int mNextPosX, mNextPosY;	// Position of the upcoming piece
	int mNextPiece;				// What kind of piece is upcoming
	int mNextRotation;			// Which rotation of the upcoming piece

	Board* mBoard;			
	Pieces* mPieces;			
	IO* mIO;

	int GetRand					(int pA, int pB);
	void InitGame				();
	void DrawPiece				(int pX, int pY, int pPiece, int pRotation);
	void DrawBoard				();

};

#endif
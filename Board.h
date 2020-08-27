#pragma once
#ifndef _BOARD_
#define _BOARD_

// Includes
#include "Pieces.h"

// Defines
#define BOARD_LINE_WIDTH		6			// Width of each of the lines that define the border
#define BLOCK_SIZE				16			// Width and height of each block of a piece
#define BOARD_POSITION			320			// Center position of the board - from left of screen
#define BOARD_WIDTH				10			// Board width in blocks
#define BOARD_HEIGHT			20			// Board height in blocks
#define MIN_VERTICAL_MARGIN		20			// Min vertical margin for board limit
#define MIN_HORIZONTAL_MARGIN	20			// Min horizontal margin for board limit
#define PIECE_BLOCKS			5			// Num of horizontal and vertical blocks in a matrix piece


/*
* ------------------------------------------------------------------*
* Board Header File													*
* ------------------------------------------------------------------*
*/


/*  __NOTES__
*	Stores a 2D array of blocks that represent the game board. These 
*	are changed to reflect which piece is moving through the board
*	and have "landed" in the bottom. 
* 
*	POS_FREE    - initial state of each block in the board array
*	POS_FILLED  - where a block is located in the board array at a given time
*
* ------------------------------------------------------------------*
*/

class Board {

public:

	Board				(Pieces* pPieces, int pScreenHeight);
	int GetXPosInPix	(int pPos);
	int GetYPosInPix	(int pPos);
	bool IsFreeBlock	(int pX, int pY);
	bool IsPossMove		(int pX, int pY, int pPiece, int pRotation);
	void StorePiece		(int pX, int pY, int pPiece, int pRotation);
	void DelPossLines	();
	bool IsGameOver		();

private:
	
	enum { POS_FREE, POS_FILLED };
	int mBoard[BOARD_WIDTH][BOARD_HEIGHT];
	Pieces* mPieces;
	int mScreenHeight;

	void InitBoard();
	void DeleteLine(int pY);
};

#endif
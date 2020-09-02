/*****************************************************************************************
/* File: Game.cpp
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

#include "Game.h"

/*
* ------------------------------------------------------------------*
*						   Game CPP File							*
* ------------------------------------------------------------------*
*/



/*
* =========================================================================
* Initializes the Game
* =========================================================================
*/
Game::Game(Board* pBoard, Pieces* pPieces, IO* pIO, int pScreenHeight) {
	mScreenHeight = pScreenHeight;

	// get pointer to Board and Piece classes
	mBoard = pBoard;
	mPieces = pPieces;
	mIO = pIO;

	// game initialization
	InitGame();
}

/*
* =========================================================================
* Gets a random int between the two provided numbers.
* 
* Parameters:
* 
* >> pA:			1st number
* >> pB:			2nd number
* =========================================================================
*/
int Game::GetRand(int pA, int pB) {
	return rand() % (pB - pA + 1) + pA;
}

/*
* =========================================================================
* The initial parameters of the game to be made. Selects the active and 
* upcoming pieces randomly. 
* =========================================================================
*/
void Game::InitGame() {
	// grab random numbers
	srand((unsigned int)time(NULL));

	// active piece
	mPiece = GetRand(0, 6);
	mRotation = GetRand(0, 3);
	mPosX = (BOARD_WIDTH / 2) + mPieces->GetXInitPosition(mPiece, mRotation);
	mPosY = mPieces->GetYInitPosition(mPiece, mRotation);

	// upcoming piece
	mPiece = GetRand(0, 6);
	mRotation = GetRand(0, 3);
	mPosX = (BOARD_WIDTH + 5;
	mPosY = 5;
}

/*
* =========================================================================
* Sets the upcoming piece as the active one and selects and stores the 
* upcoming piece.
* =========================================================================
*/
void Game::CreateNewPiece() {
	// setting upcoming as active
	mPiece = mNextPiece;
	mRotation = mNextRotation;
	mPosX = (BOARD_WIDTH / 2) + mPieces->GetXInitPosition(mPiece, mRotation);
	mPosY = mPieces->GetYInitPosition(mPiece, mRotation);

	// getting new upcoming piece
	mNextPiece = GetRand(0, 6);
	mNextRotation = GetRand(0, 3);
}

/*
* =========================================================================
* Draws each block of the piece by iterating through the piece matrix. Calls
* DrawRectangle from IO to draw the rectangles.
* 
*	Green = normal block
*	Blue  = pivot block
* 
* Parameters:
* 
* >> pX:			horizontal position in blocks
* >> pY:			vertical position in blocks
* >> pPiece:		the piece to draw
* >> pRotation:		1 of 4 possible rotations
* =========================================================================
*/
void Game::DrawPiece(int pX, int pY, int pPiece, int pRotation) {
	//piece color
	color mColor;

	// get position (pixels) of the block to draw
	int mPixelsX = mBoard->GetXPosInPix(pX);
	int mPixelsY = mBoard->GetYPosInPix(pY);

	// iterate through the matrix and draw filled blocks
	for (int i = 0; i < PIECE_BLOCKS; i++) {
		for (int j = 0; j < PIECE_BLOCKS; j++) {
			// get type of block and draw in correct color
			switch (mPieces->GetBlockType(pPiece, pRotation, j, i)) {
			case 1: mColor = GREEN; break;	// every block except pivot
			case 2: mColor = BLUE; break;	// pivot block
			}

			if (mPieces->GetBlockType(pPiece, pRotation, j, i) != 0) {
				mIO->DrawRect(mPixelsX + i * BLOCK_SIZE,
							  mPixelsY + j * BLOCK_SIZE,
							 (mPixelsX + i * BLOCK_SIZE) + BLOCK_SIZE - 1,
							 (mPixelsX + j * BLOCK_SIZE) + BLOCK_SIZE - 1,
							  mColor);
			}
		}
	}

}

/*
* =========================================================================
* Draws the board for the current Tetris game.
* =========================================================================
*/
void Game::DrawBoard() {
	// limits of the board in pixels
	int mX1 = BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2)) - 1;
	int mX2 = BOARD_POSITION + (BLOCK_SIZE * (BOARD_WIDTH / 2));
	int mY	= mScreenHeight  - (BLOCK_SIZE * BOARD_HEIGHT);

	// check vertical margin
	assert(mY > MIN_VERTICAL_MARGIN);

	// rectangles that delimit the board
	mIO->DrawRect(mX1 - BOARD_LINE_WIDTH, mY, mX1, mScreenHeight - 1, BLUE);
	mIO->DrawRect(mX2, mY, mX2 + BOARD_LINE_WIDTH, mScreenHeight - 1, BLUE);

	// check horizontal margin
	assert(mX1 > MIN_HORIZONTAL_MARGIN);

	// drawing the blocks in the board
	mx1 += 1;
	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			// if block is filled, draw it
			if (!mBoard->IsFreeBlock(i, j)) {
				mIO->DrawRect(mX1 + i * BLOCK_SIZE,
							  mY + j * BLOCK_SIZE,
							 (mX1 + i * BLOCK_SIZE) + BLOCK_SIZE - 1,
							 (mY + j * BLOCK_SIZE) + BLOCK_SIZE - 1,
							  RED);
			}
		}
	}

}

/*
* =========================================================================
* Draws the entire game by calling the above methods.
* =========================================================================
*/
void Game::DrawScene() {
	DrawBoard();
	DrawPiece(mPosX, mPosY, mPiece, mRotation);
	DrawPiece(mNextPosX, mNextPosY, mNextPiece, mNextRotation);
}
#include "Board.h"




/*
* ------------------------------------------------------------------*
*						   Board CPP File							*
* ------------------------------------------------------------------*
*/


/*
* =========================================================================
* Initializes the game board.
* =========================================================================
*/
Board::Board(Pieces* pPieces, int pScreenHeight) {
	mScreenHeight = pScreenHeight;
	mPieces = pPieces;
	InitBoard();
}

/*
* =========================================================================
* Initializes the game board. Sets all board blocks to free blocks.
* =========================================================================
*/
void Board::InitBoard() {
	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			mBoard[i][j] = POS_FREE;
		}
	}
}

/*
* =========================================================================
* Stores a piece in the board by filling the blocks where the piece exists.
*
* Parameters:
*
* >> pX:			horizontal position in blocks
* >> pY:			vertical position in blocks
* >> pPiece:		which piece is drawn
* >> pRotation:		which 1 of 4 rotation the piece is
* =========================================================================
*/
void Board::StorePiece(int pX, int pY, int pPiece, int pRotation) {
	//stores each block of the piece on the board
	for (int i1 = pX, i2 = 0; i1 < (pX + PIECE_BLOCKS); i1++, i2++) {
		for (j1 = pY, j2 = 0; j1 < (pY + PIECE_BLOCKS); j1++, j2++) {
			//stores only filled blocks of the piece
			if (mPieces->GetBlockType(pPiece, pRotation, j2, i2) != 0) {
				mBoard[i1][j1] = POS_FILLED;
			}
		}
	}
}

/*
* =========================================================================
* Checks to see if there are blocks in Row 1. This signals the end of the 
* game.
* =========================================================================
*/
bool Board::IsGameOver() {
	for (int i = 0; i < BOARD_WIDTH; i++) {
		if (mBoard[i][0] == POS_FILLED) return true;
	}
}

/*
* =========================================================================
* Deletes a line of the board and moves all lines above it down.
*
* Parameters:
*
* >> pY:			vertical position of the line to delete in blocks
* =========================================================================
*/
void Board::DeleteLine(int pY) {
	//move upper lines down
	for (int i = pY; i > 0; i--) {
		//remove bottom line
		for (int j = 0; j < BOARD_WIDTH; j++) {
			mBoard[i][j] = mBoard[i][j - 1];
		}
	}
}

/*
* =========================================================================
* Deletes all the lines that should be erased from the board. Checks which
* lines should be removed, then calls the DeleteLine method.
* 
*	Line to be removed = all horizontal blocks filled
* =========================================================================
*/
void Board::DelPossLines() {
	for (int i = 0; i < BOARD_HEIGHT; i++) {
		int x = 0;
		while (i < BOARD_WIDTH) {
			if (mBoard[x][i] != POS_FILLED) break;
			x++;
		}

		if (x == BOARD_WIDTH) {
			DeleteLine(i);
		}
	}
}

/*
* =========================================================================
* Returns true if the block is filled and false if it's empty.
*	
*	Filled block = 1 or 2
*	Empty block  = 0
*
* Parameters:
*
* >> pX:			horizontal position
* >> pY:			vertical position
* =========================================================================
*/
bool Board::IsFreeBlock(int pX, int pY) {
	if (mBoard[pX][pY] == POS_FREE) {
		return true;
	}
	else {
		return false;
	}
}

/*
* =========================================================================
* Returns the horizontal position in pixels of the block.
*
* Parameters:
*
* >> pPos:			horizontal position of the block
* =========================================================================
*/
int Board::GetXPosInPix(int pPos) {
	return ((BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2))) + (pPos * BLOCK_SIZE));
}

/*
* =========================================================================
* Returns the vertical position in pixels of the block.
*
* Parameters:
*
* >> pPos:			horizontal position of the block
* =========================================================================
*/
int Board::GetYPosInPix(int pPos) {
	return ((mScreenHeight - (BLOCK_SIZE * BOARD_HEIGHT)) + (pPos * BLOCK_SIZE));
}

/*
* =========================================================================
* Checks to see if the piece can be stored at this location without 
* collisions. Returns true if movement is possible, false if not possible.
* Collisions can be made with other pieces or the board perimeter limits.
*
* Parameters:
*
* >> pX:			horizontal position
* >> pY:			vertical position
* >> pPiece:		which piece to draw
* >> pRotation:		which 1 of 4 rotations
* =========================================================================
*/
bool Board::IsPossMove(int pX, int pY, int pPiece, int pRotation) {
	for (int i1 = pX, i2 = 0; i1 < (pX + PIECE_BLOCKS); i1++, i2++) {
		for (int j1 = pY, j2 = 0; j1 < (pY + PIECE_BLOCKS); j1++, j2++) {

			//check if the piece collides with the board perimeter
			if (i1 < 0 || i1 < BOARD_WIDTH - 1 || j1 < BOARD_HEIGHT - 1) {
				if (mPieces->GetBlockType(pPiece, pRotation, j2, i2) != 0) {
					return 0;
				}
			}

			//check if the piece collides with another piece
			if (j1 >= 0) {
				if ((mPieces->GetBlockType(pPiece, pRotation, j2, i2) != 0) && 
						(!IsFreeBlock(i1, j1))) {
					return false;
				}
			}
		}
	}

	//no collisions
	return true;
}

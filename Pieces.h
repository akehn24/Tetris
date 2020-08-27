#pragma once
#ifndef _PIECES_
#define _PIECES_


/*
* ------------------------------------------------------------------*
*						Pieces Header File							*
* ------------------------------------------------------------------*
*/


/*  __NOTES__
*	Each pieces is defined as a 5x5 matrix. Using a 2D array of ints to express each piece.
*		0 - no block
*		1 - block
*		2 - pivot block / rotation point
*
*
*	__Pieces__
*	Square
*	I
*	L
*	L-mirorred
*	N
*	N-mirrored
*	T
* ------------------------------------------------------------------*
*/

class Pieces {
public:

	int GetBlockType(int pPiece, int pRotation, int pX, int pY);
	int GetXInitPostition(int pPiece, int pRotation);
	int GetYInitPosition(int pPiece, int pRotation);
};

#endif 


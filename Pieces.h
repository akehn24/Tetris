#pragma once
#ifndef _PIECES_
#define _PIECES_


/*
* ------------------------------------------------------------------*
*						Pieces Header File							*
* ------------------------------------------------------------------*
*/

class Pieces {
public:

	int GetBlockType(int pPiece, int pRotation, int pX, int pY);
	int GetXInitPostition(int pPiece, int pRotation);
	int GetYInitPosition(int pPiece, int pRotation);
};

#endif 


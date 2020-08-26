




/*
* ------------------------------------------------------------------*
*						   Pieces CPP File							*
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

/*Pieces Definition
*	The 2D array that defines each piece. 
*	1 Array - original piece (U rotation)
*	2 Array - R rotation
*	3 Array - D rotation
*	4 Array - L rotation
* 
*	7 - number of pieces
*	4 - rotations per piece
*	5 - horizontal blocks
*	5 - vertical blocks
*/
char make_Pieces[7][4][5][5]
{
// Square
	{
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 2, 1, 0},
			{0, 0, 1, 1, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 2, 1, 0},
			{0, 0, 1, 1, 0},
			{0, 0, 0, 0, 0},
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 2, 1, 0},
			{0, 0, 1, 1, 0},
			{0, 0, 0, 0, 0},
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 2, 1, 0},
			{0, 0, 1, 1, 0},
			{0, 0, 0, 0, 0},
		}
	},
// I
	{
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 1, 2, 1, 1},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		},
			{0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 2, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 1, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{1, 1, 2, 1, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 1, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 2, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 0, 0, 0}
		}
	},
// L
	{
		{
			{0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 2, 0, 0},
			{0, 0, 1, 1, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 1, 2, 1, 0},
			{0, 1, 0, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 1, 1, 0, 0},
			{0, 0, 2, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 1, 0},
			{0, 1, 2, 1, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		},
	},
// L-mirrored
	{
		{
			{0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 2, 0, 0},
			{0, 1, 1, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 1, 0, 0, 0},
			{0, 1, 2, 1, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 1, 1, 0},
			{0, 0, 2, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 1, 2, 1, 0},
			{0, 0, 0, 1, 0},
			{0, 0, 0, 0, 0}
		},
	},
// N
	{
		{
			{0, 0, 0, 1, 0},
			{0, 0, 0, 1, 0},
			{0, 0, 2, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 1, 2, 0, 0},
			{0, 0, 0, 1, 1},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 2, 0, 0},
			{0, 1, 0, 0, 0},
			{0, 1, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{1, 1, 0, 0, 0},
			{0, 0, 2, 1, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		},
	},
// N-mirrored
	{
		{
			{0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 2, 0, 0},
			{0, 0, 0, 1, 0},
			{0, 0, 0, 1, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 2, 1, 0},
			{0, 1, 0, 0, 0},
			{0, 1, 0, 0, 0}
		},
		{
			{0, 1, 0, 0, 0},
			{0, 1, 0, 0, 0},
			{0, 0, 2, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 1, 1},
			{0, 1, 2, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		},
	},
// T
	{
		{
			{0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 2, 1, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 1, 2, 1, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 1, 2, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 1, 2, 1, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		},
	},
};

/*Piece Positioning
*	The positioning data for each piece. Each needs to appear in a 
*	specific postion in order to align with the top of the game board.
* 
*	7 - number of pieces
*	4 - number of rotations per piece
*	2 - (x, y) positioning 
*/
int piece_positioning[7][4][2]
{
// Square
	{
		{-2, -3},
		{-2, -3},
		{-2, -3},
		{-2, -3}
	},
// I
	{
		{-2, -2},
		{-2, -3},
		{-2, -2},
		{-2, -3}
	},
// L
	{
		{-2, -3},
		{-2, -3},
		{-2, -3},
		{-2, -2}
	},
// L-mirrored
	{
		{-2, -3},
		{-2, -2},
		{-2, -3},
		{-2, -3}
	},
// N
	{
		{-2, -3},
		{-2, -3},
		{-2, -3},
		{-2, -2}
	},
// N-mirrored
	{
		{-2, -3},
		{-2, -3},
		{-2, -3},
		{-2, -2}
	},
// T
	{
		{-2, -3},
		{-2, -3},
		{-2, -3},
		{-2, -2}
	}
};

/*
* =========================================================================
* Return the type of a block.
*	0 = no block
*	1 = block
*	2 = pivot block / rotation block
* 
* Parameters:
* 
* >> pPiece:			the piece to draw
* >> pRotation:			1 of 4 possible rotations
* >> pX:				horizontal position in blocks
* >> pY:				vertical position in blocks
* =========================================================================
*/
int Pieces::GetBlockType(int pPiece, int pRotation, int pX, int pY) {
	return mPieces[pPiece][pRotation][pX][pY];
}


/*
* =========================================================================
* Return the horizontal placement of the given piece. 
*
* Parameters:
*
* >> pPiece:			the piece to draw
* >> pRotation:			1 of 4 possible rotations
* =========================================================================
*/
int GetXInitPostition(int pPiece, int pRotation) {
	return mPiecesInitPosition[pPiece][pRotation];
}


/*
* =========================================================================
* Return the vertical placement of the given piece. 
*
* Parameters:
*
* >> pPiece:			the piece to draw
* >> pRotation:			1 of 4 possible rotations
* =========================================================================
*/
int GetYInitPosition(int pPiece, int pRotation) {

}
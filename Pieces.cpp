/* Pieces Definition - 
*	Each pieces is defined as a 5x5 matrix. Using a 2D array of ints to express each piece.
*		0 - no block
*		1 - block
*		2 - pivot block / rotation point
* 
* 
* __Pieces__
* Square - 
* I - 
* L - 
* L-mirorred - 
* N - 
* N-mirrored - 
* T - 
*/

/*Pieces Definition
*	The 2D array that defines each piece. 
* 
*	7 - number of pieces
*	4 - rotations per piece
*	5 - horizontal blocks
*	5 - vertical blocks
*/
char make_Pieces[7][4][5][5]{
	// Square
	{
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 2, 1, 0},
			{0, 0, 1, 1, 0},
			{0, 0, 0, 0, 0}
		},
	};
	// I
	{
		{
		},
	};
	// L
	{
		{
		},
	};
	// L-mirrored
	{
		{
		},
	};
	// N
	{
		{
		},
	};
	// N-mirrored
	{
		{
		},
	};
	// T
	{
		{
		},
	};
}
/*****************************************************************************************
/* File: Pieces.h
/* Desc: All the Tetris pieces with their respective rotations and displacements for the hotspot
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

	int GetBlockType		(int pPiece, int pRotation, int pX, int pY);
	int GetXInitPosition	(int pPiece, int pRotation);
	int GetYInitPosition	(int pPiece, int pRotation);
};

#endif 


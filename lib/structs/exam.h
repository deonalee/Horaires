/*
 * This file is part of UMons - horaires projects
 *
 *	Created on: 28/11/2013
 *		Authors: Quentin Loos, Alexandre Devaux, Jérôme Dauge
 *
 */
 
#ifndef EXAM_H_
#define EXAM_H_

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char uchar;
typedef uchar* puchar;
typedef ushort* pushort;
typedef uint* puint;

typedef struct {
	ushort exam_id;
	uint teacher_id;

	uchar timeslot; // assigned timeslot
	ushort enrollment; // number of students, also sizeof students

	puchar unavailabilities; // list of unavailabilities
	pushort deps; // list of prerequisites
	puint students; // list of students enrolled in the event

	pushort conflicts; // list of events in conflicts with this
} exam;

#endif /*EXAM_H_*/
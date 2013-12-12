/*
 * This file is part of Umons - horaires project
 *
 *  Created on: 28/11/2013
 *      Authors: Quentin Loos, Alexandre Devaux, Jérôme Dauge
 *
 */

#ifndef CONFLICT_H_
#define CONFLICT_H_

/**
 * Compute conflict between two exams. The exam->students array
 * MUST be sorted.
 *
 * @param exam1 The first exam
 * @param exam2 The second exam
 * @return true if the two exams are in conflict, false otherwise.
 */
bool compute_conflict(exam const *exam1, exam const *exam2);

/**
 * Given an array of exams, computes all of the conflicts between
 * each exam & fills the exam->conflicts array
 *
 * @param exams Array of exams
 * @param nbr_exam Size of the array
 */
void compute_conflicts(array_exams const *exams);

#endif /*CONFLICT_H_*/

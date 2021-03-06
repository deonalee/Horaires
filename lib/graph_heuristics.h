/*
 * This file is part of UMons - horaires project
 *
 *  Created on: 28/11/2013
 *      Authors: Quentin Loos, Alexandre Devaux, Jérôme Dauge
 *
 */

#ifndef GRAPH_HEURISTICS_H_
#define GRAPH_HEURISTICS_H_

#define NOT_SCHEDULED UINT8_MAX
#define NO_SAT        UINT8_MAX


/**
 * This function returns a pointer to the next exam to schedule,
 * following the saturation degree first and the largest
 * enrollment in case of tie-break.
 *
 * @param  exams An array of exams (struct array_exams).
 * @param  max_timeslot Maximum available timeslots.
 * @return The next exam to schedule following our heuristics.
 */
exam *get_first_exam(array_exams *exams, uint8_t max_timeslot);

/**
 * This function returns an array regrouping the saturation
 * degree for each given exams. The degree of already scheduled exams
 * is set to 255, considered as a special value to not consider.
 *
 * @param  exams An array of exams (struct array_exams).
 * @param  max_timeslot Maximum available timeslots.
 * @return An array regrouping saturation degree for the given parameter.
 */
uint8_t *get_exams_saturation_degree(array_exams *exams, uint8_t max_timeslot);

/**
 * Computes all available timeslots, knowing all those which
 * have already been scheduled and the possibilities of that exam.
 *
 * @param exam_ The exam to schedule.
 * @param exams An array of exams (struct array_exams).
 * @param max_timeslot Maximum timeslot
 * @return A bool array of real available timeslots.
 */
bool *set_possible_timeslot(exam *exam_, array_exams *exams,
                            uint8_t max_timeslot);

/**
 * Computes the inferior timeslot that can be used for the exam exam_,
 * following its dependencies. It means that exam_ cannot be scheduled
 * before the inferior timeslot, otherwise exam_ would be scheduled before
 * one of its dependencies.
 *
 * @param exam_ The exam to know the inferior timeslot.
 * @param exams An array of exams (struct array_exams).
 * @return The inferior timeslot that can be used according to the dependencies.
 */
uint8_t compute_inf_timeslot(exam *exam_, array_exams *exams);

/**
 * Computes the superior timeslot that can be used for the exam exam_,
 * following dependencies to which it belongs. It means that exam_ cannot be
 * scheduled after the superior timeslot, otherwise exam_ would be scheduled
 * after an exam having this (exam_) as a dependency.
 *
 * @param exam_ The exam to know the superior timeslot.
 * @param exams An array of exams (struct array_exams).
 * @return The superior timeslot that can be used according to the dependencies.
 */
uint8_t compute_sup_timeslot(exam *exam_, array_exams *exams,
                             uint8_t max_timeslot);

/**
 * Try to set a correct timeslot to all exams and then assign them a room.
 * Correct means that any students/teachers doesn't have two exams scheduled
 * in the same period. Same thing for the room, it must be a room compatible
 * for the exam (with the correct room_type) and with enough capacity.
 *
 * @param  exams An array of exams (struct array_exams).
 * @param  rooms An 3-dimensional array of rooms. The first given indice is
 *               the faculty of the room. The second indice is the type of
 *               the room (struct matrix_rooms).
 * @param  faculty_size The number of different faculties.
 * @param  max_room_type Maximum number of room type.
 * @param  max_timeslot Maximum available timeslots.
 * @return true if a correct assignement is found, false otherwise.
 *         The algorithm also assign a timeslot and a room to all exams if
 *         true is returned.
 */
bool color_graph_backtrack(array_exams *exams, matrix_rooms *rooms,
                           uint8_t faculty_size, uint8_t max_room_type,
                           uint8_t max_timeslot);

#endif /*GRAPH_HEURISTICS_H_*/

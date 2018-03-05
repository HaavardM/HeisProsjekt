#ifndef STATE_AT_FLOOR_H
#define STATE_AT_FLOOR_H
#include "fsm.h"

/** State entry
 *  @param state_data_p Current system state
 *  @return Next state
 */
fsm_state_e state_at_floor_entry(const state_data_t* state_data_p);

/** State do 
 *  @param state_data_p Current system state
 *  @return Next state
 */
fsm_state_e state_at_floor_do(const state_data_t* state_data_p);

#endif

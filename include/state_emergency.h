#ifndef STATE_EMERGENCY_H
#define STATE_EMERGENCY_H 
#include "fsm.h"

/** State entry
 *  @param state_data_p Current system state
 *  @return Next state
 */
fsm_state_e state_emergency_entry(const state_data_t* state_data_p);

/** State do 
 *  @param state_data_p Current system state
 *  @return Next state
 */
fsm_state_e state_emergency_do(const state_data_t* state_data_p);

#endif

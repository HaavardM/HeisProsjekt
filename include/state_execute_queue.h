#ifndef STATE_EXECUTE_QUEUE_H
#define STATE_EXECUTE_QUEUE_H 
#include "fsm.h"

/** State entry
 *  @param state_data_p Current system state
 *  @return Next state
 */
fsm_state_e state_execute_queue_entry(const state_data_t* state_data_p);

/** State do 
 *  @param state_data_p Current system state
 *  @return Next state
 */
fsm_state_e state_execute_queue_do(const state_data_t* state_data_p);

#endif

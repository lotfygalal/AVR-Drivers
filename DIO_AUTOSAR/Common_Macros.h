#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_

											/****************** COMMON_MACROS   ********************/
#define SET_BIT(REG , BIT)  ( (REG)|=(1<<(BIT)))
#define GET_BIT(REG , BIT)   (( (REG)>>(BIT) ) &0x01)
#define CLEAR_BIT(REG , BIT)   (REG &= ~(1<<(BIT)))
#define TOGGLE_BIT(REG , BIT)   (REG ^= (1<<(BIT)))
#define ROL(REG , NUM)      ( REG = (REG << (NUM))|(REG >> (8-(NUM)) ) )
#define ROR(REG , NUM)      ( REG = (REG >> (NUM))|(REG << (8-(NUM)) ) )
#define IS_BIT_SET(REG , BIT)   ( ( (REG)>>(BIT) )&1 )
#define IS_BIT_CLEAR(REG , BIT)  ( !( ( (REG)>>(BIT) ) &1) )

#endif /* COMMON_MACROS_H_ */

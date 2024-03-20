


#ifndef TMR0_INTERFACE_H_
#define TMR0_INTERFACE_H_

/*option for tmr0 mode
1-TMR0_NORMAL_MODE
2-TMR0_CTC_MODE
*/
#define TMR0_MODE	TMR0_CTC_MODE


#define TMR0_NORMAL_OVER_FLOW	 0
#define TMR0_CTC_COMPARE_MATCH	 1


void TMR0_voidInit	(void);
void TMR0_voidStart	(void);
void TMR0_voidStop	(void);
void TMR0_voidSetCallBack(void (*copy_pFunAction)(void),u8 copy_u8InterruptSource);
void TMR0_voidSetDelay_ms_usingCTC(u16 copy_u16Delay_ms);




#endif /* TMR0_INTERFACE_H_ */
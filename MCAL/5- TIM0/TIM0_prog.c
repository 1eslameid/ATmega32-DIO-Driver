void TIM0_voidInit(void)
/* INITIALIZATION

- SElECT PRESCALLER
- SELECT MODE SET
- CLEAR BIT 4 & 5

- DISABLE OVERFLOW INTERRUPTS -----> طالما عندك int --> ENABLE FUN & DIS FUN
- DISABLE ON COMPARE MATCH INTERRUPTS --> طالما عندك int --> ENABLE FUN & DIS FUN

- CLEAR OVERFLOW FLAG
- CLEAR ON COMPARE MATCH INTERRUPTS
- CLEAR TCNT0
- CLEAR OCR 
*/


//NORMAL MODE
void TIM0_voidEnableOVInterrupt(void);
// enable the intr ofOver flow

void TIM0_voidDisableOVInterrupt(void);
// disable the intr ofOver flow

void TIM0_voidSetOVReg(u8 u8OVRegValue);
// TO SET THE OVERFLOW REGISTER (TCNT0) WITH SP

void TIM0_voidReadOVReg(void);
// TO READ THE OVERFLOW REGISTER (TCNT0)

pf FunctionAddress;

void TIM0_voidOVSetCallBack(pf OVFunctionAddress);
// to set the call back fun ofOverflow



// for ofOverflow
void __vector_11 (void) __attribute__ ((signal, used));
void __vector_11 (void)
{
    // FunctionAddress();
}
// to set the callback finction ofOverflow


/****************************CTC MODE**********************************/
void CTC_voidEnableOVInterrupt(void);
// enable the intr ofOver flow

void CTC_voidDisableOVInterrupt(void);
// disable the intr ofOver flow

void CTC_voidSetOVReg(u8 u8OVRegValue);
// TO SET THE OVERFLOW REGISTER (TCNT0) WITH SP

void CTC_voidReadOVReg(void);
// TO READ THE OVERFLOW REGISTER (TCNT0)

pf FunctionAddress2;

void CTC_voidOVSetCallBack(pf OVFunctionAddress);
// to set the call back fun ofOverflow
// for on compare match
void __vector_10 (void) __attribute__ ((signal, used));
void __vector_10 (void)
{
    // FunctionAddress();
}
// to set the callback finction ofOverflow




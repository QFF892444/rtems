/*  dmv170.h
 *
 *  This include file contains information pertaining to the DMV170.
 *
 *  NOTE:  Other than where absolutely required, this version currently 
 *         supports only the peripherals and bits used by the basic board 
 *         support package. This includes at least significant pieces of 
 *         the following items:
 *
 *           + UART Channels A and B
 *
 *  COPYRIGHT (c) 1989-1997.
 *  On-Line Applications Research Corporation (OAR).
 *  Copyright assigned to U.S. Government, 1994.
 *
 *  The license and distribution terms for this file may in
 *  the file LICENSE in this distribution or at
 *  http://www.OARcorp.com/rtems/license.html.
 *
 *  $Id$
 */
 
#ifndef _INCLUDE_DMV170_h
#define _INCLUDE_DMV170_h


/*
 *  DY-4 is out of their mind and uses a non-standard clock.
 */

#undef  MC68681_BAUD_RATE_MASK_9600
#define MC68681_BAUD_RATE_MASK_9600

#define DMV17x_MC68681_BAUD_RATE_MASK_9600

#if 0
#define MC68681_OFFSET_MULTIPLIER 8
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Note:  Move address defs to the linker files.                            */
#define  DMV170_RTC_ADDRESS   0xf2c00000 /* Real Time clock Base Address*/
#define  DUART_ADDR	0xf2800000  /* base address of the DUART(68681)     */
#define  SCC_ADDR       0xfb000000  /* base address for the SCC (85C30)     */ 

#define DMV170_LOCAL_CONTROL_STATUS_REG                   0xf2400000
#define DMV170_TIMER0_COUNT_INTERVAL_REG                  0xf2400008
#define DMV170_TIMER1_COUNT_INTERVAL_REG                  0xf2400010
#define DMV170_TIMER2_COUNT_INTERVAL_REG                  0xf2400018
#define DMV170_TIMER_CONTROL_REG                          0xf2400020
#define DMV170_CARD_RESORCE_REG                           0xf2400040


#define DMV170_WRITE( reg,data) \
   *((volatile rtems_unsigned16 *)(reg)) = (data)

#define DMV170_READ( reg, data ) \
   (data) = *((volatile rtems_unsigned16 *)(reg))

/*
 *  The following defines the bits in the Local Control and Status Register.
 */
#define DMV170_IPLx_MASK                                  0x0007
#define DMV170_MAXPACK_SENSE_MASK                         0x0008
#define DMV170_MAXPACK_NOT_INSTALLED                      0x0008
#define DMV170_MAXPACK_INSTALLED                          0x0000

#define DMV170_MAXPACK_RESET_MASK                         0x0010
#define DMV170_MAXPACK_RESET_NEGATE                       0x0010
#define DMV170_MAXPACK_RESET_ASSERT                       0x0000
#define DMV170_EEPROM_READ_WRITE_MASK                     0x0020
#define DMV170_EEPROM_READ                                0x0020
#define DMV170_EEPROM_WRITE                               0x0000
#define DMV170_EEPROM_CLOCK_CTRL_MASK                     0x0040
#define DMV170_EEPROM_CLOCK_ASSERT                        0x0040
#define DMV170_EEPROM_CLOCK_NEGATE                        0x0000
#define DMV170_EEPROM_DATA_MASK                           0x0080
#define DMV170_EEPROM_DATA_HIGH                           0x0080
#define DMV170_EEPROM_DATA_LOW                            0x0000

/* Bits 8:10 68040 Transfer Modifer Codes represent the Transfer Modifier to be used on MAXPack Accesses. */
/* Bit  11 68040 Transfer Type (TT) 0:TT are both low 1:TT are both high                                  */

#define DMV170_USER_LINK0_STATUS_MASK                     0x1000
#define DMV170_USER_LINK0_OPEN                            0x1000
#define DMV170_USER_LINK0_INSTALLED                       0x0000
#define DMV170_LOWER_STATUS_LED_CONTROL_MASK              0x2000
#define DMV170_LOWER_STATUS_LED_IS_OFF                    0x2000
#define DMV170_LOWER_STATUS_LED_IS_ON                     0x0000
#ifdef DMV176                                             
       /* The following are not available for the DMV171 */
#define DMV170_RAM_TYPE_MASK                              0x4000
#define DMV170_RAM_TYPE_IS_DRAM                           0x4000
#define DMV170_RAM_TYPE_IS_SRAM                           0x0000
#define DMV170_IACK_VECTOR_AUTOVECTOR_MASK                0x8000
#define DMV170_IACK_VECTOR_AUTOVECTOR_IS_VECTOR           0x8000
#define DMV170_IACK_VECTOR_AUTOVECTOR_IS_NOT_VECTOR       0x0000
#endif
 
/*
 *  The following defines the bits in the Timer Control Register.
 */
#define DMV170_TIMER0_ENABLE_MASK                         0x0001
#define DMV170_TIMER0_IS_ENABLED                          0x0001
#define DMV170_TIMER0_IS_DISABLED                         0x0000
#define DMV170_TIMER1_ENABLE_MASK                         0x0002
#define DMV170_TIMER1_IS_ENABLED                          0x0002
#define DMV170_TIMER1_IS_DISABLED                         0x0000
#define DMV170_TIMER2_ENABLE_MASK                         0x0004
#define DMV170_TIMER2_IS_ENABLED                          0x0004
#define DMV170_TIMER2_IS_DISABLED                         0x0000
#define DMV170_TIMER1_CLOCK_MASK                          0x0008
#define DMV170_TIMER1_CLOCK_AT_TIMER0                     0x0008
#define DMV170_TIMER1_CLOCK_AT_1MHZ                       0x0000

#define DMV170_TIMER2_CLOCK_MASK                          0x0010
#define DMV170_TIMER2_CLOCK_AT_TIMER0                     0x0010
#define DMV170_TIMER2_CLOCK_AT_1MHZ                       0x0000
#define DMV170_TIMER0_INTERRUPT_MASK                      0x0020
#define DMV170_TIMER0_INTERRUPT_ENABLE                    0x0020
#define DMV170_TIMER0_INTERRUPT_CLEAR                     0x0000
#define DMV170_TIMER1_INTERRUPT_MASK                      0x0040
#define DMV170_TIMER1_INTERRUPT_ENABLE                    0x0040
#define DMV170_TIMER1_INTERRUPT_CLEAR                     0x0000
#define DMV170_TIMER2_INTERRUPT_MASK                      0x0080
#define DMV170_TIMER2_INTERRUPT_ENABLE                    0x0080
#define DMV170_TIMER2_INTERRUPT_CLEAR                     0x0000



/* The Following definethe bits for the Card Resource Register      */
#define DMV170_DUART_INTERRUPT_MASK    0x0001  /* DUART Interrupt Sense Bit  */
#define DMV170_DUART_INTERRUPT_NEGATE  0x0001
#define DMV170_DUART_INTERRUPT_ASSERT  0x0000
#define DMV170_SONIC_INTERRUPT_MASK    0x0002  /* SONIC Interrupt Sense Bit  */
#define DMV170_SONIC_INTERRUPT_NEGATE  0x0002
#define DMV170_SONIC_INTERRUPT_ASSERT  0x0000
#define DMV170_SCSI_INTERRUPT_MASK     0x0004  /* SCSI Interrupt Sense Bit   */
#define DMV170_SCSI_INTERRUPT_NEGATE   0x0004
#define DMV170_SCSI_INTERRUPT_ASSERT   0x0000
#define DMV170_SCC_INTERRUPT_MASK      0x0008  /* SCC Interrupt Sense Bit    */
#define DMV170_SCC_INTERRUPT_NEGATE    0x0008
#define DMV170_SCC_INTERRUPT_ASSERT    0x0000
#define DMV170_SNOOP_ENABLE_MASK       0x0010  /* CPU Snoop Enable Bit       */
#define DMV170_SNOOP_DISABLE           0x0010
#define DMV170_SNOOP_ENABLE            0x0000
#define DMV170_SONIC_RESET_MASK        0x0020  /* SONIC RESET Control        */
#define DMV170_SONIC_RESET_CLEAR       0x0020
#define DMV170_SONIC_RESET_HOLD        0x0000
#define DMV170_NV64_WE_MASK            0x0040  /* 64-bit Non-Volital Memory  */
#define DMV170_NV64_WRITE_ENABLE       0x0040  /* Write Enable               */
#define DMV170_NV64_WRITE_DISABLE      0x0000
#define DMV170_BOOT_NV16_MASK          0x0080  /* BOOT Device Type           */
#define DMV170_BOOT_64_BIT             0x0080
#define DMV170_BOOT_16_BIT             0x0000
#define DMV170_DUART_INST_MASK         0x0100  /* DUART Sense Bit            */
#define DMV170_DUART_INSTALLED         0x0100
#define DMV170_DUART_NOT_INSTALLED     0x0000
#define DMV170_SONIC_INST_MASK         0x0200  /* SONIC Sense Bit            */
#define DMV170_SONIC_INSTALLED         0x0200
#define DMV170_SONIC_NOT_INSTALLED     0x0000
#define DMV170_16M_NV64_MASK           0x0400  /* 16 Mb of 64bit Flash Sense */
#define DMV170_16Mb_FLASH_INSTALLED    0x0400
#define DMV170_8Mb_FLASH_INSTALLED     0x0000
#define DMV170_SCC_INST_MASK           0x0800  /* SCC Sense Bit              */
#define DMV170_SCC_INSTALLED           0x0800
#define DMV170_SCC_NOT_INSTALLED       0x0000
#define DMV170_RTC_INST_MASK           0x1000  /* RTC Sense Bit              */
#define DMV170_RTC_INSTALLED           0x1000
#define DMV170_RTC_NOT_INSTALLED       0x0000
#define DMV170_NV64_INST_MASK          0x2000  /* 64bit Non-Volital Mem Sense*/

#define DMV170_64_BIT_NON_VOLITAL_MEM_INSTALLED           0x2000
#define DMV170_64_BIT_NON_VOLITAL_MEM_NOT_INSTALLED       0x0000


/*
 * DUART Baud Rate Definations.
 */
#define DMV170_DUART_9621     MC68681_BAUD_RATE_MASK_600 /* close to 9600 */  

#define DMV170_RTC_FREQUENCY             0x0000


/*
 * CPU General Purpose Interrupt definations (PPC_IRQ_EXTERNAL).
 * Note: For the interrupt level read the lower 3 bits of the
 *       Local Control and Status Register.
 */
#define DMV170_IRQ_FIRST                       ( PPC_IRQ_LAST +  1 )

#define DMV170_LIRQ0                           ( DMV170_IRQ_FIRST + 0 )
#define DMV170_LIRQ1                           ( DMV170_IRQ_FIRST + 1 )
#define DMV170_LIRQ2                           ( DMV170_IRQ_FIRST + 2 )
#define DMV170_LIRQ3                           ( DMV170_IRQ_FIRST + 3 )
#define DMV170_LIRQ4                           ( DMV170_IRQ_FIRST + 4 )
#define DMV170_LIRQ5                           ( DMV170_IRQ_FIRST + 5 )

#define MAX_BOARD_IRQS                         DMV170_LIRQ5
#ifdef __cplusplus
}
#endif
 
#endif /* !_INCLUDE_DMV170_h */
/* end of include file */








## Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([rtems-c-src-lib-libbsp-sh-gensh2],[_RTEMS_VERSION],[https://devel.rtems.org/newticket])
RTEMS_TOP(../../../../../..)
RTEMS_SOURCE_TOP
RTEMS_BUILD_TOP
RTEMS_BSP_LINKCMDS

RTEMS_CANONICAL_TARGET_CPU
AM_INIT_AUTOMAKE([no-define nostdinc foreign 1.12.2])
RTEMS_BSP_CONFIGURE


## bsp-specific options
AC_DEFINE(CPU_CLOCK_RATE_HZ, 29491200, [cpu clock rate in HZ])

RTEMS_BSPOPTS_SET([START_HW_INIT],[*],[])
RTEMS_BSPOPTS_HELP([START_HW_INIT],
[If defined, selects whether 'early_hw_init()' is called from 'start.S';
 'bsp_hw_init()' is always called from 'bspstart.c'])

RTEMS_BSPOPTS_SET([STANDALONE_EVB],[*],[])
RTEMS_BSPOPTS_HELP([STANDALONE_EVB],
[If defined, compiles code to jump-start from FLASH, without a monitor])

RTEMS_BSP_CLEANUP_OPTIONS

# Explicitly list all Makefiles here
AC_CONFIG_FILES([Makefile])
AC_OUTPUT

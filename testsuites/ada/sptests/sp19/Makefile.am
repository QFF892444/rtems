include $(RTEMS_ROOT)/make/custom/@RTEMS_BSP@.cfg
include $(top_srcdir)/../automake/compile.am

include $(top_srcdir)/ada.am

AM_ADAFLAGS += -I.

noinst_PROGRAMS = ada_sp19
ada_sp19_SOURCES = sp19.adb sptest.adb config.h sptest.ads
ada_sp19_SOURCES += init.c

CLEANFILES += sptest.adb

ada_sp19$(EXEEXT): sp19.adb sptest.adb sptest.ads init.$(OBJEXT)
	$(GNATCOMPILE) -margs -a $< -o $@

scndir = $(rtems_ada_testsdir)
dist_scn_DATA = ada_sp19.scn


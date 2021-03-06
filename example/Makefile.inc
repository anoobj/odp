include $(top_srcdir)/Makefile.inc

TESTS_ENVIRONMENT = EXEEXT=${EXEEXT}

LDADD = $(LIB)/libodp-linux.la $(LIB)/libodphelper.la

# Do not link to DPDK twice in case of dynamic linking with ODP
if STATIC_APPS
LDADD += $(DPDK_LIBS_LT_STATIC)
else
LDADD += $(DPDK_LIBS_LT)
endif

AM_CFLAGS = \
	-I$(srcdir) \
	-I$(top_srcdir)/example \
	$(ODP_INCLUDES) \
	$(HELPER_INCLUDES)

if STATIC_APPS
AM_LDFLAGS = -L$(LIB) -static
else
AM_LDFLAGS =
endif

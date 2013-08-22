############################################################################
# apps/interpreters/lua/Makefile
#
#   Copyright (C) 2012 Michael Smith. All rights reserved.
#            Gregory Nutt <gnutt@nuttx.org>
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in
#    the documentation and/or other materials provided with the
#    distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
# FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
# COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
# OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
# AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
# ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
############################################################################

-include $(TOPDIR)/.config
-include $(TOPDIR)/Make.defs
include $(APPDIR)/Make.defs

# LUA library

LUASRC		= lua-5.2.0/src

CFLAGS		+= ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(BUILDDIR)/$(FICL_SUBDIR) $(BUILDDIR)/src}

ASRCS		=
CSRCS		= $(LUASRC)/lapi.c $(LUASRC)/lcode.c $(LUASRC)/lctype.c \
		  $(LUASRC)/ldebug.c $(LUASRC)/ldo.c $(LUASRC)/ldump.c \
		  $(LUASRC)/lfunc.c $(LUASRC)/lgc.c $(LUASRC)/llex.c \
		  $(LUASRC)/lmem.c $(LUASRC)/lobject.c $(LUASRC)/lopcodes.c \
		  $(LUASRC)/lparser.c $(LUASRC)/lstate.c $(LUASRC)/lstring.c \
		  $(LUASRC)/ltable.c $(LUASRC)/ltm.c $(LUASRC)/lundump.c \
		  $(LUASRC)/lvm.c $(LUASRC)/lzio.c $(LUASRC)/linit.c \
		  $(LUASRC)/lauxlib.c $(LUASRC)/loadlib.c \
		  nuttx_lua_compat.c

CSRCS		+= $(LUASRC)/lbaselib.c
CSRCS		+= $(LUASRC)/lbitlib.c
CSRCS		+= $(LUASRC)/lcorolib.c
CSRCS		+= $(LUASRC)/ldblib.c
CSRCS		+= $(LUASRC)/liolib.c
CSRCS		+= $(LUASRC)/lmathlib.c
CSRCS		+= $(LUASRC)/loslib.c
CSRCS		+= $(LUASRC)/lstrlib.c
CSRCS		+= $(LUASRC)/ltablib.c

AOBJS		= $(ASRCS:.S=$(OBJEXT))
COBJS		= $(CSRCS:.c=$(OBJEXT))

SRCS		= $(ASRCS) $(CSRCS)
OBJS		= $(AOBJS) $(COBJS)

ifeq ($(WINTOOL),y)
  BIN		= "${shell cygpath -w  $(APPDIR)/libapps$(LIBEXT)}"
else
  BIN		= "$(APPDIR)/libapps$(LIBEXT)"
endif

ROOTDEPPATH	= --dep-path .
VPATH		= 

# Build targets

all:	.built
.PHONY: context .depend depend clean distclean

$(AOBJS): %$(OBJEXT): %.S
	$(call ASSEMBLE, $<, $@)

$(COBJS): %$(OBJEXT): %.c
	$(call COMPILE, $<, $@)

.built: $(OBJS)
	$(call ARCHIVE, $(BIN), $(OBJS))
	$(Q) touch .built
	

context:

.depend: Makefile $(SRCS)
	@$(MKDEP) $(ROOTDEPPATH) \
	  $(CC) -- $(CFLAGS) -- $(SRCS) >Make.dep
	@touch $@

depend: .depend

clean:
	@rm -f *.o *~ .*.swp .built
	$(call CLEAN)

distclean: clean
	@rm -f Make.dep .depend

-include Make.dep

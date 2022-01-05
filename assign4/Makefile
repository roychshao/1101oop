#
#  Sample Makefile for C++ programs 
#  Designed for the OOP class
#  by Tsai-Yen Li (li@cs.nccu.edu.tw) 08/08/96
#

# the name of this package. 
# The library and tar file, if any, will be named after it.
PACKAGE  = Vector
# The executable program
TARGET   = vector
# The C++ source programs (.cc) [multiple files]
SOURCES  = Vector AnsiPrint
# The C++ source program for testing your implementation
TEST     = Main

O_DIR    = O_$(HOSTTYPE)
SYSDIR   = /usr/local
CLASSDIR = $(SYSDIR)/class/oop
BASEDIR  = .
INCDIR   = ../Canvas -I$(BASEDIR)/include -I$(CLASSDIR)/include -I/usr/openwin/include -I/usr/lib/g++-include
LIBDIR   =  -L../Canvas -L/usr/openwin/lib -L$(CLASSDIR)/lib
LIBS     = $(LIBDIR) -lcanvas_$(HOSTTYPE) -lcurses -ltermcap -lX11 -lm -lc 

# You may not need to modify anything below

CXX      = g++
CXXFLAGS = -g -Wall -I$(INCDIR) #-D__STDC__ 
TARG     = $(TARGET)_$(HOSTTYPE)
LIB      = lib$(PACKAGE)_$(HOSTTYPE).a

SRCS     = ${SOURCES:%=%.cc}
OBJS     = ${SRCS:%.cc=$(O_DIR)/%.o}
HEADERS  = ${SRCS:%.cc=%.h} #Canvas.h keys.h
TESTSRC  = ${TEST:%=%.cc}
TESTOBJ  = ${TESTSRC:%.cc=$(O_DIR)/%.o}
#MAKEDEP  = $(CLASSDIR)/bin/makedepend
MAKEDEP  = makedepend

$(TARG) : $(O_DIR) $(OBJS) $(TESTOBJ) 
	$(CXX) -o $@ $(CXXFLAGS) $(OBJS) $(TESTOBJ) $(LIBS) 

$(O_DIR) :
	mkdir $@

lib : $(O_DIR) $(LIB)
	@echo $@ Built

$(LIB) : $(OBJS)
	rm -f $(LIB)
	ar cr $@ $(OBJS)
	ranlib $@

$(O_DIR)/%.o: %.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean: 
	rm -f $(OBJS) $(TESTOBJ) $(TARG) core* *~ Makefile.bak 
	rmdir $(O_DIR)

tags: 
	etags $(SRCS) $(HEADERS)

ztar:
	/usr/local/bin/tar zcvf $(PACKAGE).tgz Makefile $(SRCS) $(HEADERS) $(TESTSRC) input.dat assign6.txt

ci:
	ci -l Makefile $(SRCS) $(HEADERS) $(TESTSRC) 

depend : 
	$(MAKEDEP) -p$(O_DIR)/ -I$(INCDIR) $(SRCS) $(TESTSRC)

# DO NOT DELETE THIS LINE -- make depend depends on it.

O_i386-linux/AnsiPrint.o: /usr/include/stdlib.h /usr/include/features.h
O_i386-linux/AnsiPrint.o: /usr/include/sys/cdefs.h /usr/include/errno.h
O_i386-linux/AnsiPrint.o: /usr/include/linux/errno.h /usr/include/alloca.h
O_i386-linux/AnsiPrint.o: /usr/lib/g++-include/iostream.h
O_i386-linux/AnsiPrint.o: /usr/lib/g++-include/streambuf.h
O_i386-linux/AnsiPrint.o: /usr/include/libio.h /usr/include/_G_config.h
O_i386-linux/AnsiPrint.o: AnsiPrint.h /usr/lib/g++-include/bool.h
O_i386-linux/Main.o: /usr/include/stdio.h /usr/include/libio.h
O_i386-linux/Main.o: /usr/include/_G_config.h /usr/include/string.h
O_i386-linux/Main.o: /usr/include/features.h /usr/include/sys/cdefs.h
O_i386-linux/Main.o: /usr/lib/g++-include/iostream.h
O_i386-linux/Main.o: /usr/lib/g++-include/streambuf.h
O_i386-linux/Main.o: /usr/lib/g++-include/bool.h AnsiPrint.h

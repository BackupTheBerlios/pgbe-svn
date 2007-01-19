#
# Gererated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add custumized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=g77

# Include project Makefile
include mve-Makefile.mk

# Object Files
OBJECTFILES= \
	build/Debug/GNU-Linux-x86/system.o \
	build/Debug/GNU-Linux-x86/video.o \
	build/Debug/GNU-Linux-x86/cart.o \
	build/Debug/GNU-Linux-x86/cpu.o \
	build/Debug/GNU-Linux-x86/main.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=\
	/usr/lib/libSDL.so

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS} dist/Debug/GNU-Linux-x86/mve

dist/Debug/GNU-Linux-x86/mve: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/GNU-Linux-x86
	${LINK.cc} -o dist/Debug/GNU-Linux-x86/mve ${OBJECTFILES} ${LDLIBSOPTIONS} 

build/Debug/GNU-Linux-x86/system.o: system.cpp 
	${MKDIR} -p build/Debug/GNU-Linux-x86
	$(COMPILE.cc) -g -o build/Debug/GNU-Linux-x86/system.o system.cpp

build/Debug/GNU-Linux-x86/video.o: video.cpp 
	${MKDIR} -p build/Debug/GNU-Linux-x86
	$(COMPILE.cc) -g -o build/Debug/GNU-Linux-x86/video.o video.cpp

build/Debug/GNU-Linux-x86/cart.o: cart.cpp 
	${MKDIR} -p build/Debug/GNU-Linux-x86
	$(COMPILE.cc) -g -o build/Debug/GNU-Linux-x86/cart.o cart.cpp

build/Debug/GNU-Linux-x86/cpu.o: cpu.cpp 
	${MKDIR} -p build/Debug/GNU-Linux-x86
	$(COMPILE.cc) -g -o build/Debug/GNU-Linux-x86/cpu.o cpu.cpp

build/Debug/GNU-Linux-x86/main.o: main.cpp 
	${MKDIR} -p build/Debug/GNU-Linux-x86
	$(COMPILE.cc) -g -o build/Debug/GNU-Linux-x86/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Debug
	${RM} dist/Debug/GNU-Linux-x86/mve

# Subprojects
.clean-subprojects:

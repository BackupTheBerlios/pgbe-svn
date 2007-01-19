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
	build/Release/GNU-Linux-x86/system.o \
	build/Release/GNU-Linux-x86/video.o \
	build/Release/GNU-Linux-x86/cart.o \
	build/Release/GNU-Linux-x86/cpu.o \
	build/Release/GNU-Linux-x86/main.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS} dist/Release/GNU-Linux-x86/mve

dist/Release/GNU-Linux-x86/mve: ${OBJECTFILES}
	${MKDIR} -p dist/Release/GNU-Linux-x86
	${LINK.cc} -o dist/Release/GNU-Linux-x86/mve ${OBJECTFILES} ${LDLIBSOPTIONS} 

build/Release/GNU-Linux-x86/system.o: system.cpp 
	${MKDIR} -p build/Release/GNU-Linux-x86
	$(COMPILE.cc) -O2 -o build/Release/GNU-Linux-x86/system.o system.cpp

build/Release/GNU-Linux-x86/video.o: video.cpp 
	${MKDIR} -p build/Release/GNU-Linux-x86
	$(COMPILE.cc) -O2 -o build/Release/GNU-Linux-x86/video.o video.cpp

build/Release/GNU-Linux-x86/cart.o: cart.cpp 
	${MKDIR} -p build/Release/GNU-Linux-x86
	$(COMPILE.cc) -O2 -o build/Release/GNU-Linux-x86/cart.o cart.cpp

build/Release/GNU-Linux-x86/cpu.o: cpu.cpp 
	${MKDIR} -p build/Release/GNU-Linux-x86
	$(COMPILE.cc) -O2 -o build/Release/GNU-Linux-x86/cpu.o cpu.cpp

build/Release/GNU-Linux-x86/main.o: main.cpp 
	${MKDIR} -p build/Release/GNU-Linux-x86
	$(COMPILE.cc) -O2 -o build/Release/GNU-Linux-x86/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Release
	${RM} dist/Release/GNU-Linux-x86/mve

# Subprojects
.clean-subprojects:

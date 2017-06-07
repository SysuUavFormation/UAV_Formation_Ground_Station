# This makefile is used to build the static library of CVT project,
# it will output a libCVT.a file, this file is paired with CVT.hpp
# and all object file is in build folder.
#
# Created by Junxun Zhong in 2016.11.15

CXX = g++
AR = ar
CFLAGS = -O3
OBJDIR = build
OBJSCPP = CVT.o CVT_method.o CVT_shape.o
OBJSCC = voro++/voro++.o
TARGET = libCVT.a

$(TARGET) : $(OBJDIR) OBJS
	$(AR) -r $(TARGET) $(OBJDIR)/*.o

$(OBJDIR) :
	mkdir -p ./$@

OBJS : $(OBJSCPP) $(OBJSCC)

$(OBJSCPP) : %.o : %.cpp
	$(CXX) $(CFLAGS) -c $< -o $(OBJDIR)/$(notdir $@)

$(OBJSCC) : %.o : %.cc
	$(CXX) $(CFLAGS) -c $< -o $(OBJDIR)/$(notdir $@)

.PHONY : clean

clean : 
	-$(RM) $(TARGET) 
	-$(RM) $(OBJDIR) -r

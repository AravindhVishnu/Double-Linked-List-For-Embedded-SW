TARGET     = ExampleApplication

SRCDIR     = ./src
OBJDIR     = ./obj
BINDIR     = ./bin
INCDIR     = ./inc
LIBDIR     = ./lib
LIBINCDIR  = ./lib/inc

CC         = g++
CCFLAGS    = -g -std=c++17 -Wall -MMD -MP
LINK       = g++ -o 
LIBS       = -lm
COPY       = cp

SOURCES    = $(wildcard $(SRCDIR)/*.cpp)
INCLUDES   = $(wildcard $(INCDIR)/*.h) \
						$(wildcard $(LIBINCDIR)/*.h)
MYLIBS     = $(wildcard $(LIBDIR)/*.a)
OBJECTS    = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
DEPS       = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.d)

.PHONY : all
all: $(BINDIR)/$(TARGET)

$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LINK) $@ $^ $(MYLIBS) $(LIBS)
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(CC) $(CCFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"
	
-include $(DEPS)

RM = rm -f

.PHONY: clean
clean:
	@$(RM) $(OBJECTS)
	@$(RM) $(DEPS)
	@$(RM) $(BINDIR)/$(TARGET)
	@echo "Cleanup complete!"

.PHONY: rebuild
rebuild: clean all
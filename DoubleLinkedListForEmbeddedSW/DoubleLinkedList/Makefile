TARGET           = libDoubleLinkedList.a

SRCDIR           = ./src
OBJDIR           = ./obj
BINDIR           = ./bin
INCDIR           = ./inc
CLIENTLIBDIR     = ../ExampleApplication/lib
CLIENTLIBINCDIR  = ../ExampleApplication/lib/inc

CC         = g++
CCFLAGS    = -g -std=c++17 -Wall -MMD -MP
LINK       = ar -rcs
COPY       = cp

SOURCES    = $(wildcard $(SRCDIR)/*.cpp)
INCLUDES   = $(wildcard $(INCDIR)/*.h)
OBJECTS    = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
DEPS       = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.d)

.PHONY : all
all: $(BINDIR)/$(TARGET)

$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LINK) $@ $^
	@$(COPY) $(INCLUDES) $(CLIENTLIBINCDIR)
	@$(COPY) $(BINDIR)/$(TARGET) $(CLIENTLIBDIR)
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
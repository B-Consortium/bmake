# Installation directories following GNU conventions
prefix ?= /usr/local
exec_prefix = $(prefix)
bindir = $(exec_prefix)/bin
sbindir = $(exec_prefix)/sbin
datarootdir = $(prefix)/share
datadir = $(datarootdir)
includedir = $(prefix)/include
mandir = $(datarootdir)/man

BIN=bin
OBJ=obj
SRC=src

CC ?= gcc
CXX ?= g++
CFLAGS ?= -Wextra -Wall -O2
CXXFLAGS ?= -Wextra -Wall -O2

.PHONY: all install uninstall clean

BMAKE_SRCS := $(wildcard $(SRC)/*.c $(SRC)/*.cpp)
BMAKE_OBJS := $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(patsubst $(SRC)/%.cpp,$(OBJ)/%.o,$(BMAKE_SRCS)))

bmake: $(OBJ)/bmake.o $(BMAKE_OBJS) | $(BIN)
	$(CXX) $(CXXFLAGS) -o $(BIN)/$@ $^ -lcurl

all: bmake

$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ)/%.o: $(SRC)/%.cpp | $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(BIN):
	mkdir $(BIN)

$(OBJ):
	mkdir $(OBJ)

clean:
	rm -rf $(BIN)
	rm -rf $(OBJ)

install:
	install -d $(DESTDIR)$(mandir)/man6
	install -m644 bmake.6 $(DESTDIR)$(mandir)/man6 
	install -d $(DESTDIR)$(bindir)
	cd $(BIN) && install * $(DESTDIR)$(bindir)

uninstall:
	rm -f $(DESTDIR)$(bindir)/bmake;
	rm -f $(DESTDIR)$(mandir)/man6/bmake.6

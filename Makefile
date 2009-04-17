SRC=rag.cc
HEADERS=rag.hh
OBJ=$(SRC:.cc=.o)
TEST=rag
CXX=g++-4.3
CXXFLAGS=-W -Wall -O3
CPPFLAGS=-I../../../../
LD=$(CXX)
LDFLAGS=

all: $(TEST)

$(TEST): $(OBJ)
	$(LD) $(LDFLAGS) $(OBJ) -o $(TEST)

.cc.o:
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $<

clean:
	rm -f *.o *~

distclean: clean
	rm -f $(TEST)

rag.o: rag.cc rag.hh

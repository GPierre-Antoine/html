all: redo html clean


redo: 
	rm -f -- html


html:
	g++ -std=c++17 *.{cpp,h} -lstdc++fs -fmax-errors=1 -o html


clean: 
	rm -rf *.gch


html: 
	g++ -std=c++17 *.{cpp,h} -lstdc++fs -fmax-errors=1 -o html

redo:erase html
	

erase: 
	rm -f -- html

clean: 
	rm -rf *.gch target


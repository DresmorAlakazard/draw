cc = gcc
flags = -ansi -Wall -lm

objects = ./*.o
headers = ./*.h
sources = ./*.c

outputfile = draw

$(objects): $(headers) $(sources)
	$(cc) -c $(sources) $(flags)

install: $(objects)
	$(cc) $(objects) -o $(outputfile) $(flags)

clean:
	rm $(objects)
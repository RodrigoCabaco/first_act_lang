#executable name
exec = first.exe
#c sources
sources = $(wildcard src/*.c)
objects = $(sources:.c=.o)
flags = -g

$(exec): $(objects)
	gcc $(objects) $(flags) -o $(exec)

%.o: %.c include/%.h
	gcc -c $(flags) $< -o $@

#ONLY WORKS ON LINUX:

# clean:
# 	-rm *.exe
# 	-rm *.o
# 	-rm src/*.o

# install:
# 	make
# 	cp $(exec) /usr/bin/first


#WINDOWS:

install:
	make
	COPY $(exec) C:\Users\Rodrigo\

clean:
	del *.exe
	del *.o
	del src\*.o

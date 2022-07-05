application: staticlib
	gcc main_a2.c -lgaussian_staticlib -lm

staticlib:
	gcc gaussian_staticlib.c -c
	ar -crs libgaussian_staticlib.a gaussian_staticlib.o
	sudo cp gaussian_staticlib.h /usr/include
	sudo cp libgaussian_staticlib.a /usr/lib

#
# Auteur: C.-A. Brunet
# Date: 04 janvier 2024
# Modifie par : ...
# Date : ...
# Description: compilation de graphicus-01. Ce fichier fait partie de 
#	la distribution de Graphicus.
#

MATH = -lm


graphicus-01: graphicus-01.o tests.o canevas.o couche.o forme.o rectangle.o cercle.o carre.o vecteur.o
	g++ -o graphicus-01 graphicus-01.o tests.o canevas.o couche.o forme.o rectangle.o carre.o cercle.o vecteur.o $(MATH)
	rm  -f *.o

graphicus-01.o: graphicus-01.cpp canevas.h couche.h forme.h
	g++ -c graphicus-01.cpp $(MATH)

tests.o: tests.cpp tests.h canevas.h couche.h forme.h
	g++ -c tests.cpp $(MATH)

canevas.o: canevas.cpp canevas.h couche.h forme.h
	g++ -c canevas.cpp $(MATH)

couche.o: couche.cpp couche.h forme.h
	g++ -c couche.cpp $(MATH)

rectangle.o: rectangle.cpp rectangle.h forme.h
	g++ -c rectangle.cpp $(MATH)

cercle.o: cercle.cpp cercle.h forme.h
	g++ -c cercle.cpp $(MATH)

carre.o: carre.cpp carre.h forme.h
	g++ -c carre.cpp $(MATH)

forme.o: forme.cpp forme.h
	g++ -c forme.cpp $(MATH)

vecteur.o: vecteur.cpp vecteur.h
	g++ -c vecteur.cpp $(MATH)

clean:
	rm  -f *.o

run:
	./graphicus-01

tests_compile:
	g++ -c tests.cpp
	g++ -o tests tests.o
	rm -f *.o

run_tests: tests_compile
	make tests_compile
	./tests
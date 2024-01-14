#
# Auteur: C.-A. Brunet
# Date: 04 janvier 2024
# Modifie par : ...
# Date : ...
# Description: compilation de graphicus-01. Ce fichier fait partie de 
#	la distribution de Graphicus.
#

MATH = -lm





graphicus-01: graphicus-01.o canevas.o couche.o forme.o rectangle.o cercle.o carre.o vecteur.o
	g++ -o graphicus-01 graphicus-01.o canevas.o vecteur.o couche.o forme.o rectangle.o carre.o cercle.o $(MATH)

graphicus-01.o: graphicus-01.cpp
	g++ -c graphicus-01.cpp $(MATH)

canevas.o: canevas.cpp couche.o canevas.h
	g++ -c canevas.cpp $(MATH)

couche.o: couche.cpp forme.o couche.h vecteur.o
	g++ -c couche.cpp $(MATH)

vecteur.o: vecteur.cpp forme.o vecteur.h
	g++ -c vecteur.cpp $(MATH)

rectangle.o: rectangle.cpp rectangle.h forme.o
	g++ -c rectangle.cpp $(MATH)

cercle.o: cercle.cpp cercle.h forme.o
	g++ -c cercle.cpp $(MATH)

carre.o: carre.cpp forme.o carre.h
	g++ -c carre.cpp $(MATH)

forme.o: forme.cpp forme.h
	g++ -c forme.cpp $(MATH)


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
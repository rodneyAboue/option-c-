tp3 : main.o Personne.o Etudiant.o Enseignant.o
	g++ main.o Personne.o Etudiant.o Enseignant.o -o tp3

main.o : main.cpp Personne.h Etudiant.h Enseignant.h
	g++ -c main.cpp

Personne.o : Personne.cpp Personne.h
	g++ -c Personne.cpp

Etudiant.o : Etudiant.cpp Etudiant.h Personne.h
	g++ -c Etudiant.cpp

Enseignant.o : Enseignant.cpp Enseignant.h Personne.h
	g++ -c Enseignant.cpp





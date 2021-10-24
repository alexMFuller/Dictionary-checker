a.out: spell.o spellLib.o
	gcc *.o
spell.o: spell.h spell.c
	gcc -c spell.c
spellLib.o: spellLib.h spellLib.c
	gcc -c spellLib.c
clean:
	rm a.out
	rm *.o
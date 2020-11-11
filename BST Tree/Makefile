# compilatore da usare
CC		=  gcc
# aggiungo alcuni flags di compilazione
CCFLAGS	        += -std=c99 -Wall
# gli includes sono nella directory corrente
INCLUDES	= -I.
# librerie da linkare a tutti i files (es. -lm per le librerie matematiche)
LDFLAGS 	=
# altre librerie  (es. -L<path> -lmylib)
LIBS1		= -L ./ -lbst
# flags di ottimizzazione
OPTFLAGS	= # -O3
# flags di debugging
DBGFLAGS        = -g
FLAGS           = $(DBGFLAGS) $(OPTFLAGS)
ARFLAGS         = rvs
# aggiungere qui altri targets
TARGETS		= main

.PHONY: all clean
.SUFFIXES: .c .h

# regola per la generazione di un eseguibile partendo da un .c
%: %.c
	$(CC) $(CCFLAGS) $(INCLUDES) $(FLAGS) -o $@ $< $(LDFLAGS)

# regola per la generazione di un file oggetto partendo da un .c
%.o: %.c
	$(CC) $(CCFLAGS) $(INCLUDES) $(FLAGS) -c -o $@ $<



# root target
all		: $(TARGETS)

# personalizzazione della generazione dell'eseguibile sommada
# NOTA: $^ prende tutte le occorrenze della dependency list
#       $< prende solo la prima entry della dependency list
main: main.o libbst.a
	$(CC)  $(CFLAGS) $(INCLUDES) $(FLAGS) -o $@ $< $(LDFLAGS) $(LIBS1)

libbst.a: bst_lib.o bst.h
	$(AR) $(ARFLAGS) $@ $<

clean		:
	rm -f $(TARGETS) *.a *.o

CC=gcc
CC_OPTIONS=-std=c99
#EXEP1=pa1_part1
#EXEP2=pa1_part2
#EXEP3=pa1_part3
EXE=pa1_part1 pa1_part2 pa1_part3
OBJ=pa1_part1.o pa1_part2.o pa1_part3.o

all: $(EXE)
	@echo ""
	@echo "PA1 Built!"
	@echo ""

pa1_part1.o: pa1_part1.c
	$(CC) $(CC_OPTIONS) -c pa1_part1.c

pa1_part2.o: pa1_part2.c
	$(CC) $(CC_OPTIONS) -c pa1_part2.c

pa1_part3.o: pa1_part3.c
	$(CC) $(CC_OPTIONS) -c pa1_part3.c

pa1_part1: pa1_part1.o
	$(CC) pa1_part1.o -o pa1_part1

pa1_part2: pa1_part2.o
	$(CC) pa1_part2.o -o pa1_part2

pa1_part3: pa1_part3.o
	$(CC) pa1_part3.o -o pa1_part3

run:
	@make all

clean:
	rm -f $(EXE) $(OBJ)

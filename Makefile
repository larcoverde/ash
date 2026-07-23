all:
	@echo "run make install"

install:
	@gcc -o ash ash.c builtin.c

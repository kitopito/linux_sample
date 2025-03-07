
chdir:
	gcc chdir_test.c
	./a.out
	rm a.out

hello_million:
	gcc hello_million.c
	./a.out
	rm a.out

input:
	gcc input.c
	./a.out
	rm a.out

parricide:
	gcc parricide.c
	./a.out
	rm a.out

print_env:
	gcc print_env.c
	./a.out
	rm a.out

pthread_time:
	gcc pthread_time.c
	./a.out
	rm a.out

readline_prompt:
	gcc readline_prompt.c -lreadline
	a.out
	rm a.out

shell_owata:
	gcc shell_owata.c
	./a.out
	rm a.out
	
redirect:
	gcc redirect.c

clean:
	rm a.out
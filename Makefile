all:
	gcc -g src/student.c src/maze.c src/main.c -o out/exec
run:
	out/exec
clean:
	rm -f out/exec
clean_win:
	del out /f /q *.exe *.o
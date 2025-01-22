all:
	gcc src/student.c src/maze.c src/main.c -o out/exec
run:
	out/exec
clean:
	del out /f /q *.exe *.o

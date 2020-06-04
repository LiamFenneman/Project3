# Instructions for makefiles

1. Create a new file in the AVC_robot folder called "makefile".
2. Copy the code between the "START" and "END" comments. (don't include comments)
3. Replace "<username>" with the username of your computer. (found by looking at C:\Users\)
4. Repeat these steps for AVC_server.

### AVC_robot/makefile - START

``
USER = <username>
INCLUDE = -I C:\Users\$(USER)\Desktop\Project3\SFML\include
LIBS = -I C:\Users\$(USER)\Desktop\Project3\SFML\lib
robot.exe: robot.o
	g++ $(LIBS) -o robot robot.o -lsfml-window -lsfml-graphics -lsfml-system -lsfml-network
robot.o: robot.cpp
	g++ -c $(INCLUDE) robot.cpp
``

### AVC_server/makefile

``
USER = <username>
INCLUDE = -I C:\Users\$(USER)\Desktop\Project3\SFML\include
LIBS = -I C:\Users\$(USER)\Desktop\Project3\SFML\lib
server3.exe: server3.o
	g++ $(LIBS) -o server3 server3.o -lsfml-window -lsfml-graphics -lsfml-system -lsfml-network
server3.o: server3.cpp
	g++ -c $(INCLUDE) server3.cpp
``

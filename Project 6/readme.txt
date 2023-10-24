------------------------------------------------------------------------------------
Project 6: Render Your Scene With Primitives

Caleb Klinger, Kyungchan Im (Chris)
Grand Canyon University
CST - 435 : Computer Graphics Lecture & Lab
Ricardo Citro
October 8, 2023
------------------------------------------------------------------------------------
First make sure to install required packages and update

sudo apt update
sudo apt install freeglut3-dev libglu1-mesa-dev mesa-common-dev

Once packages are installed, in terminal cd to your working directory and run makefile

$ cd Path/To/Your/Directory

$ make run



------------------------------------------------------------------------------------
If make file fails run these commands below:

1) cd "/path/to/directory/"
2) g++ scene.cpp -o scene -lglut -lGLU -lGL
3) ./scene 



------------------------------------------------------------------------------------
Scene execution file folder: It contains the built OpenGL graphics, so if everything fails due to unexpected error, run this file.



------------------------------------------------------------------------------------
File Categories:
	1) Benchmark Word Documentation: This is a documentation for project description
	2) makefile - makefile to build OpenGL and run a program
	3) scene.cpp - OpenGL c++ programming file.
	4) scene.jpg - Original Picture
	5) scene - execution for OpenGL graphics
	6) Output screenshot - Final output screenshot from OpenGL window



------------------------------------------------------------------------------------
Github Link:
https://github.com/TrippingLettuce/Computer-Graphics/tree/main/Project%204
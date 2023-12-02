sudo apt-get update
sudo apt-get install libglfw3 libglfw3-dev libglew-dev
sudo apt-get install libassimp-dev


g++ main.cpp -o scene -lglfw -lGL -lGLEW -lSOIL -lassimp
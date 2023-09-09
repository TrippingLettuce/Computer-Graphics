Ensure you have g++ installed. You can check this by running:
g++ --version

Ensure you have the required libraries (GLUT, GLU, and GL) installed. On many Linux distributions, you can install them using the package manager. For example, on Ubuntu:
sudo apt-get install freeglut3-dev

Navigate to the directory containing your source code :
cd home/path

Compile the source code using the provided command:
g++ [name.cpp] -o [newName] -lglut -lGLU -lGL

After successful compilation, you can run the program with:
./[newName]

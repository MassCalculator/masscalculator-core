# Metal Mass Calculator

This package includes one library and one executable that opens a GUI for the app. All the calculations are done in the library and the GUI Executable is only a wrapper for user experience. The library can also be integrated in a nother app so that is the reason why it is seperated like this.

TODO: Explain CRTP pattern and why it is used here

TODO: Explain the GUI stuff

## Dependencies

Below listed packages are required and have to be installed/compiled before:

* CMake
  ```
  $ sudo apt install cmake
  ```

* OpenGL
  ```
  $ sudo apt install mesa-utils
  ```

* libQT5 (Need to check which modules are nessesary to install)
  ```
  $ sudo apt install libqt5*
  ```

* libDXFlib
  ```
  $ sudo apt install libdxflib-dev
  ```

* libLUAlib
  ```
  $ sudo apt-get install lua5.1-0
  $ sudo apt-get install liblua5.1-0-dev
  ```

* freeGlut - **Not used anymore**
  ```
  $ sudo apt install freeglut3-dev
  ```

* libGlui - **Not used anymore**
  ```
  $ git clone https://github.com/libglui/glui
  $ cd ${repo}
  $ mkdir build && cd build
  $ cmake ..
  $ make 
  $ sudo make install
  ```

* GoogleTest
  ```
  $ git clone https://github.com/google/googletest.git
  $ cd ${repo}
  $ mkdir build && cd build
  $ cmake ..
  $ make 
  $ sudo make install
  ```

* Eigen
  ```
  $ git clone https://github.com/eigenteam/eigen-git-mirror.git
  $ cd ${repo}
  $ mkdir build && cd build
  $ cmake ..
  $ make 
  $ sudo make install
  ```

## Get Sources

There is no current working version, the work is still in progress.

## Start the application

The application can be started only with one line, and this is the executable after build

```
./build/MassCalculatorGUI/MassCalculatorGUI
```

Everything then can be handled from the GUI.

TODO List:
Done: Doxyfile for doxygen documentation

Add headers that include all the headers (done)
Research for inheriting in the object class the two base classes for Shape and Material
Overload shift operator with the details of the object (Done, remaining only for ObjectInterface)
Create a struct for the material properties (Done)
Integrate lua for text properties in resources follder. Also do const string literals if the file is missing or cannot be read
Integrate libdxflib to read the dxf files
Find all physical and mechalincal properties that a material has, and finish the Aluminium class so nothing else is needed there \
then can cantinue to do the other classes.
Finish the base class with the common functions so you don't have to deal then with the base class Material

Continue with the class shapes

overload shift operator in enum

.hh files are header only to include all the headers
.hpp files have a .cpp file that is associated with

lambdas
constexpr
std::function
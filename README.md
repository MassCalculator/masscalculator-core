# Metal Mass Calculator

Jenkins CI pipeline: No jenkins server for the moment

Travis CI pipeline : master: [![Build Status](https://travis-ci.com/jimmyhalimi/MassCalculator.svg?token=SL6RqWzwyVSzbz3qVX6L&branch=master)](https://travis-ci.com/jimmyhalimi/MassCalculator) | devel: [![Build Status](https://travis-ci.com/jimmyhalimi/MassCalculator.svg?token=SL6RqWzwyVSzbz3qVX6L&branch=devel)](https://travis-ci.com/jimmyhalimi/MassCalculator) 



## What is MetalMassCalculator

This package includes one library and one executable that opens a GUI for the app. All the calculations are done in the library and the GUI Executable is only a wrapper for user experience. The library can also be integrated in a nother app so that is the reason why it is seperated like this.

## Additional info (Design pattern used and GUI lib)

### CRTP Design Pattern

The main reason of using the CRTP is learning the design pattern and its usage for Compile Time Polimorfism.
During my experience I had a lot to do with Run Time Polimorfism and Base classes with pure virtual functions, and while working I realised that dynamic_casting takes a lot of time and is quite dangerous to use ...

The CRTP fixes this scenario, and it is much safier because you get errors in compile time. Also it is much faster.

The CRTP consists in:

* inheriting from a template class,
* use the derived class itself as a template parameter of the base class.

This is what it looks like in code:

```cpp
template <typename T>
class Base
{
    ...
};
 
class Derived : public Base<Derived>
{
    ...
};
```

The purpose of doing this is using the derived class in the base class. From the perspective of the base object, the derived object is itself, but downcasted. Therefore the base class can access the derived class by static_casting itself into the derived class.

[Source: FluentCPP (CRTP Expplained in three episodes)](https://www.fluentcpp.com/2017/05/12/curiously-recurring-template-pattern/)


### GUI with QT5

For my GUI I wanted to go with CopperSpice (LINK), but I found it very hard to get started, therefore I used QT because of the large community. This is my first GUI app ever, so QT Developers, bare with me I know for sure I am doing lot of stuff wrong.

## Dependencies

Below listed packages are required and have to be installed/compiled before:

* CMake
  ```bash
  $ sudo apt install cmake
  ```

* OpenGL
  ```bash
  $ sudo apt install mesa-utils
  ```

* libQT5 (Need to check which modules are nessesary to install)
  ```bash
  $ sudo apt install qtbase5-dev
  ```

* libDXFlib
  ```bash
  $ sudo apt install libdxflib-dev
  ```

* libLUAlib
  ```bash
  $ sudo apt-get install lua5.1-0
  $ sudo apt-get install liblua5.1-0-dev
  ```

* freeGlut - **Not used anymore, switched to QT**
  ```bash
  $ sudo apt install freeglut3-dev
  ```

* libGlui - **Not used anymore, switched to QT**
  ```bash
  $ git clone https://github.com/libglui/glui
  $ cd ${repo}
  $ mkdir build && cd build
  $ cmake ..
  $ make 
  $ sudo make install
  ```

* GoogleTest
  ```bash
  $ git clone https://github.com/google/googletest.git
  $ cd ${repo}
  $ mkdir build && cd build
  $ cmake ..
  $ make 
  $ sudo make install
  ```

* Eigen **Currently not used**
  ```bash
  $ git clone https://github.com/eigenteam/eigen-git-mirror.git
  $ cd ${repo}
  $ mkdir build && cd build
  $ cmake ..
  $ make 
  $ sudo make install
  ```

## Build sources

There is no current working version, the work is still in progress.

## Docker container

TODO: Add build commands and launch commands for the Dockerfile

## Use the application

### CommandLine

The application can be used in command line

```bash
./build/MassCalculator/MassCalculator
```

### GUI

The application can be started only with one line, and this is the executable after build

```bash
./build/MassCalculatorGUI/MassCalculatorGUI
```

Everything then can be handled from the GUI.

## PPA and getting the app via apt

TODO: In progress

## TODO List

* **(done)** Doxyfile for doxygen documentation
* **(done)** Add headers that include all the headers
* **(todo)** Research for inheriting in the object class the two base classes for Shape and Material
* **(done)** Overload shift operator with the details of the object (Remaining only for ObjectInterface)
* **(done)** Create a struct for the material properties
* **(done)** Integrate lua for text properties in resources follder. Also do const string literals if the file is missing or cannot be read
* **(done)** Integrate libdxflib to read the dxf files
* **(done)** Find all physical and mechalincal properties that a material has, and finish the Aluminium class so nothing else is needed there then can cantinue to do the other classes.
* **(done)** Finish the base class with the common functions so you don't have to deal then with the base class material
* **(done)** Continue with the class shapes
* **(done)** overload shift operator in enum

Note: 
* .hh files are header only to include all the headers
* .hpp files have a .cpp file that is associated with

What I also want to have in the app:
* **(done)** lambdas
* **(done)** constexpr
* **(done)** std::function
* **(todo)** Posibility to import DXF and extude while in app
* **(todo)** Posibility to import STL and calculate the mass of the model
* **(todo)** Add versioning, through cmake, and functions to print version

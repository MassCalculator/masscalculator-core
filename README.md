# Metal Mass Calculator

This package includes one library and one executable that opens a GUI for the app. All the calculations are done in the library and the GUI Executable is only a wrapper for user experience. The library can also be integrated in a nother app so that is the reason why it is seperated like this.

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

* freeGlut
  ```
  $ sudo apt install freeglut3-dev
  ```

* libGlui
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
./build/MetalMassCalculatorGUI/MetalMassCalculatorGUI
```

Everything then can be handled from the GUI.
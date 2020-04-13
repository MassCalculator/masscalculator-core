# libmasscalculator

| Master 	| Devel 	| Deployment 	|
|--------	|-------	|------------	|
| [![Build Status](https://travis-ci.com/masscalculator/libmasscalculator.svg?token=SL6RqWzwyVSzbz3qVX6L&branch=master)](https://travis-ci.com/masscalculator/libmasscalculator) |  [![Build Status](https://travis-ci.com/masscalculator/libmasscalculator.svg?token=SL6RqWzwyVSzbz3qVX6L&branch=devel)](https://travis-ci.com/masscalculator/libmasscalculator) | [![Build Status](https://travis-ci.com/masscalculator/libmasscalculator.svg?token=SL6RqWzwyVSzbz3qVX6L&branch=devel)](https://travis-ci.com/masscalculator/libmasscalculator) | 

## What is libmasscalculator

Lib MassCalculator is a library used t ocalculate the weight of an object while specifying the material and shape. The library will be able to import stl files, and also dxf files where the user can be able to extrude the dxf for a specific thickness.

I am planning to add all the material specific properties accordingly to SI (International system), but the user will be able to change these parameters from the providen LUA config files for each material (Doing so will watermark the report for not using the SI parameters but instead, custom ones)

All the datatypes are strongly typed from a third party library that I use. It is not included as a submodule because I changed some old style casting, but credit goes to the writer.

```bash
https://github.com/nholthaus/units
```

## Additional info

As additional info I am mentioning the design pattern I have used, also providing some explanation. Also I used this project as a learning process, so even if not necessary, I will provide bellow a list of the language features I wanted in this project.

### List

* std::function
* std::unordered_map
* lambda function
* Shift operator overloads

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

## Dependencies

Below listed packages are required and have to be installed/compiled before:

* CMake
  ```bash
  $ sudo apt install cmake
  ```

* DXFlib
  ```bash
  $ sudo apt install libdxflib-dev
  ```

* LUAlib
  ```bash
  $ sudo apt-get install liblua5.1-0-dev
  ```

* GoogleTest
  ```bash
  $ git clone https://github.com/google/googletest.git
  $ cd googletest
  $ mkdir build && cd build
  $ cmake ..
  $ make 
  $ sudo make install
  ```

## Build sources

There is no current working version, the work is still in progress.

* libmasscalculator
  ```bash
  $ git clone https://github.com/MassCalculator/libmasscalculator.git
  $ cd libmasscalculator
  $ mkdir build && cd build
  $ cmake ..
  $ make 
  $ sudo make install
  ```

Note: 
* .hh files are header only to include all the headers
* .hpp files have a .cpp file that is associated with
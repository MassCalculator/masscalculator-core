# MassCalculator core library

This repository contains the main codebase for the MassCalculator library development.

## What is libmasscalculator

Lib MassCalculator is a library used t ocalculate the weight of an object while specifying the material and shape. The library will be able to import stl files, and also dxf files where the user can be able to extrude the dxf for a specific thickness.

I am planning to add all the material specific properties accordingly to SI (International system), but the user will be able to change these parameters from the providen LUA config files for each material (Doing so will watermark the report for not using the SI parameters but instead, custom ones)

All the datatypes are strongly typed from a third party library that I use. It is not included as a submodule because I changed some old style casting, but credit goes to the writer.

```bash
https://github.com/nholthaus/units
```

## Instructions

- [Environment Variables](docs/ENVIRONMENT.md)
- [Environment Setup](docs/SETUP.md)
- [How to Build](docs/BUILD.md)
- [All about Tests](docs/TESTS.md)

## CI Server

WIP: Using local Jenkins for the moment.

[![Build Status](http://localhost:8080/jenkins/job/masscalculator-core/job/master/badge/icon)](http://localhost:8080/jenkins/job/masscalculator-core/job/master/)

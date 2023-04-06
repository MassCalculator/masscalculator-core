# MassCalculator core library

[![Build Status](https://jenkins.mergimhalimi.com/buildStatus/icon?job=masscalculator-core%2Fdevel)](https://jenkins.mergimhalimi.com/job/masscalculator-core/job/devel/)

This repository contains the main codebase for the MassCalculator library development.

## What is masscalculator-core

The `masscalculator-core` library is designed to determine the weight of an object by taking into account its material and shape. It can handle stl and dxf file formats, and the user can specify the desired thickness when extruding the dxf file. The library includes material properties conforming to the International System of Units (SI), but the user can customize these properties using LUA configuration files. However, using custom parameters will result in a watermark on the report. The library uses strongly-typed data types from a third-party library, which has been modified to remove old-style casting. The third-party library used is available at <https://github.com/nholthaus/units>.

## Instructions

- [Environment Variables](docs/ENVIRONMENT.md)
- [Environment Setup](docs/SETUP.md)
- [How to Build](docs/BUILD.md)
- [All about Tests](docs/TESTS.md)

## Jenkins Server

Access Jenkins server [here](https://jenkins.mergimhalimi.com/job/masscalculator-core/)

# Build the MassCalculator core library

The MassCalculator core library is built using CMake, therefore two steps are needed:

## CMake Configuration

Create a build directory, anywhere but inside the source directory.
Call CMake using the following commands:

### Basic Configuration, Debug, no Extra Tools, no Tests, no Documentation

```bash
cmake -S $MASSCALCULATOR_SOURCE -B <BUILD DIRECTORY> -G Ninja -DCMAKE_BUILD_TYPE=<Debug|Release>
```

### Configure Build with all Tests

```bash
cmake -S $MASSCALCULATOR_SOURCE -B <BUILD DIRECTORY> -G Ninja -DBUILD_TESTS=ON -DCMAKE_BUILD_TYPE=<Debug|Release>
```

### Configure Build with Doxygen Documentation

```bash
cmake -S $MASSCALCULATOR_SOURCE -B <BUILD DIRECTORY> -G Ninja -DBUILD_DOCS=ON -DCMAKE_BUILD_TYPE=<Debug|Release>
```

## Build

From the build directory call

### Build everything

```bash
cmake --build <BUILD DIRECTORY> --config <Debug|Release>
```

## Documentation

The Doxygen documentation will be available under the subdirectory `docs/html`
of your build directory. E.g., in `build/docs/html`.

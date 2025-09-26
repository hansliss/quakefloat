# Quake Fast Inverse Square Root

This repository contains a small C project that implements and exercises the famous fast inverse square root routine popularised by Quake III Arena. The code builds with CMake, exposes the function via a reusable library, includes a simple command-line driver, and provides empirical tests that verify the approximation accuracy across inputs spanning twelve orders of magnitude.

For background on the algorithm, see the [Fast inverse square root](https://en.wikipedia.org/wiki/Fast_inverse_square_root) article on Wikipedia.

## Building

```
cmake -S . -B build
cmake --build build
```

## Running the demo

```
./build/quakefloat 0.5 1 2 10
```

## Running the tests

```
ctest --test-dir build --output-on-failure
```

# Ledger Core Library

Core library which will be used by Ledger applications.

## Clone project

```
git clone --recurse-submodules https://github.com/LedgerHQ/lib-ledger-core.git
```

## Dependencies

### Build
This project is based on **_cmake_** as a build system so you should install it before starting (at least version 3.7).

### External dependencies:
* [Qt5](https://www.qt.io/download) is needed to build tests of the library.
* Generation of binding is automated with [Djinni](https://github.com/dropbox/djinni).
* Build on multiple Operating Systems is based on [polly](https://github.com/ruslo/polly) toolchains.

## Build of C++ library

**_cmake_** is building out of source, you should create a build directory (e.g. `lib-ledger-core-build`):

	.                           # Directory where clone command was launched
    ├── lib-ledger-core         # Source files directory
    ├── lib-ledger-core-build   # Build directory

If you respect this folder structure (and naming), after `cd lib-ledger-core-build`, you can build the library by running:

```
cmake -DCMAKE_INSTALL_PREFIX=/path/to/qt5 ../lib-ledger-core && make
```

### Building for JNI

Building with JNI (Java Native Interface), allows you to use the library with Java based software. In order to enable JNI mode use
```
cmake -DTARGET_JNI=ON
``` 

This will add JNI files to the library compilation and remove tests. You need at least a JDK 7 to build for JNI (OpenJDK or Oracle JDK)

## Binding to node JS

Generate binding (under `build/Release/ledgerapp_nodejs.node`):

```
npm i
```

## Test NodeJs

```
node ledger-core-samples/nodejs/tests/wallet-pool-test.js
```

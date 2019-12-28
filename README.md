# libdialstring [![C++ standard][c++-standard-shield]][c++-standard-link] [![License][license-shield]][license-link]
---
[![TravisCI][travis-shield]][travis-link]
<!--[![Codecov][codecov-shield]][codecov-link]
[![Coverity][coverity-shield]][coverity-link]
[![Coverage Status][coveralls-shield]][coveralls-link]-->
[![LGTM][LGTM-shield]][LGTM-link]


[c++-standard-shield]: https://img.shields.io/badge/c%2B%2B-14/17/20-blue.svg
[c++-standard-link]: https://en.wikipedia.org/wiki/C%2B%2B#Standardization
[license-shield]: https://img.shields.io/badge/License-Apache%202.0-blue.svg
[license-link]: https://opensource.org/licenses/Apache-2.0
[travis-shield]: https://travis-ci.org/abbyssoul/libdialstring.png?branch=master
[travis-link]: https://travis-ci.org/abbyssoul/libdialstring

[LGTM-shield]: https://img.shields.io/lgtm/grade/cpp/github/abbyssoul/libdialstring.svg
[LGTM-link]: https://lgtm.com/projects/g/abbyssoul/libdialstring/alerts/

<!--[codecov-shield]: https://codecov.io/gh/abbyssoul/libdialstring/branch/master/graph/badge.svg
[codecov-link]: https://codecov.io/gh/abbyssoul/libdialstring
[coverity-shield]: https://scan.coverity.com/projects/18800/badge.svg
[coverity-link]: https://scan.coverity.com/projects/abbyssoul-libdialstring
[coveralls-shield]: https://coveralls.io/repos/github/abbyssoul/libdialstring/badge.svg?branch=master
[coveralls-link]: https://coveralls.io/github/abbyssoul/libdialstring?branch=master-->


A _library_ defining 9p inspired DialString type.
> library: a collection of types, functions, classes, etc. implementing a set of facilities (abstractions) meant to be potentially used as part of more that one program. From [Cpp Code guidelines gloassay](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#glossary)

# Dialstrings
DialString is Plan9 equivalent of URI, but simpler.
In general dial string is a string in a format: "[protocol:]address[:service]"
For example:
- "tcp:google.com:http"
- "udp:10.1.2.3:32"
- "tipc:0.2.117:81"
- "tcp:example.com:ssh"
- "unix:/var/run/socket"
- "some_id"

# Using this library

```
// One header file to include DialString type
#include <dialstring/dialstring.hpp>

...
// Parse a dial string from a string:
auto parsedOk = styxe::tryParseDailString("tcp:example.com:ssh");
if (!parsedOk) {
... handle error
}

auto& dialString = *parsedOk;
EXPECT_EQ(styxe::kProtocolTCP, dialString.protocol);
EXPECT_EQ("example.com", dialString.address);
EXPECT_EQ("ssh", dialString.service);
```

## Consuming library with Conan
The library is available via [Conan](https://conan.io/) package manager. Add this to your project `conanfile.txt`:
```
[requires]
libdialstring/0.1
```

Please check the latest available [binary version][conan-central-latest].


## Dependencies
This library depends on [libsolace](https://github.com/abbyssoul/libsolace) for low-level primitives StringView and Result<> types.

### GTest
Note test framework used is *gtest* and it is managed via git modules.
Don't forget to do `git submodule update --init --recursive` on a new checkout to pull sub-module dependencies.



# Building

### Build tool dependencies
To build this project, following tools must be present in the system:
* git (to check out the project and it’s external modules, see dependencies section)
* cmake - user for build script generation
* ninja (opional, used by default)
* doxygen (opional, for documentation generation)
* cppcheck (opional, but recommended for static code analysis, latest version from git is used as part of the 'codecheck' step)
* cpplint (opional, for static code analysis in addition to cppcheck)
* valgrind (opional, for runtime code quality verification)

This project is using C++17 features extensively. The minimal tested/required version of gcc is gcc-7.
[CI](https://travis-ci.org/abbyssoul/libdialstring) is using clang-6 and gcc-7.
To install build tools on Debian based Linux distribution:
```shell
sudo apt-get update -qq
sudo apt-get install git doxygen python-pip valgrind ggcov
sudo pip install cpplint
```

The library has one external dependency: [libsolace](https://github.com/abbyssoul/libsolace), which is managed via conan.
Please make sure [conan is installed](https://docs.conan.io/en/latest/installation.html) on your system if you want to build this project.

## Building the project
```shell
# In the project check-out directory:
# To build debug version with sanitizer enabled (recommended for development)
./configure --enable-debug --enable-sanitizer

# To build the library it self
make

# To build and run unit tests:
make test

# To run valgrind on test suit:
# Note: `valgrind` doesn’t work with ./configure --enable-sanitize option
make verify

# To build API documentation using doxygen:
make doc
```

To install locally for testing:
```shell
make --prefix=/user/home/<username>/test/lib install
```
To install system-wide (as root):
```shell
make install
```
To run code quality check before submission of a patch:
```shell
# Verify code quality before submission
make codecheck
```


## Contributing changes
The framework is work in progress and contributions are very welcomed.
Please see  [`CONTRIBUTING.md`](CONTRIBUTING.md) for details on how to contribute to
this project.

Please note that in order to maintain code quality, a set of static code analysis tools is used as part of the build process.
Thus all contributions must be verified by these tools before PR can be accepted.


## License
The library available under Apache License 2.0
Please see [`LICENSE`](LICENSE) for details.


## Authors
Please see [`AUTHORS`](AUTHORS) file for the list of contributors.

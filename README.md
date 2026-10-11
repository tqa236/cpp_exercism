# cpp_exercism

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/61fd4c8fc29b4e62ad5ff19098e245fb)](https://www.codacy.com/app/tqa236/cpp_exercism?utm_source=github.com&utm_medium=referral&utm_content=tqa236/cpp_exercism&utm_campaign=Badge_Grade)
[![codecov](https://codecov.io/gh/tqa236/cpp_exercism/branch/main/graph/badge.svg)](https://codecov.io/gh/tqa236/cpp_exercism)

Learn C++ in a TDD environment with Exercism

Code formatting

```bash
./format.sh
```

Run `./format.sh --check` to check formatting without changing files. Both
commands use the checked-in `.clang-format` configuration.

## Continuous integration

GitHub Actions checks formatting and `cpplint` on implementation files, then
builds and runs every exercise's tests with both GCC and Clang. The test jobs
install the required Boost development libraries before configuring the
individual CMake projects. Exercise builds and tests run concurrently, bounded
by the available CPU cores; failures are collected and reported together after
all exercises complete.
For compatibility with current glibc and Clang, CI disables Catch's POSIX
signal handler and does not promote its C2y-extension warning to an error.
To run lint locally, install `cpplint` with `python -m pip install cpplint` and
run `./lint.sh`; install `clang-format` with your system package manager to
format C++ sources using `./format.sh`.

## TODO

-   Fix code coverage problem.
-   Update all exercises remove using declaration usage.
-   Use only #pragma once

# DSLib — C++ DSA Library

DSLib is a C++17 library containing the core data-structure implementations and two domain modules: School and Hospital.

## Requirements
- CMake 3.16 or newer
- A C++17 compiler (GCC, Clang, or MSVC)

## Build

```bash
cmake -S . -B build
cmake --build build --config Release
```

## Run the example

```bash
./build/dslib_demo
```

On Windows with a multi-configuration generator, the executable may be under `build/Release/`.

## Run tests

```bash
ctest --test-dir build --output-on-failure
```

## Use the library in another CMake project

```cmake
add_subdirectory(path/to/DSLib)
target_link_libraries(your_program PRIVATE DSLib::dslib)
```

Then include the required module headers:

```cpp
#include "school.h"
#include "hospital.h"
```

## Project layout

- `include/dslib/` — core DSA public headers
- `include/school/` — School domain header
- `include/hospital/` — Hospital domain header
- `src/` — core DSA implementations
- `school/` and `hospital/` — domain implementations
- `examples/` — example application
- `tests/` — basic build and behavior smoke test


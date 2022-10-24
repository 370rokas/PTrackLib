# PTrackLib

![](https://img.shields.io/github/license/370rokas/PTrackLib)
![](https://img.shields.io/github/issues/370rokas/PTrackLib)
![](https://img.shields.io/github/languages/count/370rokas/PTrackLib)
![](https://img.shields.io/github/languages/top/370rokas/PTrackLib)
![](https://img.shields.io/github/repo-size/370rokas/PTrackLib)

**Author:** 370rokas

**License:** [MIT License](license.md)

**Description:** A simple C++ chronometer library

## 🔨 Dependencies
```shell
$ Minimum C++ version: C++14
```
## ✨ Basic Usage
```c++
#include <ptracklib.h>

...

// Initialize and start a basic chronometer
ptrack::Tracker Chronometer;

...

// Gets elapsed time in miliseconds (MS)
Tracker.get();

// Gets elapsed time in a desired time format (ptrack::TimeFormat)
Tracker.get(ptrack::TimeFormat::NS);
```

## 🔧 Installation

#### CMake :
1. Clone the repo locally.
2. Include the repo in your CMake project via add_subdirectory()
3. Add the library to your project using target_link_libraries()

## 📓 Todo
- Properly document the library;
- Add lap chronometer;
- Add GitHub actions, code coverage analysis;

## 🤝 Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## 📝 License
This project is licensed under the [MIT license](license.md).

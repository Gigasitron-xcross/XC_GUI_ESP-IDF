# XC_GUI for ESP-IDF

XC_GUI is a lightweight embedded GUI library from **Gigasitron** for ESP32 devices using **ESP-IDF**.

This repository provides the ESP-IDF version of XC_GUI as a **precompiled static library** together with the public header files required to use it in an ESP-IDF project.

## ESP Component Registry

Component name:

```text
gigasitron/xc_gui
```

Install it in an ESP-IDF project with:

```bash
idf.py add-dependency "gigasitron/xc_gui^1.0.0"
```

or add it manually to your project's `idf_component.yml`:

```yaml
dependencies:
  gigasitron/xc_gui: "^1.0.0"
```

## Supported Targets

Current release:

| Target | Status |
|---|---|
| ESP32-S3 | Supported |

Additional ESP32 targets may be added in future releases. Each target uses a separately compiled XC_GUI static library.

## Features

XC_GUI is designed for small embedded displays and resource-constrained GUI applications.

Key features include:

- Lightweight embedded GUI core
- Drawing primitives
- Text and font rendering
- Support for custom fonts
- Bitmap/image drawing
- Double-buffered GUI operation
- Suitable for TFT and OLED display projects
- Designed for use with user-provided display drivers
- Precompiled optimized library for ESP-IDF

The display interface is kept separate from the GUI core so XC_GUI can be integrated with different display controllers and hardware designs.

## Repository Structure

```text
XC_GUI_ESP-IDF/
├── include/
│   ├── XGUI.h
│   ├── Common.h
│   ├── LCD.h
│   └── XC_GUI_Types.h
│
├── lib/
│   └── esp32s3/
│       └── libxc_gui.a
│
├── CMakeLists.txt
├── idf_component.yml
├── README.md
├── LICENSE
│
└── .github/
    └── workflows/
        └── upload_component.yml
```

## Using XC_GUI

After adding the component to your project, include the XC_GUI public header:

```c
#include "XGUI.h"
```

The application must provide and initialize the display hardware interface required by XC_GUI.

For example, an ESP32-S3 display project may use ESP-IDF SPI APIs to communicate with an ST7789 or another supported display controller, while XC_GUI handles the higher-level graphics operations.

## Precompiled Library

XC_GUI is distributed in this repository as a precompiled static library:

```text
lib/esp32s3/libxc_gui.a
```

The library is compiled for the specific ESP32 target listed in the directory name.

A binary compiled for one ESP32 target must not be used for another target. For example, the ESP32-S3 library must not be used directly on ESP32-C3 or ESP32-C6.

When support for additional targets is released, separate libraries will be provided, for example:

```text
lib/
├── esp32/
│   └── libxc_gui.a
├── esp32s3/
│   └── libxc_gui.a
├── esp32c3/
│   └── libxc_gui.a
└── esp32c6/
    └── libxc_gui.a
```

The component CMake configuration selects the appropriate library for the current `IDF_TARGET`.

## Optimization

The release library is built with ESP-IDF performance optimization enabled:

```text
CONFIG_COMPILER_OPTIMIZATION_PERF=y
```

which corresponds to GCC optimization:

```text
-O2
```

## ESP-IDF Compatibility

XC_GUI is built and tested with ESP-IDF.

Because this package contains a precompiled library, ESP-IDF version compatibility is important. Supported ESP-IDF versions will be documented for each release as compatibility is verified.

## Display Driver

XC_GUI does not require the GUI core to be tied to a single display controller.

The application is responsible for providing the low-level display interface used by XC_GUI, including operations such as:

- display initialization
- command/data control
- pixel or block transfer
- SPI configuration where applicable
- display reset and chip-select handling

This makes it possible to use XC_GUI with different display modules and board designs.

## Related Project

Arduino version of XC_GUI:

https://github.com/Gigasitron-xcross/XC_GUI

ESP-IDF version:

https://github.com/Gigasitron-xcross/XC_GUI_ESP-IDF

## Releases

Published ESP-IDF component releases are available under:

```text
gigasitron/xc_gui
```

Version numbers follow semantic versioning:

```text
MAJOR.MINOR.PATCH
```

For example:

```text
1.0.0
1.0.1
1.1.0
```

## License

See the `LICENSE` file in this repository for licensing terms.

## Author

**Gigasitron**

Website: https://gigasitron.com  
GitHub: https://github.com/Gigasitron-xcross

# Text Editor with Statistics

A simple text editor built in C++/Qt (Qt Widgets), supporting multiple open files at once and computing text statistics — including duplicate word counting implemented with a custom singly linked list.

Project demonstrating GUI development in Qt Creator, object-oriented programming fundamentals (inheritance, polymorphism), static array operations, and dynamic data structures (linked list).

---

## Features

### Core
- Open and save multiple text files at once (tabbed interface)
- Create new, empty documents
- Save / Save As
- Close individual tabs
- Compute text statistics:
  - paragraph count
  - word count
  - letter count
  - character count
- Display statistics as a readable report

### Extended
- Duplicate word counting, implemented with a **custom singly linked list** (no Qt/STL containers used)
- Analysis mode selection (basic / advanced) via a dedicated dialog window

---

## Architecture

```
├── main.cpp                     – application entry point
├── mainwindow.h / .cpp / .ui     – main window (editor, tabs, file handling)
├── stats.h / .cpp                – base class: core text statistics
├── advancedstats.h / .cpp        – derived class: statistics + duplicate word list
├── node.h / .cpp                 – linked list node
└── textanalyzerwindow.h/.cpp/.ui – dialog for selecting analysis mode
```

### Class hierarchy

```
stats                          (base class)
  ├── analyze(text)             – counts paragraphs, words, letters, chars
  ├── raport()                  – returns a text report
  └── frequency[26]              – static array tracking a-z letter frequency

advancedstats : public stats   (derived class)
  ├── analyze(text) override    – extends analysis with word-list construction
  ├── raport() override         – appends duplicate word report
  └── head (node*)               – pointer to the custom linked list
```

`analyze()` and `raport()` are declared `virtual` in the base class and overridden in the derived class, enabling polymorphic calls through a `stats*` pointer or reference.

---

## Requirements

- Qt 6.x (tested on Qt 6.7.3)
- C++17-compatible compiler (MinGW / MSVC / GCC)
- Qt Creator (recommended for building and running)

---

## Build & Run

1. Open the `.pro` file in Qt Creator
2. Select the appropriate kit (e.g. Desktop Qt 6.7.3 MinGW 64-bit)
3. Build: `Ctrl+B`
4. Run: `Ctrl+R`

---


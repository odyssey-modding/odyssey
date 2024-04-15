# This repo is being archived. Please use [MonsterDruide1/OdysseyDecomp](https://github.com/MonsterDruide1/OdysseyDecomp) instead.

This repo does not receive any further maintenance. As soon as all open PRs are either merged or ported over to the other repository, this repo will be archived.

# Odyssey Decompilation Project ![Decompiled Status](https://img.shields.io/endpoint?url=https://raw.githubusercontent.com/odyssey-modding/odyssey/main/data/shields.json)
Decompilation of Super Mario Odyssey 1.0.0. 

*Sorted function map can be found [here](https://docs.google.com/spreadsheets/d/198vrkkDqktrRDLInSAkK2HsG5hy1Fl8cmCNRMND3nCY/edit).*

# Building

Reminder: **this will not produce a playable game.** This project will not allow you to play the game if you don't already own it on a Switch.

## For Windows users

While Linux is not a hard requirement, it is strongly advised to [set up WSL](https://docs.microsoft.com/en-us/windows/wsl/install-win10) to simplify the setup process. Ubuntu 20.04 is usually a good choice.

The instructions below assume that you are using Linux (native or WSL) or macOS.

## 1. Set up dependencies

* Python 3.6 or newer with [pip](https://pip.pypa.io/en/stable/installation/)
* Ninja
* CMake 3.13+
    * If you are on Ubuntu 18.04, you must first [update CMake by using the official CMake APT repository](https://apt.kitware.com/).
* ccache (to speed up builds)
* xdelta3
* clang (not for compiling SMO code, but for compiling Rust tools)

Ubuntu users can install those dependencies by running:

```shell
sudo apt install python3 ninja-build cmake ccache xdelta3 clang libssl-dev
```

Additionally, you'll also need:

* A Rust toolchain ([follow the instructions here](https://www.rust-lang.org/tools/install))
* The following Python modules: `capstone colorama cxxfilt pyelftools ansiwrap watchdog python-Levenshtein toml` (install them with `pip install ...`)

## 2. Set up the project

1. Clone this repository. If you are using WSL, please clone the repo *inside* WSL, *not* on the Windows side (for performance reasons).

2. Run `git submodule update --init --recursive`

    Next, you'll need to acquire the **original 1.0 `main` NSO executable**.

    * To dump it from a Switch, follow [the instructions on the wiki](https://zeldamods.org/wiki/Help:Dumping_games#Dumping_binaries_.28executable_files.29).
    * You do not need to dump the entire game (RomFS + ExeFS + DLC). Just dumping the 1.0 ExeFS is sufficient.

3. Run `tools/setup.py [path to the NSO]`
    * This will:
        * install tools/check to check for differences in decompiled code
        * convert the executable if necessary
        * set up [Clang 3.9.1](https://releases.llvm.org/download.html#3.9.1) and [4.0.1](https://releases.llvm.org/download.html#4.0.1) by downloading them from the official LLVM website
        * create a build directory in `build/`
    * If something goes wrong, follow the instructions given to you by the script.
    * If you wish to use a CMake generator that isn't Ninja, use `--cmake_backend` to specify it.

## 3. Build

To start the build, just run

```shell
python tools/build.py
```

By default, a multithreaded build is performed. No need to specify `-j` manually.

Use `--clean` to perform a clean build, and `--verbose` to enable verbose output.

To check whether everything built correctly, just run `tools/check` after the build completes.


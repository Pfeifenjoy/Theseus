# Theseus

## Quick start guide (Linux)

### How to set everything up

1) Install all required packages

```
sudo apt-get install build-essential cmake libsfml-dev
```

2) Run CMake

This will generate a makefile that works on your system.

```
mkdir build
cd build
cmake ..
```

### How to build

To build the project just run ```make``` in the build folder.

```
cd buid 			# if you are not already there...
make
```

Note that you don't need to re-run cmake every time.

## Quick start guide (Windows)

### How to set everything up

1) Download and install the following software

 - CMake
 - Visual Studio or a C++ Compiler like g++/MinGW
 - SFML - Just download the package for the compiler of your choice and extract the *.zip-File somewhere.

2) Run CMake

 Open the Cmake GUI (cmake-gui).

  - "Where is the source code" : Enter the path to this repository.
  - "Where to build the binarires" : Enter the path where you want your Visual Studio-Project to be generated.

Click on "Add entry" and specify the following values:

 - "Name" : "CMAKE_PREFIX_PATH"
 - "Type" : "PATH"
 - "Value" : Enter the path to the folder where you extracted SFML to.

You don't need to provide a description. Press "OK" to continue. Back in the main window click on "Configure". When the configuration process is done, click on "Generate". After that you will find a Visual Studio-Project that can be used to modify and compile the project at the folder you specified.

If you want Visual Studio to automatically start the game, you have to set the project "theseus" as start project.




### How to build
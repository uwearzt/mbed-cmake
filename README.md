# mbed-cmake

My [cmake](http://www.cmake.org) files for use the [gcc-arm-embedded](https://launchpad.net/gcc-arm-embedded) toolchain
(gcc/g++) and the [mbed libraries](http://mbed.org/handbook/Homepage) together.

Everything is tested on Mac OS X at the moment only with the LPC1768 mbed devices. As soon as i get other devices,
i will integrate the other processors and vendors too. If you like too have additional targets added you can either send:

* a pull request with the needed addition
* a board, i will add support as soon as possible

## Install the gcc-arm toolchain

* Download the [gcc-arm-embedded toolchain](https://launchpad.net/gcc-arm-embedded)

* Unpack the file in */opt/local*

```bash
tar zxvf ~/Downloads/gcc-arm-none-eabi-4_8-2013q4-20131218-mac.tar.bz2
```

* Create a symbolic link, so it is easy to switch between different toolchain versions

```bash
ln -s gcc-arm-none-eabi-4_8-2013q4/ gcc-arm
```

* Add the gcc-arm-toolset to your path

```bash
export PATH=/opt/local/gcc-arm/bin:$PATH
```


## Get and build mbed libraries

* Clone the mbed libraries to */opt/local*

```bash
git clone https://github.com/mbedmicro/mbed.git
```

* Build the needed mbed (depending on your board and your compiler) libs with

```bash
python ./workspace_tools/build.py -r -e -u -d -m LPC1768 -t GCC_ARM
python ./workspace_tools/build.py -u -d -m LPC11U24 -t GCC_ARM
```

I always build for some other targets too (to see how the path settings differ for creating useful variables).

```bash
python ./workspace_tools/build.py -r -d -m RBLAB_NRF51822 -t GCC_ARM
python ./workspace_tools/build.py -r -e -u -d -m K64F -t GCC_ARM
```

* Run the mbed tests, you have to choose the correct settings for the Volume and the serial port

```bash
python ./workspace_tools/make.py -c -v -m LPC1768 -t GCC_ARM -d /Volumes/MBED -s /dev/cu.usbmodem1442 -p 0
```

## Test if mbed-cmake works for you

* Get a clone of cmake-mbed

```bash
git clone https://github.com/uwearzt/mbed-cmake.git
```

* Build the blinking LEDexample with cmake. If you have installed the gcc-arm or the mbed libs to another directory, you have to set the path to them inside **arm_mbed.cmake**.

```bash
cd build
cmake ..
make
make upload
<reset>
make sercon
```

and you should have a blinking LED and a serial console with some up counting lines.

## Integrate into your own project

The best way to integrate cmake-mbed is to use it as a git submodule. In your project repository do

```bash
git submodule add https://github.com/uwearzt/mbed-cmake.git mbed-cmake
git submodule init
git add .gitmodules mbed-cmake
cp mbed-cmake/CMakeLists.txt .
```

and do the necessary changes in the CMakeLists.txt. With cmake ist is always a good idea to create a build directory as a subfolder and do out-of-tree builds.
The best way to ignore all the intermediate files is a .gitignore with * inside the build folder.

```bash
mkdir build
echo "*" > build/.gitignore
git add -f build/.gitignore
```
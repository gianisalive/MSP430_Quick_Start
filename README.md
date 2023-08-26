# MSP430 Emulated Docker Container
The image is created with an emulated Linux x86_64 architecture. This is necessary because it's the only Linux architecture that `msp430-gcc` compiler supports. I haven't noticed any significant performance hindrance for development and compilation. 

## Workflow In a Nutshell
The code editing is done via **Visual Studio Code** by attaching it to a Docker container. The code is also compiled within the container. Afterwards, the image is flashed locally using **UniFlash**. I haven't included UniFlash in the Docker container since it's a GUI application that doesn't require any environment setup.

## 1. Build Image (assuming you already installed Docker)
Run `./docker.sh -r build`. This will install all the required packages and set up the environment to support compilation. To verify if the image is built, you can run `docker images`, and **msp430** should show up in list of available images.

## 2. Run Container
Run `./docker.sh` -r run. This will spin up the Docker container. The volume mount reflects any edits that was made in the container. To make sure the container is running, type `docker ps`.

## 3. Set Up Visual Studio Code
Install **C/C++ Theme** and **Dev Container** extension. Once the container is running, open **Command Palette...**, Type in `Dev Containers: Attach to Running Container..` and select the name of the container.

## 4. Compile C Code
Run `make`. The **Makefile** file is setup to compile **C**. Different compilers can be choosed in the same bin directory for **C++**.

## 5. Flash Firmware
After the code is compiled, hex file `output.hex` can be uploaded via **UniFlash**.

## Additional Questions
gianisalive@gmail.com - I'm friendly `:)`

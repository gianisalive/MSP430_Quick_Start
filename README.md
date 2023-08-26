# MSP430 Emulated Docker Container
The image is created with an emulated Linux x86_64 architecture. This is necessary because it's the only Linux architecture that `msp430-gcc` compiler supports. I haven't noticed any significant performance hindrance for development and compilation. 

## Workflow In a Nutshell
The code editing is done via **Visual Studio Code** by attaching it to a Docker container. The code is also compiled within the container. Afterwards, the image is flashed locally using UniFlash. I haven't included UniFlash in the Docker container since it's a GUI application that doesn't require any environment setup.

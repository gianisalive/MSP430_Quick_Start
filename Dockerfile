FROM ubuntu:20.04

ARG DEBIAN_FRONTEND=noninteractive

ENV PATH="/msp430-gcc-9.3.1.11_linux64/bin:$PATH"

WORKDIR /msp430

COPY . .

RUN apt-get update
RUN apt-get -y install build-essential
RUN apt-get -y install wget
RUN apt-get -y install p7zip-full
RUN apt-get -y install expect
RUN apt-get clean
RUN rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

# Support File For C Header
RUN wget https://dr-download.ti.com/software-development/ide-configuration-compiler-or-debugger/MD-LlCjWuAbzH/9.3.1.2/msp430-gcc-full-linux-x64-installer-9.3.1.2.7z
RUN 7z x msp430-gcc-full-linux-x64-installer-9.3.1.2.7z
RUN expect /msp430/c_toolchain_install.exp

# Support File For Compilation
RUN wget https://dr-download.ti.com/software-development/ide-configuration-compiler-or-debugger/MD-LlCjWuAbzH/9.3.1.2/msp430-gcc-9.3.1.11_linux64.tar.bz2
RUN tar xvf msp430-gcc-9.3.1.11_linux64.tar.bz2 -C /

RUN rm -rf msp430-gcc-full-linux-x64-installer-9.3.1.2.7z msp430-gcc-full-linux-x64-installer-9.3.1.2.run msp430-gcc-9.3.1.11_linux64.tar.bz2

CMD ["/bin/bash"]

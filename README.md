# Smart-Intonation
music software for intonation training

## Overview
Smart Intonation is a musical software aimed to teach the pitch to new music students, the main parts used in this software are the sound card of the pc and a linux operating system (Ubunto). The software is devided into three phases. The first step allow the user to play a C-scale video in order to start learning the difference between each tone. In the second step, the software generates random tones and the user must know which tone is generated. In the last step, the software should ask the user to sing a random tone, the software will then compare the frequecy of the tone to the frequency of the user using fast fourier transform. the steps are followed by a real-time feedback to make the user perform better.

## Making it work

Install the QT5 and Qwt development packages:

```
    apt-get install qtdeclarative5-dev-tools
    apt-get install libqwt-qt5-dev
    apt-get install fftw3
```

To clone this git repository.

To build:

```
    cd Smart-Intonation
    cmake .
    make
```

To run:

```
    ./qwt-example
```
## License

Distributed under the GPL-3.0 License. See LICENSE for more information.

## Note:

Anyone who feels they can contribute any imporovements to the project is welcome to fork the project, and submit an issue with a pull request with the changes.

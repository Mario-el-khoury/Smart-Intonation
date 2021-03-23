# Smart-Intonation
music software for intonation training

## Making it work

Install the QT5 and Qwt development packages:

```
    sudo apt-get install qtdeclarative5-dev-tools
    sudo apt-get install libqwt-qt5-dev
    sudo apt-get install libqt5multimedia5-plugins
    
```

To clone this git repository.

To build automatically:

```
    cd build
    sh build.sh

```
OR To build manually:

```
    cd build
    cmake ..
    make
    ./Smarto

```

To clean build files:

```
    cd build
    sh clean.sh

```
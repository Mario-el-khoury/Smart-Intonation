# Smart-Intonation
music software for intonation training

<h2> Hey there! I'm Mario and i am working with  Zihan and Jiajun on the Smart Intonation Software.</h2>

<h3> 👨🏻‍💻 &nbsp;About Us </h3>

- 🤔 &nbsp; Exploring new technologies and developing software solutions.
- 🎓 &nbsp; Studying at the University of Glasgow.

<h3> 🛠 &nbsp;Tech Stack</h3>

- 💻 &nbsp;
  ![C++](https://img.shields.io/badge/-C++-333333?style=flat&logo=C%2B%2B&logoColor=00599C)
- ⚙️ &nbsp;
  ![Git](https://img.shields.io/badge/-Git-333333?style=flat&logo=git)
  ![GitHub](https://img.shields.io/badge/-GitHub-333333?style=flat&logo=github)
- 🔧 &nbsp;
  ![Visual Studio Code](https://img.shields.io/badge/-Visual%20Studio%20Code-333333?style=flat&logo=visual-studio-code&logoColor=007ACC)
  

<br/>

<h3> 🤝🏻 &nbsp;Connect with us </h3>

<p align="center">
<a href="https://www.instagram.com/smartintonation/channel/"><img alt="Instagram" src="https://img.shields.io/badge/Instagram-Smartintonation-blue?style=flat-square&logo=instagram"></a>
<a href="https://www.youtube.com/channel/UCLF5YnaRpRm0oMdEWnp-TTw"><img alt="Youtube" src="https://img.shields.io/badge/YouTube-Smartintonation-blue?style=flat-square&logo=YouTube"></a>
<a href="https://www.linkedin.com/in/mario-el-khoury-027216158"><img alt="LinkedIn" src="https://img.shields.io/badge/LinkedIn-Mario%20El%20Khoury-blue?style=flat-square&logo=linkedin"></a>

</p>

⭐️ Collaborators: [Mario-el-khoury](https://github.com/Mario-el-khoury)
            ---   [Zi-han-Huang](https://github.com/Zi-han-Huang)
            ---   [Jiangjiajun-Dominic](https://github.com/Jiangjiajun-Dominic)

## Overview
Smart Intonation is a musical software aimed to teach the pitch to new music students, the main parts used in this software are the sound card of the pc and a linux operating system (Ubunto). The software is devided into three phases. The first step allow the user to play a C-scale video in order to start learning the difference between each tone. In the second step, the software generates random tones and the user must know which tone is generated. In the last step, the software should ask the user to sing a random tone, the software will then compare the frequecy of the tone to the frequency of the user using fast fourier transform. the steps are followed by a real-time feedback to make the user perform better.

## Making it work

Install the QT5 and Qwt development packages:

```
    apt-get install qtdeclarative5-dev-tools
    apt-get install libqwt-qt5-dev
    apt-get install libfftw3-3
```

To clone this git repository.

To build:

```
    cd Smart-intonation
    cd src
    cmake .
    make
```

To run:

```
    ./Smarto
```
## License

Distributed under the GPL-3.0 License. See LICENSE for more information.

## Note:

Anyone who feels they can contribute any imporovements to the project is welcome to fork the project, and submit an issue with a pull request with the changes.

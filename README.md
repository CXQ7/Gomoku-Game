# Gomoku Games
[![Language](https://img.shields.io/badge/language-C++-blue.svg)](https://isocpp.org/)  [![Standard](https://img.shields.io/badge/c%2B%2B-11-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B#Standardization) [![License](https://img.shields.io/github/license/mashape/apistatus.svg)](https://opensource.org/licenses/MIT) ![Github worflow](https://github.com/olrea/openai-cpp/actions/workflows/cmake.yml/badge.svg)
 [![GitHub version](https://badge.fury.io/gh/olrea%2Fopenai-cpp.svg)](https://github.com/olrea/openai-cpp/releases) 

## requirements
+ C++11/C++14/C++17/C++20 compatible compiler
+ [libcurl](https://curl.se/libcurl/) (check [Install curl](https://everything.curl.dev/get) to make sure you have the development package)
+ QT creator in Linux or Windows

## API key
| API reference | Method | Example file |
| --- | --- | --- |
| gpt-3.5 |"sk-on-Jo5FAGExsug1vrAvXCQ"|[gomoku-gpt3.5.cpp](gomoku/gomoku-gpt3.5.cpp) |
| gpt-4o |"sk-0DITh75zrxk-8tM6mhckTA"|[gomoku-gpt4o.cpp](gomoku/gomoku-gpt4o.cpp) |

## installation

The library consists of two files: [openai.hpp](https://github.com/CXQ7/Gomoku-Game/blob/main/examples/openai.hpp) and [nlohmann\json.hpp](https://github.com/CXQ7/Gomoku-Game/blob/main/examples/nlohmann/json.hpp).</br>
you can just download these files and feel free to test them.

## NO UI executions
here are the two original files that connect to the gpt models and play without a board ui, you can gitclone them in you Linux and try to run them.

| gpt models |   file |
| --- | --- | 
| gpt-3.5 |[gomoku-gpt3.5.cpp](gomoku/gomoku-gpt3.5.cpp) |
| gpt-4o |[gomoku-gpt4o.cpp](gomoku/gomoku-gpt4o.cpp) |

## Gomoku with board
We have provided two versions of gomoku games with board.</br>
It allows player to use the mouse instead of inputing the postion of the chess in your key board.<br>
here are the links: [board3.5.cpp](https://github.com/CXQ7/Gomoku-Game/blob/main/Gomoku/Board35.cpp) [board4o.cpp](https://github.com/CXQ7/Gomoku-Game/blob/main/Gomoku/Board4o.cpp)

## the way to use
In case you have no idea how to run the execution,watch this.
open your Ubuntu and run this code
```
sudo apt install qttools5-dev
```
```
git clone https://github.com/CXQ7/Gomoku-Game.git
```
```
cd Gomoku-Game
cd Gomoku
mkdir build
cd build
cmake ..
make
./ Gomoku
```

If U run successfully,you can see:<br>
![image](doc/Ubuntu%20%20-%20VMware%20Workstation%202024_7_18%209_38_01.png)


## License

[MIT](LICENSE.md)


## Acknowledgment

This work has been mainly inspired by [slacking](https://github.com/coin-au-carre/slacking) and the curl wrapper code from [cpr](https://github.com/libcpr/cpr).

## Sponsor

[OLREA](https://www.olrea.fr/)

# Project 3 - AVC Plan - Team 20

**GitHub**: https://github.com/LiamFenneman/Project3

Team name: *Yet to be announced*

### Team Members
- Shaylen Mamidi (mamidishay@myvuw.ac.nz)
- Liam Fenneman (fennemliam@myvuw.ac.nz)
- Nikhil Patel (patelnikh@myvuw.ac.nz)
- Addison Zhen (zhenaddi@myvuw.ac.nz)

### Communication Tools:
Email, Google Docs, Discord, and GitHub.

### Roles:
**Addison** - Project Manager *(organising team meetings, reporting regularly on progress)*

**Liam** - Software Architect *(writing core code and extending functionality)*

**Nikhil** - Software writing, testing and documentation *(debugging software and committing to
git, writing test cases and documenting performance against milestones)*

**Shaylen** - Software writing, testing and documentation *(debugging software and committing to
git, writing test cases and documenting performance against milestones)*

---


|  Date  |         Objectives        |                                        Task                                       |
|:------:|:-------------------------:|:---------------------------------------------------------------------------------:|
|  2 Jun | Planning                  | Get plan done, Sort roles, Ensure all members have code working.                  |
|  6 Jun | Core                      | Finish core with documentation/testing. Discuss steps to take for completion.     |
|  9 Jun | Discussion for Completion | Address difficulties / challenges encountered so far.                             |
| 10 Jun | Wiki Discussion Update    | Wiki Discussion is due on this day.                                               |
| 13 Jun | Completion                | Completion finished with docs/testing. Discuss approach for challenge.            |
| 16 Jun | Discussion for Challenge  | Discuss problems with Challenge.                                                  |
| 19 Jun | Hand in Finished Project  | Challenge finished. Everything is documented/tested. Wiki discussion is also due. |
| 24 Jun | Report Due                | Submit report.                                                                    |

---

### Installation Instructions (Windows 10)

- Geany - [Download Geany](https://www.geany.org/download/releases/)


1. Go to the [SFML website](https://www.sfml-dev.org/download/sfml/2.5.1/) and click "MinGW Builds 7.3.0 (32-bit)" and download button next to "GCC 7.3.0 MinGW (DW2) - 32-bit".
1. Extract the files and put them into your C drive. Rename the "SFML-2.5.1" folder to "SFML". Should look like:
![image of folder structure](https://raw.githubusercontent.com/LiamFenneman/Project3/master/images/1.png)
1. Search for "Environment Variables" in the Windows start menu and open the control panel "Edit the system environement variables".
1. Click the button at the bottom called "Environment Variables" and double click on "Path".
1. Add a new entry with `C:\\mingw32\bin`.
1. Clone respoitory somewhere on computer.
1. Open `server3.cpp` and `robot.cpp` in Geany.
1. Click the "Build" tab at the top OR the dropdown next to the "Build" button and select "Set Build Commands".
1. Ensure the "Independant Commands" -> "Make" is set to `mingw32-make`.
1. Run the program by clicking the "Execute" button on `server3.cpp` and then `robot.cpp`.

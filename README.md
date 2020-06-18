# Project 3 - AVC Plan - Team 20

**GitHub**: https://github.com/LiamFenneman/Project3

Team name: The Floor is Java

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


|  Date  |         Objectives       |                                        Task                                       |
|:------:|:-------------------------:|:---------------------------------------------------------------------------------:|
|  2 Jun | Planning                  | Get plan done, Sort roles, Ensure all members have code working.                  |
|  6 Jun | Core                      | Finish core with documentation/testing. Discuss steps to take for completion.     |
|  9 Jun | Discussion for Completion | Address difficulties / challenges encountered so far.                             |
| 12 Jun | Wiki Discussion Update    | Wiki Discussion is due on this day.                                               |
| 13 Jun | Completion                | Completion finished with docs/testing. Discuss approach for challenge.            |
| 16 Jun | Discussion for Challenge  | Discuss problems with Challenge.                                                  |
| 19 Jun | Hand in Finished Project  | Challenge finished. Everything is documented/tested. Wiki discussion is also due. |
| 24 Jun | Report Due                | Submit report.                                                                    |

---

### Installation Instructions (Windows 10)

**Required Programs:**
- [Geany](https://www.geany.org/download/releases/)
- [7Zip](https://www.7-zip.org/)
    - Other uncompression software will work if they can handle `.7z` files and you know how to use that software to uncompress `.7z` files.

**Optional Programs:**
- [GitHub Desktop](https://desktop.github.com/)
    - **OR** [Git](https://git-scm.com/) *(if familiar with **git** commands)*

**Installation:**
1. Download [Geany](https://www.geany.org/download/releases/) for Windows. Run the installer and keep all the default options.
1. Download [7Zip](https://www.7-zip.org/) version 19.00 for Windows. Run the installer and keep all the default options.
1. Install MinGW (32-bit) and SFML 2.5.1:
    - **Option 1:** via Direct Downloads: [MinGW](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/7.3.0/threads-posix/dwarf/i686-7.3.0-release-posix-dwarf-rt_v5-rev0.7z/download) & [SFML](https://www.sfml-dev.org/files/SFML-2.5.1-windows-gcc-7.3.0-mingw-32-bit.zip).
    - **Option 2:** *(only if **Option 1** doesn't work)* Go to the [SFML website](https://www.sfml-dev.org/download/sfml/2.5.1/) and click "MinGW Builds 7.3.0 (32-bit)" and download button next to "GCC 7.3.0 MinGW (DW2) - 32-bit". 
1. Select the two downloaded files. Right-Click one of the files and go to "7Zip" -> "Extract Here".
![image of extracting the files](/install_instructions/images/5.png)
1. Select the two folders that were created *("mingw32" & "SFML-2.5.1")* and right-click one of the folders and select "Cut". Then go to the root of your C drive (type `C:\` into the address bar of File Explorer) and right-click the empty space at the bottom and click "Paste". Rename "SFML-2.5.1" to "SFML". The folders should now appear within the root C drive.
![image of folder structure](/install_instructions/images/1.png)
1. Search for "Environment Variables" in the Windows start menu and open the control panel "Edit the system environement variables".
1. Click the button at the bottom called "Environment Variables" and double click on "Path".
1. Add a new entry with `C:\\mingw32\bin`.
![image of environment variables](/install_instructions/images/2.png)
1. Restart your computer for the changes to be made.
1. Clone respoitory somewhere on computer. *(e.g. Desktop, Documents or GitHub folders)* using GitHub Desktop *(or via git)*
1. In the files that was added to your computer, delete the files, `robot.o`, `robot.exe`, `server3.o`, and `server3.exe`.
1. [Download *makefiles.7z*](/install_instructions/makefiles.7z) and open the file with 7Zip *(Right-click -> 7Zip -> Open archive)*.
1. Drag the two folders inside the archive *("AVC_robot" & "AVC_server")* and drag them into your root "Project3" folder *(where you cloned the repo)*.
![image of makefiles](/install_instructions/images/6.png)
1. Ensure the first line of each makefile contains the path to the SFML folder.
    - If following the instructions this should be: `DIR = C:\\SFML`.
1. Open `server3.cpp` and `robot.cpp` in Geany.
1. Click the "Build" tab at the top OR the dropdown next to the "Build" button and select "Set Build Commands".
1. Ensure the "Independant Commands" -> "Make" is set to `mingw32-make`.
![image of independant commands](/install_instructions/images/3.png)
1. To compile the program click the dropdown next to the "Build" button and click "Make All" (**OR** press `Shift+F9`).
![image of make all button](/install_instructions/images/4.png)
1. Run the program by clicking the "Execute" button on `server3.cpp` and wait until, the command line comes up with "Listening" then click on execute `robot.cpp` (**OR** press `F5`).

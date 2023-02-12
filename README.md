# Introduction to DirectX11

![img](http://d3dcoder.net/Images/bookcover4.jpg)

- This is a unofficial repository for Frank D. Luna's book [Introduction to 3D Game Programming using DirectX11](http://d3dcoder.net/d3d11.htm).

---

## Motivation

- The book has been published for a long time and much of the much of the officially provided source code is deprecated.
- At the time this project was initialized (January 2023), much of the provided source code is difficult to run on version 10 or later of the Windows platform.
- This project has been modified in several places to run on Windows operating systems from version 10 onwards and by the Visual Studio 2019 community.

---

## License

- The copyright of the modified source code in this repository is still attributed to Frank D.Luna.
- The copyright policy for the newly created source code follows the MIT license policy.

---

## Development Environment

### System Information

> *You can check your system information using the [systeminfo](https://learn.microsoft.com/en-us/windows-server/administration/windows-commands/systeminfo) command by running Windows Powershell or a command prompt.* 
>
> Alternatively, you can run [dxdiag](https://support.microsoft.com/en-us/windows/open-and-run-dxdiag-exe-dad7792c-2ad5-f6cd-5a37-bf92228dfd85) to examine your system information.

- Operating System:   Windows 11 Pro 64-bit (10.0, Build 22621) (22621.ni_release.220506-1250)
- Processor:                AMD Ryzen 7 2700X Eight-Core Processor          (16 CPUs), ~3.7GHz
- Memory:                   32768MB RAM
- Card name:              NVIDIA GeForce GTX 1070

### Integrated development environment (IDE)

- Microsoft Visual Studio Community 2019 version 16.11.23

### Language

- C++ 20

---

## Changes

### In Solution Scope

- Avoiding use "using namespace std".
- Use fixed-length integer types instead of unfixed integer types.
  - See CoreTypes.h in CoreLibrary.
- Use RAII Pettern.
  - c++ standard smart pointers and ComPtr.
- 

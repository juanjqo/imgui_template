![Static Badge](https://img.shields.io/badge/Platform-Apple_silicon-magenta)![Static Badge](https://img.shields.io/badge/Ubuntu_x64-orange)![Static Badge](https://img.shields.io/badge/Windows_11_x64-blue)![Static Badge](https://img.shields.io/badge/backend-glfw_opengl3-green)




# Imgui_template



## MacOS requirements

```shell
brew install glfw
brew install fmt
brew install eigen
```

## Ubuntu requirements

```shell
sudo apt-get update
sudo apt install xorg-dev
sudo apt install libwayland-dev libxkbcommon-dev wayland-protocols extra-cmake-modules
sudo apt install cmake g++ libeigen3-dev fakeroot

```

## Windows requirements

###  Visual Studio Development Kit[](https://visualstudio.microsoft.com/es/)

### Install [vcpkg](https://vcpkg.io/en/)

Create a folder 'Tools' in 'C': 'C:\Tools'

```shell
cd C:\Tools
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg; .\bootstrap-vcpkg.bat
.\vcpkg.exe integrate install
```

```shell
.\vcpkg.exe install opengl  
.\vcpkg.exe install eigen3:x64-windows
```


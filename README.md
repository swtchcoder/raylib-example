# Example raylib project

This is an example project using raylib


## Build

### Windows

1. Download `w64devkit-x.xx.x.zip` from https://github.com/skeeto/w64devkit/releases
> Unzip to `C:\w64devkit`

2. Download `raylib-5.0_win64_mingw-w64.zip` from https://github.com/raysan5/raylib/releases
> Unzip include and lib to `C:\w64devkit\x86_64-w64-mingw32`

3. Goto `C:\w64devkit` run `w64devkit.exe`，which launches a console

4. Goto project's directory in `w64devkit.exe` console

5. Compile in `w64devkit.exe` console
> `make build`

6. Run:
> `bin/executable.exe`


### GNU Linux

1. Install required tools
> `sudo apt install build-essential git`

2. Install required dependencies
> `sudo apt install libasound2-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev libxinerama-dev libwayland-dev libxkbcommon-dev`

3. Build raylib
> ```
> git clone --depth 1 https://github.com/raysan5/raylib.git raylib
> cd raylib/src/
> make PLATFORM=PLATFORM_DESKTOP
> make install
> ```

4. Goto project's directory

5. Compile project
> `make build`

6. Run
> `bin/executable`

# GraceEnhancer

Audio processor plugin for OBS streaming.

## Installation

### Option 1: MSI Installer
Double-click `GraceEnhancerInstaller.msi` to install. The plugin will be placed in:
```
C:\Program Files\Common Files\VST3\
```

### Option 2: Manual
Copy `GraceEnhancer.vst3` to:
```
C:\Program Files\Common Files\VST3\
```

## OBS Setup

1. **Restart OBS** after installation
2. Add a new **Audio Input Capture** or **Audio Output Capture** source
3. Click the gear icon → **Filters**
4. Add **VST Plugin** filter
5. Select **GraceEnhancer** from the dropdown
6. Configure audio effects as needed

## Features

- EQ
- Compressor
- Limiter
- Stereo balance
- Gain control

## Building from Source

### Prerequisites
- JUCE framework
- CMake 3.15+
- Visual Studio with C++ support

### Build Commands
```cmd
cd GraceEnhancer
mkdir Build
cd Build
cmake .. -G "NMake Makefiles"
cmake --build . --config Release
```

### Build Installer
```cmd
cd Installer
candle GraceEnhancerInstaller.wxs
light GraceEnhancerInstaller.wixobj -o GraceEnhancerInstaller.msi
```

## Support

Manufacturer: GraceOnline

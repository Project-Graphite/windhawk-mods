# TaskTune

TaskTune embeds media information and controls directly in the Windows 11
taskbar. It uses Windows media sessions for playback control and can fall back to active audio sessions for applications that play sound without publishing media metadata.

## Features

- More than 20 taskbar and system-tray placements, including multi-monitor support
- Album art, title and artist text, configurable transport controls, and scrolling text
- Configurable rewind/forward interval with accessible control names and tooltips
- Per-application volume and mute controls for media and audio-only applications
- Session switching, configurable mouse actions, and a compact mini-player
- Double-click anywhere on the player to open Spotify or another configured app
- Fluent solid, gradient, Acrylic, Mica, and album-art backgrounds
- Optional WASAPI spectrum visualizer with configurable shapes, colors, and EQ presets
- Automatic hiding when media is unavailable, the taskbar is idle, or an app is full-screen
- Extensive sizing, spacing, color, typography, animation, and empty-state settings

The overview and usage guide appear on Windhawk's **Details** tab. The complete configuration is available on the **Settings** tab after installation.

## Requirements

- Windows 11 on x86-64
- [Windhawk](https://windhawk.net/)
- A media application that exposes Windows System Media Transport Controls, or an application with an active Windows audio session

## Install

1. Install [Windhawk](https://windhawk.net/).
2. Open Windhawk and choose **Explore** → **Create a new mod**.
3. Copy [`tasktune.wh.cpp`](tasktune.wh.cpp) into the editor.
4. Select **Compile mod**.
5. Review the defaults in the mod's **Settings** tab and enable it.

## Settings

- **Main:** position, layout, playback controls, text, and visualizer.
- **Appearance:** colors, materials, fonts, icons, spacing, and sizing.
- **Behavior:** clicks, wheel actions, hiding, and the double-click app command.
- **Audio Apps:** audio-only detection, exclusions, and per-app volume.
- **Player Menu:** menu placement, animation, background, and session list.
- **Context Menu:** items, order, icons, and repeat/shuffle behavior.

The default double-click command is `spotify:`. Replace it with another URI, executable, full path,
or `shell:AppsFolder` ID if needed.

Because the mod runs inside `explorer.exe`, test changes through Windhawk and keep another way to restart Explorer available while developing.

## Project

TaskTune is created and maintained by
[AmrMsCLL](https://github.com/AmrMsCLL) as part of Project Graphite. It is available under the MIT license.

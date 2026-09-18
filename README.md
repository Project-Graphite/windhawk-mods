# Windhawk Mods

A Project Graphite collection of native Windows customizations built with
[Windhawk](https://windhawk.net/).

Windhawk is an open-source marketplace and framework for modifying Windows programs. It compiles reviewable C++ mods locally and loads them into only the processes they target, allowing focused customization without replacing system files or installing a separate background application.

This collection is where Amr develops small, inspectable improvements to Windows workflows. Each mod has its own source, settings and documentation so it can be understood and maintained on its own as Windows evolves.

## Mods

### TaskTune

[TaskTune](mods/tasktune/README.md) embeds customizable media
controls in the Windows 11 taskbar, including Spotify launch by double-click, per-app volume,
audio-only app support, session switching, Fluent backgrounds, multi-monitor placement, and an
optional spectrum visualizer.

### StackSwitch

[StackSwitch](mods/stack-switch/README.md) adds a taskbar panel that starts and stops a configurable working set of applications, folders, editor workspaces, URLs and terminal commands with one action.

## Installing

1. Install [Windhawk](https://windhawk.net/).
2. Open Windhawk and choose **Explore** → **Create a new mod**.
3. Replace the editor contents with the mod's `.wh.cpp` source file.
4. Select **Compile mod**.

## Repository layout

Every mod lives at `mods/<mod-id>/` and contains `<mod-id>.wh.cpp` plus a `README.md`. The folder, source filename and Windhawk `@id` must match.

## License

[MIT](LICENSE).

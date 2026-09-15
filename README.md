# Windhawk Mods

Windhawk mods for Windows 11, maintained by [Project Graphite](https://github.com/Project-Graphite).

[Windhawk](https://windhawk.net/) is a customization marketplace for Windows. A mod is a single
C++ file that Windhawk compiles and injects into a running process.

## Mods

### Tech Stack Launcher

[`mods/tech-stack-launcher.wh.cpp`](mods/tech-stack-launcher.wh.cpp)

Adds a button to the taskbar that opens a launcher panel. Tick what you want, press **Launch**,
and it all comes up in order. Press **Close** and it goes back down.

It can start applications, folders, URLs, VS Code workspaces, and commands in a terminal or with
no window at all. Per-item toggles persist across reboots, so something you only need
occasionally stays switched off until the day you want it.

- **Groups** file items under collapsible headings
- **Profiles** switch the whole selection in one click
- **Ordering** through per-item delays, a global stagger and wait-for-exit
- **Close** shuts the same selection down in reverse order, politely first
- **Sign-in** can bring a profile up shortly after you log in
- Eight taskbar placements, a global hotkey, an optional tray icon
- Panel styled after VS Code's Dark Modern and Light Modern themes

The button is a layered child window of the taskbar rather than a XAML injection, so it needs no
symbol resolution and does not break when Windows updates.

Full documentation lives in the mod's own readme block, shown on the **Details** tab once the mod
is installed.

## Installing

1. Install [Windhawk](https://windhawk.net/).
2. Open Windhawk and choose **Explore** → **Create a new mod**.
3. Replace the contents of the editor with the mod file.
4. Press **Compile mod**.

## Contributing

Issues and pull requests are welcome. Mods here follow the conventions of the official
[windhawk-mods](https://github.com/ramensoftware/windhawk-mods) collection: one file per mod at
`mods/<mod-id>.wh.cpp`, where the file name matches the mod's `@id`, and the shared
`.clang-format` for style.

## License

[MIT](LICENSE).

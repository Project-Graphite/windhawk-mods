# StackSwitch

StackSwitch adds a button to the Windows taskbar for starting and stopping an entire working set.
Select the items you need, choose **Launch**, and StackSwitch opens them in order. Choose **Close** to shut down that same selection in reverse order.

It supports applications, folders, URLs, Visual Studio Code workspaces, and commands in a terminal or without a visible window. Per-item selections persist across restarts, so optional tools remain off until they are needed.

## Features

- Groups under collapsible headings
- Named profiles that change the full selection in one action
- Per-item delays, a global launch stagger and wait-for-exit behavior
- Graceful reverse-order shutdown with a force-close fallback
- Optional profile launch after signing in
- Eight taskbar placements, a global hotkey and an optional tray icon
- Dark and light panel themes that follow the Windows app theme

The button uses a layered child window of the taskbar rather than XAML injection, avoiding fragile Windows symbol resolution. The complete settings reference is embedded in the source and appears on Windhawk's **Details** tab after installation.

## Install

1. Install [Windhawk](https://windhawk.net/).
2. Open Windhawk and choose **Explore** → **Create a new mod**.
3. Copy [`stack-switch.wh.cpp`](stack-switch.wh.cpp) into the editor.
4. Select **Compile mod**.

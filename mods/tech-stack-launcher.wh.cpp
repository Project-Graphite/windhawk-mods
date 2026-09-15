// ==WindhawkMod==
// @id              tech-stack-launcher
// @name            Tech Stack Launcher
// @description     A taskbar button that starts and stops your whole working set - apps, folders, editors, URLs and terminal commands - with per-item toggles, groups and profiles
// @version         2.2.0
// @author          Amr
// @license         MIT
// @github          https://github.com/AmrMsCLL
// @homepage        https://github.com/Project-Graphite/windhawk-mods
// @include         explorer.exe
// @architecture    x86-64
// @compilerOptions -lcomctl32 -ldwmapi -lgdi32 -lgdiplus -lole32 -lshell32 -lshlwapi -luser32 -luuid -ladvapi32
// ==/WindhawkMod==

// ==WindhawkModReadme==
/*
# Tech Stack Launcher

A button on the taskbar that opens a launcher panel. Tick what you want, press
**Launch**, and it all comes up in order. Press **Close** and it goes back down.

Everything here is driven by the settings, so the same mod works for a web stack,
a games project, a writing setup or a machine you just want opening the same six
things every morning.

---

## Quick start

1. Set **Root folder** to wherever your projects live, for example `C:\Git`.
2. Add one **Stack item** per thing you want to open.
3. Give the items you use together the same **Profile** name, and list that name
   in **Profiles** so it gets a chip in the panel.
4. Press the taskbar button, or `Ctrl+Alt+S`.

---

## How an item's settings are laid out

Windhawk draws the settings page itself and has no collapsing, so each item keeps its
six everyday fields at the top - **Name**, **On by default**, **Type**, **Target**,
**Group**, **Profiles** - and files the rest under three sub-headings:

| Sub-heading | Holds |
| --- | --- |
| **Launch options** | Arguments, working folder, shell, keep terminal open, run as administrator, window state |
| **Timing and safety** | Skip if already running, process name, delay, wait for exit, ask before launching |
| **Appearance** | Subtitle, icon |

Every one of those has a sensible default, so a normal item only needs the six at the
top.

## Item types

| Type | What it opens | Example target |
| --- | --- | --- |
| `app` | Any executable, document or shortcut | `C:\Program Files\Docker\Docker\Docker Desktop.exe` |
| `vscode` | A folder or `.code-workspace` in VS Code | `{root}\my-project` |
| `folder` | A folder in File Explorer | `{root}\my-project\docs` |
| `url` | A URL in the default browser | `http://localhost:3000` |
| `terminal` | A command in a visible terminal | `npm run dev` |
| `command` | A command with no window at all | `wsl --shutdown` |

**Target** is read according to the type. For `terminal` and `command` it is the
command line itself, run through the shell picked in **Shell**.

A PowerShell or pwsh command is handed over base64-encoded, so semicolons, pipes,
quotes and braces all survive exactly as written - a one-liner like
`Get-ChildItem | ForEach-Object { Write-Host $_.Name; $_ }` needs no escaping. For
`cmd`, Git Bash and WSL the command is passed as text, so a double quote inside a
Git Bash or WSL command is escaped for you, but the shell's own rules still apply.

---

## Paths and tokens

`{root}` expands to the **Root folder** setting, so `{root}\my-project` saves
repeating the full path in every item. Environment variables are expanded too, so
`%USERPROFILE%\Downloads` and `%LOCALAPPDATA%` work anywhere a path is accepted.

---

## Groups and collapsing

**Group** files an item under a heading. Click a heading to collapse or expand it,
and the state is remembered. The word on the right of a heading toggles every item
in that group at once: if any of them is off it turns them all on, otherwise it
turns them all off.

Items with the same group name are always listed together under one heading, no
matter where they sit in the settings, so the list stays tidy however you add to it.

---

## Reordering

Drag an item to move it within its group, or drag a group heading to move the whole
group. The same moves are on the right click menu of any item or heading, and
`Alt+Up` / `Alt+Down` move the highlighted item.

**Launch order follows the panel**, so dragging changes what starts first.

A mod cannot write to its own Windhawk settings, so the order you drag is stored
separately and the settings page keeps listing items as you typed them. The two
disagreeing is harmless - the panel wins for display and for launching. **Reset
order to settings**, on either right click menu, throws the override away and goes
back to the settings order.

---

## Profiles

A profile is a named set. Put the name in an item's **Profiles** field, list the
name in the global **Profiles** setting, and it appears as a chip at the top of the
panel.

Clicking a chip turns on exactly the items carrying that name and turns off
everything else. The `All` chip resets every toggle back to its **On by default**
value. Example: an item with `daily, full` comes on for the `daily` chip and the
`full` chip, and goes off for `backend`.

---

## The panel, button by button

**Taskbar button** - left or right click opens and closes the panel. Its look
comes from **Button style**, **Button icon** and **Button label**; where it sits
comes from **Button position**, **Button offset**, **Button percent** and **Button
alignment**.

**Gear, top right** - opens Windhawk so you can edit these settings.

**Profile chips** - switch the whole selection in one click, as above.

**Search box** - filters on name, group, subtitle and target as you type.
`Backspace` corrects, the small x clears, `Esc` clears and then closes the panel.

**Group heading** - click to collapse or expand. The word on the right toggles the
whole group.

**Item row** - clicking the name launches that one item immediately, whatever its
toggle says. Right click gives *Launch now*, *Close now* when it is running,
*Turn on* / *Turn off*, *Show in File Explorer* and *Copy target*.

**Item toggle** - includes or excludes the item from Launch and Close. The state
survives reboots, so something you only need occasionally can sit switched off
until the day you want it.

**Green dot** - that item's process is running right now.

**Footer icons, left to right** - select all, select none, refresh the running
dots.

**Close N** - closes the selected items that are currently running, in reverse
order. The number is how many are up.

**Launch N** - launches every selected item, top to bottom. The number is how many
are selected.

**Cancel** - replaces both buttons during a run and stops after the current item.

---

## Keyboard

| Key | Does |
| --- | --- |
| any character | filters the list |
| `Backspace` | corrects the filter |
| `Esc` | clears the filter, then closes the panel |
| `Up` / `Down` | moves the highlight |
| `Home` / `End` | first / last item |
| `Page Up` / `Page Down` | scrolls |
| `Enter` | launches the highlighted item |
| `Space` | toggles the highlighted item |
| `Ctrl+Enter` | launches the whole selection |
| `Ctrl+A` / `Ctrl+D` | select all / select none |

---

## Ordering a launch

Items launch top to bottom in the order they are listed.

* **Delay before launch** waits before one specific item.
* **Stagger** waits between every pair of items.
* **Wait for it to exit** holds the rest of the sequence until that item closes.

Example: put Docker Desktop at the top, then give the `docker compose up` item
below it a 20000 ms delay so the daemon is ready before compose runs. Use **Wait
for it to exit** only for steps that genuinely finish, such as a migration - a
normal app would stall the launch forever.

---

## Closing

Close works on exactly the same selection as Launch, in reverse order, so the
things everything else depends on go down last.

It asks each item's windows to close, waits out **Seconds to wait for each item to
close**, and only terminates a process when **Force close** is on. Force close is
off by default because it loses unsaved work.

An item needs a process before it can be closed:

* `app` and `vscode` items resolve one on their own.
* `terminal` and `command` items need **Process name** filled in. A terminal
  running a dev server is usually `node.exe`, for instance, not the shell.
* An item started as administrator cannot be closed from a normal Explorer, and
  a console window has nothing to close politely - that one needs **Force close**.

---

## Placement on the taskbar

**Button position** picks what the button anchors to, and **Button offset** nudges
it from there in pixels. Negative offsets move the other way.

| Position | Anchors to |
| --- | --- |
| Taskbar left edge | the far left |
| Taskbar centre | the middle of the taskbar |
| Taskbar right edge | the far right |
| Left of the tray | just before the clock and tray icons |
| Right of the tray | just inside the tray area |
| Left of the task buttons | just before the pinned and running icons |
| Right of the task buttons | just after them |
| Percentage across | wherever **Button percent** says |

The tray and task button anchors read the taskbar's own layout. If a future
Windows build stops reporting it, they fall back to the nearest edge, and the
percentage anchor always works.

**Button alignment** and **Button vertical offset** control the height within the
taskbar.

---

## Window state, and where it does not apply

**Window state** works as written for `app`, `vscode`, `folder` and `url` items.

For a `terminal` item it is not that simple. Windows hands every new console to
whichever terminal is set as the default - Windows Terminal, unless you changed it -
and that host ignores the requested state entirely. So **Minimized** and
**Maximized** on a terminal item are applied after the window appears, which has
two consequences:

* the item gets its **own** Windows Terminal window rather than joining the shared
  one, because minimizing a shared window would take every other tab with it
* the state is applied a moment after launch, so the window may flicker into view
  first

**Wait for it to exit** also forces a terminal item out of Windows Terminal. `wt.exe`
exits the instant it hands the tab over, so waiting on it would return immediately;
the item is launched in the shell's own console instead, where the wait is real.

---

## Sign-in

**Profile to run at sign-in** brings a profile up shortly after you log in. It only
fires when Explorer genuinely just started, so editing or reloading this mod never
relaunches anything, and **Only once per day** stops an afternoon reboot doing it
twice.

---

## Appearance

The panel follows VS Code's colours - Dark Modern and Light Modern - and picks
between them from your Windows app theme unless **Theme** says otherwise.

* **Accent colour** - empty uses VS Code blue, `system` uses your Windows accent,
  or give it a hex colour such as `#4C8DFF`.
* **Font** and **Text size** - the panel defaults to Segoe UI at 13px, the same as
  VS Code's interface.
* **Animation** - off, subtle, normal or lively.
* **Compact rows** - drops the subtitle line and fits about a third more items.

---

## Icons

Leave **Icon** empty and the item uses its target's real shell icon. Otherwise:

* a Segoe Fluent Icons code point, four to six hex digits, such as `E768`
* a single emoji
* a full path to an `.exe` or `.ico` to pull the icon out of
*/
// ==/WindhawkModReadme==

// ==WindhawkModSettings==
/*
- rootPath: C:\Git
  $name: Root folder
  $description: The folder {root} expands to. See Details for the full reference.
- profiles: [daily, work, full]
  $name: Profiles
  $description: Profile names to show as chips at the top of the panel.
- items:
  - - name: My project
      $name: Name
      $description: Label shown in the panel.
    - enabled: true
      $name: On by default
      $description: Starting state of the toggle. Only read the first time.
    - type: vscode
      $name: Type
      $description: How Target is interpreted.
      $options:
      - app: Application, document or shortcut
      - vscode: Folder or workspace in VS Code
      - folder: Folder in File Explorer
      - url: URL in the default browser
      - terminal: Command in a terminal window
      - command: Command with no window
    - target: '{root}\my-project'
      $name: Target
      $description: A path, a URL, or a command line for the terminal and command types.
    - group: Editors
      $name: Group
      $description: Heading to file this item under. Keep a group's items together.
    - profiles: daily, full
      $name: Profiles
      $description: Comma separated profile names this item belongs to.
    - launch:
      - args: ""
        $name: Arguments
        $description: Extra arguments appended after Target.
      - workingDir: '{root}'
        $name: Working folder
        $description: Folder the item starts in.
      - shell: powershell
        $name: Shell
        $description: Shell used by the terminal and command types.
        $options:
        - powershell: Windows PowerShell
        - pwsh: PowerShell 7
        - cmd: Command Prompt
        - gitbash: Git Bash
        - wsl: WSL
      - keepOpen: true
        $name: Keep the terminal open
        $description: Leave the window up after the command finishes.
      - elevated: false
        $name: Run as administrator
        $description: Start it elevated. Elevated items cannot be closed again.
      - windowState: normal
        $name: Window state
        $description: How the window comes up.
        $options:
        - normal: Normal
        - minimized: Minimized
        - maximized: Maximized
        - hidden: Hidden
      $name: Launch options
      $description: How this item starts. The defaults suit most items.
    - control:
      - singleInstance: true
        $name: Skip if already running
        $description: Skip this item during a launch when its process is already up.
      - processName: ""
        $name: Process name
        $description: Executable used for the running dot and for closing. Empty auto-detects.
      - delayMs: 0
        $name: Delay before launch (ms)
        $description: Extra wait before starting this one item.
      - waitForExit: false
        $name: Wait for it to exit
        $description: Hold the rest of the sequence until this item closes.
      - confirm: false
        $name: Ask before launching
        $description: Prompt before this one item runs.
      $name: Timing and safety
      $description: Where this item sits in a sequence, and how it is found and closed.
    - display:
      - description: ""
        $name: Subtitle
        $description: Optional second line. Empty shows the target instead.
      - icon: ""
        $name: Icon
        $description: Empty uses the target's own icon. Or a glyph code, an emoji, or an icon file.
      $name: Appearance
      $description: How this item looks in the panel.
  $name: Stack items
  $description: Everything the launcher can start, in launch order. An empty name ends the list.
- panelTitle: Stack
  $name: Panel title
  $description: Heading shown at the top of the panel.
- staggerMs: 400
  $name: Stagger between items (ms)
  $description: Pause between every pair of items during a launch.
- terminalHost: auto
  $name: Terminal host
  $description: Where terminal items open. Auto groups them into one Windows Terminal window.
  $options:
  - auto: Auto
  - wt: Always Windows Terminal
  - shell: Always the shell's own console
- wtWindowId: _stack
  $name: Windows Terminal window
  $description: Window name the tabs go to. Use 0 for the last used, or new each time.
- vscodePath: ""
  $name: VS Code path
  $description: Empty auto-detects the usual install locations.
- gitBashPath: ""
  $name: Git Bash path
  $description: Empty auto-detects. Point it at Git's bash.exe.
- hotkey: Ctrl+Alt+S
  $name: Hotkey
  $description: Opens the panel from anywhere. Empty for none.
- showTaskbarButton: true
  $name: Show the taskbar button
  $description: Turn off to drive the launcher from the hotkey or tray icon only.
- buttonPosition: beforeTray
  $name: Button position
  $description: What the button anchors to. See Details.
  $options:
  - left: Taskbar left edge
  - center: Taskbar centre
  - right: Taskbar right edge
  - beforeTray: Left of the tray
  - afterTray: Right of the tray
  - beforeTaskList: Left of the task buttons
  - afterTaskList: Right of the task buttons
  - percent: Percentage across the taskbar
- buttonOffset: 8
  $name: Button offset (px)
  $description: Pixels from the anchor. Negative moves the other way.
- buttonPercent: 50
  $name: Button percent
  $description: Position across the taskbar, for the percentage anchor.
- buttonAlign: middle
  $name: Button alignment
  $description: Vertical placement within the taskbar.
  $options:
  - top: Top
  - middle: Middle
  - bottom: Bottom
- buttonOffsetY: 0
  $name: Button vertical offset (px)
  $description: Nudge up or down from that alignment.
- buttonStyle: glyphLabel
  $name: Button style
  $description: Whether the button shows its icon, its label, or both.
  $options:
  - glyphLabel: Icon and label
  - glyph: Icon only
  - label: Label only
- buttonGlyph: E768
  $name: Button icon
  $description: A Segoe Fluent Icons code point, an emoji, or short text.
- buttonLabel: Stack
  $name: Button label
  $description: Text shown next to the icon.
- showTrayIcon: false
  $name: Also show a tray icon
  $description: Adds a notification area icon with a launch menu.
- showOnSecondaryTaskbars: false
  $name: Show on secondary taskbars
  $description: Put a button on other monitors' taskbars too.
- theme: auto
  $name: Theme
  $description: Panel colours follow VS Code's Dark Modern and Light Modern.
  $options:
  - auto: Follow Windows
  - dark: Dark
  - light: Light
- accentColor: ""
  $name: Accent colour
  $description: Empty uses VS Code blue. Use system for the Windows accent, or a hex colour.
- fontFamily: Segoe UI
  $name: Font
  $description: UI font for the panel and the taskbar button.
- fontSize: 13
  $name: Text size (px)
  $description: Base text size. Everything else scales from it.
- animation: normal
  $name: Animation
  $description: Speed of the panel, hover, Toggle and collapse animations.
  $options:
  - off: Off
  - subtle: Subtle
  - normal: Normal
  - lively: Lively
- panelWidth: 400
  $name: Panel width (px)
  $description: Raise it if long names are being cut off.
- panelMaxHeight: 640
  $name: Panel maximum height (px)
  $description: The panel shrinks to fit and scrolls past this.
- compactRows: false
  $name: Compact rows
  $description: Drop the subtitle line and fit about a third more items.
- showStatusDots: true
  $name: Show running indicators
  $description: Green dot on items whose process is up.
- closeAfterLaunch: true
  $name: Close the panel after launching
  $description: Hide the panel as soon as something starts.
- confirmBeforeLaunchAll: false
  $name: Confirm before launching a batch
  $description: Ask before the Launch button runs the whole selection.
- showCloseButton: true
  $name: Show the Close button
  $description: Closes the same selection Launch would start, in reverse.
- confirmBeforeClose: true
  $name: Confirm before closing
  $description: Ask before the Close button runs.
- closeGraceSeconds: 15
  $name: Seconds to wait for each item to close
  $description: How long to give each item to shut down before moving on.
- forceCloseAfterGrace: false
  $name: Force close if it does not shut down
  $description: Terminates the process afterwards. Loses unsaved work.
- autoRunProfile: ""
  $name: Profile to run at sign-in
  $description: Runs this profile after Explorer starts. Empty disables it.
- autoRunDelaySeconds: 15
  $name: Sign-in delay (seconds)
  $description: How long to wait after Explorer starts.
- autoRunOncePerDay: true
  $name: Only once per day
  $description: Stops a second reboot starting everything again.
*/
// ==/WindhawkModSettings==

#include <windhawk_utils.h>

#undef min
#undef max
#include <algorithm>
using std::max;
using std::min;

#include <objidl.h>

#include <gdiplus.h>

#include <commctrl.h>
#include <dwmapi.h>
#include <shellapi.h>
#include <shlwapi.h>
#include <tlhelp32.h>
#include <windowsx.h>

#include <atomic>
#include <cmath>
#include <condition_variable>
#include <deque>
#include <functional>
#include <memory>
#include <mutex>
#include <string>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace gp = Gdiplus;

constexpr PCWSTR kButtonClass = L"WhTechStackLauncherButton";
constexpr PCWSTR kPanelClass = L"WhTechStackLauncherPanel";
constexpr PCWSTR kMessageClass = L"WhTechStackLauncherMessages";

constexpr UINT kMsgTogglePanel = WM_APP + 1;
constexpr UINT kMsgLaunchProgress = WM_APP + 2;
constexpr UINT kMsgLaunchFinished = WM_APP + 3;
constexpr UINT kMsgStatusReady = WM_APP + 4;
constexpr UINT kMsgIconReady = WM_APP + 5;
constexpr UINT kMsgTrayCallback = WM_APP + 6;
constexpr UINT kMsgReloadSettings = WM_APP + 7;
constexpr UINT kMsgButtonRefresh = WM_APP + 9;
constexpr UINT kMsgButtonClose = WM_APP + 10;

constexpr UINT_PTR kTimerButtonLayout = 1;
constexpr UINT_PTR kTimerCaret = 2;
constexpr UINT_PTR kTimerStatus = 3;
constexpr UINT_PTR kTimerAutoRun = 4;
constexpr UINT_PTR kTimerAnimate = 5;

constexpr UINT kFrameMs = 16;
constexpr int kHotkeyId = 0x5701;
constexpr UINT kTrayIconId = 1;

enum class ItemType { App, VSCode, Folder, Url, Terminal, Command };
enum class ShellKind { PowerShell, Pwsh, Cmd, GitBash, Wsl };
enum class WindowStateOption { Normal, Minimized, Maximized, Hidden };
enum class ButtonPosition {
    Left,
    Center,
    Right,
    BeforeTray,
    AfterTray,
    BeforeTaskList,
    AfterTaskList,
    Percent,
};
enum class ButtonAlign { Top, Middle, Bottom };
enum class ButtonStyle { Glyph, GlyphLabel, Label };
enum class ThemeMode { Auto, Dark, Light };
enum class TerminalHost { Auto, WindowsTerminal, Shell };

struct StackItem {
    std::wstring name;
    std::wstring description;
    std::wstring group;
    std::wstring profiles;
    std::wstring target;
    std::wstring args;
    std::wstring workingDir;
    std::wstring icon;
    std::wstring processName;
    ItemType type = ItemType::App;
    ShellKind shell = ShellKind::PowerShell;
    WindowStateOption windowState = WindowStateOption::Normal;
    bool defaultEnabled = true;
    bool keepOpen = true;
    bool elevated = false;
    bool singleInstance = true;
    bool waitForExit = false;
    bool confirm = false;
    int delayMs = 0;
    std::wstring storageKey;
    bool enabled = true;
    bool running = false;
};

struct Settings {
    std::wstring rootPath;
    std::vector<std::wstring> profiles;
    std::vector<StackItem> items;
    std::wstring panelTitle;
    int staggerMs = 400;
    TerminalHost terminalHost = TerminalHost::Auto;
    std::wstring wtWindowId;
    std::wstring vscodePath;
    std::wstring gitBashPath;
    std::wstring hotkey;
    bool showTaskbarButton = true;
    ButtonPosition buttonPosition = ButtonPosition::BeforeTray;
    int buttonOffset = 8;
    int buttonPercent = 50;
    ButtonAlign buttonAlign = ButtonAlign::Middle;
    int buttonOffsetY = 0;
    ButtonStyle buttonStyle = ButtonStyle::GlyphLabel;
    std::wstring buttonGlyph;
    std::wstring buttonLabel;
    bool showTrayIcon = false;
    bool showOnSecondaryTaskbars = false;
    ThemeMode theme = ThemeMode::Auto;
    std::wstring accentColor;
    std::wstring fontFamily;
    int fontSize = 13;
    double animationSpeed = 1.0;
    int panelWidth = 400;
    int panelMaxHeight = 640;
    bool compactRows = false;
    bool showStatusDots = true;
    bool closeAfterLaunch = true;
    bool confirmBeforeLaunchAll = false;
    bool showCloseButton = true;
    bool confirmBeforeClose = true;
    int closeGraceSeconds = 15;
    bool forceCloseAfterGrace = false;
    std::wstring autoRunProfile;
    int autoRunDelaySeconds = 15;
    bool autoRunOncePerDay = true;
};

static Settings g_settings;
static std::recursive_mutex g_settingsMutex;

static ULONG_PTR g_gdiplusToken = 0;
static std::thread g_uiThread;
static std::atomic<bool> g_unloading{false};
static HWND g_messageWnd = nullptr;
static HWND g_panelWnd = nullptr;
static std::vector<HWND> g_buttonWnds;
static std::mutex g_buttonMutex;
static std::atomic<bool> g_panelOpen{false};
static std::atomic<bool> g_launching{false};
static std::atomic<bool> g_cancelLaunch{false};
static ULONGLONG g_panelHiddenTick = 0;
static std::atomic<UINT> g_dpi{96};
static bool g_trayIconAdded = false;
static HICON g_trayIcon = nullptr;
static UINT g_taskbarCreatedMessage = 0;

class TaskQueue {
   public:
    void Start() { m_thread = std::thread([this] { Run(); }); }

    void Post(std::function<void()> task) {
        {
            std::lock_guard<std::mutex> lock(m_mutex);
            if (m_stop) {
                return;
            }
            m_tasks.push_back(std::move(task));
        }
        m_condition.notify_one();
    }

    void Stop() {
        {
            std::lock_guard<std::mutex> lock(m_mutex);
            m_stop = true;
        }
        m_condition.notify_all();
        if (m_thread.joinable()) {
            m_thread.join();
        }
    }

   private:
    void Run() {
        for (;;) {
            std::function<void()> task;
            {
                std::unique_lock<std::mutex> lock(m_mutex);
                m_condition.wait(lock, [this] { return m_stop || !m_tasks.empty(); });
                if (m_stop) {
                    return;
                }
                task = std::move(m_tasks.front());
                m_tasks.pop_front();
            }
            task();
        }
    }

    std::thread m_thread;
    std::mutex m_mutex;
    std::condition_variable m_condition;
    std::deque<std::function<void()>> m_tasks;
    bool m_stop = false;
};

static TaskQueue g_backgroundQueue;
static TaskQueue g_launchQueue;

static std::mutex g_iconMutex;
static std::unordered_map<std::wstring, HICON> g_iconCache;
static std::unordered_set<std::wstring> g_iconPending;

static std::wstring g_filter;
static int g_scrollOffset = 0;
static int g_focusRow = -1;
static std::wstring g_activeProfile;
static std::mutex g_statusMutex;
static std::wstring g_statusText;
static std::atomic<int> g_progressCurrent{0};
static std::atomic<int> g_progressTotal{0};
static bool g_caretVisible = true;
static bool g_suppressDeactivate = false;

static void SetStatusText(std::wstring text) {
    std::lock_guard<std::mutex> lock(g_statusMutex);
    g_statusText = std::move(text);
}

static std::wstring StatusText() {
    std::lock_guard<std::mutex> lock(g_statusMutex);
    return g_statusText;
}

static int Scale(int value) {
    return MulDiv(value, (int)g_dpi.load(), 96);
}

static std::atomic<double> g_animationSpeed{1.0};

static bool Approach(double& value, double target, double tau) {
    double speed = g_animationSpeed.load();
    if (speed <= 0.0) {
        value = target;
        return false;
    }
    value += (target - value) * (1.0 - exp(-(kFrameMs / 1000.0) * speed / tau));
    if (fabs(target - value) < 0.002) {
        value = target;
        return false;
    }
    return true;
}

static double Ease(double amount) {
    return amount * amount * (3.0 - 2.0 * amount);
}

static std::wstring Trim(std::wstring_view text) {
    size_t begin = text.find_first_not_of(L" \t\r\n");
    if (begin == std::wstring_view::npos) {
        return std::wstring();
    }
    return std::wstring(
        text.substr(begin, text.find_last_not_of(L" \t\r\n") - begin + 1));
}

static std::wstring ToLower(std::wstring_view text) {
    std::wstring result(text);
    std::transform(result.begin(), result.end(), result.begin(),
                   [](wchar_t c) { return (wchar_t)towlower(c); });
    return result;
}

static std::vector<std::wstring> SplitList(std::wstring_view text, wchar_t separator) {
    std::vector<std::wstring> result;
    size_t start = 0;
    while (start <= text.size()) {
        size_t next = text.find(separator, start);
        if (next == std::wstring_view::npos) {
            next = text.size();
        }
        std::wstring piece = Trim(text.substr(start, next - start));
        if (!piece.empty()) {
            result.push_back(std::move(piece));
        }
        start = next + 1;
    }
    return result;
}

static bool ListContains(std::wstring_view list, std::wstring_view value) {
    std::wstring wanted = ToLower(value);
    for (const auto& entry : SplitList(list, L',')) {
        if (ToLower(entry) == wanted) {
            return true;
        }
    }
    return false;
}

static bool ContainsNoCase(std::wstring_view haystack, std::wstring_view needle) {
    if (needle.empty()) {
        return true;
    }
    return ToLower(haystack).find(ToLower(needle)) != std::wstring::npos;
}

static std::wstring HashKey(PCWSTR prefix, std::wstring_view text) {
    unsigned long long hash = 1469598103934665603ULL;
    for (wchar_t c : ToLower(text)) {
        hash ^= (unsigned long long)c;
        hash *= 1099511628211ULL;
    }
    wchar_t buffer[32];
    swprintf_s(buffer, L"%s%016llx", prefix, hash);
    return buffer;
}

static std::wstring ExpandTokens(std::wstring_view raw) {
    std::wstring text(raw);
    std::wstring root;
    {
        std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
        root = g_settings.rootPath;
    }
    for (;;) {
        size_t position = ToLower(text).find(L"{root}");
        if (position == std::wstring::npos) {
            break;
        }
        text.replace(position, 6, root);
    }
    if (text.find(L'%') == std::wstring::npos) {
        return text;
    }
    DWORD needed = ExpandEnvironmentStringsW(text.c_str(), nullptr, 0);
    if (needed == 0) {
        return text;
    }
    std::wstring expanded(needed, L'\0');
    DWORD written = ExpandEnvironmentStringsW(text.c_str(), expanded.data(), needed);
    if (written == 0 || written > needed) {
        return text;
    }
    expanded.resize(written - 1);
    return expanded;
}

static std::wstring QuoteIfNeeded(std::wstring_view text) {
    if (text.empty() || text.find(L' ') == std::wstring_view::npos ||
        text.front() == L'"') {
        return std::wstring(text);
    }
    return L"\"" + std::wstring(text) + L"\"";
}

static std::wstring FileNameOf(std::wstring_view path) {
    size_t slash = path.find_last_of(L"\\/");
    return std::wstring(slash == std::wstring_view::npos ? path
                                                         : path.substr(slash + 1));
}

static bool FileExists(const std::wstring& path) {
    return !path.empty() && PathFileExistsW(path.c_str());
}

static ItemType ParseItemType(PCWSTR value) {
    if (wcscmp(value, L"vscode") == 0) return ItemType::VSCode;
    if (wcscmp(value, L"folder") == 0) return ItemType::Folder;
    if (wcscmp(value, L"url") == 0) return ItemType::Url;
    if (wcscmp(value, L"terminal") == 0) return ItemType::Terminal;
    if (wcscmp(value, L"command") == 0) return ItemType::Command;
    return ItemType::App;
}

static ShellKind ParseShellKind(PCWSTR value) {
    if (wcscmp(value, L"pwsh") == 0) return ShellKind::Pwsh;
    if (wcscmp(value, L"cmd") == 0) return ShellKind::Cmd;
    if (wcscmp(value, L"gitbash") == 0) return ShellKind::GitBash;
    if (wcscmp(value, L"wsl") == 0) return ShellKind::Wsl;
    return ShellKind::PowerShell;
}

static WindowStateOption ParseWindowState(PCWSTR value) {
    if (wcscmp(value, L"minimized") == 0) return WindowStateOption::Minimized;
    if (wcscmp(value, L"maximized") == 0) return WindowStateOption::Maximized;
    if (wcscmp(value, L"hidden") == 0) return WindowStateOption::Hidden;
    return WindowStateOption::Normal;
}

static ButtonPosition ParseButtonPosition(PCWSTR value) {
    if (wcscmp(value, L"left") == 0) return ButtonPosition::Left;
    if (wcscmp(value, L"center") == 0) return ButtonPosition::Center;
    if (wcscmp(value, L"right") == 0) return ButtonPosition::Right;
    if (wcscmp(value, L"afterTray") == 0) return ButtonPosition::AfterTray;
    if (wcscmp(value, L"beforeTaskList") == 0) return ButtonPosition::BeforeTaskList;
    if (wcscmp(value, L"afterTaskList") == 0) return ButtonPosition::AfterTaskList;
    if (wcscmp(value, L"percent") == 0) return ButtonPosition::Percent;
    return ButtonPosition::BeforeTray;
}

static double ParseAnimationSpeed(PCWSTR value) {
    if (wcscmp(value, L"off") == 0) return 0.0;
    if (wcscmp(value, L"subtle") == 0) return 0.65;
    if (wcscmp(value, L"lively") == 0) return 1.7;
    return 1.0;
}

static void LoadSettings() {
    Settings loaded;

    loaded.rootPath = Trim(WindhawkUtils::StringSetting::make(L"rootPath").get());

    for (int i = 0;; i++) {
        auto profile = WindhawkUtils::StringSetting::make(L"profiles[%d]", i);
        if (!*profile) {
            break;
        }
        std::wstring trimmed = Trim(profile.get());
        if (!trimmed.empty()) {
            loaded.profiles.push_back(std::move(trimmed));
        }
    }

    for (int i = 0;; i++) {
        auto name = WindhawkUtils::StringSetting::make(L"items[%d].name", i);
        if (!*name) {
            break;
        }
        StackItem item;
        item.name = Trim(name.get());
        item.description = Trim(
            WindhawkUtils::StringSetting::make(L"items[%d].display.description", i)
                .get());
        item.group =
            Trim(WindhawkUtils::StringSetting::make(L"items[%d].group", i).get());
        item.profiles =
            Trim(WindhawkUtils::StringSetting::make(L"items[%d].profiles", i).get());
        item.type = ParseItemType(
            WindhawkUtils::StringSetting::make(L"items[%d].type", i).get());
        item.target =
            Trim(WindhawkUtils::StringSetting::make(L"items[%d].target", i).get());
        item.args = Trim(
            WindhawkUtils::StringSetting::make(L"items[%d].launch.args", i).get());
        item.workingDir = Trim(
            WindhawkUtils::StringSetting::make(L"items[%d].launch.workingDir", i)
                .get());
        item.shell = ParseShellKind(
            WindhawkUtils::StringSetting::make(L"items[%d].launch.shell", i).get());
        item.icon = Trim(
            WindhawkUtils::StringSetting::make(L"items[%d].display.icon", i).get());
        item.processName = Trim(
            WindhawkUtils::StringSetting::make(L"items[%d].control.processName", i)
                .get());
        item.windowState = ParseWindowState(
            WindhawkUtils::StringSetting::make(L"items[%d].launch.windowState", i)
                .get());
        item.defaultEnabled = Wh_GetIntSetting(L"items[%d].enabled", i) != 0;
        item.keepOpen = Wh_GetIntSetting(L"items[%d].launch.keepOpen", i) != 0;
        item.elevated = Wh_GetIntSetting(L"items[%d].launch.elevated", i) != 0;
        item.singleInstance =
            Wh_GetIntSetting(L"items[%d].control.singleInstance", i) != 0;
        item.waitForExit = Wh_GetIntSetting(L"items[%d].control.waitForExit", i) != 0;
        item.confirm = Wh_GetIntSetting(L"items[%d].control.confirm", i) != 0;
        item.delayMs = max(0, Wh_GetIntSetting(L"items[%d].control.delayMs", i));
        item.storageKey =
            HashKey(L"en_", item.group + L"|" + item.name + L"|" + item.target);
        item.enabled =
            Wh_GetIntValue(item.storageKey.c_str(), item.defaultEnabled ? 1 : 0) != 0;
        loaded.items.push_back(std::move(item));
    }

    loaded.panelTitle = Trim(WindhawkUtils::StringSetting::make(L"panelTitle").get());
    loaded.staggerMs = max(0, Wh_GetIntSetting(L"staggerMs"));

    auto terminalHost = WindhawkUtils::StringSetting::make(L"terminalHost");
    loaded.terminalHost =
        wcscmp(terminalHost, L"wt") == 0      ? TerminalHost::WindowsTerminal
        : wcscmp(terminalHost, L"shell") == 0 ? TerminalHost::Shell
                                              : TerminalHost::Auto;

    loaded.wtWindowId = Trim(WindhawkUtils::StringSetting::make(L"wtWindowId").get());
    loaded.vscodePath = Trim(WindhawkUtils::StringSetting::make(L"vscodePath").get());
    loaded.gitBashPath = Trim(WindhawkUtils::StringSetting::make(L"gitBashPath").get());
    loaded.hotkey = Trim(WindhawkUtils::StringSetting::make(L"hotkey").get());

    loaded.showTaskbarButton = Wh_GetIntSetting(L"showTaskbarButton") != 0;
    loaded.buttonPosition = ParseButtonPosition(
        WindhawkUtils::StringSetting::make(L"buttonPosition").get());
    loaded.buttonOffset = Wh_GetIntSetting(L"buttonOffset");
    loaded.buttonPercent = max(0, min(100, Wh_GetIntSetting(L"buttonPercent")));

    auto buttonAlign = WindhawkUtils::StringSetting::make(L"buttonAlign");
    loaded.buttonAlign = wcscmp(buttonAlign, L"top") == 0      ? ButtonAlign::Top
                         : wcscmp(buttonAlign, L"bottom") == 0 ? ButtonAlign::Bottom
                                                               : ButtonAlign::Middle;
    loaded.buttonOffsetY = Wh_GetIntSetting(L"buttonOffsetY");

    auto buttonStyle = WindhawkUtils::StringSetting::make(L"buttonStyle");
    loaded.buttonStyle = wcscmp(buttonStyle, L"glyph") == 0   ? ButtonStyle::Glyph
                         : wcscmp(buttonStyle, L"label") == 0 ? ButtonStyle::Label
                                                              : ButtonStyle::GlyphLabel;

    loaded.buttonGlyph = Trim(WindhawkUtils::StringSetting::make(L"buttonGlyph").get());
    loaded.buttonLabel = Trim(WindhawkUtils::StringSetting::make(L"buttonLabel").get());
    loaded.showTrayIcon = Wh_GetIntSetting(L"showTrayIcon") != 0;
    loaded.showOnSecondaryTaskbars = Wh_GetIntSetting(L"showOnSecondaryTaskbars") != 0;

    auto theme = WindhawkUtils::StringSetting::make(L"theme");
    loaded.theme = wcscmp(theme, L"dark") == 0    ? ThemeMode::Dark
                   : wcscmp(theme, L"light") == 0 ? ThemeMode::Light
                                                  : ThemeMode::Auto;

    loaded.accentColor = Trim(WindhawkUtils::StringSetting::make(L"accentColor").get());
    loaded.fontFamily = Trim(WindhawkUtils::StringSetting::make(L"fontFamily").get());
    loaded.fontSize = max(9, min(22, Wh_GetIntSetting(L"fontSize")));
    loaded.animationSpeed =
        ParseAnimationSpeed(WindhawkUtils::StringSetting::make(L"animation").get());
    loaded.panelWidth = max(280, Wh_GetIntSetting(L"panelWidth"));
    loaded.panelMaxHeight = max(240, Wh_GetIntSetting(L"panelMaxHeight"));
    loaded.compactRows = Wh_GetIntSetting(L"compactRows") != 0;
    loaded.showStatusDots = Wh_GetIntSetting(L"showStatusDots") != 0;
    loaded.closeAfterLaunch = Wh_GetIntSetting(L"closeAfterLaunch") != 0;
    loaded.confirmBeforeLaunchAll = Wh_GetIntSetting(L"confirmBeforeLaunchAll") != 0;
    loaded.showCloseButton = Wh_GetIntSetting(L"showCloseButton") != 0;
    loaded.confirmBeforeClose = Wh_GetIntSetting(L"confirmBeforeClose") != 0;
    loaded.closeGraceSeconds = max(0, Wh_GetIntSetting(L"closeGraceSeconds"));
    loaded.forceCloseAfterGrace = Wh_GetIntSetting(L"forceCloseAfterGrace") != 0;
    loaded.autoRunProfile =
        Trim(WindhawkUtils::StringSetting::make(L"autoRunProfile").get());
    loaded.autoRunDelaySeconds = max(0, Wh_GetIntSetting(L"autoRunDelaySeconds"));
    loaded.autoRunOncePerDay = Wh_GetIntSetting(L"autoRunOncePerDay") != 0;

    if (loaded.fontFamily.empty()) {
        loaded.fontFamily = L"Segoe UI";
    }

    g_animationSpeed = loaded.animationSpeed;

    std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
    g_settings = std::move(loaded);
}

static bool CancellableSleep(int milliseconds) {
    while (milliseconds > 0) {
        if (g_unloading || g_cancelLaunch) {
            return false;
        }
        int slice = min(milliseconds, 50);
        Sleep((DWORD)slice);
        milliseconds -= slice;
    }
    return !g_unloading && !g_cancelLaunch;
}

using ProcessMap = std::unordered_map<std::wstring, std::vector<DWORD>>;

static ProcessMap SnapshotProcesses() {
    ProcessMap processes;
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot == INVALID_HANDLE_VALUE) {
        return processes;
    }
    PROCESSENTRY32W entry{};
    entry.dwSize = sizeof(entry);
    if (Process32FirstW(snapshot, &entry)) {
        do {
            processes[ToLower(entry.szExeFile)].push_back(entry.th32ProcessID);
        } while (Process32NextW(snapshot, &entry));
    }
    CloseHandle(snapshot);
    return processes;
}

static std::vector<DWORD> StillRunning(const std::vector<DWORD>& pids) {
    std::vector<DWORD> alive;
    if (pids.empty()) {
        return alive;
    }
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot == INVALID_HANDLE_VALUE) {
        return pids;
    }
    PROCESSENTRY32W entry{};
    entry.dwSize = sizeof(entry);
    if (Process32FirstW(snapshot, &entry)) {
        do {
            if (std::find(pids.begin(), pids.end(), entry.th32ProcessID) != pids.end()) {
                alive.push_back(entry.th32ProcessID);
            }
        } while (Process32NextW(snapshot, &entry));
    }
    CloseHandle(snapshot);
    return alive;
}

static int PostCloseToProcess(DWORD pid) {
    struct EnumContext {
        DWORD pid;
        int posted;
    };
    EnumContext context{pid, 0};
    EnumWindows(
        [](HWND window, LPARAM param) CALLBACK -> BOOL {
            auto* context = reinterpret_cast<EnumContext*>(param);
            DWORD owner = 0;
            GetWindowThreadProcessId(window, &owner);
            if (owner == context->pid && IsWindowVisible(window) &&
                !GetWindow(window, GW_OWNER)) {
                PostMessageW(window, WM_CLOSE, 0, 0);
                context->posted++;
            }
            return TRUE;
        },
        reinterpret_cast<LPARAM>(&context));
    return context.posted;
}

static bool TerminateProcessById(DWORD pid) {
    HANDLE process = OpenProcess(PROCESS_TERMINATE, FALSE, pid);
    if (!process) {
        return false;
    }
    BOOL terminated = TerminateProcess(process, 0);
    CloseHandle(process);
    return terminated != FALSE;
}

static std::wstring FindVSCode();

static std::wstring ResolveDuplicateProcessName(const StackItem& item) {
    if (!item.processName.empty()) {
        std::wstring name = ToLower(item.processName);
        if (name.find(L".exe") == std::wstring::npos) {
            name += L".exe";
        }
        return name;
    }
    if (item.type != ItemType::App) {
        return std::wstring();
    }
    std::wstring file = ToLower(FileNameOf(ExpandTokens(item.target)));
    if (file.size() > 4 && file.compare(file.size() - 4, 4, L".exe") == 0) {
        return file;
    }
    return std::wstring();
}

static std::wstring ResolveProcessName(const StackItem& item) {
    std::wstring name = ResolveDuplicateProcessName(item);
    if (!name.empty() || item.type != ItemType::VSCode) {
        return name;
    }
    return ToLower(FileNameOf(FindVSCode()));
}

static std::wstring FindFirstExisting(std::initializer_list<PCWSTR> candidates) {
    for (PCWSTR candidate : candidates) {
        std::wstring path = ExpandTokens(candidate);
        if (FileExists(path)) {
            return path;
        }
    }
    return std::wstring();
}

static std::wstring FindVSCode() {
    {
        std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
        if (!g_settings.vscodePath.empty()) {
            return ExpandTokens(g_settings.vscodePath);
        }
    }
    return FindFirstExisting({
        L"%LOCALAPPDATA%\\Programs\\Microsoft VS Code\\Code.exe",
        L"%ProgramFiles%\\Microsoft VS Code\\Code.exe",
        L"%ProgramFiles(x86)%\\Microsoft VS Code\\Code.exe",
        L"%LOCALAPPDATA%\\Programs\\Microsoft VS Code Insiders\\Code - Insiders.exe",
    });
}

static std::wstring FindGitBash() {
    {
        std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
        if (!g_settings.gitBashPath.empty()) {
            return ExpandTokens(g_settings.gitBashPath);
        }
    }
    return FindFirstExisting({
        L"%ProgramFiles%\\Git\\bin\\bash.exe",
        L"%ProgramFiles(x86)%\\Git\\bin\\bash.exe",
        L"%LOCALAPPDATA%\\Programs\\Git\\bin\\bash.exe",
    });
}

static std::wstring FindWindowsTerminal() {
    return FindFirstExisting(
        {L"%LOCALAPPDATA%\\Microsoft\\WindowsApps\\wt.exe"});
}

static std::wstring FindWindhawk() {
    return FindFirstExisting({L"%ProgramFiles%\\Windhawk\\windhawk.exe"});
}

struct ShellInvocation {
    std::wstring file;
    std::wstring args;
};

static std::wstring EncodeUtf16Base64(const std::wstring& text) {
    static constexpr wchar_t kAlphabet[] =
        L"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    const BYTE* bytes = reinterpret_cast<const BYTE*>(text.data());
    size_t length = text.size() * sizeof(wchar_t);
    std::wstring encoded;
    encoded.reserve((length + 2) / 3 * 4);
    for (size_t i = 0; i < length; i += 3) {
        unsigned value = (unsigned)bytes[i] << 16;
        if (i + 1 < length) {
            value |= (unsigned)bytes[i + 1] << 8;
        }
        if (i + 2 < length) {
            value |= (unsigned)bytes[i + 2];
        }
        encoded += kAlphabet[(value >> 18) & 0x3F];
        encoded += kAlphabet[(value >> 12) & 0x3F];
        encoded += i + 1 < length ? kAlphabet[(value >> 6) & 0x3F] : L'=';
        encoded += i + 2 < length ? kAlphabet[value & 0x3F] : L'=';
    }
    return encoded;
}

static std::wstring EscapeDoubleQuotes(const std::wstring& text) {
    std::wstring escaped;
    for (wchar_t character : text) {
        if (character == L'"') {
            escaped += L'\\';
        }
        escaped += character;
    }
    return escaped;
}

static std::wstring EscapeSemicolons(const std::wstring& text) {
    std::wstring escaped;
    for (wchar_t character : text) {
        if (character == L';') {
            escaped += L'\\';
        }
        escaped += character;
    }
    return escaped;
}

static bool BuildShellInvocation(const StackItem& item,
                                 const std::wstring& command,
                                 bool visible,
                                 ShellInvocation& out) {
    bool keepOpen = visible && item.keepOpen;
    switch (item.shell) {
        case ShellKind::Cmd:
            out.file = L"cmd.exe";
            out.args = (keepOpen ? L"/k " : L"/c ") + command;
            return true;
        case ShellKind::GitBash: {
            out.file = FindGitBash();
            if (out.file.empty()) {
                return false;
            }
            out.args = L"-l -c \"" + EscapeDoubleQuotes(command) +
                       (keepOpen ? L"; exec bash\"" : L"\"");
            return true;
        }
        case ShellKind::Wsl:
            out.file = L"wsl.exe";
            out.args = L"-- bash -lc \"" + EscapeDoubleQuotes(command) +
                       (keepOpen ? L"; exec bash\"" : L"\"");
            return true;
        case ShellKind::Pwsh:
        default:
            out.file = item.shell == ShellKind::Pwsh ? L"pwsh.exe" : L"powershell.exe";
            out.args = keepOpen ? L"-NoLogo -NoExit -EncodedCommand "
                                : L"-NoLogo -EncodedCommand ";
            out.args += EncodeUtf16Base64(command);
            return true;
    }
}

static bool WrapInWindowsTerminal(const StackItem& item,
                                  const std::wstring& workingDir,
                                  ShellInvocation& invocation) {
    TerminalHost host;
    std::wstring windowId;
    {
        std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
        host = g_settings.terminalHost;
        windowId = g_settings.wtWindowId;
    }
    if (host == TerminalHost::Shell) {
        return false;
    }
    std::wstring terminal = FindWindowsTerminal();
    if (terminal.empty()) {
        return false;
    }
    bool ownWindow = item.windowState == WindowStateOption::Minimized ||
                     item.windowState == WindowStateOption::Maximized;

    std::wstring args;
    if (ownWindow) {
        args += L"-w new ";
    } else if (!windowId.empty() && ToLower(windowId) != L"new") {
        args += L"-w " + QuoteIfNeeded(windowId) + L" ";
    }
    args += L"new-tab --title " + QuoteIfNeeded(item.name);
    if (!workingDir.empty()) {
        args += L" -d " + QuoteIfNeeded(workingDir);
    }
    args += L" " + QuoteIfNeeded(invocation.file) + L" " +
            EscapeSemicolons(invocation.args);
    invocation.file = terminal;
    invocation.args = std::move(args);
    return true;
}

static bool WindowBelongsToProcess(HWND window, PCWSTR exeName) {
    DWORD pid = 0;
    GetWindowThreadProcessId(window, &pid);
    if (!pid) {
        return false;
    }
    HANDLE process =
        OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, pid);
    if (!process) {
        return false;
    }
    wchar_t path[MAX_PATH] = {};
    DWORD size = ARRAYSIZE(path);
    bool matches = QueryFullProcessImageNameW(process, 0, path, &size) &&
                   _wcsicmp(FileNameOf(path).c_str(), exeName) == 0;
    CloseHandle(process);
    return matches;
}

static void ApplyTerminalWindowState(const std::wstring& title, int showCommand) {
    struct EnumContext {
        const std::wstring* title;
        HWND found;
    };
    for (int attempt = 0; attempt < 24 && !g_unloading; attempt++) {
        EnumContext context{&title, nullptr};
        EnumWindows(
            [](HWND window, LPARAM param) CALLBACK -> BOOL {
                auto* context = reinterpret_cast<EnumContext*>(param);
                if (!IsWindowVisible(window) || GetWindow(window, GW_OWNER) ||
                    !WindowBelongsToProcess(window, L"WindowsTerminal.exe")) {
                    return TRUE;
                }
                wchar_t text[512] = {};
                GetWindowTextW(window, text, ARRAYSIZE(text));
                if (wcsstr(text, context->title->c_str())) {
                    context->found = window;
                    return FALSE;
                }
                return TRUE;
            },
            reinterpret_cast<LPARAM>(&context));
        if (context.found) {
            ShowWindow(context.found, showCommand);
            return;
        }
        Sleep(250);
    }
}

struct LaunchPlan {
    std::wstring file;
    std::wstring args;
    std::wstring workingDir;
    std::wstring adjustWindowTitle;
    int showCommand = SW_SHOWNORMAL;
    bool elevated = false;
    bool hidden = false;
};

static bool BuildLaunchPlan(const StackItem& item, LaunchPlan& plan) {
    std::wstring target = ExpandTokens(item.target);
    std::wstring args = ExpandTokens(item.args);
    plan.workingDir = ExpandTokens(item.workingDir);
    plan.elevated = item.elevated;

    switch (item.windowState) {
        case WindowStateOption::Minimized:
            plan.showCommand = SW_SHOWMINNOACTIVE;
            break;
        case WindowStateOption::Maximized:
            plan.showCommand = SW_SHOWMAXIMIZED;
            break;
        case WindowStateOption::Hidden:
            plan.showCommand = SW_HIDE;
            break;
        default:
            plan.showCommand = SW_SHOWNORMAL;
            break;
    }

    switch (item.type) {
        case ItemType::App:
        case ItemType::Folder:
        case ItemType::Url:
            if (target.empty()) {
                return false;
            }
            plan.file = target;
            plan.args = args;
            if (plan.workingDir.empty() && item.type == ItemType::App) {
                size_t slash = target.find_last_of(L"\\/");
                if (slash != std::wstring::npos) {
                    plan.workingDir = target.substr(0, slash);
                }
            }
            return true;

        case ItemType::VSCode: {
            std::wstring code = FindVSCode();
            if (code.empty() || target.empty()) {
                return false;
            }
            plan.file = code;
            plan.args = QuoteIfNeeded(target);
            if (!args.empty()) {
                plan.args += L" " + args;
            }
            return true;
        }

        case ItemType::Terminal:
        case ItemType::Command: {
            std::wstring command = target;
            if (!args.empty()) {
                command += L" " + args;
            }
            if (command.empty()) {
                return false;
            }
            bool visible = item.type == ItemType::Terminal &&
                           item.windowState != WindowStateOption::Hidden;
            ShellInvocation invocation;
            if (!BuildShellInvocation(item, command, visible, invocation)) {
                return false;
            }
            if (visible && !item.waitForExit &&
                WrapInWindowsTerminal(item, plan.workingDir, invocation) &&
                (item.windowState == WindowStateOption::Minimized ||
                 item.windowState == WindowStateOption::Maximized)) {
                plan.adjustWindowTitle = item.name;
            }
            plan.file = invocation.file;
            plan.args = invocation.args;
            plan.hidden = !visible;
            if (plan.hidden) {
                plan.showCommand = SW_HIDE;
            }
            return true;
        }
    }
    return false;
}

static bool LaunchPlanNow(const LaunchPlan& plan, HANDLE* outProcess) {
    if (plan.hidden && !plan.elevated) {
        std::wstring commandLine = QuoteIfNeeded(plan.file);
        if (!plan.args.empty()) {
            commandLine += L" " + plan.args;
        }
        STARTUPINFOW startup{};
        startup.cb = sizeof(startup);
        startup.dwFlags = STARTF_USESHOWWINDOW;
        startup.wShowWindow = SW_HIDE;
        PROCESS_INFORMATION process{};
        std::vector<wchar_t> buffer(commandLine.begin(), commandLine.end());
        buffer.push_back(L'\0');
        if (!CreateProcessW(nullptr, buffer.data(), nullptr, nullptr, FALSE,
                            CREATE_NO_WINDOW, nullptr,
                            plan.workingDir.empty() ? nullptr
                                                    : plan.workingDir.c_str(),
                            &startup, &process)) {
            return false;
        }
        CloseHandle(process.hThread);
        if (outProcess) {
            *outProcess = process.hProcess;
        } else {
            CloseHandle(process.hProcess);
        }
        return true;
    }

    SHELLEXECUTEINFOW info{};
    info.cbSize = sizeof(info);
    info.fMask = SEE_MASK_NOCLOSEPROCESS | SEE_MASK_FLAG_NO_UI;
    info.lpVerb = plan.elevated ? L"runas" : nullptr;
    info.lpFile = plan.file.c_str();
    info.lpParameters = plan.args.empty() ? nullptr : plan.args.c_str();
    info.lpDirectory = plan.workingDir.empty() ? nullptr : plan.workingDir.c_str();
    info.nShow = plan.showCommand;
    if (!ShellExecuteExW(&info)) {
        return false;
    }
    if (info.hProcess) {
        if (outProcess) {
            *outProcess = info.hProcess;
        } else {
            CloseHandle(info.hProcess);
        }
    }
    return true;
}

struct Palette {
    gp::Color background;
    gp::Color surface;
    gp::Color surfaceStrong;
    gp::Color border;
    gp::Color divider;
    gp::Color text;
    gp::Color textStrong;
    gp::Color textDim;
    gp::Color hover;
    gp::Color press;
    gp::Color selection;
    gp::Color accent;
    gp::Color accentHover;
    gp::Color accentText;
    gp::Color running;
    gp::Color scrollbar;
    bool dark = true;
};

static Palette g_palette;
static std::mutex g_paletteMutex;

static Palette CurrentPalette() {
    std::lock_guard<std::mutex> lock(g_paletteMutex);
    return g_palette;
}

static bool SystemUsesDarkMode() {
    HKEY key = nullptr;
    if (RegOpenKeyExW(HKEY_CURRENT_USER,
                      L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\"
                      L"Personalize",
                      0, KEY_QUERY_VALUE, &key) != ERROR_SUCCESS) {
        return true;
    }
    DWORD value = 0;
    DWORD size = sizeof(value);
    DWORD type = 0;
    LSTATUS status = RegQueryValueExW(key, L"AppsUseLightTheme", nullptr, &type,
                                      (LPBYTE)&value, &size);
    RegCloseKey(key);
    return status != ERROR_SUCCESS || type != REG_DWORD || value == 0;
}

static bool ParseHexColor(const std::wstring& text, gp::Color& color) {
    std::wstring digits = text;
    if (!digits.empty() && digits.front() == L'#') {
        digits.erase(0, 1);
    }
    if (digits.size() != 6) {
        return false;
    }
    wchar_t* end = nullptr;
    unsigned long value = wcstoul(digits.c_str(), &end, 16);
    if (end != digits.c_str() + 6) {
        return false;
    }
    color = gp::Color(255, (BYTE)(value >> 16), (BYTE)(value >> 8), (BYTE)value);
    return true;
}

static double Luminance(const gp::Color& color) {
    return (0.2126 * color.GetR() + 0.7152 * color.GetG() + 0.0722 * color.GetB()) /
           255.0;
}

static gp::Color Shift(const gp::Color& color, double amount) {
    auto mix = [amount](BYTE channel) {
        double target = amount > 0 ? 255.0 : 0.0;
        return (BYTE)(channel + (target - channel) * fabs(amount));
    };
    return gp::Color(color.GetA(), mix(color.GetR()), mix(color.GetG()),
                     mix(color.GetB()));
}

static gp::Color Fade(const gp::Color& color, double amount) {
    return gp::Color((BYTE)(color.GetA() * max(0.0, min(1.0, amount))), color.GetR(),
                     color.GetG(), color.GetB());
}

static gp::Color Blend(const gp::Color& from, const gp::Color& to, double amount) {
    double t = max(0.0, min(1.0, amount));
    auto mix = [t](BYTE a, BYTE b) { return (BYTE)(a + (b - a) * t); };
    return gp::Color(mix(from.GetA(), to.GetA()), mix(from.GetR(), to.GetR()),
                     mix(from.GetG(), to.GetG()), mix(from.GetB(), to.GetB()));
}

static gp::Color ResolveAccent(bool dark) {
    std::wstring choice;
    {
        std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
        choice = g_settings.accentColor;
    }
    gp::Color parsed;
    if (ParseHexColor(choice, parsed)) {
        return parsed;
    }
    if (ToLower(choice) == L"system") {
        DWORD colorization = 0;
        BOOL opaque = FALSE;
        if (SUCCEEDED(DwmGetColorizationColor(&colorization, &opaque))) {
            gp::Color accent(255, (BYTE)(colorization >> 16), (BYTE)(colorization >> 8),
                             (BYTE)colorization);
            if (dark && Luminance(accent) < 0.30) {
                accent = Shift(accent, 0.35);
            }
            if (!dark && Luminance(accent) > 0.70) {
                accent = Shift(accent, -0.35);
            }
            return accent;
        }
    }
    return dark ? gp::Color(255, 0x00, 0x78, 0xD4) : gp::Color(255, 0x00, 0x5F, 0xB8);
}

static Palette BuildPalette() {
    ThemeMode mode;
    {
        std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
        mode = g_settings.theme;
    }
    bool dark = mode == ThemeMode::Dark ||
                (mode == ThemeMode::Auto && SystemUsesDarkMode());

    Palette palette;
    palette.dark = dark;
    palette.accent = ResolveAccent(dark);
    palette.accentHover = Shift(palette.accent, dark ? 0.16 : 0.12);
    palette.accentText = Luminance(palette.accent) > 0.6
                             ? gp::Color(255, 0x1F, 0x1F, 0x1F)
                             : gp::Color(255, 0xFF, 0xFF, 0xFF);

    if (dark) {
        palette.background = gp::Color(247, 0x1F, 0x1F, 0x1F);
        palette.surface = gp::Color(255, 0x31, 0x31, 0x31);
        palette.surfaceStrong = gp::Color(255, 0x3C, 0x3C, 0x3C);
        palette.border = gp::Color(190, 0x3C, 0x3C, 0x3C);
        palette.divider = gp::Color(120, 0x3C, 0x3C, 0x3C);
        palette.text = gp::Color(255, 0xCC, 0xCC, 0xCC);
        palette.textStrong = gp::Color(255, 0xE7, 0xE7, 0xE7);
        palette.textDim = gp::Color(255, 0x9D, 0x9D, 0x9D);
        palette.hover = gp::Color(255, 0x2A, 0x2D, 0x2E);
        palette.press = gp::Color(255, 0x37, 0x3B, 0x3D);
        palette.selection = gp::Color(255, 0x04, 0x39, 0x5E);
        palette.running = gp::Color(255, 0x73, 0xC9, 0x91);
        palette.scrollbar = gp::Color(110, 0x79, 0x79, 0x79);
    } else {
        palette.background = gp::Color(249, 0xF8, 0xF8, 0xF8);
        palette.surface = gp::Color(255, 0xFF, 0xFF, 0xFF);
        palette.surfaceStrong = gp::Color(255, 0xF0, 0xF0, 0xF0);
        palette.border = gp::Color(220, 0xCE, 0xCE, 0xCE);
        palette.divider = gp::Color(160, 0xE5, 0xE5, 0xE5);
        palette.text = gp::Color(255, 0x3B, 0x3B, 0x3B);
        palette.textStrong = gp::Color(255, 0x1F, 0x1F, 0x1F);
        palette.textDim = gp::Color(255, 0x76, 0x76, 0x76);
        palette.hover = gp::Color(255, 0xF2, 0xF2, 0xF2);
        palette.press = gp::Color(255, 0xE4, 0xE4, 0xE4);
        palette.selection = gp::Color(255, 0xCF, 0xE3, 0xFA);
        palette.running = gp::Color(255, 0x38, 0x8A, 0x34);
        palette.scrollbar = gp::Color(110, 0x64, 0x64, 0x64);
    }
    return palette;
}

static void RefreshPalette() {
    Palette palette = BuildPalette();
    std::lock_guard<std::mutex> lock(g_paletteMutex);
    g_palette = palette;
}

class Surface {
   public:
    ~Surface() { Release(); }

    bool Resize(int width, int height) {
        if (width <= 0 || height <= 0) {
            return false;
        }
        if (m_width == width && m_height == height) {
            Clear();
            return true;
        }
        Release();

        BITMAPINFO info{};
        info.bmiHeader.biSize = sizeof(info.bmiHeader);
        info.bmiHeader.biWidth = width;
        info.bmiHeader.biHeight = -height;
        info.bmiHeader.biPlanes = 1;
        info.bmiHeader.biBitCount = 32;
        info.bmiHeader.biCompression = BI_RGB;

        HDC screen = GetDC(nullptr);
        m_dc = CreateCompatibleDC(screen);
        ReleaseDC(nullptr, screen);
        if (!m_dc) {
            return false;
        }
        m_bitmap = CreateDIBSection(m_dc, &info, DIB_RGB_COLORS, &m_bits, nullptr, 0);
        if (!m_bitmap) {
            Release();
            return false;
        }
        m_previousBitmap = (HBITMAP)SelectObject(m_dc, m_bitmap);
        m_width = width;
        m_height = height;
        m_clip = gp::Rect(0, 0, width, height);
        m_bitmapWrapper = std::make_unique<gp::Bitmap>(
            width, height, width * 4, PixelFormat32bppPARGB, (BYTE*)m_bits);
        m_graphics = std::make_unique<gp::Graphics>(m_bitmapWrapper.get());
        m_graphics->SetSmoothingMode(gp::SmoothingModeAntiAlias);
        m_graphics->SetPixelOffsetMode(gp::PixelOffsetModeHalf);
        m_graphics->SetInterpolationMode(gp::InterpolationModeHighQualityBicubic);
        Clear();
        return true;
    }

    void Clear() {
        if (m_bits) {
            memset(m_bits, 0, (size_t)m_width * m_height * 4);
        }
    }

    void Release() {
        ReleaseScratch();
        m_graphics.reset();
        m_bitmapWrapper.reset();
        if (m_dc) {
            if (m_previousBitmap) {
                SelectObject(m_dc, m_previousBitmap);
                m_previousBitmap = nullptr;
            }
            DeleteDC(m_dc);
            m_dc = nullptr;
        }
        if (m_bitmap) {
            DeleteObject(m_bitmap);
            m_bitmap = nullptr;
        }
        m_bits = nullptr;
        m_width = 0;
        m_height = 0;
    }

    gp::Graphics* Graphics() const { return m_graphics.get(); }
    HDC Dc() const { return m_dc; }

    void SetClip(const gp::Rect& clip) {
        m_clip = clip;
        if (m_graphics) {
            m_graphics->SetClip(clip);
        }
    }

    void ClearClip() {
        m_clip = gp::Rect(0, 0, m_width, m_height);
        if (m_graphics) {
            m_graphics->ResetClip();
        }
    }

    void RenderText(const std::wstring& text,
                    HFONT font,
                    const gp::Color& color,
                    const gp::Rect& box,
                    UINT format) {
        if (text.empty() || !font || !m_bits || box.Width <= 0 || box.Height <= 0 ||
            color.GetA() == 0) {
            return;
        }
        int left = max(max(box.X, m_clip.X), 0);
        int top = max(max(box.Y, m_clip.Y), 0);
        int right = min(min(box.X + box.Width, m_clip.X + m_clip.Width), m_width);
        int bottom = min(min(box.Y + box.Height, m_clip.Y + m_clip.Height), m_height);
        if (right <= left || bottom <= top || !EnsureScratch(box.Width, box.Height)) {
            return;
        }

        for (int y = 0; y < box.Height; y++) {
            memset(m_scratchBits + (size_t)y * m_scratchWidth * 4, 0,
                   (size_t)box.Width * 4);
        }
        HGDIOBJ previousFont = SelectObject(m_scratchDc, font);
        SetBkMode(m_scratchDc, TRANSPARENT);
        SetTextColor(m_scratchDc, RGB(255, 255, 255));
        RECT textRect{0, 0, box.Width, box.Height};
        DrawTextW(m_scratchDc, text.c_str(), (int)text.size(), &textRect, format);
        SelectObject(m_scratchDc, previousFont);
        GdiFlush();

        int colorAlpha = color.GetA();
        for (int y = top; y < bottom; y++) {
            const BYTE* source = m_scratchBits +
                                 (size_t)(y - box.Y) * m_scratchWidth * 4 +
                                 (size_t)(left - box.X) * 4;
            BYTE* target = (BYTE*)m_bits + (size_t)y * m_width * 4 + (size_t)left * 4;
            for (int x = left; x < right; x++, source += 4, target += 4) {
                int alpha = source[2] * colorAlpha / 255;
                if (alpha == 0) {
                    continue;
                }
                int inverse = 255 - alpha;
                target[0] = (BYTE)((color.GetB() * alpha + target[0] * inverse) / 255);
                target[1] = (BYTE)((color.GetG() * alpha + target[1] * inverse) / 255);
                target[2] = (BYTE)((color.GetR() * alpha + target[2] * inverse) / 255);
                target[3] = (BYTE)((255 * alpha + target[3] * inverse) / 255);
            }
        }
    }

    void Present(HWND window, BYTE opacity) {
        POINT source{0, 0};
        SIZE size{m_width, m_height};
        BLENDFUNCTION blend{AC_SRC_OVER, 0, opacity, AC_SRC_ALPHA};
        UpdateLayeredWindow(window, nullptr, nullptr, &size, m_dc, &source, 0, &blend,
                            ULW_ALPHA);
    }

   private:
    bool EnsureScratch(int width, int height) {
        if (m_scratchDc && m_scratchWidth >= width && m_scratchHeight >= height) {
            return true;
        }
        int wantedWidth = max(width, m_scratchWidth);
        int wantedHeight = max(height, m_scratchHeight);
        ReleaseScratch();

        BITMAPINFO info{};
        info.bmiHeader.biSize = sizeof(info.bmiHeader);
        info.bmiHeader.biWidth = wantedWidth;
        info.bmiHeader.biHeight = -wantedHeight;
        info.bmiHeader.biPlanes = 1;
        info.bmiHeader.biBitCount = 32;
        info.bmiHeader.biCompression = BI_RGB;

        HDC screen = GetDC(nullptr);
        m_scratchDc = CreateCompatibleDC(screen);
        ReleaseDC(nullptr, screen);
        if (!m_scratchDc) {
            return false;
        }
        void* bits = nullptr;
        m_scratchBitmap =
            CreateDIBSection(m_scratchDc, &info, DIB_RGB_COLORS, &bits, nullptr, 0);
        if (!m_scratchBitmap) {
            ReleaseScratch();
            return false;
        }
        m_scratchPreviousBitmap = (HBITMAP)SelectObject(m_scratchDc, m_scratchBitmap);
        m_scratchBits = (BYTE*)bits;
        m_scratchWidth = wantedWidth;
        m_scratchHeight = wantedHeight;
        return true;
    }

    void ReleaseScratch() {
        if (m_scratchDc) {
            if (m_scratchPreviousBitmap) {
                SelectObject(m_scratchDc, m_scratchPreviousBitmap);
                m_scratchPreviousBitmap = nullptr;
            }
            DeleteDC(m_scratchDc);
            m_scratchDc = nullptr;
        }
        if (m_scratchBitmap) {
            DeleteObject(m_scratchBitmap);
            m_scratchBitmap = nullptr;
        }
        m_scratchBits = nullptr;
        m_scratchWidth = 0;
        m_scratchHeight = 0;
    }

    HDC m_dc = nullptr;
    HBITMAP m_bitmap = nullptr;
    HBITMAP m_previousBitmap = nullptr;
    void* m_bits = nullptr;
    int m_width = 0;
    int m_height = 0;
    gp::Rect m_clip;
    std::unique_ptr<gp::Bitmap> m_bitmapWrapper;
    std::unique_ptr<gp::Graphics> m_graphics;

    HDC m_scratchDc = nullptr;
    HBITMAP m_scratchBitmap = nullptr;
    HBITMAP m_scratchPreviousBitmap = nullptr;
    BYTE* m_scratchBits = nullptr;
    int m_scratchWidth = 0;
    int m_scratchHeight = 0;
};

constexpr UINT kTextLeft =
    DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS | DT_NOPREFIX;
constexpr UINT kTextCenter =
    DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS | DT_NOPREFIX;

static std::mutex g_fontMutex;
static std::unordered_map<std::wstring, HFONT> g_fontCache;
static std::unordered_map<std::wstring, int> g_textWidthCache;

static const std::wstring& IconFontFamily() {
    static const std::wstring family = [] {
        gp::FontFamily fluent(L"Segoe Fluent Icons");
        return fluent.IsAvailable() ? std::wstring(L"Segoe Fluent Icons")
                                    : std::wstring(L"Segoe MDL2 Assets");
    }();
    return family;
}

static std::wstring FontKey(const std::wstring& family, int sizePx, bool bold) {
    wchar_t key[160];
    swprintf_s(key, L"%s|%d|%d", family.c_str(), sizePx, bold ? 1 : 0);
    return key;
}

static HFONT GetFont(const std::wstring& family, int sizePx, bool bold) {
    std::wstring key = FontKey(family, sizePx, bold);
    std::lock_guard<std::mutex> lock(g_fontMutex);
    auto found = g_fontCache.find(key);
    if (found != g_fontCache.end()) {
        return found->second;
    }
    LOGFONTW description{};
    description.lfHeight = -sizePx;
    description.lfWeight = bold ? FW_SEMIBOLD : FW_NORMAL;
    description.lfCharSet = DEFAULT_CHARSET;
    description.lfOutPrecision = OUT_TT_PRECIS;
    description.lfQuality = ANTIALIASED_QUALITY;
    description.lfPitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;
    wcscpy_s(description.lfFaceName, family.c_str());
    HFONT font = CreateFontIndirectW(&description);
    g_fontCache.emplace(key, font);
    return font;
}

static std::wstring UiFontFamily() {
    std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
    return g_settings.fontFamily;
}

static int BaseFontSize() {
    std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
    return g_settings.fontSize;
}

static HFONT UiFont(int delta = 0, bool bold = false) {
    return GetFont(UiFontFamily(), Scale(max(7, BaseFontSize() + delta)), bold);
}

static HFONT IconFont(int delta = 0) {
    return GetFont(IconFontFamily(), Scale(max(7, BaseFontSize() + delta)), false);
}

static void ClearFontCache() {
    std::lock_guard<std::mutex> lock(g_fontMutex);
    for (auto& entry : g_fontCache) {
        if (entry.second) {
            DeleteObject(entry.second);
        }
    }
    g_fontCache.clear();
    g_textWidthCache.clear();
}

static int MeasureText(const std::wstring& text, HFONT font) {
    if (text.empty() || !font) {
        return 0;
    }
    wchar_t prefix[24];
    swprintf_s(prefix, L"%p|", (void*)font);
    std::wstring key = prefix + text;
    {
        std::lock_guard<std::mutex> lock(g_fontMutex);
        auto found = g_textWidthCache.find(key);
        if (found != g_textWidthCache.end()) {
            return found->second;
        }
    }
    HDC screen = GetDC(nullptr);
    HDC dc = CreateCompatibleDC(screen);
    ReleaseDC(nullptr, screen);
    if (!dc) {
        return 0;
    }
    HGDIOBJ previousFont = SelectObject(dc, font);
    SIZE extent{};
    GetTextExtentPoint32W(dc, text.c_str(), (int)text.size(), &extent);
    SelectObject(dc, previousFont);
    DeleteDC(dc);
    std::lock_guard<std::mutex> lock(g_fontMutex);
    g_textWidthCache[key] = extent.cx;
    return extent.cx;
}

static void AddRoundRect(gp::GraphicsPath& path, const gp::RectF& rect, gp::REAL radius) {
    gp::REAL r = min(radius, min(rect.Width, rect.Height) / 2.0f);
    if (r <= 0.5f) {
        path.AddRectangle(rect);
        return;
    }
    gp::REAL diameter = r * 2;
    path.AddArc(rect.X, rect.Y, diameter, diameter, 180, 90);
    path.AddArc(rect.GetRight() - diameter, rect.Y, diameter, diameter, 270, 90);
    path.AddArc(rect.GetRight() - diameter, rect.GetBottom() - diameter, diameter,
                diameter, 0, 90);
    path.AddArc(rect.X, rect.GetBottom() - diameter, diameter, diameter, 90, 90);
    path.CloseFigure();
}

static gp::RectF ToRectF(const gp::Rect& rect) {
    return gp::RectF((gp::REAL)rect.X, (gp::REAL)rect.Y, (gp::REAL)rect.Width,
                     (gp::REAL)rect.Height);
}

static void FillRoundRect(gp::Graphics& graphics,
                          const gp::RectF& rect,
                          gp::REAL radius,
                          const gp::Color& color) {
    if (rect.Width <= 0 || rect.Height <= 0 || color.GetA() == 0) {
        return;
    }
    gp::GraphicsPath path;
    AddRoundRect(path, rect, radius);
    gp::SolidBrush brush(color);
    graphics.FillPath(&brush, &path);
}

static void StrokeRoundRect(gp::Graphics& graphics,
                            const gp::RectF& rect,
                            gp::REAL radius,
                            const gp::Color& color,
                            gp::REAL width) {
    if (rect.Width <= 0 || rect.Height <= 0 || color.GetA() == 0) {
        return;
    }
    gp::GraphicsPath path;
    AddRoundRect(path, gp::RectF(rect.X + width / 2, rect.Y + width / 2,
                                 rect.Width - width, rect.Height - width),
                 radius);
    gp::Pen pen(color, width);
    graphics.DrawPath(&pen, &path);
}

static void DrawShadow(gp::Graphics& graphics,
                       const gp::RectF& rect,
                       gp::REAL radius,
                       int spread,
                       double opacity) {
    for (int i = spread; i >= 1; i--) {
        gp::REAL grow = (gp::REAL)i;
        double falloff = 1.0 - (double)i / (spread + 1);
        BYTE alpha = (BYTE)max(1.0, 30.0 * falloff * falloff * opacity);
        FillRoundRect(graphics,
                      gp::RectF(rect.X - grow, rect.Y - grow + grow * 0.4f,
                                rect.Width + grow * 2, rect.Height + grow * 2),
                      radius + grow, gp::Color(alpha, 0, 0, 0));
    }
}

static void DrawChevron(gp::Graphics& graphics,
                        const gp::Rect& box,
                        double openAmount,
                        const gp::Color& color) {
    double centerX = box.X + box.Width / 2.0;
    double centerY = box.Y + box.Height / 2.0;
    double reach = Scale(4);
    double angle = (1.0 - openAmount) * (-90.0) * 3.14159265358979 / 180.0;
    double cosine = cos(angle);
    double sine = sin(angle);
    auto rotate = [&](double x, double y) {
        return gp::PointF((gp::REAL)(centerX + x * cosine - y * sine),
                          (gp::REAL)(centerY + x * sine + y * cosine));
    };
    gp::PointF points[3] = {rotate(-reach, -reach * 0.55), rotate(0, reach * 0.55),
                            rotate(reach, -reach * 0.55)};
    gp::Pen pen(color, max(1.2f, (gp::REAL)Scale(1000) / 700.0f));
    pen.SetStartCap(gp::LineCapRound);
    pen.SetEndCap(gp::LineCapRound);
    pen.SetLineJoin(gp::LineJoinRound);
    graphics.DrawLines(&pen, points, 3);
}

static void DrawIconImage(gp::Graphics& graphics, HICON icon, const gp::Rect& box) {
    ICONINFO iconInfo{};
    if (!GetIconInfo(icon, &iconInfo)) {
        return;
    }
    BITMAP colorBitmap{};
    if (!iconInfo.hbmColor ||
        !GetObjectW(iconInfo.hbmColor, sizeof(colorBitmap), &colorBitmap)) {
        if (iconInfo.hbmColor) {
            DeleteObject(iconInfo.hbmColor);
        }
        if (iconInfo.hbmMask) {
            DeleteObject(iconInfo.hbmMask);
        }
        return;
    }

    int width = colorBitmap.bmWidth;
    int height = colorBitmap.bmHeight;
    BITMAPINFO info{};
    info.bmiHeader.biSize = sizeof(info.bmiHeader);
    info.bmiHeader.biWidth = width;
    info.bmiHeader.biHeight = -height;
    info.bmiHeader.biPlanes = 1;
    info.bmiHeader.biBitCount = 32;
    info.bmiHeader.biCompression = BI_RGB;

    std::vector<BYTE> pixels((size_t)width * height * 4);
    HDC screen = GetDC(nullptr);
    int scanned = GetDIBits(screen, iconInfo.hbmColor, 0, height, pixels.data(), &info,
                            DIB_RGB_COLORS);

    bool opaque = true;
    for (size_t i = 3; i < pixels.size(); i += 4) {
        if (pixels[i] != 0) {
            opaque = false;
            break;
        }
    }
    if (opaque && iconInfo.hbmMask) {
        std::vector<BYTE> mask((size_t)width * height * 4);
        if (GetDIBits(screen, iconInfo.hbmMask, 0, height, mask.data(), &info,
                      DIB_RGB_COLORS)) {
            for (size_t i = 0; i < pixels.size(); i += 4) {
                pixels[i + 3] = mask[i] ? 0 : 255;
            }
        }
    }
    ReleaseDC(nullptr, screen);
    DeleteObject(iconInfo.hbmColor);
    if (iconInfo.hbmMask) {
        DeleteObject(iconInfo.hbmMask);
    }
    if (scanned == 0) {
        return;
    }

    for (size_t i = 0; i < pixels.size(); i += 4) {
        BYTE alpha = pixels[i + 3];
        pixels[i] = (BYTE)(pixels[i] * alpha / 255);
        pixels[i + 1] = (BYTE)(pixels[i + 1] * alpha / 255);
        pixels[i + 2] = (BYTE)(pixels[i + 2] * alpha / 255);
    }

    gp::Bitmap bitmap(width, height, width * 4, PixelFormat32bppPARGB, pixels.data());
    graphics.DrawImage(&bitmap, box.X, box.Y, box.Width, box.Height);
}

static bool ParseGlyph(const std::wstring& text, std::wstring& glyph) {
    if (text.size() < 4 || text.size() > 6) {
        return false;
    }
    for (wchar_t c : text) {
        if (!iswxdigit(c)) {
            return false;
        }
    }
    wchar_t* end = nullptr;
    unsigned long code = wcstoul(text.c_str(), &end, 16);
    if (code < 0x20 || code > 0xFFFF) {
        return false;
    }
    glyph.assign(1, (wchar_t)code);
    return true;
}

static PCWSTR TypeGlyph(ItemType type) {
    switch (type) {
        case ItemType::VSCode:
            return L"\uE943";
        case ItemType::Folder:
            return L"\uE8B7";
        case ItemType::Url:
            return L"\uE774";
        case ItemType::Terminal:
        case ItemType::Command:
            return L"\uE756";
        default:
            return L"\uE7B8";
    }
}

static std::wstring IconCacheKey(const StackItem& item) {
    if (!item.icon.empty()) {
        return ExpandTokens(item.icon);
    }
    if (item.type == ItemType::App || item.type == ItemType::Folder) {
        return ExpandTokens(item.target);
    }
    if (item.type == ItemType::VSCode) {
        return FindVSCode();
    }
    return std::wstring();
}

static HICON LoadShellIcon(const std::wstring& path) {
    if (path.empty()) {
        return nullptr;
    }
    SHFILEINFOW info{};
    UINT flags = SHGFI_ICON | SHGFI_LARGEICON;
    if (!PathFileExistsW(path.c_str())) {
        flags |= SHGFI_USEFILEATTRIBUTES;
    }
    if (!SHGetFileInfoW(path.c_str(), FILE_ATTRIBUTE_NORMAL, &info, sizeof(info),
                        flags)) {
        return nullptr;
    }
    return info.hIcon;
}

static HICON TryGetCachedIcon(const std::wstring& key) {
    std::lock_guard<std::mutex> lock(g_iconMutex);
    auto found = g_iconCache.find(key);
    return found == g_iconCache.end() ? nullptr : found->second;
}

static void RequestIcon(const std::wstring& key) {
    if (key.empty()) {
        return;
    }
    {
        std::lock_guard<std::mutex> lock(g_iconMutex);
        if (g_iconCache.count(key) || g_iconPending.count(key)) {
            return;
        }
        g_iconPending.insert(key);
    }
    g_backgroundQueue.Post([key]() {
        HICON icon = LoadShellIcon(key);
        {
            std::lock_guard<std::mutex> lock(g_iconMutex);
            g_iconPending.erase(key);
            g_iconCache[key] = icon;
        }
        if (g_panelWnd) {
            PostMessageW(g_panelWnd, kMsgIconReady, 0, 0);
        }
    });
}

static void ClearIconCache() {
    std::lock_guard<std::mutex> lock(g_iconMutex);
    for (auto& entry : g_iconCache) {
        if (entry.second) {
            DestroyIcon(entry.second);
        }
    }
    g_iconCache.clear();
}

struct GroupBlock {
    std::wstring name;
    int clipTop = 0;
    int clipBottom = 0;
};

struct PanelRow {
    bool isGroup = false;
    int itemIndex = -1;
    int groupIndex = -1;
    std::wstring text;
    int top = 0;
    int height = 0;
};

enum class HitKind {
    None,
    Item,
    ItemToggle,
    GroupHeader,
    GroupToggleAll,
    Chip,
    Search,
    SearchClear,
    Settings,
    Launch,
    Close,
    SelectAll,
    SelectNone,
    Refresh,
    Cancel,
    Scrollbar,
    Outside,
};

struct HitResult {
    HitKind kind = HitKind::None;
    int index = -1;

    bool operator==(const HitResult& other) const {
        return kind == other.kind && index == other.index;
    }
};

struct PanelLayout {
    gp::Rect window;
    gp::Rect content;
    gp::Rect header;
    gp::Rect settingsButton;
    gp::Rect chips;
    gp::Rect search;
    gp::Rect searchClear;
    gp::Rect list;
    gp::Rect footer;
    gp::Rect launchButton;
    gp::Rect closeButton;
    gp::Rect selectAllButton;
    gp::Rect selectNoneButton;
    gp::Rect refreshButton;
    gp::Rect cancelButton;
    gp::Rect progressBar;
    gp::Rect scrollTrack;
    gp::Rect scrollThumb;
    std::vector<gp::Rect> chipRects;
    std::vector<std::wstring> chipNames;
    int shadow = 0;
    int rowsHeight = 0;
};

static PanelLayout g_layout;
static std::vector<PanelRow> g_rows;
static std::vector<GroupBlock> g_groups;
static HitResult g_hover;
static HitResult g_pressed;
static bool g_draggingScrollbar = false;
static int g_dragOffset = 0;
static bool g_dragActive = false;
static HitResult g_dragCandidate;
static POINT g_dragOrigin{};
static int g_dragItemIndex = -1;
static std::wstring g_dragGroup;
static Surface g_panelSurface;

static double g_revealAmount = 0.0;
static double g_revealTarget = 0.0;
static double g_hoverAmount = 0.0;
static double g_hoverFadeAmount = 0.0;
static HitResult g_hoverFading;
static double g_progressAmount = 0.0;
static std::vector<double> g_toggleAmount;
static std::unordered_map<std::wstring, double> g_groupOpenAmount;
static std::unordered_set<std::wstring> g_collapsedGroups;
static bool g_animating = false;

static bool Contains(const gp::Rect& rect, POINT point) {
    return rect.Width > 0 && rect.Height > 0 && point.x >= rect.X &&
           point.x < rect.X + rect.Width && point.y >= rect.Y &&
           point.y < rect.Y + rect.Height;
}

static std::wstring GroupStorageKey(const std::wstring& group) {
    return HashKey(L"gc_", group);
}

static bool IsGroupCollapsed(const std::wstring& group) {
    return g_collapsedGroups.count(group) > 0;
}

static void LoadCollapsedGroups() {
    g_collapsedGroups.clear();
    g_groupOpenAmount.clear();
    std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
    for (const auto& item : g_settings.items) {
        if (item.group.empty() || g_groupOpenAmount.count(item.group)) {
            continue;
        }
        bool collapsed = Wh_GetIntValue(GroupStorageKey(item.group).c_str(), 0) != 0;
        if (collapsed) {
            g_collapsedGroups.insert(item.group);
        }
        g_groupOpenAmount[item.group] = collapsed ? 0.0 : 1.0;
    }
}

static void SetGroupCollapsed(const std::wstring& group, bool collapsed) {
    if (collapsed) {
        g_collapsedGroups.insert(group);
    } else {
        g_collapsedGroups.erase(group);
    }
    Wh_SetIntValue(GroupStorageKey(group).c_str(), collapsed ? 1 : 0);
}

static std::vector<std::wstring> g_itemOrder;

static void LoadItemOrder() {
    std::vector<wchar_t> stored(8192, L'\0');
    Wh_GetStringValue(L"itemOrder", stored.data(), stored.size());
    g_itemOrder = SplitList(stored.data(), L'|');
}

static void SaveItemOrder() {
    std::wstring joined;
    for (const auto& key : g_itemOrder) {
        if (!joined.empty()) {
            joined += L'|';
        }
        joined += key;
    }
    Wh_SetStringValue(L"itemOrder", joined.c_str());
}

static std::vector<int> OrderedIndices() {
    std::vector<int> order;
    std::vector<bool> placed(g_settings.items.size(), false);
    for (const auto& key : g_itemOrder) {
        for (size_t i = 0; i < g_settings.items.size(); i++) {
            if (!placed[i] && g_settings.items[i].storageKey == key) {
                order.push_back((int)i);
                placed[i] = true;
                break;
            }
        }
    }
    for (size_t i = 0; i < g_settings.items.size(); i++) {
        if (!placed[i]) {
            order.push_back((int)i);
        }
    }
    return order;
}

static void AdoptOrder(const std::vector<int>& order) {
    g_itemOrder.clear();
    for (int index : order) {
        g_itemOrder.push_back(g_settings.items[index].storageKey);
    }
}

static void NormalizeItemOrder() {
    std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
    AdoptOrder(OrderedIndices());
}

static std::vector<std::wstring> GroupSequence(const std::vector<int>& order) {
    std::vector<std::wstring> sequence;
    for (int index : order) {
        const std::wstring& name = g_settings.items[index].group;
        if (std::find(sequence.begin(), sequence.end(), name) == sequence.end()) {
            sequence.push_back(name);
        }
    }
    return sequence;
}

static bool MoveItemWithinGroup(int itemIndex, int delta) {
    std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
    if (itemIndex < 0 || itemIndex >= (int)g_settings.items.size() || delta == 0) {
        return false;
    }
    const std::wstring group = g_settings.items[itemIndex].group;
    std::vector<int> order = OrderedIndices();
    std::vector<size_t> slots;
    for (size_t i = 0; i < order.size(); i++) {
        if (g_settings.items[order[i]].group == group) {
            slots.push_back(i);
        }
    }
    size_t position = slots.size();
    for (size_t i = 0; i < slots.size(); i++) {
        if (order[slots[i]] == itemIndex) {
            position = i;
            break;
        }
    }
    if (position == slots.size()) {
        return false;
    }
    if (delta < 0 ? position == 0 : position + 1 >= slots.size()) {
        return false;
    }
    std::swap(order[slots[position]], order[slots[position + delta]]);
    AdoptOrder(order);
    return true;
}

static bool MoveGroupBlock(const std::wstring& group, int delta) {
    std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
    if (delta == 0) {
        return false;
    }
    std::vector<int> order = OrderedIndices();
    std::vector<std::wstring> sequence = GroupSequence(order);
    size_t position = sequence.size();
    for (size_t i = 0; i < sequence.size(); i++) {
        if (sequence[i] == group) {
            position = i;
            break;
        }
    }
    if (position == sequence.size()) {
        return false;
    }
    if (delta < 0 ? position == 0 : position + 1 >= sequence.size()) {
        return false;
    }
    std::swap(sequence[position], sequence[position + delta]);

    std::vector<int> rebuilt;
    for (const auto& name : sequence) {
        for (int index : order) {
            if (g_settings.items[index].group == name) {
                rebuilt.push_back(index);
            }
        }
    }
    AdoptOrder(rebuilt);
    return true;
}

static void ResetItemOrder() {
    g_itemOrder.clear();
    Wh_SetStringValue(L"itemOrder", L"");
    NormalizeItemOrder();
}

static bool ItemMatchesFilter(const StackItem& item) {
    if (g_filter.empty()) {
        return true;
    }
    return ContainsNoCase(item.name, g_filter) ||
           ContainsNoCase(item.group, g_filter) ||
           ContainsNoCase(item.description, g_filter) ||
           ContainsNoCase(item.target, g_filter);
}

static int RowHeight() {
    std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
    return Scale(g_settings.compactRows ? 34 : 46);
}

static void RebuildRows() {
    g_rows.clear();
    g_groups.clear();

    std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
    if (g_toggleAmount.size() != g_settings.items.size()) {
        g_toggleAmount.assign(g_settings.items.size(), 0.0);
        for (size_t i = 0; i < g_settings.items.size(); i++) {
            g_toggleAmount[i] = g_settings.items[i].enabled ? 1.0 : 0.0;
        }
    }

    const int rowHeight = RowHeight();
    const int groupHeight = Scale(32);
    int y = Scale(6);

    std::vector<int> order = OrderedIndices();
    std::vector<std::wstring> emitted;
    for (int first : order) {
        const StackItem& item = g_settings.items[first];
        if (!ItemMatchesFilter(item)) {
            continue;
        }

        const std::wstring group = item.group;
        if (std::find(emitted.begin(), emitted.end(), group) != emitted.end()) {
            continue;
        }
        emitted.push_back(group);

        std::vector<size_t> members;
        for (int candidate : order) {
            if (g_settings.items[candidate].group == group &&
                ItemMatchesFilter(g_settings.items[candidate])) {
                members.push_back((size_t)candidate);
            }
        }
        if (members.empty()) {
            continue;
        }

        int groupIndex = -1;
        int visibleHeight = (int)members.size() * rowHeight;
        if (!group.empty()) {
            double openAmount = 1.0;
            auto found = g_groupOpenAmount.find(group);
            if (found != g_groupOpenAmount.end()) {
                openAmount = found->second;
            }
            PanelRow header;
            header.isGroup = true;
            header.text = group;
            header.top = y;
            header.height = groupHeight;
            g_rows.push_back(std::move(header));
            y += groupHeight;

            visibleHeight = (int)((int)members.size() * rowHeight * Ease(openAmount));
            GroupBlock block;
            block.name = group;
            block.clipTop = y;
            block.clipBottom = y + visibleHeight;
            groupIndex = (int)g_groups.size();
            g_groups.push_back(std::move(block));
        }

        int memberTop = y;
        for (size_t member : members) {
            PanelRow row;
            row.itemIndex = (int)member;
            row.groupIndex = groupIndex;
            row.top = memberTop;
            row.height = rowHeight;
            g_rows.push_back(std::move(row));
            memberTop += rowHeight;
        }
        y += visibleHeight;
        if (!group.empty() && visibleHeight > 0) {
            y += Scale(2);
        }
    }

    g_layout.rowsHeight = y + Scale(6);
    if (g_focusRow >= (int)g_rows.size()) {
        g_focusRow = -1;
    }
}

static bool RowVisible(const PanelRow& row) {
    if (row.groupIndex < 0 || row.groupIndex >= (int)g_groups.size()) {
        return true;
    }
    const GroupBlock& block = g_groups[row.groupIndex];
    return row.top < block.clipBottom && row.top + row.height > block.clipTop;
}

static void ComputeLayout() {
    std::lock_guard<std::recursive_mutex> settingsLock(g_settingsMutex);

    const int shadow = Scale(24);
    const int width = Scale(g_settings.panelWidth);
    const int pad = Scale(14);
    const int headerHeight = Scale(56);
    const int chipsHeight = g_settings.profiles.empty() ? 0 : Scale(38);
    const int searchHeight = Scale(44);
    const int footerHeight = Scale(58);

    int listHeight = Scale(g_settings.panelMaxHeight) - headerHeight - chipsHeight -
                     searchHeight - footerHeight;
    listHeight = max(Scale(72), min(listHeight, g_layout.rowsHeight));
    int contentHeight =
        headerHeight + chipsHeight + searchHeight + listHeight + footerHeight;

    g_layout.shadow = shadow;
    g_layout.window = gp::Rect(0, 0, width + shadow * 2, contentHeight + shadow * 2);
    g_layout.content = gp::Rect(shadow, shadow, width, contentHeight);

    int y = shadow;
    g_layout.header = gp::Rect(shadow, y, width, headerHeight);
    g_layout.settingsButton =
        gp::Rect(shadow + width - pad - Scale(30), y + (headerHeight - Scale(30)) / 2,
                 Scale(30), Scale(30));
    y += headerHeight;

    g_layout.chipRects.clear();
    g_layout.chipNames.clear();
    g_layout.chips = gp::Rect(shadow, y, width, chipsHeight);
    if (chipsHeight > 0) {
        std::vector<std::wstring> names{L"All"};
        for (const auto& profile : g_settings.profiles) {
            names.push_back(profile);
        }
        int chipX = shadow + pad;
        int chipHeight = Scale(24);
        int chipY = y + (chipsHeight - chipHeight) / 2;
        for (const auto& name : names) {
            int chipWidth = MeasureText(name, UiFont(-1)) + Scale(20);
            if (chipX + chipWidth > shadow + width - pad) {
                break;
            }
            g_layout.chipRects.push_back(gp::Rect(chipX, chipY, chipWidth, chipHeight));
            g_layout.chipNames.push_back(name);
            chipX += chipWidth + Scale(6);
        }
        y += chipsHeight;
    }

    int searchBoxHeight = Scale(30);
    g_layout.search = gp::Rect(shadow + pad, y + (searchHeight - searchBoxHeight) / 2,
                               width - pad * 2, searchBoxHeight);
    g_layout.searchClear =
        gp::Rect(g_layout.search.X + g_layout.search.Width - Scale(28),
                 g_layout.search.Y, Scale(28), searchBoxHeight);
    y += searchHeight;

    g_layout.list = gp::Rect(shadow, y, width, listHeight);
    y += listHeight;

    g_layout.footer = gp::Rect(shadow, y, width, footerHeight);

    int buttonHeight = Scale(30);
    int footerY = y + (footerHeight - buttonHeight) / 2;
    int smallButton = Scale(28);
    int smallY = y + (footerHeight - smallButton) / 2;
    int smallX = shadow + pad;

    g_layout.selectAllButton = gp::Rect(smallX, smallY, smallButton, smallButton);
    smallX += smallButton + Scale(2);
    g_layout.selectNoneButton = gp::Rect(smallX, smallY, smallButton, smallButton);
    smallX += smallButton + Scale(2);
    g_layout.refreshButton = gp::Rect(smallX, smallY, smallButton, smallButton);
    smallX += smallButton + Scale(2);

    int rightEdge = shadow + width - pad;
    int available = rightEdge - smallX - Scale(8);
    int closeWidth =
        g_settings.showCloseButton ? max(Scale(60), min(Scale(84), available / 3)) : 0;
    int launchWidth =
        max(Scale(92), available - closeWidth - (closeWidth > 0 ? Scale(6) : 0));
    g_layout.launchButton =
        gp::Rect(rightEdge - launchWidth, footerY, launchWidth, buttonHeight);
    g_layout.closeButton =
        closeWidth > 0 ? gp::Rect(g_layout.launchButton.X - Scale(6) - closeWidth,
                                  footerY, closeWidth, buttonHeight)
                       : gp::Rect(0, 0, 0, 0);
    g_layout.cancelButton =
        gp::Rect(rightEdge - Scale(64), footerY, Scale(64), buttonHeight);
    g_layout.progressBar =
        gp::Rect(shadow + pad, y + footerHeight - Scale(16),
                 width - pad * 2 - Scale(72), Scale(3));

    int trackWidth = Scale(4);
    g_layout.scrollTrack = gp::Rect(shadow + width - trackWidth - Scale(4),
                                    g_layout.list.Y + Scale(4), trackWidth,
                                    g_layout.list.Height - Scale(8));
    if (g_layout.rowsHeight > g_layout.list.Height) {
        double ratio = (double)g_layout.list.Height / g_layout.rowsHeight;
        int thumbHeight = max(Scale(24), (int)(g_layout.scrollTrack.Height * ratio));
        int maxScroll = g_layout.rowsHeight - g_layout.list.Height;
        double progress = maxScroll > 0 ? (double)g_scrollOffset / maxScroll : 0.0;
        g_layout.scrollThumb = gp::Rect(
            g_layout.scrollTrack.X,
            g_layout.scrollTrack.Y +
                (int)((g_layout.scrollTrack.Height - thumbHeight) * progress),
            trackWidth, thumbHeight);
    } else {
        g_layout.scrollThumb = gp::Rect(0, 0, 0, 0);
    }
}

static int MaxScroll() {
    return max(0, g_layout.rowsHeight - g_layout.list.Height);
}

static void ClampScroll() {
    g_scrollOffset = max(0, min(g_scrollOffset, MaxScroll()));
}

static int ToggleLeftEdge() {
    return g_layout.list.X + g_layout.list.Width - Scale(14) - Scale(34) - Scale(6);
}

static HitResult HitTest(POINT point) {
    HitResult result;
    if (!Contains(g_layout.content, point)) {
        result.kind = HitKind::Outside;
        return result;
    }
    if (Contains(g_layout.settingsButton, point)) {
        result.kind = HitKind::Settings;
        return result;
    }
    for (size_t i = 0; i < g_layout.chipRects.size(); i++) {
        if (Contains(g_layout.chipRects[i], point)) {
            result.kind = HitKind::Chip;
            result.index = (int)i;
            return result;
        }
    }
    if (!g_filter.empty() && Contains(g_layout.searchClear, point)) {
        result.kind = HitKind::SearchClear;
        return result;
    }
    if (Contains(g_layout.search, point)) {
        result.kind = HitKind::Search;
        return result;
    }
    if (g_layout.scrollThumb.Height > 0 && Contains(g_layout.scrollTrack, point)) {
        result.kind = HitKind::Scrollbar;
        return result;
    }
    if (Contains(g_layout.list, point)) {
        int localY = point.y - g_layout.list.Y + g_scrollOffset;
        for (size_t i = 0; i < g_rows.size(); i++) {
            const PanelRow& row = g_rows[i];
            if (localY < row.top || localY >= row.top + row.height ||
                !RowVisible(row)) {
                continue;
            }
            if (row.isGroup) {
                int toggleAllLeft =
                    g_layout.list.X + g_layout.list.Width - Scale(14) - Scale(52);
                result.kind = point.x >= toggleAllLeft ? HitKind::GroupToggleAll
                                                       : HitKind::GroupHeader;
            } else {
                result.kind = point.x >= ToggleLeftEdge() ? HitKind::ItemToggle
                                                          : HitKind::Item;
            }
            result.index = (int)i;
            return result;
        }
        return result;
    }
    if (Contains(g_layout.footer, point)) {
        if (g_launching) {
            if (Contains(g_layout.cancelButton, point)) {
                result.kind = HitKind::Cancel;
            }
            return result;
        }
        if (Contains(g_layout.launchButton, point)) {
            result.kind = HitKind::Launch;
        } else if (Contains(g_layout.closeButton, point)) {
            result.kind = HitKind::Close;
        } else if (Contains(g_layout.selectAllButton, point)) {
            result.kind = HitKind::SelectAll;
        } else if (Contains(g_layout.selectNoneButton, point)) {
            result.kind = HitKind::SelectNone;
        } else if (Contains(g_layout.refreshButton, point)) {
            result.kind = HitKind::Refresh;
        }
    }
    return result;
}

static void SetItemEnabled(int itemIndex, bool enabled) {
    std::wstring key;
    {
        std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
        if (itemIndex < 0 || itemIndex >= (int)g_settings.items.size()) {
            return;
        }
        g_settings.items[itemIndex].enabled = enabled;
        key = g_settings.items[itemIndex].storageKey;
    }
    Wh_SetIntValue(key.c_str(), enabled ? 1 : 0);
}

static void ApplyProfile(const std::wstring& profile) {
    g_activeProfile = ToLower(profile) == L"all" ? std::wstring() : profile;
    Wh_SetStringValue(L"activeProfile", g_activeProfile.c_str());
    std::vector<std::pair<std::wstring, bool>> updates;
    {
        std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
        for (auto& item : g_settings.items) {
            item.enabled = g_activeProfile.empty()
                               ? item.defaultEnabled
                               : ListContains(item.profiles, g_activeProfile);
            updates.emplace_back(item.storageKey, item.enabled);
        }
    }
    for (const auto& update : updates) {
        Wh_SetIntValue(update.first.c_str(), update.second ? 1 : 0);
    }
}

static void SetGroupEnabled(const std::wstring& group) {
    std::vector<std::wstring> keys;
    bool turnOn = false;
    {
        std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
        for (const auto& item : g_settings.items) {
            if (item.group == group && !item.enabled) {
                turnOn = true;
                break;
            }
        }
        for (auto& item : g_settings.items) {
            if (item.group == group) {
                item.enabled = turnOn;
                keys.push_back(item.storageKey);
            }
        }
    }
    for (const auto& key : keys) {
        Wh_SetIntValue(key.c_str(), turnOn ? 1 : 0);
    }
}

static void SetAllEnabled(bool enabled) {
    std::vector<std::wstring> keys;
    {
        std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
        for (auto& item : g_settings.items) {
            item.enabled = enabled;
            keys.push_back(item.storageKey);
        }
    }
    for (const auto& key : keys) {
        Wh_SetIntValue(key.c_str(), enabled ? 1 : 0);
    }
}

static void RefreshRunningStatus() {
    g_backgroundQueue.Post([]() {
        ProcessMap running = SnapshotProcesses();
        {
            std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
            for (auto& item : g_settings.items) {
                std::wstring process = ResolveProcessName(item);
                item.running = !process.empty() && running.count(process) > 0;
            }
        }
        if (g_panelWnd) {
            PostMessageW(g_panelWnd, kMsgStatusReady, 0, 0);
        }
    });
}

static void ReportProgress() {
    if (g_panelWnd) {
        PostMessageW(g_panelWnd, kMsgLaunchProgress, 0, 0);
    }
}

static void RunLaunchSequence(std::vector<int> indices) {
    g_launching = true;
    g_cancelLaunch = false;
    g_progressTotal = (int)indices.size();
    g_progressCurrent = 0;

    ProcessMap running = SnapshotProcesses();

    for (size_t i = 0; i < indices.size(); i++) {
        if (g_unloading || g_cancelLaunch) {
            break;
        }
        StackItem item;
        {
            std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
            if (indices[i] < 0 || indices[i] >= (int)g_settings.items.size()) {
                continue;
            }
            item = g_settings.items[indices[i]];
        }

        g_progressCurrent = (int)i;
        SetStatusText(L"Starting " + item.name);
        ReportProgress();

        if (item.delayMs > 0 && !CancellableSleep(item.delayMs)) {
            break;
        }

        std::wstring process = ResolveDuplicateProcessName(item);
        if (item.singleInstance && !process.empty() && running.count(process) > 0) {
            SetStatusText(item.name + L" is already running");
            ReportProgress();
            continue;
        }

        if (item.confirm) {
            if (MessageBoxW(nullptr, (L"Launch " + item.name + L"?").c_str(),
                            L"Tech Stack Launcher",
                            MB_OKCANCEL | MB_ICONQUESTION | MB_TOPMOST |
                                MB_SETFOREGROUND) != IDOK) {
                continue;
            }
        }

        LaunchPlan plan;
        if (!BuildLaunchPlan(item, plan)) {
            SetStatusText(L"Could not resolve " + item.name);
            ReportProgress();
            continue;
        }

        HANDLE processHandle = nullptr;
        if (!LaunchPlanNow(plan, item.waitForExit ? &processHandle : nullptr)) {
            SetStatusText(L"Failed to start " + item.name);
            ReportProgress();
            continue;
        }
        if (!plan.adjustWindowTitle.empty()) {
            ApplyTerminalWindowState(plan.adjustWindowTitle,
                                     item.windowState == WindowStateOption::Minimized
                                         ? SW_MINIMIZE
                                         : SW_MAXIMIZE);
        }
        if (!process.empty()) {
            running[process];
        }

        if (item.waitForExit && processHandle) {
            SetStatusText(L"Waiting for " + item.name);
            ReportProgress();
            while (!g_unloading && !g_cancelLaunch) {
                if (WaitForSingleObject(processHandle, 100) == WAIT_OBJECT_0) {
                    break;
                }
            }
        }
        if (processHandle) {
            CloseHandle(processHandle);
        }

        int stagger = 0;
        {
            std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
            stagger = g_settings.staggerMs;
        }
        if (i + 1 < indices.size() && stagger > 0 && !CancellableSleep(stagger)) {
            break;
        }
    }

    g_progressCurrent = g_progressTotal.load();
    SetStatusText(g_cancelLaunch ? L"Cancelled" : L"Launched");
    g_launching = false;
    if (g_panelWnd) {
        PostMessageW(g_panelWnd, kMsgLaunchFinished, 0, 0);
    }
}

static void RunShutdownSequence(std::vector<int> indices) {
    g_launching = true;
    g_cancelLaunch = false;
    g_progressTotal = (int)indices.size();
    g_progressCurrent = 0;

    int graceMs = 0;
    bool force = false;
    {
        std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
        graceMs = g_settings.closeGraceSeconds * 1000;
        force = g_settings.forceCloseAfterGrace;
    }

    ProcessMap processes = SnapshotProcesses();
    int closed = 0;
    int stubborn = 0;

    for (size_t i = 0; i < indices.size(); i++) {
        if (g_unloading || g_cancelLaunch) {
            break;
        }
        StackItem item;
        {
            std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
            if (indices[i] < 0 || indices[i] >= (int)g_settings.items.size()) {
                continue;
            }
            item = g_settings.items[indices[i]];
        }

        g_progressCurrent = (int)i;

        std::wstring process = ResolveProcessName(item);
        if (process.empty()) {
            SetStatusText(item.name + L" has no process name");
            ReportProgress();
            continue;
        }

        auto found = processes.find(process);
        if (found == processes.end() || found->second.empty()) {
            SetStatusText(item.name + L" is not running");
            ReportProgress();
            continue;
        }

        SetStatusText(L"Closing " + item.name);
        ReportProgress();

        const std::vector<DWORD>& pids = found->second;
        int posted = 0;
        for (DWORD pid : pids) {
            posted += PostCloseToProcess(pid);
        }

        std::vector<DWORD> alive = StillRunning(pids);
        if (posted > 0) {
            ULONGLONG deadline = GetTickCount64() + (ULONGLONG)graceMs;
            while (!alive.empty() && GetTickCount64() < deadline) {
                if (!CancellableSleep(250)) {
                    break;
                }
                alive = StillRunning(pids);
            }
        }

        if (!alive.empty() && force) {
            for (DWORD pid : alive) {
                TerminateProcessById(pid);
            }
            CancellableSleep(250);
            alive = StillRunning(pids);
        }

        if (alive.empty()) {
            closed++;
        } else {
            stubborn++;
            SetStatusText(L"Could not close " + item.name);
            ReportProgress();
        }
    }

    g_progressCurrent = g_progressTotal.load();
    wchar_t summary[160];
    swprintf_s(summary, L"Closed %d, %d still running", closed, stubborn);
    SetStatusText(g_cancelLaunch ? L"Cancelled" : summary);
    g_launching = false;
    if (g_panelWnd) {
        PostMessageW(g_panelWnd, kMsgLaunchFinished, 0, 0);
    }
}

static void StartLaunch(std::vector<int> indices) {
    if (indices.empty() || g_launching) {
        return;
    }
    g_launchQueue.Post([indices = std::move(indices)]() mutable {
        RunLaunchSequence(std::move(indices));
    });
}

static void StartShutdown(std::vector<int> indices) {
    if (indices.empty() || g_launching) {
        return;
    }
    g_launchQueue.Post([indices = std::move(indices)]() mutable {
        RunShutdownSequence(std::move(indices));
    });
}

static std::vector<int> SelectedIndices() {
    std::vector<int> indices;
    std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
    for (size_t i = 0; i < g_settings.items.size(); i++) {
        if (g_settings.items[i].enabled) {
            indices.push_back((int)i);
        }
    }
    return indices;
}

static std::vector<int> RunningSelectedIndices() {
    std::vector<int> indices;
    std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
    for (size_t i = 0; i < g_settings.items.size(); i++) {
        if (g_settings.items[i].enabled && g_settings.items[i].running) {
            indices.push_back((int)i);
        }
    }
    return indices;
}

static std::vector<int> ProfileIndices(const std::wstring& profile) {
    std::vector<int> indices;
    std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
    for (size_t i = 0; i < g_settings.items.size(); i++) {
        const StackItem& item = g_settings.items[i];
        if (ToLower(profile) == L"all" ? item.enabled
                                       : ListContains(item.profiles, profile)) {
            indices.push_back((int)i);
        }
    }
    return indices;
}

static void OpenContainingFolder(const StackItem& item) {
    std::wstring target = ExpandTokens(item.target);
    if (target.empty()) {
        return;
    }
    if (PathIsDirectoryW(target.c_str())) {
        ShellExecuteW(nullptr, L"open", target.c_str(), nullptr, nullptr,
                      SW_SHOWNORMAL);
        return;
    }
    ShellExecuteW(nullptr, L"open", L"explorer.exe",
                  (L"/select,\"" + target + L"\"").c_str(), nullptr, SW_SHOWNORMAL);
}

static void CopyToClipboard(const std::wstring& text) {
    if (!OpenClipboard(g_panelWnd)) {
        return;
    }
    EmptyClipboard();
    size_t bytes = (text.size() + 1) * sizeof(wchar_t);
    HGLOBAL memory = GlobalAlloc(GMEM_MOVEABLE, bytes);
    if (memory) {
        void* data = GlobalLock(memory);
        if (data) {
            memcpy(data, text.c_str(), bytes);
            GlobalUnlock(memory);
            SetClipboardData(CF_UNICODETEXT, memory);
        } else {
            GlobalFree(memory);
        }
    }
    CloseClipboard();
}

static void OpenWindhawk() {
    std::wstring windhawk = FindWindhawk();
    if (!windhawk.empty()) {
        ShellExecuteW(nullptr, L"open", windhawk.c_str(), nullptr, nullptr,
                      SW_SHOWNORMAL);
    }
}

static int g_panelBaseX = 0;
static int g_panelBaseY = 0;
static int g_panelAnchorBottom = 0;
static bool g_panelGrowsUp = true;

static void DrawSmallButton(Surface& surface,
                            const gp::Rect& box,
                            PCWSTR glyph,
                            const Palette& palette,
                            bool hovered,
                            bool pressed) {
    if (box.Width <= 0) {
        return;
    }
    gp::Graphics& graphics = *surface.Graphics();
    if (pressed || hovered) {
        FillRoundRect(graphics, ToRectF(box), (gp::REAL)Scale(4),
                      pressed ? palette.press : palette.hover);
    }
    surface.RenderText(glyph, IconFont(-2), palette.textDim, box, kTextCenter);
}

static void DrawTextButton(Surface& surface,
                           const gp::Rect& box,
                           const std::wstring& label,
                           const Palette& palette,
                           bool primary,
                           bool enabled,
                           bool hovered,
                           bool pressed) {
    if (box.Width <= 0) {
        return;
    }
    gp::Graphics& graphics = *surface.Graphics();
    gp::REAL radius = (gp::REAL)Scale(4);
    gp::Color background;
    gp::Color foreground;
    if (primary) {
        background = !enabled ? palette.surface
                    : pressed ? Shift(palette.accent, -0.12)
                    : hovered ? palette.accentHover
                              : palette.accent;
        foreground = enabled ? palette.accentText : palette.textDim;
    } else {
        background = pressed ? palette.press : hovered ? palette.hover : palette.surface;
        foreground = enabled ? palette.text : palette.textDim;
    }
    FillRoundRect(graphics, ToRectF(box), radius, background);
    if (!primary) {
        StrokeRoundRect(graphics, ToRectF(box), radius, palette.border, 1.0f);
    }
    surface.RenderText(label, UiFont(-1, primary), foreground, box, kTextCenter);
}

static void DrawToggle(Surface& surface,
                       const gp::Rect& box,
                       double amount,
                       const Palette& palette,
                       bool hovered) {
    gp::Graphics& graphics = *surface.Graphics();
    gp::RectF track = ToRectF(box);
    gp::REAL radius = track.Height / 2;
    gp::Color off = palette.dark ? gp::Color(255, 0x5A, 0x5A, 0x5A)
                                 : gp::Color(255, 0xC2, 0xC2, 0xC2);
    gp::Color trackColor = Blend(off, palette.accent, Ease(amount));
    if (hovered) {
        trackColor = Shift(trackColor, palette.dark ? 0.12 : -0.08);
    }
    FillRoundRect(graphics, track, radius, trackColor);

    gp::REAL knobSize = track.Height - Scale(6);
    gp::REAL travel = track.Width - knobSize - Scale(6);
    gp::REAL knobX = track.X + Scale(3) + travel * (gp::REAL)Ease(amount);
    gp::SolidBrush knob(gp::Color(255, 0xFF, 0xFF, 0xFF));
    graphics.FillEllipse(&knob, knobX, track.Y + Scale(3), knobSize, knobSize);
}

static void DrawIconGlyph(Surface& surface,
                          const gp::Rect& box,
                          const std::wstring& source,
                          ItemType type,
                          const gp::Color& color) {
    std::wstring glyph;
    if (!source.empty() && ParseGlyph(source, glyph)) {
        surface.RenderText(glyph, IconFont(1), color, box, kTextCenter);
        return;
    }
    if (!source.empty() && source.find(L'\\') == std::wstring::npos &&
        source.find(L'/') == std::wstring::npos) {
        surface.RenderText(source, UiFont(1), color, box, kTextCenter);
        return;
    }
    surface.RenderText(TypeGlyph(type), IconFont(), color, box, kTextCenter);
}

static void DrawItemIcon(Surface& surface,
                         const gp::Rect& box,
                         const StackItem& item,
                         const Palette& palette) {
    if (!item.icon.empty()) {
        std::wstring glyph;
        if (ParseGlyph(item.icon, glyph) ||
            item.icon.find(L'\\') == std::wstring::npos) {
            DrawIconGlyph(surface, box, item.icon, item.type, palette.textDim);
            return;
        }
    }
    std::wstring key = IconCacheKey(item);
    HICON icon = key.empty() ? nullptr : TryGetCachedIcon(key);
    if (!icon) {
        if (!key.empty()) {
            RequestIcon(key);
        }
        DrawIconGlyph(surface, box, std::wstring(), item.type, palette.textDim);
        return;
    }
    DrawIconImage(*surface.Graphics(), icon, box);
}

static bool StepAnimations() {
    bool animating = false;
    animating |= Approach(g_revealAmount, g_revealTarget, 0.075);
    animating |= Approach(g_hoverAmount, 1.0, 0.05);
    animating |= Approach(g_hoverFadeAmount, 0.0, 0.05);

    double progressTarget =
        g_progressTotal > 0 ? (double)g_progressCurrent / g_progressTotal : 0.0;
    animating |= Approach(g_progressAmount, progressTarget, 0.09);

    {
        std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
        for (size_t i = 0; i < g_toggleAmount.size() && i < g_settings.items.size();
             i++) {
            animating |=
                Approach(g_toggleAmount[i], g_settings.items[i].enabled ? 1.0 : 0.0,
                         0.06);
        }
    }

    for (auto& entry : g_groupOpenAmount) {
        animating |=
            Approach(entry.second, IsGroupCollapsed(entry.first) ? 0.0 : 1.0, 0.07);
    }

    g_animating = animating;
    return animating;
}

static void PaintPanel() {
    if (!g_panelWnd) {
        return;
    }
    Palette palette = CurrentPalette();
    RebuildRows();
    ClampScroll();
    ComputeLayout();
    if (!g_panelSurface.Resize(g_layout.window.Width, g_layout.window.Height)) {
        return;
    }
    g_panelSurface.Clear();
    Surface& surface = g_panelSurface;
    gp::Graphics& graphics = *surface.Graphics();

    double reveal = Ease(max(0.0, min(1.0, g_revealAmount)));
    const int pad = Scale(14);
    gp::RectF content = ToRectF(g_layout.content);
    gp::REAL radius = (gp::REAL)Scale(8);

    gp::Region shadowRegion(gp::RectF(0, 0, (gp::REAL)g_layout.window.Width,
                                      (gp::REAL)g_layout.window.Height));
    shadowRegion.Exclude(
        gp::RectF(content.X + 2, content.Y + 2, content.Width - 4, content.Height - 4));
    graphics.SetClip(&shadowRegion);
    DrawShadow(graphics, content, radius, Scale(16), reveal);
    graphics.ResetClip();

    FillRoundRect(graphics, content, radius, palette.background);
    StrokeRoundRect(graphics, content, radius, palette.border, 1.0f);

    int selected = 0;
    int total = 0;
    int runningSelected = 0;
    std::wstring title;
    bool compact = false;
    bool showDots = true;
    {
        std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
        title = g_settings.panelTitle;
        compact = g_settings.compactRows;
        showDots = g_settings.showStatusDots;
        total = (int)g_settings.items.size();
        for (const auto& item : g_settings.items) {
            if (!item.enabled) {
                continue;
            }
            selected++;
            if (item.running) {
                runningSelected++;
            }
        }
    }

    surface.RenderText(title.empty() ? std::wstring(L"Tech Stack") : title,
                       UiFont(2, true), palette.textStrong,
                       gp::Rect(g_layout.header.X + pad, g_layout.header.Y + Scale(9),
                                g_layout.header.Width - pad * 2 - Scale(34), Scale(20)),
                       kTextLeft);

    wchar_t subtitle[160];
    swprintf_s(subtitle, L"%d of %d selected  ·  %d running", selected, total,
               runningSelected);
    surface.RenderText(subtitle, UiFont(-2), palette.textDim,
                       gp::Rect(g_layout.header.X + pad, g_layout.header.Y + Scale(29),
                                g_layout.header.Width - pad * 2 - Scale(34), Scale(16)),
                       kTextLeft);

    DrawSmallButton(surface, g_layout.settingsButton, L"\uE713", palette,
                    g_hover.kind == HitKind::Settings,
                    g_pressed.kind == HitKind::Settings);

    for (size_t i = 0; i < g_layout.chipRects.size(); i++) {
        const gp::Rect& chip = g_layout.chipRects[i];
        const std::wstring& name = g_layout.chipNames[i];
        bool active = g_activeProfile.empty() ? name == L"All"
                                              : ToLower(name) == ToLower(g_activeProfile);
        bool hovered = g_hover.kind == HitKind::Chip && g_hover.index == (int)i;
        FillRoundRect(graphics, ToRectF(chip), (gp::REAL)(chip.Height / 2),
                      active     ? palette.accent
                      : hovered  ? palette.hover
                                 : palette.surface);
        if (!active) {
            StrokeRoundRect(graphics, ToRectF(chip), (gp::REAL)(chip.Height / 2),
                            palette.border, 1.0f);
        }
        surface.RenderText(name, UiFont(-1), active ? palette.accentText : palette.text,
                           chip, kTextCenter);
    }

    bool searchFocused = !g_filter.empty();
    FillRoundRect(graphics, ToRectF(g_layout.search), (gp::REAL)Scale(4),
                  palette.surface);
    StrokeRoundRect(graphics, ToRectF(g_layout.search), (gp::REAL)Scale(4),
                    searchFocused ? palette.accent : palette.border, 1.0f);
    surface.RenderText(L"\uE721", IconFont(-3), palette.textDim,
                       gp::Rect(g_layout.search.X, g_layout.search.Y, Scale(28),
                                g_layout.search.Height),
                       kTextCenter);
    gp::Rect searchTextBox(g_layout.search.X + Scale(28), g_layout.search.Y,
                           g_layout.search.Width - Scale(58), g_layout.search.Height);
    if (g_filter.empty()) {
        surface.RenderText(L"Type to filter", UiFont(-1), palette.textDim, searchTextBox,
                           kTextLeft);
    } else {
        surface.RenderText(g_filter, UiFont(-1), palette.text, searchTextBox, kTextLeft);
        DrawSmallButton(surface, g_layout.searchClear, L"\uE711", palette,
                        g_hover.kind == HitKind::SearchClear, false);
    }
    if (g_caretVisible) {
        gp::REAL caretX = (gp::REAL)(searchTextBox.X + MeasureText(g_filter, UiFont(-1)));
        caretX = min(caretX, (gp::REAL)(searchTextBox.X + searchTextBox.Width));
        gp::Pen caret(palette.text, 1.0f);
        graphics.DrawLine(&caret, caretX, (gp::REAL)(g_layout.search.Y + Scale(7)),
                          caretX,
                          (gp::REAL)(g_layout.search.Y + g_layout.search.Height -
                                     Scale(7)));
    }

    gp::Pen dividerPen(palette.divider, 1.0f);
    graphics.DrawLine(&dividerPen, (gp::REAL)(g_layout.list.X + pad),
                      (gp::REAL)g_layout.list.Y,
                      (gp::REAL)(g_layout.list.X + g_layout.list.Width - pad),
                      (gp::REAL)g_layout.list.Y);

    surface.SetClip(g_layout.list);

    if (g_rows.empty()) {
        surface.RenderText(total == 0
                               ? L"No items yet. Add them in the mod settings."
                               : L"Nothing matches that filter.",
                           UiFont(-1), palette.textDim, g_layout.list, kTextCenter);
    }

    std::lock_guard<std::recursive_mutex> itemsLock(g_settingsMutex);
    for (size_t rowIndex = 0; rowIndex < g_rows.size(); rowIndex++) {
        const PanelRow& row = g_rows[rowIndex];
        if (!RowVisible(row)) {
            continue;
        }
        int rowTop = g_layout.list.Y + row.top - g_scrollOffset;
        if (rowTop + row.height < g_layout.list.Y ||
            rowTop > g_layout.list.Y + g_layout.list.Height) {
            continue;
        }

        gp::Rect clip = g_layout.list;
        if (row.groupIndex >= 0 && row.groupIndex < (int)g_groups.size()) {
            const GroupBlock& block = g_groups[row.groupIndex];
            int top = max(g_layout.list.Y, g_layout.list.Y + block.clipTop - g_scrollOffset);
            int bottom =
                min(g_layout.list.Y + g_layout.list.Height,
                    g_layout.list.Y + block.clipBottom - g_scrollOffset);
            if (bottom <= top) {
                continue;
            }
            clip = gp::Rect(g_layout.list.X, top, g_layout.list.Width, bottom - top);
        }
        surface.SetClip(clip);

        double hoverWeight = 0.0;
        if (g_hover.index == (int)rowIndex &&
            (g_hover.kind == HitKind::Item || g_hover.kind == HitKind::ItemToggle ||
             g_hover.kind == HitKind::GroupHeader ||
             g_hover.kind == HitKind::GroupToggleAll)) {
            hoverWeight = g_hoverAmount;
        } else if (g_hoverFading.index == (int)rowIndex) {
            hoverWeight = g_hoverFadeAmount;
        }
        bool dragged = g_dragActive && (row.isGroup ? row.text == g_dragGroup
                                                    : row.itemIndex == g_dragItemIndex);

        if (row.isGroup) {
            gp::Rect headerBox(g_layout.list.X + Scale(6), rowTop,
                               g_layout.list.Width - Scale(12), row.height - Scale(2));
            if (dragged) {
                FillRoundRect(graphics, ToRectF(headerBox), (gp::REAL)Scale(4),
                              palette.selection);
                StrokeRoundRect(graphics, ToRectF(headerBox), (gp::REAL)Scale(4),
                                palette.accent, 1.0f);
            } else if (hoverWeight > 0.01) {
                FillRoundRect(graphics, ToRectF(headerBox), (gp::REAL)Scale(4),
                              Fade(palette.hover, hoverWeight));
            }
            double openAmount = 1.0;
            auto found = g_groupOpenAmount.find(row.text);
            if (found != g_groupOpenAmount.end()) {
                openAmount = Ease(found->second);
            }
            DrawChevron(graphics,
                        gp::Rect(headerBox.X + Scale(4), rowTop, Scale(16), row.height),
                        openAmount, palette.textDim);
            surface.RenderText(
                row.text, UiFont(-2, true), palette.textDim,
                gp::Rect(headerBox.X + Scale(22), rowTop,
                         g_layout.list.Width - Scale(40) - Scale(52), row.height),
                kTextLeft);
            bool toggleHovered = g_hover.kind == HitKind::GroupToggleAll &&
                                 g_hover.index == (int)rowIndex;
            surface.RenderText(
                L"toggle", UiFont(-3), toggleHovered ? palette.accent : palette.textDim,
                gp::Rect(g_layout.list.X + g_layout.list.Width - pad - Scale(52), rowTop,
                         Scale(52), row.height),
                kTextCenter);
            continue;
        }

        const StackItem& item = g_settings.items[row.itemIndex];
        bool focused = g_focusRow == (int)rowIndex;
        gp::Rect rowBox(g_layout.list.X + Scale(6), rowTop,
                        g_layout.list.Width - Scale(12), row.height - Scale(2));

        if (dragged) {
            FillRoundRect(graphics, ToRectF(rowBox), (gp::REAL)Scale(4),
                          palette.selection);
            StrokeRoundRect(graphics, ToRectF(rowBox), (gp::REAL)Scale(4),
                            palette.accent, 1.0f);
        } else if (focused) {
            FillRoundRect(graphics, ToRectF(rowBox), (gp::REAL)Scale(4),
                          palette.selection);
        } else if (hoverWeight > 0.01) {
            FillRoundRect(graphics, ToRectF(rowBox), (gp::REAL)Scale(4),
                          Fade(g_pressed.index == (int)rowIndex &&
                                       g_pressed.kind == HitKind::Item
                                   ? palette.press
                                   : palette.hover,
                               hoverWeight));
        }
        if (focused) {
            gp::SolidBrush bar(palette.accent);
            graphics.FillRectangle(&bar, (gp::REAL)rowBox.X, (gp::REAL)rowBox.Y + 2,
                                   (gp::REAL)Scale(2), (gp::REAL)rowBox.Height - 4);
        }

        int iconSize = Scale(compact ? 16 : 22);
        gp::Rect iconBox(rowBox.X + Scale(10), rowTop + (row.height - iconSize) / 2,
                         iconSize, iconSize);
        DrawItemIcon(surface, iconBox, item, palette);

        int textLeft = iconBox.X + iconSize + Scale(10);
        int textRight = ToggleLeftEdge() - Scale(8);
        if (showDots) {
            textRight -= Scale(12);
        }
        int textWidth = max(Scale(30), textRight - textLeft);

        std::wstring subtitleText =
            item.description.empty() ? item.target : item.description;
        if (!compact && !subtitleText.empty()) {
            surface.RenderText(item.name, UiFont(-1),
                               item.enabled ? palette.text : palette.textDim,
                               gp::Rect(textLeft, rowTop + Scale(5), textWidth, Scale(18)),
                               kTextLeft);
            surface.RenderText(subtitleText, UiFont(-3), palette.textDim,
                               gp::Rect(textLeft, rowTop + Scale(22), textWidth,
                                        Scale(15)),
                               kTextLeft);
        } else {
            surface.RenderText(item.name, UiFont(-1),
                               item.enabled ? palette.text : palette.textDim,
                               gp::Rect(textLeft, rowTop, textWidth, row.height),
                               kTextLeft);
        }

        if (showDots && item.running) {
            gp::SolidBrush dot(palette.running);
            int dotSize = Scale(6);
            graphics.FillEllipse(&dot, (gp::REAL)(textRight + Scale(5)),
                                 (gp::REAL)(rowTop + (row.height - dotSize) / 2),
                                 (gp::REAL)dotSize, (gp::REAL)dotSize);
        }

        double toggleValue = row.itemIndex < (int)g_toggleAmount.size()
                                 ? g_toggleAmount[row.itemIndex]
                                 : (item.enabled ? 1.0 : 0.0);
        DrawToggle(surface,
                   gp::Rect(g_layout.list.X + g_layout.list.Width - pad - Scale(34),
                            rowTop + (row.height - Scale(18)) / 2, Scale(34), Scale(18)),
                   toggleValue, palette,
                   g_hover.kind == HitKind::ItemToggle && g_hover.index == (int)rowIndex);
    }

    surface.ClearClip();

    if (g_layout.scrollThumb.Height > 0) {
        FillRoundRect(graphics, ToRectF(g_layout.scrollThumb),
                      (gp::REAL)g_layout.scrollThumb.Width / 2, palette.scrollbar);
    }

    graphics.DrawLine(&dividerPen, (gp::REAL)(g_layout.footer.X + pad),
                      (gp::REAL)g_layout.footer.Y,
                      (gp::REAL)(g_layout.footer.X + g_layout.footer.Width - pad),
                      (gp::REAL)g_layout.footer.Y);

    if (g_launching) {
        surface.RenderText(StatusText(), UiFont(-2), palette.text,
                           gp::Rect(g_layout.footer.X + pad, g_layout.footer.Y + Scale(9),
                                    g_layout.footer.Width - pad * 2 - Scale(72),
                                    Scale(18)),
                           kTextLeft);
        FillRoundRect(graphics, ToRectF(g_layout.progressBar), 1.5f, palette.surface);
        if (g_progressAmount > 0.001) {
            FillRoundRect(
                graphics,
                gp::RectF((gp::REAL)g_layout.progressBar.X,
                          (gp::REAL)g_layout.progressBar.Y,
                          (gp::REAL)max(Scale(4),
                                        (int)(g_layout.progressBar.Width *
                                              min(1.0, g_progressAmount))),
                          (gp::REAL)g_layout.progressBar.Height),
                1.5f, palette.accent);
        }
        DrawTextButton(surface, g_layout.cancelButton, L"Cancel", palette, false, true,
                       g_hover.kind == HitKind::Cancel,
                       g_pressed.kind == HitKind::Cancel);
    } else {
        DrawSmallButton(surface, g_layout.selectAllButton, L"\uE73A", palette,
                        g_hover.kind == HitKind::SelectAll,
                        g_pressed.kind == HitKind::SelectAll);
        DrawSmallButton(surface, g_layout.selectNoneButton, L"\uE739", palette,
                        g_hover.kind == HitKind::SelectNone,
                        g_pressed.kind == HitKind::SelectNone);
        DrawSmallButton(surface, g_layout.refreshButton, L"\uE72C", palette,
                        g_hover.kind == HitKind::Refresh,
                        g_pressed.kind == HitKind::Refresh);

        if (g_layout.closeButton.Width > 0) {
            wchar_t closeLabel[48];
            if (runningSelected == 0) {
                wcscpy_s(closeLabel, L"Close");
            } else {
                swprintf_s(closeLabel, L"Close %d", runningSelected);
            }
            DrawTextButton(surface, g_layout.closeButton, closeLabel, palette, false,
                           runningSelected > 0, g_hover.kind == HitKind::Close,
                           g_pressed.kind == HitKind::Close);
        }

        wchar_t launchLabel[48];
        if (selected == 0) {
            wcscpy_s(launchLabel, L"Nothing selected");
        } else {
            swprintf_s(launchLabel, L"Launch %d", selected);
        }
        DrawTextButton(surface, g_layout.launchButton, launchLabel, palette, true,
                       selected > 0, g_hover.kind == HitKind::Launch,
                       g_pressed.kind == HitKind::Launch);
    }

    int slide = (int)((1.0 - reveal) * Scale(12));
    int top = g_panelGrowsUp ? g_panelAnchorBottom - g_layout.window.Height
                             : g_panelBaseY;
    SetWindowPos(g_panelWnd, HWND_TOPMOST, g_panelBaseX, top + slide,
                 g_layout.window.Width, g_layout.window.Height,
                 SWP_NOACTIVATE | SWP_NOREDRAW);
    g_panelSurface.Present(g_panelWnd, (BYTE)(255 * max(0.0, min(1.0, reveal))));
}

static int DraggedRowIndex() {
    for (size_t i = 0; i < g_rows.size(); i++) {
        const PanelRow& row = g_rows[i];
        bool match = g_dragItemIndex >= 0
                         ? !row.isGroup && row.itemIndex == g_dragItemIndex
                         : row.isGroup && row.text == g_dragGroup;
        if (match) {
            return (int)i;
        }
    }
    return -1;
}

static bool RowHit(const HitResult& hit) {
    return hit.kind == HitKind::Item || hit.kind == HitKind::ItemToggle ||
           hit.kind == HitKind::GroupHeader || hit.kind == HitKind::GroupToggleAll;
}

static void EndDrag(bool persist) {
    if (!g_dragActive) {
        return;
    }
    g_dragActive = false;
    g_dragItemIndex = -1;
    g_dragGroup.clear();
    g_dragCandidate = HitResult{};
    ReleaseCapture();
    if (persist) {
        SaveItemOrder();
    }
}

static void RefreshPanel() {
    if (g_panelWnd && IsWindowVisible(g_panelWnd)) {
        PaintPanel();
    }
}

static void EnsureAnimationTimer() {
    if (g_panelWnd) {
        SetTimer(g_panelWnd, kTimerAnimate, kFrameMs, nullptr);
    }
}

static HWND AnchorWindow() {
    std::lock_guard<std::mutex> lock(g_buttonMutex);
    for (HWND button : g_buttonWnds) {
        if (IsWindow(button)) {
            return button;
        }
    }
    return nullptr;
}

static void PositionPanel() {
    RebuildRows();
    ComputeLayout();

    RECT anchorRect{};
    HWND anchor = AnchorWindow();
    if (anchor) {
        GetWindowRect(anchor, &anchorRect);
    } else {
        POINT cursor{};
        GetCursorPos(&cursor);
        anchorRect = RECT{cursor.x, cursor.y, cursor.x, cursor.y};
    }

    MONITORINFO monitorInfo{sizeof(monitorInfo)};
    GetMonitorInfoW(MonitorFromRect(&anchorRect, MONITOR_DEFAULTTONEAREST),
                    &monitorInfo);
    const RECT& work = monitorInfo.rcWork;
    int width = g_layout.window.Width;
    int height = g_layout.window.Height;

    int x = anchorRect.left + (anchorRect.right - anchorRect.left) / 2 - width / 2;
    x = max((int)work.left - g_layout.shadow,
            min(x, (int)work.right - width + g_layout.shadow));

    bool growsUp = true;
    int y = anchorRect.top - height + g_layout.shadow;
    if (y < work.top) {
        y = anchorRect.bottom - g_layout.shadow;
        growsUp = false;
    }
    y = max((int)work.top - g_layout.shadow,
            min(y, (int)work.bottom - height + g_layout.shadow));

    g_panelBaseX = x;
    g_panelBaseY = y;
    g_panelAnchorBottom = y + height;
    g_panelGrowsUp = growsUp;
    SetWindowPos(g_panelWnd, HWND_TOPMOST, x, y, width, height, SWP_NOACTIVATE);
}

static void ForceForeground(HWND window) {
    DWORD currentThread = GetCurrentThreadId();
    DWORD foregroundThread = GetWindowThreadProcessId(GetForegroundWindow(), nullptr);
    bool attached = foregroundThread && foregroundThread != currentThread &&
                    AttachThreadInput(currentThread, foregroundThread, TRUE);
    SetForegroundWindow(window);
    SetFocus(window);
    if (attached) {
        AttachThreadInput(currentThread, foregroundThread, FALSE);
    }
}

static void RefreshTaskbarButtons() {
    std::lock_guard<std::mutex> lock(g_buttonMutex);
    for (HWND button : g_buttonWnds) {
        if (IsWindow(button)) {
            PostMessageW(button, kMsgButtonRefresh, 0, 0);
        }
    }
}

static void OpenPanel() {
    if (!g_panelWnd) {
        return;
    }
    RefreshPalette();
    LoadCollapsedGroups();
    NormalizeItemOrder();
    g_filter.clear();
    g_focusRow = -1;
    g_scrollOffset = 0;
    g_hover = HitResult{};
    g_pressed = HitResult{};
    g_hoverFading = HitResult{};
    g_hoverAmount = 0.0;
    g_hoverFadeAmount = 0.0;
    g_caretVisible = true;
    g_revealAmount = g_animationSpeed.load() > 0.0 ? 0.0 : 1.0;
    g_revealTarget = 1.0;

    PositionPanel();
    PaintPanel();
    ShowWindow(g_panelWnd, SW_SHOWNOACTIVATE);
    ForceForeground(g_panelWnd);
    g_panelOpen = true;

    SetTimer(g_panelWnd, kTimerCaret, 530, nullptr);
    SetTimer(g_panelWnd, kTimerStatus, 2500, nullptr);
    EnsureAnimationTimer();
    RefreshRunningStatus();
    RefreshTaskbarButtons();
}

static void FinishClosingPanel() {
    KillTimer(g_panelWnd, kTimerCaret);
    KillTimer(g_panelWnd, kTimerStatus);
    KillTimer(g_panelWnd, kTimerAnimate);
    ShowWindow(g_panelWnd, SW_HIDE);
    g_panelHiddenTick = GetTickCount64();
    RefreshTaskbarButtons();
}

static void ClosePanel() {
    if (!g_panelWnd || !g_panelOpen) {
        return;
    }
    g_panelOpen = false;
    g_panelHiddenTick = GetTickCount64();
    g_revealTarget = 0.0;
    if (g_animationSpeed.load() <= 0.0) {
        g_revealAmount = 0.0;
        FinishClosingPanel();
        return;
    }
    EnsureAnimationTimer();
    RefreshTaskbarButtons();
}

static void TogglePanel() {
    if (g_panelOpen) {
        ClosePanel();
        return;
    }
    if (GetTickCount64() - g_panelHiddenTick < 220) {
        return;
    }
    OpenPanel();
}

static void SetHover(const HitResult& hit) {
    if (hit == g_hover) {
        return;
    }
    g_hoverFading = g_hover;
    g_hoverFadeAmount = g_hoverAmount;
    g_hover = hit;
    g_hoverAmount = 0.0;
    EnsureAnimationTimer();
}

static void ScrollRowIntoView(int rowIndex) {
    if (rowIndex < 0 || rowIndex >= (int)g_rows.size()) {
        return;
    }
    const PanelRow& row = g_rows[rowIndex];
    if (row.top < g_scrollOffset) {
        g_scrollOffset = row.top;
    } else if (row.top + row.height > g_scrollOffset + g_layout.list.Height) {
        g_scrollOffset = row.top + row.height - g_layout.list.Height;
    }
    ClampScroll();
}

static void MoveFocus(int delta) {
    if (g_rows.empty()) {
        return;
    }
    int index = g_focusRow;
    for (int step = 0; step < (int)g_rows.size(); step++) {
        index += delta;
        if (index < 0) {
            index = (int)g_rows.size() - 1;
        }
        if (index >= (int)g_rows.size()) {
            index = 0;
        }
        if (!g_rows[index].isGroup && RowVisible(g_rows[index])) {
            g_focusRow = index;
            break;
        }
    }
    ScrollRowIntoView(g_focusRow);
}

static void FocusEdge(bool last) {
    g_focusRow = -1;
    MoveFocus(last ? -1 : 1);
}

static void LaunchSelected() {
    std::vector<int> indices = SelectedIndices();
    if (indices.empty()) {
        return;
    }
    bool confirm = false;
    bool closeAfter = false;
    {
        std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
        confirm = g_settings.confirmBeforeLaunchAll;
        closeAfter = g_settings.closeAfterLaunch;
    }
    if (confirm) {
        wchar_t message[128];
        swprintf_s(message, L"Launch %d items?", (int)indices.size());
        g_suppressDeactivate = true;
        int answer = MessageBoxW(g_panelWnd, message, L"Tech Stack Launcher",
                                 MB_OKCANCEL | MB_ICONQUESTION);
        g_suppressDeactivate = false;
        if (answer != IDOK) {
            return;
        }
    }
    StartLaunch(std::move(indices));
    if (closeAfter) {
        ClosePanel();
    }
}

static void CloseSelected() {
    std::vector<int> indices = RunningSelectedIndices();
    if (indices.empty()) {
        SetStatusText(L"Nothing selected is running");
        return;
    }
    std::reverse(indices.begin(), indices.end());

    bool confirm = false;
    bool closeAfter = false;
    {
        std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
        confirm = g_settings.confirmBeforeClose;
        closeAfter = g_settings.closeAfterLaunch;
    }
    if (confirm) {
        wchar_t message[128];
        swprintf_s(message, L"Close %d items?", (int)indices.size());
        g_suppressDeactivate = true;
        int answer = MessageBoxW(g_panelWnd, message, L"Tech Stack Launcher",
                                 MB_OKCANCEL | MB_ICONWARNING);
        g_suppressDeactivate = false;
        if (answer != IDOK) {
            return;
        }
    }
    StartShutdown(std::move(indices));
    if (closeAfter) {
        ClosePanel();
    }
}

static void FocusItemRow(int itemIndex) {
    for (size_t i = 0; i < g_rows.size(); i++) {
        if (!g_rows[i].isGroup && g_rows[i].itemIndex == itemIndex) {
            g_focusRow = (int)i;
            ScrollRowIntoView(g_focusRow);
            return;
        }
    }
}

static void ShowGroupMenu(int rowIndex, POINT screenPoint) {
    if (rowIndex < 0 || rowIndex >= (int)g_rows.size() || !g_rows[rowIndex].isGroup) {
        return;
    }
    std::wstring group = g_rows[rowIndex].text;

    HMENU menu = CreatePopupMenu();
    if (!menu) {
        return;
    }
    AppendMenuW(menu, MF_STRING, 1,
                IsGroupCollapsed(group) ? L"Expand" : L"Collapse");
    AppendMenuW(menu, MF_STRING, 2, L"Toggle every item");
    AppendMenuW(menu, MF_SEPARATOR, 0, nullptr);
    AppendMenuW(menu, MF_STRING, 3, L"Move group up");
    AppendMenuW(menu, MF_STRING, 4, L"Move group down");
    AppendMenuW(menu, MF_STRING, 5, L"Reset order to settings");

    g_suppressDeactivate = true;
    SetForegroundWindow(g_panelWnd);
    int command = TrackPopupMenu(menu, TPM_RETURNCMD | TPM_RIGHTBUTTON, screenPoint.x,
                                 screenPoint.y, 0, g_panelWnd, nullptr);
    DestroyMenu(menu);
    g_suppressDeactivate = false;

    switch (command) {
        case 1:
            SetGroupCollapsed(group, !IsGroupCollapsed(group));
            EnsureAnimationTimer();
            break;
        case 2:
            SetGroupEnabled(group);
            EnsureAnimationTimer();
            break;
        case 3:
            if (MoveGroupBlock(group, -1)) {
                SaveItemOrder();
            }
            break;
        case 4:
            if (MoveGroupBlock(group, 1)) {
                SaveItemOrder();
            }
            break;
        case 5:
            ResetItemOrder();
            break;
        default:
            break;
    }
}

static void ShowItemMenu(int rowIndex, POINT screenPoint) {
    if (rowIndex < 0 || rowIndex >= (int)g_rows.size() || g_rows[rowIndex].isGroup) {
        return;
    }
    int itemIndex = g_rows[rowIndex].itemIndex;
    StackItem item;
    {
        std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
        if (itemIndex < 0 || itemIndex >= (int)g_settings.items.size()) {
            return;
        }
        item = g_settings.items[itemIndex];
    }

    HMENU menu = CreatePopupMenu();
    if (!menu) {
        return;
    }
    AppendMenuW(menu, MF_STRING, 1, L"Launch now");
    if (item.running) {
        AppendMenuW(menu, MF_STRING, 5, L"Close now");
    }
    AppendMenuW(menu, MF_STRING, 2, item.enabled ? L"Turn off" : L"Turn on");
    AppendMenuW(menu, MF_SEPARATOR, 0, nullptr);
    AppendMenuW(menu, MF_STRING, 6, L"Move up");
    AppendMenuW(menu, MF_STRING, 7, L"Move down");
    AppendMenuW(menu, MF_STRING, 8, L"Reset order to settings");
    AppendMenuW(menu, MF_SEPARATOR, 0, nullptr);
    AppendMenuW(menu, MF_STRING, 3, L"Show in File Explorer");
    AppendMenuW(menu, MF_STRING, 4, L"Copy target");

    g_suppressDeactivate = true;
    SetForegroundWindow(g_panelWnd);
    int command = TrackPopupMenu(menu, TPM_RETURNCMD | TPM_RIGHTBUTTON, screenPoint.x,
                                 screenPoint.y, 0, g_panelWnd, nullptr);
    DestroyMenu(menu);
    g_suppressDeactivate = false;

    switch (command) {
        case 1:
            StartLaunch({itemIndex});
            break;
        case 2:
            SetItemEnabled(itemIndex, !item.enabled);
            EnsureAnimationTimer();
            break;
        case 3:
            OpenContainingFolder(item);
            break;
        case 4:
            CopyToClipboard(ExpandTokens(item.target));
            break;
        case 5:
            StartShutdown({itemIndex});
            break;
        case 6:
            if (MoveItemWithinGroup(itemIndex, -1)) {
                SaveItemOrder();
            }
            break;
        case 7:
            if (MoveItemWithinGroup(itemIndex, 1)) {
                SaveItemOrder();
            }
            break;
        case 8:
            ResetItemOrder();
            break;
        default:
            break;
    }
}

static void HandleClick(const HitResult& hit) {
    switch (hit.kind) {
        case HitKind::Outside:
            ClosePanel();
            break;
        case HitKind::Settings:
            OpenWindhawk();
            ClosePanel();
            break;
        case HitKind::Chip:
            if (hit.index >= 0 && hit.index < (int)g_layout.chipNames.size()) {
                ApplyProfile(g_layout.chipNames[hit.index]);
                EnsureAnimationTimer();
            }
            break;
        case HitKind::SearchClear:
            g_filter.clear();
            g_scrollOffset = 0;
            break;
        case HitKind::ItemToggle:
            if (hit.index >= 0 && hit.index < (int)g_rows.size()) {
                int itemIndex = g_rows[hit.index].itemIndex;
                bool enabled = false;
                {
                    std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
                    if (itemIndex < 0 || itemIndex >= (int)g_settings.items.size()) {
                        break;
                    }
                    enabled = g_settings.items[itemIndex].enabled;
                }
                SetItemEnabled(itemIndex, !enabled);
                EnsureAnimationTimer();
            }
            break;
        case HitKind::Item:
            if (hit.index >= 0 && hit.index < (int)g_rows.size()) {
                StartLaunch({g_rows[hit.index].itemIndex});
                bool closeAfter = false;
                {
                    std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
                    closeAfter = g_settings.closeAfterLaunch;
                }
                if (closeAfter) {
                    ClosePanel();
                }
            }
            break;
        case HitKind::GroupHeader:
            if (hit.index >= 0 && hit.index < (int)g_rows.size()) {
                const std::wstring& group = g_rows[hit.index].text;
                SetGroupCollapsed(group, !IsGroupCollapsed(group));
                EnsureAnimationTimer();
            }
            break;
        case HitKind::GroupToggleAll:
            if (hit.index >= 0 && hit.index < (int)g_rows.size()) {
                SetGroupEnabled(g_rows[hit.index].text);
                EnsureAnimationTimer();
            }
            break;
        case HitKind::Launch:
            LaunchSelected();
            break;
        case HitKind::Close:
            CloseSelected();
            break;
        case HitKind::SelectAll:
            SetAllEnabled(true);
            EnsureAnimationTimer();
            break;
        case HitKind::SelectNone:
            SetAllEnabled(false);
            EnsureAnimationTimer();
            break;
        case HitKind::Refresh:
            RefreshRunningStatus();
            break;
        case HitKind::Cancel:
            g_cancelLaunch = true;
            break;
        default:
            break;
    }
}

static LRESULT CALLBACK PanelWndProc(HWND window,
                                     UINT message,
                                     WPARAM wParam,
                                     LPARAM lParam) {
    switch (message) {
        case WM_MOUSEMOVE: {
            POINT point{GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam)};
            if (!g_dragActive && RowHit(g_dragCandidate) &&
                (GetKeyState(VK_LBUTTON) & 0x8000) &&
                abs(point.y - g_dragOrigin.y) > Scale(6) &&
                g_dragCandidate.index >= 0 &&
                g_dragCandidate.index < (int)g_rows.size()) {
                const PanelRow& row = g_rows[g_dragCandidate.index];
                if (row.isGroup) {
                    g_dragGroup = row.text;
                } else {
                    g_dragItemIndex = row.itemIndex;
                }
                g_dragActive = true;
                g_pressed = HitResult{};
                SetCapture(window);
            }
            if (g_dragActive) {
                HitResult over = HitTest(point);
                int from = DraggedRowIndex();
                if (RowHit(over) && from >= 0 && over.index != from) {
                    bool moved =
                        g_dragItemIndex >= 0
                            ? MoveItemWithinGroup(g_dragItemIndex,
                                                  over.index > from ? 1 : -1)
                            : MoveGroupBlock(g_dragGroup, over.index > from ? 1 : -1);
                    if (moved) {
                        RebuildRows();
                        PaintPanel();
                    }
                }
                return 0;
            }
            if (g_draggingScrollbar) {
                int travel =
                    g_layout.scrollTrack.Height - g_layout.scrollThumb.Height;
                if (travel > 0) {
                    g_scrollOffset =
                        (int)((double)(point.y - g_dragOffset - g_layout.scrollTrack.Y) /
                              travel * MaxScroll());
                    ClampScroll();
                    PaintPanel();
                }
                return 0;
            }
            SetHover(HitTest(point));
            TRACKMOUSEEVENT track{sizeof(track), TME_LEAVE, window, 0};
            TrackMouseEvent(&track);
            return 0;
        }

        case WM_MOUSELEAVE:
            SetHover(HitResult{});
            return 0;

        case WM_LBUTTONDOWN: {
            POINT point{GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam)};
            HitResult hit = HitTest(point);
            if (hit.kind == HitKind::Scrollbar) {
                g_dragOffset = Contains(g_layout.scrollThumb, point)
                                   ? point.y - g_layout.scrollThumb.Y
                                   : g_layout.scrollThumb.Height / 2;
                g_draggingScrollbar = true;
                SetCapture(window);
                return 0;
            }
            if (hit.kind == HitKind::Item || hit.kind == HitKind::GroupHeader) {
                g_dragCandidate = hit;
                g_dragOrigin = point;
            }
            g_pressed = hit;
            PaintPanel();
            return 0;
        }

        case WM_CAPTURECHANGED:
            g_draggingScrollbar = false;
            EndDrag(true);
            return 0;

        case WM_LBUTTONUP: {
            if (g_dragActive) {
                EndDrag(true);
                RefreshPanel();
                return 0;
            }
            g_dragCandidate = HitResult{};
            if (g_draggingScrollbar) {
                g_draggingScrollbar = false;
                ReleaseCapture();
                return 0;
            }
            POINT point{GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam)};
            HitResult hit = HitTest(point);
            HitResult pressed = g_pressed;
            g_pressed = HitResult{};
            if (hit == pressed) {
                HandleClick(hit);
            }
            RefreshPanel();
            return 0;
        }

        case WM_RBUTTONUP: {
            POINT point{GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam)};
            HitResult hit = HitTest(point);
            POINT screenPoint = point;
            ClientToScreen(window, &screenPoint);
            if (hit.kind == HitKind::Item || hit.kind == HitKind::ItemToggle) {
                ShowItemMenu(hit.index, screenPoint);
                RefreshPanel();
            } else if (hit.kind == HitKind::GroupHeader ||
                       hit.kind == HitKind::GroupToggleAll) {
                ShowGroupMenu(hit.index, screenPoint);
                RefreshPanel();
            }
            return 0;
        }

        case WM_MOUSEWHEEL:
            g_scrollOffset -=
                GET_WHEEL_DELTA_WPARAM(wParam) * RowHeight() / WHEEL_DELTA;
            ClampScroll();
            PaintPanel();
            return 0;

        case WM_CHAR: {
            wchar_t character = (wchar_t)wParam;
            if (character == VK_BACK) {
                if (!g_filter.empty()) {
                    g_filter.pop_back();
                    g_scrollOffset = 0;
                    PaintPanel();
                }
                return 0;
            }
            if (character == L' ' && g_focusRow >= 0) {
                HandleClick(HitResult{HitKind::ItemToggle, g_focusRow});
                return 0;
            }
            if (character >= L' ') {
                g_filter.push_back(character);
                g_scrollOffset = 0;
                g_focusRow = -1;
                PaintPanel();
            }
            return 0;
        }

        case WM_SYSKEYDOWN:
            if ((wParam == VK_UP || wParam == VK_DOWN) &&
                (GetKeyState(VK_MENU) & 0x8000) && g_focusRow >= 0 &&
                g_focusRow < (int)g_rows.size() && !g_rows[g_focusRow].isGroup) {
                int itemIndex = g_rows[g_focusRow].itemIndex;
                if (MoveItemWithinGroup(itemIndex, wParam == VK_UP ? -1 : 1)) {
                    SaveItemOrder();
                    RebuildRows();
                    FocusItemRow(itemIndex);
                }
                PaintPanel();
                return 0;
            }
            break;

        case WM_KEYDOWN: {
            bool control = (GetKeyState(VK_CONTROL) & 0x8000) != 0;
            switch (wParam) {
                case VK_ESCAPE:
                    if (!g_filter.empty()) {
                        g_filter.clear();
                        PaintPanel();
                    } else {
                        ClosePanel();
                    }
                    return 0;
                case VK_DOWN:
                    MoveFocus(1);
                    PaintPanel();
                    return 0;
                case VK_UP:
                    MoveFocus(-1);
                    PaintPanel();
                    return 0;
                case VK_HOME:
                    FocusEdge(false);
                    PaintPanel();
                    return 0;
                case VK_END:
                    FocusEdge(true);
                    PaintPanel();
                    return 0;
                case VK_PRIOR:
                    g_scrollOffset -= g_layout.list.Height;
                    ClampScroll();
                    PaintPanel();
                    return 0;
                case VK_NEXT:
                    g_scrollOffset += g_layout.list.Height;
                    ClampScroll();
                    PaintPanel();
                    return 0;
                case VK_RETURN:
                    if (control || g_focusRow < 0) {
                        LaunchSelected();
                    } else {
                        HandleClick(HitResult{HitKind::Item, g_focusRow});
                    }
                    return 0;
                case 'A':
                    if (control) {
                        SetAllEnabled(true);
                        EnsureAnimationTimer();
                        return 0;
                    }
                    break;
                case 'D':
                    if (control) {
                        SetAllEnabled(false);
                        EnsureAnimationTimer();
                        return 0;
                    }
                    break;
            }
            break;
        }

        case WM_ACTIVATE:
            if (LOWORD(wParam) == WA_INACTIVE && !g_suppressDeactivate) {
                ClosePanel();
            }
            return 0;

        case WM_TIMER:
            if (wParam == kTimerAnimate) {
                bool stillAnimating = StepAnimations();
                if (!g_panelOpen && g_revealAmount <= 0.0) {
                    FinishClosingPanel();
                    return 0;
                }
                PaintPanel();
                if (!stillAnimating) {
                    KillTimer(window, kTimerAnimate);
                }
                return 0;
            }
            if (wParam == kTimerCaret) {
                g_caretVisible = !g_caretVisible;
                RefreshPanel();
                return 0;
            }
            if (wParam == kTimerStatus) {
                RefreshRunningStatus();
                return 0;
            }
            break;

        case kMsgStatusReady:
        case kMsgIconReady:
            RefreshPanel();
            return 0;

        case kMsgLaunchProgress:
            EnsureAnimationTimer();
            RefreshPanel();
            return 0;

        case kMsgLaunchFinished:
            EnsureAnimationTimer();
            RefreshPanel();
            RefreshTaskbarButtons();
            RefreshRunningStatus();
            return 0;
    }
    return DefWindowProcW(window, message, wParam, lParam);
}

static bool TaskbarUsesLightTheme() {
    HKEY key = nullptr;
    if (RegOpenKeyExW(HKEY_CURRENT_USER,
                      L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\"
                      L"Personalize",
                      0, KEY_QUERY_VALUE, &key) != ERROR_SUCCESS) {
        return false;
    }
    DWORD value = 0;
    DWORD size = sizeof(value);
    DWORD type = 0;
    LSTATUS status = RegQueryValueExW(key, L"SystemUsesLightTheme", nullptr, &type,
                                      (LPBYTE)&value, &size);
    RegCloseKey(key);
    return status == ERROR_SUCCESS && type == REG_DWORD && value != 0;
}

struct TaskbarAnchors {
    int width = 0;
    int height = 0;
    bool hasTray = false;
    int trayLeft = 0;
    int trayRight = 0;
    bool hasTaskList = false;
    int taskListLeft = 0;
    int taskListRight = 0;
};

static TaskbarAnchors ReadAnchors(HWND taskbar) {
    TaskbarAnchors anchors;
    RECT client{};
    RECT screen{};
    if (!GetClientRect(taskbar, &client) || !GetWindowRect(taskbar, &screen)) {
        return anchors;
    }
    anchors.width = client.right - client.left;
    anchors.height = client.bottom - client.top;

    auto read = [&](PCWSTR className, bool& has, int& left, int& right) {
        HWND child = FindWindowExW(taskbar, nullptr, className, nullptr);
        RECT childRect{};
        if (!child || !IsWindowVisible(child) || !GetWindowRect(child, &childRect)) {
            return;
        }
        int childLeft = childRect.left - screen.left;
        int childRight = childRect.right - screen.left;
        if (childRight <= childLeft || childLeft < 0 || childRight > anchors.width) {
            return;
        }
        has = true;
        left = childLeft;
        right = childRight;
    };
    read(L"TrayNotifyWnd", anchors.hasTray, anchors.trayLeft, anchors.trayRight);
    read(L"ReBarWindow32", anchors.hasTaskList, anchors.taskListLeft,
         anchors.taskListRight);
    return anchors;
}

struct ButtonState {
    Surface surface;
    double hover = 0.0;
    double press = 0.0;
    bool hovered = false;
    bool pressed = false;
};

static ButtonState& StateOf(HWND window) {
    auto* state = reinterpret_cast<ButtonState*>(GetWindowLongPtrW(window, GWLP_USERDATA));
    if (!state) {
        state = new ButtonState();
        SetWindowLongPtrW(window, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(state));
    }
    return *state;
}

static SIZE MeasureButton() {
    ButtonStyle style;
    std::wstring label;
    {
        std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
        style = g_settings.buttonStyle;
        label = g_settings.buttonLabel;
    }
    int width = Scale(20);
    if (style != ButtonStyle::Label) {
        width += Scale(16);
    }
    if (style != ButtonStyle::Glyph && !label.empty()) {
        width += MeasureText(label, UiFont(-1)) + Scale(6);
    }
    return SIZE{max(Scale(32), width), Scale(30)};
}

static void PaintButton(HWND window) {
    ButtonState& state = StateOf(window);
    RECT rect{};
    GetWindowRect(window, &rect);
    int width = rect.right - rect.left;
    int height = rect.bottom - rect.top;
    if (!state.surface.Resize(width, height)) {
        return;
    }
    state.surface.Clear();
    gp::Graphics& graphics = *state.surface.Graphics();

    Palette palette = CurrentPalette();
    bool open = g_panelOpen.load();
    bool light = TaskbarUsesLightTheme();

    ButtonStyle style;
    std::wstring glyphSource;
    std::wstring label;
    {
        std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
        style = g_settings.buttonStyle;
        glyphSource = g_settings.buttonGlyph;
        label = g_settings.buttonLabel;
    }

    gp::Color base = light ? gp::Color(255, 0, 0, 0) : gp::Color(255, 255, 255, 255);
    double lift = 0.08 + 0.10 * state.hover + 0.10 * state.press;
    gp::Color background = open ? palette.accent : Fade(base, lift);
    gp::RectF body(1.0f, 1.0f, (gp::REAL)width - 2, (gp::REAL)height - 2);
    gp::REAL radius = (gp::REAL)Scale(6);
    FillRoundRect(graphics, body, radius, background);
    if (!open) {
        StrokeRoundRect(graphics, body, radius, Fade(base, 0.12), 1.0f);
    }

    gp::Color foreground = open ? palette.accentText : base;
    int contentLeft = Scale(10);
    if (style != ButtonStyle::Label) {
        std::wstring glyph;
        if (!ParseGlyph(glyphSource, glyph)) {
            glyph = glyphSource.empty() ? std::wstring(L"\uE768") : glyphSource;
        }
        state.surface.RenderText(glyph, IconFont(-2), foreground,
                                 gp::Rect(contentLeft, 0, Scale(16), height),
                                 kTextCenter);
        contentLeft += Scale(16) + Scale(4);
    }
    if (style != ButtonStyle::Glyph && !label.empty()) {
        state.surface.RenderText(
            label, UiFont(-1), foreground,
            gp::Rect(contentLeft, 0, width - contentLeft - Scale(8), height),
            kTextLeft);
    }

    state.surface.Present(window, 255);
}

static void PositionButton(HWND window) {
    HWND taskbar = GetParent(window);
    if (!taskbar) {
        return;
    }
    TaskbarAnchors anchors = ReadAnchors(taskbar);
    if (anchors.width <= 0 || anchors.height <= 0) {
        return;
    }

    UINT dpi = GetDpiForWindow(taskbar);
    if (dpi >= 72) {
        g_dpi = dpi;
    }

    SIZE size = MeasureButton();
    size.cy = min((int)size.cy, max(Scale(18), anchors.height - Scale(6)));

    ButtonPosition position;
    ButtonAlign align;
    int offset = 0;
    int offsetY = 0;
    int percent = 50;
    {
        std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
        position = g_settings.buttonPosition;
        align = g_settings.buttonAlign;
        offset = g_settings.buttonOffset;
        offsetY = g_settings.buttonOffsetY;
        percent = g_settings.buttonPercent;
    }
    int scaledOffset = Scale(offset);

    int x = 0;
    switch (position) {
        case ButtonPosition::Left:
            x = scaledOffset;
            break;
        case ButtonPosition::Center:
            x = (anchors.width - size.cx) / 2 + scaledOffset;
            break;
        case ButtonPosition::Percent:
            x = anchors.width * percent / 100 - size.cx / 2 + scaledOffset;
            break;
        case ButtonPosition::BeforeTray:
            x = (anchors.hasTray ? anchors.trayLeft : anchors.width) - size.cx -
                scaledOffset;
            break;
        case ButtonPosition::AfterTray:
            x = (anchors.hasTray ? anchors.trayRight : anchors.width) - size.cx +
                scaledOffset;
            break;
        case ButtonPosition::BeforeTaskList:
            x = (anchors.hasTaskList ? anchors.taskListLeft : 0) - size.cx -
                scaledOffset;
            break;
        case ButtonPosition::AfterTaskList:
            x = (anchors.hasTaskList ? anchors.taskListRight : 0) + scaledOffset;
            break;
        default:
            x = anchors.width - size.cx - scaledOffset;
            break;
    }
    x = max(0, min(x, anchors.width - (int)size.cx));

    int y = align == ButtonAlign::Top      ? 0
            : align == ButtonAlign::Bottom ? anchors.height - size.cy
                                           : (anchors.height - size.cy) / 2;
    y = max(0, min(y + Scale(offsetY), anchors.height - (int)size.cy));

    RECT current{};
    GetWindowRect(window, &current);
    POINT topLeft{current.left, current.top};
    ScreenToClient(taskbar, &topLeft);
    if (topLeft.x != x || topLeft.y != y || current.right - current.left != size.cx ||
        current.bottom - current.top != size.cy) {
        SetWindowPos(window, HWND_TOP, x, y, size.cx, size.cy, SWP_NOACTIVATE);
        PaintButton(window);
    } else if (GetWindow(window, GW_HWNDPREV)) {
        SetWindowPos(window, HWND_TOP, 0, 0, 0, 0,
                     SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
    }
}

static LRESULT CALLBACK ButtonWndProc(HWND window,
                                      UINT message,
                                      WPARAM wParam,
                                      LPARAM lParam) {
    switch (message) {
        case WM_CREATE:
            SetTimer(window, kTimerButtonLayout, 400, nullptr);
            PositionButton(window);
            PaintButton(window);
            return 0;

        case WM_TIMER:
            if (wParam == kTimerButtonLayout) {
                PositionButton(window);
                return 0;
            }
            if (wParam == kTimerAnimate) {
                ButtonState& state = StateOf(window);
                bool animating = Approach(state.hover, state.hovered ? 1.0 : 0.0, 0.05);
                animating |= Approach(state.press, state.pressed ? 1.0 : 0.0, 0.04);
                PaintButton(window);
                if (!animating) {
                    KillTimer(window, kTimerAnimate);
                }
                return 0;
            }
            break;

        case WM_MOUSEMOVE: {
            ButtonState& state = StateOf(window);
            if (!state.hovered) {
                state.hovered = true;
                TRACKMOUSEEVENT track{sizeof(track), TME_LEAVE, window, 0};
                TrackMouseEvent(&track);
                SetTimer(window, kTimerAnimate, kFrameMs, nullptr);
            }
            return 0;
        }

        case WM_MOUSELEAVE: {
            ButtonState& state = StateOf(window);
            state.hovered = false;
            state.pressed = false;
            SetTimer(window, kTimerAnimate, kFrameMs, nullptr);
            return 0;
        }

        case WM_LBUTTONDOWN:
            StateOf(window).pressed = true;
            SetTimer(window, kTimerAnimate, kFrameMs, nullptr);
            return 0;

        case WM_LBUTTONUP:
        case WM_RBUTTONUP:
            StateOf(window).pressed = false;
            SetTimer(window, kTimerAnimate, kFrameMs, nullptr);
            if (g_messageWnd) {
                PostMessageW(g_messageWnd, kMsgTogglePanel, 0, 0);
            }
            return 0;

        case kMsgButtonRefresh:
            PositionButton(window);
            PaintButton(window);
            return 0;

        case kMsgButtonClose:
            DestroyWindow(window);
            return 0;

        case WM_DESTROY: {
            KillTimer(window, kTimerButtonLayout);
            KillTimer(window, kTimerAnimate);
            auto* state =
                reinterpret_cast<ButtonState*>(GetWindowLongPtrW(window, GWLP_USERDATA));
            SetWindowLongPtrW(window, GWLP_USERDATA, 0);
            delete state;
            return 0;
        }
    }
    return DefWindowProcW(window, message, wParam, lParam);
}

struct CreateButtonContext {
    HWND taskbar;
    HWND created;
};

static void CreateButtonOnTaskbarThread(void* parameter) {
    auto* context = reinterpret_cast<CreateButtonContext*>(parameter);
    context->created = CreateWindowExW(
        WS_EX_LAYERED | WS_EX_NOPARENTNOTIFY, kButtonClass, L"",
        WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS, 0, 0, Scale(80), Scale(30),
        context->taskbar, nullptr, GetModuleHandleW(nullptr), nullptr);
}

using WindowThreadProc = void (*)(void*);

static bool RunFromWindowThread(HWND window, WindowThreadProc proc, void* parameter) {
    static const UINT message =
        RegisterWindowMessageW(L"WhTechStackLauncher_RunFromWindowThread_" WH_MOD_ID);
    struct Payload {
        WindowThreadProc proc;
        void* parameter;
    };
    DWORD threadId = GetWindowThreadProcessId(window, nullptr);
    if (!threadId) {
        return false;
    }
    if (threadId == GetCurrentThreadId()) {
        proc(parameter);
        return true;
    }
    HHOOK hook = SetWindowsHookExW(
        WH_CALLWNDPROC,
        [](int code, WPARAM wParam, LPARAM lParam) CALLBACK -> LRESULT {
            if (code == HC_ACTION) {
                auto* call = reinterpret_cast<const CWPSTRUCT*>(lParam);
                static const UINT inner = RegisterWindowMessageW(
                    L"WhTechStackLauncher_RunFromWindowThread_" WH_MOD_ID);
                if (call->message == inner) {
                    auto* payload = reinterpret_cast<Payload*>(call->lParam);
                    payload->proc(payload->parameter);
                }
            }
            return CallNextHookEx(nullptr, code, wParam, lParam);
        },
        nullptr, threadId);
    if (!hook) {
        return false;
    }
    Payload payload{proc, parameter};
    DWORD_PTR result = 0;
    SendMessageTimeoutW(window, message, 0, reinterpret_cast<LPARAM>(&payload),
                        SMTO_ABORTIFHUNG | SMTO_NORMAL, 5000, &result);
    UnhookWindowsHookEx(hook);
    return true;
}

static HWND FindTaskbarOfClass(PCWSTR className) {
    struct Context {
        PCWSTR className;
        HWND found;
    };
    Context context{className, nullptr};
    EnumWindows(
        [](HWND window, LPARAM param) CALLBACK -> BOOL {
            auto* context = reinterpret_cast<Context*>(param);
            DWORD pid = 0;
            wchar_t name[48] = {};
            if (GetWindowThreadProcessId(window, &pid) &&
                pid == GetCurrentProcessId() &&
                GetClassNameW(window, name, ARRAYSIZE(name)) &&
                wcscmp(name, context->className) == 0) {
                context->found = window;
                return FALSE;
            }
            return TRUE;
        },
        reinterpret_cast<LPARAM>(&context));
    return context.found;
}

static std::vector<HWND> FindSecondaryTaskbars() {
    std::vector<HWND> taskbars;
    EnumWindows(
        [](HWND window, LPARAM param) CALLBACK -> BOOL {
            DWORD pid = 0;
            wchar_t name[48] = {};
            if (GetWindowThreadProcessId(window, &pid) &&
                pid == GetCurrentProcessId() &&
                GetClassNameW(window, name, ARRAYSIZE(name)) &&
                wcscmp(name, L"Shell_SecondaryTrayWnd") == 0) {
                reinterpret_cast<std::vector<HWND>*>(param)->push_back(window);
            }
            return TRUE;
        },
        reinterpret_cast<LPARAM>(&taskbars));
    return taskbars;
}

static void CreateTaskbarButtons() {
    bool enabled = false;
    bool secondary = false;
    {
        std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
        enabled = g_settings.showTaskbarButton;
        secondary = g_settings.showOnSecondaryTaskbars;
    }
    if (!enabled) {
        return;
    }

    std::vector<HWND> taskbars;
    if (HWND primary = FindTaskbarOfClass(L"Shell_TrayWnd")) {
        taskbars.push_back(primary);
    }
    if (secondary) {
        for (HWND window : FindSecondaryTaskbars()) {
            taskbars.push_back(window);
        }
    }

    for (HWND taskbar : taskbars) {
        CreateButtonContext context{taskbar, nullptr};
        RunFromWindowThread(taskbar, CreateButtonOnTaskbarThread, &context);
        if (context.created) {
            std::lock_guard<std::mutex> lock(g_buttonMutex);
            g_buttonWnds.push_back(context.created);
        }
    }
}

static void DestroyTaskbarButtons() {
    std::vector<HWND> buttons;
    {
        std::lock_guard<std::mutex> lock(g_buttonMutex);
        buttons.swap(g_buttonWnds);
    }
    for (HWND button : buttons) {
        if (IsWindow(button)) {
            DWORD_PTR result = 0;
            SendMessageTimeoutW(button, kMsgButtonClose, 0, 0,
                                SMTO_ABORTIFHUNG | SMTO_NORMAL, 5000, &result);
        }
    }
}

static bool ParseHotkey(const std::wstring& text, UINT& modifiers, UINT& key) {
    modifiers = 0;
    key = 0;
    for (const auto& part : SplitList(text, L'+')) {
        std::wstring lower = ToLower(part);
        if (lower == L"ctrl" || lower == L"control") {
            modifiers |= MOD_CONTROL;
        } else if (lower == L"alt") {
            modifiers |= MOD_ALT;
        } else if (lower == L"shift") {
            modifiers |= MOD_SHIFT;
        } else if (lower == L"win") {
            modifiers |= MOD_WIN;
        } else if (part.size() == 1) {
            key = (UINT)towupper(part[0]);
        } else if (lower.size() >= 2 && lower[0] == L'f' && iswdigit(lower[1])) {
            int number = _wtoi(lower.c_str() + 1);
            if (number >= 1 && number <= 24) {
                key = VK_F1 + number - 1;
            }
        }
    }
    return modifiers != 0 && key != 0;
}

static HICON CreateTrayIcon() {
    int size = GetSystemMetrics(SM_CXSMICON);
    Surface surface;
    if (!surface.Resize(size, size)) {
        return nullptr;
    }
    std::wstring glyphSource;
    std::wstring family;
    {
        std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
        glyphSource = g_settings.buttonGlyph;
        family = g_settings.fontFamily;
    }
    std::wstring glyph;
    bool isGlyph = ParseGlyph(glyphSource, glyph);
    if (!isGlyph) {
        glyph = glyphSource.empty() ? std::wstring(L"\uE768") : glyphSource;
        isGlyph = glyphSource.empty();
    }
    surface.RenderText(glyph,
                       GetFont(isGlyph ? IconFontFamily() : family,
                               (int)(size * 0.72), false),
                       gp::Color(255, 255, 255, 255), gp::Rect(0, 0, size, size),
                       kTextCenter);

    std::vector<BYTE> maskBits((size_t)((size + 15) / 16) * 2 * size, 0);
    HBITMAP mask = CreateBitmap(size, size, 1, 1, maskBits.data());
    if (!mask) {
        return nullptr;
    }
    BITMAPINFO info{};
    info.bmiHeader.biSize = sizeof(info.bmiHeader);
    info.bmiHeader.biWidth = size;
    info.bmiHeader.biHeight = -size;
    info.bmiHeader.biPlanes = 1;
    info.bmiHeader.biBitCount = 32;
    info.bmiHeader.biCompression = BI_RGB;
    void* bits = nullptr;
    HDC screen = GetDC(nullptr);
    HBITMAP color = CreateDIBSection(screen, &info, DIB_RGB_COLORS, &bits, nullptr, 0);
    ReleaseDC(nullptr, screen);
    if (!color) {
        DeleteObject(mask);
        return nullptr;
    }
    HDC target = CreateCompatibleDC(nullptr);
    HBITMAP previous = (HBITMAP)SelectObject(target, color);
    BitBlt(target, 0, 0, size, size, surface.Dc(), 0, 0, SRCCOPY);
    SelectObject(target, previous);
    DeleteDC(target);

    ICONINFO iconInfo{};
    iconInfo.fIcon = TRUE;
    iconInfo.hbmMask = mask;
    iconInfo.hbmColor = color;
    HICON icon = CreateIconIndirect(&iconInfo);
    DeleteObject(mask);
    DeleteObject(color);
    return icon;
}

static void UpdateTrayIcon() {
    bool wanted = false;
    {
        std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
        wanted = g_settings.showTrayIcon;
    }
    NOTIFYICONDATAW data{};
    data.cbSize = sizeof(data);
    data.hWnd = g_messageWnd;
    data.uID = kTrayIconId;

    if (!wanted) {
        if (g_trayIconAdded) {
            Shell_NotifyIconW(NIM_DELETE, &data);
            g_trayIconAdded = false;
        }
        if (g_trayIcon) {
            DestroyIcon(g_trayIcon);
            g_trayIcon = nullptr;
        }
        return;
    }

    if (!g_trayIcon) {
        g_trayIcon = CreateTrayIcon();
    }
    data.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
    data.uCallbackMessage = kMsgTrayCallback;
    data.hIcon = g_trayIcon;
    wcscpy_s(data.szTip, L"Tech Stack Launcher");
    Shell_NotifyIconW(g_trayIconAdded ? NIM_MODIFY : NIM_ADD, &data);
    g_trayIconAdded = true;
}

static void ShowTrayMenu() {
    HMENU menu = CreatePopupMenu();
    if (!menu) {
        return;
    }
    AppendMenuW(menu, MF_STRING, 1, L"Open launcher");
    std::vector<std::wstring> profiles;
    {
        std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
        profiles = g_settings.profiles;
    }
    if (!profiles.empty()) {
        HMENU submenu = CreatePopupMenu();
        for (size_t i = 0; i < profiles.size(); i++) {
            AppendMenuW(submenu, MF_STRING, (UINT_PTR)(100 + i), profiles[i].c_str());
        }
        AppendMenuW(menu, MF_POPUP, (UINT_PTR)submenu, L"Launch profile");
    }
    AppendMenuW(menu, MF_SEPARATOR, 0, nullptr);
    AppendMenuW(menu, MF_STRING, 2, L"Settings");

    POINT cursor{};
    GetCursorPos(&cursor);
    SetForegroundWindow(g_messageWnd);
    int command = TrackPopupMenu(menu, TPM_RETURNCMD | TPM_RIGHTBUTTON, cursor.x,
                                 cursor.y, 0, g_messageWnd, nullptr);
    DestroyMenu(menu);

    if (command == 1) {
        TogglePanel();
    } else if (command == 2) {
        OpenWindhawk();
    } else if (command >= 100 && command - 100 < (int)profiles.size()) {
        StartLaunch(ProfileIndices(profiles[command - 100]));
    }
}

static bool ExplorerJustStarted() {
    FILETIME creation{};
    FILETIME exit{};
    FILETIME kernel{};
    FILETIME user{};
    if (!GetProcessTimes(GetCurrentProcess(), &creation, &exit, &kernel, &user)) {
        return false;
    }
    FILETIME now{};
    GetSystemTimeAsFileTime(&now);
    ULARGE_INTEGER started{creation.dwLowDateTime, creation.dwHighDateTime};
    ULARGE_INTEGER current{now.dwLowDateTime, now.dwHighDateTime};
    return (current.QuadPart - started.QuadPart) < 180ULL * 10000000ULL;
}

static bool ShouldAutoRunToday() {
    bool oncePerDay = true;
    {
        std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
        oncePerDay = g_settings.autoRunOncePerDay;
    }
    if (!oncePerDay) {
        return true;
    }
    SYSTEMTIME time{};
    GetLocalTime(&time);
    wchar_t today[16];
    swprintf_s(today, L"%04d-%02d-%02d", time.wYear, time.wMonth, time.wDay);
    wchar_t stored[16] = {};
    Wh_GetStringValue(L"lastAutoRun", stored, ARRAYSIZE(stored));
    if (wcscmp(stored, today) == 0) {
        return false;
    }
    Wh_SetStringValue(L"lastAutoRun", today);
    return true;
}

static void ScheduleAutoRun() {
    std::wstring profile;
    int delaySeconds = 0;
    {
        std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
        profile = g_settings.autoRunProfile;
        delaySeconds = g_settings.autoRunDelaySeconds;
    }
    if (profile.empty() || !ExplorerJustStarted() || !ShouldAutoRunToday()) {
        return;
    }
    SetTimer(g_messageWnd, kTimerAutoRun, max(1, delaySeconds) * 1000, nullptr);
}

static LRESULT CALLBACK MessageWndProc(HWND window,
                                       UINT message,
                                       WPARAM wParam,
                                       LPARAM lParam) {
    if (message == g_taskbarCreatedMessage && g_taskbarCreatedMessage != 0) {
        g_trayIconAdded = false;
        DestroyTaskbarButtons();
        CreateTaskbarButtons();
        UpdateTrayIcon();
        return 0;
    }

    switch (message) {
        case kMsgTogglePanel:
            TogglePanel();
            return 0;

        case WM_HOTKEY:
            if (wParam == kHotkeyId) {
                TogglePanel();
            }
            return 0;

        case kMsgTrayCallback:
            if (LOWORD(lParam) == WM_LBUTTONUP) {
                TogglePanel();
            } else if (LOWORD(lParam) == WM_RBUTTONUP) {
                ShowTrayMenu();
            }
            return 0;

        case WM_SETTINGCHANGE:
        case WM_THEMECHANGED:
            RefreshPalette();
            RefreshTaskbarButtons();
            RefreshPanel();
            return 0;

        case kMsgReloadSettings:
            DestroyTaskbarButtons();
            RefreshPalette();
            ClearFontCache();
            ClearIconCache();
            LoadCollapsedGroups();
            NormalizeItemOrder();
            g_toggleAmount.clear();
            CreateTaskbarButtons();
            UpdateTrayIcon();
            RefreshPanel();
            return 0;

        case WM_TIMER:
            if (wParam == kTimerAutoRun) {
                KillTimer(window, kTimerAutoRun);
                std::wstring profile;
                {
                    std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
                    profile = g_settings.autoRunProfile;
                }
                if (!profile.empty()) {
                    StartLaunch(ProfileIndices(profile));
                }
                return 0;
            }
            break;
    }
    return DefWindowProcW(window, message, wParam, lParam);
}

static void RegisterWindowClasses() {
    WNDCLASSEXW buttonClass{};
    buttonClass.cbSize = sizeof(buttonClass);
    buttonClass.lpfnWndProc = ButtonWndProc;
    buttonClass.hInstance = GetModuleHandleW(nullptr);
    buttonClass.hCursor = LoadCursorW(nullptr, IDC_ARROW);
    buttonClass.lpszClassName = kButtonClass;
    RegisterClassExW(&buttonClass);

    WNDCLASSEXW panelClass{};
    panelClass.cbSize = sizeof(panelClass);
    panelClass.lpfnWndProc = PanelWndProc;
    panelClass.hInstance = GetModuleHandleW(nullptr);
    panelClass.hCursor = LoadCursorW(nullptr, IDC_ARROW);
    panelClass.lpszClassName = kPanelClass;
    RegisterClassExW(&panelClass);

    WNDCLASSEXW messageClass{};
    messageClass.cbSize = sizeof(messageClass);
    messageClass.lpfnWndProc = MessageWndProc;
    messageClass.hInstance = GetModuleHandleW(nullptr);
    messageClass.lpszClassName = kMessageClass;
    RegisterClassExW(&messageClass);
}

static void UnregisterWindowClasses() {
    HINSTANCE instance = GetModuleHandleW(nullptr);
    UnregisterClassW(kButtonClass, instance);
    UnregisterClassW(kPanelClass, instance);
    UnregisterClassW(kMessageClass, instance);
}

static HWND WaitForTaskbar() {
    for (int attempt = 0; attempt < 200 && !g_unloading; attempt++) {
        if (HWND taskbar = FindTaskbarOfClass(L"Shell_TrayWnd")) {
            return taskbar;
        }
        Sleep(200);
    }
    return nullptr;
}

static void UiThreadMain() {
    g_taskbarCreatedMessage = RegisterWindowMessageW(L"TaskbarCreated");

    g_messageWnd =
        CreateWindowExW(WS_EX_TOOLWINDOW, kMessageClass, L"Tech Stack Launcher",
                        WS_POPUP, 0, 0, 0, 0, nullptr, nullptr,
                        GetModuleHandleW(nullptr), nullptr);
    if (!g_messageWnd) {
        return;
    }

    g_panelWnd = CreateWindowExW(WS_EX_LAYERED | WS_EX_TOOLWINDOW | WS_EX_TOPMOST,
                                 kPanelClass, L"Tech Stack Launcher", WS_POPUP, 0, 0,
                                 Scale(440), Scale(600), nullptr, nullptr,
                                 GetModuleHandleW(nullptr), nullptr);
    if (!g_panelWnd) {
        DestroyWindow(g_messageWnd);
        g_messageWnd = nullptr;
        return;
    }

    RefreshPalette();
    LoadCollapsedGroups();
    LoadItemOrder();
    NormalizeItemOrder();

    wchar_t storedProfile[64] = {};
    Wh_GetStringValue(L"activeProfile", storedProfile, ARRAYSIZE(storedProfile));
    g_activeProfile = storedProfile;

    if (HWND taskbar = WaitForTaskbar()) {
        UINT dpi = GetDpiForWindow(taskbar);
        if (dpi >= 72) {
            g_dpi = dpi;
        }
        CreateTaskbarButtons();
    }

    std::wstring hotkey;
    {
        std::lock_guard<std::recursive_mutex> lock(g_settingsMutex);
        hotkey = g_settings.hotkey;
    }
    UINT modifiers = 0;
    UINT key = 0;
    if (!hotkey.empty() && ParseHotkey(hotkey, modifiers, key)) {
        RegisterHotKey(g_messageWnd, kHotkeyId, modifiers | MOD_NOREPEAT, key);
    }

    UpdateTrayIcon();
    ScheduleAutoRun();
    RefreshRunningStatus();

    MSG message;
    while (GetMessageW(&message, nullptr, 0, 0) > 0) {
        TranslateMessage(&message);
        DispatchMessageW(&message);
    }

    UnregisterHotKey(g_messageWnd, kHotkeyId);
    DestroyTaskbarButtons();

    NOTIFYICONDATAW trayData{};
    trayData.cbSize = sizeof(trayData);
    trayData.hWnd = g_messageWnd;
    trayData.uID = kTrayIconId;
    if (g_trayIconAdded) {
        Shell_NotifyIconW(NIM_DELETE, &trayData);
        g_trayIconAdded = false;
    }
    if (g_trayIcon) {
        DestroyIcon(g_trayIcon);
        g_trayIcon = nullptr;
    }

    g_panelSurface.Release();
    DestroyWindow(g_panelWnd);
    g_panelWnd = nullptr;
    DestroyWindow(g_messageWnd);
    g_messageWnd = nullptr;
}

BOOL Wh_ModInit() {
    Wh_Log(L"Init");

    gp::GdiplusStartupInput startupInput;
    if (gp::GdiplusStartup(&g_gdiplusToken, &startupInput, nullptr) != gp::Ok) {
        Wh_Log(L"GDI+ startup failed");
        return FALSE;
    }

    LoadSettings();
    RegisterWindowClasses();

    g_backgroundQueue.Start();
    g_launchQueue.Start();
    g_uiThread = std::thread(UiThreadMain);
    return TRUE;
}

void Wh_ModSettingsChanged() {
    Wh_Log(L"Settings changed");
    LoadSettings();
    if (g_messageWnd) {
        PostMessageW(g_messageWnd, kMsgReloadSettings, 0, 0);
    }
}

void Wh_ModBeforeUninit() {
    g_unloading = true;
    g_cancelLaunch = true;
    if (g_messageWnd) {
        PostMessageW(g_messageWnd, WM_QUIT, 0, 0);
    }
}

void Wh_ModUninit() {
    Wh_Log(L"Uninit");

    g_launchQueue.Stop();
    g_backgroundQueue.Stop();

    if (g_uiThread.joinable()) {
        g_uiThread.join();
    }

    ClearIconCache();
    ClearFontCache();
    UnregisterWindowClasses();

    if (g_gdiplusToken) {
        gp::GdiplusShutdown(g_gdiplusToken);
        g_gdiplusToken = 0;
    }
}

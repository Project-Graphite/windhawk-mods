// ==WindhawkMod==
// @id              tasktune
// @name            TaskTune
// @description     Customizable media controls, per-app volume, audio-only app support, and a spectrum visualizer for the Windows 11 taskbar.
// @version         2.2.3
// @author          AmrMsCLL
// @github          https://github.com/AmrMsCLL
// @license         MIT
// @architecture    x86-64
// @include         explorer.exe
// @compilerOptions -lole32 -loleaut32 -lruntimeobject -luuid -luser32 -lwindowsapp -lshell32 -lgdi32 -lshlwapi -lwindowscodecs -ldwmapi -lshcore -lksuser -lversion
// ==/WindhawkMod==

// ==WindhawkModReadme==
/*
# TaskTune

TaskTune puts media information and controls directly in the Windows 11 taskbar. It uses Windows media sessions for track details and playback, then falls back to active audio sessions for apps such as calls, games, and browser tabs that play sound without publishing media metadata.

## Features

- More than 20 taskbar and system-tray placements
- Independent players on multiple monitors
- Album art, track title, artist, and configurable scrolling text
- Play, pause, stop, previous, next, shuffle, repeat, and session switching
- Configurable 1-60 second rewind and forward controls
- Per-application volume and mute controls
- Compact mini-player with media-session selection
- Solid, gradient, Acrylic, Mica, Mica Alt, and blurred-album-art backgrounds
- WASAPI spectrum visualizer with multiple shapes, color modes, and EQ presets
- Automatic hiding when no media exists, the taskbar is idle, or an app is full-screen
- Configurable mouse clicks, double-clicks, middle clicks, and wheel actions
- Accessible control names and tooltips

## Requirements

- Windows 11 on x86-64
- A media app that exposes Windows System Media Transport Controls, or an app with an active Windows audio session

## Getting started

After installing the mod, open **Settings** and choose the player position. The default layout shows album art, title, artist, and Previous/Play/Next controls in the system tray area.

Double-click anywhere on the player to open Spotify. Change **App opened by double-click** to launch another app. Main settings control layout and playback, Appearance controls styling, Behavior controls input and hiding, and Audio Apps controls audio-only detection and volume.

Some media applications expose only part of the Windows media-control API. TaskTune disables or hides unsupported actions according to the **Hide unsupported buttons** setting.

## Notes

TaskTune runs inside `explorer.exe`. If an experimental layout or another taskbar customization causes a conflict, disable TaskTune from Windhawk and restart Explorer before changing settings.

Created and maintained by [AmrMsCLL](https://github.com/AmrMsCLL) as part of Project Graphite.
Licensed under the MIT License.
*/
// ==/WindhawkModReadme==

// ==WindhawkModSettings==
/*
- MainSettings:
  - PlayerSetting:
    - position: "tray_left"
      $name: Media player position
      $options:
      - "taskbar_left_edge": "Taskbar - Left edge (Overlay)"
      - "taskbar_center_edge": "Taskbar - Center (Overlay)"
      - "taskbar_right_edge": "Taskbar - Right edge (Overlay)"
      - "taskbar_left_start": "Taskbar - Left of Start button"
      - "taskbar_right_start": "Taskbar - Right of Start button"
      - "taskbar_after_search_left": "Taskbar - Left of Search button"
      - "taskbar_after_search_right": "Taskbar - Right of Search button"
      - "taskbar_after_taskview_left": "Taskbar - Left of Task View button"
      - "taskbar_after_taskview_right": "Taskbar - Right of Task View button"
      - "taskbar_after_widgets_left": "Taskbar - Left of Widgets button"
      - "taskbar_after_widgets_right": "Taskbar - Right of Widgets button"
      - "tray_left": "Tray - Far left"
      - "tray_right": "Tray - Far right"
      - "tray_before_clock": "Tray - Left of Clock"
      - "tray_after_clock": "Tray - Right of Clock"
      - "tray_before_omni_left": "Tray - Left of Network/Volume button"
      - "tray_before_omni_right": "Tray - Right of Network/Volume button"
      - "tray_language_left": "Tray - Left of Language button"
      - "tray_language_right": "Tray - Right of Language button"
      - "tray_icons_left": "Tray - Left of Tray Icons"
      - "tray_icons_right": "Tray - Right of Tray Icons"
      - "tray_hidden_icons_left": "Tray - Left of Hidden icons button"
      - "tray_hidden_icons_right": "Tray - Right of Hidden icons button"
      - "tray_after_showdesktop_left": "Tray - Left of Show Desktop"
      - "tray_after_showdesktop_right": "Tray - Right of Show Desktop"
    - showOnAllMonitors: false
      $name: Show on all monitors
      $description: Shows one player per taskbar and ignores Monitor.
    - monitor: 1
      $name: Monitor
      $description: Selects one taskbar by monitor number.
    - playerWidth: "0 0"
      $name: Media player width (min max)
      $description: "Two values: minimum and maximum. Use 0 for no limit."
    - playerHeight: "40 40"
      $name: Media player height (min max)
    - playerMargin: "4 4"
      $name: Media player margin (left right)
      $description: "Two values: left and right."
    - autoSwitchSession: true
      $name: Auto-switch to active media session
      $description: Follows whichever media session is playing.
    - mirrorLayout: false
      $name: Mirror layout
      $description: Reverses the album art, text, and buttons.
    - fullHeightHitArea: true
      $name: Full-height invisible hit area
      $description: Extends clicks and hover to the full taskbar height.
    $name: Media player

  - AlbumArtSetting:
    - showAlbumArt: true
      $name: Show album art
    - albumArtWidth: "32 64"
      $name: Album art width (min max)
    - albumArtHeight: "32 32"
      $name: Album art height (min max)
    - albumArtMargin: "0 0"
      $name: Album art margin (left right)
    $name: Album Art

  - TextAreaSetting:
    - showTrackTitle: true
      $name: Show track title
    - showTrackArtist: true
      $name: Show artist name
    - textAreaWidth: "0 120"
      $name: Text area width (min max)
    - textAreaHeight: "0 0"
      $name: Text area height (min max)
    - textAreaMargin: "5 5"
      $name: Text area margin (left right)
    - textSpacing: -1
      $name: Spacing between title and artist
    - enableTitleScrolling: true
      $name: Enable track title scrolling
      $description: Scrolls titles that exceed the text area.
    - enableArtistScrolling: false
      $name: Enable artist name scrolling
      $description: Scrolls artist names that exceed the text area.
    - scrollSpeed: 1
      $name: Scroll speed (1-10)
      $description: 1 is slowest; 10 is fastest.
    - scrollPauseDuration: 1000
      $name: Pause duration at edges (ms)
      $description: Delay before scrolling reverses.
    - scrollMode: "bounce"
      $name: Scroll mode
      $options:
      - "bounce": "Bounce (back and forth)"
      - "loop":   "Loop (continuous)"
    - loopGap: 40
      $name: Loop gap (px)
      $description: Space between repeated text in Loop mode.
    - swapTitleArtist: false
      $name: Swap artist name and track title
    - emptyTitleText: "Untitled"
      $name: Title text when track has no name
      $description: Leave blank to hide missing titles.
    - noMediaTitleText: ""
      $name: Title text when nothing is playing
      $description: Leave blank to hide the idle title.
    - emptyArtistText: ""
      $name: Artist text when track has no artist
      $description: Leave blank to hide missing artists.
    - noMediaArtistText: ""
      $name: Artist text when nothing is playing
      $description: Leave blank to hide the idle artist.
    $name: Text area

  - MediaButtonsSettings:
    - showMediaButtons: true
      $name: Show media buttons
    - mediaButtons: [prev, play, next]
      $name: Media buttons order
      $description: Sets visible controls and order. Duplicates are ignored.
      $options:
      - none: Nothing
      - prev: Previous Track
      - play: Play/Pause
      - next: Next Track
      - rewind: Rewind
      - forward: Forward
      - shuffle: Toggle Shuffle
      - repeat: Toggle Repeat
      - switch_sessions: Switch Sessions
    - mediaButtonsMargin: "2 2"
      $name: Media buttons margin (left right)
    - buttonSize: 28
      $name: Button size
    - seekStepSeconds: 5
      $name: Rewind and forward interval (seconds)
      $description: Applies to buttons, clicks, and menu commands.
    - hideUnsupportedButtons: false
      $name: Hide unsupported buttons
      $description: Hides unavailable controls instead of disabling them.
    $name: Media Buttons

  - VisualizerFunctionsSettings:
    - vizEnabled: false
      $name: Enable audio visualizer
      $description: Shows spectrum bars from system audio output.
    - vizPosition: "right"
      $name: Position
      $description: Selects the visualizer side.
      $options:
      - "left": Left
      - "right": Right
    - vizShape: "stereo"
      $name: Bar shape
      $options:
      - "stereo": Stereo
      - "mountain": Mountain
      - "mirror": Mirror
      - "wave": Wave
      - "breathe": Breathe
    - vizEQ: "default"
      $name: EQ preset
      $options:
      - "default": Balanced
      - "bass": Bass
      - "rock": Rock
      - "pop": Pop
      - "jazz": Jazz
      - "electronic": Electronic
    - vizAnchor: "middle"
      $name: Vertical anchor
      $options:
      - "top": Top
      - "middle": Middle
      - "bottom": Bottom
    - vizBarCountGap: "7 5"
      $name: Bars (count gap)
      $description: "Two values: bar count and gap in pixels."
    - vizBarSize: "5 3"
      $name: Bar size (width height)
      $description: "Two values: bar width and idle height. Width 0 hides bars."
    - vizPadding: "0 0"
      $name: Padding (left right)
      $description: "Two values: left and right pixels."
    - vizSensitivity: 150
      $name: Sensitivity (0-300)
    $name: Visualizer
  $name: Main Settings

- AppearanceSettings:
  - BackgroundStyleSettings:
    - backgroundType: "none"
      $name: Background type
      $options:
      - "none":           "None (transparent)"
      - "solid":          "Solid color"
      - "gradient":       "Gradient"
      - "acrylic":        "Acrylic"
      - "mica":           "Mica"
      - "mica_alt":       "Mica Alt"
      - "album_art_blur": "Blurred album cover"
    - solidColor: "35 35 35"
      $name: Background color (RGB)
      $description: "Use -1 for system contrast, -2 for album art, or light$dark for themes."
    - solidColor2: "35 35 35"
      $name: Gradient color 1 (RGB)
    - gradientColor2: "128 128 128"
      $name: Gradient color 2 (RGB)
    - solidOpacity: 100
      $name: Solid color opacity (0-100)
    - gradientAngle: 50
      $name: Gradient rotation angle (0-360)
    - gradientBalance: 50
      $name: Gradient color balance (0-100)
    - acrylicTintOpacity: 50
      $name: Acrylic tint opacity (0-100)
    - micaOpacity: 50
      $name: Mica/Mica Alt opacity (0-100)
    - blurOpacity: 65
      $name: Album art blur opacity (0-100)
    - blurRadius: 11
      $name: Album art blur strength (1-50)
    - cornerRadius: "4"
      $name: Media player corner radius
      $description: Use one value for all corners or four values for each corner.
    - enablePlayerHoverEffect: "auto"
      $name: Player hover effect
      $options:
      - "auto":  "Auto (theme changes automatically)"
      - "black": "Black"
      - "white": "White"
      - "off":   "Disable hover effect"
    - enableMediaButtonsHoverEffect: "auto"
      $name: Media buttons hover effect
      $options:
      - "auto":  "Auto (theme changes automatically)"
      - "black": "Black"
      - "white": "White"
      - "off":   "Disable hover effect"
    - enableHoverAnimation: true
      $name: Smooth hover animation
      $description: Animates hover and pressed backgrounds and borders.
    $name: Background Style

  - MediaButtonsStyleSettings:
    - iconStyle: "fluent_outline"
      $name: Icon style
      $options:
      - "fluent_outline": "Segoe Fluent Icons (Outline)"
      - "fluent_filled":  "Segoe Fluent Icons (Filled)"
      - "mdl2_outline":   "Segoe MDL2 Assets (Outline)"
      - "mdl2_filled":    "Segoe MDL2 Assets (Filled)"
    - buttonSpacing: 0
      $name: Spacing between media buttons
    - buttonIconSize: 12
      $name: Button icon size
    - buttonCornerRadius: "4"
      $name: Media buttons corner radius
      $description: Use one value for all corners or four values for each corner.
    - buttonColor: "0 0 0$255 255 255"
      $name: Media buttons icons color (RGB)
      $description: "Use -1 for system contrast, -2 for album art, or light$dark for themes."
    - buttonColorOpacity: 100
      $name: Media buttons icons opacity (0-100)
    $name: Media Buttons Style

  - TitleTextStyleSettings:
    - titleColor: "0 0 0$255 255 255"
      $name: Title color (RGB)
      $description: "Use -1 for system contrast, -2 for album art, or light$dark for themes."
    - titleColorOpacity: 100
      $name: Title opacity (0-100)
    - titleFont: segoe_ui_variable
      $name: Title font
      $options:
      - segoe_ui_variable: Segoe UI Variable Display
      - segoe_ui:          Segoe UI
      - aptos:             Aptos
      - calibri:           Calibri
      - cambria:           Cambria
      - candara:           Candara
      - consolas:          Consolas
      - corbel:            Corbel
      - arial:             Arial
      - trebuchet:         Trebuchet MS
      - verdana:           Verdana
      - tahoma:            Tahoma
      - georgia:           Georgia
      - times_new_roman:   Times New Roman
      - custom:            Custom...
    - titleFontSize: 12
      $name: Title font size
    - titleFontFamily: ""
      $name: Title font family (for Custom option)
      $description: Enter an installed Windows font family name.
    - titleFontWeight: ""
      $name: Title font weight
      $options:
      - "":          Default
      - Thin:        Thin
      - ExtraLight:  Extra light
      - Light:       Light
      - SemiLight:   Semi light
      - Normal:      Normal
      - Medium:      Medium
      - SemiBold:    Semi bold
      - Bold:        Bold
      - ExtraBold:   Extra bold
      - Black:       Black
      - ExtraBlack:  Extra black
    - titleFontStyle: ""
      $name: Title font style
      $options:
      - "":       Default
      - Normal:   Normal
      - Oblique:  Oblique
      - Italic:   Italic
    - titleCharacterSpacing: 0
      $name: Title character spacing
      $description: Can be a positive or a negative number.
    $name: Title Text Style

  - ArtistTextStyleSettings:
    - artistColor: "0 0 0$255 255 255"
      $name: Artist color (RGB)
      $description: "Use -1 for system contrast, -2 for album art, or light$dark for themes."
    - artistColorOpacity: 80
      $name: Artist opacity (0-100)
    - artistFont: segoe_ui_variable
      $name: Artist font
      $options:
      - segoe_ui_variable: Segoe UI Variable Display
      - segoe_ui:          Segoe UI
      - aptos:             Aptos
      - calibri:           Calibri
      - cambria:           Cambria
      - candara:           Candara
      - consolas:          Consolas
      - corbel:            Corbel
      - arial:             Arial
      - trebuchet:         Trebuchet MS
      - verdana:           Verdana
      - tahoma:            Tahoma
      - georgia:           Georgia
      - times_new_roman:   Times New Roman
      - custom:            Custom...
    - artistFontSize: 11
      $name: Artist font size
    - artistFontFamily: ""
      $name: Artist font family (for Custom option)
      $description: Enter an installed Windows font family name.
    - artistFontWeight: ""
      $name: Artist font weight
      $options:
      - "":          Default
      - Thin:        Thin
      - ExtraLight:  Extra light
      - Light:       Light
      - SemiLight:   Semi light
      - Normal:      Normal
      - Medium:      Medium
      - SemiBold:    Semi bold
      - Bold:        Bold
      - ExtraBold:   Extra bold
      - Black:       Black
      - ExtraBlack:  Extra black
    - artistFontStyle: ""
      $name: Artist font style
      $options:
      - "":       Default
      - Normal:   Normal
      - Oblique:  Oblique
      - Italic:   Italic
    - artistCharacterSpacing: 0
      $name: Artist character spacing
      $description: Can be a positive or a negative number.
    $name: Artist Text Style

  - AlbumArtDisplaySettings:
    - albumArtEmptyBehavior: "show"
      $name: Album art behavior when no cover available
      $options:
      - "show":          "Show area"
      - "hide":          "Hide area"
      - "show_icon":     "Show area with icon"
    - emptyIconGlyph: "E189"
      $name: Icon glyph code (hex)
      $description: Hex glyph code from the selected icon font.
    - emptyIconSize: 16
      $name: Icon size
    - emptyIconFont: "segoe_fluent"
      $name: Icon font style
      $options:
      - "segoe_fluent": "Segoe Fluent Icons"
      - "segoe_mdl2":   "Segoe MDL2 Assets"
    - emptyIconColor: "140 140 140"
      $name: Icon color (RGB)
      $description: "Use -1 for system accent, -2 for album art, or light$dark for themes."
    - emptyIconOpacity: 100
      $name: Icon opacity (0-100)
    - albumArtQuality: "medium"
      $name: Album art quality
      $options:
      - "low":    "Low (faster, less memory)"
      - "medium": "Medium (default)"
      - "high":   "High (best quality)"
    - showPauseOverlay: true
      $name: Show pause icon overlay on album art when paused
    - pauseOverlayIconSize: 16
      $name: Pause icon size
    - pauseOverlayOpacity: 60
      $name: Pause overlay background opacity (0-100)
    - albumArtOpacity: 100
      $name: Album art opacity (0-100)
    - albumArtCornerRadius: "4"
      $name: Album art corner radius
      $description: Use one value for all corners or four values for each corner.
    - showAppIcon: false
      $name: Show media app icon overlay
    - appIconCorner: "bottom_right"
      $name: App icon corner
      $options:
      - "top_left":     "Top left"
      - "top_right":    "Top right"
      - "bottom_left":  "Bottom left"
      - "bottom_right": "Bottom right"
    - appIconSize: 12
      $name: App icon size
    $name: Album Art Display

  - VisualizerStyleSettings:
    - vizColorMode: "solid"
      $name: Color mode
      $options:
      - "solid": Solid
      - "dynamic_album": Dynamic album color
      - "dynamic_gradient": Dynamic gradient
      - "custom_gradient": Custom gradient
      - "acrylic": Acrylic
    - vizColor: "0 0 0$255 255 255"
      $name: Bar color (RGB)
      $description: "For Solid/Acrylic. Use -1 for accent, -2 for album art, or light$dark."
    - vizColor1: "30 215 96"
      $name: Gradient color 1 (RGB)
    - vizColor2: "0 180 255"
      $name: Gradient color 2 (RGB)
    $name: Visualizer Style
  $name: Appearance Settings

- PlayerMenuSettings:
  - placementMode: screen
    $name: Placement mode
    $description: Opens near the player or at a fixed screen position.
    $options:
    - near: Near the media player
    - screen: Placement on the screen

  - PlayerMenuSettingsNear:
    - miniPlayerHorizontalOffsetNear: 0
      $name: Menu horizontal offset (right/left)
    - miniPlayerVerticalPlacementNear: top
      $name: Vertical placement
      $description: Sets the menu side and animation direction.
      $options:
      - top: Top
      - bottom: Bottom 
    $name: Near the media player

  - PlayerMenuSettingsScreen:
    - miniPlayerHorizontalPlacement: right
      $name: Horizontal placement on the screen
      $options:
      - left: Left
      - center: Center
      - right: Right
    
    - horizontalDistanceFromScreenEdge: 0
      $name: Distance from the right/left side of the screen
    
    - miniPlayerVerticalPlacement: bottom
      $name: Vertical placement on the screen
      $options:
      - top: Top
      - center: Center
      - bottom: Bottom
    
    - verticalDistanceFromScreenEdge: 0
      $name: Distance from the bottom/top side of the screen
    
    - miniPlayerAnimation: auto
      $name: Appearance animation
      $options:
      - auto: Automatic
      - top: From top
      - bottom: From bottom 
      - left: From left
      - right: From right
    $name: Placement on the screen

  - keepMiniPlayerOpen: false
    $name: Keep mini player menu open
  - hideMediaSessionsList: false
    $name: Hide media sessions list
    $description: Hide the list of other media sessions/apps in the player menu
  - miniPlayerMatchPlayerBackground: true
    $name: Use the player's background in the menu
    $description: Uses the player's background instead of plain Acrylic.
  $name: Player Menu Settings

- BehaviorSettings:
  - disableAlbumArtClick: false
    $name: Disable album art click (click through to player)
    $description: Passes album-art clicks to the whole player.
  - emptyStateHideButtons: true
    $name: Hide the media buttons when nothing is playing
    $description: Hides playback controls while idle.
  - emptyStateHideVisualizer: true
    $name: Hide the visualizer when nothing is playing
    $description: Hides the visualizer and stops capture while idle.
  - emptyStateHideAlbumArt: true
    $name: Hide the album art area when nothing is playing
    $description: Removes the cover area while idle.
  - launchAppCommand: "spotify:"
    $name: App opened by double-click
    $description: "Use a URI, executable, full path, or shell:AppsFolder ID. The default opens Spotify."
  - ClickActionSettings:
      - - object: player
          $name: Object
          $options:
          - none:       Nothing
          - player:     Player area
          - album_art:  Album art area
        - click: left_click
          $name: Click type
          $options:
          - none:                Nothing
          - left_click:          Left click
          - left_double_click:   Left double click
          - right_click:         Right click
          - right_double_click:  Right double click
          - middle_click:        Middle click
          - middle_double_click: Middle double click
        - action: open_mini_player
          $name: Action
          $options:
          - none:            Nothing
          - switch_session:  Switch active media session
          - play_pause:      Play/Pause
          - next_track:      Next track
          - prev_track:      Previous track
          - stop:            Stop playback
          - rewind:          Rewind
          - forward:         Forward
          - toggle_shuffle:  Toggle Shuffle
          - toggle_repeat:   Toggle Repeat
          - open_app:        Open media app
          - open_configured_app: Open configured app
          - open_context_menu: Open context menu
          - open_mini_player: Open player menu
          - toggle_app_mute: Mute/unmute the app
          - app_volume_up:   App volume up
          - app_volume_down: App volume down
      - - object: player
        - click: right_click
        - action: open_context_menu
      - - object: player
        - click: left_double_click
        - action: open_configured_app
    $name: Click Actions
  - MouseWheelActionSettings:
      - - object: player
          $name: Object
          $options:
          - none:       Nothing
          - player:     Player area
          - album_art:  Album art area
        - click: mouse_wheel
          $name: Mouse type
          $options:
          - none:             Nothing
          - mouse_wheel:      Mouse wheel
        - action: switch_tracks
          $name: Action
          $options:
          - none:                      Nothing
          - "switch_tracks":           "Switch tracks"
          - "switch_tracks_inverted":  "Switch tracks (inverted)"
          - "switch_sessions":         "Switch sessions"
          - "system_sound":            "Change system sound volume"
          - "app_sound":               "Change app sound volume"
          - "app_sound_inverted":      "Change app sound volume (inverted)"
      - - object: album_art
        - click: mouse_wheel
        - action: switch_sessions
    $name: Mouse wheel Actions
  - hideWhenNoMedia: true
    $name: Hide when no media is playing
  - hideFullscreen: true
    $name: Hide when a fullscreen app is running
  - idleHideSeconds: 0
    $name: Idle auto-hide timeout (seconds, 0 = disabled)
  - showFullTitleOnHover: true
    $name: Show full track title on hover (tooltip)
  - ignoredProcesses: ""
    $name: Ignore media from processes (separate with ; )
  $name: Behavior Settings

- AudioAppSettings:
  - enableAudioApps: true
    $name: Show apps that play sound without media info
    $description: Shows the active audio app when no media session exists.
  - audioAppsRequireSound: true
    $name: Only while the app is actually making sound
    $description: Excludes silent apps with open audio streams.
  - audioAppSubtitle: "Playing audio"
    $name: Second line for these apps
    $description: Supports %app% and %volume%. Leave blank for automatic detection.
  - audioAppShowIcon: true
    $name: Use the app icon as the album art
  - audioAppIgnore: "explorer;SystemSettings;ShellExperienceHost;TextInputHost;ApplicationFrameHost"
    $name: Never show these processes (separate with ; )
  - volumeStep: 4
    $name: Volume step per scroll notch (%)
  - showVolumeInMenu: true
    $name: Show an app volume slider in the player menu
    $description: Controls the shown app, not system volume.
  $name: Audio App Settings

- AnimationSettings:
  - enableSmoothPositionAnimation: true
    $name: Enable smooth animations
    $description: Animates movement, visibility, album art, and text changes.
  $name: Animation Settings media player

- ContextMenuSettings:
  - contextMenuItems: [switch_sessions, open_app]
    $name: Context menu items
    $description: Sets visible items and order. Duplicates are ignored.
    $options:
    - none:             Nothing
    - repeat:           Repeat
    - shuffle:          Shuffle
    - forward:          Forward
    - rewind:           Rewind
    - next:             Next Track
    - prev:             Previous Track
    - switch_sessions:  Switch Sessions
    - open_app:         Open media app
    - app_volume:       App volume
    - mute_app:         Mute/unmute the app
  - repeatStyle: "submenu"
    $name: Repeat style
    $options:
    - "submenu": "Submenu (Repeat off / Repeat all / Repeat one)"
    - "toggle":  "Toggle (cycle through modes)"
  - shuffleStyle: "toggle"
    $name: Shuffle style
    $options:
    - "submenu": "Submenu (Shuffle off / Shuffle on)"
    - "toggle":  "Toggle (single button)"
  - contextMenuIconStyle: "as_media_buttons"
    $name: Context menu icon style
    $options:
    - "as_media_buttons": "Same as Media Buttons"
    - "fluent_outline":   "Segoe Fluent Icons (Outline)"
    - "fluent_filled":    "Segoe Fluent Icons (Filled)"
    - "mdl2_outline":     "Segoe MDL2 Assets (Outline)"
    - "mdl2_filled":      "Segoe MDL2 Assets (Filled)"
  - contextMenuIconColor: "0 0 0$255 255 255"
    $name: Context menu icons color (RGB)
    $description: "Use -1 for system contrast, -2 for album art, light$dark for themes, or blank to inherit."
  - contextMenuIconOpacity: 100
    $name: Context menu icons opacity (0-100)
  $name: Context Menu Settings

*/
// ==/WindhawkModSettings==

#undef GetCurrentTime
#include <winrt/base.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.UI.Core.h>
#include <winrt/Windows.UI.Text.h>
#include <winrt/Windows.UI.Input.h>
#include <winrt/Windows.UI.Xaml.h>
#include <winrt/Windows.UI.Xaml.Controls.Primitives.h>
#include <winrt/Windows.UI.Xaml.Controls.h>
#include <winrt/Windows.UI.Xaml.Media.h>
#include <winrt/Windows.UI.Xaml.Media.Imaging.h>
#include <winrt/Windows.UI.Xaml.Shapes.h>
#include <winrt/Windows.UI.Xaml.Media.Animation.h>
#include <winrt/Windows.UI.Xaml.Markup.h>
#include <winrt/Windows.UI.Xaml.Interop.h>
#include <winrt/Windows.UI.Xaml.Input.h>
#include <winrt/Windows.UI.Xaml.Automation.h>
#include <winrt/Windows.UI.Xaml.Hosting.h>
#include <winrt/Windows.UI.Composition.h>
#include <winrt/Windows.UI.ViewManagement.h>
#include <winrt/Windows.Media.Control.h>
#include <winrt/Windows.Storage.Streams.h>
#include <winrt/Windows.Graphics.Imaging.h>
#include <robuffer.h>
#include <shcore.h>
#include <windows.h>
#include <shellapi.h>
#include <shlobj.h>
#include <shlwapi.h>
#include <shobjidl.h>
#include <commoncontrols.h>
#include <wincodec.h>
#include <propsys.h>
#include <dwmapi.h>
#include <windhawk_utils.h>
#include <audiopolicy.h>
#include <mmdeviceapi.h>
#include <audioclient.h>
#include <propkey.h>
#include <atomic>
#include <functional>
#include <memory>
#include <utility>
#include <mutex>
#include <string>
#include <vector>
#include <optional>
#include <set>
#include <map>
#include <cwctype>
#include <algorithm>
#include <thread>
#include <cmath>
#include <chrono>
using namespace winrt::Windows::UI::Xaml;
using namespace winrt::Windows::UI::Xaml::Controls;
using namespace winrt::Windows::UI::Xaml::Media;
using namespace winrt::Windows::UI::Xaml::Media::Imaging;
using namespace winrt::Windows::UI::Xaml::Media::Animation;
using namespace winrt::Windows::UI::Xaml::Input;
using namespace winrt::Windows::Media::Control;
using namespace winrt::Windows::Storage::Streams;
enum class VizShape { Stereo, Mountain, Mirror, Wave, Breathe };
enum class VizColorMode { Solid, DynamicAlbum, DynamicGradient, CustomGradient, Acrylic };
enum class VizEQ { Default, Bass, Rock, Pop, Jazz, Electronic };
enum class VizAnchor { Top, Middle, Bottom };
struct ModSettings {
    int          monitor              = 1;
    bool         showOnAllMonitors    = false;
    std::wstring position             = L"tray_left";
    std::wstring albumArtLeftClick    = L"none";
    std::wstring albumArtRightClick   = L"none";
    std::wstring albumArtMiddleClick  = L"none";
    std::wstring albumArtLeftDoubleClick  = L"none";
    std::wstring albumArtRightDoubleClick = L"none";
    std::wstring albumArtMiddleDoubleClick = L"none";
    std::wstring albumArtWheelAction  = L"none";
    std::wstring playerLeftClick      = L"none";
    std::wstring playerRightClick     = L"none";
    std::wstring playerMiddleClick    = L"none";
    std::wstring playerLeftDoubleClick  = L"none";
    std::wstring playerRightDoubleClick = L"none";
    std::wstring playerMiddleDoubleClick = L"none";
    std::wstring playerWheelAction    = L"none";
    bool         mirrorLayout         = false;
    bool         fullHeightHitArea    = true;
    bool         autoSwitchSession    = true;
    bool         showMediaButtons     = true;
    int          playerMinWidth       = 0;
    int          playerMaxWidth       = 0;
    int          playerMinHeight      = 40;
    int          playerMaxHeight      = 40;
    bool         showAlbumArt         = true;
    std::wstring albumArtEmptyBehavior = L"show";
    std::wstring emptyIconGlyph       = L"E189";
    int          emptyIconSize        = 16;
    std::wstring emptyIconFont        = L"segoe_fluent";
    std::wstring emptyIconColor       = L"255 255 255";
    int          emptyIconOpacity     = 100;
    std::wstring albumArtQuality      = L"medium";
    bool         showPauseOverlay     = true;
    int          pauseOverlayIconSize = 16;
    int          pauseOverlayOpacity  = 60;
    int          albumArtMinWidth     = 32;
    int          albumArtMaxWidth     = 64;
    int          albumArtMinHeight    = 32;
    int          albumArtMaxHeight    = 32;
    int          albumArtOpacity      = 100;
    int          albumArtLeftMargin   = 0;
    int          albumArtRightMargin  = 0;
    bool         showTrackTitle       = true;
    bool         showFullTitleOnHover = true;
    bool         showTrackArtist      = true;
    bool         swapTitleArtist      = false;
    std::wstring emptyTitleText       = L"Untitled";
    std::wstring noMediaTitleText     = L"Not Playing";
    std::wstring emptyArtistText      = L"";
    std::wstring noMediaArtistText    = L"";
    std::wstring iconStyle            = L"fluent_outline";
    bool         showAppIcon          = false;
    std::wstring appIconCorner        = L"bottom_right";
    int          appIconSize          = 12;
    bool         hideWhenNoMedia      = true;
    std::wstring playerHoverEffectMode = L"auto";
    std::wstring mediaButtonsHoverEffectMode = L"auto";
    bool         enableHoverAnimation = true;
    bool         enableSmoothPositionAnimation = true;
    int          playerMarginLeft     = 4;
    int          playerMarginRight    = 4;
    int          mediaButtonsLeftMargin  = 2;
    int          mediaButtonsRightMargin = 2;
    int          textAreaMinWidth     = 0;
    int          textAreaMaxWidth     = 120;
    int          textAreaMinHeight    = 0;
    int          textAreaMaxHeight    = 0;
    int          textAreaLeftMargin   = 5;
    int          textAreaRightMargin  = 5;
    bool         hideFullscreen       = true;
    int          idleHideSeconds      = 0;
    std::wstring backgroundType       = L"none";
    int          blurOpacity          = 65;
    int          blurRadius           = 11;
    double       cornerRadiusTL       = 4;
    double       cornerRadiusTR       = 4;
    double       cornerRadiusBR       = 4;
    double       cornerRadiusBL       = 4;
    double       albumArtCornerRadiusTL = 4;
    double       albumArtCornerRadiusTR = 4;
    double       albumArtCornerRadiusBR = 4;
    double       albumArtCornerRadiusBL = 4;
    int          buttonSpacing        = 0;
    int          buttonSize           = 28;
    int          seekStepSeconds      = 5;
    int          buttonIconSize       = 12;
    double       buttonCornerRadiusTL = 4;
    double       buttonCornerRadiusTR = 4;
    double       buttonCornerRadiusBR = 4;
    double       buttonCornerRadiusBL = 4;
    int          titleFontSize        = 12;
    int          artistFontSize       = 11;
    std::wstring titleFont            = L"segoe_ui_variable";
    std::wstring artistFont           = L"segoe_ui_variable";
    std::wstring titleFontFamily      = L"";
    std::wstring artistFontFamily     = L"";
    std::wstring titleFontWeight      = L"";
    std::wstring artistFontWeight     = L"";
    std::wstring titleFontStyle       = L"";
    std::wstring artistFontStyle      = L"";
    int          titleCharacterSpacing  = 0;
    int          artistCharacterSpacing = 0;
    int          textSpacing          = -1;
    bool         enableArtistScrolling = false;
    bool         enableTitleScrolling = true;
    int          scrollSpeed          = 1;
    int          scrollPauseDuration  = 1000;
    std::wstring scrollMode           = L"bounce";
    int          loopGap              = 40;
    std::wstring solidColor           = L"35 35 35";
    std::wstring solidColor2          = L"35 35 35";
    std::wstring gradientColor2       = L"128 128 128";
    int          solidOpacity         = 100;
    int          gradientAngle        = 50;
    int          gradientBalance      = 50;
    int          acrylicTintOpacity   = 50;
    int          micaOpacity          = 50;
    std::wstring buttonColor          = L"255 255 255";
    int          buttonColorOpacity   = 100;
    std::wstring titleColor           = L"255 255 255";
    int          titleColorOpacity    = 100;
    std::wstring artistColor          = L"255 255 255";
    int          artistColorOpacity   = 80;
    std::wstring ignoredProcesses     = L"";
    std::vector<std::wstring> ignoredProcessMatchers;
    bool         enableTreeDump       = false;
    bool         keepMiniPlayerOpen   = false;
    bool         hideMediaSessionsList = false;
    bool         miniPlayerMatchPlayerBackground = true;
    std::wstring miniPlayerPlacementMode = L"screen";
    int          miniPlayerHorizontalOffsetNear = 0;
    std::wstring miniPlayerVerticalPlacementNear = L"top";
    std::wstring miniPlayerHorizontalPlacement = L"right";
    int          miniPlayerHorizontalDistanceFromScreenEdge = 0;
    std::wstring miniPlayerVerticalPlacement = L"bottom";
    int          miniPlayerVerticalDistanceFromScreenEdge = 0;
    std::wstring miniPlayerAnimation = L"auto";
    bool         hideUnsupportedButtons  = false;
    bool         disableAlbumArtClick    = false;
    bool         emptyStateHideButtons    = true;
    bool         emptyStateHideVisualizer = true;
    bool         emptyStateHideAlbumArt   = true;
    bool         enableAudioApps         = true;
    bool         audioAppsRequireSound   = true;
    std::wstring audioAppSubtitle        = L"Playing audio";
    bool         audioAppShowIcon        = true;
    std::wstring audioAppIgnore          = L"";
    std::set<std::wstring> audioAppIgnoredStems;
    int          volumeStep              = 4;
    bool         showVolumeInMenu        = true;
    std::wstring launchAppCommand        = L"spotify:";
    std::vector<std::wstring> contextMenuItems;
    std::wstring contextMenuRepeatStyle   = L"submenu";
    std::wstring contextMenuShuffleStyle  = L"submenu";
    std::wstring contextMenuIconStyle     = L"as_media_buttons";
    std::wstring contextMenuIconColor     = L"255 255 255";
    int          contextMenuIconOpacity   = 100;
    bool         vizEnabled      = false;
    std::wstring vizPosition     = L"right";
    VizShape     vizShape        = VizShape::Stereo;
    VizColorMode vizColorMode    = VizColorMode::Solid;
    VizEQ        vizEq           = VizEQ::Default;
    VizAnchor    vizAnchor       = VizAnchor::Middle;
    std::wstring vizColor        = L"255 255 255";
    std::wstring vizColor1       = L"30 215 96";
    std::wstring vizColor2       = L"0 180 255";
    int          vizBars         = 7;
    int          vizBarWidth     = 5;
    int          vizBarGap       = 5;
    int          vizIdleBarSize  = 3;
    int          vizSensitivity  = 150;
    int          vizPadLeft      = 0;
    int          vizPadRight     = 0;
};
static ModSettings g_settings;
static void ParseTwoInts(const std::wstring& s, int& a, int& b) {
    size_t sp = s.find(L' ');
    if (sp == std::wstring::npos) return;
    try {
        a = std::stoi(s.substr(0, sp));
        b = std::stoi(s.substr(sp + 1));
    } catch (...) {}
}
static constexpr int kCmdPrevious      = 1;
static constexpr int kCmdPlayPause     = 2;
static constexpr int kCmdNext          = 3;
static constexpr int kCmdStop          = 4;
static constexpr int kCmdRewind        = 5;
static constexpr int kCmdForward       = 6;
static constexpr int kCmdToggleShuffle = 7;
static constexpr int kCmdCycleRepeat   = 8;
static constexpr int kCmdSwitchSession = 9;
static constexpr int kCmdRepeatOff     = 10;
static constexpr int kCmdRepeatAll     = 11;
static constexpr int kCmdRepeatOne     = 12;
static constexpr int kCmdToggleMute    = 20;
static constexpr int kCmdVolumeUp      = 21;
static constexpr int kCmdVolumeDown    = 22;
enum class MediaButtonType {
    Previous = 1,
    PlayPause = 2,
    Next = 3,
    Rewind = 4,
    Forward = 5,
    Shuffle = 6,
    Repeat = 7,
    SwitchSessions = 8,
};
struct MediaButtonDefinition {
    std::wstring keyword;
    MediaButtonType type;
    int cmd;
};
static const std::vector<MediaButtonDefinition> g_mediaButtonDefinitions = {
    {L"prev", MediaButtonType::Previous, kCmdPrevious},
    {L"play", MediaButtonType::PlayPause, kCmdPlayPause},
    {L"next", MediaButtonType::Next, kCmdNext},
    {L"rewind", MediaButtonType::Rewind, kCmdRewind},
    {L"forward", MediaButtonType::Forward, kCmdForward},
    {L"shuffle", MediaButtonType::Shuffle, kCmdToggleShuffle},
    {L"repeat", MediaButtonType::Repeat, kCmdCycleRepeat},
    {L"switch_sessions", MediaButtonType::SwitchSessions, kCmdSwitchSession},
};
struct MediaButtonConfig {
    MediaButtonType type;
    int cmd;
};
static std::vector<MediaButtonConfig> g_mediaButtons;
static std::mutex g_mediaButtonsMutex;
static std::wstring MapFontName(const std::wstring& key) {
    if (key == L"custom") return L"";
    if (key == L"segoe_ui_variable") return L"Segoe UI Variable Display";
    if (key == L"segoe_ui") return L"Segoe UI";
    if (key == L"segoe_ui_semibold") return L"Segoe UI Semibold";
    if (key == L"segoe_ui_bold") return L"Segoe UI Bold";
    if (key == L"segoe_ui_light") return L"Segoe UI Light";
    if (key == L"segoe_ui_semilight") return L"Segoe UI Semilight";
    if (key == L"aptos") return L"Aptos";
    if (key == L"calibri") return L"Calibri";
    if (key == L"cambria") return L"Cambria";
    if (key == L"candara") return L"Candara";
    if (key == L"consolas") return L"Consolas";
    if (key == L"corbel") return L"Corbel";
    if (key == L"arial") return L"Arial";
    if (key == L"trebuchet") return L"Trebuchet MS";
    if (key == L"verdana") return L"Verdana";
    if (key == L"tahoma") return L"Tahoma";
    if (key == L"georgia") return L"Georgia";
    if (key == L"times_new_roman") return L"Times New Roman";
    return L"Segoe UI Variable Display";
}
static void LoadSettings() {
    auto Str = [](const wchar_t* key, const wchar_t* def) -> std::wstring {
        PCWSTR p = Wh_GetStringSetting(key);
        std::wstring r = (*p != L'\0') ? p : def;
        Wh_FreeStringSetting(p);
        return r;
    };
    auto StrAllowEmpty = [](const wchar_t* key) -> std::wstring {
        PCWSTR p = Wh_GetStringSetting(key);
        std::wstring r = p ? p : L"";
        Wh_FreeStringSetting(p);
        return r;
    };
    auto Int = [](const wchar_t* key, int lo, int hi, int) -> int {
        return std::clamp(Wh_GetIntSetting(key), lo, hi);
    };
    auto ParseMargin = [&Str](const wchar_t* key, const wchar_t* def, int& left, int& right) {
        std::wstring val = Str(key, def);
        try {
            size_t space = val.find(L' ');
            if (space != std::wstring::npos) {
                left  = std::stoi(val.substr(0, space));
                right = std::stoi(val.substr(space + 1));
            } else if (!val.empty()) {
                left = right = std::stoi(val);
            }
        } catch (...) {
            std::wstring d(def);
            size_t space = d.find(L' ');
            try {
                if (space != std::wstring::npos) {
                    left  = std::stoi(d.substr(0, space));
                    right = std::stoi(d.substr(space + 1));
                } else {
                    left = right = std::stoi(d);
                }
            } catch (...) { left = right = 0; }
        }
    };
    auto ParseCornerRadius = [&Str](const wchar_t* key, const wchar_t* def, double& tl, double& tr, double& br, double& bl) {
        std::wstring val = Str(key, def);
        std::vector<double> values;
        try {
            size_t pos = 0;
            while (pos < val.length()) {
                size_t space = val.find(L' ', pos);
                if (space == std::wstring::npos) space = val.length();
                std::wstring part = val.substr(pos, space - pos);
                if (!part.empty()) {
                    double v = std::stod(part);
                    values.push_back(v < 0.0 ? 0.0 : v);
                }
                pos = space + 1;
            }
        } catch (...) {}
        if (values.empty()) {
            try {
                std::wstring d(def);
                double v = std::stod(d);
                values.push_back(v < 0.0 ? 0.0 : v);
            } catch (...) {
                values.push_back(4.0);
            }
        }
        if (values.size() == 1) {
            tl = tr = br = bl = values[0];
        } else if (values.size() == 4) {
            tl = values[0];
            tr = values[1];
            br = values[2];
            bl = values[3];
        } else {
            tl = tr = br = bl = values[0];
        }
    };
    auto HoverMode = [&Str](const wchar_t* key) -> std::wstring {
        std::wstring mode = Str(key, L"auto");
        if (mode == L"black") return L"black";
        if (mode == L"white") return L"white";
        if (mode == L"off")   return L"off";
        return L"auto";
    };
    g_settings.monitor               = std::max(1, Wh_GetIntSetting(L"MainSettings.PlayerSetting.monitor"));
    g_settings.showOnAllMonitors     = Wh_GetIntSetting(L"MainSettings.PlayerSetting.showOnAllMonitors") != 0;
    g_settings.position             = Str(L"MainSettings.PlayerSetting.position",    L"tray_left");
    ParseMargin(L"MainSettings.PlayerSetting.playerMargin", L"4 4", g_settings.playerMarginLeft, g_settings.playerMarginRight);
    ParseMargin(L"MainSettings.PlayerSetting.playerWidth", L"0 0", g_settings.playerMinWidth, g_settings.playerMaxWidth);
    ParseMargin(L"MainSettings.PlayerSetting.playerHeight", L"40 40", g_settings.playerMinHeight, g_settings.playerMaxHeight);
    ParseMargin(L"MainSettings.AlbumArtSetting.albumArtWidth", L"32 64", g_settings.albumArtMinWidth, g_settings.albumArtMaxWidth);
    ParseMargin(L"MainSettings.AlbumArtSetting.albumArtHeight", L"32 32", g_settings.albumArtMinHeight, g_settings.albumArtMaxHeight);
    ParseMargin(L"MainSettings.AlbumArtSetting.albumArtMargin", L"0 0", g_settings.albumArtLeftMargin, g_settings.albumArtRightMargin);
    ParseMargin(L"MainSettings.TextAreaSetting.textAreaWidth", L"0 120", g_settings.textAreaMinWidth, g_settings.textAreaMaxWidth);
    ParseMargin(L"MainSettings.TextAreaSetting.textAreaHeight", L"0 0", g_settings.textAreaMinHeight, g_settings.textAreaMaxHeight);
    ParseMargin(L"MainSettings.TextAreaSetting.textAreaMargin", L"5 5", g_settings.textAreaLeftMargin, g_settings.textAreaRightMargin);
    g_settings.mirrorLayout         = Wh_GetIntSetting(L"MainSettings.PlayerSetting.mirrorLayout") != 0;
    g_settings.fullHeightHitArea    = Wh_GetIntSetting(L"MainSettings.PlayerSetting.fullHeightHitArea") != 0;
    g_settings.autoSwitchSession    = Wh_GetIntSetting(L"MainSettings.PlayerSetting.autoSwitchSession") != 0;
    g_settings.showMediaButtons     = Wh_GetIntSetting(L"MainSettings.MediaButtonsSettings.showMediaButtons") != 0;
    ParseMargin(L"MainSettings.MediaButtonsSettings.mediaButtonsMargin", L"2 2", g_settings.mediaButtonsLeftMargin, g_settings.mediaButtonsRightMargin);
    g_settings.showTrackTitle       = Wh_GetIntSetting(L"MainSettings.TextAreaSetting.showTrackTitle")    != 0;
    g_settings.showFullTitleOnHover = Wh_GetIntSetting(L"BehaviorSettings.showFullTitleOnHover") != 0;
    g_settings.showTrackArtist      = Wh_GetIntSetting(L"MainSettings.TextAreaSetting.showTrackArtist")   != 0;
    g_settings.swapTitleArtist      = Wh_GetIntSetting(L"MainSettings.TextAreaSetting.swapTitleArtist")   != 0;
    g_settings.emptyTitleText       = StrAllowEmpty(L"MainSettings.TextAreaSetting.emptyTitleText");
    g_settings.noMediaTitleText     = StrAllowEmpty(L"MainSettings.TextAreaSetting.noMediaTitleText");
    g_settings.emptyArtistText      = StrAllowEmpty(L"MainSettings.TextAreaSetting.emptyArtistText");
    g_settings.noMediaArtistText    = StrAllowEmpty(L"MainSettings.TextAreaSetting.noMediaArtistText");
    g_settings.showAlbumArt         = Wh_GetIntSetting(L"MainSettings.AlbumArtSetting.showAlbumArt")      != 0;
    g_settings.albumArtEmptyBehavior = Str(L"AppearanceSettings.AlbumArtDisplaySettings.albumArtEmptyBehavior", L"show");
    g_settings.emptyIconGlyph       = Str(L"AppearanceSettings.AlbumArtDisplaySettings.emptyIconGlyph",       L"E189");
    g_settings.emptyIconSize        = Int(L"AppearanceSettings.AlbumArtDisplaySettings.emptyIconSize",          1, 256, 16);
    g_settings.emptyIconFont        = Str(L"AppearanceSettings.AlbumArtDisplaySettings.emptyIconFont",        L"segoe_fluent");
    g_settings.emptyIconColor       = Str(L"AppearanceSettings.AlbumArtDisplaySettings.emptyIconColor",       L"140 140 140");
    g_settings.emptyIconOpacity     = Int(L"AppearanceSettings.AlbumArtDisplaySettings.emptyIconOpacity",       0, 100, 100);
    g_settings.albumArtQuality      = Str(L"AppearanceSettings.AlbumArtDisplaySettings.albumArtQuality", L"medium");
    g_settings.showPauseOverlay     = Wh_GetIntSetting(L"AppearanceSettings.AlbumArtDisplaySettings.showPauseOverlay")  != 0;
    g_settings.pauseOverlayIconSize = Int(L"AppearanceSettings.AlbumArtDisplaySettings.pauseOverlayIconSize",     1, 256, 16);
    g_settings.pauseOverlayOpacity  = Int(L"AppearanceSettings.AlbumArtDisplaySettings.pauseOverlayOpacity",     0, 100,  60);
    g_settings.iconStyle            = Str(L"AppearanceSettings.MediaButtonsStyleSettings.iconStyle", L"fluent_outline");
    g_settings.showAppIcon          = Wh_GetIntSetting(L"AppearanceSettings.AlbumArtDisplaySettings.showAppIcon")       != 0;
    g_settings.appIconCorner        = Str(L"AppearanceSettings.AlbumArtDisplaySettings.appIconCorner",  L"bottom_right");
    g_settings.appIconSize          = Int(L"AppearanceSettings.AlbumArtDisplaySettings.appIconSize",         8,  32,  12);
    g_settings.backgroundType       = Str(L"AppearanceSettings.BackgroundStyleSettings.backgroundType", L"none");
    g_settings.blurOpacity          = Int(L"AppearanceSettings.BackgroundStyleSettings.blurOpacity",           0, 100, 65);
    g_settings.blurRadius           = Int(L"AppearanceSettings.BackgroundStyleSettings.blurRadius",            1,  50,  11);
    ParseCornerRadius(L"AppearanceSettings.BackgroundStyleSettings.cornerRadius", L"4",
                    g_settings.cornerRadiusTL, g_settings.cornerRadiusTR,
                    g_settings.cornerRadiusBR, g_settings.cornerRadiusBL);
    g_settings.albumArtOpacity      = Int(L"AppearanceSettings.AlbumArtDisplaySettings.albumArtOpacity",       0, 100, 100);
    ParseCornerRadius(L"AppearanceSettings.AlbumArtDisplaySettings.albumArtCornerRadius", L"4",
                    g_settings.albumArtCornerRadiusTL, g_settings.albumArtCornerRadiusTR,
                    g_settings.albumArtCornerRadiusBR, g_settings.albumArtCornerRadiusBL);
    g_settings.buttonSpacing        = Wh_GetIntSetting(L"AppearanceSettings.MediaButtonsStyleSettings.buttonSpacing");
    g_settings.buttonSize           = Int(L"MainSettings.MediaButtonsSettings.buttonSize",          16,  48,  28);
    g_settings.seekStepSeconds      = Int(L"MainSettings.MediaButtonsSettings.seekStepSeconds",       1,  60,   5);
    g_settings.buttonIconSize       = Int(L"AppearanceSettings.MediaButtonsStyleSettings.buttonIconSize",       8,  32,  12);
    ParseCornerRadius(L"AppearanceSettings.MediaButtonsStyleSettings.buttonCornerRadius", L"4",
                    g_settings.buttonCornerRadiusTL, g_settings.buttonCornerRadiusTR,
                    g_settings.buttonCornerRadiusBR, g_settings.buttonCornerRadiusBL);
    g_settings.titleFontSize        = Int(L"AppearanceSettings.TitleTextStyleSettings.titleFontSize",         7,  24,  12);
    g_settings.titleFont            = MapFontName(Str(L"AppearanceSettings.TitleTextStyleSettings.titleFont", L"segoe_ui_variable"));
    g_settings.titleFontFamily      = Str(L"AppearanceSettings.TitleTextStyleSettings.titleFontFamily", L"");
    g_settings.titleFontWeight      = Str(L"AppearanceSettings.TitleTextStyleSettings.titleFontWeight", L"");
    g_settings.titleFontStyle       = Str(L"AppearanceSettings.TitleTextStyleSettings.titleFontStyle", L"");
    g_settings.titleCharacterSpacing = Wh_GetIntSetting(L"AppearanceSettings.TitleTextStyleSettings.titleCharacterSpacing");
    g_settings.artistFontSize       = Int(L"AppearanceSettings.ArtistTextStyleSettings.artistFontSize",        7,  24,  11);
    g_settings.artistFont           = MapFontName(Str(L"AppearanceSettings.ArtistTextStyleSettings.artistFont", L"segoe_ui_variable"));
    g_settings.artistFontFamily     = Str(L"AppearanceSettings.ArtistTextStyleSettings.artistFontFamily", L"");
    g_settings.artistFontWeight     = Str(L"AppearanceSettings.ArtistTextStyleSettings.artistFontWeight", L"");
    g_settings.artistFontStyle      = Str(L"AppearanceSettings.ArtistTextStyleSettings.artistFontStyle", L"");
    g_settings.artistCharacterSpacing = Wh_GetIntSetting(L"AppearanceSettings.ArtistTextStyleSettings.artistCharacterSpacing");
    g_settings.textSpacing          = Wh_GetIntSetting(L"MainSettings.TextAreaSetting.textSpacing");
    g_settings.enableArtistScrolling = Wh_GetIntSetting(L"MainSettings.TextAreaSetting.enableArtistScrolling") != 0;
    g_settings.enableTitleScrolling = Wh_GetIntSetting(L"MainSettings.TextAreaSetting.enableTitleScrolling") != 0;
    g_settings.scrollSpeed          = Int(L"MainSettings.TextAreaSetting.scrollSpeed", 1, 10, 1);
    g_settings.scrollPauseDuration  = Int(L"MainSettings.TextAreaSetting.scrollPauseDuration", 0, 10000, 1000);
    g_settings.scrollMode           = Str(L"MainSettings.TextAreaSetting.scrollMode", L"bounce");
    g_settings.loopGap              = Int(L"MainSettings.TextAreaSetting.loopGap", 0, 500, 40);
    g_settings.solidColor           = Str(L"AppearanceSettings.BackgroundStyleSettings.solidColor", L"35 35 35");
    g_settings.solidColor2          = Str(L"AppearanceSettings.BackgroundStyleSettings.solidColor2", L"35 35 35");
    g_settings.gradientColor2       = Str(L"AppearanceSettings.BackgroundStyleSettings.gradientColor2", L"128 128 128");
    g_settings.solidOpacity         = Int(L"AppearanceSettings.BackgroundStyleSettings.solidOpacity", 0, 100, 100);
    g_settings.gradientAngle        = Int(L"AppearanceSettings.BackgroundStyleSettings.gradientAngle", 0, 360, 50);
    g_settings.gradientBalance      = Int(L"AppearanceSettings.BackgroundStyleSettings.gradientBalance", 0, 100, 50);
    g_settings.acrylicTintOpacity   = Int(L"AppearanceSettings.BackgroundStyleSettings.acrylicTintOpacity", 0, 100, 50);
    g_settings.micaOpacity          = Int(L"AppearanceSettings.BackgroundStyleSettings.micaOpacity", 0, 100, 50);
    g_settings.buttonColor          = Str(L"AppearanceSettings.MediaButtonsStyleSettings.buttonColor", L"0 0 0$255 255 255");
    g_settings.buttonColorOpacity   = Int(L"AppearanceSettings.MediaButtonsStyleSettings.buttonColorOpacity", 0, 100, 100);
    g_settings.titleColor           = Str(L"AppearanceSettings.TitleTextStyleSettings.titleColor", L"0 0 0$255 255 255");
    g_settings.titleColorOpacity    = Int(L"AppearanceSettings.TitleTextStyleSettings.titleColorOpacity", 0, 100, 100);
    g_settings.artistColor          = Str(L"AppearanceSettings.ArtistTextStyleSettings.artistColor", L"0 0 0$255 255 255");
    g_settings.artistColorOpacity   = Int(L"AppearanceSettings.ArtistTextStyleSettings.artistColorOpacity", 0, 100, 80);
    g_settings.vizEnabled      = Wh_GetIntSetting(L"MainSettings.VisualizerFunctionsSettings.vizEnabled") != 0;
    g_settings.vizPosition     = Str(L"MainSettings.VisualizerFunctionsSettings.vizPosition", L"right");
    g_settings.vizColor        = Str(L"AppearanceSettings.VisualizerStyleSettings.vizColor",  L"0 0 0$255 255 255");
    g_settings.vizColor1       = Str(L"AppearanceSettings.VisualizerStyleSettings.vizColor1", L"30 215 96");
    g_settings.vizColor2       = Str(L"AppearanceSettings.VisualizerStyleSettings.vizColor2", L"0 180 255");
    g_settings.vizSensitivity  = Int(L"MainSettings.VisualizerFunctionsSettings.vizSensitivity", 0, 300, 150);
    {
        int n = 7, gap = 5;
        ParseTwoInts(Str(L"MainSettings.VisualizerFunctionsSettings.vizBarCountGap", L"7 5"), n, gap);
        g_settings.vizBars   = std::clamp(n, 1, 20);
        g_settings.vizBarGap = std::clamp(gap, 0, 40);
        int w = 5, h = 3;
        ParseTwoInts(Str(L"MainSettings.VisualizerFunctionsSettings.vizBarSize", L"5 3"), w, h);
        g_settings.vizBarWidth    = std::clamp(w, 0, 40);
        g_settings.vizIdleBarSize = std::clamp(h, 0, 15);
        int l = 0, r = 0;
        ParseTwoInts(Str(L"MainSettings.VisualizerFunctionsSettings.vizPadding", L"0 0"), l, r);
        g_settings.vizPadLeft  = std::clamp(l, 0, 200);
        g_settings.vizPadRight = std::clamp(r, 0, 200);
    }
    {
        std::wstring shape = Str(L"MainSettings.VisualizerFunctionsSettings.vizShape", L"stereo");
        g_settings.vizShape = (shape == L"mountain") ? VizShape::Mountain
                    : (shape == L"mirror")   ? VizShape::Mirror
                    : (shape == L"wave")     ? VizShape::Wave
                    : (shape == L"breathe")  ? VizShape::Breathe
                                            : VizShape::Stereo;
        std::wstring mode = Str(L"AppearanceSettings.VisualizerStyleSettings.vizColorMode", L"solid");
        g_settings.vizColorMode = (mode == L"dynamic_album")    ? VizColorMode::DynamicAlbum
                        : (mode == L"dynamic_gradient") ? VizColorMode::DynamicGradient
                        : (mode == L"custom_gradient")  ? VizColorMode::CustomGradient
                        : (mode == L"acrylic")          ? VizColorMode::Acrylic
                                                        : VizColorMode::Solid;
        std::wstring eq = Str(L"MainSettings.VisualizerFunctionsSettings.vizEQ", L"default");
        g_settings.vizEq = (eq == L"bass")       ? VizEQ::Bass
                : (eq == L"rock")       ? VizEQ::Rock
                : (eq == L"pop")        ? VizEQ::Pop
                : (eq == L"jazz")       ? VizEQ::Jazz
                : (eq == L"electronic") ? VizEQ::Electronic
                                        : VizEQ::Default;
        std::wstring anchor = Str(L"MainSettings.VisualizerFunctionsSettings.vizAnchor", L"middle");
        g_settings.vizAnchor = (anchor == L"top")    ? VizAnchor::Top
                    : (anchor == L"bottom") ? VizAnchor::Bottom
                                            : VizAnchor::Middle;
    }
    g_settings.albumArtLeftClick         = L"none";
    g_settings.albumArtRightClick        = L"none";
    g_settings.albumArtMiddleClick       = L"none";
    g_settings.albumArtLeftDoubleClick   = L"none";
    g_settings.albumArtRightDoubleClick  = L"none";
    g_settings.albumArtMiddleDoubleClick = L"none";
    g_settings.playerLeftClick           = L"none";
    g_settings.playerRightClick          = L"none";
    g_settings.playerMiddleClick         = L"none";
    g_settings.playerLeftDoubleClick     = L"open_configured_app";
    g_settings.playerRightDoubleClick    = L"none";
    g_settings.playerMiddleDoubleClick   = L"none";
    for (int i = 0; i < 20; i++) {
        PCWSTR objectStr = Wh_GetStringSetting(L"BehaviorSettings.ClickActionSettings[%d].object", i);
        PCWSTR clickStr = Wh_GetStringSetting(L"BehaviorSettings.ClickActionSettings[%d].click", i);
        PCWSTR actionStr = Wh_GetStringSetting(L"BehaviorSettings.ClickActionSettings[%d].action", i);
        if (*objectStr == L'\0' || *clickStr == L'\0' || *actionStr == L'\0') {
            Wh_FreeStringSetting(objectStr);
            Wh_FreeStringSetting(clickStr);
            Wh_FreeStringSetting(actionStr);
            break;
        }
        std::wstring object(objectStr);
        std::wstring click(clickStr);
        std::wstring action(actionStr);
        Wh_FreeStringSetting(objectStr);
        Wh_FreeStringSetting(clickStr);
        Wh_FreeStringSetting(actionStr);
        if (object.empty()) object = L"none";
        if (click.empty()) click = L"none";
        if (action.empty()) action = L"none";
        if (object == L"none" || click == L"none") {
            continue;
        }
        if (object == L"album_art") {
            if (click == L"left_click") g_settings.albumArtLeftClick = action;
            else if (click == L"right_click") g_settings.albumArtRightClick = action;
            else if (click == L"middle_click") g_settings.albumArtMiddleClick = action;
            else if (click == L"left_double_click") g_settings.albumArtLeftDoubleClick = action;
            else if (click == L"right_double_click") g_settings.albumArtRightDoubleClick = action;
            else if (click == L"middle_double_click") g_settings.albumArtMiddleDoubleClick = action;
        } else if (object == L"player") {
            if (click == L"left_click") g_settings.playerLeftClick = action;
            else if (click == L"right_click") g_settings.playerRightClick = action;
            else if (click == L"middle_click") g_settings.playerMiddleClick = action;
            else if (click == L"left_double_click") g_settings.playerLeftDoubleClick = action;
            else if (click == L"right_double_click") g_settings.playerRightDoubleClick = action;
            else if (click == L"middle_double_click") g_settings.playerMiddleDoubleClick = action;
        }
    }
    g_settings.albumArtWheelAction = L"none";
    g_settings.playerWheelAction   = L"none";
    for (int i = 0; i < 20; i++) {
        PCWSTR objectStr = Wh_GetStringSetting(L"BehaviorSettings.MouseWheelActionSettings[%d].object", i);
        PCWSTR clickStr = Wh_GetStringSetting(L"BehaviorSettings.MouseWheelActionSettings[%d].click", i);
        PCWSTR actionStr = Wh_GetStringSetting(L"BehaviorSettings.MouseWheelActionSettings[%d].action", i);
        if (*objectStr == L'\0' || *clickStr == L'\0' || *actionStr == L'\0') {
            Wh_FreeStringSetting(objectStr);
            Wh_FreeStringSetting(clickStr);
            Wh_FreeStringSetting(actionStr);
            break;
        }
        std::wstring object(objectStr);
        std::wstring click(clickStr);
        std::wstring action(actionStr);
        Wh_FreeStringSetting(objectStr);
        Wh_FreeStringSetting(clickStr);
        Wh_FreeStringSetting(actionStr);
        if (object.empty()) object = L"none";
        if (click.empty()) click = L"none";
        if (action.empty()) action = L"none";
        if (object == L"none" || click == L"none") {
            continue;
        }
        if (object == L"album_art" && click == L"mouse_wheel") {
            g_settings.albumArtWheelAction = action;
        } else if (object == L"player" && click == L"mouse_wheel") {
            g_settings.playerWheelAction = action;
        }
    }
    g_settings.hideWhenNoMedia      = Wh_GetIntSetting(L"BehaviorSettings.hideWhenNoMedia")   != 0;
    g_settings.hideFullscreen       = Wh_GetIntSetting(L"BehaviorSettings.hideFullscreen")    != 0;
    g_settings.idleHideSeconds      = std::max(Wh_GetIntSetting(L"BehaviorSettings.idleHideSeconds"), 0);
    g_settings.playerHoverEffectMode = HoverMode(L"AppearanceSettings.BackgroundStyleSettings.enablePlayerHoverEffect");
    g_settings.mediaButtonsHoverEffectMode = HoverMode(L"AppearanceSettings.BackgroundStyleSettings.enableMediaButtonsHoverEffect");
    g_settings.enableHoverAnimation = Wh_GetIntSetting(L"AppearanceSettings.BackgroundStyleSettings.enableHoverAnimation") != 0;
    g_settings.enableSmoothPositionAnimation = Wh_GetIntSetting(L"AnimationSettings.enableSmoothPositionAnimation") != 0;
    g_settings.hideUnsupportedButtons  = Wh_GetIntSetting(L"MainSettings.MediaButtonsSettings.hideUnsupportedButtons") != 0;
    g_settings.disableAlbumArtClick    = Wh_GetIntSetting(L"BehaviorSettings.disableAlbumArtClick") != 0;
    g_settings.emptyStateHideButtons    = Wh_GetIntSetting(L"BehaviorSettings.emptyStateHideButtons") != 0;
    g_settings.emptyStateHideVisualizer = Wh_GetIntSetting(L"BehaviorSettings.emptyStateHideVisualizer") != 0;
    g_settings.emptyStateHideAlbumArt   = Wh_GetIntSetting(L"BehaviorSettings.emptyStateHideAlbumArt") != 0;
    g_settings.enableAudioApps       = Wh_GetIntSetting(L"AudioAppSettings.enableAudioApps") != 0;
    g_settings.audioAppsRequireSound = Wh_GetIntSetting(L"AudioAppSettings.audioAppsRequireSound") != 0;
    g_settings.audioAppSubtitle      = StrAllowEmpty(L"AudioAppSettings.audioAppSubtitle");
    g_settings.audioAppShowIcon      = Wh_GetIntSetting(L"AudioAppSettings.audioAppShowIcon") != 0;
    g_settings.audioAppIgnore        = StrAllowEmpty(L"AudioAppSettings.audioAppIgnore");
    g_settings.volumeStep            = Int(L"AudioAppSettings.volumeStep", 1, 50, 4);
    g_settings.showVolumeInMenu      = Wh_GetIntSetting(L"AudioAppSettings.showVolumeInMenu") != 0;
    g_settings.launchAppCommand         = Str(L"BehaviorSettings.launchAppCommand", L"spotify:");
    g_settings.ignoredProcesses     = Str(L"BehaviorSettings.ignoredProcesses", L"");
    g_settings.ignoredProcessMatchers.clear();
    g_settings.audioAppIgnoredStems.clear();
    auto ParseProcessList = [](const std::wstring& list, auto&& fn) {
        auto Lower = [](std::wstring value) {
            std::transform(value.begin(), value.end(), value.begin(),
                [](wchar_t c) { return (wchar_t)towlower(c); });
            return value;
        };
        auto Stem = [](std::wstring value) {
            size_t slash = value.find_last_of(L"\\/");
            if (slash != std::wstring::npos) value.erase(0, slash + 1);
            size_t dot = value.rfind(L'.');
            if (dot != std::wstring::npos) value.resize(dot);
            return value;
        };
        size_t start = 0;
        while (start <= list.size()) {
            size_t end = list.find(L';', start);
            std::wstring item = list.substr(
                start, end == std::wstring::npos ? std::wstring::npos : end - start);
            while (!item.empty() && iswspace(item.front())) item.erase(item.begin());
            while (!item.empty() && iswspace(item.back())) item.pop_back();
            if (!item.empty()) {
                std::wstring stem = Lower(Stem(item));
                if (!stem.empty()) fn(std::move(stem));
            }
            if (end == std::wstring::npos) break;
            start = end + 1;
        }
    };
    ParseProcessList(g_settings.ignoredProcesses,
        [](std::wstring stem) {
            g_settings.ignoredProcessMatchers.push_back(std::move(stem));
        });
    ParseProcessList(g_settings.audioAppIgnore,
        [](std::wstring stem) {
            g_settings.audioAppIgnoredStems.insert(std::move(stem));
        });
    g_settings.keepMiniPlayerOpen   = Wh_GetIntSetting(L"PlayerMenuSettings.keepMiniPlayerOpen") != 0;
    g_settings.hideMediaSessionsList = Wh_GetIntSetting(L"PlayerMenuSettings.hideMediaSessionsList") != 0;
    g_settings.miniPlayerMatchPlayerBackground =
        Wh_GetIntSetting(L"PlayerMenuSettings.miniPlayerMatchPlayerBackground") != 0;
    g_settings.miniPlayerPlacementMode = Str(L"PlayerMenuSettings.placementMode", L"screen");
    g_settings.miniPlayerHorizontalOffsetNear =
        Wh_GetIntSetting(L"PlayerMenuSettings.PlayerMenuSettingsNear.miniPlayerHorizontalOffsetNear");
    g_settings.miniPlayerVerticalPlacementNear =
        Str(L"PlayerMenuSettings.PlayerMenuSettingsNear.miniPlayerVerticalPlacementNear", L"top");
    g_settings.miniPlayerHorizontalPlacement =
        Str(L"PlayerMenuSettings.PlayerMenuSettingsScreen.miniPlayerHorizontalPlacement", L"right");
    g_settings.miniPlayerHorizontalDistanceFromScreenEdge =
        Wh_GetIntSetting(L"PlayerMenuSettings.PlayerMenuSettingsScreen.horizontalDistanceFromScreenEdge");
    g_settings.miniPlayerVerticalPlacement =
        Str(L"PlayerMenuSettings.PlayerMenuSettingsScreen.miniPlayerVerticalPlacement", L"bottom");
    g_settings.miniPlayerVerticalDistanceFromScreenEdge =
        Wh_GetIntSetting(L"PlayerMenuSettings.PlayerMenuSettingsScreen.verticalDistanceFromScreenEdge");
    g_settings.miniPlayerAnimation =
        Str(L"PlayerMenuSettings.PlayerMenuSettingsScreen.miniPlayerAnimation", L"auto");
    g_settings.contextMenuRepeatStyle  = Str(L"ContextMenuSettings.repeatStyle",  L"submenu");
    g_settings.contextMenuShuffleStyle = Str(L"ContextMenuSettings.shuffleStyle", L"toggle");
    g_settings.contextMenuIconStyle    = Str(L"ContextMenuSettings.contextMenuIconStyle", L"as_media_buttons");
    g_settings.contextMenuIconColor    = StrAllowEmpty(L"ContextMenuSettings.contextMenuIconColor");
    g_settings.contextMenuIconOpacity  = Int(L"ContextMenuSettings.contextMenuIconOpacity", 0, 100, 100);
    {
        g_settings.contextMenuItems.clear();
        const wchar_t* defaultItems[] = { L"switch_sessions", L"open_app" };
        std::set<std::wstring> seen;
        for (int i = 0; i < 20; i++) {
            PCWSTR p = Wh_GetStringSetting(L"ContextMenuSettings.contextMenuItems[%d]", i);
            if (!p || !*p) { Wh_FreeStringSetting(p); break; }
            std::wstring s(p);
            Wh_FreeStringSetting(p);
            if (seen.insert(s).second) {
                g_settings.contextMenuItems.push_back(s);
            }
        }
        if (g_settings.contextMenuItems.empty()) {
            for (auto& d : defaultItems)
                g_settings.contextMenuItems.push_back(d);
        }
    }
    try {
        std::lock_guard<std::mutex> lock(g_mediaButtonsMutex);
        g_mediaButtons.clear();
        std::set<MediaButtonType> seen;
        for (int i = 0; i < 10; i++) {
            try {
                PCWSTR itemStr = Wh_GetStringSetting(L"MainSettings.MediaButtonsSettings.mediaButtons[%d]", i);
                if (!itemStr || !*itemStr) {
                    Wh_FreeStringSetting(itemStr);
                    break;
                }
                std::wstring keyword(itemStr);
                Wh_FreeStringSetting(itemStr);
                for (const auto& def : g_mediaButtonDefinitions) {
                    if (def.keyword == keyword && seen.insert(def.type).second) {
                        g_mediaButtons.push_back({def.type, def.cmd});
                        break;
                    }
                }
            } catch (...) {
                Wh_Log(L"LoadSettings: Exception parsing media button at index %d", i);
            }
        }
    } catch (...) {
        Wh_Log(L"LoadSettings: Critical exception in media buttons parsing, using defaults");
        try {
            std::lock_guard<std::mutex> lock(g_mediaButtonsMutex);
            g_mediaButtons = {
                {MediaButtonType::Previous, kCmdPrevious},
                {MediaButtonType::PlayPause, kCmdPlayPause},
                {MediaButtonType::Next, kCmdNext}
            };
        } catch (...) {}
    }
    if (g_settings.position == L"taskbar_left")
        g_settings.position = L"taskbar_left_start";
    else if (g_settings.position == L"taskbar_right")
        g_settings.position = L"taskbar_right_start";
    else if (g_settings.position == L"taskbar_after_start")
        g_settings.position = L"taskbar_after_search_right";
    else if (g_settings.position == L"taskbar_after_search")
        g_settings.position = L"taskbar_after_search_right";
    else if (g_settings.position == L"tray_before_omni")
        g_settings.position = L"tray_before_omni_right";
    else if (g_settings.position == L"tray_after_showdesktop")
        g_settings.position = L"tray_after_showdesktop_right";
}
static HWND FindCurrentProcessTaskbarWnd();
static void DispatchMediaUpdate();
static void RefreshMiniPlayerFlyoutUI();
static void FetchMiniSessionInfosAsync(HWND taskbarWnd);
struct MiniSessionInfo;
static void AnimateSessionPill(winrt::Windows::UI::Xaml::Shapes::Rectangle const& pill, bool isCurrent, bool animate);
static winrt::Windows::UI::Xaml::Controls::Button BuildSessionRowButton(const MiniSessionInfo& info, bool isCurrent, int rowIndex);

static void ApplySettings();
static std::atomic<bool> g_unloading{false};
static std::atomic<bool> g_applyingSettings{false};
static HWND g_taskbarWnd = nullptr;
static HWND g_curTaskbarWnd = nullptr;

template <typename F> static void ForEachPlayerInstance(F&& fn);
static int  PlayerInstanceCount();

static std::atomic<int> g_activeWorkerThreads{0};
template <typename F>
static void SpawnTrackedWorker(F&& fn) {
    struct Worker {
        std::function<void()> fn;
        HMODULE module;
    };
    auto* worker = new Worker{std::forward<F>(fn), nullptr};
    GetModuleHandleExW(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS,
                       reinterpret_cast<LPCWSTR>(&g_activeWorkerThreads), &worker->module);
    g_activeWorkerThreads.fetch_add(1, std::memory_order_relaxed);
    HANDLE thread = CreateThread(nullptr, 0, [](LPVOID param) WINAPI -> DWORD {
        auto* worker = static_cast<Worker*>(param);
        HMODULE module = worker->module;
        worker->fn();
        delete worker;
        g_activeWorkerThreads.fetch_sub(1, std::memory_order_release);
        FreeLibraryAndExitThread(module, 0);
    }, worker, 0, nullptr);
    if (thread) {
        CloseHandle(thread);
        return;
    }
    FreeLibrary(worker->module);
    delete worker;
    g_activeWorkerThreads.fetch_sub(1, std::memory_order_release);
}

static void WaitForTrackedWorkers() {
    HWND hTaskbar = g_taskbarWnd;
    DWORD tid = GetCurrentThreadId();
    bool isUiThread = hTaskbar && (GetWindowThreadProcessId(hTaskbar, nullptr) == tid);
    if (isUiThread) {
        while (g_activeWorkerThreads.load(std::memory_order_acquire) > 0) {
            MSG msg;
            while (PeekMessageW(&msg, nullptr, 0, 0, PM_REMOVE | PM_QS_SENDMESSAGE)) {
                TranslateMessage(&msg);
                DispatchMessageW(&msg);
            }
            Sleep(10);
        }
    } else {
        while (g_activeWorkerThreads.load(std::memory_order_acquire) > 0) {
            Sleep(10);
        }
    }
}

static std::atomic<bool> g_miniPlayerFlyoutOpen{false};
static bool   g_miniPlayerAnimHorizontal = false;
static double g_miniPlayerAnimSign = 1.0;
static std::atomic<bool> g_miniPlayerClosingAnimInProgress{false};
static std::atomic<bool> g_miniPlayerClosingAnimStarted{false};
static std::atomic<bool> g_miniPlayerExplicitCloseRequested{false};
static IMMDeviceEnumerator* g_pDeviceEnumerator = nullptr;
static const CLSID XIID_MMDeviceEnumerator = __uuidof(MMDeviceEnumerator);
static const IID XIID_IMMDeviceEnumerator = __uuidof(IMMDeviceEnumerator);
static const IID XIID_IAudioSessionManager2 = __uuidof(IAudioSessionManager2);
[[clang::no_destroy]] static Grid             g_playerGrid      = nullptr;
[[clang::no_destroy]] static FrameworkElement g_injectionParent = nullptr;
static int              g_playerColumn    = -1;
[[clang::no_destroy]] static std::function<void()> g_playerButtonStateUpdater;
[[clang::no_destroy]] static ToolTip          g_playerToolTip   = nullptr;
static std::atomic<bool> g_needsUiUpdate{false};
[[clang::no_destroy]] static FrameworkElement g_trackedElement = nullptr;
static Thickness g_trackedElementOriginalMargin{};
static std::wstring g_trackPosition = L"";
static winrt::event_token g_layoutUpdateToken{};
using CTaskBand_GetTaskbarHost_t  = void*(WINAPI*)(void*, void*);
using CSecondaryTaskBand_GetTaskbarHost_t = void*(WINAPI*)(void*, void*);
using TaskbarHost_FrameHeight_t   = int  (WINAPI*)(void*);
using Std_Ref_Decref_t            = void (WINAPI*)(void*);
static CTaskBand_GetTaskbarHost_t  CTaskBand_GetTaskbarHost_Original  = nullptr;
static CSecondaryTaskBand_GetTaskbarHost_t CSecondaryTaskBand_GetTaskbarHost_Original = nullptr;
static TaskbarHost_FrameHeight_t   TaskbarHost_FrameHeight_Original   = nullptr;
static Std_Ref_Decref_t            Std_Ref_Decref_Original            = nullptr;
static void* CTaskBand_ITaskListWndSite_vftable = nullptr;
static void* CSecondaryTaskBand_ITaskListWndSite_vftable = nullptr;
using WindowThreadProc = void(*)(void*);
static bool RunFromWindowThread(HWND hWnd, WindowThreadProc proc, void* param) {
    static const UINT kMsg = RegisterWindowMessage(L"Windhawk_RunFromWindowThread_" WH_MOD_ID);
    struct Payload { WindowThreadProc proc; void* param; };
    DWORD tid = GetWindowThreadProcessId(hWnd, nullptr);
    if (!tid) return false;
    if (tid == GetCurrentThreadId()) {
        proc(param);
        return true;
    }
    HHOOK hook = SetWindowsHookExW(WH_CALLWNDPROC,
        [](int code, WPARAM w, LPARAM l) CALLBACK -> LRESULT {
            if (code == HC_ACTION) {
                auto* cwp = reinterpret_cast<const CWPSTRUCT*>(l);
                static const UINT kM = RegisterWindowMessage(L"Windhawk_RunFromWindowThread_" WH_MOD_ID);
                if (cwp->message == kM) {
                    auto* p = reinterpret_cast<Payload*>(cwp->lParam);
                    p->proc(p->param);
                }
            }
            return CallNextHookEx(nullptr, code, w, l);
        }, nullptr, tid);
    if (!hook) return false;
    Payload pay{proc, param};
    SendMessageW(hWnd, kMsg, 0, reinterpret_cast<LPARAM>(&pay));
    UnhookWindowsHookEx(hook);
    return true;
}
struct MediaState {
    std::wstring      title;
    std::wstring      artist;
    std::wstring      appUserModelId;
    bool              isPlaying     = false;
    bool              hasMedia      = false;
    std::vector<BYTE> thumbnailBytes;
    uint64_t          thumbnailHash = 0;
    uint64_t          thumbnailStreamSize = 0;
    std::vector<BYTE> appIconBytes;
    std::wstring      appIconKey;
    bool              canSkipPrevious  = true;
    bool              canSkipNext      = true;
    bool              canShuffle       = true;
    bool              canRepeat        = true;
    bool              canSeek          = true;
};
static MediaState g_media;
static std::mutex g_mediaMtx;
static std::wstring g_lastTitleArtistKey;
static uint64_t     g_suspectArtSize   = 0;
static uint64_t     g_suspectArtHash   = 0;
static bool         g_artDelayPending  = false;
enum class RepeatMode {
    Off = 0,
    All = 1,
    One = 2,
};
static std::atomic<bool> g_shuffleEnabled{false};
static std::atomic<RepeatMode> g_repeatMode{RepeatMode::Off};
static std::wstring g_cachedAlbumTitle;
static std::wstring g_cachedAlbumArtist;
static std::vector<BYTE> g_cachedThumbnailBytes;
static std::wstring g_scrollCachedTitle;
static std::wstring g_scrollCachedArtist;
struct BlurBgCache {
    std::vector<BYTE>  blurredPixels;
    int                width  = 0;
    int                height = 0;
    size_t             artHash = 0;
    void Invalidate() {
        blurredPixels.clear();
        width = height = 0;
        artHash = 0;
    }
} g_blurBgCache;
struct AlbumPalette {
    winrt::Windows::UI::Color primary;
    winrt::Windows::UI::Color secondary;
};
static AlbumPalette g_cachedAlbumPalette = {
    winrt::Windows::UI::Color{255, 18, 18, 18},
    winrt::Windows::UI::Color{255, 45, 45, 45}
};
static size_t g_cachedPaletteHash = 0;
static winrt::Windows::UI::Color g_cachedVizBaseColor{255, 255, 255, 255};
static bool g_vizBaseColorDirty = true;
static winrt::Windows::UI::Color g_cachedVizPal0{255, 255, 255, 255};
static winrt::Windows::UI::Color g_cachedVizPal1{255, 255, 255, 255};
static winrt::Windows::UI::Color g_cachedVizCg0{255, 255, 255, 255};
static winrt::Windows::UI::Color g_cachedVizCg1{255, 255, 255, 255};
static winrt::Windows::UI::Color g_cachedVizAcrCol{255, 255, 255, 255};
static bool g_vizPaletteColorsDirty = true;
[[clang::no_destroy]] static GlobalSystemMediaTransportControlsSessionManager g_sessionMgr     = nullptr;
[[clang::no_destroy]] static GlobalSystemMediaTransportControlsSession        g_currentSession = nullptr;
static std::mutex  g_sessionMtx;
static std::mutex  g_attachMtx;
static bool g_userSwitchedSession = false;
static std::atomic<bool> g_forceSessionRefresh{false};
static std::atomic<int> g_sessionCount{0};
static winrt::event_token g_evSessionsChanged{};
static winrt::event_token g_evCurrentChanged{};
static winrt::event_token g_evMediaProps{};
static winrt::event_token g_evPlayback{};
static HANDLE g_mediaThread    = nullptr;
static HANDLE g_mediaStopEvent = nullptr;
static bool IsSystemLightTheme() {
    DWORD v = 0, sz = sizeof(v);
    if (RegGetValueW(HKEY_CURRENT_USER,
        L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize",
        L"SystemUsesLightTheme", RRF_RT_DWORD, nullptr, &v, &sz) == ERROR_SUCCESS) {
        return v != 0;
    }
    v = 0; sz = sizeof(v);
    RegGetValueW(HKEY_CURRENT_USER,
        L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize",
        L"AppsUseLightTheme", RRF_RT_DWORD, nullptr, &v, &sz);
    return v != 0;
}
static SolidColorBrush MakeBrush(winrt::Windows::UI::Color c) {
    SolidColorBrush b; b.Color(c); return b;
}
static bool IsHoverEffectEnabled(std::wstring const& mode) {
    return mode != L"off";
}
static bool IsHoverLightTheme(std::wstring const& mode) {
    if (mode == L"white") return true;
    if (mode == L"black") return false;
    return IsSystemLightTheme();
}
static winrt::Windows::UI::Color GetSystemButtonHoverColor(std::wstring const& mode) {
    if (IsHoverLightTheme(mode)) {
        return winrt::Windows::UI::Color{0x99, 0xFF, 0xFF, 0xFF};
    }
    return winrt::Windows::UI::Color{0x0F, 0xFF, 0xFF, 0xFF};
}
static winrt::Windows::UI::Color GetSystemButtonPressedColor(std::wstring const& mode) {
    if (IsHoverLightTheme(mode)) {
        return winrt::Windows::UI::Color{0x4D, 0xFF, 0xFF, 0xFF};
    }
    return winrt::Windows::UI::Color{0x0A, 0xFF, 0xFF, 0xFF};
}
static winrt::Windows::UI::Color GetSystemButtonBorderColor(std::wstring const& mode) {
    if (IsHoverLightTheme(mode)) {
        return winrt::Windows::UI::Color{0x08, 0x00, 0x00, 0x00};
    }
    return winrt::Windows::UI::Color{0x14, 0xFF, 0xFF, 0xFF};
}
static winrt::Windows::UI::Color GetSystemButtonBorderPressedColor(std::wstring const& mode) {
    if (IsHoverLightTheme(mode)) {
        return winrt::Windows::UI::Color{0x05, 0x00, 0x00, 0x00};
    }
    return winrt::Windows::UI::Color{0x0A, 0xFF, 0xFF, 0xFF};
}
[[clang::no_destroy]] static SolidColorBrush g_mediaHoverBrush   = nullptr;
[[clang::no_destroy]] static SolidColorBrush g_mediaPressedBrush = nullptr;
[[clang::no_destroy]] static SolidColorBrush g_playerHoverBrush   = nullptr;
[[clang::no_destroy]] static SolidColorBrush g_playerPressedBrush = nullptr;
[[clang::no_destroy]] static SolidColorBrush g_playerBorderBrush  = nullptr;
[[clang::no_destroy]] static SolidColorBrush g_playerBorderPressedBrush = nullptr;
static void EnsureHoverBrushes() {
    if (!g_mediaHoverBrush) {
        g_mediaHoverBrush   = SolidColorBrush(GetSystemButtonHoverColor(g_settings.mediaButtonsHoverEffectMode));
        g_mediaPressedBrush = SolidColorBrush(GetSystemButtonPressedColor(g_settings.mediaButtonsHoverEffectMode));
    }
    if (!g_playerHoverBrush) {
        g_playerHoverBrush   = SolidColorBrush(GetSystemButtonHoverColor(g_settings.playerHoverEffectMode));
        g_playerPressedBrush = SolidColorBrush(GetSystemButtonPressedColor(g_settings.playerHoverEffectMode));
        g_playerBorderBrush  = SolidColorBrush(GetSystemButtonBorderColor(g_settings.playerHoverEffectMode));
        g_playerBorderPressedBrush = SolidColorBrush(GetSystemButtonBorderPressedColor(g_settings.playerHoverEffectMode));
    }
}
static void UpdateHoverBrushColors() {
    if (g_mediaHoverBrush) {
        try { g_mediaHoverBrush.Color(GetSystemButtonHoverColor(g_settings.mediaButtonsHoverEffectMode)); } catch (...) {}
    } else {
        try { g_mediaHoverBrush = SolidColorBrush(GetSystemButtonHoverColor(g_settings.mediaButtonsHoverEffectMode)); } catch (...) {}
    }
    if (g_mediaPressedBrush) {
        try { g_mediaPressedBrush.Color(GetSystemButtonPressedColor(g_settings.mediaButtonsHoverEffectMode)); } catch (...) {}
    } else {
        try { g_mediaPressedBrush = SolidColorBrush(GetSystemButtonPressedColor(g_settings.mediaButtonsHoverEffectMode)); } catch (...) {}
    }
    if (g_playerHoverBrush) {
        try { g_playerHoverBrush.Color(GetSystemButtonHoverColor(g_settings.playerHoverEffectMode)); } catch (...) {}
    } else {
        try { g_playerHoverBrush = SolidColorBrush(GetSystemButtonHoverColor(g_settings.playerHoverEffectMode)); } catch (...) {}
    }
    if (g_playerPressedBrush) {
        try { g_playerPressedBrush.Color(GetSystemButtonPressedColor(g_settings.playerHoverEffectMode)); } catch (...) {}
    } else {
        try { g_playerPressedBrush = SolidColorBrush(GetSystemButtonPressedColor(g_settings.playerHoverEffectMode)); } catch (...) {}
    }
    if (g_playerBorderBrush) {
        try { g_playerBorderBrush.Color(GetSystemButtonBorderColor(g_settings.playerHoverEffectMode)); } catch (...) {}
    } else {
        try { g_playerBorderBrush = SolidColorBrush(GetSystemButtonBorderColor(g_settings.playerHoverEffectMode)); } catch (...) {}
    }
    if (g_playerBorderPressedBrush) {
        try { g_playerBorderPressedBrush.Color(GetSystemButtonBorderPressedColor(g_settings.playerHoverEffectMode)); } catch (...) {}
    } else {
        try { g_playerBorderPressedBrush = SolidColorBrush(GetSystemButtonBorderPressedColor(g_settings.playerHoverEffectMode)); } catch (...) {}
    }
}
static Border GetButtonTemplateRoot(Button const& btn) {
    if (!btn) return nullptr;
    try {
        btn.ApplyTemplate();
        if (VisualTreeHelper::GetChildrenCount(btn) > 0) {
            if (auto border = VisualTreeHelper::GetChild(btn, 0).try_as<Border>())
                return border;
        }
        if (auto named = btn.FindName(L"Root")) {
            if (auto border = named.try_as<Border>()) return border;
        }
    } catch (...) {}
    return nullptr;
}

[[clang::no_destroy]] static Style g_fluentMediaButtonStyle = nullptr;
static Style GetFluentMediaButtonStyle() {
    if (!g_fluentMediaButtonStyle) {
        static const wchar_t kStyleXaml[] = LR"(<Style TargetType="Button"
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
<Setter Property="Background" Value="Transparent"/>
<Setter Property="BorderBrush" Value="Transparent"/>
<Setter Property="BorderThickness" Value="0"/>
<Setter Property="UseSystemFocusVisuals" Value="True"/>
<Setter Property="Template">
    <Setter.Value>
    <ControlTemplate TargetType="Button">
        <Border x:Name="Root"
                Background="{TemplateBinding Background}"
                BorderBrush="{TemplateBinding BorderBrush}"
                BorderThickness="{TemplateBinding BorderThickness}"
                CornerRadius="{TemplateBinding CornerRadius}"
                Padding="{TemplateBinding Padding}">
        <Border.BackgroundTransition>
            <BrushTransition Duration="0:0:0.083"/>
        </Border.BackgroundTransition>
        <VisualStateManager.VisualStateGroups>
            <VisualStateGroup x:Name="CommonStates">
            <VisualState x:Name="Normal">
                <VisualState.Setters>
                    <Setter Target="Root.Background" Value="Transparent"/>
                    <Setter Target="Root.BorderBrush" Value="Transparent"/>
                </VisualState.Setters>
            </VisualState>
            <VisualState x:Name="PointerOver">
                <VisualState.Setters>
                    <Setter Target="Root.Background" Value="Transparent"/>
                    <Setter Target="Root.BorderBrush" Value="Transparent"/>
                </VisualState.Setters>
            </VisualState>
            <VisualState x:Name="Pressed">
                <VisualState.Setters>
                    <Setter Target="Root.Background" Value="Transparent"/>
                    <Setter Target="Root.BorderBrush" Value="Transparent"/>
                </VisualState.Setters>
            </VisualState>
            <VisualState x:Name="Disabled">
                <VisualState.Setters>
                    <Setter Target="Root.Background" Value="Transparent"/>
                    <Setter Target="Root.BorderBrush" Value="Transparent"/>
                </VisualState.Setters>
            </VisualState>
            </VisualStateGroup>
        </VisualStateManager.VisualStateGroups>
        <ContentPresenter Content="{TemplateBinding Content}"
                            ContentTransitions="{TemplateBinding ContentTransitions}"
                            ContentTemplate="{TemplateBinding ContentTemplate}"
                            HorizontalContentAlignment="{TemplateBinding HorizontalContentAlignment}"
                            VerticalContentAlignment="{TemplateBinding VerticalContentAlignment}"/>
        </Border>
    </ControlTemplate>
    </Setter.Value>
</Setter>
</Style>)";
        try {
            g_fluentMediaButtonStyle = winrt::Windows::UI::Xaml::Markup::XamlReader::Load(
                winrt::hstring(kStyleXaml)).as<Style>();
        } catch (...) {}
    }
    return g_fluentMediaButtonStyle;
}
static void ApplyFluentMediaButtonStyle(Button const& btn) {
    if (auto style = GetFluentMediaButtonStyle()) {
        btn.Style(style);
    }
}

static VisualState FindCommonState(Border const& root, std::wstring const& stateName) {
    if (!root) return nullptr;
    try {
        auto groups = VisualStateManager::GetVisualStateGroups(root);
        for (auto const& g : groups) {
            if (g.Name() == L"CommonStates") {
                for (auto const& s : g.States()) {
                    if (s.Name() == stateName) return s;
                }
            }
        }
    } catch (...) {}
    return nullptr;
}

static void SetStateBrush(Border const& root, std::wstring const& stateName, uint32_t setterIndex, Brush const& value) {
    if (!root) return;
    try {
        auto state = FindCommonState(root, stateName);
        if (!state) return;
        auto setters = state.Setters();
        if (setterIndex >= setters.Size()) return;
        if (auto setter = setters.GetAt(setterIndex).try_as<Setter>()) {
            setter.Value(value);
        }
    } catch (...) {}
}
static void ApplyHoverTransitionSetting(Border const& root) {
    if (!root) return;
    try {
        if (g_settings.enableHoverAnimation) {
            BrushTransition bt;
            bt.Duration(winrt::Windows::Foundation::TimeSpan(std::chrono::milliseconds(83)));
            root.BackgroundTransition(bt);
        } else {
            root.BackgroundTransition(nullptr);
        }
    } catch (...) {}
}
static void SetupCommonStates(
    Button const& btn,
    Brush const& normalBackground,
    Brush const& pointerOverBackground,
    Brush const& pressedBackground,
    Brush const& disabledBackground,
    Brush const& normalBorderBrush,
    Brush const& pointerOverBorderBrush,
    Brush const& pressedBorderBrush,
    Brush const& disabledBorderBrush)
{
    auto root = GetButtonTemplateRoot(btn);
    if (!root) return;
    ApplyHoverTransitionSetting(root);
    SetStateBrush(root, L"Normal",      0, normalBackground);
    SetStateBrush(root, L"Normal",      1, normalBorderBrush);
    SetStateBrush(root, L"PointerOver", 0, pointerOverBackground);
    SetStateBrush(root, L"PointerOver", 1, pointerOverBorderBrush);
    SetStateBrush(root, L"Pressed",     0, pressedBackground);
    SetStateBrush(root, L"Pressed",     1, pressedBorderBrush);
    SetStateBrush(root, L"Disabled",    0, disabledBackground);
    SetStateBrush(root, L"Disabled",    1, disabledBorderBrush);
    try {
        root.Background(normalBackground);
        root.BorderBrush(normalBorderBrush);
    } catch (...) {}
}
static constexpr int kPlayerShowAnimMs = 220;
static constexpr int kPlayerHideAnimMs = 160;
static constexpr int kArtCrossfadeMs   = 280;
static constexpr int kTextFadeMs       = 200;
static constexpr int kButtonPressMs    = 110;

static CompositeTransform EnsureCompositeTransform(UIElement const& el) {
    if (!el) return nullptr;
    try {
        auto existing = el.RenderTransform().try_as<CompositeTransform>();
        if (existing) return existing;
        CompositeTransform transform;
        el.RenderTransformOrigin({0.5, 0.5});
        el.RenderTransform(transform);
        return transform;
    } catch (...) {}
    return nullptr;
}

static EasingFunctionBase MakeEase(bool easeOut, double exponent = 4.5) {
    ExponentialEase ease;
    ease.Exponent(exponent);
    ease.EasingMode(easeOut ? EasingMode::EaseOut : EasingMode::EaseIn);
    return ease;
}

static void AppendAnim(Storyboard const& sb, DependencyObject const& target,
                       PCWSTR property, double from, double to, int durationMs,
                       bool easeOut, int beginMs = 0) {
    DoubleAnimation anim;
    anim.From(from);
    anim.To(to);
    anim.Duration(DurationHelper::FromTimeSpan(std::chrono::milliseconds(durationMs)));
    if (beginMs > 0) {
        anim.BeginTime(winrt::Windows::Foundation::TimeSpan(std::chrono::milliseconds(beginMs)));
    }
    anim.EasingFunction(MakeEase(easeOut));
    anim.FillBehavior(FillBehavior::Stop);
    Storyboard::SetTarget(anim, target);
    Storyboard::SetTargetProperty(anim, property);
    sb.Children().Append(anim);
}

static void AnimateFade(UIElement const& el, double from, double to, int durationMs,
                        bool easeOut = true, double scaleFrom = 1.0,
                        double scaleTo = 1.0) {
    if (!el) return;
    try {
        bool scaling = (scaleFrom != scaleTo);
        CompositeTransform transform{nullptr};
        if (scaling) {
            transform = EnsureCompositeTransform(el);
            if (transform) {
                transform.ScaleX(scaleTo);
                transform.ScaleY(scaleTo);
            }
        }
        el.Opacity(to);
        Storyboard sb;
        AppendAnim(sb, el, L"Opacity", from, to, durationMs, easeOut);
        if (scaling && transform) {
            AppendAnim(sb, el, L"(UIElement.RenderTransform).(CompositeTransform.ScaleX)",
                       scaleFrom, scaleTo, durationMs, easeOut);
            AppendAnim(sb, el, L"(UIElement.RenderTransform).(CompositeTransform.ScaleY)",
                       scaleFrom, scaleTo, durationMs, easeOut);
        }
        sb.Begin();
    } catch (...) {
        try { el.Opacity(to); } catch (...) {}
    }
}

static void ResetElementScale(UIElement const& el) {
    if (!el) return;
    try {
        if (auto transform = el.RenderTransform().try_as<CompositeTransform>()) {
            transform.ScaleX(1.0);
            transform.ScaleY(1.0);
        }
    } catch (...) {}
}

static void AnimateContentSwap(UIElement const& el, int durationMs,
                               double scaleFrom = 0.97) {
    if (!el) return;
    if (!g_settings.enableSmoothPositionAnimation) {
        ResetElementScale(el);
        return;
    }
    AnimateFade(el, 0.0, 1.0, durationMs, true, scaleFrom, 1.0);
}

static void AnimatePlayerShow(FrameworkElement const& el) {
    if (!el) return;
    if (!g_settings.enableSmoothPositionAnimation) {
        ResetElementScale(el);
        try { el.Opacity(1.0); } catch (...) {}
        return;
    }
    AnimateFade(el, 0.0, 1.0, kPlayerShowAnimMs, true, 0.90, 1.0);
}

static void AnimatePlayerHide(FrameworkElement const& el) {
    if (!el) return;
    if (!g_settings.enableSmoothPositionAnimation) {
        ResetElementScale(el);
        try { el.Opacity(0.0); } catch (...) {}
        return;
    }
    AnimateFade(el, 1.0, 0.0, kPlayerHideAnimMs, false, 1.0, 0.92);
}

static void CollapseAfterHideAnim(FrameworkElement const& el) {
    if (!el) return;
    if (!g_settings.enableSmoothPositionAnimation) {
        try { el.Visibility(Visibility::Collapsed); } catch (...) {}
        return;
    }
    try {
        auto timer = DispatcherTimer();
        timer.Interval(winrt::Windows::Foundation::TimeSpan{
            std::chrono::milliseconds(kPlayerHideAnimMs + 20)});
        auto token = std::make_shared<winrt::event_token>();
        *token = timer.Tick([timer, token, el](
            winrt::Windows::Foundation::IInspectable const&,
            winrt::Windows::Foundation::IInspectable const&) mutable {
            try { timer.Stop(); timer.Tick(*token); } catch (...) {}
            try {
                if (el.Opacity() <= 0.01) el.Visibility(Visibility::Collapsed);
            } catch (...) {}
        });
        timer.Start();
    } catch (...) {
        try { el.Visibility(Visibility::Collapsed); } catch (...) {}
    }
}

static void AnimateButtonPress(UIElement const& el, bool pressed) {
    if (!el) return;
    if (!g_settings.enableHoverAnimation) {
        ResetElementScale(el);
        return;
    }
    try {
        auto transform = EnsureCompositeTransform(el);
        if (!transform) return;
        double from = pressed ? 1.0 : 0.90;
        double to   = pressed ? 0.90 : 1.0;
        if (std::abs(transform.ScaleX() - to) < 0.001) return;
        transform.ScaleX(to);
        transform.ScaleY(to);
        Storyboard sb;
        AppendAnim(sb, el, L"(UIElement.RenderTransform).(CompositeTransform.ScaleX)",
                   from, to, kButtonPressMs, !pressed);
        AppendAnim(sb, el, L"(UIElement.RenderTransform).(CompositeTransform.ScaleY)",
                   from, to, kButtonPressMs, !pressed);
        sb.Begin();
    } catch (...) {}
}

static void GoToCommonState(Button const& btn, bool effectEnabled, bool pressed, bool hovered) {
    if (!btn) return;
    AnimateButtonPress(btn, pressed);
    try {
        winrt::hstring stateName = L"Normal";
        if (effectEnabled) {
            if (pressed)      stateName = L"Pressed";
            else if (hovered) stateName = L"PointerOver";
        }
        if (pressed && g_settings.enableHoverAnimation) {
            if (auto root = GetButtonTemplateRoot(btn)) {
                auto saved = root.BackgroundTransition();
                root.BackgroundTransition(nullptr);
                VisualStateManager::GoToState(btn, stateName, true);
                root.BackgroundTransition(saved);
                return;
            }
        }
        VisualStateManager::GoToState(btn, stateName, true);
    } catch (...) {}
}
static void RunWhenButtonReady(Button const& btn, std::function<void()> const& action) {
    if (!btn || !action) return;
    auto run = std::make_shared<std::function<void()>>(action);
    auto invoke = [btn, run]() {
        try {
            btn.ApplyTemplate();
            (*run)();
        } catch (...) {}
    };
    try {
        if (btn.IsLoaded()) {
            invoke();
        } else {
            auto token = std::make_shared<winrt::event_token>();
            *token = btn.Loaded([btn, invoke, token](auto const&, auto const&) {
                btn.Loaded(*token);
                invoke();
            });
        }
    } catch (...) {
        invoke();
    }
}

static void SetupMediaButtonCommonStates(Button const& btn) {
    auto transparent = MakeBrush({0x00, 0xFF, 0xFF, 0xFF});
    if (!IsHoverEffectEnabled(g_settings.mediaButtonsHoverEffectMode)) {
        SetupCommonStates(
            btn,
            transparent, transparent, transparent, transparent,
            transparent, transparent, transparent, transparent);
        return;
    }
    EnsureHoverBrushes();
    SetupCommonStates(
        btn,
        transparent,
        g_mediaHoverBrush,
        g_mediaPressedBrush,
        transparent,
        transparent, transparent, transparent, transparent);
}
static Brush MakeElevationBorderBrush(std::wstring const& mode) {
    bool light = IsHoverLightTheme(mode);
    winrt::Windows::UI::Color topColor, bottomColor;
    if (light) {
        topColor    = winrt::Windows::UI::Color{0x08, 0x00, 0x00, 0x00};
        bottomColor = winrt::Windows::UI::Color{0x10, 0x00, 0x00, 0x00};
    } else {
        topColor    = winrt::Windows::UI::Color{0x28, 0xFF, 0xFF, 0xFF};
        bottomColor = winrt::Windows::UI::Color{0x0A, 0xFF, 0xFF, 0xFF};
    }
    try {
        winrt::Windows::UI::Xaml::Media::LinearGradientBrush brush;
        brush.StartPoint(winrt::Windows::Foundation::Point(0.5f, 0.0f));
        brush.EndPoint(winrt::Windows::Foundation::Point(0.5f, 1.0f));
        winrt::Windows::UI::Xaml::Media::GradientStop s1, s2;
        s1.Color(topColor);    s1.Offset(0.0);
        s2.Color(bottomColor); s2.Offset(1.0);
        brush.GradientStops().Append(s1);
        brush.GradientStops().Append(s2);
        return brush;
    } catch (...) {
        return MakeBrush(topColor);
    }
}
static void SetupPlayerCommonStates(Button const& btn, Brush const& normalBg) {
    auto transparent = MakeBrush({0x00, 0xFF, 0xFF, 0xFF});
    if (!IsHoverEffectEnabled(g_settings.playerHoverEffectMode)) {
        SetupCommonStates(
            btn,
            normalBg, normalBg, normalBg, normalBg,
            transparent, transparent, transparent, transparent);
        return;
    }
    EnsureHoverBrushes();
    auto elevBorder        = MakeElevationBorderBrush(g_settings.playerHoverEffectMode);
    auto elevBorderPressed = MakeBrush(GetSystemButtonBorderPressedColor(g_settings.playerHoverEffectMode));
    SetupCommonStates(
        btn,
        normalBg,
        g_playerHoverBrush,
        g_playerPressedBrush,
        normalBg,
        transparent,
        elevBorder,
        elevBorderPressed,
        transparent);
}
static void ApplyPlayerButtonState(Button const& btn, Brush const&, bool hovered, bool pressed) {
    if (!btn) return;
    try {
        GoToCommonState(btn, IsHoverEffectEnabled(g_settings.playerHoverEffectMode), pressed, hovered);
    } catch (...) {}
}
static bool DecodeImageToBGRA(const std::vector<BYTE>& imgBytes,
                            std::vector<BYTE>& outPixels,
                            int& outW, int& outH)
{
    if (imgBytes.empty()) return false;
    IWICImagingFactory* pFactory = nullptr;
    if (FAILED(CoCreateInstance(CLSID_WICImagingFactory, nullptr,
                                CLSCTX_INPROC_SERVER,
                                IID_PPV_ARGS(&pFactory))) || !pFactory)
        return false;
    IStream* pStream = SHCreateMemStream(imgBytes.data(), (UINT)imgBytes.size());
    if (!pStream) { pFactory->Release(); return false; }
    bool ok = false;
    IWICBitmapDecoder* pDecoder = nullptr;
    if (SUCCEEDED(pFactory->CreateDecoderFromStream(
            pStream, nullptr, WICDecodeMetadataCacheOnDemand, &pDecoder))) {
        IWICBitmapFrameDecode* pFrame = nullptr;
        if (SUCCEEDED(pDecoder->GetFrame(0, &pFrame))) {
            IWICFormatConverter* pConv = nullptr;
            if (SUCCEEDED(pFactory->CreateFormatConverter(&pConv))) {
                if (SUCCEEDED(pConv->Initialize(
                        pFrame, GUID_WICPixelFormat32bppPBGRA,
                        WICBitmapDitherTypeNone, nullptr, 0.0,
                        WICBitmapPaletteTypeMedianCut))) {
                    UINT w = 0, h = 0;
                    pConv->GetSize(&w, &h);
                    if (w > 0 && h > 0) {
                        outPixels.resize((size_t)w * h * 4);
                        if (SUCCEEDED(pConv->CopyPixels(nullptr, w * 4,
                                (UINT)outPixels.size(), outPixels.data()))) {
                            outW = (int)w; outH = (int)h; ok = true;
                        }
                    }
                }
                pConv->Release();
            }
            pFrame->Release();
        }
        pDecoder->Release();
    }
    pStream->Release();
    pFactory->Release();
    return ok;
}
static void DownsampleBGRA(const std::vector<BYTE>& src, int srcW, int srcH,
                            std::vector<BYTE>& dst, int dstW, int dstH)
{
    dst.resize((size_t)dstW * dstH * 4);
    float xr = (float)srcW / dstW, yr = (float)srcH / dstH;
    for (int dy = 0; dy < dstH; ++dy) {
        for (int dx = 0; dx < dstW; ++dx) {
            float sx = (dx + 0.5f) * xr - 0.5f;
            float sy = (dy + 0.5f) * yr - 0.5f;
            int x0 = (int)sx; if (x0 < 0) x0 = 0;
            int y0 = (int)sy; if (y0 < 0) y0 = 0;
            int x1 = x0 + 1; if (x1 >= srcW) x1 = srcW - 1;
            int y1 = y0 + 1; if (y1 >= srcH) y1 = srcH - 1;
            float fx = sx - (float)x0; if (fx < 0) fx = 0;
            float fy = sy - (float)y0; if (fy < 0) fy = 0;
            const BYTE* p00 = &src[((size_t)y0 * srcW + x0) * 4];
            const BYTE* p10 = &src[((size_t)y0 * srcW + x1) * 4];
            const BYTE* p01 = &src[((size_t)y1 * srcW + x0) * 4];
            const BYTE* p11 = &src[((size_t)y1 * srcW + x1) * 4];
            BYTE* d = &dst[((size_t)dy * dstW + dx) * 4];
            for (int c = 0; c < 4; ++c) {
                float v = p00[c]*(1-fx)*(1-fy) + p10[c]*fx*(1-fy)
                        + p01[c]*(1-fx)*fy     + p11[c]*fx*fy;
                d[c] = (BYTE)(v < 0 ? 0 : v > 255 ? 255 : (int)v);
            }
        }
    }
}
static void ApplyBoxBlurBGRA(std::vector<BYTE>& pixels, int w, int h, int radius)
{
    if (radius < 1 || w < 1 || h < 1) return;
    std::vector<BYTE> temp(pixels.size());
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            int r = 0, g = 0, b = 0, a = 0, count = 0;
            for (int dx = -radius; dx <= radius; ++dx) {
                int sx = x + dx;
                if (sx >= 0 && sx < w) {
                    const BYTE* p = &pixels[((size_t)y * w + sx) * 4];
                    b += p[0]; g += p[1]; r += p[2]; a += p[3];
                    count++;
                }
            }
            BYTE* d = &temp[((size_t)y * w + x) * 4];
            d[0] = (BYTE)(b / count);
            d[1] = (BYTE)(g / count);
            d[2] = (BYTE)(r / count);
            d[3] = (BYTE)(a / count);
        }
    }
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            int r = 0, g = 0, b = 0, a = 0, count = 0;
            for (int dy = -radius; dy <= radius; ++dy) {
                int sy = y + dy;
                if (sy >= 0 && sy < h) {
                    const BYTE* p = &temp[((size_t)sy * w + x) * 4];
                    b += p[0]; g += p[1]; r += p[2]; a += p[3];
                    count++;
                }
            }
            BYTE* d = &pixels[((size_t)y * w + x) * 4];
            d[0] = (BYTE)(b / count);
            d[1] = (BYTE)(g / count);
            d[2] = (BYTE)(r / count);
            d[3] = (BYTE)(a / count);
        }
    }
}
static bool UpdateAlbumBlurBgCache(const std::vector<BYTE>& thumbBytes,
                                    int targetW, int targetH)
{
    if (thumbBytes.empty() || targetW <= 0 || targetH <= 0) {
        g_blurBgCache.Invalidate(); return false;
    }
    size_t artHash = 0;
    for (size_t i = 0; i < thumbBytes.size(); i += 512)
        artHash = artHash * 31 + thumbBytes[i];
    if (g_blurBgCache.artHash == artHash && g_blurBgCache.width == targetW &&
        g_blurBgCache.height == targetH && !g_blurBgCache.blurredPixels.empty())
        return true;
    std::vector<BYTE> srcPixels; int srcW = 0, srcH = 0;
    if (!DecodeImageToBGRA(thumbBytes, srcPixels, srcW, srcH)) return false;
    int blurDiv = 8;
    int smallW = srcW / blurDiv; if (smallW < 1) smallW = 1;
    int smallH = srcH / blurDiv; if (smallH < 1) smallH = 1;
    std::vector<BYTE> small;
    DownsampleBGRA(srcPixels, srcW, srcH, small, smallW, smallH);
    int blurRadius = std::clamp(g_settings.blurRadius, 1, 50);
    for (int i = 0; i < 3; ++i) {
        ApplyBoxBlurBGRA(small, smallW, smallH, blurRadius);
    }
    std::vector<BYTE> blurred;
    DownsampleBGRA(small, smallW, smallH, blurred, targetW, targetH);
    g_blurBgCache.blurredPixels = std::move(blurred);
    g_blurBgCache.width   = targetW;
    g_blurBgCache.height  = targetH;
    g_blurBgCache.artHash = artHash;
    return true;
}
static AlbumPalette ExtractAlbumPalette(const std::vector<BYTE>& thumbBytes) {
    const winrt::Windows::UI::Color fallbackPrimary{255, 18, 18, 18};
    const winrt::Windows::UI::Color fallbackSecondary{255, 45, 45, 45};
    if (thumbBytes.empty())
        return {fallbackPrimary, fallbackSecondary};
    try {
        std::vector<BYTE> pixels;
        int w = 0, h = 0;
        if (!DecodeImageToBGRA(thumbBytes, pixels, w, h) || w <= 0 || h <= 0 ||
            pixels.size() < (size_t)w * h * 4)
            return {fallbackPrimary, fallbackSecondary};
        struct Bucket { uint32_t r=0, g=0, b=0, n=0; };
        Bucket buckets[16][16][16]{};
        for (int y = 0; y < h; y += 4) {
            for (int x = 0; x < w; x += 4) {
                size_t idx = ((size_t)y * w + x) * 4;
                if (idx + 4 > pixels.size()) continue;
                BYTE pb = pixels[idx];
                BYTE pg = pixels[idx + 1];
                BYTE pr = pixels[idx + 2];
                int luma = (pr * 299 + pg * 587 + pb * 114) / 1000;
                if (luma < 24 || luma > 235) continue;
                auto& bk = buckets[pr >> 4][pg >> 4][pb >> 4];
                bk.r += pr; bk.g += pg; bk.b += pb; bk.n++;
            }
        }
        struct Cand { float w; BYTE r, g, b; };
        std::vector<Cand> cands;
        cands.reserve(64);
        for (int R = 0; R < 16; R++)
            for (int G = 0; G < 16; G++)
                for (int B = 0; B < 16; B++) {
                    auto& bk = buckets[R][G][B];
                    if (bk.n < 8) continue;
                    float fr = bk.r / (float)bk.n / 255.f;
                    float fg = bk.g / (float)bk.n / 255.f;
                    float fb = bk.b / (float)bk.n / 255.f;
                    float mx = std::max({fr, fg, fb});
                    float mn = std::min({fr, fg, fb});
                    float sat = mx > 0 ? (mx - mn) / mx : 0;
                    cands.push_back({bk.n * (0.3f + sat),
                                    (BYTE)(fr * 255), (BYTE)(fg * 255), (BYTE)(fb * 255)});
                }
        if (cands.empty())
            return {fallbackPrimary, fallbackSecondary};
        std::sort(cands.begin(), cands.end(),
                [](const Cand& a, const Cand& b){ return a.w > b.w; });
        winrt::Windows::UI::Color primary{255, cands[0].r, cands[0].g, cands[0].b};
        winrt::Windows::UI::Color secondary = primary;
        for (auto& c : cands) {
            int dr = (int)c.r - (int)cands[0].r;
            int dg = (int)c.g - (int)cands[0].g;
            int db = (int)c.b - (int)cands[0].b;
            if (dr*dr + dg*dg + db*db > 3264) {
                secondary = winrt::Windows::UI::Color{255, c.r, c.g, c.b};
                break;
            }
        }
        return {primary, secondary};
    } catch (...) {
        return {fallbackPrimary, fallbackSecondary};
    }
}
static DWORD GetWindowsAccentColor() {
    DWORD color = 0;
    BOOL opaque = FALSE;
    if (SUCCEEDED(DwmGetColorizationColor(&color, &opaque)))
        return 0xFF000000 | (color & 0x00FFFFFF);
    return 0xFF0078D4;
}
static winrt::Windows::UI::Color ParseColorWithSpecialValues(const std::wstring& colorStr, BYTE alpha = 255) {
    int r = 255, g = 255, b = 255;
    size_t pos1 = colorStr.find(L' ');
    size_t pos2 = colorStr.find(L' ', pos1 + 1);
    if (pos1 != std::wstring::npos && pos2 != std::wstring::npos) {
        try {
            r = std::stoi(colorStr.substr(0, pos1));
            g = std::stoi(colorStr.substr(pos1 + 1, pos2 - pos1 - 1));
            b = std::stoi(colorStr.substr(pos2 + 1));
            if (r == -1 && g == -1 && b == -1) {
                DWORD accentColor = GetWindowsAccentColor();
                return winrt::Windows::UI::Color{alpha,
                    (BYTE)((accentColor >> 16) & 0xFF),
                    (BYTE)((accentColor >> 8) & 0xFF),
                    (BYTE)(accentColor & 0xFF)};
            }
            if (r == -2 && g == -2 && b == -2) {
                if (g_cachedPaletteHash == 0) {
                    return winrt::Windows::UI::Color{0, 255, 255, 255};
                }
                return winrt::Windows::UI::Color{alpha,
                    g_cachedAlbumPalette.primary.R,
                    g_cachedAlbumPalette.primary.G,
                    g_cachedAlbumPalette.primary.B};
            }
            r = std::clamp(r, 0, 255);
            g = std::clamp(g, 0, 255);
            b = std::clamp(b, 0, 255);
        } catch (...) {}
    }
    return winrt::Windows::UI::Color{alpha, (BYTE)r, (BYTE)g, (BYTE)b};
}
static winrt::Windows::UI::Color ParseColorWithThemeSupport(const std::wstring& colorStr, BYTE alpha) {
    size_t dollarPos = colorStr.find(L'$');
    if (dollarPos != std::wstring::npos) {
        std::wstring lightColorStr = colorStr.substr(0, dollarPos);
        std::wstring darkColorStr = colorStr.substr(dollarPos + 1);
        lightColorStr.erase(0, lightColorStr.find_first_not_of(L" \t"));
        lightColorStr.erase(lightColorStr.find_last_not_of(L" \t") + 1);
        darkColorStr.erase(0, darkColorStr.find_first_not_of(L" \t"));
        darkColorStr.erase(darkColorStr.find_last_not_of(L" \t") + 1);
        if (IsSystemLightTheme()) {
            return ParseColorWithSpecialValues(lightColorStr, alpha);
        } else {
            return ParseColorWithSpecialValues(darkColorStr, alpha);
        }
    } else {
        return ParseColorWithSpecialValues(colorStr, alpha);
    }
}
static winrt::Windows::UI::Color TextColor() {
    BYTE alpha = (BYTE)((g_settings.titleColorOpacity / 100.0) * 255);
    return ParseColorWithThemeSupport(g_settings.titleColor, alpha);
}
static winrt::Windows::UI::Color ArtistColor() {
    BYTE alpha = (BYTE)((g_settings.artistColorOpacity / 100.0) * 255);
    return ParseColorWithThemeSupport(g_settings.artistColor, alpha);
}
static winrt::Windows::UI::Color ButtonColor() {
    BYTE alpha = (BYTE)((g_settings.buttonColorOpacity / 100.0) * 255);
    return ParseColorWithThemeSupport(g_settings.buttonColor, alpha);
}
static winrt::Windows::UI::Color ContextMenuIconColor() {
    BYTE alpha = (BYTE)((g_settings.contextMenuIconOpacity / 100.0) * 255);
    const std::wstring& clr = g_settings.contextMenuIconColor;
    if (clr.empty()) {
        return ParseColorWithThemeSupport(g_settings.buttonColor, alpha);
    }
    return ParseColorWithThemeSupport(clr, alpha);
}
static const std::wstring& ContextMenuIconStyle() {
    if (g_settings.contextMenuIconStyle == L"as_media_buttons")
        return g_settings.iconStyle;
    return g_settings.contextMenuIconStyle;
}
static Brush MakeAlbumBlurBrush(const std::vector<BYTE>& thumbBytes,
                                int panelW, int panelH)
{
    if (!UpdateAlbumBlurBgCache(thumbBytes, panelW, panelH) ||
        g_blurBgCache.blurredPixels.empty())
        return MakeBrush({0x00, 0x00, 0x00, 0x00});
    try {
        size_t bytesNeeded = (size_t)panelW * panelH * 4;
        WriteableBitmap wb(panelW, panelH);
        auto buf = wb.PixelBuffer();
        auto byteAccess = buf.as<Windows::Storage::Streams::IBufferByteAccess>();
        BYTE* pixels = nullptr;
        byteAccess->Buffer(&pixels);
        if (pixels && g_blurBgCache.blurredPixels.size() >= bytesNeeded)
            memcpy(pixels, g_blurBgCache.blurredPixels.data(), bytesNeeded);
        buf.Length(static_cast<uint32_t>(bytesNeeded));
        wb.Invalidate();
        ImageBrush brush;
        brush.ImageSource(wb);
        brush.Stretch(Stretch::UniformToFill);
        return brush;
    } catch (...) {}
    return MakeBrush({0x00, 0x00, 0x00, 0x00});
}
static bool UsesBackgroundBrush() {
    auto& t = g_settings.backgroundType;
    return t == L"solid" || t == L"gradient" || t == L"acrylic" || t == L"mica" || t == L"mica_alt";
}
static Brush MakeBackgroundBrush() {
    auto& t = g_settings.backgroundType;
    BYTE opacity = (BYTE)((g_settings.solidOpacity / 100.0) * 255);
    auto color1 = ParseColorWithThemeSupport(g_settings.solidColor, opacity);
    auto color2 = ParseColorWithSpecialValues(g_settings.solidColor2, opacity);
    auto gradientColor2 = ParseColorWithSpecialValues(g_settings.gradientColor2, opacity);
    if (t == L"gradient") {
        try {
            winrt::Windows::UI::Xaml::Media::LinearGradientBrush brush;
            double angleRad = (g_settings.gradientAngle % 360) * 3.14159265358979323846 / 180.0;
            double startX = 0.5 - 0.5 * std::cos(angleRad);
            double startY = 0.5 - 0.5 * std::sin(angleRad);
            double endX = 0.5 + 0.5 * std::cos(angleRad);
            double endY = 0.5 + 0.5 * std::sin(angleRad);
            brush.StartPoint(winrt::Windows::Foundation::Point((float)startX, (float)startY));
            brush.EndPoint(winrt::Windows::Foundation::Point((float)endX, (float)endY));
            double balancePoint = std::clamp(g_settings.gradientBalance, 0, 100) / 100.0;
            winrt::Windows::UI::Xaml::Media::GradientStop stop1;
            stop1.Color(color2);
            stop1.Offset(0.0);
            winrt::Windows::UI::Xaml::Media::GradientStop stop2;
            stop2.Color(gradientColor2);
            stop2.Offset(balancePoint);
            winrt::Windows::UI::Xaml::Media::GradientStop stop3;
            stop3.Color(gradientColor2);
            stop3.Offset(1.0);
            brush.GradientStops().Append(stop1);
            brush.GradientStops().Append(stop2);
            brush.GradientStops().Append(stop3);
            return brush;
        } catch (...) {}
    }
    if (t == L"acrylic") {
        try {
            winrt::Windows::UI::Xaml::Media::AcrylicBrush brush;
            brush.BackgroundSource(winrt::Windows::UI::Xaml::Media::AcrylicBackgroundSource::HostBackdrop);
            auto col = winrt::Windows::UI::Color{0xFF, color1.R, color1.G, color1.B};
            brush.TintColor(col);
            brush.TintOpacity(g_settings.acrylicTintOpacity / 100.0);
            brush.FallbackColor(winrt::Windows::UI::Color{0xCC, color1.R, color1.G, color1.B});
            return brush;
        } catch (...) {}
    }
    if (t == L"mica" || t == L"mica_alt") {
        BYTE micaAlpha = (BYTE)((g_settings.micaOpacity / 100.0) * 255);
        auto col = winrt::Windows::UI::Color{micaAlpha, color1.R, color1.G, color1.B};
        return MakeBrush(col);
    }
    if (t == L"solid") {
        return MakeBrush(color1);
    }
    if (t == L"album_art_blur") {
        return MakeBrush({0x00, 0xFF, 0xFF, 0xFF});
    }
    return MakeBrush({0x00, 0xFF, 0xFF, 0xFF});
}
static void ApplyBrushBackground(Border const& b) {
    b.Background(MakeBackgroundBrush());
    b.Visibility(Visibility::Visible);
    b.Opacity(1.0);
}
static FrameworkElement FindChildByName(FrameworkElement const& root, std::wstring_view name, int depth = 32) {
    if (!root || depth == 0) return nullptr;
    int n = VisualTreeHelper::GetChildrenCount(root);
    for (int i = 0; i < n; ++i) {
        auto child = VisualTreeHelper::GetChild(root, i).try_as<FrameworkElement>();
        if (!child) continue;
        if (child.Name() == name) return child;
        if (auto found = FindChildByName(child, name, depth - 1)) return found;
    }
    return nullptr;
}
static void DumpXamlTree(DependencyObject const& node, int depth, int maxDepth) {
    if (!node || depth > maxDepth) return;
    std::wstring indent(depth * 2, L' ');
    auto fe = node.try_as<FrameworkElement>();
    std::wstring name  = fe ? std::wstring(fe.Name()) : L"";
    winrt::hstring typeHstr = winrt::get_class_name(node);
    std::wstring type  = std::wstring(typeHstr);
    auto dot = type.rfind(L'.');
    if (dot != std::wstring::npos) type = type.substr(dot + 1);
    int col = fe ? Grid::GetColumn(fe) : -1;
    if (!name.empty()) Wh_Log(L"%ls[%ls] name='%ls' col=%d", indent.c_str(), type.c_str(), name.c_str(), col);
    else Wh_Log(L"%ls[%ls]", indent.c_str(), type.c_str());
    int n = VisualTreeHelper::GetChildrenCount(node);
    for (int i = 0; i < n; ++i) {
        auto child = VisualTreeHelper::GetChild(node, i);
        if (child) DumpXamlTree(child, depth + 1, maxDepth);
    }
}
static constexpr wchar_t kGridName[]        = L"FluentMediaBar";
static constexpr wchar_t kArtImageName[]    = L"FluentMedia_Art";
static constexpr wchar_t kAppIconImageName[]= L"FluentMedia_AppIcon";
static constexpr wchar_t kTextStackName[]   = L"FluentMedia_TextStack";
static constexpr wchar_t kTitleBlockName[]  = L"FluentMedia_Title";
static constexpr wchar_t kArtistBlockName[] = L"FluentMedia_Artist";
static constexpr wchar_t kPlayBtnName[]     = L"FluentMedia_Play";
static constexpr wchar_t kPrevBtnName[]     = L"FluentMedia_Prev";
static constexpr wchar_t kNextBtnName[]     = L"FluentMedia_Next";
static constexpr wchar_t kRewindBtnName[]   = L"FluentMedia_Rewind";
static constexpr wchar_t kForwardBtnName[]  = L"FluentMedia_Forward";
static constexpr wchar_t kShuffleBtnName[]  = L"FluentMedia_Shuffle";
static constexpr wchar_t kRepeatBtnName[]   = L"FluentMedia_Repeat";
static constexpr wchar_t kSwitchSessionsBtnName[] = L"FluentMedia_SwitchSessions";
static constexpr wchar_t kControlsPanelName[] = L"FluentMedia_Controls";
static constexpr wchar_t kVizContainerName[]  = L"FluentMedia_Visualizer";
static constexpr wchar_t kArtContainerName[]  = L"FluentMedia_ArtContainer";
static constexpr wchar_t kBackgroundName[]    = L"FluentMedia_Background";
static constexpr wchar_t kPauseOverlayName[]  = L"PauseIconOverlay";
static ULONGLONG g_idleSinceTick = 0;
static std::atomic<bool> g_hiddenByIdle{false};
static std::chrono::steady_clock::time_point g_lastMediaTime = std::chrono::steady_clock::now();
static void SwitchMediaSession();
static bool AudioAppIsCurrentSource();
static bool AppAudioGetState(float* outVolume, bool* outMuted);
static bool AppAudioSetVolume(float value);
static bool AppAudioAdjustVolume(float delta);
static bool AppAudioToggleMute();
static std::atomic<int>  g_targetVolumePercent{-1};
static std::atomic<bool> g_targetMuted{false};
static std::atomic<int>       g_pendingVolumePercent{-1};
static std::atomic<bool>      g_volumeWriterActive{false};
static std::atomic<ULONGLONG> g_volumeUserActionTick{0};
static void QueueAppVolume(int percent);
static void SendMediaCommandAsync(int cmd) {
    SpawnTrackedWorker([cmd]() {
        if (g_unloading) return;
        winrt::init_apartment(winrt::apartment_type::multi_threaded);
        try {
            if (cmd == kCmdToggleMute || cmd == kCmdVolumeUp || cmd == kCmdVolumeDown) {
                float step = (float)g_settings.volumeStep / 100.0f;
                if (cmd == kCmdToggleMute)      AppAudioToggleMute();
                else if (cmd == kCmdVolumeUp)   AppAudioAdjustVolume(step);
                else                            AppAudioAdjustVolume(-step);
                DispatchMediaUpdate();
                winrt::uninit_apartment();
                return;
            }
            if (cmd == kCmdPlayPause && AudioAppIsCurrentSource()) {
                AppAudioToggleMute();
                DispatchMediaUpdate();
                winrt::uninit_apartment();
                return;
            }
            GlobalSystemMediaTransportControlsSession session{nullptr};
            { std::lock_guard<std::mutex> lk(g_sessionMtx); session = g_currentSession; }
            if (session) {
                switch (cmd) {
                    case kCmdPrevious: session.TrySkipPreviousAsync().get(); break;
                    case kCmdPlayPause: {
                        auto info = session.GetPlaybackInfo();
                        bool isPlaying = info &&
                            info.PlaybackStatus() == GlobalSystemMediaTransportControlsSessionPlaybackStatus::Playing;
                        if (isPlaying)
                            session.TryPauseAsync().get();
                        else
                            session.TryPlayAsync().get();
                        break;
                    }
                    case kCmdNext: session.TrySkipNextAsync().get(); break;
                    case kCmdStop:
                        try {
                            auto result = session.TryStopAsync().get();
                            if (!result) {
                                session.TryPauseAsync().get();
                                session.TryChangePlaybackPositionAsync(0).get();
                            }
                        } catch (...) {
                            try {
                                session.TryPauseAsync().get();
                                session.TryChangePlaybackPositionAsync(0).get();
                            } catch (...) {
                                Wh_Log(L"SendMediaCommandAsync: Fallback also failed");
                            }
                        }
                        break;
                    case kCmdRewind:
                        try {
                            auto timeline = session.GetTimelineProperties();
                            auto currentPos = timeline.Position();
                            if (auto info = session.GetPlaybackInfo();
                                info && info.PlaybackStatus() == GlobalSystemMediaTransportControlsSessionPlaybackStatus::Playing)
                                currentPos += winrt::clock::now() - timeline.LastUpdatedTime();
                            auto newPos = currentPos - std::chrono::seconds(g_settings.seekStepSeconds);
                            if (newPos.count() < 0) newPos = std::chrono::seconds(0);
                            session.TryChangePlaybackPositionAsync(newPos.count()).get();
                        } catch (...) {}
                        break;
                    case kCmdForward:
                        try {
                            auto timeline = session.GetTimelineProperties();
                            auto currentPos = timeline.Position();
                            if (auto info = session.GetPlaybackInfo();
                                info && info.PlaybackStatus() == GlobalSystemMediaTransportControlsSessionPlaybackStatus::Playing)
                                currentPos += winrt::clock::now() - timeline.LastUpdatedTime();
                            auto endTime = timeline.EndTime();
                            auto newPos = currentPos + std::chrono::seconds(g_settings.seekStepSeconds);
                            if (endTime.count() > 0 && newPos > endTime) newPos = endTime;
                            session.TryChangePlaybackPositionAsync(newPos.count()).get();
                        } catch (...) {}
                        break;
                    case kCmdToggleShuffle:
                        try {
                            bool currentShuffle = g_shuffleEnabled.load();
                            if (session.TryChangeShuffleActiveAsync(!currentShuffle).get()) {
                                g_shuffleEnabled = !currentShuffle;
                                DispatchMediaUpdate();
                            }
                        } catch (...) {}
                        break;
                    case kCmdCycleRepeat:
                        try {
                            RepeatMode current = g_repeatMode.load();
                            winrt::Windows::Media::MediaPlaybackAutoRepeatMode mode;
                            RepeatMode next;
                            switch (current) {
                                case RepeatMode::Off:
                                    mode = winrt::Windows::Media::MediaPlaybackAutoRepeatMode::List;
                                    next = RepeatMode::All;
                                    break;
                                case RepeatMode::All:
                                    mode = winrt::Windows::Media::MediaPlaybackAutoRepeatMode::Track;
                                    next = RepeatMode::One;
                                    break;
                                case RepeatMode::One:
                                default:
                                    mode = winrt::Windows::Media::MediaPlaybackAutoRepeatMode::None;
                                    next = RepeatMode::Off;
                                    break;
                            }
                            if (session.TryChangeAutoRepeatModeAsync(mode).get()) {
                                g_repeatMode = next;
                                DispatchMediaUpdate();
                            }
                        } catch (...) {}
                        break;
                    case kCmdSwitchSession:
                        SwitchMediaSession();
                        break;
                    case kCmdRepeatOff:
                        try {
                            if (session.TryChangeAutoRepeatModeAsync(winrt::Windows::Media::MediaPlaybackAutoRepeatMode::None).get()) {
                                g_repeatMode = RepeatMode::Off;
                                DispatchMediaUpdate();
                            }
                        } catch (...) {}
                        break;
                    case kCmdRepeatAll:
                        try {
                            if (session.TryChangeAutoRepeatModeAsync(winrt::Windows::Media::MediaPlaybackAutoRepeatMode::List).get()) {
                                g_repeatMode = RepeatMode::All;
                                DispatchMediaUpdate();
                            }
                        } catch (...) {}
                        break;
                    case kCmdRepeatOne:
                        try {
                            if (session.TryChangeAutoRepeatModeAsync(winrt::Windows::Media::MediaPlaybackAutoRepeatMode::Track).get()) {
                                g_repeatMode = RepeatMode::One;
                                DispatchMediaUpdate();
                            }
                        } catch (...) {}
                        break;
                }
            }
        } catch (...) {}
        winrt::uninit_apartment();
    });
}
struct TextScrollState {
    double offset    = 0.0;
    double textWidth = 0.0;
    double viewWidth = 0.0;
    bool   forward   = true;
    bool   active    = false;
    bool   pausing   = false;
    int    pauseTick = 0;
};
static TextScrollState g_titleScroll;
static TextScrollState g_artistScroll;
static void OnSessionsChanged();
static void AttachToSession(GlobalSystemMediaTransportControlsSession session);
static void SwitchMediaSession();
static void SwitchMediaSession() {
    GlobalSystemMediaTransportControlsSessionManager mgr{nullptr};
    GlobalSystemMediaTransportControlsSession curSession{nullptr};
    {
        std::lock_guard<std::mutex> lk(g_sessionMtx);
        if (!g_sessionMgr) return;
        mgr = g_sessionMgr;
        curSession = g_currentSession;
    }
    GlobalSystemMediaTransportControlsSession nextSession{nullptr};
    try {
        auto sessions = mgr.GetSessions();
        int count = (int)sessions.Size();
        if (count <= 1) return;
        int currentIndex = -1;
        if (curSession) {
            for (int i = 0; i < count; ++i) {
                if (sessions.GetAt(i) == curSession) {
                    currentIndex = i;
                    break;
                }
            }
        }
        int nextIndex = (currentIndex + 1) % count;
        nextSession = sessions.GetAt(nextIndex);
    } catch (...) { return; }
    if (nextSession) {
        {
            std::lock_guard<std::mutex> lk(g_sessionMtx);
            g_userSwitchedSession = true;
        }
        AttachToSession(nextSession);
    }
}
static std::mutex g_deviceEnumeratorMtx;
static void InitAudioDeviceEnumerator() {
    std::lock_guard<std::mutex> lk(g_deviceEnumeratorMtx);
    if (!g_pDeviceEnumerator) {
        CoCreateInstance(
            XIID_MMDeviceEnumerator, NULL, CLSCTX_INPROC_SERVER,
            XIID_IMMDeviceEnumerator, (LPVOID*)&g_pDeviceEnumerator);
    }
}
static void CleanupAudioDeviceEnumerator() {
    std::lock_guard<std::mutex> lk(g_deviceEnumeratorMtx);
    if (g_pDeviceEnumerator) {
        g_pDeviceEnumerator->Release();
        g_pDeviceEnumerator = nullptr;
    }
}
static void ChangeSystemVolume(bool increase) {
    HWND hShellTrayWnd = FindWindow(L"Shell_TrayWnd", nullptr);
    if (hShellTrayWnd) {
        SHORT appCommand = increase ? APPCOMMAND_VOLUME_UP : APPCOMMAND_VOLUME_DOWN;
        PostMessage(hShellTrayWnd, WM_APPCOMMAND, (WPARAM)hShellTrayWnd,
                    MAKELPARAM(0, appCommand));
    }
}
static std::wstring ToLowerCopy(std::wstring value);
static std::wstring PathFileStem(std::wstring path);
static std::wstring GetProcessImagePath(DWORD pid);
static std::wstring GetWindowAppUserModelId(HWND hWnd);
static void ShowMediaContextMenu(FrameworkElement const& target);
static void ShowMiniPlayerFlyout(FrameworkElement const& target);
static void LaunchConfiguredApp();
[[maybe_unused]]
static void ExecuteMediaAction(const std::wstring& action, FrameworkElement const& sourceElement = nullptr) {
    if (action == L"none") {
        return;
    } else if (action == L"open_context_menu") {
        if (sourceElement) {
            ShowMediaContextMenu(sourceElement);
        }
        return;
    } else if (action == L"open_mini_player") {
        if (sourceElement) {
            ShowMiniPlayerFlyout(sourceElement);
        }
        return;
    } else if (action == L"open_configured_app") {
        LaunchConfiguredApp();
        return;
    } else if (action == L"switch_session") {
        SwitchMediaSession();
    } else if (action == L"toggle_app_mute") {
        SendMediaCommandAsync(kCmdToggleMute);
        return;
    } else if (action == L"app_volume_up") {
        SendMediaCommandAsync(kCmdVolumeUp);
        return;
    } else if (action == L"app_volume_down") {
        SendMediaCommandAsync(kCmdVolumeDown);
        return;
    } else if (action == L"play_pause") {
        SendMediaCommandAsync(kCmdPlayPause);
        DispatchMediaUpdate();
    } else if (action == L"next_track") {
        SendMediaCommandAsync(kCmdNext);
        DispatchMediaUpdate();
    } else if (action == L"prev_track") {
        SendMediaCommandAsync(kCmdPrevious);
        DispatchMediaUpdate();
    } else if (action == L"stop") {
        g_forceSessionRefresh = true;
        SendMediaCommandAsync(kCmdStop);
        DispatchMediaUpdate();
        SpawnTrackedWorker([]() {
            for (DWORD delay : {300, 1200, 2500}) {
                for (DWORD waited = 0; waited < delay; waited += 50) {
                    Sleep(50);
                    if (g_unloading || g_applyingSettings) return;
                }
                g_forceSessionRefresh = true;
                OnSessionsChanged();
            }
        });
    } else if (action == L"rewind") {
        SendMediaCommandAsync(kCmdRewind);
        DispatchMediaUpdate();
    } else if (action == L"forward") {
        SendMediaCommandAsync(kCmdForward);
        DispatchMediaUpdate();
    } else if (action == L"toggle_shuffle") {
        SendMediaCommandAsync(kCmdToggleShuffle);
        DispatchMediaUpdate();
    } else if (action == L"toggle_repeat") {
        SendMediaCommandAsync(kCmdCycleRepeat);
        DispatchMediaUpdate();
} else if (action == L"open_app") {
        SpawnTrackedWorker([]() {
            std::wstring title, appAumid;
            {
                std::lock_guard<std::mutex> lk(g_mediaMtx);
                title = g_media.title;
            }
            {
                GlobalSystemMediaTransportControlsSession sessionCopy{nullptr};
                {
                    std::lock_guard<std::mutex> lk(g_sessionMtx);
                    sessionCopy = g_currentSession;
                }
                if (sessionCopy) {
                    try {
                        appAumid = std::wstring(sessionCopy.SourceAppUserModelId());
                    } catch (...) {}
                }
            }
            struct WindowSearch {
                std::wstring targetTitle;
                std::wstring targetAumid;
                HWND aumidHwnd = nullptr;
                HWND processHwnd = nullptr;
                HWND titleHwnd = nullptr;
            };
            WindowSearch search;
            search.targetTitle = ToLowerCopy(title);
            search.targetAumid = ToLowerCopy(appAumid);
            EnumWindows([](HWND hwnd, LPARAM lParam) CALLBACK -> BOOL {
                if (!IsWindowVisible(hwnd)) return TRUE;
                WINDOWINFO wi{};
                wi.cbSize = sizeof(wi);
                GetWindowInfo(hwnd, &wi);
                if ((wi.dwStyle & WS_CHILD) != 0) return TRUE;
                auto* s = reinterpret_cast<WindowSearch*>(lParam);
                if (!s->aumidHwnd && !s->targetAumid.empty()) {
                    std::wstring winAumid = ToLowerCopy(GetWindowAppUserModelId(hwnd));
                    if (!winAumid.empty() &&
                        (winAumid.find(s->targetAumid) != std::wstring::npos ||
                        s->targetAumid.find(winAumid) != std::wstring::npos)) {
                        s->aumidHwnd = hwnd;
                    }
                }
                if (!s->processHwnd && !s->targetAumid.empty()) {
                    DWORD pid = 0;
                    GetWindowThreadProcessId(hwnd, &pid);
                    std::wstring stem = ToLowerCopy(PathFileStem(GetProcessImagePath(pid)));
                    if (!stem.empty() &&
                        (s->targetAumid.find(stem) != std::wstring::npos ||
                        stem.find(s->targetAumid) != std::wstring::npos)) {
                        s->processHwnd = hwnd;
                    }
                }
                if (!s->titleHwnd && !s->targetTitle.empty()) {
                    wchar_t windowTitle[512];
                    if (GetWindowTextW(hwnd, windowTitle, 512) > 0) {
                        if (ToLowerCopy(windowTitle).find(s->targetTitle) != std::wstring::npos) {
                            s->titleHwnd = hwnd;
                        }
                    }
                }
                return TRUE;
            }, reinterpret_cast<LPARAM>(&search));
            HWND targetWindow = search.aumidHwnd
                ? search.aumidHwnd
                : (search.processHwnd ? search.processHwnd : search.titleHwnd);
            if (targetWindow) {
                if (IsIconic(targetWindow)) {
                    ShowWindow(targetWindow, SW_RESTORE);
                }
                
                HWND hCurWnd = GetForegroundWindow();
                if (hCurWnd && hCurWnd != targetWindow) {
                    DWORD dwMyID = GetCurrentThreadId();
                    DWORD dwCurID = GetWindowThreadProcessId(hCurWnd, NULL);
                    AttachThreadInput(dwCurID, dwMyID, TRUE);
                    SetForegroundWindow(targetWindow);
                    BringWindowToTop(targetWindow);
                    AttachThreadInput(dwCurID, dwMyID, FALSE);
                } else {
                    SetForegroundWindow(targetWindow);
                    BringWindowToTop(targetWindow);
                }
                return;
            }
            if (!appAumid.empty()) {
                std::wstring shellPath = L"shell:AppsFolder\\" + appAumid;
                ShellExecuteW(nullptr, L"open", shellPath.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
            }
        });
    }
}
struct PendingPointerAction {
    winrt::Windows::UI::Xaml::DispatcherTimer timer{nullptr};
    std::wstring action;
    FrameworkElement source{nullptr};
};
static std::shared_ptr<PendingPointerAction> MakePendingPointerAction() {
    auto pending = std::make_shared<PendingPointerAction>();
    pending->timer = winrt::Windows::UI::Xaml::DispatcherTimer();
    std::weak_ptr<PendingPointerAction> weakPending = pending;
    pending->timer.Tick([weakPending](auto const&, auto const&) {
        auto current = weakPending.lock();
        if (!current) return;
        current->timer.Stop();
        auto action = std::move(current->action);
        auto source = current->source;
        current->source = nullptr;
        if (!g_unloading && !action.empty()) {
            ExecuteMediaAction(action, source);
        }
    });
    return pending;
}
static void CancelPendingPointerAction(const std::shared_ptr<PendingPointerAction>& pending) {
    pending->timer.Stop();
    pending->action.clear();
    pending->source = nullptr;
}
static void RunPointerAction(const std::shared_ptr<PendingPointerAction>& pending,
                             const FrameworkElement& source,
                             const std::wstring& singleAction,
                             const std::wstring& doubleAction,
                             bool isDouble,
                             bool allowSingle,
                             bool playerHasDoubleAction = false) {
    bool waitsForDouble = doubleAction != L"none" || playerHasDoubleAction;
    if (isDouble && waitsForDouble) {
        CancelPendingPointerAction(pending);
        ExecuteMediaAction(doubleAction, source);
    } else if (allowSingle && singleAction != L"none") {
        CancelPendingPointerAction(pending);
        if (!waitsForDouble) {
            ExecuteMediaAction(singleAction, source);
            return;
        }
        pending->action = singleAction;
        pending->source = source;
        pending->timer.Interval(winrt::Windows::Foundation::TimeSpan{
            std::chrono::milliseconds(GetDoubleClickTime())});
        pending->timer.Start();
    }
}
static bool HasNamedVisualAncestor(const winrt::Windows::Foundation::IInspectable& source,
                                   const wchar_t* name) {
    auto current = source.try_as<DependencyObject>();
    while (current) {
        if (auto element = current.try_as<FrameworkElement>()) {
            if (element.Name() == name) return true;
        }
        try {
            current = VisualTreeHelper::GetParent(current);
        } catch (...) {
            return false;
        }
    }
    return false;
}
static std::wstring ToLowerCopy(std::wstring value) {
    for (auto& c : value) c = towlower(c);
    return value;
}
static std::wstring PathFileStem(std::wstring path) {
    auto slash = path.find_last_of(L"\\/");
    if (slash != std::wstring::npos) path = path.substr(slash + 1);
    auto dot = path.rfind(L'.');
    if (dot != std::wstring::npos) path = path.substr(0, dot);
    return path;
}
static std::wstring TrimCopy(std::wstring value) {
    const wchar_t* ws = L" \t\r\n";
    size_t first = value.find_first_not_of(ws);
    if (first == std::wstring::npos) return L"";
    size_t last = value.find_last_not_of(ws);
    return value.substr(first, last - first + 1);
}
static bool HasMediaToControl() {
    bool hasSession = false;
    bool hasMedia = false;
    {
        std::lock_guard<std::mutex> lock(g_sessionMtx);
        hasSession = g_currentSession != nullptr;
    }
    {
        std::lock_guard<std::mutex> lock(g_mediaMtx);
        hasMedia = g_media.hasMedia;
    }
    return (hasSession && hasMedia) || AudioAppIsCurrentSource();
}
static void LaunchConfiguredApp() {
    std::wstring command = TrimCopy(g_settings.launchAppCommand);
    if (command.empty()) return;
    SpawnTrackedWorker([command]() {
        std::wstring target = command;
        wchar_t expanded[2048]{};
        if (ExpandEnvironmentStringsW(target.c_str(), expanded, ARRAYSIZE(expanded))) {
            target = expanded;
        }
        auto shellExec = [](const std::wstring& what) -> bool {
            auto result = ShellExecuteW(nullptr, L"open", what.c_str(),
                                       nullptr, nullptr, SW_SHOWNORMAL);
            return reinterpret_cast<INT_PTR>(result) > 32;
        };
        if (shellExec(target)) return;
        bool looksLikePathOrUri = (target.find(L':')  != std::wstring::npos) ||
                                  (target.find(L'\\') != std::wstring::npos);
        if (!looksLikePathOrUri && shellExec(target + L":")) return;
        Wh_Log(L"LaunchConfiguredApp: failed to open '%s'", target.c_str());
    });
}
static bool IsIgnoredMediaApp(const std::wstring& appUserModelId) {
    if (g_settings.ignoredProcessMatchers.empty() || appUserModelId.empty()) return false;
    std::wstring appLower = ToLowerCopy(appUserModelId);
    for (auto const& stem : g_settings.ignoredProcessMatchers)
        if (appLower.find(stem) != std::wstring::npos) return true;
    return false;
}
static bool IsBrowserAumid(const std::wstring& appUserModelId) {
    if (appUserModelId.empty()) return false;
    static const wchar_t* kBrowserSubstrings[] = {
        L"chrome", L"msedge", L"firefox", L"opera", L"brave", L"vivaldi"
    };
    std::wstring lower = ToLowerCopy(appUserModelId);
    for (auto* needle : kBrowserSubstrings) {
        if (lower.find(needle) != std::wstring::npos) return true;
    }
    return false;
}
static std::wstring GetWindowAppUserModelId(HWND hWnd) {
    winrt::com_ptr<IPropertyStore> store;
    if (FAILED(SHGetPropertyStoreForWindow(hWnd, __uuidof(IPropertyStore), store.put_void()))) return {};
    std::wstring result;
    PROPVARIANT pv;
    PropVariantInit(&pv);
    if (SUCCEEDED(store->GetValue(PKEY_AppUserModel_ID, &pv)) && pv.vt == VT_LPWSTR && pv.pwszVal) {
        result = pv.pwszVal;
    }
    PropVariantClear(&pv);
    return result;
}
static bool AppIdMatchesProcess(const std::wstring& appUserModelId, HWND hWnd, DWORD* outPid = nullptr, std::wstring* outProcPath = nullptr) {
    DWORD pid = 0;
    GetWindowThreadProcessId(hWnd, &pid);
    if (outPid) *outPid = pid;
    if (!pid) return false;
    std::wstring windowAumid = GetWindowAppUserModelId(hWnd);
    std::wstring appLower = ToLowerCopy(appUserModelId);
    std::wstring windowAumidLower = ToLowerCopy(windowAumid);
    if (!windowAumidLower.empty() &&
        (appLower.find(windowAumidLower) != std::wstring::npos ||
        windowAumidLower.find(appLower) != std::wstring::npos)) {
        return true;
    }
    wchar_t procPath[MAX_PATH] = {};
    HANDLE hProc = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, pid);
    if (hProc) {
        DWORD sz = MAX_PATH;
        QueryFullProcessImageNameW(hProc, 0, procPath, &sz);
        CloseHandle(hProc);
    }
    if (outProcPath) *outProcPath = procPath;
    std::wstring procLower = ToLowerCopy(PathFileStem(procPath));
    if (procLower.empty()) return false;
    return appLower.find(procLower) != std::wstring::npos ||
        procLower.find(appLower) != std::wstring::npos ||
        procLower.find(ToLowerCopy(PathFileStem(appUserModelId))) != std::wstring::npos ||
        (!windowAumidLower.empty() &&
            (windowAumidLower.find(procLower) != std::wstring::npos ||
            procLower.find(windowAumidLower) != std::wstring::npos));
}
static std::vector<BYTE> RenderIconToBytes(HICON hIcon, int iconSize) {
    if (!hIcon || iconSize <= 0) return {};
    ICONINFO ii{};
    if (!GetIconInfo(hIcon, &ii)) return {};
    BITMAP bm{};
    GetObjectW(ii.hbmColor ? ii.hbmColor : ii.hbmMask, sizeof(bm), &bm);
    if (ii.hbmColor) DeleteObject(ii.hbmColor);
    if (ii.hbmMask)  DeleteObject(ii.hbmMask);
    int srcW = bm.bmWidth  > 0 ? bm.bmWidth  : iconSize;
    int srcH = bm.bmHeight > 0 ? bm.bmHeight : iconSize;
    HDC screenDC = GetDC(nullptr);
    HDC hdc      = CreateCompatibleDC(screenDC);
    HBITMAP hBmp = CreateCompatibleBitmap(screenDC, srcW, srcH);
    ReleaseDC(nullptr, screenDC);
    HBITMAP hOld = (HBITMAP)SelectObject(hdc, hBmp);
    RECT rc{ 0, 0, srcW, srcH };
    HBRUSH hBr = (HBRUSH)GetStockObject(BLACK_BRUSH);
    FillRect(hdc, &rc, hBr);
    DrawIconEx(hdc, 0, 0, hIcon, srcW, srcH, 0, nullptr, DI_NORMAL);
    BITMAPINFO bi{};
    bi.bmiHeader.biSize        = sizeof(BITMAPINFOHEADER);
    bi.bmiHeader.biWidth       = srcW;
    bi.bmiHeader.biHeight      = -srcH;
    bi.bmiHeader.biPlanes      = 1;
    bi.bmiHeader.biBitCount    = 32;
    bi.bmiHeader.biCompression = BI_RGB;
    std::vector<BYTE> src(srcW * srcH * 4, 0);
    SelectObject(hdc, hOld);
    GetDIBits(hdc, hBmp, 0, srcH, src.data(), &bi, DIB_RGB_COLORS);
    DeleteObject(hBmp);
    DeleteDC(hdc);
    if (srcW == iconSize && srcH == iconSize)
        return src;
    std::vector<BYTE> dst(iconSize * iconSize * 4, 0);
    float scaleX = (float)srcW / iconSize;
    float scaleY = (float)srcH / iconSize;
    for (int dy = 0; dy < iconSize; ++dy) {
        for (int dx = 0; dx < iconSize; ++dx) {
            float fx = (dx + 0.5f) * scaleX - 0.5f;
            float fy = (dy + 0.5f) * scaleY - 0.5f;
            int x0 = (int)fx; int y0 = (int)fy;
            int x1 = x0 + 1;  int y1 = y0 + 1;
            x0 = x0 < 0 ? 0 : (x0 > srcW - 1 ? srcW - 1 : x0);
            y0 = y0 < 0 ? 0 : (y0 > srcH - 1 ? srcH - 1 : y0);
            x1 = x1 < 0 ? 0 : (x1 > srcW - 1 ? srcW - 1 : x1);
            y1 = y1 < 0 ? 0 : (y1 > srcH - 1 ? srcH - 1 : y1);
            float wx = fx - (int)fx; float wy = fy - (int)fy;
            int di = (dy * iconSize + dx) * 4;
            for (int c = 0; c < 4; ++c) {
                float v = src[(y0 * srcW + x0) * 4 + c] * (1-wx)*(1-wy)
                        + src[(y0 * srcW + x1) * 4 + c] * wx    *(1-wy)
                        + src[(y1 * srcW + x0) * 4 + c] * (1-wx)* wy
                        + src[(y1 * srcW + x1) * 4 + c] * wx    * wy;
                dst[di + c] = (BYTE)(v + 0.5f);
            }
        }
    }
    return dst;
}
static HICON GetWindowIconNoHang(HWND hWnd) {
    auto getIconTimeout = [hWnd](WPARAM iconType) -> HICON {
        DWORD_PTR res = 0;
        if (SendMessageTimeoutW(hWnd, WM_GETICON, iconType, 0,
                SMTO_ABORTIFHUNG | SMTO_BLOCK, 100, &res)) {
            return (HICON)res;
        }
        return nullptr;
    };
    HICON icon = getIconTimeout(ICON_BIG);
    if (!icon) icon = getIconTimeout(ICON_SMALL);
    if (!icon) icon = (HICON)GetClassLongPtrW(hWnd, GCLP_HICON);
    if (!icon) icon = (HICON)GetClassLongPtrW(hWnd, GCLP_HICONSM);
    return icon;
}
static std::vector<BYTE> FetchAppIconBytes(const std::wstring& appUserModelId, int iconSize) {
    std::vector<BYTE> result;
    if (appUserModelId.empty()) return result;
    auto Render = [&](HICON h, bool own) -> bool {
        if (!h) return false;
        result = RenderIconToBytes(h, iconSize);
        if (own) DestroyIcon(h);
        return !result.empty();
    };
    {
        std::wstring shellPath = L"shell:AppsFolder\\" + appUserModelId;
        PIDLIST_ABSOLUTE pidl = nullptr;
        if (SUCCEEDED(SHParseDisplayName(shellPath.c_str(), nullptr, &pidl, 0, nullptr)) && pidl) {
            SHFILEINFOW sfi{};
            DWORD flags = SHGFI_PIDL | SHGFI_ICON | SHGFI_LARGEICON;
            if (SHGetFileInfoW(reinterpret_cast<LPCWSTR>(pidl), 0, &sfi, sizeof(sfi), flags) && sfi.hIcon) {
                CoTaskMemFree(pidl);
                if (Render(sfi.hIcon, true)) return result;
            } else {
                CoTaskMemFree(pidl);
            }
        }
    }
    auto tryExePath = [&](const std::wstring& path) -> bool {
        if (path.empty()) return false;
        SHFILEINFOW sfi{};
        if (SHGetFileInfoW(path.c_str(), 0, &sfi, sizeof(sfi), SHGFI_ICON | SHGFI_LARGEICON) && sfi.hIcon)
            return Render(sfi.hIcon, true);
        if (SHGetFileInfoW(path.c_str(), 0, &sfi, sizeof(sfi), SHGFI_ICON | SHGFI_SMALLICON) && sfi.hIcon)
            return Render(sfi.hIcon, true);
        return false;
    };
    auto tryExtractIconEx = [&](const std::wstring& path) -> bool {
        if (path.empty()) return false;
        HICON hL = nullptr, hS = nullptr;
        if (ExtractIconExW(path.c_str(), 0, &hL, &hS, 1)) {
            HICON chosen = hL ? hL : hS;
            if (chosen) {
                bool ok = Render(chosen, false);
                if (hL) DestroyIcon(hL);
                if (hS) DestroyIcon(hS);
                if (ok) return true;
            }
        }
        return false;
    };
    struct EnumCtx {
        const std::wstring* aumid;
        std::wstring aumidLower;
        HICON  exactIcon = nullptr;
        HICON  fuzzyIcon = nullptr;
        DWORD  fuzzyPid  = 0;
        std::wstring exactPath;
        std::wstring fuzzyPath;
    };
    EnumCtx ctx{};
    ctx.aumid = &appUserModelId;
    ctx.aumidLower = ToLowerCopy(appUserModelId);
    EnumWindows([](HWND hWnd, LPARAM lParam) CALLBACK -> BOOL {
        if (!IsWindowVisible(hWnd)) return TRUE;
        auto* c = reinterpret_cast<EnumCtx*>(lParam);
        std::wstring windowAumid = GetWindowAppUserModelId(hWnd);
        if (!windowAumid.empty()) {
            if (ToLowerCopy(windowAumid) != c->aumidLower) return TRUE;
            HICON icon = GetWindowIconNoHang(hWnd);
            if (!icon) return TRUE;
            DWORD pid = 0;
            GetWindowThreadProcessId(hWnd, &pid);
            c->exactIcon = icon;
            c->exactPath = GetProcessImagePath(pid);
            return FALSE;
        }
        if (c->fuzzyIcon) return TRUE;
        DWORD pid = 0;
        std::wstring procPath;
        if (AppIdMatchesProcess(*c->aumid, hWnd, &pid, &procPath)) {
            HICON icon = GetWindowIconNoHang(hWnd);
            if (icon) {
                c->fuzzyIcon = icon;
                c->fuzzyPid  = pid;
                c->fuzzyPath = procPath;
            } else if (!c->fuzzyPid) {
                c->fuzzyPid  = pid;
                c->fuzzyPath = procPath;
            }
        }
        return TRUE;
    }, reinterpret_cast<LPARAM>(&ctx));
    if (ctx.exactIcon && Render(ctx.exactIcon, false)) return result;
    if (ctx.fuzzyIcon) {
        HANDLE hProc = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, ctx.fuzzyPid);
        if (hProc) {
            DWORD exitCode = 0;
            if (GetExitCodeProcess(hProc, &exitCode) && exitCode == STILL_ACTIVE) {
                CloseHandle(hProc);
                if (Render(ctx.fuzzyIcon, false)) return result;
            } else {
                CloseHandle(hProc);
            }
        }
    }
    if (tryExePath(ctx.exactPath))        return result;
    if (tryExePath(ctx.fuzzyPath))        return result;
    if (tryExtractIconEx(ctx.exactPath))  return result;
    if (tryExtractIconEx(ctx.fuzzyPath))  return result;
    if (appUserModelId.find(L".exe") != std::wstring::npos) {
        std::wstring exePath = appUserModelId;
        if (exePath.size() >= 2 && exePath.front() == L'"' && exePath.back() == L'"')
            exePath = exePath.substr(1, exePath.size() - 2);
        if (tryExePath(exePath) || tryExtractIconEx(exePath)) return result;
    }
    return result;
}
struct IWhAudioMeter : public IUnknown {
    virtual HRESULT STDMETHODCALLTYPE GetPeakValue(float* peak) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetMeteringChannelCount(UINT* channelCount) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetChannelsPeakValues(UINT32 channelCount, float* peaks) = 0;
    virtual HRESULT STDMETHODCALLTYPE QueryHardwareSupport(DWORD* hardwareSupportMask) = 0;
};
static const GUID kIID_AudioMeterInformation = {
    0xC02216F6, 0x8C67, 0x4B5B, {0x9D, 0x00, 0xD0, 0x08, 0xE7, 0x3E, 0x00, 0x64}
};
struct AudioAppEntry {
    DWORD        pid     = 0;
    std::wstring exeStem;
    std::wstring exePath;
    std::wstring displayName;
    std::wstring detail;
    float        volume  = 1.0f;
    bool         muted   = false;
    float        peak    = 0.0f;
    bool         audible = false;
};
static std::mutex                 g_audioAppMtx;
static AudioAppEntry              g_audioAppCurrent;
static bool                       g_audioAppHasCurrent = false;
static std::vector<BYTE>          g_audioAppIconPng;
static uint64_t                   g_audioAppIconHash = 0;
static std::wstring               g_audioAppIconKey;
static std::map<std::wstring, ULONGLONG> g_audioAppLastAudible;
static constexpr ULONGLONG kAudioAppHoldMs      = 6000;
static constexpr float     kAudioAppPeakFloor   = 0.0008f;
static std::wstring GetProcessImagePath(DWORD pid) {
    if (!pid) return {};
    wchar_t path[MAX_PATH]{};
    HANDLE hProc = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, pid);
    if (!hProc) return {};
    DWORD sz = MAX_PATH;
    if (!QueryFullProcessImageNameW(hProc, 0, path, &sz)) path[0] = L'\0';
    CloseHandle(hProc);
    return path;
}
static std::wstring GetExecutableDescription(const std::wstring& exePath) {
    if (exePath.empty()) return {};
    DWORD dummy = 0;
    DWORD size = GetFileVersionInfoSizeW(exePath.c_str(), &dummy);
    if (!size) return {};
    std::vector<BYTE> buf(size);
    if (!GetFileVersionInfoW(exePath.c_str(), 0, size, buf.data())) return {};
    struct LangAndCodepage { WORD language; WORD codePage; };
    LangAndCodepage* translate = nullptr;
    UINT translateLen = 0;
    if (!VerQueryValueW(buf.data(), L"\\VarFileInfo\\Translation",
                        reinterpret_cast<LPVOID*>(&translate), &translateLen) ||
        !translate || translateLen < sizeof(LangAndCodepage)) {
        return {};
    }
    wchar_t subBlock[64]{};
    wsprintfW(subBlock, L"\\StringFileInfo\\%04x%04x\\FileDescription",
              translate->language, translate->codePage);
    wchar_t* value = nullptr;
    UINT valueLen = 0;
    if (VerQueryValueW(buf.data(), subBlock, reinterpret_cast<LPVOID*>(&value), &valueLen) &&
        value && valueLen > 1) {
        return TrimCopy(std::wstring(value));
    }
    return {};
}
static std::wstring KnownAudioAppName(const std::wstring& exeStemLower) {
    struct KnownApp { const wchar_t* stem; const wchar_t* name; };
    static const KnownApp kKnownApps[] = {
        {L"discord",          L"Discord"},
        {L"discordptb",       L"Discord PTB"},
        {L"discordcanary",    L"Discord Canary"},
        {L"zoom",             L"Zoom"},
        {L"cpthost",          L"Zoom"},
        {L"ms-teams",         L"Microsoft Teams"},
        {L"teams",            L"Microsoft Teams"},
        {L"slack",            L"Slack"},
        {L"skype",            L"Skype"},
        {L"webexhost",        L"Webex"},
        {L"webexmta",         L"Webex"},
        {L"atmgr",            L"Webex"},
        {L"gotomeeting",      L"GoTo Meeting"},
        {L"telegram",         L"Telegram"},
        {L"whatsapp",         L"WhatsApp"},
        {L"signal",           L"Signal"},
        {L"chrome",           L"Google Chrome"},
        {L"msedge",           L"Microsoft Edge"},
        {L"msedgewebview2",   L"Microsoft Edge"},
        {L"firefox",          L"Firefox"},
        {L"librewolf",        L"LibreWolf"},
        {L"zen",              L"Zen Browser"},
        {L"brave",            L"Brave"},
        {L"opera",            L"Opera"},
        {L"opera_gx",         L"Opera GX"},
        {L"vivaldi",          L"Vivaldi"},
        {L"arc",              L"Arc"},
        {L"spotify",          L"Spotify"},
        {L"vlc",              L"VLC"},
        {L"mpv",              L"mpv"},
        {L"foobar2000",       L"foobar2000"},
        {L"aimp",             L"AIMP"},
        {L"itunes",           L"iTunes"},
        {L"applemusic",       L"Apple Music"},
        {L"musicbee",         L"MusicBee"},
        {L"deezer",           L"Deezer"},
        {L"tidal",            L"TIDAL"},
        {L"audacity",         L"Audacity"},
        {L"obs64",            L"OBS Studio"},
        {L"obs32",            L"OBS Studio"},
        {L"steam",            L"Steam"},
        {L"steamwebhelper",   L"Steam"},
        {L"epicgameslauncher", L"Epic Games"},
        {L"parsecd",          L"Parsec"},
        {L"mstsc",            L"Remote Desktop"},
        {L"mpc-hc64",         L"MPC-HC"},
        {L"mpc-be64",         L"MPC-BE"},
        {L"potplayermini64",  L"PotPlayer"},
    };
    for (auto const& app : kKnownApps) {
        if (exeStemLower == app.stem) return app.name;
    }
    return {};
}
static bool IsBrowserExeStem(const std::wstring& exeStemLower) {
    static const wchar_t* kBrowsers[] = {
        L"chrome", L"msedge", L"msedgewebview2", L"firefox", L"librewolf", L"zen",
        L"brave", L"opera", L"opera_gx", L"vivaldi", L"arc", L"chromium", L"thorium",
    };
    for (auto* browser : kBrowsers) {
        if (exeStemLower == browser) return true;
    }
    return false;
}
static std::wstring WebAppNameFromTitle(const std::wstring& titleLower) {
    struct WebApp { const wchar_t* needle; const wchar_t* name; };
    static const WebApp kWebApps[] = {
        {L"google meet",   L"Google Meet"},
        {L"meet.google",   L"Google Meet"},
        {L"meet – ",  L"Google Meet"},
        {L"meet - ",       L"Google Meet"},
        {L"zoom",          L"Zoom"},
        {L"microsoft teams", L"Microsoft Teams"},
        {L"jitsi",         L"Jitsi Meet"},
        {L"whereby",       L"Whereby"},
        {L"webex",         L"Webex"},
        {L"discord",       L"Discord"},
        {L"slack",         L"Slack"},
        {L"youtube music", L"YouTube Music"},
        {L"youtube",       L"YouTube"},
        {L"twitch",        L"Twitch"},
        {L"netflix",       L"Netflix"},
        {L"prime video",   L"Prime Video"},
        {L"disney+",       L"Disney+"},
        {L"hulu",          L"Hulu"},
        {L"crunchyroll",   L"Crunchyroll"},
        {L"hbo max",       L"HBO Max"},
        {L"soundcloud",    L"SoundCloud"},
        {L"bandcamp",      L"Bandcamp"},
        {L"spotify",       L"Spotify"},
        {L"apple music",   L"Apple Music"},
        {L"deezer",        L"Deezer"},
        {L"tidal",         L"TIDAL"},
        {L"plex",          L"Plex"},
        {L"jellyfin",      L"Jellyfin"},
        {L"vimeo",         L"Vimeo"},
        {L"coursera",      L"Coursera"},
        {L"udemy",         L"Udemy"},
    };
    for (auto const& app : kWebApps) {
        size_t len = wcslen(app.needle);
        for (size_t pos = titleLower.find(app.needle); pos != std::wstring::npos;
             pos = titleLower.find(app.needle, pos + 1)) {
            bool startOk = pos == 0 || !iswalnum(app.needle[0]) || !iswalnum(titleLower[pos - 1]);
            bool endOk = pos + len == titleLower.size() || !iswalnum(app.needle[len - 1]) ||
                         !iswalnum(titleLower[pos + len]);
            if (startOk && endOk) return app.name;
        }
    }
    return {};
}
static std::wstring CleanBrowserWindowTitle(const std::wstring& title) {
    std::wstring text = TrimCopy(title);
    static const wchar_t* kSuffixes[] = {
        L" - Google Chrome", L" – Google Chrome",
        L" - Microsoft​ Edge", L" - Microsoft Edge", L" – Microsoft Edge",
        L" — Mozilla Firefox", L" - Mozilla Firefox", L" – Mozilla Firefox",
        L" - Brave", L" - Opera", L" - Opera GX", L" - Vivaldi", L" - Chromium",
        L" - LibreWolf", L" — LibreWolf", L" - Zen Browser", L" - Arc",
    };
    for (auto* suffix : kSuffixes) {
        size_t len = wcslen(suffix);
        if (text.size() > len && text.compare(text.size() - len, len, suffix) == 0) {
            text.erase(text.size() - len);
            break;
        }
    }
    size_t andPos = text.rfind(L" and ");
    if (andPos != std::wstring::npos && text.find(L" more page", andPos) != std::wstring::npos) {
        text.erase(andPos);
    }
    if (!text.empty() && (text[0] == L'(' || text[0] == L'[')) {
        wchar_t close = (text[0] == L'(') ? L')' : L']';
        size_t end = text.find(close);
        if (end != std::wstring::npos && end <= 6) {
            text = TrimCopy(text.substr(end + 1));
        }
    }
    return TrimCopy(text);
}
struct ProcessWindowTitles {
    std::vector<std::wstring> titles;
    std::wstring              foreground;
};
static ProcessWindowTitles CollectWindowTitlesForExe(const std::wstring& exeStemLower) {
    struct EnumCtx {
        const std::wstring*  stem;
        ProcessWindowTitles* out;
        HWND                 foreground;
    };
    ProcessWindowTitles result;
    if (exeStemLower.empty()) return result;
    EnumCtx ctx{ &exeStemLower, &result, GetForegroundWindow() };
    EnumWindows([](HWND hWnd, LPARAM lParam) CALLBACK -> BOOL {
        auto* c = reinterpret_cast<EnumCtx*>(lParam);
        if (!IsWindowVisible(hWnd)) return TRUE;
        if (GetWindow(hWnd, GW_OWNER)) return TRUE;
        int len = GetWindowTextLengthW(hWnd);
        if (len <= 0 || len > 512) return TRUE;
        DWORD pid = 0;
        GetWindowThreadProcessId(hWnd, &pid);
        if (!pid) return TRUE;
        std::wstring stem = ToLowerCopy(PathFileStem(GetProcessImagePath(pid)));
        if (stem != *c->stem) return TRUE;
        std::wstring text(len, L'\0');
        int copied = GetWindowTextW(hWnd, text.data(), len + 1);
        if (copied <= 0) return TRUE;
        text.resize(copied);
        if (hWnd == c->foreground) c->out->foreground = text;
        c->out->titles.push_back(std::move(text));
        return TRUE;
    }, reinterpret_cast<LPARAM>(&ctx));
    return result;
}
static bool RenderIconToStraightBGRA(HICON hIcon, int size, std::vector<BYTE>& out) {
    if (!hIcon || size <= 0) return false;
    HDC screenDC = GetDC(nullptr);
    if (!screenDC) return false;
    HDC memDC = CreateCompatibleDC(screenDC);
    ReleaseDC(nullptr, screenDC);
    if (!memDC) return false;
    BITMAPINFO bi{};
    bi.bmiHeader.biSize        = sizeof(BITMAPINFOHEADER);
    bi.bmiHeader.biWidth       = size;
    bi.bmiHeader.biHeight      = -size;
    bi.bmiHeader.biPlanes      = 1;
    bi.bmiHeader.biBitCount    = 32;
    bi.bmiHeader.biCompression = BI_RGB;
    auto drawOn = [&](COLORREF back, std::vector<BYTE>& pixels) -> bool {
        void* bits = nullptr;
        HBITMAP bmp = CreateDIBSection(memDC, &bi, DIB_RGB_COLORS, &bits, nullptr, 0);
        if (!bmp || !bits) { if (bmp) DeleteObject(bmp); return false; }
        HGDIOBJ old = SelectObject(memDC, bmp);
        RECT rc{0, 0, size, size};
        HBRUSH brush = CreateSolidBrush(back);
        FillRect(memDC, &rc, brush);
        DeleteObject(brush);
        BOOL drawn = DrawIconEx(memDC, 0, 0, hIcon, size, size, 0, nullptr, DI_NORMAL);
        GdiFlush();
        if (drawn) {
            pixels.assign(static_cast<BYTE*>(bits),
                          static_cast<BYTE*>(bits) + (size_t)size * size * 4);
        }
        SelectObject(memDC, old);
        DeleteObject(bmp);
        return drawn != FALSE;
    };
    std::vector<BYTE> onBlack, onWhite;
    bool ok = drawOn(RGB(0, 0, 0), onBlack) && drawOn(RGB(255, 255, 255), onWhite);
    DeleteDC(memDC);
    if (!ok || onBlack.size() != onWhite.size() || onBlack.empty()) return false;
    out.assign(onBlack.size(), 0);
    bool anyVisible = false;
    for (size_t i = 0; i + 3 < onBlack.size(); i += 4) {
        int alpha = 255 - ((int)onWhite[i] - (int)onBlack[i]);
        int alphaG = 255 - ((int)onWhite[i + 1] - (int)onBlack[i + 1]);
        int alphaB = 255 - ((int)onWhite[i + 2] - (int)onBlack[i + 2]);
        alpha = (alpha + alphaG + alphaB) / 3;
        alpha = std::clamp(alpha, 0, 255);
        if (alpha == 0) continue;
        anyVisible = true;
        for (int c = 0; c < 3; ++c) {
            int straight = ((int)onBlack[i + c] * 255) / alpha;
            out[i + c] = (BYTE)std::clamp(straight, 0, 255);
        }
        out[i + 3] = (BYTE)alpha;
    }
    return anyVisible;
}
static std::vector<BYTE> EncodeBGRAToPng(const std::vector<BYTE>& pixels, UINT size) {
    if (pixels.size() < (size_t)size * size * 4) return {};
    winrt::com_ptr<IWICImagingFactory> factory;
    if (FAILED(CoCreateInstance(CLSID_WICImagingFactory, nullptr, CLSCTX_INPROC_SERVER,
                                __uuidof(IWICImagingFactory), factory.put_void()))) {
        return {};
    }
    winrt::com_ptr<IStream> stream;
    if (FAILED(CreateStreamOnHGlobal(nullptr, TRUE, stream.put()))) return {};
    winrt::com_ptr<IWICBitmapEncoder> encoder;
    if (FAILED(factory->CreateEncoder(GUID_ContainerFormatPng, nullptr, encoder.put())) ||
        FAILED(encoder->Initialize(stream.get(), WICBitmapEncoderNoCache))) {
        return {};
    }
    winrt::com_ptr<IWICBitmapFrameEncode> frame;
    winrt::com_ptr<IPropertyBag2> props;
    WICPixelFormatGUID format = GUID_WICPixelFormat32bppBGRA;
    if (FAILED(encoder->CreateNewFrame(frame.put(), props.put())) ||
        FAILED(frame->Initialize(props.get())) ||
        FAILED(frame->SetSize(size, size)) ||
        FAILED(frame->SetPixelFormat(&format)) ||
        FAILED(frame->WritePixels(size, size * 4, (UINT)pixels.size(),
                                  const_cast<BYTE*>(pixels.data()))) ||
        FAILED(frame->Commit()) ||
        FAILED(encoder->Commit())) {
        return {};
    }
    STATSTG stat{};
    HGLOBAL hGlobal = nullptr;
    if (FAILED(stream->Stat(&stat, STATFLAG_NONAME)) ||
        FAILED(GetHGlobalFromStream(stream.get(), &hGlobal))) {
        return {};
    }
    auto* data = static_cast<BYTE*>(GlobalLock(hGlobal));
    if (!data) return {};
    std::vector<BYTE> result(data, data + stat.cbSize.QuadPart);
    GlobalUnlock(hGlobal);
    return result;
}
static HICON LoadLargestExecutableIcon(const std::wstring& exePath, int& outSize) {
    outSize = 32;
    if (exePath.empty()) return nullptr;
    SHFILEINFOW sfi{};
    if (SHGetFileInfoW(exePath.c_str(), 0, &sfi, sizeof(sfi), SHGFI_SYSICONINDEX)) {
        for (int listId : {SHIL_EXTRALARGE, SHIL_LARGE}) {
            winrt::com_ptr<IImageList> imageList;
            HICON icon = nullptr;
            if (FAILED(SHGetImageList(listId, __uuidof(IImageList), imageList.put_void())) ||
                FAILED(imageList->GetIcon(sfi.iIcon, ILD_TRANSPARENT, &icon)) || !icon) {
                continue;
            }
            int cx = 32, cy = 32;
            if (SUCCEEDED(imageList->GetIconSize(&cx, &cy)) && cx > 0) outSize = cx;
            return icon;
        }
    }
    SHFILEINFOW large{};
    if (SHGetFileInfoW(exePath.c_str(), 0, &large, sizeof(large),
                       SHGFI_ICON | SHGFI_LARGEICON) && large.hIcon) {
        return large.hIcon;
    }
    return nullptr;
}
static std::vector<BYTE> FetchExecutableIconPng(const std::wstring& exePath) {
    std::vector<BYTE> result;
    int size = 32;
    HICON icon = LoadLargestExecutableIcon(exePath, size);
    if (!icon) return result;
    if (size > 128) size = 128;
    if (size < 16)  size = 16;
    std::vector<BYTE> pixels;
    if (RenderIconToStraightBGRA(icon, size, pixels)) {
        result = EncodeBGRAToPng(pixels, (UINT)size);
    }
    DestroyIcon(icon);
    return result;
}
static bool IsIgnoredAudioApp(const std::wstring& exeStemLower) {
    if (exeStemLower.empty()) return true;
    if (IsIgnoredMediaApp(exeStemLower)) return true;
    return g_settings.audioAppIgnoredStems.contains(exeStemLower);
}
static void ForEachRenderAudioSession(
    const std::function<void(IAudioSessionControl*, IAudioSessionControl2*)>& fn)
{
    InitAudioDeviceEnumerator();
    std::lock_guard<std::mutex> lk(g_deviceEnumeratorMtx);
    if (!g_pDeviceEnumerator) return;
    winrt::com_ptr<IMMDevice> device;
    if (FAILED(g_pDeviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, device.put())))
        return;
    winrt::com_ptr<IAudioSessionManager2> manager;
    if (FAILED(device->Activate(XIID_IAudioSessionManager2, CLSCTX_ALL, nullptr,
                                manager.put_void()))) {
        return;
    }
    winrt::com_ptr<IAudioSessionEnumerator> sessions;
    if (FAILED(manager->GetSessionEnumerator(sessions.put()))) return;
    int count = 0;
    if (FAILED(sessions->GetCount(&count))) return;
    for (int i = 0; i < count; ++i) {
        winrt::com_ptr<IAudioSessionControl> control;
        if (FAILED(sessions->GetSession(i, control.put()))) continue;
        winrt::com_ptr<IAudioSessionControl2> control2;
        if (FAILED(control->QueryInterface(__uuidof(IAudioSessionControl2), control2.put_void())))
            continue;
        if (control2->IsSystemSoundsSession() == S_OK) continue;
        fn(control.get(), control2.get());
    }
}
static std::vector<AudioAppEntry> EnumerateAudioAppSessions() {
    std::vector<AudioAppEntry> entries;
    const DWORD ownPid = GetCurrentProcessId();
    ForEachRenderAudioSession([&](IAudioSessionControl* control, IAudioSessionControl2* control2) {
        DWORD pid = 0;
        if (FAILED(control2->GetProcessId(&pid)) || !pid || pid == ownPid) return;
        AudioSessionState state = AudioSessionStateInactive;
        if (SUCCEEDED(control->GetState(&state)) && state == AudioSessionStateExpired) return;
        std::wstring exePath = GetProcessImagePath(pid);
        std::wstring exeStem = ToLowerCopy(PathFileStem(exePath));
        if (IsIgnoredAudioApp(exeStem)) return;
        float volume = 1.0f;
        BOOL  muted  = FALSE;
        winrt::com_ptr<ISimpleAudioVolume> simpleVolume;
        if (SUCCEEDED(control->QueryInterface(__uuidof(ISimpleAudioVolume),
                                              simpleVolume.put_void()))) {
            simpleVolume->GetMasterVolume(&volume);
            simpleVolume->GetMute(&muted);
        }
        float peak = 0.0f;
        IWhAudioMeter* meter = nullptr;
        if (SUCCEEDED(control->QueryInterface(kIID_AudioMeterInformation,
                                              reinterpret_cast<void**>(&meter))) && meter) {
            meter->GetPeakValue(&peak);
            meter->Release();
        }
        auto existing = std::find_if(entries.begin(), entries.end(),
            [&](AudioAppEntry const& e) { return e.exeStem == exeStem; });
        if (existing != entries.end()) {
            if (peak > existing->peak) {
                existing->peak   = peak;
                existing->pid    = pid;
                existing->volume = volume;
                existing->muted  = muted != FALSE;
            }
            return;
        }
        AudioAppEntry entry;
        entry.pid     = pid;
        entry.exeStem = exeStem;
        entry.exePath = exePath;
        entry.volume  = volume;
        entry.muted   = muted != FALSE;
        entry.peak    = peak;
        entries.push_back(std::move(entry));
    });
    return entries;
}
static void ResolveAudioAppNames(AudioAppEntry& entry) {
    std::wstring known = KnownAudioAppName(entry.exeStem);
    if (!known.empty()) {
        entry.displayName = known;
    } else {
        entry.displayName = GetExecutableDescription(entry.exePath);
        if (entry.displayName.empty() && !entry.exeStem.empty()) {
            entry.displayName = entry.exeStem;
            entry.displayName[0] = (wchar_t)towupper(entry.displayName[0]);
        }
    }
    if (IsBrowserExeStem(entry.exeStem)) {
        auto titles = CollectWindowTitlesForExe(entry.exeStem);
        std::wstring webAppName, webAppTitle;
        auto consider = [&](const std::wstring& title) {
            if (!webAppName.empty() || title.empty()) return;
            std::wstring name = WebAppNameFromTitle(ToLowerCopy(title));
            if (!name.empty()) {
                webAppName  = name;
                webAppTitle = CleanBrowserWindowTitle(title);
            }
        };
        consider(titles.foreground);
        for (auto const& title : titles.titles) consider(title);
        if (!webAppName.empty()) {
            entry.detail      = (webAppTitle == webAppName) ? entry.displayName : webAppTitle;
            entry.displayName = webAppName;
        } else if (!titles.foreground.empty()) {
            entry.detail = CleanBrowserWindowTitle(titles.foreground);
        }
    }
    if (entry.detail == entry.displayName) entry.detail.clear();
}
static bool AudioAppIsCurrentSource() {
    if (!g_settings.enableAudioApps) return false;
    { std::lock_guard<std::mutex> lk(g_mediaMtx); if (g_media.hasMedia) return false; }
    std::lock_guard<std::mutex> lk(g_audioAppMtx);
    return g_audioAppHasCurrent;
}
static bool GetCurrentAudioApp(AudioAppEntry& out, std::vector<BYTE>* outIconPng = nullptr,
                               uint64_t* outIconHash = nullptr) {
    std::lock_guard<std::mutex> lk(g_audioAppMtx);
    if (!g_audioAppHasCurrent) return false;
    out = g_audioAppCurrent;
    if (outIconPng)  *outIconPng  = g_audioAppIconPng;
    if (outIconHash) *outIconHash = g_audioAppIconHash;
    return true;
}
struct AppVolumeTarget {
    std::set<DWORD> pids;
    std::wstring    exeStem;
    std::wstring    aumid;
    bool empty() const { return pids.empty() && exeStem.empty() && aumid.empty(); }
};
static std::mutex      g_volumeTargetMtx;
static std::wstring    g_volumeTargetKey;
static AppVolumeTarget g_volumeTargetCache;
static ULONGLONG       g_volumeTargetTime = 0;
static constexpr ULONGLONG kVolumeTargetCacheMs = 5000;
static AppVolumeTarget ResolveAppVolumeTarget() {
    AppVolumeTarget target;
    if (AudioAppIsCurrentSource()) {
        AudioAppEntry entry;
        if (GetCurrentAudioApp(entry)) {
            if (entry.pid) target.pids.insert(entry.pid);
            target.exeStem = entry.exeStem;
            return target;
        }
    }
    std::wstring aumid;
    {
        GlobalSystemMediaTransportControlsSession session{nullptr};
        { std::lock_guard<std::mutex> lk(g_sessionMtx); session = g_currentSession; }
        if (session) {
            try { aumid = std::wstring(session.SourceAppUserModelId()); } catch (...) {}
        }
    }
    if (aumid.empty()) return target;
    ULONGLONG now = GetTickCount64();
    {
        std::lock_guard<std::mutex> lk(g_volumeTargetMtx);
        if (g_volumeTargetKey == aumid && now - g_volumeTargetTime < kVolumeTargetCacheMs) {
            return g_volumeTargetCache;
        }
    }
    target.aumid = ToLowerCopy(aumid);
    struct EnumCtx {
        const std::wstring* aumid;
        AppVolumeTarget*    target;
    };
    EnumCtx ctx{ &aumid, &target };
    EnumWindows([](HWND hWnd, LPARAM lParam) CALLBACK -> BOOL {
        if (!IsWindowVisible(hWnd)) return TRUE;
        auto* c = reinterpret_cast<EnumCtx*>(lParam);
        DWORD pid = 0;
        std::wstring procPath;
        if (!AppIdMatchesProcess(*c->aumid, hWnd, &pid, &procPath)) return TRUE;
        if (pid) c->target->pids.insert(pid);
        if (c->target->exeStem.empty()) {
            c->target->exeStem = ToLowerCopy(PathFileStem(procPath));
        }
        return TRUE;
    }, reinterpret_cast<LPARAM>(&ctx));
    if (target.exeStem.empty() && target.aumid.find(L".exe") != std::wstring::npos) {
        target.exeStem = ToLowerCopy(PathFileStem(aumid));
    }
    {
        std::lock_guard<std::mutex> lk(g_volumeTargetMtx);
        g_volumeTargetKey   = aumid;
        g_volumeTargetCache = target;
        g_volumeTargetTime  = now;
    }
    return target;
}
static void ForEachTargetAudioSession(
    const AppVolumeTarget& target,
    const std::function<void(IAudioSessionControl*, ISimpleAudioVolume*)>& fn)
{
    if (target.empty()) return;
    ForEachRenderAudioSession([&](IAudioSessionControl* control, IAudioSessionControl2* control2) {
        bool isMatch = false;
        DWORD pid = 0;
        if (SUCCEEDED(control2->GetProcessId(&pid)) && pid) {
            if (target.pids.count(pid)) {
                isMatch = true;
            } else if (!target.exeStem.empty()) {
                isMatch = (ToLowerCopy(PathFileStem(GetProcessImagePath(pid))) == target.exeStem);
            }
        }
        if (!isMatch && !target.aumid.empty()) {
            LPWSTR sessionId = nullptr;
            if (SUCCEEDED(control2->GetSessionIdentifier(&sessionId)) && sessionId) {
                isMatch = ToLowerCopy(std::wstring(sessionId)).find(target.aumid) !=
                          std::wstring::npos;
                CoTaskMemFree(sessionId);
            }
        }
        if (!isMatch) return;
        winrt::com_ptr<ISimpleAudioVolume> simpleVolume;
        if (FAILED(control->QueryInterface(__uuidof(ISimpleAudioVolume),
                                           simpleVolume.put_void()))) {
            return;
        }
        fn(control, simpleVolume.get());
    });
}
static bool AppAudioGetState(float* outVolume, bool* outMuted) {
    float volume = 0.0f;
    bool  muted  = false;
    bool  found  = false;
    auto target = ResolveAppVolumeTarget();
    ForEachTargetAudioSession(target, [&](IAudioSessionControl*, ISimpleAudioVolume* vol) {
        if (found) return;
        float current = 0.0f;
        BOOL  isMuted = FALSE;
        if (SUCCEEDED(vol->GetMasterVolume(&current))) {
            volume = current;
            vol->GetMute(&isMuted);
            muted = (isMuted != FALSE);
            found = true;
        }
    });
    if (!found) return false;
    if (outVolume) *outVolume = volume;
    if (outMuted)  *outMuted  = muted;
    return true;
}
static bool AppAudioSetVolume(float value) {
    float clamped = std::clamp(value, 0.0f, 1.0f);
    auto target = ResolveAppVolumeTarget();
    bool changed = false;
    ForEachTargetAudioSession(target, [&](IAudioSessionControl*, ISimpleAudioVolume* vol) {
        if (SUCCEEDED(vol->SetMasterVolume(clamped, nullptr))) {
            if (clamped > 0.0f) vol->SetMute(FALSE, nullptr);
            changed = true;
        }
    });
    return changed;
}
static bool AppAudioAdjustVolume(float delta) {
    float current = 0.0f;
    if (!AppAudioGetState(&current, nullptr)) return false;
    return AppAudioSetVolume(current + delta);
}
static bool AppAudioToggleMute() {
    bool muted = false;
    if (!AppAudioGetState(nullptr, &muted)) return false;
    bool newMuted = !muted;
    auto target = ResolveAppVolumeTarget();
    bool changed = false;
    ForEachTargetAudioSession(target, [&](IAudioSessionControl*, ISimpleAudioVolume* vol) {
        if (SUCCEEDED(vol->SetMute(newMuted ? TRUE : FALSE, nullptr))) changed = true;
    });
    return changed;
}
static void QueueAppVolume(int percent) {
    g_volumeUserActionTick.store(GetTickCount64());
    g_pendingVolumePercent.store(std::clamp(percent, 0, 100));
    if (g_volumeWriterActive.exchange(true)) return;
    SpawnTrackedWorker([]() {
        if (g_unloading) { g_volumeWriterActive.store(false); return; }
        winrt::init_apartment(winrt::apartment_type::multi_threaded);
        for (;;) {
            int value = g_pendingVolumePercent.exchange(-1);
            if (value < 0) {
                g_volumeWriterActive.store(false);
                if (g_pendingVolumePercent.load() < 0 ||
                    g_volumeWriterActive.exchange(true)) {
                    break;
                }
                continue;
            }
            AppAudioSetVolume((float)value / 100.0f);
            if (g_unloading) { g_volumeWriterActive.store(false); break; }
            Sleep(25);
        }
        winrt::uninit_apartment();
    });
}
static void PollAudioAppSelection(bool& changed);
static void PollAudioApps() {
    bool changed = false;
    if (g_settings.enableAudioApps) PollAudioAppSelection(changed);
    float volume = 0.0f;
    bool  muted  = false;
    int   percent = -1;
    if (AppAudioGetState(&volume, &muted)) {
        percent = (int)std::lround(std::clamp(volume, 0.0f, 1.0f) * 100.0f);
    }
    if (g_targetVolumePercent.exchange(percent) != percent) changed = true;
    if (g_targetMuted.exchange(muted) != muted) changed = true;
    if (changed) DispatchMediaUpdate();
}
static void PollAudioAppSelection(bool& changed) {
    std::vector<AudioAppEntry> entries = EnumerateAudioAppSessions();
    ULONGLONG now = GetTickCount64();
    std::wstring previousStem;
    {
        std::lock_guard<std::mutex> lk(g_audioAppMtx);
        previousStem = g_audioAppCurrent.exeStem;
        for (auto& entry : entries) {
            if (entry.peak >= kAudioAppPeakFloor && !entry.muted) {
                g_audioAppLastAudible[entry.exeStem] = now;
            }
            auto last = g_audioAppLastAudible.find(entry.exeStem);
            entry.audible = (last != g_audioAppLastAudible.end()) &&
                            (now - last->second <= kAudioAppHoldMs);
        }
        for (auto it = g_audioAppLastAudible.begin(); it != g_audioAppLastAudible.end();) {
            if (now - it->second > kAudioAppHoldMs * 4) {
                it = g_audioAppLastAudible.erase(it);
            } else {
                ++it;
            }
        }
    }
    const AudioAppEntry* best = nullptr;
    for (auto const& entry : entries) {
        if (g_settings.audioAppsRequireSound && !entry.audible) continue;
        if (!best) { best = &entry; continue; }
        if (entry.exeStem == previousStem && entry.peak >= kAudioAppPeakFloor) {
            best = &entry;
            continue;
        }
        if (best->exeStem == previousStem && best->peak >= kAudioAppPeakFloor) continue;
        if (entry.peak > best->peak) best = &entry;
    }
    AudioAppEntry selected;
    bool hasSelected = false;
    if (best) {
        selected = *best;
        ResolveAudioAppNames(selected);
        hasSelected = !selected.displayName.empty();
    }
    std::vector<BYTE> iconPng;
    uint64_t          iconHash = 0;
    if (hasSelected && g_settings.audioAppShowIcon) {
        bool needsIcon = false;
        {
            std::lock_guard<std::mutex> lk(g_audioAppMtx);
            needsIcon = (g_audioAppIconKey != selected.exePath) || g_audioAppIconPng.empty();
            if (!needsIcon) {
                iconPng  = g_audioAppIconPng;
                iconHash = g_audioAppIconHash;
            }
        }
        if (needsIcon) {
            iconPng = FetchExecutableIconPng(selected.exePath);
            for (size_t i = 0; i < iconPng.size(); i += 512) iconHash = iconHash * 31 + iconPng[i];
            iconHash = iconHash * 31 + iconPng.size();
        }
    }
    {
        std::lock_guard<std::mutex> lk(g_audioAppMtx);
        changed = (g_audioAppHasCurrent != hasSelected) ||
                  (g_audioAppCurrent.exeStem     != selected.exeStem) ||
                  (g_audioAppCurrent.displayName != selected.displayName) ||
                  (g_audioAppCurrent.detail      != selected.detail) ||
                  (g_audioAppCurrent.muted       != selected.muted) ||
                  (std::abs(g_audioAppCurrent.volume - selected.volume) > 0.005f);
        g_audioAppHasCurrent = hasSelected;
        g_audioAppCurrent    = selected;
        if (hasSelected && g_settings.audioAppShowIcon) {
            g_audioAppIconKey  = selected.exePath;
            g_audioAppIconPng  = iconPng;
            g_audioAppIconHash = iconHash;
        } else if (!hasSelected) {
            g_audioAppIconKey.clear();
            g_audioAppIconPng.clear();
            g_audioAppIconHash = 0;
        }
    }
}
static HANDLE g_audioAppThread    = nullptr;
static HANDLE g_audioAppStopEvent = nullptr;
static DWORD WINAPI AudioAppThreadProc(void*) {
    try {
        winrt::init_apartment(winrt::apartment_type::multi_threaded);
    } catch (...) {
        return 0;
    }
    while (!g_unloading) {
        if (WaitForSingleObject(g_audioAppStopEvent, 900) == WAIT_OBJECT_0) break;
        if (g_unloading || g_applyingSettings) continue;
        try { PollAudioApps(); } catch (...) {}
    }
    winrt::uninit_apartment();
    return 0;
}
static void StartAudioAppThread() {
    if (g_audioAppThread) return;
    g_audioAppStopEvent = CreateEventW(nullptr, TRUE, FALSE, nullptr);
    if (!g_audioAppStopEvent) return;
    g_audioAppThread = CreateThread(nullptr, 0, AudioAppThreadProc, nullptr, 0, nullptr);
    if (!g_audioAppThread) {
        CloseHandle(g_audioAppStopEvent);
        g_audioAppStopEvent = nullptr;
    }
}
static void StopAudioAppThread() {
    if (g_audioAppStopEvent) SetEvent(g_audioAppStopEvent);
    if (g_audioAppThread) {
        WaitForSingleObject(g_audioAppThread, INFINITE);
        CloseHandle(g_audioAppThread);
        g_audioAppThread = nullptr;
    }
    if (g_audioAppStopEvent) {
        CloseHandle(g_audioAppStopEvent);
        g_audioAppStopEvent = nullptr;
    }
    g_targetVolumePercent.store(-1);
    g_targetMuted.store(false);
    std::lock_guard<std::mutex> lk(g_audioAppMtx);
    g_audioAppHasCurrent = false;
    g_audioAppCurrent = AudioAppEntry{};
    g_audioAppIconPng.clear();
    g_audioAppIconKey.clear();
    g_audioAppIconHash = 0;
    g_audioAppLastAudible.clear();
}
static bool ApplyAudioAppToDisplay(std::wstring& title, std::wstring& artist,
                                   std::vector<BYTE>& thumbBytes, uint64_t& thumbHash,
                                   bool& isPlaying) {
    if (!g_settings.enableAudioApps) return false;
    AudioAppEntry entry;
    std::vector<BYTE> iconPng;
    uint64_t iconHash = 0;
    if (!GetCurrentAudioApp(entry, &iconPng, &iconHash)) return false;
    title  = entry.displayName;
    artist = entry.detail;
    if (!g_settings.audioAppSubtitle.empty()) {
        std::wstring subtitle = g_settings.audioAppSubtitle;
        auto replace = [&subtitle](const wchar_t* token, const std::wstring& value) {
            size_t pos = 0;
            size_t tokenLen = wcslen(token);
            while ((pos = subtitle.find(token, pos)) != std::wstring::npos) {
                subtitle.replace(pos, tokenLen, value);
                pos += value.size();
            }
        };
        replace(L"%app%", entry.displayName);
        replace(L"%volume%", std::to_wstring(
            (int)std::lround(std::clamp(entry.volume, 0.0f, 1.0f) * 100.0f)));
        artist = subtitle;
    }
    if (g_settings.audioAppShowIcon && !iconPng.empty()) {
        thumbBytes = iconPng;
        thumbHash  = iconHash;
    }
    isPlaying = !entry.muted;
    return true;
}
static std::atomic<uint64_t> g_mediaPropsFetchGen{0};
static std::atomic<uint64_t> g_playbackFetchGen{0};
static void FetchMediaPropertiesAsync() {
    SpawnTrackedWorker([gen = ++g_mediaPropsFetchGen]() {
        if (g_unloading) return;
        winrt::init_apartment(winrt::apartment_type::multi_threaded);
        GlobalSystemMediaTransportControlsSession session{nullptr};
        std::wstring aumid;
        {
            std::lock_guard<std::mutex> lk(g_sessionMtx);
            session = g_currentSession;
        }
        if (!session) {
            winrt::uninit_apartment();
            return;
        }
        try {
            aumid = std::wstring(session.SourceAppUserModelId());
        } catch (...) {
            winrt::uninit_apartment();
            return;
        }
        try {
            auto props = session.TryGetMediaPropertiesAsync().get();
            if (!props) {
                winrt::uninit_apartment();
                return;
            }
            std::vector<BYTE> thumbBytes;
            uint64_t          thumbHash = 0;
            uint64_t          thumbStreamSize = 0;
            if (auto thumbRef = props.Thumbnail()) {
                try {
                    auto stream = thumbRef.OpenReadAsync().get();
                    if (stream) {
                        UINT64 sz = stream.Size();
                        thumbStreamSize = sz;
                        if (sz > 0 && sz < 4 * 1024 * 1024) {
                            DataReader reader(stream);
                            reader.LoadAsync((UINT32)sz).get();
                            thumbBytes.resize((size_t)sz);
                            reader.ReadBytes(winrt::array_view<BYTE>(thumbBytes));
                            reader.DetachStream();
                            for (size_t i = 0; i < thumbBytes.size(); i += 1024)
                                thumbHash = thumbHash * 31 + thumbBytes[i];
                        }
                    }
                } catch (...) { thumbBytes.clear(); thumbStreamSize = 0; }
            }

            {
                bool isBrowserSession = IsBrowserAumid(aumid);
                std::wstring titleArtistKey =
                    std::wstring(props.Title()) + L"\x1f" + std::wstring(props.Artist());
                bool suspectMatch = false;
                {
                    std::lock_guard<std::mutex> lk(g_mediaMtx);
                    bool     trackChanged = (titleArtistKey != g_lastTitleArtistKey);
                    uint64_t prevArtSize  = g_media.thumbnailStreamSize;
                    uint64_t prevArtHash  = g_media.thumbnailHash;
                    g_lastTitleArtistKey = titleArtistKey;

                    if (trackChanged) {
                        g_suspectArtSize  = isBrowserSession ? prevArtSize : 0;
                        g_suspectArtHash  = isBrowserSession ? prevArtHash : 0;
                        g_artDelayPending = isBrowserSession && prevArtSize > 0;
                    }

                    if (g_artDelayPending && isBrowserSession) {
                        bool matchesSuspect = thumbStreamSize > 0 &&
                                              thumbStreamSize == g_suspectArtSize &&
                                              (g_suspectArtHash == 0 || thumbHash == g_suspectArtHash);
                        if (matchesSuspect) {
                            suspectMatch = true;
                        } else {
                            g_artDelayPending = false;
                        }
                    }
                }
                if (suspectMatch) {
                    thumbBytes.clear();
                    thumbHash = 0;
                    thumbStreamSize = 0;
                }
            }
            std::vector<BYTE> appIconBytes;
            std::wstring      appIconKey;
            bool forceIconRefresh = false;
            {
                std::lock_guard<std::mutex> lk(g_mediaMtx);
                appIconKey = g_media.appIconKey;
                appIconBytes = g_media.appIconBytes;
            }
            {
                std::lock_guard<std::mutex> lk(g_sessionMtx);
                forceIconRefresh = g_userSwitchedSession;
            }
            if (g_settings.showAppIcon && (aumid != appIconKey || appIconBytes.empty() || forceIconRefresh)) {
                appIconBytes = FetchAppIconBytes(aumid, g_settings.appIconSize);
                appIconKey   = aumid;
            }
            {
                std::lock_guard<std::mutex> lk(g_mediaMtx);
                if (gen != g_mediaPropsFetchGen.load()) {
                    winrt::uninit_apartment();
                    return;
                }
                g_media.title          = std::wstring(props.Title());
                g_media.artist         = std::wstring(props.Artist());
                g_media.hasMedia       = !g_media.title.empty() || !g_media.artist.empty();
                g_media.thumbnailBytes = std::move(thumbBytes);
                g_media.thumbnailHash  = thumbHash;
                g_media.thumbnailStreamSize = thumbStreamSize;
                g_media.appUserModelId = aumid;
                if (g_settings.showAppIcon) {
                    g_media.appIconBytes   = std::move(appIconBytes);
                    g_media.appIconKey     = appIconKey;
                }
            }
            if (forceIconRefresh) {
                std::lock_guard<std::mutex> lk(g_sessionMtx);
                g_userSwitchedSession = false;
            }
        } catch (...) {
        }
        DispatchMediaUpdate();
        winrt::uninit_apartment();
    });
}
static void FetchPlaybackInfoAsync() {
    SpawnTrackedWorker([gen = ++g_playbackFetchGen]() {
        if (g_unloading) return;
        winrt::init_apartment(winrt::apartment_type::multi_threaded);
        GlobalSystemMediaTransportControlsSession session{nullptr};
        { std::lock_guard<std::mutex> lk(g_sessionMtx); session = g_currentSession; }
        if (session) {
            try {
                auto info = session.GetPlaybackInfo();
                if (!info) {
                    winrt::uninit_apartment();
                    return;
                }
                auto status = info.PlaybackStatus();
                bool playing = (status == GlobalSystemMediaTransportControlsSessionPlaybackStatus::Playing);
                bool wasPlaying = false;
                {
                    std::lock_guard<std::mutex> lk(g_mediaMtx);
                    if (gen != g_playbackFetchGen.load()) {
                        winrt::uninit_apartment();
                        return;
                    }
                    wasPlaying = g_media.isPlaying;
                    g_media.isPlaying = playing;
                }
                if (wasPlaying && !playing && !g_unloading) OnSessionsChanged();
                try {
                    auto shuffleRef = info.IsShuffleActive();
                    if (shuffleRef) {
                        g_shuffleEnabled = shuffleRef.Value();
                    }
                } catch (...) {}
                try {
                    auto repeatRef = info.AutoRepeatMode();
                    if (repeatRef) {
                        using RM = winrt::Windows::Media::MediaPlaybackAutoRepeatMode;
                        auto v = repeatRef.Value();
                        if (v == RM::Track) g_repeatMode = RepeatMode::One;
                        else if (v == RM::List) g_repeatMode = RepeatMode::All;
                        else g_repeatMode = RepeatMode::Off;
                    } else {
                        g_repeatMode = RepeatMode::Off;
                    }
                } catch (...) {
                    g_repeatMode = RepeatMode::Off;
                }
                try {
                    auto controls = info.Controls();
                    if (controls) {
                        bool canPrev   = controls.IsPreviousEnabled();
                        bool canNext   = controls.IsNextEnabled();
                        bool canShuf   = controls.IsShuffleEnabled();
                        bool canRep    = controls.IsRepeatEnabled();
                        bool canSeek   = controls.IsPlaybackPositionEnabled();
                        {
                            std::lock_guard<std::mutex> lk(g_mediaMtx);
                            g_media.canSkipPrevious = canPrev;
                            g_media.canSkipNext     = canNext;
                            g_media.canShuffle      = canShuf;
                            g_media.canRepeat       = canRep;
                            g_media.canSeek         = canSeek;
                        }
                    }
                } catch (...) {}
            } catch (...) {
            }
        }
        DispatchMediaUpdate();
        winrt::uninit_apartment();
    });
}
static void DetachCurrentSession() {
    std::lock_guard<std::mutex> lk(g_sessionMtx);
    if (!g_currentSession) return;
    try {
        if (g_evMediaProps.value) { g_currentSession.MediaPropertiesChanged(g_evMediaProps); g_evMediaProps = {}; }
        if (g_evPlayback.value)   { g_currentSession.PlaybackInfoChanged(g_evPlayback); g_evPlayback = {}; }
    } catch (...) {}
    g_currentSession = nullptr;
    g_repeatMode = RepeatMode::Off;
    g_shuffleEnabled = false;
    {
        std::lock_guard<std::mutex> lkm(g_mediaMtx);
        g_media.canSkipPrevious = true;
        g_media.canSkipNext     = true;
        g_media.canShuffle      = true;
        g_media.canRepeat       = true;
        g_media.canSeek         = true;
    }
}
static GlobalSystemMediaTransportControlsSession PickBestSession() {
    GlobalSystemMediaTransportControlsSessionManager mgr{nullptr};
    {
        std::lock_guard<std::mutex> lkMgr(g_sessionMtx);
        mgr = g_sessionMgr;
    }
    if (!mgr) return nullptr;
    try {
        auto sessions = mgr.GetSessions();
        if (sessions.Size() == 0) return nullptr;
        using S = GlobalSystemMediaTransportControlsSessionPlaybackStatus;
        GlobalSystemMediaTransportControlsSession current{nullptr};
        bool userSwitched = false;
        {
            std::lock_guard<std::mutex> lk(g_sessionMtx);
            current      = g_currentSession;
            userSwitched = g_userSwitchedSession;
        }
        GlobalSystemMediaTransportControlsSession playingFirst{nullptr};
        GlobalSystemMediaTransportControlsSession firstValid{nullptr};
        bool currentExists  = false;
        bool currentPlaying = false;
        for (auto const& s : sessions) {
            try {
                if (!s) continue;
                std::wstring appId = s.SourceAppUserModelId().c_str();
                if (IsIgnoredMediaApp(appId)) continue;
                auto pb = s.GetPlaybackInfo();
                if (!pb) continue;
                auto status = pb.PlaybackStatus();
                bool isPlaying = (status == S::Playing);
                if (!firstValid) firstValid = s;
                if (s == current) {
                    currentExists  = true;
                    currentPlaying = isPlaying;
                }
                if (isPlaying && !playingFirst) {
                    playingFirst = s;
                }
            } catch (...) {}
        }
        if (userSwitched) {
            if (currentExists) {
                return current;
            }
            { std::lock_guard<std::mutex> lk(g_sessionMtx); g_userSwitchedSession = false; }
        }
        if (!g_settings.autoSwitchSession) {
            if (currentExists) {
                return current;
            }
            return firstValid;
        }
        if (currentExists && currentPlaying) {
            return current;
        }
        if (playingFirst) {
            return playingFirst;
        }
        if (currentExists) {
            return current;
        }
        return firstValid;
    } catch (...) {
        Wh_Log(L"PickBestSession: Exception occurred");
        return nullptr;
    }
}
static void AttachToSession(GlobalSystemMediaTransportControlsSession session) {
    if (!session) {
        DetachCurrentSession();
        {
            std::lock_guard<std::mutex> lk(g_mediaMtx);
            g_media = MediaState{};
            g_lastTitleArtistKey.clear();
            g_suspectArtSize  = 0;
            g_suspectArtHash  = 0;
            g_artDelayPending = false;
        }
        DispatchMediaUpdate();
        return;
    }
    {
        std::lock_guard<std::mutex> attachLock(g_attachMtx);
        if (g_unloading) return;
        {
            std::lock_guard<std::mutex> lk(g_sessionMtx);
            if (g_currentSession == session && g_evMediaProps.value && g_evPlayback.value) goto fetch;
        }
        DetachCurrentSession();
        {
            std::lock_guard<std::mutex> lk(g_mediaMtx);
            g_media.appIconKey   = L"";
            g_media.appIconBytes.clear();
            g_media.thumbnailBytes.clear();
            g_media.thumbnailHash = 0;
            g_media.thumbnailStreamSize = 0;
            g_lastTitleArtistKey.clear();
            g_suspectArtSize  = 0;
            g_suspectArtHash  = 0;
            g_artDelayPending = false;
        }
        {
            std::lock_guard<std::mutex> lk(g_sessionMtx);
            g_currentSession = session;
            try {
                g_evMediaProps = g_currentSession.MediaPropertiesChanged([](auto const&, auto const&) {
                    if (!g_unloading) FetchMediaPropertiesAsync();
                });
                g_evPlayback = g_currentSession.PlaybackInfoChanged([](auto const&, auto const&) {
                    if (!g_unloading) FetchPlaybackInfoAsync();
                });
            } catch (...) {
                Wh_Log(L"AttachToSession: Failed to attach event handlers");
                g_currentSession = nullptr;
                return;
            }
        }
    }
fetch:
    FetchMediaPropertiesAsync();
    FetchPlaybackInfoAsync();
}
static void OnSessionsChanged() {
    if (g_unloading) return;
    bool forceRefresh = g_forceSessionRefresh.exchange(false);
    try {
        GlobalSystemMediaTransportControlsSessionManager mgr{nullptr};
        {
            std::lock_guard<std::mutex> lk(g_sessionMtx);
            mgr = g_sessionMgr;
        }
        if (mgr) {
            auto sessions = mgr.GetSessions();
            g_sessionCount.store((int)sessions.Size());
        }
    } catch (...) {}
    if (forceRefresh) {
        std::lock_guard<std::mutex> lk(g_sessionMtx);
        g_userSwitchedSession = false;
    }
    try {
        auto newSession = PickBestSession();
        AttachToSession(newSession);
    } catch (...) {
        Wh_Log(L"OnSessionsChanged: Exception occurred");
    }
}
static DWORD WINAPI MediaThreadProc(void*) {
    try {
        winrt::init_apartment(winrt::apartment_type::multi_threaded);
        auto op = GlobalSystemMediaTransportControlsSessionManager::RequestAsync();
        while (op.Status() == winrt::Windows::Foundation::AsyncStatus::Started) {
            if (WaitForSingleObject(g_mediaStopEvent, 50) == WAIT_OBJECT_0) goto done;
        }
        {
            std::lock_guard<std::mutex> lk(g_sessionMtx);
            g_sessionMgr = op.GetResults();
        }
        g_evSessionsChanged = g_sessionMgr.SessionsChanged([](auto const&, auto const&) {
            OnSessionsChanged();
        });
        g_evCurrentChanged  = g_sessionMgr.CurrentSessionChanged([](auto const&, auto const&) {
            OnSessionsChanged();
        });
        OnSessionsChanged();
        if (WaitForSingleObject(g_mediaStopEvent, 2000) == WAIT_TIMEOUT) {
            if (!g_unloading) {
                g_forceSessionRefresh = true;
                OnSessionsChanged();
            }
        }
        WaitForSingleObject(g_mediaStopEvent, INFINITE);
        try { if (g_evSessionsChanged.value) g_sessionMgr.SessionsChanged(g_evSessionsChanged); } catch (...) { Wh_Log(L"MediaThreadProc: Failed to unregister SessionsChanged event"); }
        try { if (g_evCurrentChanged.value)  g_sessionMgr.CurrentSessionChanged(g_evCurrentChanged); } catch (...) { Wh_Log(L"MediaThreadProc: Failed to unregister CurrentSessionChanged event"); }
        {
            std::lock_guard<std::mutex> attachLock(g_attachMtx);
            DetachCurrentSession();
        }
        {
            std::lock_guard<std::mutex> lk(g_sessionMtx);
            g_sessionMgr = nullptr;
        }
    done:
        winrt::uninit_apartment();
    } catch (...) {
        Wh_Log(L"MediaThreadProc: Exception in media thread");
    }
    return 0;
}
static void StartMediaThread() {
    if (g_mediaThread) return;
    g_mediaStopEvent = CreateEventW(nullptr, TRUE, FALSE, nullptr);
    if (!g_mediaStopEvent) return;
    g_mediaThread = CreateThread(nullptr, 0, MediaThreadProc, nullptr, 0, nullptr);
    if (!g_mediaThread) { CloseHandle(g_mediaStopEvent); g_mediaStopEvent = nullptr; }
}
static void StopMediaThread() {
    if (g_mediaStopEvent) SetEvent(g_mediaStopEvent);
    if (g_mediaThread) { WaitForSingleObject(g_mediaThread, INFINITE); CloseHandle(g_mediaThread); g_mediaThread = nullptr; }
    if (g_mediaStopEvent) { CloseHandle(g_mediaStopEvent); g_mediaStopEvent = nullptr; }
}
static HANDLE g_timerThread    = nullptr;
static HANDLE g_timerStopEvent = nullptr;
static HANDLE g_timerUpdateEvent = nullptr;
static constexpr int kTickTimerMs = 16;
struct TickTimer {
    winrt::Windows::UI::Xaml::DispatcherTimer timer{nullptr};
    winrt::event_token token{};
    void (*onTick)(winrt::Windows::Foundation::IInspectable const&, winrt::Windows::Foundation::IInspectable const&);
};
static void StartTickTimer(TickTimer& t) {
    HWND hWnd = g_taskbarWnd;
    if (!hWnd || !IsWindow(hWnd)) return;
    RunFromWindowThread(hWnd, [](void* param) {
        auto& t = *static_cast<TickTimer*>(param);
        try {
            if (!t.timer) {
                t.timer = winrt::Windows::UI::Xaml::DispatcherTimer();
                t.timer.Interval(
                    winrt::Windows::Foundation::TimeSpan{std::chrono::milliseconds(kTickTimerMs)});
                t.token = t.timer.Tick(t.onTick);
            }
            t.timer.Start();
        } catch (...) {}
    }, &t);
}
static void StopTickTimer(TickTimer& t) {
    HWND hWnd = g_taskbarWnd;
    auto stop = [](void* param) {
        auto& t = *static_cast<TickTimer*>(param);
        try {
            if (t.timer) {
                t.timer.Stop();
                if (g_unloading) {
                    if (t.token) {
                        t.timer.Tick(t.token);
                        t.token = {};
                    }
                    t.timer = nullptr;
                }
            }
        } catch (...) {}
    };
    if (hWnd && IsWindow(hWnd)) {
        RunFromWindowThread(hWnd, stop, &t);
    } else {
        stop(&t);
    }
}
static void ScrollTimerTick(winrt::Windows::Foundation::IInspectable const&,
                            winrt::Windows::Foundation::IInspectable const&);
[[clang::no_destroy]] static TickTimer g_scrollTimer{.onTick = &ScrollTimerTick};
static void TickScrollState(TextScrollState& s, int stepPx, int pauseMs, const std::wstring& mode) {
    if (!s.active) return;
    if (s.pausing) {
        s.pauseTick -= kTickTimerMs;
        if (s.pauseTick <= 0) {
            s.pausing = false;
            s.pauseTick = 0;
        }
        return;
    }
    double maxOff = s.textWidth - s.viewWidth + 10.0;
    if (maxOff < 0.0) maxOff = 0.0;
    if (mode == L"loop") {
        s.offset += stepPx;
        if (s.offset >= s.textWidth + g_settings.loopGap) {
            s.offset = 0.0;
        }
    } else {
        if (s.forward) {
            s.offset += stepPx;
            if (s.offset >= maxOff) {
                s.offset = maxOff;
                s.forward = false;
                s.pausing = true;
                s.pauseTick = pauseMs;
            }
        } else {
            s.offset -= stepPx;
            if (s.offset <= 0.0) {
                s.offset = 0.0;
                s.forward = true;
                s.pausing = true;
                s.pauseTick = pauseMs;
            }
        }
    }
}
static void UpdateScrollTransforms();
static bool ScrollTickCurrentInstance() {
    if (!(g_titleScroll.active || g_artistScroll.active)) return false;
    int stepPx = std::max(1, g_settings.scrollSpeed);
    int pauseMs = g_settings.scrollPauseDuration;
    TickScrollState(g_titleScroll, stepPx, pauseMs, g_settings.scrollMode);
    TickScrollState(g_artistScroll, stepPx, pauseMs, g_settings.scrollMode);
    UpdateScrollTransforms();
    return true;
}
static void ScrollTimerTick(winrt::Windows::Foundation::IInspectable const&,
                            winrt::Windows::Foundation::IInspectable const&) {
    if (g_unloading || g_applyingSettings) return;
    bool anyActive = false;
    ForEachPlayerInstance([&anyActive] { anyActive |= ScrollTickCurrentInstance(); });
    if (!anyActive) {
        if (g_scrollTimer.timer) {
            try { g_scrollTimer.timer.Stop(); } catch (...) {}
        }
    }
}
static void ResetScrollState(TextScrollState& s) {
    s.offset    = 0.0;
    s.textWidth = 0.0;
    s.viewWidth = 0.0;
    s.forward   = true;
    s.active    = false;
    if (g_settings.scrollMode == L"loop") {
        s.pausing  = false;
        s.pauseTick = 0;
    } else {
        s.pausing  = true;
        s.pauseTick = g_settings.scrollPauseDuration;
    }
}
static constexpr wchar_t kTitleScrollViewName[]  = L"FluentMedia_TitleScrollView";
static constexpr wchar_t kArtistScrollViewName[] = L"FluentMedia_ArtistScrollView";
static constexpr wchar_t kTitleCloneName[]       = L"FluentMedia_TitleClone";
static constexpr wchar_t kArtistCloneName[]      = L"FluentMedia_ArtistClone";
static constexpr wchar_t kPanelGridName[]        = L"FluentMedia_PanelGrid";
static double GetAvailableScrollTextAreaWidth() {
    try {
        if (g_settings.playerMaxWidth <= 0) return 0.0;
        if (!g_playerGrid) return 0.0;
        auto panelFe = FindChildByName(g_playerGrid, kPanelGridName);
        if (!panelFe) return 0.0;
        auto panelGrid = panelFe.try_as<Grid>();
        if (!panelGrid) return 0.0;
        double total = panelGrid.ActualWidth();
        if (total <= 0.0) return 0.0;
        auto cols = panelGrid.ColumnDefinitions();
        double used = 0.0;
        for (uint32_t i = 0; i < cols.Size(); i++) {
            if (i == 1) continue;
            used += cols.GetAt(i).ActualWidth();
        }
        return std::max(0.0, total - used - g_settings.textAreaLeftMargin - g_settings.textAreaRightMargin);
    } catch (...) {
        return 0.0;
    }
}
static void ApplyScrollOffset(const wchar_t* viewName, const wchar_t* blockName,
                              const wchar_t* cloneName, const TextScrollState& s, bool isLoop) {
    try {
        if (auto fe = FindChildByName(g_playerGrid, viewName)) {
            if (auto cv = fe.try_as<Canvas>()) {
                int n = VisualTreeHelper::GetChildrenCount(cv);
                for (int i = 0; i < n; i++) {
                    auto child = VisualTreeHelper::GetChild(cv, i);
                    if (auto tb = child.try_as<TextBlock>()) {
                        auto name = tb.Name();
                        if (name == blockName) {
                            Canvas::SetLeft(tb, -s.offset);
                        } else if (isLoop && name == cloneName) {
                            Canvas::SetLeft(tb, s.textWidth + g_settings.loopGap - s.offset);
                        }
                    }
                }
            }
        }
    } catch (...) {}
}
static void UpdateScrollTransforms() {
    if (!g_playerGrid) return;
    bool isLoop = (g_settings.scrollMode == L"loop");
    if (g_settings.enableTitleScrolling)
        ApplyScrollOffset(kTitleScrollViewName, kTitleBlockName, kTitleCloneName, g_titleScroll, isLoop);
    if (g_settings.enableArtistScrolling)
        ApplyScrollOffset(kArtistScrollViewName, kArtistBlockName, kArtistCloneName, g_artistScroll, isLoop);
}
static void DispatchMediaUpdate() {
    if (g_unloading || g_applyingSettings) return;
    g_needsUiUpdate = true;
    if (g_timerUpdateEvent) {
        SetEvent(g_timerUpdateEvent);
    }

    HWND tw = g_taskbarWnd;
    if (g_miniPlayerFlyoutOpen && tw) {
        if (!g_settings.hideMediaSessionsList)
            FetchMiniSessionInfosAsync(tw);
        RunFromWindowThread(tw, [](void*) {
            if (g_miniPlayerFlyoutOpen) RefreshMiniPlayerFlyoutUI();
        }, nullptr);
    }
}
static void RefreshPlayerContents();
static void RefreshPlayerContentsInstance();
static void UpdateVisibility();
static void RefreshThemeColors();
static std::atomic<bool> g_themeChangePending{false};
static DWORD WINAPI TimerThreadProc(void*) {
    static bool lastThemeWasLight = IsSystemLightTheme();
    HKEY hKey = nullptr;
    HANDLE hEvent = CreateEventW(nullptr, FALSE, FALSE, nullptr);
    if (RegOpenKeyExW(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize", 0, KEY_NOTIFY, &hKey) == ERROR_SUCCESS) {
        RegNotifyChangeKeyValue(hKey, FALSE, REG_NOTIFY_CHANGE_LAST_SET, hEvent, TRUE);
    }
    while (!g_unloading) {
        HANDLE handles[] = {g_timerStopEvent, hEvent, g_timerUpdateEvent};
        DWORD wait = WaitForMultipleObjects(3, handles, FALSE, 500);
        if (wait == WAIT_OBJECT_0) break;
        if (wait == WAIT_OBJECT_0 + 1) {
            if (hKey) {
                RegNotifyChangeKeyValue(hKey, FALSE, REG_NOTIFY_CHANGE_LAST_SET, hEvent, TRUE);
            }
            {
                bool currentThemeIsLight = IsSystemLightTheme();
                if (currentThemeIsLight != lastThemeWasLight) {
                    lastThemeWasLight = currentThemeIsLight;
                    g_themeChangePending = true;
                    g_needsUiUpdate = true;
                }
            }
        }
        if (g_applyingSettings) continue;
        HWND hWnd = g_taskbarWnd;
        if (!hWnd || !IsWindow(hWnd)) {
            hWnd = FindCurrentProcessTaskbarWnd();
            g_taskbarWnd = hWnd;
            if (!hWnd) continue;
        }
        if (g_themeChangePending.exchange(false)) {
            Sleep(150);
            if (!g_unloading && !g_applyingSettings) {
                RunFromWindowThread(hWnd, [](void*) {
                    if (!g_unloading && !g_applyingSettings && PlayerInstanceCount() > 0) {
                        RefreshThemeColors();
                    }
                }, nullptr);
            }
        }
        bool needsUpdate = g_needsUiUpdate.exchange(false);
        if (g_settings.idleHideSeconds > 0) {
            bool playing = false;
            { std::lock_guard<std::mutex> lk(g_mediaMtx); playing = g_media.isPlaying; }
            if (!playing && AudioAppIsCurrentSource()) {
                AudioAppEntry app;
                playing = GetCurrentAudioApp(app) && app.audible && !app.muted;
            }
            if (playing) {
                g_idleSinceTick = 0;
                if (g_hiddenByIdle) {
                    g_hiddenByIdle = false;
                    needsUpdate = true;
                }
            } else {
                ULONGLONG now = GetTickCount64();
                if (!g_idleSinceTick) g_idleSinceTick = now;
                if (!g_hiddenByIdle &&
                    now - g_idleSinceTick >= (ULONGLONG)g_settings.idleHideSeconds * 1000) {
                    g_hiddenByIdle = true;
                    needsUpdate = true;
                }
            }
        } else {
            if (g_hiddenByIdle) {
                g_hiddenByIdle = false;
                g_idleSinceTick = 0;
                needsUpdate = true;
            }
        }
        if (needsUpdate) {
            RunFromWindowThread(hWnd, [](void*) {
                if (g_unloading || g_applyingSettings) return;
                if (PlayerInstanceCount() > 0) {
                    RefreshPlayerContents();
                    UpdateVisibility();
                }
            }, nullptr);
        }
    }
    if (hKey) RegCloseKey(hKey);
    if (hEvent) CloseHandle(hEvent);
    return 0;
}
static constexpr int VIZ_BARS_MAX = 20;
static constexpr int VIZ_FFT_SIZE = 1024;
static constexpr int VIZ_NUM_BANDS = 7;
static constexpr float VIZ_PI = 3.14159265f;
static std::atomic<float> g_VizBands[VIZ_NUM_BANDS] = {};
static std::atomic<bool> g_CaptureRunning{false};
static std::atomic<bool> g_vizCurrentlyVisible{false};
[[clang::no_destroy]] static std::optional<std::thread> g_CaptureThread;
static HANDLE g_hCaptureEvent = nullptr;
static std::atomic<bool> g_VizDeviceChanged{false};
static std::mutex g_captureThreadMtx;
class VizEndpointNotificationClient : public IMMNotificationClient {
public:
    virtual ~VizEndpointNotificationClient() = default;
    ULONG STDMETHODCALLTYPE AddRef() override {
        return InterlockedIncrement(&m_ref);
    }
    ULONG STDMETHODCALLTYPE Release() override {
        ULONG ref = InterlockedDecrement(&m_ref);
        if (ref == 0)
            delete this;
        return ref;
    }
    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppv) override {
        if (riid == __uuidof(IUnknown) || riid == __uuidof(IMMNotificationClient)) {
            *ppv = static_cast<IMMNotificationClient*>(this);
            AddRef();
            return S_OK;
        }
        *ppv = nullptr;
        return E_NOINTERFACE;
    }
    HRESULT STDMETHODCALLTYPE OnDefaultDeviceChanged(EDataFlow flow, ERole,
                                                    LPCWSTR) override {
        if (flow == eRender)
            g_VizDeviceChanged.store(true, std::memory_order_relaxed);
        return S_OK;
    }
    HRESULT STDMETHODCALLTYPE OnDeviceAdded(LPCWSTR) override {
        g_VizDeviceChanged.store(true, std::memory_order_relaxed);
        return S_OK;
    }
    HRESULT STDMETHODCALLTYPE OnDeviceRemoved(LPCWSTR) override {
        g_VizDeviceChanged.store(true, std::memory_order_relaxed);
        return S_OK;
    }
    HRESULT STDMETHODCALLTYPE OnDeviceStateChanged(LPCWSTR, DWORD) override {
        g_VizDeviceChanged.store(true, std::memory_order_relaxed);
        return S_OK;
    }
    HRESULT STDMETHODCALLTYPE OnPropertyValueChanged(LPCWSTR,
                                                    const PROPERTYKEY) override {
        return S_OK;
    }
private:
    LONG m_ref = 1;
};
static float g_HannWindow[VIZ_FFT_SIZE] = {};
static float g_TwiddleRe[VIZ_FFT_SIZE / 2] = {};
static float g_TwiddleIm[VIZ_FFT_SIZE / 2] = {};
static int g_LogBinStart[VIZ_NUM_BANDS + 1] = {};
static void BuildHannWindow() {
    for (int i = 0; i < VIZ_FFT_SIZE; i++)
        g_HannWindow[i] = 0.5f * (1.f - cosf(2.f * VIZ_PI * i / (VIZ_FFT_SIZE - 1)));
}
static void BuildTwiddleFactors() {
    for (int i = 0; i < VIZ_FFT_SIZE / 2; i++) {
        float ang = -2.0f * VIZ_PI * i / VIZ_FFT_SIZE;
        g_TwiddleRe[i] = cosf(ang);
        g_TwiddleIm[i] = sinf(ang);
    }
}
static void BuildLogBins(UINT32 sampleRate) {
    static constexpr float FREQ_EDGES[VIZ_NUM_BANDS + 1] = {
        20.f, 120.f, 300.f, 800.f, 2500.f, 6000.f, 14000.f, 20000.f};
    for (int b = 0; b <= VIZ_NUM_BANDS; b++) {
        int bin = (int)(FREQ_EDGES[b] * VIZ_FFT_SIZE / (float)sampleRate);
        g_LogBinStart[b] = std::max(1, std::min(VIZ_FFT_SIZE / 2 - 1, bin));
    }
}
static void VizFFT(std::vector<float>& re, std::vector<float>& im) {
    int n = (int)re.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j) {
            std::swap(re[i], re[j]);
            std::swap(im[i], im[j]);
        }
    }
    for (int len = 2; len <= n; len <<= 1) {
        int halfLen = len / 2;
        int stride = n / len;
        for (int i = 0; i < n; i += len) {
            for (int j = 0; j < halfLen; j++) {
                float wRe = g_TwiddleRe[j * stride];
                float wIm = g_TwiddleIm[j * stride];
                float uRe = re[i + j], uIm = im[i + j];
                float vRe = re[i + j + halfLen] * wRe - im[i + j + halfLen] * wIm;
                float vIm = re[i + j + halfLen] * wIm + im[i + j + halfLen] * wRe;
                re[i + j] = uRe + vRe;
                im[i + j] = uIm + vIm;
                re[i + j + halfLen] = uRe - vRe;
                im[i + j + halfLen] = uIm - vIm;
            }
        }
    }
}
struct VizEQMul { float low, mid, high; };
static VizEQMul GetVizEQMultipliers(VizEQ eq) {
    switch (eq) {
    case VizEQ::Bass: return {2.0f, 0.6f, 0.4f};
    case VizEQ::Rock: return {1.3f, 1.5f, 1.2f};
    case VizEQ::Pop: return {0.8f, 1.2f, 1.8f};
    case VizEQ::Jazz: return {1.1f, 0.8f, 0.6f};
    case VizEQ::Electronic: return {1.7f, 0.6f, 1.7f};
    default: return {1.0f, 1.0f, 1.0f};
    }
}
static bool VizInitAudioClient(IMMDeviceEnumerator* pEnum,
                                winrt::com_ptr<IAudioClient>& pClient,
                                winrt::com_ptr<IAudioCaptureClient>& pCapture,
                                UINT32& sampleRate, UINT32& channels,
                                bool& isFloat, HANDLE hEvent) {
    pClient = nullptr;
    pCapture = nullptr;
    winrt::com_ptr<IMMDevice> pDev;
    if (FAILED(pEnum->GetDefaultAudioEndpoint(eRender, eConsole, pDev.put())))
        return false;
    winrt::com_ptr<IAudioClient> pC;
    if (FAILED(pDev->Activate(__uuidof(IAudioClient), CLSCTX_ALL, nullptr,
                            pC.put_void())))
        return false;
    WAVEFORMATEX* pwfx = nullptr;
    pC->GetMixFormat(&pwfx);
    if (!pwfx)
        return false;
    sampleRate = pwfx->nSamplesPerSec;
    channels = pwfx->nChannels;
    isFloat = (pwfx->wFormatTag == WAVE_FORMAT_IEEE_FLOAT) ||
            (pwfx->wFormatTag == WAVE_FORMAT_EXTENSIBLE &&
            reinterpret_cast<WAVEFORMATEXTENSIBLE*>(pwfx)->SubFormat ==
                KSDATAFORMAT_SUBTYPE_IEEE_FLOAT);
    HRESULT hr = pC->Initialize(
        AUDCLNT_SHAREMODE_SHARED,
        AUDCLNT_STREAMFLAGS_LOOPBACK | AUDCLNT_STREAMFLAGS_EVENTCALLBACK,
        200000, 0, pwfx, nullptr);
    CoTaskMemFree(pwfx);
    if (FAILED(hr))
        return false;
    if (hEvent)
        pC->SetEventHandle(hEvent);
    winrt::com_ptr<IAudioCaptureClient> pCap;
    if (FAILED(pC->GetService(__uuidof(IAudioCaptureClient), pCap.put_void())))
        return false;
    if (FAILED(pC->Start()))
        return false;
    pClient = pC;
    pCapture = pCap;
    return true;
}
static void VizCaptureThreadProc() {
    CoInitializeEx(nullptr, COINIT_MULTITHREADED);
    BuildHannWindow();
    BuildTwiddleFactors();
    winrt::com_ptr<IMMDeviceEnumerator> pEnum;
    if (FAILED(CoCreateInstance(XIID_MMDeviceEnumerator, nullptr, CLSCTX_ALL,
                                XIID_IMMDeviceEnumerator, pEnum.put_void()))) {
        g_CaptureRunning.store(false);
        CoUninitialize();
        return;
    }
    auto* notifyClient = new VizEndpointNotificationClient();
    bool notifyRegistered =
        SUCCEEDED(pEnum->RegisterEndpointNotificationCallback(notifyClient));
    winrt::com_ptr<IAudioClient> pClient;
    winrt::com_ptr<IAudioCaptureClient> pCapture;
    UINT32 sampleRate = 48000, channels = 2;
    bool isFloat = true;
    g_VizDeviceChanged.store(false, std::memory_order_relaxed);
    static constexpr int RING_CAP = VIZ_FFT_SIZE * 4;
    std::vector<float> ringBuf(RING_CAP, 0.f);
    int ringHead = 0, ringCount = 0;
    std::vector<float> re(VIZ_FFT_SIZE), im(VIZ_FFT_SIZE);
    float bandEnv[VIZ_NUM_BANDS] = {};
    static constexpr float GRAVITY[VIZ_NUM_BANDS] = {0.018f, 0.020f, 0.022f, 0.025f,
                                                    0.030f, 0.036f, 0.042f};
    ULONGLONG lastReinitAttempt = GetTickCount64() - 1000;
    while (g_CaptureRunning.load(std::memory_order_relaxed)) {
        if (g_hCaptureEvent)
            WaitForSingleObject(g_hCaptureEvent, 20);
        else
            Sleep(8);
        bool needsReinit = g_VizDeviceChanged.exchange(false, std::memory_order_relaxed) ||
                            !pClient;
        if (needsReinit) {
            ULONGLONG now = GetTickCount64();
            if (now - lastReinitAttempt >= 500) {
                lastReinitAttempt = now;
                if (pClient)
                    pClient->Stop();
                ringHead = 0;
                ringCount = 0;
                for (int b = 0; b < VIZ_NUM_BANDS; b++) {
                    bandEnv[b] = 0.f;
                    g_VizBands[b].store(0.f, std::memory_order_relaxed);
                }
                if (VizInitAudioClient(pEnum.get(), pClient, pCapture, sampleRate,
                                    channels, isFloat, g_hCaptureEvent))
                    BuildLogBins(sampleRate);
            }
        }
        if (!pCapture)
            continue;
        UINT32 packetSize = 0;
        HRESULT hr = pCapture->GetNextPacketSize(&packetSize);
        if (hr == AUDCLNT_E_DEVICE_INVALIDATED) {
            g_VizDeviceChanged.store(true, std::memory_order_relaxed);
            continue;
        }
        if (FAILED(hr) || packetSize == 0) {
            for (int b = 0; b < VIZ_NUM_BANDS; b++) {
                bandEnv[b] = std::max(0.f, bandEnv[b] - GRAVITY[b]);
                g_VizBands[b].store(bandEnv[b], std::memory_order_relaxed);
            }
            continue;
        }
        while (packetSize > 0) {
            BYTE* pData = nullptr;
            UINT32 numFrames = 0;
            DWORD flags = 0;
            HRESULT hrBuf =
                pCapture->GetBuffer(&pData, &numFrames, &flags, nullptr, nullptr);
            if (hrBuf == AUDCLNT_E_DEVICE_INVALIDATED) {
                g_VizDeviceChanged.store(true, std::memory_order_relaxed);
                break;
            }
            if (FAILED(hrBuf))
                break;
            bool silent = (flags & AUDCLNT_BUFFERFLAGS_SILENT) != 0;
            if (pData && numFrames > 0) {
                if (isFloat) {
                    float* src = reinterpret_cast<float*>(pData);
                    for (UINT32 f = 0; f < numFrames; f++) {
                        float mono = 0.f;
                        if (!silent)
                            for (UINT32 c = 0; c < channels; c++)
                                mono += src[f * channels + c];
                        ringBuf[ringHead] = mono / (float)channels;
                        ringHead = (ringHead + 1) % RING_CAP;
                        if (ringCount < RING_CAP)
                            ringCount++;
                    }
                } else {
                    INT16* src = reinterpret_cast<INT16*>(pData);
                    for (UINT32 f = 0; f < numFrames; f++) {
                        float mono = 0.f;
                        if (!silent)
                            for (UINT32 c = 0; c < channels; c++)
                                mono += src[f * channels + c] / 32768.f;
                        ringBuf[ringHead] = mono / (float)channels;
                        ringHead = (ringHead + 1) % RING_CAP;
                        if (ringCount < RING_CAP)
                            ringCount++;
                    }
                }
            }
            pCapture->ReleaseBuffer(numFrames);
            hr = pCapture->GetNextPacketSize(&packetSize);
            if (hr == AUDCLNT_E_DEVICE_INVALIDATED) {
                g_VizDeviceChanged.store(true, std::memory_order_relaxed);
                break;
            }
            if (FAILED(hr))
                break;
        }
        while (ringCount >= VIZ_FFT_SIZE) {
            int readStart = (ringHead - ringCount + RING_CAP) % RING_CAP;
            for (int i = 0; i < VIZ_FFT_SIZE; i++) {
                re[i] = ringBuf[(readStart + i) % RING_CAP] * g_HannWindow[i];
                im[i] = 0.f;
            }
            ringCount -= VIZ_FFT_SIZE / 2;
            VizFFT(re, im);
            float t_sens = g_settings.vizSensitivity / 100.0f;
            float sliderGain = (t_sens <= 1.0f)
                ? 0.25f + t_sens * t_sens * 2.75f
                : 3.0f + (t_sens - 1.0f) * 4.0f;
            auto eq = GetVizEQMultipliers(g_settings.vizEq);
            static constexpr float BAND_SENSITIVITY[VIZ_NUM_BANDS] = {
                0.30f, 0.22f, 0.12f, 0.06f, 0.030f, 0.018f, 0.010f};
            static constexpr int BAND_EQ_ZONE[VIZ_NUM_BANDS] = {0, 0, 1, 1, 2, 2, 2};
            for (int b = 0; b < VIZ_NUM_BANDS; b++) {
                int bStart = g_LogBinStart[b];
                int bEnd = g_LogBinStart[b + 1];
                if (bEnd <= bStart)
                    bEnd = bStart + 1;
                float sumSq = 0.f;
                int count = 0;
                for (int k = bStart; k < bEnd; k++) {
                    sumSq += re[k] * re[k] + im[k] * im[k];
                    count++;
                }
                float rms = (count > 0) ? sqrtf(sumSq / (float)count) : 0.f;
                float eqM = (BAND_EQ_ZONE[b] == 0)   ? eq.low
                            : (BAND_EQ_ZONE[b] == 1) ? eq.mid
                                                    : eq.high;
                float mag = std::max(
                    0.f, std::min(1.f, (rms / (VIZ_FFT_SIZE * 0.5f)) /
                                        BAND_SENSITIVITY[b] * sliderGain * eqM));
                bandEnv[b] = (mag >= bandEnv[b])
                                ? mag
                                : std::max(0.f, bandEnv[b] - GRAVITY[b]);
                g_VizBands[b].store(bandEnv[b], std::memory_order_relaxed);
            }
        }
    }
    if (pClient)
        pClient->Stop();
    if (notifyRegistered)
        pEnum->UnregisterEndpointNotificationCallback(notifyClient);
    notifyClient->Release();
    CoUninitialize();
}
static void StartVizCaptureThread() {
    std::lock_guard<std::mutex> lk(g_captureThreadMtx);
    if (g_CaptureRunning.load())
        return;
    if (g_CaptureThread && g_CaptureThread->joinable())
        g_CaptureThread->join();
    g_CaptureThread.reset();
    if (!g_hCaptureEvent)
        g_hCaptureEvent = CreateEvent(nullptr, FALSE, FALSE, nullptr);
    g_CaptureRunning.store(true);
    g_CaptureThread.emplace(VizCaptureThreadProc);
}
static void StopVizCaptureThread(bool onlyIfHidden = false) {
    std::lock_guard<std::mutex> lk(g_captureThreadMtx);
    if (onlyIfHidden && g_vizCurrentlyVisible) return;
    g_CaptureRunning.store(false);
    if (g_hCaptureEvent)
        SetEvent(g_hCaptureEvent);
    if (g_CaptureThread) {
        if (g_CaptureThread->joinable())
            g_CaptureThread->join();
        g_CaptureThread.reset();
    }
    if (g_hCaptureEvent) {
        CloseHandle(g_hCaptureEvent);
        g_hCaptureEvent = nullptr;
    }
    for (int i = 0; i < VIZ_NUM_BANDS; i++)
        g_VizBands[i].store(0.f);
}
static float g_VizPeak[VIZ_BARS_MAX] = {};
static float g_VizTarget[VIZ_BARS_MAX] = {};
static float g_VizBreatheEnv = 0.f;
static constexpr float VIZ_SEEDS[VIZ_BARS_MAX] = {
    0.83f, 0.41f, 1.27f, 0.61f, 1.09f, 0.37f, 0.95f, 0.52f, 1.18f, 0.74f,
    0.29f, 1.03f, 0.66f, 0.88f, 0.45f, 1.21f, 0.57f, 0.93f, 0.31f, 1.15f};
static void UpdateVisualizerPeaks() {
    const int vizBars = std::max(1, std::min(g_settings.vizBars, VIZ_BARS_MAX));
    float bands[VIZ_NUM_BANDS];
    float masterPeak = 0.f;
    for (int i = 0; i < VIZ_NUM_BANDS; i++) {
        bands[i] = g_VizBands[i].load(std::memory_order_relaxed);
        masterPeak = std::max(masterPeak, bands[i]);
    }
    auto sampleBands = [&](float t) -> float {
        float pos = t * (VIZ_NUM_BANDS - 1);
        int lo = (int)pos;
        int hi = std::min(lo + 1, VIZ_NUM_BANDS - 1);
        return bands[lo] * (1.f - (pos - (float)lo)) +
            bands[hi] * (pos - (float)lo);
    };
    float t = (float)GetTickCount64() * 0.001f;
    float center = (vizBars - 1) * 0.5f;
    for (int i = 0; i < vizBars; i++) {
        float freqT = (vizBars > 1) ? (float)i / (float)(vizBars - 1) : 0.5f;
        float target = 0.f;
        switch (g_settings.vizShape) {
            case VizShape::Stereo:
                target = sampleBands(freqT);
                break;
            case VizShape::Mountain: {
                float dist = fabsf((float)i - center) / std::max(1.f, center);
                float energy = sampleBands(dist);
                float taper = 1.6f - dist * 0.9f;
                target = (energy + masterPeak * (0.2f - dist * 0.12f)) * taper;
                break;
            }
            case VizShape::Mirror: {
                float mirT = 1.f - fabsf((float)i - center) / std::max(1.f, center);
                float energy = sampleBands(mirT);
                target = (energy + masterPeak * (0.1f + mirT * 0.12f)) * 1.3f;
                break;
            }
            case VizShape::Wave: {
                float phase = (float)i * (2.f * VIZ_PI / (float)vizBars);
                float wave = 0.55f + 0.45f * sinf(t * 3.5f - phase);
                float energy = sampleBands(freqT);
                target = energy * wave + masterPeak * 0.15f;
                break;
            }
            case VizShape::Breathe: {
                if (i == 0) {
                    float k = (masterPeak > g_VizBreatheEnv) ? 0.04f : 0.015f;
                    g_VizBreatheEnv += (masterPeak - g_VizBreatheEnv) * k;
                }
                float rate = 0.55f + VIZ_SEEDS[i] * 0.18f;
                float inhale =
                    0.5f + 0.5f * sinf(t * rate + VIZ_SEEDS[i] * 1.2f);
                target = inhale * (0.12f + g_VizBreatheEnv * 0.88f);
                break;
            }
        }
        g_VizTarget[i] = std::max(0.f, std::min(1.f, target));
    }
}
using VizRect = winrt::Windows::UI::Xaml::Shapes::Rectangle;
[[clang::no_destroy]] static std::optional<std::vector<VizRect>> g_vizBars{std::in_place};
[[clang::no_destroy]] static std::optional<std::vector<SolidColorBrush>> g_vizBrushes{std::in_place};

struct PlayerInstanceState {
    HWND                  taskbarWnd = nullptr;
    Grid                  grid{nullptr};
    FrameworkElement      injectionParent{nullptr};
    int                   column = -1;
    ToolTip               toolTip{nullptr};
    std::function<void()> buttonStateUpdater;
    FrameworkElement      trackedElement{nullptr};
    Thickness             trackedElementOriginalMargin{};
    std::wstring          trackPosition;
    winrt::event_token    layoutUpdateToken{};
    TextScrollState       titleScroll;
    TextScrollState       artistScroll;
    std::wstring          cachedAlbumTitle;
    std::wstring          cachedAlbumArtist;
    std::vector<BYTE>     cachedThumbnailBytes;
    std::wstring          scrollCachedTitle;
    std::wstring          scrollCachedArtist;
    size_t                cachedPaletteHash = 0;
    std::optional<std::vector<VizRect>>          vizBars{std::in_place};
    std::optional<std::vector<SolidColorBrush>>  vizBrushes{std::in_place};
};

static void SwapPlayerInstanceState(PlayerInstanceState& s) {
    std::swap(s.taskbarWnd,      g_curTaskbarWnd);
    std::swap(s.grid,            g_playerGrid);
    std::swap(s.injectionParent, g_injectionParent);
    std::swap(s.column,          g_playerColumn);
    std::swap(s.toolTip,         g_playerToolTip);
    std::swap(s.buttonStateUpdater, g_playerButtonStateUpdater);
    std::swap(s.trackedElement,  g_trackedElement);
    std::swap(s.trackedElementOriginalMargin, g_trackedElementOriginalMargin);
    std::swap(s.trackPosition,   g_trackPosition);
    std::swap(s.layoutUpdateToken, g_layoutUpdateToken);
    std::swap(s.titleScroll,     g_titleScroll);
    std::swap(s.artistScroll,    g_artistScroll);
    std::swap(s.cachedAlbumTitle,     g_cachedAlbumTitle);
    std::swap(s.cachedAlbumArtist,    g_cachedAlbumArtist);
    std::swap(s.cachedThumbnailBytes, g_cachedThumbnailBytes);
    std::swap(s.scrollCachedTitle,    g_scrollCachedTitle);
    std::swap(s.scrollCachedArtist,   g_scrollCachedArtist);
    std::swap(s.cachedPaletteHash,    g_cachedPaletteHash);
    std::swap(s.vizBars,    g_vizBars);
    std::swap(s.vizBrushes, g_vizBrushes);
}

[[clang::no_destroy]] static std::vector<std::unique_ptr<PlayerInstanceState>> g_playerInstances;
static PlayerInstanceState* g_currentInstance = nullptr;

static int PlayerInstanceCount() {
    return (int)g_playerInstances.size();
}

static bool IsLivePlayerInstance(PlayerInstanceState* inst) {
    if (!inst) return false;
    for (auto& owned : g_playerInstances) {
        if (owned.get() == inst) return true;
    }
    return false;
}

static void SetCurrentPlayerInstance(PlayerInstanceState* target) {
    if (g_currentInstance == target) return;
    if (g_currentInstance) {
        SwapPlayerInstanceState(*g_currentInstance);
        g_currentInstance = nullptr;
    }
    if (target) {
        SwapPlayerInstanceState(*target);
        g_currentInstance = target;
    }
}

static PlayerInstanceState* DefaultPlayerInstance() {
    return g_playerInstances.empty() ? nullptr : g_playerInstances.front().get();
}

template <typename F>
static void WithPlayerInstance(PlayerInstanceState* inst, F&& fn) {
    PlayerInstanceState* previous = g_currentInstance;
    SetCurrentPlayerInstance(inst);
    try { fn(); } catch (...) {}
    SetCurrentPlayerInstance(previous);
}

template <typename F>
static void ForEachPlayerInstance(F&& fn) {
    std::vector<PlayerInstanceState*> snapshot;
    snapshot.reserve(g_playerInstances.size());
    for (auto& owned : g_playerInstances) snapshot.push_back(owned.get());
    PlayerInstanceState* previous = g_currentInstance;
    for (auto* inst : snapshot) {
        if (!IsLivePlayerInstance(inst)) continue;
        SetCurrentPlayerInstance(inst);
        try { fn(); } catch (...) {}
    }
    SetCurrentPlayerInstance(IsLivePlayerInstance(previous) ? previous
                                                           : DefaultPlayerInstance());
}

static winrt::Windows::UI::Color VizLerpColor(winrt::Windows::UI::Color a,
                                            winrt::Windows::UI::Color b, float t) {
    auto lerpChannel = [](BYTE x, BYTE y, float tt) -> BYTE {
        return (BYTE)((int)x + (int)((float)((int)y - (int)x) * tt));
    };
    return winrt::Windows::UI::Color{255, lerpChannel(a.R, b.R, t), lerpChannel(a.G, b.G, t),
                                     lerpChannel(a.B, b.B, t)};
}
static winrt::Windows::UI::Color VizEnsureContrast(winrt::Windows::UI::Color c) {
    const int kLumaThreshold = 90;
    bool light = IsSystemLightTheme();
    int luma = (c.R * 299 + c.G * 587 + c.B * 114) / 1000;
    int edgeDist = light ? (255 - luma) : luma;
    if (edgeDist >= kLumaThreshold) return c;
    winrt::Windows::UI::Color base = light
        ? winrt::Windows::UI::Color{255, 0, 0, 0}
        : winrt::Windows::UI::Color{255, 255, 255, 255};
    if (g_cachedThumbnailBytes.empty()) return base;
    float t = edgeDist / (float)kLumaThreshold;
    float tintAmount = 0.65f + t * 0.35f;
    return VizLerpColor(base, c, tintAmount);
}
static double VizZoneHeight() {
    double h = 0.0;
    if (g_settings.showAlbumArt && g_settings.albumArtMaxHeight > 0)
        h = std::max(h, (double)g_settings.albumArtMaxHeight);
    if (g_settings.showMediaButtons)
        h = std::max(h, (double)g_settings.buttonSize);
    if (h <= 0.0)
        h = (g_settings.playerMaxHeight > 0 ? (double)g_settings.playerMaxHeight : 40.0);
    if (g_settings.playerMaxHeight > 0)
        h = std::min(h, (double)g_settings.playerMaxHeight);
    return h;
}
static void VizApplyFrame() {
    if (!g_settings.vizEnabled)
        return;
    UpdateVisualizerPeaks();
    float attack = 0.f, decay = 0.f;
    float sensBoost = std::max(0.f, (g_settings.vizSensitivity - 100) / 200.f) * 0.12f;
    switch (g_settings.vizShape) {
        case VizShape::Stereo:  attack = 0.72f; decay = 0.22f + sensBoost; break;
        case VizShape::Mirror:  attack = 0.52f; decay = 0.20f + sensBoost; break;
        case VizShape::Wave:    attack = 0.34f; decay = 0.17f + sensBoost; break;
        case VizShape::Breathe: attack = 0.20f; decay = 0.11f + sensBoost; break;
        case VizShape::Mountain: break;
    }
    int barCount = std::clamp(g_settings.vizBars, 1, VIZ_BARS_MAX);
    double zoneH = VizZoneHeight();
    double maxBH = std::max(4.0, zoneH - 6.0);
    double minBH = (double)g_settings.vizBarWidth;
    double idlePx = std::min((double)g_settings.vizIdleBarSize, std::max(0.0, maxBH - minBH));
    double range = std::max(0.0, maxBH - minBH - idlePx);
    bool idleHidden = (g_settings.vizIdleBarSize == 0);
    winrt::Windows::UI::Color baseCol{255, 255, 255, 255};
    if (g_settings.vizColorMode == VizColorMode::DynamicAlbum) {
        if (g_vizBaseColorDirty || g_vizPaletteColorsDirty) {
            g_cachedVizBaseColor = VizEnsureContrast(g_cachedAlbumPalette.primary);
            g_cachedVizBaseColor.A = 255;
        }
        baseCol = g_cachedVizBaseColor;
    } else {
        if (g_vizBaseColorDirty) {
            g_cachedVizBaseColor = ParseColorWithThemeSupport(g_settings.vizColor, 255);
        }
        baseCol = g_cachedVizBaseColor;
    }
    if (g_vizPaletteColorsDirty || g_vizBaseColorDirty) {
        g_cachedVizPal0   = VizEnsureContrast(g_cachedAlbumPalette.primary);
        g_cachedVizPal1   = VizEnsureContrast(g_cachedAlbumPalette.secondary);
        g_cachedVizCg0    = ParseColorWithSpecialValues(g_settings.vizColor1, 255);
        g_cachedVizCg1    = ParseColorWithSpecialValues(g_settings.vizColor2, 255);
        g_cachedVizAcrCol = ParseColorWithThemeSupport(g_settings.vizColor, 255);
        g_vizPaletteColorsDirty = false;
        g_vizBaseColorDirty = false;
    }
    double heights[VIZ_BARS_MAX];
    winrt::Windows::UI::Color colors[VIZ_BARS_MAX];
    for (int i = 0; i < barCount; i++) {
        float tgt = g_VizTarget[i], cur = g_VizPeak[i];
        float a = attack, d = decay;
        if (g_settings.vizShape == VizShape::Mountain) {
            float dist = fabsf((float)i - ((barCount - 1) * 0.5f));
            if (dist < 0.5f)      { a = 0.85f; d = 0.26f + sensBoost; }
            else if (dist < 1.5f) { a = 0.62f; d = 0.20f + sensBoost; }
            else                  { a = 0.92f; d = 0.34f + sensBoost; }
        }
        float next = cur + (tgt - cur) * ((tgt > cur) ? a : d);
        g_VizPeak[i] = (fabsf(next - cur) > 0.0005f) ? next : tgt;
        float fac = g_VizPeak[i];
        heights[i] = idleHidden
            ? (fac * maxBH)
            : (minBH + idlePx + fac * range);
        colors[i] = baseCol;
        if (g_settings.vizColorMode == VizColorMode::DynamicGradient) {
            float t = (float)i / std::max(1, barCount - 1);
            float freqT = std::min(1.f, t * 0.6f + fac * 0.4f);
            colors[i] = VizLerpColor(g_cachedVizPal0, g_cachedVizPal1, freqT);
        } else if (g_settings.vizColorMode == VizColorMode::CustomGradient) {
            float t = (barCount > 1) ? (float)i / (barCount - 1) : 0.f;
            colors[i] = VizLerpColor(g_cachedVizCg0, g_cachedVizCg1, t);
        } else if (g_settings.vizColorMode == VizColorMode::Acrylic) {
            BYTE aa = (BYTE)std::max(30, std::min(180, (int)(150.f * fac + 30.f)));
            colors[i] = winrt::Windows::UI::Color{aa, g_cachedVizAcrCol.R, g_cachedVizAcrCol.G,
                                                  g_cachedVizAcrCol.B};
        }
    }
    ForEachPlayerInstance([&] {
        for (int i = 0, n = std::min((int)g_vizBars->size(), barCount); i < n; i++) {
            try {
                (*g_vizBars)[i].Height(heights[i]);
                if (i < (int)g_vizBrushes->size() && (*g_vizBrushes)[i])
                    (*g_vizBrushes)[i].Color(colors[i]);
            } catch (...) {}
        }
    });
}
static void VizTimerTick(winrt::Windows::Foundation::IInspectable const&,
                        winrt::Windows::Foundation::IInspectable const&) {
    if (g_unloading || g_applyingSettings) return;
    if (!g_settings.vizEnabled) return;
    VizApplyFrame();
}
[[clang::no_destroy]] static TickTimer g_vizTimer{.onTick = &VizTimerTick};
static FrameworkElement BuildVisualizerElement() {
    int barCount = std::clamp(g_settings.vizBars, 1, VIZ_BARS_MAX);
    g_vizBars->reserve((size_t)barCount);
    g_vizBrushes->reserve((size_t)barCount);
    double zoneH = VizZoneHeight();
    StackPanel bars;
    bars.Name(L"FluentMedia_VisualizerBars");
    bars.Orientation(Orientation::Horizontal);
    bars.Height(zoneH);
    bars.VerticalAlignment(VerticalAlignment::Center);
    bars.HorizontalAlignment(HorizontalAlignment::Center);
    bars.IsHitTestVisible(false);
    VerticalAlignment va = (g_settings.vizAnchor == VizAnchor::Top)    ? VerticalAlignment::Top
                        : (g_settings.vizAnchor == VizAnchor::Bottom) ? VerticalAlignment::Bottom
                                                            : VerticalAlignment::Center;
    double minBH = (double)g_settings.vizBarWidth;
    double maxBH = std::max(4.0, zoneH - 6.0);
    double idlePx = std::min((double)g_settings.vizIdleBarSize, std::max(0.0, maxBH - minBH));
    double corner = g_settings.vizBarWidth * 0.5;
    bool idleHidden = (g_settings.vizIdleBarSize == 0);
    for (int i = 0; i < barCount; i++) {
        VizRect r;
        r.Width((double)g_settings.vizBarWidth);
        r.Height(idleHidden ? 0.0 : (minBH + idlePx));
        r.RadiusX(corner);
        r.RadiusY(corner);
        r.VerticalAlignment(va);
        if (i > 0)
            r.Margin({(double)g_settings.vizBarGap, 0, 0, 0});
        SolidColorBrush br = MakeBrush({255, 255, 255, 255});
        r.Fill(br);
        if (g_settings.vizColorMode == VizColorMode::Acrylic) {
            r.Stroke(MakeBrush({0x40, 0xFF, 0xFF, 0xFF}));
            r.StrokeThickness(0.8);
        }
        bars.Children().Append(r);
        g_vizBars->push_back(r);
        g_vizBrushes->push_back(br);
    }
    bool vizLeft = (g_settings.vizPosition == L"left");
    if (g_settings.mirrorLayout) vizLeft = !vizLeft;
    const double kVizSectionGap = 6.0;
    double marginL = (double)g_settings.vizPadLeft  + (vizLeft ? 0.0 : kVizSectionGap);
    double marginR = (double)g_settings.vizPadRight + (vizLeft ? kVizSectionGap : 0.0);
    Grid vizContainer;
    vizContainer.Name(kVizContainerName);
    vizContainer.Height(zoneH);
    vizContainer.VerticalAlignment(VerticalAlignment::Center);
    vizContainer.HorizontalAlignment(HorizontalAlignment::Center);
    vizContainer.IsHitTestVisible(false);
    vizContainer.Margin({marginL, 0, marginR, 0});
    vizContainer.Children().Append(bars);
    return vizContainer;
}
static void StartTimerThread() {
    if (g_timerThread) return;
    g_timerStopEvent = CreateEventW(nullptr, TRUE, FALSE, nullptr);
    g_timerUpdateEvent = CreateEventW(nullptr, FALSE, FALSE, nullptr);
    if (!g_timerStopEvent || !g_timerUpdateEvent) {
        if (g_timerStopEvent) CloseHandle(g_timerStopEvent);
        if (g_timerUpdateEvent) CloseHandle(g_timerUpdateEvent);
        g_timerStopEvent = nullptr;
        g_timerUpdateEvent = nullptr;
        return;
    }
    g_timerThread    = CreateThread(nullptr, 0, TimerThreadProc, nullptr, 0, nullptr);
    if (!g_timerThread) {
        CloseHandle(g_timerStopEvent);
        g_timerStopEvent = nullptr;
        CloseHandle(g_timerUpdateEvent);
        g_timerUpdateEvent = nullptr;
    }
    if (g_settings.enableTitleScrolling || g_settings.enableArtistScrolling) {
        StartTickTimer(g_scrollTimer);
    }
}
static void StopTimerThread() {
    StopTickTimer(g_scrollTimer);
    StopTickTimer(g_vizTimer);
    StopVizCaptureThread();
    if (g_timerStopEvent) SetEvent(g_timerStopEvent);
    if (g_timerThread) {
        WaitForSingleObject(g_timerThread, INFINITE);
        CloseHandle(g_timerThread);
        g_timerThread = nullptr;
    }
    if (g_timerStopEvent) { CloseHandle(g_timerStopEvent); g_timerStopEvent = nullptr; }
    if (g_timerUpdateEvent) { CloseHandle(g_timerUpdateEvent); g_timerUpdateEvent = nullptr; }
}
static void RefreshThemeColorsInstance() {
    if (!g_playerGrid || g_unloading || g_applyingSettings) return;
    g_vizBaseColorDirty = true;
    g_vizPaletteColorsDirty = true;
    try {
        UpdateHoverBrushColors();
        auto textClr = TextColor();
        auto artistClr = ArtistColor();
        auto buttonClr = ButtonColor();
        if (auto bgFe = FindChildByName(g_playerGrid, kBackgroundName)) {
            if (auto bgBorder = bgFe.try_as<Border>()) {
                if (g_settings.backgroundType == L"album_art_blur") {
                    if (!g_cachedThumbnailBytes.empty()) {
                        int w = (int)bgBorder.ActualWidth();
                        int h = (int)bgBorder.ActualHeight();
                        if (w > 0 && h > 0) {
                            bgBorder.Background(MakeAlbumBlurBrush(g_cachedThumbnailBytes, w, h));
                        }
                    } else {
                        bgBorder.Background(MakeBrush(IsSystemLightTheme()
                            ? winrt::Windows::UI::Color{0xCC, 0xF3, 0xF3, 0xF3}
                            : winrt::Windows::UI::Color{0xCC, 0x20, 0x20, 0x20}));
                    }
                    bgBorder.Visibility(Visibility::Visible);
                    bgBorder.Opacity(g_settings.blurOpacity / 100.0);
                } else if (UsesBackgroundBrush()) {
                    ApplyBrushBackground(bgBorder);
                } else {
                    bgBorder.Background(nullptr);
                    bgBorder.Visibility(Visibility::Collapsed);
                }
            }
        }
        if (auto fe = FindChildByName(g_playerGrid, L"FluentMedia_OuterBorder")) {
            if (auto btn = fe.try_as<Button>()) {
                try {
                    auto normalBg = MakeBackgroundBrush();
                    ApplyFluentMediaButtonStyle(btn);
                    btn.ApplyTemplate();
                    SetupPlayerCommonStates(btn, normalBg);
                    GoToCommonState(btn, IsHoverEffectEnabled(g_settings.playerHoverEffectMode), false, false);
                } catch (...) {}
            }
        }
        if (auto fe = FindChildByName(g_playerGrid, kTitleBlockName))
            if (auto tb = fe.try_as<TextBlock>()) tb.Foreground(MakeBrush(textClr));
        if (auto fe = FindChildByName(g_playerGrid, kArtistBlockName))
            if (auto ab = fe.try_as<TextBlock>()) ab.Foreground(MakeBrush(artistClr));
        for (const wchar_t* name : {kPrevBtnName, kPlayBtnName, kNextBtnName, kRewindBtnName, kForwardBtnName, kShuffleBtnName, kRepeatBtnName, kSwitchSessionsBtnName}) {
            if (auto fe = FindChildByName(g_playerGrid, name)) {
                if (auto btn = fe.try_as<Button>()) {
                    if (auto ct = btn.Content().try_as<TextBlock>()) ct.Foreground(MakeBrush(buttonClr));
                    ApplyFluentMediaButtonStyle(btn);
                    btn.ApplyTemplate();
                    SetupMediaButtonCommonStates(btn);
                    try { VisualStateManager::GoToState(btn, L"Normal", false); } catch (...) {}
                }
            }
        }
    } catch (...) {}
}
static void RefreshThemeColors() {
    ForEachPlayerInstance(&RefreshThemeColorsInstance);
}
static HMONITOR GetMonitorByNumber(int monitorNumber) {
    struct Ctx { int target; int current; HMONITOR result; };
    Ctx ctx{monitorNumber - 1, 0, nullptr};
    EnumDisplayMonitors(nullptr, nullptr,
        [](HMONITOR hMon, HDC, LPRECT, LPARAM lp) CALLBACK -> BOOL {
            auto* c = reinterpret_cast<Ctx*>(lp);
            if (c->current == c->target) { c->result = hMon; return FALSE; }
            c->current++;
            return TRUE;
        }, reinterpret_cast<LPARAM>(&ctx));
    return ctx.result;
}
static HWND FindTaskbarWndForMonitor(HMONITOR targetMonitor) {
    struct Ctx { HMONITOR target; HWND result; };
    Ctx ctx{targetMonitor, nullptr};
    EnumWindows([](HWND hWnd, LPARAM lp) CALLBACK -> BOOL {
        auto* c = reinterpret_cast<Ctx*>(lp);
        DWORD pid = 0; wchar_t cls[64] = {};
        if (GetWindowThreadProcessId(hWnd, &pid) && pid == GetCurrentProcessId() &&
            GetClassNameW(hWnd, cls, ARRAYSIZE(cls)) &&
            (_wcsicmp(cls, L"Shell_TrayWnd") == 0 ||
             _wcsicmp(cls, L"Shell_SecondaryTrayWnd") == 0)) {
            HMONITOR hMon = MonitorFromWindow(hWnd, MONITOR_DEFAULTTONEAREST);
            if (hMon == c->target) {
                c->result = hWnd;
                return FALSE;
            }
        }
        return TRUE;
    }, reinterpret_cast<LPARAM>(&ctx));
    return ctx.result;
}
static HWND FindCurrentProcessTaskbarWnd() {
    if (!g_settings.showOnAllMonitors) {
        if (HMONITOR mon = GetMonitorByNumber(g_settings.monitor)) {
            if (HWND hWnd = FindTaskbarWndForMonitor(mon)) {
                return hWnd;
            }
        }
    }
    HWND result = nullptr;
    EnumWindows([](HWND hWnd, LPARAM lp) CALLBACK -> BOOL {
        DWORD pid = 0; wchar_t cls[32] = {};
        if (GetWindowThreadProcessId(hWnd, &pid) && pid == GetCurrentProcessId() &&
            GetClassNameW(hWnd, cls, ARRAYSIZE(cls)) &&
            _wcsicmp(cls, L"Shell_TrayWnd") == 0)
        {
            *reinterpret_cast<HWND*>(lp) = hWnd;
            return FALSE;
        }
        return TRUE;
    }, reinterpret_cast<LPARAM>(&result));
    return result;
}
static bool IsReadableMemoryRange(const void* address, size_t size) {
    if (!address || size == 0) return false;
    MEMORY_BASIC_INFORMATION memory{};
    if (!VirtualQuery(address, &memory, sizeof(memory)) ||
        memory.State != MEM_COMMIT ||
        (memory.Protect & (PAGE_GUARD | PAGE_NOACCESS))) {
        return false;
    }
    const auto start = reinterpret_cast<uintptr_t>(address);
    const auto regionStart = reinterpret_cast<uintptr_t>(memory.BaseAddress);
    const auto regionEnd = regionStart + memory.RegionSize;
    return start >= regionStart && start <= regionEnd &&
           size <= regionEnd - start;
}
static XamlRoot GetTaskbarXamlRoot(HWND hTaskbarWnd) {
    wchar_t clsBuf[64] = {};
    GetClassNameW(hTaskbarWnd, clsBuf, ARRAYSIZE(clsBuf));
    bool isSecondary = _wcsicmp(clsBuf, L"Shell_SecondaryTrayWnd") == 0;
    HWND hTaskSwWnd = isSecondary
        ? FindWindowExW(hTaskbarWnd, nullptr, L"WorkerW", nullptr)
        : (HWND)GetProp(hTaskbarWnd, L"TaskbandHWND");
    if (!hTaskSwWnd) {
        Wh_Log(L"GetTaskbarXamlRoot: could not find taskband host window, aborting");
        return nullptr;
    }
    void* taskBand = (void*)GetWindowLongPtrW(hTaskSwWnd, 0);
    if (!taskBand) {
        Wh_Log(L"GetTaskbarXamlRoot: taskBand pointer is null, aborting");
        return nullptr;
    }
    void* expectedVftable = isSecondary
        ? CSecondaryTaskBand_ITaskListWndSite_vftable
        : CTaskBand_ITaskListWndSite_vftable;
    auto getTaskbarHost = isSecondary
        ? CSecondaryTaskBand_GetTaskbarHost_Original
        : CTaskBand_GetTaskbarHost_Original;
    if (!expectedVftable || !getTaskbarHost) {
        Wh_Log(L"GetTaskbarXamlRoot: %s symbols not resolved, aborting",
            isSecondary ? L"CSecondaryTaskBand" : L"CTaskBand");
        return nullptr;
    }
    void* taskBandForTaskListWndSite = taskBand;
    int i = 0;
    constexpr int kMaxSlotsToScan = 20;
    for (;; i++) {
        if (!IsReadableMemoryRange(taskBandForTaskListWndSite, sizeof(void*))) {
            Wh_Log(L"GetTaskbarXamlRoot: hit unreadable memory at slot %d, aborting", i);
            return nullptr;
        }
        if (*(void**)taskBandForTaskListWndSite == expectedVftable) break;
        if (i == kMaxSlotsToScan) {
            Wh_Log(L"GetTaskbarXamlRoot: ITaskListWndSite vftable not found within %d slots, aborting",
                kMaxSlotsToScan);
            return nullptr;
        }
        taskBandForTaskListWndSite = (void**)taskBandForTaskListWndSite + 1;
    }
    void* taskbarHostSharedPtr[2]{};
    getTaskbarHost(taskBandForTaskListWndSite, taskbarHostSharedPtr);
    if (!taskbarHostSharedPtr[0]) {
        Wh_Log(L"GetTaskbarXamlRoot: TaskbarHost shared_ptr is empty, aborting");
        if (taskbarHostSharedPtr[1] && Std_Ref_Decref_Original)
            Std_Ref_Decref_Original(taskbarHostSharedPtr[1]);
        return nullptr;
    }
    size_t taskbarElementIUnknownOffset = 0;
    bool frameHeightPatternRecognized = false;
#if defined(_M_X64) || defined(__x86_64__)
    {
        const BYTE* b = (const BYTE*)TaskbarHost_FrameHeight_Original;
        if (IsReadableMemoryRange(b, 8) &&
            b[0] == 0x48 && b[1] == 0x83 && b[2] == 0xEC && b[4] == 0x48 &&
            b[5] == 0x83 && b[6] == 0xC1 && b[7] <= 0x7F) {
            taskbarElementIUnknownOffset = b[7];
            frameHeightPatternRecognized = true;
        } else {
            Wh_Log(L"Unsupported TaskbarHost::FrameHeight pattern (x64)");
        }
    }
#elif defined(_M_ARM64) || defined(__aarch64__)
    {
        const DWORD* p = (const DWORD*)TaskbarHost_FrameHeight_Original;
        if (IsReadableMemoryRange(p, sizeof(DWORD) * 4) &&
            p[0] == 0xD503237F && (p[1] & 0xFFC07FFF) == 0xA9807BFD &&
            p[2] == 0x910003FD && (p[3] & 0xFFF00FE0) == 0xF8400C00) {
            taskbarElementIUnknownOffset = (p[3] >> 12) & 0xFF;
            frameHeightPatternRecognized = true;
        } else {
            Wh_Log(L"Unsupported TaskbarHost::FrameHeight pattern (arm64)");
        }
    }
#else
#error "Unsupported architecture"
#endif
    if (!frameHeightPatternRecognized ||
        !IsReadableMemoryRange(
            static_cast<BYTE*>(taskbarHostSharedPtr[0]) +
                taskbarElementIUnknownOffset,
            sizeof(IUnknown*))) {
        Wh_Log(L"GetTaskbarXamlRoot: FrameHeight pattern not recognized or offset unreadable, aborting");
        if (taskbarHostSharedPtr[1] && Std_Ref_Decref_Original)
            Std_Ref_Decref_Original(taskbarHostSharedPtr[1]);
        return nullptr;
    }
    auto* taskbarElementIUnknown =
        *(IUnknown**)((BYTE*)taskbarHostSharedPtr[0] +
                    taskbarElementIUnknownOffset);
    if (!taskbarElementIUnknown) {
        Wh_Log(L"GetTaskbarXamlRoot: taskbarElementIUnknown is null, aborting");
        if (taskbarHostSharedPtr[1] && Std_Ref_Decref_Original)
            Std_Ref_Decref_Original(taskbarHostSharedPtr[1]);
        return nullptr;
    }
    FrameworkElement taskbarElement{nullptr};
    taskbarElementIUnknown->QueryInterface(
        winrt::guid_of<FrameworkElement>(), winrt::put_abi(taskbarElement));
    auto result = taskbarElement ? taskbarElement.XamlRoot() : nullptr;
    if (taskbarHostSharedPtr[1] && Std_Ref_Decref_Original)
        Std_Ref_Decref_Original(taskbarHostSharedPtr[1]);
    return result;
}
static const wchar_t* RepeatModeGlyph(RepeatMode m) {
    if (m == RepeatMode::All) return L"\uE8EE";
    if (m == RepeatMode::One) return L"\uE8ED";
    return L"\uF5E7";
}
static bool IsFluentIconStyle(const std::wstring& s) {
    return s == L"fluent_outline" || s == L"fluent_filled";
}
static const wchar_t* GetGlyphWithStyle(int cmd, const std::wstring& style, bool isPlaying = false) {
    bool isFluent = IsFluentIconStyle(style);
    bool isFilled = (style == L"fluent_filled" || style == L"mdl2_filled");
    switch (cmd) {
        case kCmdPrevious:
            if (isFilled) return L"\uF8AC";
            return L"\uE892";
        case kCmdPlayPause:
            if (isPlaying) {
                if (isFluent && isFilled) return L"\uE62E";
                if (!isFluent && isFilled) return L"\uF8AE";
                return L"\uE769";
            } else {
                if (isFilled) return L"\uF5B0";
                return L"\uE768";
            }
        case kCmdNext:
            if (isFilled) return L"\uF8AD";
            return L"\uE893";
        case kCmdRewind:
            if (isFilled) return L"\uE627";
            return L"\uEB9E";
        case kCmdForward:
            if (isFilled) return L"\uE628";
            return L"\uEB9D";
        case kCmdToggleShuffle:
            return L"\uE8B1";
        case kCmdCycleRepeat:
            return RepeatModeGlyph(g_repeatMode.load());
        case kCmdSwitchSession:
            return L"\uE974";
        case kCmdRepeatOff: return RepeatModeGlyph(RepeatMode::Off);
        case kCmdRepeatAll: return RepeatModeGlyph(RepeatMode::All);
        case kCmdRepeatOne: return RepeatModeGlyph(RepeatMode::One);
    }
    return L"";
}
static const wchar_t* GetGlyph(int cmd, bool isPlaying = false) {
    return GetGlyphWithStyle(cmd, g_settings.iconStyle, isPlaying);
}
static TextBlock MakeIconText(const wchar_t* glyph, double sz, winrt::Windows::UI::Color c) {
    TextBlock t;
    t.Text(glyph);
    t.FontSize(sz);
    t.Foreground(MakeBrush(c));
    t.VerticalAlignment(VerticalAlignment::Center);
    t.HorizontalAlignment(HorizontalAlignment::Center);
    t.FontFamily(FontFamily(IsFluentIconStyle(g_settings.iconStyle) ? L"Segoe Fluent Icons" : L"Segoe MDL2 Assets"));
    return t;
}
static bool IsPointerInside(PointerRoutedEventArgs const& e, UIElement const& elem) {
    try {
        auto pos = e.GetCurrentPoint(elem).Position();
        auto size = elem.RenderSize();
        return pos.X >= 0 && pos.X <= size.Width && pos.Y >= 0 && pos.Y <= size.Height;
    } catch (...) {
        return false;
    }
}
static std::wstring MediaCommandLabel(int cmd) {
    switch (cmd) {
        case kCmdPrevious: return L"Previous track";
        case kCmdPlayPause: return L"Play or pause";
        case kCmdNext: return L"Next track";
        case kCmdRewind: return L"Rewind " + std::to_wstring(g_settings.seekStepSeconds) + L" seconds";
        case kCmdForward: return L"Forward " + std::to_wstring(g_settings.seekStepSeconds) + L" seconds";
        case kCmdToggleShuffle: return L"Toggle shuffle";
        case kCmdCycleRepeat: return L"Toggle repeat";
        case kCmdSwitchSession: return L"Switch media session";
    }
    return {};
}
static void SetButtonLabel(Button const& btn, std::wstring const& label) {
    Automation::AutomationProperties::SetName(btn, label);
    ToolTip toolTip;
    toolTip.Content(winrt::box_value(winrt::hstring(label)));
    ToolTipService::SetToolTip(btn, toolTip);
}
static Button MakeControlButton(int cmd, bool isPlaying, winrt::Windows::UI::Color iconColor) {
    Button btn;
    try {
        btn.Width((double)g_settings.buttonSize);
        btn.Height((double)g_settings.buttonSize);
        btn.Padding({1,1,1,1});
        btn.CornerRadius({
            g_settings.buttonCornerRadiusTL,
            g_settings.buttonCornerRadiusTR,
            g_settings.buttonCornerRadiusBR,
            g_settings.buttonCornerRadiusBL
        });
        btn.BorderThickness({0,0,0,0});
        btn.VerticalAlignment(VerticalAlignment::Center);
        btn.HorizontalAlignment(HorizontalAlignment::Center);
        auto iconText = MakeIconText(GetGlyph(cmd, isPlaying), (double)g_settings.buttonIconSize, iconColor);
        iconText.Opacity(cmd == kCmdToggleShuffle && !g_shuffleEnabled.load() ? 0.4 : 1.0);
        btn.Content(winrt::box_value(iconText));
        SetButtonLabel(btn, MediaCommandLabel(cmd));
        btn.Click([cmd](auto const&, auto const&) {
            if (!g_unloading) {
                try {
                    SendMediaCommandAsync(cmd);
                    DispatchMediaUpdate();
                } catch (...) {
                    Wh_Log(L"MakeControlButton: Exception in Click handler for cmd %d", cmd);
                }
            }
        });
        ApplyFluentMediaButtonStyle(btn);

        auto isPressed = std::make_shared<bool>(false);
        auto isHovered = std::make_shared<bool>(false);

        auto updateBtnVisualState = [weakBtn = winrt::make_weak(btn), isPressed, isHovered]() {
            try {
                if (auto b = weakBtn.get())
                    GoToCommonState(b, IsHoverEffectEnabled(g_settings.mediaButtonsHoverEffectMode), *isPressed, *isHovered);
            } catch (...) {

            }
        };

        RunWhenButtonReady(btn, [btn, updateBtnVisualState]() {
            try {
                SetupMediaButtonCommonStates(btn);
                updateBtnVisualState();
            } catch (...) {
                Wh_Log(L"MakeControlButton: Exception in RunWhenButtonReady");
            }
        });

        btn.PointerEntered([isHovered, updateBtnVisualState](auto const&, auto const&) {
            *isHovered = true;
            updateBtnVisualState();
        });

        btn.PointerExited([isHovered, updateBtnVisualState](auto const&, auto const&) {
            *isHovered = false;
            updateBtnVisualState();
        });

        btn.AddHandler(UIElement::PointerPressedEvent(), winrt::box_value(
            winrt::Windows::UI::Xaml::Input::PointerEventHandler(
            [isPressed, updateBtnVisualState](auto const& sender, winrt::Windows::UI::Xaml::Input::PointerRoutedEventArgs const& e) {
            if (auto elem = sender.template try_as<UIElement>()) {
                elem.CapturePointer(e.Pointer());
            }
            *isPressed = true;
            updateBtnVisualState();
        })), true);

        btn.AddHandler(UIElement::PointerReleasedEvent(), winrt::box_value(
            winrt::Windows::UI::Xaml::Input::PointerEventHandler(
            [isPressed, isHovered, updateBtnVisualState](auto const& sender, winrt::Windows::UI::Xaml::Input::PointerRoutedEventArgs const& e) {
            bool actuallyHovered = false;

            if (auto elem = sender.template try_as<UIElement>()) {
                elem.ReleasePointerCapture(e.Pointer());
                actuallyHovered = IsPointerInside(e, elem);
            }
            *isPressed = false;
            *isHovered = actuallyHovered;
            updateBtnVisualState();
            e.Handled(true);
        })), true);

        btn.PointerCanceled([isPressed, isHovered, updateBtnVisualState](auto const&, auto const&) {
            *isPressed = false;
            *isHovered = false;
            updateBtnVisualState();
        });

        btn.PointerCaptureLost([isPressed, isHovered, updateBtnVisualState](auto const& sender, winrt::Windows::UI::Xaml::Input::PointerRoutedEventArgs const& e) {
            if (auto elem = sender.template try_as<UIElement>()) {
                *isHovered = IsPointerInside(e, elem);
            }
            updateBtnVisualState();
        });
    } catch (...) {
        Wh_Log(L"MakeControlButton: Exception while creating button");
    }
    return btn;
}
static FontIcon MakeContextMenuIcon(const wchar_t* glyph, double opacity) {
    FontIcon icon;
    icon.Glyph(glyph);
    icon.FontSize((double)g_settings.buttonIconSize);
    icon.FontFamily(FontFamily(IsFluentIconStyle(ContextMenuIconStyle()) ? L"Segoe Fluent Icons" : L"Segoe MDL2 Assets"));
    icon.Foreground(MakeBrush(ContextMenuIconColor()));
    icon.Opacity(opacity);
    return icon;
}
static MenuFlyoutItem MakeActionContextMenuItem(const wchar_t* glyph, const wchar_t* label,
                                                std::function<void()> onClick) {
    MenuFlyoutItem item;
    item.Text(label);
    item.Icon(MakeContextMenuIcon(glyph, 1.0));
    item.Click([onClick](winrt::Windows::Foundation::IInspectable const&, RoutedEventArgs const&) {
        if (g_unloading) return;
        try {
            onClick();
        } catch (...) {}
    });
    return item;
}
static MenuFlyoutItem MakeMediaContextMenuItem(int cmd, const wchar_t* label, bool enabled, double iconOpacity) {
    auto item = MakeActionContextMenuItem(GetGlyphWithStyle(cmd, ContextMenuIconStyle()), label, [cmd]() {
        SendMediaCommandAsync(cmd);
        DispatchMediaUpdate();
    });
    item.IsEnabled(enabled);
    item.Icon().Opacity(iconOpacity);
    return item;
}
static void ShowMediaContextMenu(FrameworkElement const& target) {
    if (!target || g_unloading) return;
    try {
        bool canSkipPrevious = true, canSkipNext = true;
        bool canShuffle = true, canRepeat = true, canSeek = true;
        bool shuffleEnabled = false;
        {
            std::lock_guard<std::mutex> lk(g_mediaMtx);
            canSkipPrevious = g_media.canSkipPrevious;
            canSkipNext     = g_media.canSkipNext;
            canShuffle      = g_media.canShuffle;
            canRepeat       = g_media.canRepeat;
            canSeek         = g_media.canSeek;
            shuffleEnabled  = g_shuffleEnabled.load();
        }
        MenuFlyout menu;
        RepeatMode curRepeat = g_repeatMode.load();
        for (const auto& item : g_settings.contextMenuItems) {
            if (item == L"repeat") {
                if (g_settings.contextMenuRepeatStyle == L"toggle") {
                    const wchar_t* repeatLabel =
                        (curRepeat == RepeatMode::All) ? L"Repeat all" :
                        (curRepeat == RepeatMode::One) ? L"Repeat one" : L"Repeat off";
                    double repeatOpacity = canRepeat ? (curRepeat != RepeatMode::Off ? 1.0 : 0.4) : 0.4;
                    menu.Items().Append(MakeMediaContextMenuItem(kCmdCycleRepeat, repeatLabel, canRepeat, repeatOpacity));
                } else {
                    MenuFlyoutSubItem repeatSubMenu;
                    repeatSubMenu.Text(L"Repeat");
                    repeatSubMenu.Icon(MakeContextMenuIcon(GetGlyphWithStyle(kCmdCycleRepeat, ContextMenuIconStyle()), canRepeat ? 1.0 : 0.4));
                    repeatSubMenu.IsEnabled(canRepeat);
                    repeatSubMenu.Items().Append(MakeMediaContextMenuItem(kCmdRepeatOff, L"Repeat off", canRepeat, curRepeat == RepeatMode::Off ? 1.0 : 0.5));
                    repeatSubMenu.Items().Append(MakeMediaContextMenuItem(kCmdRepeatAll, L"Repeat all", canRepeat, curRepeat == RepeatMode::All ? 1.0 : 0.5));
                    repeatSubMenu.Items().Append(MakeMediaContextMenuItem(kCmdRepeatOne, L"Repeat one", canRepeat, curRepeat == RepeatMode::One ? 1.0 : 0.5));
                    menu.Items().Append(repeatSubMenu);
                }
            } else if (item == L"shuffle") {
                if (g_settings.contextMenuShuffleStyle == L"toggle") {
                    const wchar_t* shuffleLabel = shuffleEnabled ? L"Shuffle on" : L"Shuffle off";
                    double shuffleOpacity = canShuffle ? (shuffleEnabled ? 1.0 : 0.4) : 0.4;
                    menu.Items().Append(MakeMediaContextMenuItem(kCmdToggleShuffle, shuffleLabel, canShuffle, shuffleOpacity));
                } else {
                    MenuFlyoutSubItem shuffleSubMenu;
                    shuffleSubMenu.Text(L"Shuffle");
                    shuffleSubMenu.Icon(MakeContextMenuIcon(GetGlyphWithStyle(kCmdToggleShuffle, ContextMenuIconStyle()), canShuffle ? 1.0 : 0.4));
                    shuffleSubMenu.IsEnabled(canShuffle);
                    MenuFlyoutItem shuffleOffItem;
                    shuffleOffItem.Text(L"Shuffle off");
                    shuffleOffItem.IsEnabled(canShuffle);
                    shuffleOffItem.Icon(MakeContextMenuIcon(GetGlyphWithStyle(kCmdToggleShuffle, ContextMenuIconStyle()), !shuffleEnabled ? 1.0 : 0.5));
                    shuffleOffItem.Click([](winrt::Windows::Foundation::IInspectable const&, RoutedEventArgs const&) {
                        if (g_unloading) return;
                        try {
                            if (g_shuffleEnabled.load()) {
                                SendMediaCommandAsync(kCmdToggleShuffle);
                                DispatchMediaUpdate();
                            }
                        } catch (...) {}
                    });
                    MenuFlyoutItem shuffleOnItem;
                    shuffleOnItem.Text(L"Shuffle on");
                    shuffleOnItem.IsEnabled(canShuffle);
                    shuffleOnItem.Icon(MakeContextMenuIcon(GetGlyphWithStyle(kCmdToggleShuffle, ContextMenuIconStyle()), shuffleEnabled ? 1.0 : 0.5));
                    shuffleOnItem.Click([](winrt::Windows::Foundation::IInspectable const&, RoutedEventArgs const&) {
                        if (g_unloading) return;
                        try {
                            if (!g_shuffleEnabled.load()) {
                                SendMediaCommandAsync(kCmdToggleShuffle);
                                DispatchMediaUpdate();
                            }
                        } catch (...) {}
                    });
                    shuffleSubMenu.Items().Append(shuffleOffItem);
                    shuffleSubMenu.Items().Append(shuffleOnItem);
                    menu.Items().Append(shuffleSubMenu);
                }
            } else if (item == L"forward") {
                std::wstring label = L"Forward " + std::to_wstring(g_settings.seekStepSeconds) + L"s";
                menu.Items().Append(MakeMediaContextMenuItem(kCmdForward, label.c_str(), canSeek, canSeek ? 1.0 : 0.4));
            } else if (item == L"rewind") {
                std::wstring label = L"Rewind " + std::to_wstring(g_settings.seekStepSeconds) + L"s";
                menu.Items().Append(MakeMediaContextMenuItem(kCmdRewind, label.c_str(), canSeek, canSeek ? 1.0 : 0.4));
            } else if (item == L"next") {
                menu.Items().Append(MakeMediaContextMenuItem(kCmdNext, L"Next track", canSkipNext, canSkipNext ? 1.0 : 0.4));
            } else if (item == L"prev") {
                menu.Items().Append(MakeMediaContextMenuItem(kCmdPrevious, L"Previous track", canSkipPrevious, canSkipPrevious ? 1.0 : 0.4));
            } else if (item == L"switch_sessions") {
                menu.Items().Append(MakeMediaContextMenuItem(kCmdSwitchSession, L"Switch sessions", g_sessionCount.load() > 1, g_sessionCount.load() > 1 ? 1.0 : 0.4));
            } else if (item == L"open_app") {
                menu.Items().Append(MakeActionContextMenuItem(L"\uE8A7", L"Open media app", []() {
                    ExecuteMediaAction(L"open_app");
                }));
            } else if (item == L"mute_app") {
                int percent = g_targetVolumePercent.load();
                bool muted  = g_targetMuted.load();
                auto muteItem = MakeActionContextMenuItem(
                    muted ? L"\uE74F" : L"\uE767",
                    muted ? L"Unmute app" : L"Mute app",
                    []() { SendMediaCommandAsync(kCmdToggleMute); });
                muteItem.IsEnabled(percent >= 0);
                menu.Items().Append(muteItem);
            } else if (item == L"app_volume") {
                int percent = g_targetVolumePercent.load();
                bool muted  = g_targetMuted.load();
                MenuFlyoutSubItem volumeSubMenu;
                volumeSubMenu.Text(percent >= 0
                    ? winrt::hstring(L"App volume - " + std::to_wstring(percent) + L"%")
                    : winrt::hstring(L"App volume"));
                volumeSubMenu.IsEnabled(percent >= 0);
                volumeSubMenu.Icon(MakeContextMenuIcon(muted ? L"\uE74F" : L"\uE767", 1.0));
                volumeSubMenu.Items().Append(MakeActionContextMenuItem(
                    L"\uE995", L"Volume up",
                    []() { SendMediaCommandAsync(kCmdVolumeUp); }));
                volumeSubMenu.Items().Append(MakeActionContextMenuItem(
                    L"\uE993", L"Volume down",
                    []() { SendMediaCommandAsync(kCmdVolumeDown); }));
                volumeSubMenu.Items().Append(MakeActionContextMenuItem(
                    muted ? L"\uE74F" : L"\uE767",
                    muted ? L"Unmute" : L"Mute",
                    []() { SendMediaCommandAsync(kCmdToggleMute); }));
                menu.Items().Append(volumeSubMenu);
            }
        }
        Controls::Primitives::FlyoutShowOptions flyoutOptions;
        flyoutOptions.Placement(Controls::Primitives::FlyoutPlacementMode::Top);
        flyoutOptions.ShowMode(Controls::Primitives::FlyoutShowMode::Standard);
        flyoutOptions.ExclusionRect(winrt::Windows::Foundation::Rect{
            0.f, 0.f,
            (float)target.ActualWidth(),
            (float)target.ActualHeight() + 8.f
        });

        menu.Closed([](auto const&, auto const&) {
            try {
                if (g_playerButtonStateUpdater) {
                    g_playerButtonStateUpdater();
                }
                if (g_playerGrid && !g_unloading && !g_applyingSettings) {
                    if (auto bgFe = FindChildByName(g_playerGrid, kBackgroundName)) {
                        if (auto bgBorder = bgFe.try_as<Border>()) {
                            if (UsesBackgroundBrush()) {
                                ApplyBrushBackground(bgBorder);
                            }
                        }
                    }
                }
            } catch (...) {
                Wh_Log(L"ShowMediaContextMenu: Closed handler exception");
            }
        });
        
        menu.ShowAt(target, flyoutOptions);
    } catch (...) {
        Wh_Log(L"ShowMediaContextMenu: exception");
    }
}

[[clang::no_destroy]] static winrt::Windows::UI::Xaml::Controls::Flyout g_miniPlayerFlyout{nullptr};
[[clang::no_destroy]] static Controls::Image g_miniPlayerArtRef{nullptr};
[[clang::no_destroy]] static TextBlock       g_miniPlayerTitleRef{nullptr};
[[clang::no_destroy]] static TextBlock       g_miniPlayerArtistRef{nullptr};
[[clang::no_destroy]] static Button          g_miniPlayerPlayBtnRef{nullptr};
[[clang::no_destroy]] static Button          g_miniPlayerPrevBtnRef{nullptr};
[[clang::no_destroy]] static Button          g_miniPlayerNextBtnRef{nullptr};
[[clang::no_destroy]] static Button          g_miniPlayerShuffleBtnRef{nullptr};
[[clang::no_destroy]] static Button          g_miniPlayerRepeatBtnRef{nullptr};
[[clang::no_destroy]] static Button          g_miniPlayerMuteBtnRef{nullptr};
[[clang::no_destroy]] static Controls::Slider g_miniPlayerVolumeSliderRef{nullptr};
[[clang::no_destroy]] static TextBlock       g_miniPlayerVolumeTextRef{nullptr};
[[clang::no_destroy]] static Grid            g_miniPlayerVolumeRowRef{nullptr};
static bool                                  g_miniPlayerVolumeSuppress = false;
[[clang::no_destroy]] static StackPanel      g_miniPlayerSessionListRef{nullptr};
[[clang::no_destroy]] static Border          g_miniPlayerSessionListSepRef{nullptr};
[[clang::no_destroy]] static Border          g_miniPlayerBgOverlayRef{nullptr};
static void ClearMiniPlayerRefs() {
    g_miniPlayerArtRef            = nullptr;
    g_miniPlayerTitleRef          = nullptr;
    g_miniPlayerArtistRef         = nullptr;
    g_miniPlayerPlayBtnRef        = nullptr;
    g_miniPlayerPrevBtnRef        = nullptr;
    g_miniPlayerNextBtnRef        = nullptr;
    g_miniPlayerShuffleBtnRef     = nullptr;
    g_miniPlayerRepeatBtnRef      = nullptr;
    g_miniPlayerMuteBtnRef        = nullptr;
    g_miniPlayerVolumeSliderRef   = nullptr;
    g_miniPlayerVolumeTextRef     = nullptr;
    g_miniPlayerVolumeRowRef      = nullptr;
    g_miniPlayerSessionListRef    = nullptr;
    g_miniPlayerSessionListSepRef = nullptr;
    g_miniPlayerBgOverlayRef      = nullptr;
}

static void ApplyMiniPlayerBackground(Border const& overlay,
                                      const std::vector<BYTE>& thumbBytes) {
    if (!overlay) return;
    try {
        if (!g_settings.miniPlayerMatchPlayerBackground) {
            overlay.Background(nullptr);
            overlay.Visibility(Visibility::Collapsed);
            return;
        }
        overlay.Visibility(Visibility::Visible);
        if (g_settings.backgroundType != L"album_art_blur") {
            overlay.Opacity(1.0);
            overlay.Background(MakeBackgroundBrush());
            return;
        }
        overlay.Opacity(g_settings.blurOpacity / 100.0);
        if (thumbBytes.empty()) {
            overlay.Background(nullptr);
            return;
        }
        auto applyBlur = [overlay, thumbBytes]() {
            try {
                int w = (int)overlay.ActualWidth();
                int h = (int)overlay.ActualHeight();
                if (w <= 0 || h <= 0) return;
                overlay.Background(MakeAlbumBlurBrush(thumbBytes, w, h));
            } catch (...) {}
        };
        if (overlay.ActualWidth() > 0 && overlay.ActualHeight() > 0) {
            applyBlur();
        } else {
            auto token = std::make_shared<winrt::event_token>();
            *token = overlay.SizeChanged(
                [applyBlur, overlay, token](auto const&, auto const&) mutable {
                    applyBlur();
                    try { overlay.SizeChanged(*token); } catch (...) {}
                });
        }
    } catch (...) {}
}

struct MiniSessionInfo {
    std::wstring id;
    std::wstring title;
    std::wstring artist;
    std::vector<BYTE> thumbBytes;
};
static std::vector<MiniSessionInfo> g_miniSessionInfos;
static std::mutex                   g_miniSessionMtx;
static std::vector<BYTE> g_miniPlayerCachedThumb;
static std::vector<size_t> g_miniSessionCachedThumbSizes;
static std::vector<std::wstring> g_miniSessionRowIds;
static int g_miniSessionHoveredIndex = -1;

static winrt::Windows::Storage::Streams::IRandomAccessStream StreamFromBytes(std::vector<BYTE> const& bytes) {
    winrt::com_ptr<IStream> memStream;
    memStream.attach(SHCreateMemStream(bytes.data(), static_cast<UINT>(bytes.size())));
    winrt::Windows::Storage::Streams::IRandomAccessStream stream{nullptr};
    if (memStream) {
        ::CreateRandomAccessStreamOverStream(
            memStream.get(), BSOS_DEFAULT,
            winrt::guid_of<winrt::Windows::Storage::Streams::IRandomAccessStream>(),
            winrt::put_abi(stream));
    }
    return stream;
}
static void LoadMiniPlayerArtBitmap(Controls::Image const& img, std::vector<BYTE> const& thumbBytes) {
    if (!img || thumbBytes.empty()) return;
    try {
        auto rasStream = StreamFromBytes(thumbBytes);
        if (!rasStream) return;
        BitmapImage bmp;
        img.Source(bmp);
        bmp.SetSourceAsync(rasStream);
        img.Visibility(Visibility::Visible);
    } catch (...) {}
}
static Controls::Image MakeSessionRowArtImage(std::vector<BYTE> const& bytes) {
    auto stream = StreamFromBytes(bytes);
    if (!stream) return nullptr;
    Controls::Image rowImg;
    rowImg.Stretch(Stretch::None);
    rowImg.HorizontalAlignment(HorizontalAlignment::Center);
    rowImg.VerticalAlignment(VerticalAlignment::Center);
    BitmapImage bmp;
    bmp.DecodePixelHeight(32);
    rowImg.Source(bmp);
    bmp.SetSourceAsync(stream);
    return rowImg;
}
static winrt::Windows::UI::Color SessionRowBackground(bool isCurrent, bool isLight) {
    if (!isCurrent) return {0x00, 0x00, 0x00, 0x00};
    return isLight ? winrt::Windows::UI::Color{0x20, 0x00, 0x00, 0x00}
                   : winrt::Windows::UI::Color{0x2C, 0xFF, 0xFF, 0xFF};
}

static std::vector<std::shared_ptr<bool>> g_miniSessionCurrentFlags;

static void RefreshMiniPlayerFlyoutUI() {
    if (!g_miniPlayerFlyoutOpen) return;
    std::wstring title, artist;
    bool isPlaying = false;
    bool hasMedia = false;
    bool canSkipPrevious = true, canSkipNext = true;
    bool canShuffle = true, canRepeat = true;
    std::vector<BYTE> thumbBytes;
    {
        std::lock_guard<std::mutex> lk(g_mediaMtx);
        title           = g_media.title;
        artist          = g_media.artist;
        isPlaying       = g_media.isPlaying;
        hasMedia        = g_media.hasMedia;
        canSkipPrevious = g_media.canSkipPrevious;
        canSkipNext     = g_media.canSkipNext;
        canShuffle      = g_media.canShuffle;
        canRepeat       = g_media.canRepeat;
        thumbBytes      = g_media.thumbnailBytes;
    }
    std::wstring currentId;
    {
        GlobalSystemMediaTransportControlsSession sessionCopy{nullptr};
        {
            std::lock_guard<std::mutex> lk(g_sessionMtx);
            sessionCopy = g_currentSession;
        }
        if (sessionCopy) {
            try { currentId = std::wstring(sessionCopy.SourceAppUserModelId()); } catch (...) {}
        }
    }
    
    bool audioAppSource = false;
    if (!hasMedia) {
        uint64_t unusedHash = 0;
        if (ApplyAudioAppToDisplay(title, artist, thumbBytes, unusedHash, isPlaying)) {
            audioAppSource  = true;
            hasMedia        = true;
            canSkipPrevious = canSkipNext = canShuffle = canRepeat = false;
        }
    }
    try {
        ApplyMiniPlayerBackground(g_miniPlayerBgOverlayRef, thumbBytes);
        if (g_miniPlayerTitleRef) {
            std::wstring displayTitle;
            if (!hasMedia) {
                displayTitle = g_settings.noMediaTitleText;
            } else if (title.empty()) {
                displayTitle = g_settings.emptyTitleText;
            } else {
                displayTitle = title;
            }
            g_miniPlayerTitleRef.Text(winrt::hstring(displayTitle));
        }
        if (g_miniPlayerArtistRef) {
            std::wstring trimmedArtist = artist;
            trimmedArtist.erase(0, trimmedArtist.find_first_not_of(L" \t\n\r"));
            trimmedArtist.erase(trimmedArtist.find_last_not_of(L" \t\n\r") + 1);
            bool isEmpty = trimmedArtist.empty();
            g_miniPlayerArtistRef.Text(isEmpty ? winrt::hstring() : winrt::hstring(artist));
            g_miniPlayerArtistRef.Visibility(isEmpty ? Visibility::Collapsed : Visibility::Visible);
        }

        if (g_miniPlayerPlayBtnRef) {
            g_miniPlayerPlayBtnRef.IsEnabled(hasMedia);
            g_miniPlayerPlayBtnRef.Opacity(hasMedia ? 1.0 : 0.35);
            if (auto icon = g_miniPlayerPlayBtnRef.Content().try_as<TextBlock>()) {
                const wchar_t* glyph = audioAppSource
                    ? (isPlaying ? L"\uE767" : L"\uE74F")
                    : GetGlyphWithStyle(kCmdPlayPause, L"fluent_filled", isPlaying);
                icon.Text(winrt::hstring(glyph));
            }
        }
        if (g_miniPlayerVolumeRowRef) {
            int  percent = g_targetVolumePercent.load();
            bool muted   = g_targetMuted.load();
            bool haveVolume = (percent >= 0);
            g_miniPlayerVolumeRowRef.Visibility(
                (g_settings.showVolumeInMenu && haveVolume) ? Visibility::Visible
                                                            : Visibility::Collapsed);
            bool userIsDragging =
                (GetTickCount64() - g_volumeUserActionTick.load()) < 900;
            if (g_miniPlayerVolumeSliderRef && haveVolume && !userIsDragging) {
                g_miniPlayerVolumeSuppress = true;
                if (std::abs(g_miniPlayerVolumeSliderRef.Value() - (double)percent) > 0.5) {
                    g_miniPlayerVolumeSliderRef.Value((double)percent);
                }
                g_miniPlayerVolumeSuppress = false;
            }
            if (g_miniPlayerVolumeSliderRef) {
                g_miniPlayerVolumeSliderRef.Opacity(muted ? 0.45 : 1.0);
            }
            if (g_miniPlayerMuteBtnRef) {
                const wchar_t* muteLabel = muted ? L"Unmute app" : L"Mute app";
                if (Automation::AutomationProperties::GetName(g_miniPlayerMuteBtnRef) != muteLabel) {
                    SetButtonLabel(g_miniPlayerMuteBtnRef, muteLabel);
                }
                if (auto icon = g_miniPlayerMuteBtnRef.Content().try_as<TextBlock>()) {
                    icon.Text(winrt::hstring(muted ? L"\uE74F" : L"\uE767"));
                    icon.Opacity(muted ? 1.0 : 0.75);
                }
            }
            if (g_miniPlayerVolumeTextRef && !userIsDragging) {
                g_miniPlayerVolumeTextRef.Text(winrt::hstring(
                    muted ? std::wstring(L"Muted")
                          : std::to_wstring(std::max(0, percent)) + L"%"));
            }
        }

        if (g_miniPlayerPrevBtnRef) {
            bool enabled = hasMedia && canSkipPrevious;
            g_miniPlayerPrevBtnRef.IsEnabled(enabled);
            g_miniPlayerPrevBtnRef.Opacity(enabled ? 1.0 : 0.35);
        }

        if (g_miniPlayerNextBtnRef) {
            bool enabled = hasMedia && canSkipNext;
            g_miniPlayerNextBtnRef.IsEnabled(enabled);
            g_miniPlayerNextBtnRef.Opacity(enabled ? 1.0 : 0.35);
        }

        if (g_miniPlayerShuffleBtnRef) {
            bool enabled = hasMedia && canShuffle;
            g_miniPlayerShuffleBtnRef.IsEnabled(enabled);
            g_miniPlayerShuffleBtnRef.Opacity(enabled ? 1.0 : 0.35);
            if (auto icon = g_miniPlayerShuffleBtnRef.Content().try_as<TextBlock>()) {
                icon.Opacity(enabled && g_shuffleEnabled.load() ? 1.0 : 0.40);
            }
        }

        if (g_miniPlayerRepeatBtnRef) {
            bool enabled = hasMedia && canRepeat;
            g_miniPlayerRepeatBtnRef.IsEnabled(enabled);
            g_miniPlayerRepeatBtnRef.Opacity(enabled ? 1.0 : 0.35);
            if (auto icon = g_miniPlayerRepeatBtnRef.Content().try_as<TextBlock>()) {
                RepeatMode mode = g_repeatMode.load();
                icon.Text(RepeatModeGlyph(mode));
                icon.Opacity(enabled && mode != RepeatMode::Off ? 1.0 : 0.40);
            }
        }

        if (g_miniPlayerArtRef) {
            bool sameThumb = (!thumbBytes.empty() && thumbBytes == g_miniPlayerCachedThumb);
            if (!thumbBytes.empty() && !sameThumb) {
                LoadMiniPlayerArtBitmap(g_miniPlayerArtRef, thumbBytes);
                g_miniPlayerCachedThumb = thumbBytes;
            } else if (thumbBytes.empty()) {
                try { g_miniPlayerArtRef.Source(nullptr); } catch (...) {}
                g_miniPlayerArtRef.Visibility(Visibility::Collapsed);
                g_miniPlayerCachedThumb.clear();
            }
        }
        {
            std::vector<MiniSessionInfo> infos;
            {
                std::lock_guard<std::mutex> lk(g_miniSessionMtx);
                infos = g_miniSessionInfos;
            }

            if (g_miniPlayerSessionListSepRef) {
                g_miniPlayerSessionListSepRef.Visibility(
                    (infos.empty() || g_settings.hideMediaSessionsList) ? Visibility::Collapsed : Visibility::Visible);
            }

            if (g_miniPlayerSessionListRef) {
                auto sessionList = g_miniPlayerSessionListRef;
                sessionList.Visibility(infos.empty() ? Visibility::Collapsed : Visibility::Visible);

                std::vector<std::wstring> ids;
                for (auto const& info : infos) ids.push_back(info.id);
                if (ids != g_miniSessionRowIds) {
                    sessionList.Children().Clear();
                    g_miniSessionCurrentFlags.clear();
                    g_miniSessionCachedThumbSizes.clear();
                    g_miniSessionCachedThumbSizes.resize(infos.size(), SIZE_MAX);
                    for (size_t i = 0; i < infos.size(); ++i) {
                        bool isCurrent = (infos[i].id == currentId);
                        auto rowBtn = BuildSessionRowButton(infos[i], isCurrent, static_cast<int>(i));
                        sessionList.Children().Append(rowBtn);
                        g_miniSessionCachedThumbSizes[i] = infos[i].thumbBytes.size();
                    }
                    g_miniSessionRowIds = std::move(ids);
            } else {
                bool isLight = IsSystemLightTheme();
                int hoveredIdx = g_miniSessionHoveredIndex;

                for (uint32_t i = 0; i < infos.size(); ++i) {
                    bool isCurrent = (infos[i].id == currentId);
                    bool wasCurrent = isCurrent;
                    if (i < g_miniSessionCurrentFlags.size() && g_miniSessionCurrentFlags[i]) {
                        wasCurrent = *g_miniSessionCurrentFlags[i];
                        *g_miniSessionCurrentFlags[i] = isCurrent;
                    }
                    if (auto btn = sessionList.Children().GetAt(i).try_as<Button>()) {
                        if (auto hb = btn.Content().try_as<Border>()) {
                            if (hoveredIdx != static_cast<int>(i)) {
                                hb.Background(MakeBrush(SessionRowBackground(isCurrent, isLight)));
                            }
                            if (auto grid = hb.Child().try_as<Grid>()) {
                                for (uint32_t j = 0; j < grid.Children().Size(); ++j) {
                                    auto child = grid.Children().GetAt(j);
                                    if (auto pillRect = child.try_as<winrt::Windows::UI::Xaml::Shapes::Rectangle>()) {
                                        if (wasCurrent != isCurrent) {
                                            AnimateSessionPill(pillRect, isCurrent, true);
                                        }
                                        continue;
                                    }
                                    if (auto artBdr = child.try_as<Border>()) {
                                        size_t newSize = infos[i].thumbBytes.size();
                                        size_t cachedSize = (i < g_miniSessionCachedThumbSizes.size())
                                            ? g_miniSessionCachedThumbSizes[i] : SIZE_MAX;
                                        if (newSize != cachedSize) {
                                            if (i < g_miniSessionCachedThumbSizes.size())
                                                g_miniSessionCachedThumbSizes[i] = newSize;
                                            if (!infos[i].thumbBytes.empty()) {
                                                try { artBdr.Child(MakeSessionRowArtImage(infos[i].thumbBytes)); } catch (...) {}
                                            } else {
                                                try { artBdr.Child(nullptr); } catch (...) {}
                                            }
                                        }
                                        continue;
                                    }
                                    if (auto sp = child.try_as<StackPanel>()) {
                                        std::wstring disp = infos[i].title.empty() ? infos[i].id : infos[i].title;
                                        if (sp.Children().Size() > 0) {
                                            if (auto tb = sp.Children().GetAt(0).try_as<TextBlock>()) {
                                                tb.Text(winrt::hstring(disp));
                                            }
                                        }
                                        if (sp.Children().Size() > 1) {
                                            if (auto tb = sp.Children().GetAt(1).try_as<TextBlock>()) {
                                                tb.Text(winrt::hstring(infos[i].artist));
                                                tb.Visibility(infos[i].artist.empty()
                                                    ? Visibility::Collapsed
                                                    : Visibility::Visible);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            }
        }
    } catch (...) {}
}

static void AnimateSessionPill(winrt::Windows::UI::Xaml::Shapes::Rectangle const& pill, bool isCurrent, bool animate) {
    using namespace winrt::Windows::UI::Xaml::Media;
    using namespace winrt::Windows::UI::Xaml::Media::Animation;

    if (isCurrent) {
        try {
            auto uiSettings = winrt::Windows::UI::ViewManagement::UISettings();
            auto accentColor = uiSettings.GetColorValue(
                winrt::Windows::UI::ViewManagement::UIColorType::Accent);
            BYTE r = std::min(255, (int)accentColor.R + 60);
            BYTE g = std::min(255, (int)accentColor.G + 60);
            BYTE b = std::min(255, (int)accentColor.B + 60);
            
            pill.Fill(MakeBrush({0xFF, r, g, b}));
        } catch (...) {
            pill.Fill(MakeBrush({0xFF, 0x40, 0xA0, 0xFF}));
        }
    }

    auto st = pill.RenderTransform().try_as<ScaleTransform>();
    if (!st) {
        st = ScaleTransform();
        pill.RenderTransformOrigin({0.5, 0.5});
        pill.RenderTransform(st);
    }

    if (!animate) {
        pill.Opacity(isCurrent ? 1.0 : 0.0);
        st.ScaleY(isCurrent ? 1.0 : 0.0);
        return;
    }

    if (isCurrent) {
        pill.Opacity(0.0);
        st.ScaleY(0.0);

        try {
            Storyboard sb;

            DoubleAnimation fadeAnim;
            fadeAnim.From(0.0);
            fadeAnim.To(1.0);
            fadeAnim.Duration(DurationHelper::FromTimeSpan(std::chrono::milliseconds(100)));
            Storyboard::SetTarget(fadeAnim, pill);
            Storyboard::SetTargetProperty(fadeAnim, L"Opacity");
            sb.Children().Append(fadeAnim);
            DoubleAnimation scaleAnim;
            scaleAnim.From(0.0);
            scaleAnim.To(1.0);
            scaleAnim.Duration(DurationHelper::FromTimeSpan(std::chrono::milliseconds(350)));
            auto ease = BackEase();
            ease.EasingMode(EasingMode::EaseOut);
            ease.Amplitude(0.6);
            scaleAnim.EasingFunction(ease);
            Storyboard::SetTarget(scaleAnim, pill);
            Storyboard::SetTargetProperty(scaleAnim,
                L"(UIElement.RenderTransform).(ScaleTransform.ScaleY)");
            sb.Children().Append(scaleAnim);

            sb.Begin();
        } catch (...) {
            pill.Opacity(1.0);
            st.ScaleY(1.0);
        }
    } else {
        try {
            Storyboard sb;

            DoubleAnimation scaleAnim;
            scaleAnim.To(0.0);
            scaleAnim.Duration(DurationHelper::FromTimeSpan(std::chrono::milliseconds(150)));
            auto ease = CircleEase();
            ease.EasingMode(EasingMode::EaseIn);
            scaleAnim.EasingFunction(ease);
            Storyboard::SetTarget(scaleAnim, pill);
            Storyboard::SetTargetProperty(scaleAnim,
                L"(UIElement.RenderTransform).(ScaleTransform.ScaleY)");
            sb.Children().Append(scaleAnim);

            DoubleAnimation fadeAnim;
            fadeAnim.To(0.0);
            fadeAnim.BeginTime(winrt::Windows::Foundation::TimeSpan(std::chrono::milliseconds(100)));
            fadeAnim.Duration(DurationHelper::FromTimeSpan(std::chrono::milliseconds(80)));
            Storyboard::SetTarget(fadeAnim, pill);
            Storyboard::SetTargetProperty(fadeAnim, L"Opacity");
            sb.Children().Append(fadeAnim);

            sb.Begin();
        } catch (...) {
            pill.Opacity(0.0);
            st.ScaleY(0.0);
        }
    }
}

static Button BuildSessionRowButton(const MiniSessionInfo& info, bool isCurrent, int rowIndex) {
    bool isLight = IsSystemLightTheme();

    winrt::Windows::UI::Color bgHover = isLight 
        ? winrt::Windows::UI::Color{0x0E, 0x00, 0x00, 0x00}
        : winrt::Windows::UI::Color{0x14, 0xFF, 0xFF, 0xFF};
    winrt::Windows::UI::Color bgPressed = isLight 
        ? winrt::Windows::UI::Color{0x18, 0x00, 0x00, 0x00}
        : winrt::Windows::UI::Color{0x20, 0xFF, 0xFF, 0xFF};

    auto isCurrentFlag = std::make_shared<bool>(isCurrent);
    if (static_cast<size_t>(rowIndex) >= g_miniSessionCurrentFlags.size()) {
        g_miniSessionCurrentFlags.resize(rowIndex + 1);
    }
    g_miniSessionCurrentFlags[rowIndex] = isCurrentFlag;

    Border hoverBorder;
    hoverBorder.CornerRadius({6, 6, 6, 6});
    hoverBorder.Background(MakeBrush(SessionRowBackground(isCurrent, isLight)));
    hoverBorder.Height(48);
    hoverBorder.HorizontalAlignment(HorizontalAlignment::Stretch);
    hoverBorder.Padding({0, 0, 12, 0});
    try {
        BrushTransition bt;
        bt.Duration(std::chrono::milliseconds(83));
        hoverBorder.BackgroundTransition(bt);
    } catch (...) {}

    Grid rowGrid;
    rowGrid.Height(48);
    rowGrid.HorizontalAlignment(HorizontalAlignment::Stretch);
    ColumnDefinition cPill, c0, c1;
    cPill.Width({8, GridUnitType::Pixel});
    c0.Width({34, GridUnitType::Pixel});
    c1.Width({1,  GridUnitType::Star});
    rowGrid.ColumnDefinitions().Append(cPill);
    rowGrid.ColumnDefinitions().Append(c0);
    rowGrid.ColumnDefinitions().Append(c1);

    {
        winrt::Windows::UI::Xaml::Shapes::Rectangle pill;
        pill.Width(3);
        pill.Height(20);
        pill.RadiusX(1.5);
        pill.RadiusY(1.5);
        pill.VerticalAlignment(VerticalAlignment::Center);
        pill.HorizontalAlignment(HorizontalAlignment::Left);

        AnimateSessionPill(pill, isCurrent, false);
        if (isCurrent) {
            pill.Loaded([](auto const& sender, auto const&) {
                AnimateSessionPill(sender.template as<winrt::Windows::UI::Xaml::Shapes::Rectangle>(), true, true);
            });
        }

        Grid::SetColumn(pill, 0);
        rowGrid.Children().Append(pill);
    }

    Border rowArt;
    rowArt.Width(32); rowArt.Height(32);
    rowArt.CornerRadius({6, 6, 6, 6});
    rowArt.Margin({2, 0, 0, 0});
    rowArt.Background(MakeBrush({0x40, 0x80, 0x80, 0x80}));
    rowArt.VerticalAlignment(VerticalAlignment::Center);
    if (!info.thumbBytes.empty()) {
        try { rowArt.Child(MakeSessionRowArtImage(info.thumbBytes)); } catch (...) {}
    }
    Grid::SetColumn(rowArt, 1);
    rowGrid.Children().Append(rowArt);

    StackPanel rowText;
    rowText.Orientation(Orientation::Vertical);
    rowText.VerticalAlignment(VerticalAlignment::Center);
    rowText.HorizontalAlignment(HorizontalAlignment::Left);
    rowText.Margin({8, 0, 0, 0});
    rowText.MaxWidth(240);

    std::wstring displayTitle = info.title.empty() ? info.id : info.title;
    TextBlock rowTitle;
    rowTitle.Text(winrt::hstring(displayTitle));
    rowTitle.FontSize(12);
    rowTitle.FontWeight(winrt::Windows::UI::Text::FontWeights::SemiBold());
    rowTitle.TextTrimming(TextTrimming::CharacterEllipsis);
    rowTitle.TextWrapping(TextWrapping::NoWrap);
    rowTitle.HorizontalAlignment(HorizontalAlignment::Left);
    rowTitle.TextAlignment(TextAlignment::Left);
    rowTitle.Foreground(MakeBrush(isLight
        ? winrt::Windows::UI::Color{0xFF, 0x10, 0x10, 0x10}
        : winrt::Windows::UI::Color{0xFF, 0xFF, 0xFF, 0xFF}));
    rowText.Children().Append(rowTitle);

    TextBlock rowArtist;
    rowArtist.Text(winrt::hstring(info.artist));
    rowArtist.Visibility(info.artist.empty() ? Visibility::Collapsed : Visibility::Visible);
    rowArtist.FontSize(10.5);
    rowArtist.Opacity(0.65);
    rowArtist.TextTrimming(TextTrimming::CharacterEllipsis);
    rowArtist.TextWrapping(TextWrapping::NoWrap);
    rowArtist.HorizontalAlignment(HorizontalAlignment::Left);
    rowArtist.TextAlignment(TextAlignment::Left);
    rowArtist.Margin({0, 2, 0, 0});
    rowArtist.Foreground(MakeBrush(isLight
        ? winrt::Windows::UI::Color{0xFF, 0x50, 0x50, 0x50}
        : winrt::Windows::UI::Color{0xFF, 0xFF, 0xFF, 0xFF}));
    rowText.Children().Append(rowArtist);

    Grid::SetColumn(rowText, 2);
    rowGrid.Children().Append(rowText);
    hoverBorder.Child(rowGrid);

    Button rowBtn;
    rowBtn.HorizontalAlignment(HorizontalAlignment::Stretch);
    rowBtn.HorizontalContentAlignment(HorizontalAlignment::Stretch);
    rowBtn.Padding({0, 0, 0, 0});
    rowBtn.Margin({4, 2, 4, 2});
    rowBtn.CornerRadius({6, 6, 6, 6});
    rowBtn.BorderThickness({0, 0, 0, 0});
    rowBtn.Background(MakeBrush({0x00, 0x00, 0x00, 0x00}));
    rowBtn.Content(hoverBorder);

    std::wstring capturedId = info.id;
    rowBtn.Click([capturedId](auto const&, auto const&) {
        if (g_unloading) return;
        SpawnTrackedWorker([capturedId]() {
            winrt::init_apartment(winrt::apartment_type::multi_threaded);
            GlobalSystemMediaTransportControlsSession targetSession{nullptr};
            {
                GlobalSystemMediaTransportControlsSessionManager mgr{nullptr};
                {
                    std::lock_guard<std::mutex> lk(g_sessionMtx);
                    mgr = g_sessionMgr;
                }
                if (mgr) {
                    try {
                        auto sessions = mgr.GetSessions();
                        for (auto const& s : sessions) {
                            try {
                                if (std::wstring(s.SourceAppUserModelId()) == capturedId) {
                                    targetSession = s;
                                    std::lock_guard<std::mutex> lk(g_sessionMtx);
                                    g_userSwitchedSession = true;
                                    break;
                                }
                            } catch (...) {}
                        }
                    } catch (...) {}
                }
            }
            if (targetSession) {
                AttachToSession(targetSession);
            }
            winrt::uninit_apartment();
        });
    });

    ApplyFluentMediaButtonStyle(rowBtn);

    auto hBorderWeak  = winrt::make_weak(hoverBorder);
    auto brushSelected   = MakeBrush(SessionRowBackground(true, isLight));
    auto brushUnselected = MakeBrush(SessionRowBackground(false, isLight));
    auto brushHover       = MakeBrush(bgHover);
    auto brushPressed     = MakeBrush(bgPressed);
    auto restingBrush = [isCurrentFlag, brushSelected, brushUnselected]() {
        return *isCurrentFlag ? brushSelected : brushUnselected;
    };

    rowBtn.PointerEntered([hBorderWeak, brushHover, rowIndex](auto const&, auto const&) {
        g_miniSessionHoveredIndex = rowIndex;
        if (auto b = hBorderWeak.get()) b.Background(brushHover);
    });
    rowBtn.PointerExited([hBorderWeak, restingBrush, rowIndex](auto const&, auto const&) {
        if (g_miniSessionHoveredIndex == rowIndex) g_miniSessionHoveredIndex = -1;
        if (auto b = hBorderWeak.get()) b.Background(restingBrush());
    });
    rowBtn.AddHandler(UIElement::PointerPressedEvent(), winrt::box_value(
        winrt::Windows::UI::Xaml::Input::PointerEventHandler(
        [hBorderWeak, brushPressed](auto const& sender,
        winrt::Windows::UI::Xaml::Input::PointerRoutedEventArgs const& e) {
        if (auto elem = sender.template try_as<UIElement>()) elem.CapturePointer(e.Pointer());
        if (auto b = hBorderWeak.get()) b.Background(brushPressed);
    })), true);
    rowBtn.AddHandler(UIElement::PointerReleasedEvent(), winrt::box_value(
        winrt::Windows::UI::Xaml::Input::PointerEventHandler(
        [hBorderWeak, brushHover](auto const& sender,
        winrt::Windows::UI::Xaml::Input::PointerRoutedEventArgs const& e) {
        if (auto elem = sender.template try_as<UIElement>()) elem.ReleasePointerCapture(e.Pointer());
        if (auto b = hBorderWeak.get()) b.Background(brushHover);
    })), true);
    rowBtn.PointerCanceled([hBorderWeak, restingBrush, rowIndex](auto const&, auto const&) {
        if (g_miniSessionHoveredIndex == rowIndex) g_miniSessionHoveredIndex = -1;
        if (auto b = hBorderWeak.get()) b.Background(restingBrush());
    });
    rowBtn.PointerCaptureLost([hBorderWeak, restingBrush, rowIndex](auto const&, auto const&) {
        if (g_miniSessionHoveredIndex == rowIndex) g_miniSessionHoveredIndex = -1;
        if (auto b = hBorderWeak.get()) b.Background(restingBrush());
    });

    return rowBtn;
}

static void FetchMiniSessionInfosAsync(HWND taskbarWnd) {
    SpawnTrackedWorker([taskbarWnd]() {
        winrt::init_apartment(winrt::apartment_type::multi_threaded);
        std::vector<MiniSessionInfo> infos;
        GlobalSystemMediaTransportControlsSessionManager mgr{nullptr};
        {
            std::lock_guard<std::mutex> lk(g_sessionMtx);
            mgr = g_sessionMgr;
        }
        if (!mgr) { winrt::uninit_apartment(); return; }
        {
            try {
                auto sessions = mgr.GetSessions();
                for (auto const& s : sessions) {
                    try {
                        std::wstring sid = std::wstring(s.SourceAppUserModelId());
                        if (IsIgnoredMediaApp(sid)) continue;
                        MiniSessionInfo info;
                        info.id = sid;
                        try {
                            auto props = s.TryGetMediaPropertiesAsync().get();
                            if (props) {
                                info.title  = std::wstring(props.Title());
                                info.artist = std::wstring(props.Artist());
                                if (auto thumbRef = props.Thumbnail()) {
                                    try {
                                        auto stream = thumbRef.OpenReadAsync().get();
                                        if (stream) {
                                            UINT64 sz = stream.Size();
                                            if (sz > 0 && sz < 2 * 1024 * 1024) {
                                                DataReader reader(stream);
                                                reader.LoadAsync((UINT32)sz).get();
                                                info.thumbBytes.resize((size_t)sz);
                                                reader.ReadBytes(winrt::array_view<BYTE>(info.thumbBytes));
                                                reader.DetachStream();
                                            }
                                        }
                                    } catch (...) { info.thumbBytes.clear(); }
                                }
                            }
                        } catch (...) {}
                        if (info.title.empty() && info.artist.empty()) continue;
                        infos.push_back(std::move(info));
                    } catch (...) {}
                }
            } catch (...) {}
        }
        {
            std::lock_guard<std::mutex> lk(g_miniSessionMtx);
            g_miniSessionInfos = std::move(infos);
        }
        winrt::uninit_apartment();

        if (taskbarWnd) {
            RunFromWindowThread(taskbarWnd, [](void*) {
                if (!g_miniPlayerFlyoutOpen) return;
                RefreshMiniPlayerFlyoutUI();
            }, nullptr);
        }
    });
}

static Grid BuildMiniPlayerFlyoutContent() {
    Grid outer;
    outer.MinWidth(360);
    outer.MaxWidth(360);
    outer.MinHeight(400);

    Border bg;
    bg.CornerRadius({8, 8, 8, 8});
    bg.Padding({16, 16, 16, 16});
    bg.Margin({13, 13, 13, 13});

    bool isLight = IsSystemLightTheme();

    bg.BorderThickness({1, 1, 1, 1});
    bg.BorderBrush(MakeBrush(isLight
        ? winrt::Windows::UI::Color{0x30, 0x00, 0x00, 0x00}
        : winrt::Windows::UI::Color{0x30, 0xFF, 0xFF, 0xFF}));

    bg.Shadow(ThemeShadow());
    bg.Translation({0.f, 0.f, 32.f});

    AcrylicBrush flyoutContentBackground;
    flyoutContentBackground.BackgroundSource(AcrylicBackgroundSource::Backdrop);
    winrt::Windows::UI::Color tint = isLight
        ? winrt::Windows::UI::Color{0xff, 0xf2, 0xf2, 0xf2}
        : winrt::Windows::UI::Color{0xFF, 0x24, 0x24, 0x24};
    flyoutContentBackground.TintColor(tint);
    flyoutContentBackground.TintOpacity(isLight ? 0.0 : 0.5);
    flyoutContentBackground.TintLuminosityOpacity(isLight ? 0.9 : 0.96);
    flyoutContentBackground.FallbackColor(tint);

    StackPanel content;
    content.Orientation(Orientation::Vertical);
    content.HorizontalAlignment(HorizontalAlignment::Stretch);

    Border artBorder;
    artBorder.MaxWidth(300);
    artBorder.MinWidth(170);
    artBorder.Height(169);
    artBorder.HorizontalAlignment(HorizontalAlignment::Center);
    artBorder.CornerRadius({8, 8, 8, 8});
    artBorder.Background(MakeBrush({0x40, 0x80, 0x80, 0x80}));
    artBorder.Margin({0, 0, 0, 10});
    artBorder.BorderThickness({1, 1, 1, 1});
    artBorder.BorderBrush(MakeBrush(isLight
        ? winrt::Windows::UI::Color{0x30, 0x00, 0x00, 0x00}
        : winrt::Windows::UI::Color{0x30, 0xFF, 0xFF, 0xFF}));

    Grid artInnerGrid;
    artInnerGrid.HorizontalAlignment(HorizontalAlignment::Stretch);
    artInnerGrid.VerticalAlignment(VerticalAlignment::Stretch);
    {
        auto clipGeo = winrt::Windows::UI::Xaml::Media::RectangleGeometry();
        artInnerGrid.SizeChanged([clipGeo](
            winrt::Windows::Foundation::IInspectable const& sender,
            winrt::Windows::UI::Xaml::SizeChangedEventArgs const&) mutable {
                try {
                    if (auto fe = sender.try_as<FrameworkElement>()) {
                        clipGeo.Rect({0.f, 0.f,
                            (float)fe.ActualWidth(),
                            (float)fe.ActualHeight()});
                    }
                } catch (...) {}
            });
        artInnerGrid.Clip(clipGeo);
    }

    Controls::Image artImage;
    artImage.Stretch(Stretch::Uniform );
    artImage.HorizontalAlignment(HorizontalAlignment::Center);
    artImage.VerticalAlignment(VerticalAlignment::Center);
    artImage.Visibility(Visibility::Collapsed);
    g_miniPlayerCachedThumb.clear();
    artInnerGrid.Children().Append(artImage);
    artBorder.Child(artInnerGrid);
    content.Children().Append(artBorder);

    TextBlock titleBlock;
    titleBlock.FontSize(16);
    titleBlock.FontWeight(winrt::Windows::UI::Text::FontWeights::SemiBold());
    titleBlock.TextTrimming(TextTrimming::CharacterEllipsis);
    titleBlock.TextWrapping(TextWrapping::NoWrap);
    titleBlock.HorizontalAlignment(HorizontalAlignment::Center);
    titleBlock.TextAlignment(TextAlignment::Center);
    titleBlock.Foreground(MakeBrush(TextColor()));
    titleBlock.Margin({0, 0, 0, 4});
    content.Children().Append(titleBlock);

    TextBlock artistBlock;
    artistBlock.FontSize(13);
    artistBlock.TextTrimming(TextTrimming::CharacterEllipsis);
    artistBlock.TextWrapping(TextWrapping::NoWrap);
    artistBlock.HorizontalAlignment(HorizontalAlignment::Center);
    artistBlock.TextAlignment(TextAlignment::Center);
    artistBlock.Opacity(0.65);
    artistBlock.Foreground(MakeBrush(ArtistColor()));
    artistBlock.Margin({0, 0, 0, 5});
    content.Children().Append(artistBlock);

    StackPanel controlsRow;
    controlsRow.Orientation(Orientation::Horizontal);
    controlsRow.HorizontalAlignment(HorizontalAlignment::Center);
    controlsRow.Spacing(4);
    controlsRow.Margin({0, 10, 0, 10});

    auto iconClr = ButtonColor();

    auto MakeBigBtn = [&](int cmd) -> Button {
        Button btn;
        btn.Width(48);
        btn.Height(48);
        btn.Padding({1,1,1,1});
        btn.CornerRadius({4,4,4,4});
        btn.BorderThickness({0,0,0,0});
        btn.VerticalAlignment(VerticalAlignment::Center);
        btn.HorizontalAlignment(HorizontalAlignment::Center);

        const wchar_t* glyph = L"";
        if (cmd == kCmdPrevious) glyph = L"\uE622";
        else if (cmd == kCmdNext) glyph = L"\uE623";
        else if (cmd == kCmdToggleShuffle) glyph = L"\uE8B1";
        else if (cmd == kCmdCycleRepeat) glyph = RepeatModeGlyph(g_repeatMode.load());

        TextBlock iconText;
        iconText.Text(winrt::hstring(glyph));
        iconText.FontSize(16);
        iconText.FontFamily(Media::FontFamily(L"Segoe Fluent Icons"));
        iconText.Foreground(MakeBrush(iconClr));
        iconText.HorizontalAlignment(HorizontalAlignment::Center);
        iconText.VerticalAlignment(VerticalAlignment::Center);
        if (cmd == kCmdToggleShuffle) iconText.Opacity(g_shuffleEnabled.load() ? 1.0 : 0.40);
        if (cmd == kCmdCycleRepeat) iconText.Opacity(g_repeatMode.load() != RepeatMode::Off ? 1.0 : 0.40);
        btn.Content(winrt::box_value(iconText));
        SetButtonLabel(btn, MediaCommandLabel(cmd));

        btn.Click([cmd](auto const&, auto const&) {
            if (!g_unloading) {
                try {
                    SendMediaCommandAsync(cmd);
                    DispatchMediaUpdate();
                } catch (...) {}
            }
        });

        ApplyFluentMediaButtonStyle(btn);

        auto isHovered = std::make_shared<bool>(false);
        auto applyState = [weakBtn = winrt::make_weak(btn), isHovered](bool pressed) {
            try {
                if (auto b = weakBtn.get())
                    GoToCommonState(b, IsHoverEffectEnabled(g_settings.mediaButtonsHoverEffectMode), pressed, *isHovered);
            } catch (...) {}
        };
        
        RunWhenButtonReady(btn, [btn, applyState]() {
            try {
                SetupMediaButtonCommonStates(btn);
                applyState(false);
            } catch (...) {}
        });
        
        btn.PointerEntered([isHovered, applyState](auto const&, auto const&) {
            *isHovered = true;
            applyState(false);
        });
        btn.PointerExited([isHovered, applyState](auto const&, auto const&) {
            *isHovered = false;
            applyState(false);
        });
        btn.AddHandler(UIElement::PointerPressedEvent(), winrt::box_value(
            winrt::Windows::UI::Xaml::Input::PointerEventHandler(
            [applyState](auto const& sender, winrt::Windows::UI::Xaml::Input::PointerRoutedEventArgs const& e) {
            try {
                if (auto elem = sender.template try_as<UIElement>()) elem.CapturePointer(e.Pointer());
                applyState(true);
            } catch (...) {}
        })), true);
        btn.AddHandler(UIElement::PointerReleasedEvent(), winrt::box_value(
            winrt::Windows::UI::Xaml::Input::PointerEventHandler(
            [applyState](auto const& sender, winrt::Windows::UI::Xaml::Input::PointerRoutedEventArgs const& e) {
            try {
                if (auto elem = sender.template try_as<UIElement>()) elem.ReleasePointerCapture(e.Pointer());
                applyState(false);
            } catch (...) {}
        })), true);
        
        return btn;
    };

    Button shuffleBtn = MakeBigBtn(kCmdToggleShuffle);
    Button prevBtn    = MakeBigBtn(kCmdPrevious);
    Button playBtn    = MakeBigBtn(kCmdPlayPause);
    Button nextBtn    = MakeBigBtn(kCmdNext);
    Button repeatBtn  = MakeBigBtn(kCmdCycleRepeat);

    controlsRow.Children().Append(shuffleBtn);
    controlsRow.Children().Append(prevBtn);
    controlsRow.Children().Append(playBtn);
    controlsRow.Children().Append(nextBtn);
    controlsRow.Children().Append(repeatBtn);

    content.Children().Append(controlsRow);

    {
        Grid volumeRow;
        volumeRow.Margin({0, 6, 0, 2});
        volumeRow.Visibility(Visibility::Collapsed);
        ColumnDefinition volColMute;
        volColMute.Width(GridLengthHelper::FromValueAndType(1.0, GridUnitType::Auto));
        ColumnDefinition volColSlider;
        volColSlider.Width(GridLengthHelper::FromValueAndType(1.0, GridUnitType::Star));
        ColumnDefinition volColText;
        volColText.Width(GridLengthHelper::FromValueAndType(1.0, GridUnitType::Auto));
        volumeRow.ColumnDefinitions().Append(volColMute);
        volumeRow.ColumnDefinitions().Append(volColSlider);
        volumeRow.ColumnDefinitions().Append(volColText);

        Button muteBtn;
        muteBtn.Width(36);
        muteBtn.Height(36);
        muteBtn.Padding({0, 0, 0, 0});
        muteBtn.CornerRadius({6, 6, 6, 6});
        muteBtn.BorderThickness({0, 0, 0, 0});
        muteBtn.Background(MakeBrush({0x00, 0x00, 0x00, 0x00}));
        muteBtn.VerticalAlignment(VerticalAlignment::Center);
        {
            TextBlock icon;
            icon.Text(L"");
            icon.FontSize(16);
            icon.FontFamily(Media::FontFamily(L"Segoe Fluent Icons"));
            icon.Foreground(MakeBrush(isLight
                ? winrt::Windows::UI::Color{0xFF, 0x00, 0x00, 0x00}
                : winrt::Windows::UI::Color{0xFF, 0xFF, 0xFF, 0xFF}));
            icon.HorizontalAlignment(HorizontalAlignment::Center);
            icon.VerticalAlignment(VerticalAlignment::Center);
            muteBtn.Content(winrt::box_value(icon));
        }
        ApplyFluentMediaButtonStyle(muteBtn);
        RunWhenButtonReady(muteBtn, [muteBtn]() {
            try { SetupMediaButtonCommonStates(muteBtn); } catch (...) {}
        });
        muteBtn.Click([](auto const&, auto const&) {
            if (g_unloading) return;
            SendMediaCommandAsync(kCmdToggleMute);
        });
        Grid::SetColumn(muteBtn, 0);
        volumeRow.Children().Append(muteBtn);

        Controls::Slider volumeSlider;
        volumeSlider.Minimum(0.0);
        volumeSlider.Maximum(100.0);
        volumeSlider.StepFrequency(1.0);
        volumeSlider.Value(100.0);
        volumeSlider.Margin({8, 0, 8, 0});
        volumeSlider.VerticalAlignment(VerticalAlignment::Center);
        Automation::AutomationProperties::SetName(volumeSlider, L"App volume");
        volumeSlider.ValueChanged([](winrt::Windows::Foundation::IInspectable const&,
                                     Controls::Primitives::RangeBaseValueChangedEventArgs const& e) {
            if (g_unloading || g_miniPlayerVolumeSuppress) return;
            int percent = (int)std::lround(e.NewValue());
            QueueAppVolume(percent);
            if (g_miniPlayerVolumeTextRef) {
                try {
                    g_miniPlayerVolumeTextRef.Text(
                        winrt::hstring(std::to_wstring(percent) + L"%"));
                } catch (...) {}
            }
        });
        Grid::SetColumn(volumeSlider, 1);
        volumeRow.Children().Append(volumeSlider);

        TextBlock volumeText;
        volumeText.Text(L"100%");
        volumeText.FontSize(12);
        volumeText.MinWidth(38);
        volumeText.TextAlignment(winrt::Windows::UI::Xaml::TextAlignment::Right);
        volumeText.VerticalAlignment(VerticalAlignment::Center);
        volumeText.Opacity(0.75);
        volumeText.Foreground(MakeBrush(isLight
            ? winrt::Windows::UI::Color{0xFF, 0x00, 0x00, 0x00}
            : winrt::Windows::UI::Color{0xFF, 0xFF, 0xFF, 0xFF}));
        Grid::SetColumn(volumeText, 2);
        volumeRow.Children().Append(volumeText);

        g_miniPlayerVolumeRowRef    = volumeRow;
        g_miniPlayerMuteBtnRef      = muteBtn;
        g_miniPlayerVolumeSliderRef = volumeSlider;
        g_miniPlayerVolumeTextRef   = volumeText;
        content.Children().Append(volumeRow);
    }

    {
        Border sep;
        sep.Height(1);
        sep.Margin({-16, 0, -16, 0});
        sep.Background(MakeBrush(isLight
            ? winrt::Windows::UI::Color{0x20, 0x00, 0x00, 0x00}
            : winrt::Windows::UI::Color{0x20, 0xFF, 0xFF, 0xFF}));
        sep.Visibility(Visibility::Collapsed);
        g_miniPlayerSessionListSepRef = sep;
        content.Children().Append(sep);
    }

    if (!g_settings.hideMediaSessionsList) {
        StackPanel sessionList;
        sessionList.Orientation(Orientation::Vertical);
        sessionList.Spacing(0);
        sessionList.Margin({-16, 3, -16, 3});
        sessionList.Visibility(Visibility::Collapsed);
        g_miniPlayerSessionListRef = sessionList;
        content.Children().Append(sessionList);
    } else {
        g_miniPlayerSessionListRef = nullptr;
    }


    Grid innerGrid;
    innerGrid.VerticalAlignment(VerticalAlignment::Stretch);
    RowDefinition rowContent;
    rowContent.Height(GridLengthHelper::FromValueAndType(1.0, GridUnitType::Star));
    innerGrid.RowDefinitions().Append(rowContent);

    content.VerticalAlignment(VerticalAlignment::Top);
    Grid::SetRow(content, 0);

    Border contentBackground;
    contentBackground.Background(flyoutContentBackground);
    contentBackground.CornerRadius({8, 8, 8, 8});
    contentBackground.Margin({-16, -16, -16, -16});
    Grid::SetRow(contentBackground, 0);
    innerGrid.Children().Append(contentBackground);

    Border playerBackgroundOverlay;
    playerBackgroundOverlay.CornerRadius({8, 8, 8, 8});
    playerBackgroundOverlay.Margin({-16, -16, -16, -16});
    playerBackgroundOverlay.IsHitTestVisible(false);
    Grid::SetRow(playerBackgroundOverlay, 0);
    innerGrid.Children().Append(playerBackgroundOverlay);
    g_miniPlayerBgOverlayRef = playerBackgroundOverlay;

    innerGrid.Children().Append(content);

    bg.Child(innerGrid);
    outer.Children().Append(bg);

    outer.Opacity(0.0);
    outer.RenderTransform(CompositeTransform());

    g_miniPlayerArtRef       = artImage;
    g_miniPlayerTitleRef     = titleBlock;
    g_miniPlayerArtistRef    = artistBlock;
    g_miniPlayerPlayBtnRef   = playBtn;
    g_miniPlayerPrevBtnRef   = prevBtn;
    g_miniPlayerNextBtnRef   = nextBtn;
    g_miniPlayerShuffleBtnRef = shuffleBtn;
    g_miniPlayerRepeatBtnRef  = repeatBtn;

    return outer;
}

struct MiniPlayerAnchor {
    winrt::Windows::Foundation::Point placementPoint{0.f, 0.f};
    Controls::Primitives::FlyoutPlacementMode placement =
        Controls::Primitives::FlyoutPlacementMode::Top;
    bool   animHorizontal = false;
    double animSign = 1.0;
};

static bool GetTaskbarMonitorWorkAreaInfo(FrameworkElement const& rootContent,
                                          RECT& outWorkAreaPx,
                                          POINT& outOriginPx,
                                          double& outScale) {
    HWND hTaskbar = g_curTaskbarWnd ? g_curTaskbarWnd : g_taskbarWnd;
    if (!hTaskbar || !rootContent) return false;

    HMONITOR mon = MonitorFromWindow(hTaskbar, MONITOR_DEFAULTTONEAREST);
    if (!mon) return false;

    MONITORINFO mi{};
    mi.cbSize = sizeof(mi);
    if (!GetMonitorInfo(mon, &mi)) return false;
    outWorkAreaPx = mi.rcWork;

    POINT originPx{0, 0};
    if (!ClientToScreen(hTaskbar, &originPx)) return false;
    outOriginPx = originPx;

    double scale = 1.0;
    try {
        auto xamlRoot = rootContent.XamlRoot();
        if (xamlRoot) scale = xamlRoot.RasterizationScale();
    } catch (...) {}
    if (scale <= 0.0) scale = 1.0;
    outScale = scale;

    return true;
}

static bool ComputeScreenPlacementAnchor(FrameworkElement const& rootContent,
                                         MiniPlayerAnchor& outAnchor) {
    RECT workPx;
    POINT originPx;
    double scale;
    if (!GetTaskbarMonitorWorkAreaInfo(rootContent, workPx, originPx, scale)) {
        return false;
    }

    double left   = (workPx.left   - originPx.x) / scale;
    double top    = (workPx.top    - originPx.y) / scale;
    double right  = (workPx.right  - originPx.x) / scale;
    double bottom = (workPx.bottom - originPx.y) / scale;

    const std::wstring& hPlace = g_settings.miniPlayerHorizontalPlacement;
    const std::wstring& vPlace = g_settings.miniPlayerVerticalPlacement;
    int hDist = g_settings.miniPlayerHorizontalDistanceFromScreenEdge;
    int vDist = g_settings.miniPlayerVerticalDistanceFromScreenEdge;

    bool hLeft  = (hPlace == L"left");
    bool hRight = (hPlace == L"right");
    bool vTop   = (vPlace == L"top");
    bool vBottom = (vPlace == L"bottom");

    double anchorX;
    if (hLeft)       anchorX = left + hDist;
    else if (hRight) anchorX = right - hDist;
    else              anchorX = (left + right) / 2.0 + hDist;

    double anchorY;
    if (vTop)         anchorY = top + vDist;
    else if (vBottom) anchorY = bottom - vDist;
    else               anchorY = (top + bottom) / 2.0 + vDist;

    using FPM = Controls::Primitives::FlyoutPlacementMode;
    FPM placement;
    bool animHorizontal;
    double animSign;

    if (vBottom) {
        placement = hLeft ? FPM::TopEdgeAlignedLeft
                  : hRight ? FPM::TopEdgeAlignedRight
                  : FPM::Top;
        animHorizontal = false;
        animSign = 1.0;
    } else if (vTop) {
        placement = hLeft ? FPM::BottomEdgeAlignedLeft
                  : hRight ? FPM::BottomEdgeAlignedRight
                  : FPM::Bottom;
        animHorizontal = false;
        animSign = -1.0;
    } else {
        if (hLeft) {
            placement = FPM::Right;
            animHorizontal = true;
            animSign = -1.0;
        } else if (hRight) {
            placement = FPM::Left;
            animHorizontal = true;
            animSign = 1.0;
        } else {
            placement = FPM::Right;
            anchorX -= 180.0;
            animHorizontal = false;
            animSign = 1.0;
        }
    }

    if (g_settings.miniPlayerAnimation == L"top") {
        animHorizontal = false; animSign = -1.0;
    } else if (g_settings.miniPlayerAnimation == L"bottom") {
        animHorizontal = false; animSign = 1.0;
    } else if (g_settings.miniPlayerAnimation == L"left") {
        animHorizontal = true; animSign = -1.0;
    } else if (g_settings.miniPlayerAnimation == L"right") {
        animHorizontal = true; animSign = 1.0;
    }

    outAnchor.placementPoint = {(float)anchorX, (float)anchorY};
    outAnchor.placement = placement;
    outAnchor.animHorizontal = animHorizontal;
    outAnchor.animSign = animSign;
    return true;
}

static void ShowMiniPlayerFlyout(FrameworkElement const& target) {
    if (!target || g_unloading) return;
    try {

        if (g_miniPlayerFlyoutOpen && g_miniPlayerFlyout) {
            g_miniPlayerExplicitCloseRequested.store(true);
            g_miniPlayerFlyout.Hide();
            return;
        }

        Flyout flyout;
        Grid content = BuildMiniPlayerFlyoutContent();

        Grid clipHost;
        clipHost.HorizontalAlignment(HorizontalAlignment::Stretch);
        clipHost.VerticalAlignment(VerticalAlignment::Stretch);
        clipHost.Children().Append(content);
        flyout.Content(clipHost);

        Style flyoutStyle(winrt::xaml_typename<Controls::FlyoutPresenter>());
        flyoutStyle.Setters().Append(Setter(
            Controls::Control::BackgroundProperty(),
            winrt::box_value(winrt::Windows::UI::Xaml::Media::SolidColorBrush{
                winrt::Windows::UI::Colors::Transparent()})));
        flyoutStyle.Setters().Append(Setter(
            FrameworkElement::MarginProperty(),
            winrt::box_value(Thickness{0, 0, 0, 0})));
        flyoutStyle.Setters().Append(Setter(
            Controls::Control::PaddingProperty(),
            winrt::box_value(Thickness{0, 0, 0, 0})));
        flyoutStyle.Setters().Append(Setter(
            Controls::Control::BorderThicknessProperty(),
            winrt::box_value(Thickness{0, 0, 0, 0})));
        flyoutStyle.Setters().Append(Setter(
            Controls::Control::BorderBrushProperty(),
            winrt::box_value(winrt::Windows::UI::Xaml::Media::SolidColorBrush{
                winrt::Windows::UI::Colors::Transparent()})));
        flyoutStyle.Setters().Append(Setter(
            FrameworkElement::MaxWidthProperty(),
            winrt::box_value(10000.0)));
        flyoutStyle.Setters().Append(Setter(
            FrameworkElement::MaxHeightProperty(),
            winrt::box_value(10000.0)));
        flyout.FlyoutPresenterStyle(flyoutStyle);

        flyout.Opened([content](auto const&, auto const&) {
            g_miniPlayerFlyoutOpen = true;
            g_miniPlayerClosingAnimStarted.store(false);
            if (g_playerButtonStateUpdater) g_playerButtonStateUpdater();
            g_miniSessionHoveredIndex = -1;
            {
                std::lock_guard<std::mutex> lk(g_miniSessionMtx);
                g_miniSessionInfos.clear();
            }
            RefreshMiniPlayerFlyoutUI();
            if (!g_settings.hideMediaSessionsList) {
                FetchMiniSessionInfosAsync(g_taskbarWnd);
            }

            try {
                Controls::FlyoutPresenter presenter{nullptr};
                {
                    auto node = content.as<winrt::Windows::UI::Xaml::DependencyObject>();
                    for (int i = 0; i < 12 && node; ++i) {
                        if (auto p = node.try_as<Controls::FlyoutPresenter>()) {
                            presenter = p;
                            break;
                        }
                        node = VisualTreeHelper::GetParent(node);
                    }
                }
                if (presenter) {
                    int childCount = VisualTreeHelper::GetChildrenCount(presenter);
                    for (int i = 0; i < childCount; ++i) {
                        auto child = VisualTreeHelper::GetChild(presenter, i);
                        if (auto border = child.try_as<Controls::Border>()) {
                            border.Shadow(nullptr);
                            break;
                        }
                    }
                }
            } catch (...) {
                Wh_Log(L"Flyout.Opened: Exception removing Shadow");
            }

            auto transform = content.RenderTransform().as<winrt::Windows::UI::Xaml::Media::CompositeTransform>();

            auto fired = std::make_shared<bool>(false);
            auto doReveal = [content, transform, fired]() mutable {
                if (*fired) return;
                *fired = true;
                try {
                    bool horizontal = g_miniPlayerAnimHorizontal;
                    double startOffset = 48.0 * g_miniPlayerAnimSign;

                    PCWSTR propertyPath = horizontal
                        ? L"(UIElement.RenderTransform).(CompositeTransform.TranslateX)"
                        : L"(UIElement.RenderTransform).(CompositeTransform.TranslateY)";

                    if (horizontal) transform.TranslateX(startOffset);
                    else            transform.TranslateY(startOffset);

                    using namespace winrt::Windows::UI::Xaml::Media::Animation;
                    Storyboard sb;
                    DoubleAnimation anim;
                    anim.From(startOffset);
                    anim.To(0.0);
                    anim.Duration(winrt::Windows::UI::Xaml::DurationHelper::FromTimeSpan(
                        std::chrono::milliseconds(300)));
                    auto ease = ExponentialEase();
                    ease.Exponent(5.0);
                    ease.EasingMode(EasingMode::EaseOut);
                    anim.EasingFunction(ease);
                    Storyboard::SetTarget(anim, content);
                    Storyboard::SetTargetProperty(anim, propertyPath);
                    sb.Children().Append(anim);

                    DoubleAnimation fade;
                    fade.From(0.0);
                    fade.To(1.0);
                    fade.Duration(winrt::Windows::UI::Xaml::DurationHelper::FromTimeSpan(
                        std::chrono::milliseconds(170)));
                    auto fadeEase = ExponentialEase();
                    fadeEase.Exponent(3.0);
                    fadeEase.EasingMode(EasingMode::EaseOut);
                    fade.EasingFunction(fadeEase);
                    Storyboard::SetTarget(fade, content);
                    Storyboard::SetTargetProperty(fade, L"Opacity");
                    sb.Children().Append(fade);

                    sb.Begin();
                } catch (...) {
                    try { content.Opacity(1.0); } catch (...) {}
                }
            };

            auto token = std::make_shared<winrt::event_token>();
            *token = content.SizeChanged([content, token, doReveal](
                winrt::Windows::Foundation::IInspectable const&,
                winrt::Windows::UI::Xaml::SizeChangedEventArgs const&) mutable
            {
                try { content.SizeChanged(*token); } catch (...) {}
                doReveal();
            });

            auto fallbackTimer = DispatcherTimer();
            fallbackTimer.Interval(
                winrt::Windows::Foundation::TimeSpan{std::chrono::milliseconds(80)});
            auto fallbackToken = std::make_shared<winrt::event_token>();
            *fallbackToken = fallbackTimer.Tick([fallbackTimer, fallbackToken, doReveal](
                winrt::Windows::Foundation::IInspectable const&,
                winrt::Windows::Foundation::IInspectable const&) mutable
            {
                try { fallbackTimer.Stop(); } catch (...) {}
                fallbackTimer.Tick(*fallbackToken);
                doReveal();
            });
            fallbackTimer.Start();
        });

        flyout.Closing([content](
            winrt::Windows::UI::Xaml::Controls::Primitives::FlyoutBase const& sender,
            winrt::Windows::UI::Xaml::Controls::Primitives::FlyoutBaseClosingEventArgs const& e)
        {
            if (g_unloading || g_applyingSettings) return;

            if (g_miniPlayerClosingAnimInProgress.exchange(false)) return;

            bool explicitClose = g_miniPlayerExplicitCloseRequested.exchange(false);

            if (g_settings.keepMiniPlayerOpen && !explicitClose) {
                e.Cancel(true);
                return;
            }

            if (g_miniPlayerClosingAnimStarted.load()) {
                e.Cancel(true);
                return;
            }

            try {
                e.Cancel(true);

                bool horizontal = g_miniPlayerAnimHorizontal;
                double endOffset = 40.0 * g_miniPlayerAnimSign;

                PCWSTR propertyPath = horizontal
                    ? L"(UIElement.RenderTransform).(CompositeTransform.TranslateX)"
                    : L"(UIElement.RenderTransform).(CompositeTransform.TranslateY)";

                using namespace winrt::Windows::UI::Xaml::Media::Animation;
                Storyboard sb;
                DoubleAnimation anim;
                anim.To(endOffset);
                anim.Duration(winrt::Windows::UI::Xaml::DurationHelper::FromTimeSpan(
                    std::chrono::milliseconds(180)));
                auto ease = ExponentialEase();
                ease.Exponent(4.0);
                ease.EasingMode(EasingMode::EaseIn);
                anim.EasingFunction(ease);
                Storyboard::SetTarget(anim, content);
                Storyboard::SetTargetProperty(anim, propertyPath);
                sb.Children().Append(anim);

                DoubleAnimation fade;
                fade.To(0.0);
                fade.Duration(winrt::Windows::UI::Xaml::DurationHelper::FromTimeSpan(
                    std::chrono::milliseconds(150)));
                auto fadeEase = ExponentialEase();
                fadeEase.Exponent(3.0);
                fadeEase.EasingMode(EasingMode::EaseIn);
                fade.EasingFunction(fadeEase);
                Storyboard::SetTarget(fade, content);
                Storyboard::SetTargetProperty(fade, L"Opacity");
                sb.Children().Append(fade);
                g_miniPlayerClosingAnimStarted.store(true);
                auto doHide = [sender]() {
                    g_miniPlayerClosingAnimStarted.store(false);
                    try {
                        g_miniPlayerClosingAnimInProgress.store(true);
                        sender.Hide();
                    } catch (...) {
                        g_miniPlayerClosingAnimInProgress.store(false);
                    }
                };
                sb.Completed([doHide](auto const&, auto const&) { doHide(); });
                auto closingFallback = DispatcherTimer();
                closingFallback.Interval(winrt::Windows::Foundation::TimeSpan{
                    std::chrono::milliseconds(350)});
                auto closingFallbackToken = std::make_shared<winrt::event_token>();
                *closingFallbackToken = closingFallback.Tick(
                    [closingFallback, closingFallbackToken, doHide](
                        winrt::Windows::Foundation::IInspectable const&,
                        winrt::Windows::Foundation::IInspectable const&) mutable {
                        try { closingFallback.Stop(); } catch (...) {}
                        closingFallback.Tick(*closingFallbackToken);
                        if (g_miniPlayerClosingAnimStarted.load())
                            doHide();
                    });
                closingFallback.Start();
                sb.Begin();
            } catch (...) {
                g_miniPlayerClosingAnimStarted.store(false);
            }
        });

        flyout.Closed([](auto const&, auto const&) {
            g_miniPlayerFlyoutOpen = false;
            g_miniPlayerClosingAnimStarted.store(false);
            g_miniSessionHoveredIndex = -1;
            ClearMiniPlayerRefs();
            g_miniPlayerFlyout = nullptr;
            g_miniSessionCachedThumbSizes.clear();
            g_miniSessionRowIds.clear();
            if (g_playerButtonStateUpdater) g_playerButtonStateUpdater();
        });


        bool useScreenPlacement = (g_settings.miniPlayerPlacementMode == L"screen");
        Controls::Primitives::FlyoutPlacementMode placementMode =
            Controls::Primitives::FlyoutPlacementMode::Top;
        winrt::Windows::Foundation::Point anchorPoint{0.f, 0.f};
        FrameworkElement showAtElem = target;
        bool anchorComputed = false;

        try {
            auto xamlRoot = target.XamlRoot();
            if (xamlRoot) {
                auto rootContent = xamlRoot.Content().try_as<FrameworkElement>();
                if (rootContent) {
                    showAtElem = rootContent;

                    try {
                        flyout.OverlayInputPassThroughElement(rootContent);
                    } catch (...) {}

                    if (useScreenPlacement) {
                        MiniPlayerAnchor screenAnchor;
                        if (ComputeScreenPlacementAnchor(rootContent, screenAnchor)) {
                            anchorPoint = screenAnchor.placementPoint;
                            placementMode = screenAnchor.placement;
                            g_miniPlayerAnimHorizontal = screenAnchor.animHorizontal;
                            g_miniPlayerAnimSign = screenAnchor.animSign;
                            anchorComputed = true;
                        } else {
                            Wh_Log(L"ShowMiniPlayerFlyout: Failed to compute screen anchor, "
                                   L"falling back to 'over the player' placement");
                        }
                    }

                    if (!anchorComputed) {
                        auto xform = target.TransformToVisual(rootContent);
                        auto pt = xform.TransformPoint({0.f, 0.f});
                        float cx = pt.X + (float)target.ActualWidth() * 0.5f +
                                   (float)g_settings.miniPlayerHorizontalOffsetNear;

                        bool placeBelow = (g_settings.miniPlayerVerticalPlacementNear == L"bottom");
                        if (placeBelow) {
                            float ty = pt.Y + (float)target.ActualHeight();
                            anchorPoint = {cx, ty};
                            placementMode = Controls::Primitives::FlyoutPlacementMode::Bottom;
                            g_miniPlayerAnimHorizontal = false;
                            g_miniPlayerAnimSign = -1.0;
                        } else {
                            float ty = pt.Y;
                            anchorPoint = {cx, ty};
                            placementMode = Controls::Primitives::FlyoutPlacementMode::Top;
                            g_miniPlayerAnimHorizontal = false;
                            g_miniPlayerAnimSign = 1.0;
                        }
                    }
                }
            }
        } catch (...) {
            Wh_Log(L"ShowMiniPlayerFlyout: Exception setting position");
        }

        try {
            flyout.ShouldConstrainToRootBounds(false);
        } catch (...) {}

        g_miniPlayerFlyout = flyout;


        Controls::Primitives::FlyoutShowOptions opts;
        opts.Placement(placementMode);
        opts.Position(anchorPoint);

        flyout.ShowAt(showAtElem, opts);

    } catch (...) {
        Wh_Log(L"ShowMiniPlayerFlyout: Exception in main try block");
    }
}

struct DoubleClickTracker {
    ULONGLONG time = 0;
    winrt::Windows::UI::Input::PointerUpdateKind kind = winrt::Windows::UI::Input::PointerUpdateKind::Other;
    winrt::Windows::Foundation::Point pos{};
    bool Register(winrt::Windows::UI::Input::PointerUpdateKind k, winrt::Windows::Foundation::Point p) {
        ULONGLONG now = GetTickCount64();
        bool isDouble = k == kind &&
                        now - time <= GetDoubleClickTime() &&
                        std::abs(p.X - pos.X) <= GetSystemMetrics(SM_CXDOUBLECLK) / 2.0 &&
                        std::abs(p.Y - pos.Y) <= GetSystemMetrics(SM_CYDOUBLECLK) / 2.0;
        time = isDouble ? 0 : now;
        kind = k;
        pos = p;
        return isDouble;
    }
};
static void HandleWheelAction(std::wstring const& action, PointerRoutedEventArgs const& e) {
    if (g_unloading) return;
    if (action == L"none") return;
    int delta = e.GetCurrentPoint(nullptr).Properties().MouseWheelDelta();
    if (action == L"switch_tracks") {
        if (delta > 0) SendMediaCommandAsync(kCmdPrevious);
        else if (delta < 0) SendMediaCommandAsync(kCmdNext);
        DispatchMediaUpdate();
    } else if (action == L"switch_tracks_inverted") {
        if (delta > 0) SendMediaCommandAsync(kCmdNext);
        else if (delta < 0) SendMediaCommandAsync(kCmdPrevious);
        DispatchMediaUpdate();
    } else if (action == L"switch_sessions") {
        if (delta != 0) SwitchMediaSession();
    } else if (action == L"system_sound") {
        SpawnTrackedWorker([delta]() { ChangeSystemVolume(delta > 0); });
    } else if (action == L"app_sound" || action == L"app_sound_inverted") {
        bool up = (action == L"app_sound") ? (delta > 0) : (delta < 0);
        SendMediaCommandAsync(up ? kCmdVolumeUp : kCmdVolumeDown);
    }
    e.Handled(true);
}
static TextBlock MakeTrackTextBlock(const wchar_t* name, int size, std::wstring const& font,
                                    std::wstring const& weight, std::wstring const& style,
                                    int spacing, winrt::Windows::UI::Color color) {
    TextBlock block;
    block.Name(name);
    block.FontSize((double)size);
    if (!font.empty()) {
        try {
            block.FontFamily(Media::FontFamily(font));
        } catch (...) {}
    }
    if (!weight.empty()) {
        try {
            block.FontWeight(Markup::XamlBindingHelper::ConvertValue(
                winrt::Windows::UI::Xaml::Interop::TypeName{
                    winrt::hstring{L"Windows.UI.Text.FontWeight"},
                    winrt::Windows::UI::Xaml::Interop::TypeKind::Metadata
                },
                winrt::box_value(weight))
                .as<winrt::Windows::UI::Text::FontWeight>());
        } catch (...) {}
    }
    if (!style.empty()) {
        try {
            block.FontStyle(Markup::XamlBindingHelper::ConvertValue(
                winrt::Windows::UI::Xaml::Interop::TypeName{
                    winrt::hstring{L"Windows.UI.Text.FontStyle"},
                    winrt::Windows::UI::Xaml::Interop::TypeKind::Metadata
                },
                winrt::box_value(style))
                .as<winrt::Windows::UI::Text::FontStyle>());
        } catch (...) {}
    }
    if (spacing != 0) {
        block.CharacterSpacing(spacing);
    }
    block.Foreground(MakeBrush(color));
    block.TextWrapping(TextWrapping::NoWrap);
    block.TextTrimming(TextTrimming::CharacterEllipsis);
    block.TextAlignment(g_settings.mirrorLayout ? TextAlignment::Right : TextAlignment::Left);
    return block;
}
static Grid BuildPlayerGrid() {
    try {
        g_vizBars->clear();
        g_vizBrushes->clear();
        auto buttonClr = ButtonColor();
        double phMin = (double)g_settings.playerMinHeight;
        double phMax = (double)g_settings.playerMaxHeight;
        bool hasTextOrButtons = g_settings.showTrackTitle || g_settings.showTrackArtist || (g_settings.showMediaButtons && !g_mediaButtons.empty());
        Border backgroundBorder;
        backgroundBorder.Name(kBackgroundName);
        backgroundBorder.CornerRadius({
            g_settings.cornerRadiusTL,
            g_settings.cornerRadiusTR,
            g_settings.cornerRadiusBR,
            g_settings.cornerRadiusBL
        });
        backgroundBorder.HorizontalAlignment(HorizontalAlignment::Stretch);
        backgroundBorder.VerticalAlignment(VerticalAlignment::Stretch);
        backgroundBorder.IsHitTestVisible(false);
        backgroundBorder.Visibility(Visibility::Collapsed);
        if (phMin > 0) {
            backgroundBorder.MinHeight(phMin);
        }
        if (phMax > 0) {
            backgroundBorder.MaxHeight(phMax);
        }
        Button playerButton;
        playerButton.Name(L"FluentMedia_OuterBorder");
        playerButton.CornerRadius({
            g_settings.cornerRadiusTL,
            g_settings.cornerRadiusTR,
            g_settings.cornerRadiusBR,
            g_settings.cornerRadiusBL
        });
        playerButton.BorderThickness({0, 0, 0, 0});
        playerButton.UseSystemFocusVisuals(false);
        playerButton.IsHitTestVisible(false);
        playerButton.HorizontalAlignment(HorizontalAlignment::Stretch);
        playerButton.VerticalAlignment(VerticalAlignment::Stretch);
        if (phMin > 0) {
            playerButton.MinHeight(phMin);
        }
        if (phMax > 0) {
            playerButton.MaxHeight(phMax);
        }
        Grid chromeFill;
        if (phMin > 0) {
            chromeFill.MinHeight(phMin);
        }
        if (phMax > 0) {
            chromeFill.MaxHeight(phMax);
        }
        chromeFill.IsHitTestVisible(false);
        playerButton.Content(chromeFill);
        Grid panel;
        panel.Name(kPanelGridName);
        panel.VerticalAlignment(VerticalAlignment::Center);
        panel.HorizontalAlignment(HorizontalAlignment::Stretch);
        if (hasTextOrButtons) {
            panel.Margin({4, 2, 4, 2});
        }
        bool buttonsLeft = g_settings.mirrorLayout;
        bool albumArtLeft = !g_settings.mirrorLayout;
        bool hasText = g_settings.showTrackTitle || g_settings.showTrackArtist;
        ColumnDefinition colFirst, colText, colLast;
        colFirst.Width({1.0, GridUnitType::Auto});
        if (hasText) {
            colText.Width({1.0, GridUnitType::Star});
        } else {
            colText.Width({0.0, GridUnitType::Pixel});
        }
        colLast.Width({1.0, GridUnitType::Auto});
        panel.ColumnDefinitions().Append(colFirst);
        panel.ColumnDefinitions().Append(colText);
        panel.ColumnDefinitions().Append(colLast);
        Grid artContainer{nullptr};
        if (g_settings.showAlbumArt) {
            int iconSz = g_settings.appIconSize;
            artContainer = Grid();
            artContainer.Name(kArtContainerName);
            artContainer.VerticalAlignment(VerticalAlignment::Center);
            artContainer.HorizontalAlignment(HorizontalAlignment::Center);
            if (g_settings.albumArtMinWidth > 0) {
                artContainer.MinWidth((double)g_settings.albumArtMinWidth);
            }
            if (g_settings.albumArtMaxWidth > 0) {
                artContainer.MaxWidth((double)g_settings.albumArtMaxWidth);
            }
            if (g_settings.albumArtMinHeight > 0) {
                artContainer.MinHeight((double)g_settings.albumArtMinHeight);
            }
            if (g_settings.albumArtMaxHeight > 0) {
                artContainer.MaxHeight((double)g_settings.albumArtMaxHeight);
            }
            double artLeftMargin = (double)g_settings.albumArtLeftMargin;
            double artRightMargin = (double)g_settings.albumArtRightMargin;
            artContainer.Margin({artLeftMargin, 0, artRightMargin, 0});
            artContainer.Opacity(g_settings.albumArtOpacity / 100.0);
            artContainer.Background(MakeBrush({0x00,0x00,0x00,0x00}));
            winrt::Windows::UI::Xaml::Shapes::Rectangle placeholder;
            placeholder.Fill(MakeBrush({0x40,0x80,0x80,0x80}));
            double maxRadius = std::max({g_settings.albumArtCornerRadiusTL, g_settings.albumArtCornerRadiusTR,
                                        g_settings.albumArtCornerRadiusBR, g_settings.albumArtCornerRadiusBL});
            placeholder.RadiusX(maxRadius);
            placeholder.RadiusY(maxRadius);
            placeholder.HorizontalAlignment(HorizontalAlignment::Stretch);
            placeholder.VerticalAlignment(VerticalAlignment::Stretch);
            artContainer.Children().Append(placeholder);
            Border artBorder;
            artBorder.CornerRadius({
                g_settings.albumArtCornerRadiusTL,
                g_settings.albumArtCornerRadiusTR,
                g_settings.albumArtCornerRadiusBR,
                g_settings.albumArtCornerRadiusBL
            });
            artBorder.HorizontalAlignment(HorizontalAlignment::Stretch);
            artBorder.VerticalAlignment(VerticalAlignment::Stretch);
            Controls::Image artImage;
            artImage.Name(kArtImageName);
            artImage.Stretch(Stretch::Uniform);
            artImage.HorizontalAlignment(HorizontalAlignment::Center);
            artImage.VerticalAlignment(VerticalAlignment::Center);
            Grid artInnerGrid;
            artInnerGrid.HorizontalAlignment(HorizontalAlignment::Stretch);
            artInnerGrid.VerticalAlignment(VerticalAlignment::Stretch);
            artInnerGrid.Children().Append(artImage);
            {
                auto clipGeo = winrt::Windows::UI::Xaml::Media::RectangleGeometry();
                artInnerGrid.Clip(clipGeo);
                artInnerGrid.SizeChanged([clipGeo](
                    winrt::Windows::Foundation::IInspectable const& sender,
                    winrt::Windows::UI::Xaml::SizeChangedEventArgs const&) mutable {
                        try {
                            if (auto fe = sender.try_as<FrameworkElement>()) {
                                clipGeo.Rect({0, 0,
                                    (float)fe.ActualWidth(),
                                    (float)fe.ActualHeight()});
                            }
                        } catch (...) {}
                    });
            }
            artBorder.Child(artInnerGrid);
            artContainer.Children().Append(artBorder);
            Border artRing;
            artRing.CornerRadius({
                g_settings.albumArtCornerRadiusTL,
                g_settings.albumArtCornerRadiusTR,
                g_settings.albumArtCornerRadiusBR,
                g_settings.albumArtCornerRadiusBL
            });
            artRing.BorderThickness({1,1,1,1});
            artRing.BorderBrush(MakeBrush({0x25,0x80,0x80,0x80}));
            artContainer.Children().Append(artRing);
            if (g_settings.showAppIcon) {
                Grid iconOverlay;
                iconOverlay.VerticalAlignment(VerticalAlignment::Stretch);
                iconOverlay.HorizontalAlignment(HorizontalAlignment::Stretch);
                Controls::Image appIconImage;
                appIconImage.Name(kAppIconImageName);
                appIconImage.Width(iconSz);
                appIconImage.Height(iconSz);
                appIconImage.Stretch(Stretch::UniformToFill);
                appIconImage.Visibility(Visibility::Collapsed);
                const auto& corner = g_settings.appIconCorner;
                appIconImage.HorizontalAlignment(corner == L"top_left" || corner == L"bottom_left" ? HorizontalAlignment::Left : HorizontalAlignment::Right);
                appIconImage.VerticalAlignment(corner == L"top_left" || corner == L"top_right" ? VerticalAlignment::Top : VerticalAlignment::Bottom);
                iconOverlay.Children().Append(appIconImage);
                Canvas::SetZIndex(iconOverlay, 15);
                artContainer.Children().Append(iconOverlay);
            }
            if (g_settings.showPauseOverlay) {
                Border pauseBorder;
                pauseBorder.Name(kPauseOverlayName);
                pauseBorder.HorizontalAlignment(HorizontalAlignment::Stretch);
                pauseBorder.VerticalAlignment(VerticalAlignment::Stretch);
                BYTE opacity = (BYTE)((g_settings.pauseOverlayOpacity * 255) / 100);
                pauseBorder.Background(MakeBrush({opacity, 0x00, 0x00, 0x00}));
                pauseBorder.Visibility(Visibility::Collapsed);
                Canvas::SetZIndex(pauseBorder, 8);
                TextBlock pauseIcon;
                pauseIcon.Foreground(MakeBrush({0xFF, 0xFF, 0xFF, 0xFF}));
                pauseIcon.HorizontalAlignment(HorizontalAlignment::Center);
                pauseIcon.VerticalAlignment(VerticalAlignment::Center);
                pauseBorder.Child(pauseIcon);
                artInnerGrid.Children().Append(pauseBorder);
            }
            if (g_settings.disableAlbumArtClick) {
                artContainer.IsHitTestVisible(false);
            } else {
                artContainer.PointerPressed([](auto const& sender, winrt::Windows::UI::Xaml::Input::PointerRoutedEventArgs const& e) mutable {
                    if (auto elem = sender.template try_as<UIElement>()) {
                        elem.CapturePointer(e.Pointer());
                    }
                    e.Handled(true);
                });
                auto artDoubleClick = std::make_shared<DoubleClickTracker>();
                auto pendingAlbumArtClick = MakePendingPointerAction();
                artContainer.PointerReleased([artDoubleClick, pendingAlbumArtClick](auto const& sender, winrt::Windows::UI::Xaml::Input::PointerRoutedEventArgs const& e) mutable {
                    bool actuallyHovered = false;
                    if (auto elem = sender.template try_as<UIElement>()) {
                        elem.ReleasePointerCapture(e.Pointer());
                        actuallyHovered = IsPointerInside(e, elem);
                    }
                    if (g_unloading) return;
                    if (actuallyHovered) {
                        auto point = e.GetCurrentPoint(nullptr);
                        auto kind = point.Properties().PointerUpdateKind();
                        auto fe = sender.template try_as<FrameworkElement>();
                        bool isDouble = artDoubleClick->Register(kind, point.Position());
                        using Kind = winrt::Windows::UI::Input::PointerUpdateKind;
                        if (kind == Kind::LeftButtonReleased) {
                            RunPointerAction(pendingAlbumArtClick, fe, g_settings.albumArtLeftClick,
                                             g_settings.albumArtLeftDoubleClick, isDouble, true,
                                             g_settings.playerLeftDoubleClick != L"none");
                        } else if (kind == Kind::RightButtonReleased) {
                            RunPointerAction(pendingAlbumArtClick, fe, g_settings.albumArtRightClick,
                                             g_settings.albumArtRightDoubleClick, isDouble, true,
                                             g_settings.playerRightDoubleClick != L"none");
                        } else if (kind == Kind::MiddleButtonReleased) {
                            RunPointerAction(pendingAlbumArtClick, fe, g_settings.albumArtMiddleClick,
                                             g_settings.albumArtMiddleDoubleClick, isDouble, true,
                                             g_settings.playerMiddleDoubleClick != L"none");
                        }
                    }
                    e.Handled(true);
                });
                artContainer.Unloaded([pendingAlbumArtClick](auto const&, auto const&) {
                    CancelPendingPointerAction(pendingAlbumArtClick);
                });
                artContainer.PointerWheelChanged([](auto const&, PointerRoutedEventArgs const& e) {
                    HandleWheelAction(g_settings.albumArtWheelAction, e);
                });
            }
            if (albumArtLeft) {
                Grid::SetColumn(artContainer, 0);
            } else {
                Grid::SetColumn(artContainer, 2);
            }
            panel.Children().Append(artContainer);
        }
        if (hasText) {
            Border textContainer;
            textContainer.VerticalAlignment(VerticalAlignment::Center);
            if (albumArtLeft) {
                textContainer.HorizontalAlignment(HorizontalAlignment::Left);
            } else {
                textContainer.HorizontalAlignment(HorizontalAlignment::Right);
            }
            if (g_settings.textAreaMinWidth > 0) {
                textContainer.MinWidth((double)g_settings.textAreaMinWidth);
            }
            if (g_settings.textAreaMaxWidth > 0) {
                textContainer.MaxWidth((double)g_settings.textAreaMaxWidth);
            }
            if (g_settings.textAreaMinHeight > 0) {
                textContainer.MinHeight((double)g_settings.textAreaMinHeight);
            }
            if (g_settings.textAreaMaxHeight > 0) {
                textContainer.MaxHeight((double)g_settings.textAreaMaxHeight);
            }
            textContainer.Margin({(double)g_settings.textAreaLeftMargin, 0, (double)g_settings.textAreaRightMargin, 0});
            StackPanel textStack;
            textStack.Name(kTextStackName);
            textStack.Orientation(Orientation::Vertical);
            textStack.VerticalAlignment(VerticalAlignment::Center);
            if (g_settings.enableTitleScrolling || g_settings.enableArtistScrolling) {
                textStack.HorizontalAlignment(HorizontalAlignment::Stretch);
            } else {
                textStack.HorizontalAlignment(g_settings.mirrorLayout ? HorizontalAlignment::Right : HorizontalAlignment::Left);
            }
            textStack.Spacing((double)g_settings.textSpacing);
            TextBlock titleBlock{nullptr};
            TextBlock artistBlock{nullptr};
            if (g_settings.showTrackTitle) {
                titleBlock = MakeTrackTextBlock(
                    kTitleBlockName, g_settings.titleFontSize,
                    g_settings.titleFont.empty() ? g_settings.titleFontFamily : g_settings.titleFont,
                    g_settings.titleFontWeight, g_settings.titleFontStyle,
                    g_settings.titleCharacterSpacing, TextColor());
            }
            if (g_settings.showTrackArtist) {
                artistBlock = MakeTrackTextBlock(
                    kArtistBlockName, g_settings.artistFontSize,
                    g_settings.artistFont.empty() ? g_settings.artistFontFamily : g_settings.artistFont,
                    g_settings.artistFontWeight, g_settings.artistFontStyle,
                    g_settings.artistCharacterSpacing, ArtistColor());
            }
            auto MakeScrollView = [](TextBlock const& block, const wchar_t* viewName, const wchar_t* cloneName) {
                Canvas scrollView;
                scrollView.Name(viewName);
                scrollView.VerticalAlignment(VerticalAlignment::Center);
                scrollView.HorizontalAlignment(g_settings.mirrorLayout ? HorizontalAlignment::Right : HorizontalAlignment::Left);
                scrollView.Width(100.0);
                block.TextTrimming(TextTrimming::None);
                Canvas::SetLeft(block, 0.0);
                Canvas::SetTop(block, 0.0);
                scrollView.Children().Append(block);
                if (g_settings.scrollMode == L"loop") {
                    TextBlock clone;
                    clone.Name(cloneName);
                    clone.Text(block.Text());
                    clone.FontSize(block.FontSize());
                    clone.FontFamily(block.FontFamily());
                    clone.FontWeight(block.FontWeight());
                    clone.FontStyle(block.FontStyle());
                    clone.CharacterSpacing(block.CharacterSpacing());
                    clone.Foreground(block.Foreground());
                    clone.TextWrapping(TextWrapping::NoWrap);
                    clone.TextTrimming(TextTrimming::None);
                    clone.TextAlignment(block.TextAlignment());
                    Canvas::SetLeft(clone, 9999.0);
                    Canvas::SetTop(clone, 0.0);
                    scrollView.Children().Append(clone);
                }
                auto geo = winrt::Windows::UI::Xaml::Media::RectangleGeometry();
                scrollView.Clip(geo);
                block.SizeChanged([scrollView, geo](winrt::Windows::Foundation::IInspectable const&, SizeChangedEventArgs const& e) mutable {
                    try {
                        double h = e.NewSize().Height;
                        if (h < 1.0) h = 16.0;
                        double w = scrollView.Width();
                        scrollView.Height(h);
                        geo.Rect({0, 0, (float)w, (float)h});
                    } catch (...) {}
                });
                return scrollView;
            };
            auto appendTrackText = [&](TextBlock const& block, bool scrolls, bool otherScrolls, const wchar_t* viewName, const wchar_t* cloneName) {
                if (!block) return;
                if (scrolls) {
                    textStack.Children().Append(MakeScrollView(block, viewName, cloneName));
                } else {
                    if (otherScrolls && g_settings.textAreaMaxWidth > 0) {
                        block.MaxWidth((double)g_settings.textAreaMaxWidth);
                    }
                    textStack.Children().Append(block);
                }
            };
            if (g_settings.swapTitleArtist) {
                appendTrackText(artistBlock, g_settings.enableArtistScrolling, g_settings.enableTitleScrolling, kArtistScrollViewName, kArtistCloneName);
                appendTrackText(titleBlock, g_settings.enableTitleScrolling, g_settings.enableArtistScrolling, kTitleScrollViewName, kTitleCloneName);
            } else {
                appendTrackText(titleBlock, g_settings.enableTitleScrolling, g_settings.enableArtistScrolling, kTitleScrollViewName, kTitleCloneName);
                appendTrackText(artistBlock, g_settings.enableArtistScrolling, g_settings.enableTitleScrolling, kArtistScrollViewName, kArtistCloneName);
            }
            textContainer.Child(textStack);
            Grid::SetColumn(textContainer, 1);
            panel.Children().Append(textContainer);
        }
        if (g_settings.showMediaButtons) {
            StackPanel ctrlPanel;
            ctrlPanel.Name(kControlsPanelName);
            ctrlPanel.Orientation(Orientation::Horizontal);
            ctrlPanel.Spacing((double)g_settings.buttonSpacing);
            ctrlPanel.VerticalAlignment(VerticalAlignment::Center);
            ctrlPanel.HorizontalAlignment(buttonsLeft ? HorizontalAlignment::Left : HorizontalAlignment::Right);
            std::vector<MediaButtonConfig> currentButtons;
            {
                std::lock_guard<std::mutex> lock(g_mediaButtonsMutex);
                currentButtons = g_mediaButtons;
            }
            bool hasButtons = !currentButtons.empty();
            if (hasButtons) {
                try {
                    ctrlPanel.Margin({(double)g_settings.mediaButtonsLeftMargin, 0, (double)g_settings.mediaButtonsRightMargin, 0});
                } catch (...) {
                    Wh_Log(L"BuildPlayerGrid: Exception setting control panel margin");
                }
            }
            for (size_t i = 0; i < currentButtons.size(); i++) {
                try {
                    const auto& btnCfg = currentButtons[i];
                    auto btn = MakeControlButton(btnCfg.cmd, false, buttonClr);
                    switch (btnCfg.type) {
                        case MediaButtonType::Previous:
                            btn.Name(kPrevBtnName);
                            break;
                        case MediaButtonType::PlayPause:
                            btn.Name(kPlayBtnName);
                            break;
                        case MediaButtonType::Next:
                            btn.Name(kNextBtnName);
                            break;
                        case MediaButtonType::Rewind:
                            btn.Name(kRewindBtnName);
                            break;
                        case MediaButtonType::Forward:
                            btn.Name(kForwardBtnName);
                            break;
                        case MediaButtonType::Shuffle:
                            btn.Name(kShuffleBtnName);
                            break;
                        case MediaButtonType::Repeat:
                            btn.Name(kRepeatBtnName);
                            break;
                        case MediaButtonType::SwitchSessions:
                            btn.Name(kSwitchSessionsBtnName);
                            break;
                    }
                    ctrlPanel.Children().Append(btn);
                } catch (const winrt::hresult_error& e) {
                    Wh_Log(L"BuildPlayerGrid: WinRT exception creating button %zu: 0x%08X", i, static_cast<uint32_t>(e.code()));
                } catch (...) {
                    Wh_Log(L"BuildPlayerGrid: Unknown exception creating button %zu, skipping", i);
                }
            }
            if (buttonsLeft) {
                Grid::SetColumn(ctrlPanel, 0);
            } else {
                Grid::SetColumn(ctrlPanel, 2);
            }
            if (hasButtons) {
                panel.Children().Append(ctrlPanel);
            }
        }
        if (g_settings.vizEnabled) {
            try {
                auto vizEl = BuildVisualizerElement();
                if (vizEl) {
                    bool left = (g_settings.vizPosition == L"left");
                    if (g_settings.mirrorLayout) left = !left;
                    ColumnDefinition vcol;
                    vcol.Width({1.0, GridUnitType::Auto});
                    if (left) {
                        panel.ColumnDefinitions().InsertAt(0, vcol);
                        auto kids = panel.Children();
                        for (uint32_t k = 0; k < kids.Size(); k++) {
                            if (auto fe = kids.GetAt(k).try_as<FrameworkElement>())
                                Grid::SetColumn(fe, Grid::GetColumn(fe) + 1);
                        }
                        Grid::SetColumn(vizEl, 0);
                    } else {
                        panel.ColumnDefinitions().Append(vcol);
                        Grid::SetColumn(vizEl, (int)panel.ColumnDefinitions().Size() - 1);
                    }
                    panel.Children().Append(vizEl);
                }
            } catch (...) {
                Wh_Log(L"BuildPlayerGrid: Exception adding inline visualizer");
            }
        }
        Grid wrapper;
        wrapper.Name(kGridName);
        wrapper.VerticalAlignment(g_settings.fullHeightHitArea ? VerticalAlignment::Stretch : VerticalAlignment::Center);
        wrapper.HorizontalAlignment(HorizontalAlignment::Left);
        try {
            if (g_settings.enableSmoothPositionAnimation) {
                TransitionCollection transitions;
                RepositionThemeTransition marginTransition;
                transitions.Append(marginTransition);
                wrapper.Transitions(transitions);
            }
        } catch (...) {}
        if (hasTextOrButtons && g_settings.playerMinWidth > 0) {
            wrapper.MinWidth((double)g_settings.playerMinWidth);
        }
        if (g_settings.playerMaxWidth > 0) {
            wrapper.MaxWidth((double)g_settings.playerMaxWidth);
        }

        wrapper.Background(MakeBrush({0x00, 0, 0, 0}));

        Canvas::SetZIndex(backgroundBorder, 0);
        Canvas::SetZIndex(playerButton, 1);    
        Canvas::SetZIndex(panel, 2);           
        wrapper.Children().Append(backgroundBorder);
        wrapper.Children().Append(playerButton);
        wrapper.Children().Append(panel);
        ApplyFluentMediaButtonStyle(playerButton);
        playerButton.BorderThickness({1, 1, 1, 1});
        auto isPressed = std::make_shared<bool>(false);
        auto isHovered = std::make_shared<bool>(false);
        auto playerNormalBg = MakeBackgroundBrush();
        auto updatePlayerVisualState = [playerButton, playerNormalBg, isPressed, isHovered]() {
            bool hovered = *isHovered || g_miniPlayerFlyoutOpen;
            ApplyPlayerButtonState(playerButton, playerNormalBg, hovered, *isPressed);
        };
        g_playerButtonStateUpdater = updatePlayerVisualState;
        RunWhenButtonReady(playerButton, [playerButton, playerNormalBg]() {
            try {
                SetupPlayerCommonStates(playerButton, playerNormalBg);
                GoToCommonState(playerButton, IsHoverEffectEnabled(g_settings.playerHoverEffectMode), false, false);
            } catch (...) {}
        });
    wrapper.PointerEntered([isHovered, updatePlayerVisualState](auto const&, auto const&) mutable {
        *isHovered = true;
        updatePlayerVisualState();
    });
    wrapper.PointerExited([isHovered, updatePlayerVisualState](auto const& sender, PointerRoutedEventArgs const& e) mutable {
        if (auto elem = sender.template try_as<UIElement>(); elem && IsPointerInside(e, elem)) return;
        *isHovered = false;
        updatePlayerVisualState();
    });
    wrapper.PointerPressed([isPressed, updatePlayerVisualState](auto const& sender, winrt::Windows::UI::Xaml::Input::PointerRoutedEventArgs const& e) mutable {
        if (auto elem = sender.template try_as<UIElement>()) {
            elem.CapturePointer(e.Pointer());
        }
        *isPressed = true;
        updatePlayerVisualState();
    });
    auto wrapperDoubleClick = std::make_shared<DoubleClickTracker>();
    auto pendingPlayerClick = MakePendingPointerAction();
    wrapper.AddHandler(UIElement::PointerReleasedEvent(), winrt::box_value(
        winrt::Windows::UI::Xaml::Input::PointerEventHandler(
        [isPressed, isHovered, updatePlayerVisualState, wrapperDoubleClick, pendingPlayerClick](auto const& sender, winrt::Windows::UI::Xaml::Input::PointerRoutedEventArgs const& e) mutable {
        bool wasHandled = e.Handled();
        *isPressed = false;
        bool actuallyHovered = false;
        if (auto elem = sender.template try_as<UIElement>()) {
            elem.ReleasePointerCapture(e.Pointer());
            actuallyHovered = IsPointerInside(e, elem);
        }
        *isHovered = actuallyHovered;
        updatePlayerVisualState();
        if (g_unloading) return;
        bool handledByAlbumArt =
            wasHandled && HasNamedVisualAncestor(e.OriginalSource(), kArtContainerName);
        if (wasHandled && !handledByAlbumArt) return;
        if (actuallyHovered) {
            auto point = e.GetCurrentPoint(nullptr);
            auto kind = point.Properties().PointerUpdateKind();
            auto fe = sender.template try_as<FrameworkElement>();
            bool isDouble = wrapperDoubleClick->Register(kind, point.Position());
            using Kind = winrt::Windows::UI::Input::PointerUpdateKind;
            if (kind == Kind::LeftButtonReleased) {
                if (!handledByAlbumArt || g_settings.albumArtLeftDoubleClick == L"none") {
                    RunPointerAction(pendingPlayerClick, fe, g_settings.playerLeftClick,
                                     g_settings.playerLeftDoubleClick, isDouble, !wasHandled);
                }
            } else if (kind == Kind::RightButtonReleased) {
                if (!handledByAlbumArt || g_settings.albumArtRightDoubleClick == L"none") {
                    RunPointerAction(pendingPlayerClick, fe, g_settings.playerRightClick,
                                     g_settings.playerRightDoubleClick, isDouble, !wasHandled);
                }
            } else if (kind == Kind::MiddleButtonReleased) {
                if (!handledByAlbumArt || g_settings.albumArtMiddleDoubleClick == L"none") {
                    RunPointerAction(pendingPlayerClick, fe, g_settings.playerMiddleClick,
                                     g_settings.playerMiddleDoubleClick, isDouble, !wasHandled);
                }
            }
        }
    })), true);
    wrapper.PointerCanceled([isPressed, isHovered, updatePlayerVisualState](auto const&, auto const&) mutable {
        *isPressed = false;
        *isHovered = false;
        updatePlayerVisualState();
    });
    wrapper.Unloaded([pendingPlayerClick](auto const&, auto const&) {
        CancelPendingPointerAction(pendingPlayerClick);
    });
    wrapper.PointerCaptureLost([isPressed, isHovered, updatePlayerVisualState](auto const& sender, winrt::Windows::UI::Xaml::Input::PointerRoutedEventArgs const& e) mutable {
        *isPressed = false;
        if (auto elem = sender.template try_as<UIElement>()) {
            *isHovered = IsPointerInside(e, elem);
        }
        updatePlayerVisualState();
    });
        wrapper.PointerWheelChanged([](auto const&, PointerRoutedEventArgs const& e) {
            HandleWheelAction(g_settings.playerWheelAction, e);
        });
        try {
            winrt::Windows::UI::Xaml::Interop::TypeName gridType;
            gridType.Name = L"Windows.UI.Xaml.Controls.Grid";
            gridType.Kind = winrt::Windows::UI::Xaml::Interop::TypeKind::Metadata;
            winrt::Windows::UI::Xaml::Style wrapperStyle(gridType);
            wrapper.Style(wrapperStyle);
        } catch (...) {}
        try {
            ToolTip tt;
            TextBlock ttText;
            ttText.TextWrapping(TextWrapping::Wrap);
            ttText.MaxWidth(300);
            tt.Content(ttText);
            ToolTipService::SetToolTip(wrapper, tt);
            g_playerToolTip = tt;
        } catch (...) {}
        return wrapper;
    } catch (...) {
        Wh_Log(L"BuildPlayerGrid: Exception occurred");
        return nullptr;
    }
}
struct InjectionTarget {
    FrameworkElement parent{nullptr};
    int insertAt = 0;
};
static void RemovePlayerGridChildren(Panel const& targetPanel) {
    if (!targetPanel) return;
    for (int i = (int)targetPanel.Children().Size() - 1; i >= 0; --i) {
        auto fe = targetPanel.Children().GetAt(i).try_as<FrameworkElement>();
        if (fe && fe.Name() == kGridName) {
            try { targetPanel.Children().RemoveAt(i); } catch (...) {}
        }
    }
}
static const wchar_t* const kStartButtonNames[] = {
    L"StartButton",
    L"StartMenuButton",
    L"StartMenuLaunchButton", 
    L"LaunchListButton",
};
static Grid FindTaskbarRootGrid(FrameworkElement const& root) {
    FrameworkElement taskbarFrame = nullptr;
    int count = VisualTreeHelper::GetChildrenCount(root);
    for (int i = 0; i < count; i++) {
        auto c = VisualTreeHelper::GetChild(root, i).try_as<FrameworkElement>();
        if (c) {
            auto className = winrt::get_class_name(c);
            if (className == L"Taskbar.TaskbarFrame") {
                taskbarFrame = c;
                break;
            }
        }
    }
    if (!taskbarFrame) {
        return nullptr;
    }
    auto rootGrid = FindChildByName(taskbarFrame, L"RootGrid");
    return rootGrid ? rootGrid.try_as<Grid>() : nullptr;
}
static FrameworkElement FindElementInRepeater(FrameworkElement const& repeater, const wchar_t* const* names, int nameCount) {
    if (!repeater) return nullptr;
    int childCount = VisualTreeHelper::GetChildrenCount(repeater);
    for (int i = 0; i < childCount; i++) {
        auto child = VisualTreeHelper::GetChild(repeater, i).try_as<FrameworkElement>();
        if (!child) continue;
        for (int j = 0; j < nameCount; j++) {
            if (child.Name() == names[j]) return child;
        }
    }
    for (int i = 0; i < childCount; i++) {
        auto child = VisualTreeHelper::GetChild(repeater, i).try_as<FrameworkElement>();
        if (!child) continue;
        int subChildCount = VisualTreeHelper::GetChildrenCount(child);
        for (int k = 0; k < subChildCount; k++) {
            auto subChild = VisualTreeHelper::GetChild(child, k).try_as<FrameworkElement>();
            if (!subChild) continue;
            for (int j = 0; j < nameCount; j++) {
                if (subChild.Name() == names[j]) return subChild;
            }
        }
    }
    return nullptr;
}
static FrameworkElement FindNthElementByClassName(FrameworkElement const& parent, const wchar_t* className, int index) {
    if (!parent) return nullptr;
    int foundCount = 0;
    int childCount = VisualTreeHelper::GetChildrenCount(parent);
    for (int i = 0; i < childCount; i++) {
        auto child = VisualTreeHelper::GetChild(parent, i).try_as<FrameworkElement>();
        if (!child) continue;
        auto childClassName = winrt::get_class_name(child);
        if (childClassName == className) {
            if (foundCount == index) return child;
            foundCount++;
        }
    }
    return nullptr;
}
static FrameworkElement FindChildByClassName(FrameworkElement const& parent, const wchar_t* className, int depth = 32) {
    if (!parent || depth <= 0) return nullptr;
    int childCount = VisualTreeHelper::GetChildrenCount(parent);
    for (int i = 0; i < childCount; i++) {
        auto child = VisualTreeHelper::GetChild(parent, i).try_as<FrameworkElement>();
        if (!child) continue;
        if (winrt::get_class_name(child) == className) return child;
        if (auto found = FindChildByClassName(child, className, depth - 1)) return found;
    }
    return nullptr;
}
static FrameworkElement FindTrayElement(FrameworkElement const& trayGrid, FrameworkElement const& root, const wchar_t* name) {
    auto elem = FindChildByName(trayGrid, name);
    if (!elem) elem = FindChildByName(root, name);
    return elem;
}
static FrameworkElement FindDirectPanelChild(Panel const& panel, FrameworkElement element) {
    if (!panel || !element) return nullptr;
    DependencyObject current = element;
    while (current) {
        auto parent = VisualTreeHelper::GetParent(current);
        if (!parent) return nullptr;
        if (parent == panel) return current.try_as<FrameworkElement>();
        current = parent;
    }
    return nullptr;
}
static int FindPanelChildIndex(Panel const& panel, FrameworkElement element) {
    auto directChild = FindDirectPanelChild(panel, element);
    if (!directChild) return -1;
    for (uint32_t i = 0; i < panel.Children().Size(); ++i) {
        if (panel.Children().GetAt(i) == directChild) return (int)i;
    }
    return -1;
}
static int FindTrayInsertionPoint(Panel const& trayPanel,
                                  FrameworkElement const& root,
                                  const wchar_t* anchorName,
                                  bool after) {
    auto anchor = FindTrayElement(trayPanel, root, anchorName);
    auto directChild = FindDirectPanelChild(trayPanel, anchor);
    if (!directChild) return -1;
    int position = -1;
    if (auto trayGrid = trayPanel.try_as<Grid>()) {
        position = Grid::GetColumn(directChild);
    } else {
        position = FindPanelChildIndex(trayPanel, directChild);
    }
    return position < 0 ? -1 : position + (after ? 1 : 0);
}
static bool IsTaskbarEdgePosition(std::wstring_view p) {
    return p == L"taskbar_left_edge" ||
           p == L"taskbar_center_edge" ||
           p == L"taskbar_right_edge";
}
static bool IsTaskbarTrackingPosition(std::wstring_view p) {
    return p == L"taskbar_left_start" ||
           p == L"taskbar_right_start" ||
           p == L"taskbar_after_search_left" ||
           p == L"taskbar_after_search_right" ||
           p == L"taskbar_after_taskview_left" ||
           p == L"taskbar_after_taskview_right" ||
           p == L"taskbar_after_widgets_left" ||
           p == L"taskbar_after_widgets_right";
}
static InjectionTarget ResolveInjectionTarget(
    FrameworkElement const& root,
    std::wstring_view position)
{
    auto trayFrame = FindChildByName(root, L"SystemTrayFrameGrid");
    if (auto trayPanel = trayFrame ? trayFrame.try_as<Panel>() : nullptr) {
        int insertAt = -1;
        if      (position == L"tray_right")
            insertAt = trayPanel.try_as<Grid>()
                ? (int)trayPanel.as<Grid>().ColumnDefinitions().Size()
                : (int)trayPanel.Children().Size();
        else if (position == L"tray_left")
            insertAt = 0;
        else if (position == L"tray_before_clock") {
            insertAt = FindTrayInsertionPoint(
                trayPanel, root, L"NotificationCenterButton", false);
        }
        else if (position == L"tray_after_clock") {
            insertAt = FindTrayInsertionPoint(
                trayPanel, root, L"ShowDesktopStack", false);
            if (insertAt < 0) {
                insertAt = FindTrayInsertionPoint(
                    trayPanel, root, L"NotificationCenterButton", true);
            }
        }
        else if (position == L"tray_before_omni_left") {
            insertAt = FindTrayInsertionPoint(
                trayPanel, root, L"ControlCenterButton", false);
        }
        else if (position == L"tray_before_omni_right") {
            insertAt = FindTrayInsertionPoint(
                trayPanel, root, L"ControlCenterButton", true);
        }
        else if (position == L"tray_language_left") {
            insertAt = FindTrayInsertionPoint(
                trayPanel, root, L"NonActivatableStack", false);
        }
        else if (position == L"tray_language_right") {
            insertAt = FindTrayInsertionPoint(
                trayPanel, root, L"NonActivatableStack", true);
        }
        else if (position == L"tray_hidden_icons_left") {
            insertAt = FindTrayInsertionPoint(
                trayPanel, root, L"NotifyIconStack", false);
        }
        else if (position == L"tray_hidden_icons_right") {
            insertAt = FindTrayInsertionPoint(
                trayPanel, root, L"NotifyIconStack", true);
        }
        else if (position == L"tray_icons_left") {
            insertAt = FindTrayInsertionPoint(
                trayPanel, root, L"NotificationAreaIcons", false);
        }
        else if (position == L"tray_icons_right") {
            insertAt = FindTrayInsertionPoint(
                trayPanel, root, L"NotificationAreaIcons", true);
        }
        else if (position == L"tray_after_showdesktop_left") {
            insertAt = FindTrayInsertionPoint(
                trayPanel, root, L"ShowDesktopStack", false);
        }
        else if (position == L"tray_after_showdesktop_right") {
            insertAt = FindTrayInsertionPoint(
                trayPanel, root, L"ShowDesktopStack", true);
            if (insertAt < 0) insertAt = trayPanel.try_as<Grid>() ? (int)trayPanel.as<Grid>().ColumnDefinitions().Size() : (int)trayPanel.Children().Size();
        }
        if (insertAt >= 0) {
            return {trayPanel, insertAt};
        }
    }
    if (IsTaskbarEdgePosition(position) || IsTaskbarTrackingPosition(position))
    {
        auto rootGrid = FindTaskbarRootGrid(root);
        if (!rootGrid) {
            auto tf2 = FindChildByName(root, L"SystemTrayFrameGrid");
            if (auto tg2 = tf2 ? tf2.try_as<Grid>() : nullptr)
                return {tg2, (int)tg2.ColumnDefinitions().Size()};
            return {};
        }
        return {rootGrid, -1};
    }
    return {};
}
static bool InjectPlayerGridIntoTaskbar(HWND hWnd) {
    g_curTaskbarWnd = hWnd;
    try {
        auto xamlRoot = GetTaskbarXamlRoot(hWnd);
        if (!xamlRoot) {
            Wh_Log(L"InjectPlayerGrid: Failed to get XAML root");
            return false;
        }
        auto root = xamlRoot.Content().try_as<FrameworkElement>();
        if (!root) {
            Wh_Log(L"InjectPlayerGrid: Failed to get root FrameworkElement");
            return false;
        }
        if (g_settings.enableTreeDump) {
            DumpXamlTree(root, 0, 5);
            auto rootGrid = FindTaskbarRootGrid(root);
            if (rootGrid) {
                auto repeater = FindChildByName(rootGrid, L"TaskbarFrameRepeater");
                if (repeater) {
                    DumpXamlTree(repeater, 0, 3);
                }
            }
        }
        auto [targetParent, insertAt] = ResolveInjectionTarget(root, g_settings.position);
        if (!targetParent) {
            if (g_settings.enableTreeDump) {
                DumpXamlTree(root, 0, 8);
            }
            return false;
        }
        Grid playerGrid = BuildPlayerGrid();
        if (!playerGrid) return false;
        auto targetPanel = targetParent.try_as<Panel>();
        auto targetGrid = targetParent.try_as<Grid>();
        bool isTrayPanel = (targetParent.Name() == L"SystemTrayFrameGrid");
        RemovePlayerGridChildren(targetPanel);
        if (isTrayPanel) {
            playerGrid.Margin({(double)g_settings.playerMarginLeft, 0,
                            (double)g_settings.playerMarginRight, 0});
            if (targetGrid) {
                ColumnDefinition newCol;
                newCol.Width({1.0, GridUnitType::Auto});
                if (insertAt >= (int)targetGrid.ColumnDefinitions().Size()) {
                    targetGrid.ColumnDefinitions().Append(newCol);
                } else {
                    targetGrid.ColumnDefinitions().InsertAt(insertAt, newCol);
                    for (uint32_t i = 0; i < targetGrid.Children().Size(); ++i) {
                        auto child = targetGrid.Children().GetAt(i).try_as<FrameworkElement>();
                        if (child) {
                            int childCol = Grid::GetColumn(child);
                            if (childCol >= insertAt)
                                Grid::SetColumn(child, childCol + 1);
                        }
                    }
                }
                Grid::SetColumn(playerGrid, insertAt);
                targetGrid.Children().Append(playerGrid);
                g_playerColumn = insertAt;
            } else {
                uint32_t childIndex = (uint32_t)std::clamp(
                    insertAt, 0, (int)targetPanel.Children().Size());
                targetPanel.Children().InsertAt(childIndex, playerGrid);
                g_playerColumn = -1;
            }
        }
        else {
            auto repeater  = FindChildByName(targetGrid, L"TaskbarFrameRepeater");
            auto trayFrame = FindChildByName(targetGrid, L"SystemTrayFrameGrid");
            double leftMargin  = (double)g_settings.playerMarginLeft;
            double rightMargin = (double)g_settings.playerMarginRight;
            playerGrid.HorizontalAlignment(HorizontalAlignment::Left);
            if (IsTaskbarEdgePosition(g_settings.position)) {
                if (g_settings.position == L"taskbar_center_edge") {
                    playerGrid.HorizontalAlignment(HorizontalAlignment::Center);
                }
                else if (g_settings.position == L"taskbar_right_edge") {
                    playerGrid.HorizontalAlignment(HorizontalAlignment::Right);
                    if (trayFrame) rightMargin += trayFrame.ActualWidth() + 4;
                }
                playerGrid.Margin({leftMargin, 0, rightMargin, 0});
            } else {
                FrameworkElement targetElem = nullptr;
                std::wstring trackSide = L"right";
                if (repeater) {
                    if (g_settings.position == L"taskbar_left_start") {
                        targetElem = FindElementInRepeater(repeater, kStartButtonNames, ARRAYSIZE(kStartButtonNames));
                        trackSide = L"left";
                    } else if (g_settings.position == L"taskbar_right_start") {
                        targetElem = FindElementInRepeater(repeater, kStartButtonNames, ARRAYSIZE(kStartButtonNames));
                        trackSide = L"right";
                    } else if (g_settings.position == L"taskbar_after_search_left") {
                        targetElem = FindNthElementByClassName(repeater, L"Taskbar.TaskbarExtensionElement", 0);
                        trackSide = L"left";
                    } else if (g_settings.position == L"taskbar_after_search_right") {
                        targetElem = FindNthElementByClassName(repeater, L"Taskbar.TaskbarExtensionElement", 0);
                        trackSide = L"right";
                    } else if (g_settings.position == L"taskbar_after_taskview_left") {
                        targetElem = FindNthElementByClassName(repeater, L"Taskbar.ExperienceToggleButton", 1);
                        trackSide = L"left";
                    } else if (g_settings.position == L"taskbar_after_taskview_right") {
                        targetElem = FindNthElementByClassName(repeater, L"Taskbar.ExperienceToggleButton", 1);
                        trackSide = L"right";
                    } else if (g_settings.position == L"taskbar_after_widgets_left") {
                        targetElem = FindChildByName(repeater, L"AugmentedEntryPointButton");
                        if (!targetElem) targetElem = FindChildByClassName(repeater, L"Taskbar.AugmentedEntryPointButton");
                        trackSide = L"left";
                    } else if (g_settings.position == L"taskbar_after_widgets_right") {
                        targetElem = FindChildByName(repeater, L"AugmentedEntryPointButton");
                        if (!targetElem) targetElem = FindChildByClassName(repeater, L"Taskbar.AugmentedEntryPointButton");
                        trackSide = L"right";
                    }
                }
                if (targetElem) {
                    g_trackedElement = targetElem;
                    g_trackedElementOriginalMargin = targetElem.Margin();
                    g_trackPosition = trackSide;
                    auto startButton = FindElementInRepeater(repeater, kStartButtonNames, 1);
                    double startButtonOffset =
                        (startButton && startButton.Margin().Right < -10.0 &&
                         (g_settings.position == L"taskbar_left_start" ||
                          g_settings.position == L"taskbar_right_start" ||
                          g_settings.position == L"taskbar_after_taskview_left" ||
                          g_settings.position == L"taskbar_after_taskview_right"))
                            ? startButton.ActualWidth() : 0.0;
                    PlayerInstanceState* owner = g_currentInstance;
                    g_layoutUpdateToken = targetGrid.LayoutUpdated(
                        [targetGrid, startButtonOffset, owner](winrt::Windows::Foundation::IInspectable const&, winrt::Windows::Foundation::IInspectable const&) {
                            if (!IsLivePlayerInstance(owner)) return;
                            WithPlayerInstance(owner, [&]() {
                            try {
                                if (!g_playerGrid || !g_trackedElement || g_unloading) return;
                                bool isVisible = (g_playerGrid.Visibility() == Visibility::Visible);
                                double w = isVisible ? g_playerGrid.ActualWidth() : 0.0;
                                double desiredGap = isVisible ? (w + g_settings.playerMarginLeft + g_settings.playerMarginRight) : 0.0;
                                auto m = g_trackedElementOriginalMargin;
                                auto currentMargin = g_trackedElement.Margin();
                                bool changedMargin = false;
                                if (g_trackPosition == L"left") {
                                    double target = isVisible ? desiredGap : g_trackedElementOriginalMargin.Left;
                                    if (std::abs(currentMargin.Left - target) > 1.0) { m.Left = target; changedMargin = true; }
                                } else {
                                    double target = isVisible ? desiredGap : g_trackedElementOriginalMargin.Right;
                                    if (std::abs(currentMargin.Right - target) > 1.0) { m.Right = target; changedMargin = true; }
                                }
                                if (changedMargin) g_trackedElement.Margin(m);
                                if (isVisible) {
                                    try {
                                        auto transform = g_trackedElement.TransformToVisual(targetGrid);
                                        auto point = transform.TransformPoint({0, 0});
                                        double leftPos = g_trackPosition == L"left"
                                            ? point.X - desiredGap + g_settings.playerMarginLeft + startButtonOffset
                                            : point.X + g_trackedElement.ActualWidth() + g_settings.playerMarginLeft;
                                        auto pm = g_playerGrid.Margin();
                                        if (std::abs(pm.Left - leftPos) > 1.0) {
                                            g_playerGrid.Margin({leftPos, 0, 0, 0});
                                        }
                                    } catch (...) {}
                                }
                            } catch (...) {
                                g_trackedElement = nullptr;
                            }
                            });
                        }
                    );
                } else {
                    playerGrid.Margin({leftMargin, 0, rightMargin, 0});
                }
            }
            Grid::SetColumn(playerGrid, 0);
            Canvas::SetZIndex(playerGrid, 1000);
            targetGrid.Children().Append(playerGrid);
            g_playerColumn = -1;
        }
        g_playerGrid      = playerGrid;
        g_injectionParent = targetParent;
        {
            PlayerInstanceState* owner = g_currentInstance;
            winrt::Windows::UI::Xaml::Input::PointerEventHandler select(
                [owner](winrt::Windows::Foundation::IInspectable const&,
                        winrt::Windows::UI::Xaml::Input::PointerRoutedEventArgs const&) {
                    if (IsLivePlayerInstance(owner)) SetCurrentPlayerInstance(owner);
                });
            playerGrid.AddHandler(UIElement::PointerEnteredEvent(),
                                  winrt::box_value(select), true);
            playerGrid.AddHandler(UIElement::PointerPressedEvent(),
                                  winrt::box_value(select), true);
        }
        RefreshPlayerContentsInstance();
        g_playerGrid.Visibility(Visibility::Visible);
        g_playerGrid.UpdateLayout();
        if (g_injectionParent) {
            g_injectionParent.UpdateLayout();
        }
        if (g_playerGrid.ActualWidth() == 0.0 && g_playerGrid.ActualHeight() == 0.0) {
            g_needsUiUpdate = true;
            if (g_timerUpdateEvent) SetEvent(g_timerUpdateEvent);
        }
        auto dispatcher = g_playerGrid.Dispatcher();
        if (dispatcher) {
            try {
                dispatcher.RunAsync(winrt::Windows::UI::Core::CoreDispatcherPriority::Low, [=]() {
                    if (!g_unloading) RefreshThemeColors();
                });
            } catch (...) {
                Wh_Log(L"InjectPlayerGrid: Failed to dispatch RefreshThemeColors");
            }
        }
        Canvas::SetZIndex(g_playerGrid, 1000);
        g_needsUiUpdate = true;
        return true;
    } catch (...) {
        Wh_Log(L"InjectPlayerGrid: Exception during injection");
        return false;
    }
}
static std::vector<HWND> CollectTargetTaskbarWnds() {
    std::vector<HWND> result;
    if (!g_settings.showOnAllMonitors) {
        if (g_taskbarWnd) result.push_back(g_taskbarWnd);
        return result;
    }
    EnumWindows([](HWND hWnd, LPARAM lp) CALLBACK -> BOOL {
        auto* out = reinterpret_cast<std::vector<HWND>*>(lp);
        DWORD pid = 0; wchar_t cls[64] = {};
        if (GetWindowThreadProcessId(hWnd, &pid) && pid == GetCurrentProcessId() &&
            GetClassNameW(hWnd, cls, ARRAYSIZE(cls)) &&
            (_wcsicmp(cls, L"Shell_TrayWnd") == 0 ||
             _wcsicmp(cls, L"Shell_SecondaryTrayWnd") == 0)) {
            out->push_back(hWnd);
        }
        return TRUE;
    }, reinterpret_cast<LPARAM>(&result));
    auto primary = std::find(result.begin(), result.end(), g_taskbarWnd);
    if (primary != result.end()) {
        std::iter_swap(result.begin(), primary);
    }
    return result;
}
static bool InjectPlayerGrid() {
    if (!g_taskbarWnd) g_taskbarWnd = FindCurrentProcessTaskbarWnd();
    auto targets = CollectTargetTaskbarWnds();
    if (targets.empty()) {
        Wh_Log(L"InjectPlayerGrid: No taskbar window found");
        return false;
    }
    bool injectedAny = false;
    for (HWND hWnd : targets) {
        auto instance = std::make_unique<PlayerInstanceState>();
        PlayerInstanceState* raw = instance.get();
        g_playerInstances.push_back(std::move(instance));
        bool ok = false;
        WithPlayerInstance(raw, [hWnd, &ok]() {
            ok = InjectPlayerGridIntoTaskbar(hWnd);
        });
        if (ok) {
            injectedAny = true;
        } else {
            auto it = std::find_if(g_playerInstances.begin(), g_playerInstances.end(),
                                   [raw](auto const& o) { return o.get() == raw; });
            if (it != g_playerInstances.end()) {
                if (g_currentInstance == raw) SetCurrentPlayerInstance(nullptr);
                g_playerInstances.erase(it);
            }
        }
    }
    SetCurrentPlayerInstance(DefaultPlayerInstance());
    if (injectedAny) {
        OnSessionsChanged();
    }
    return injectedAny;
}
static void RemovePlayerGridInstance() {
    if (!g_injectionParent) return;
    try {
        if (g_layoutUpdateToken.value) {
            auto targetGrid = g_injectionParent.try_as<Grid>();
            if (targetGrid) {
                try { targetGrid.LayoutUpdated(g_layoutUpdateToken); } catch (...) {}
            }
        }
        
        if (g_trackedElement) {
            try {
                g_trackedElement.Margin(g_trackedElementOriginalMargin);
            } catch (...) {}
        }
        auto targetPanel = g_injectionParent.try_as<Panel>();
        auto targetGrid = g_injectionParent.try_as<Grid>();
        RemovePlayerGridChildren(targetPanel);
        if (targetGrid && g_playerColumn >= 0 && g_playerColumn < (int)targetGrid.ColumnDefinitions().Size()) {
            for (uint32_t i = 0; i < targetGrid.Children().Size(); ++i) {
                auto child = targetGrid.Children().GetAt(i).try_as<FrameworkElement>();
                if (child) {
                    int childCol = Grid::GetColumn(child);
                    if (childCol > g_playerColumn)
                        Grid::SetColumn(child, childCol - 1);
                }
            }
            targetGrid.ColumnDefinitions().RemoveAt(g_playerColumn);
        }
    } catch (...) {
        Wh_Log(L"RemovePlayerGridInstance: Exception during removal");
    }
}
static void RemovePlayerGrid() {
    try {
        if (g_miniPlayerFlyoutOpen && g_miniPlayerFlyout) {
            g_miniPlayerExplicitCloseRequested.store(true);
            try { g_miniPlayerFlyout.Hide(); } catch (...) {}
        }
        g_miniPlayerFlyout = nullptr;
        g_miniPlayerFlyoutOpen = false;
    } catch (...) {}
    ForEachPlayerInstance(&RemovePlayerGridInstance);
    SetCurrentPlayerInstance(nullptr);
    g_playerInstances.clear();
    g_blurBgCache.Invalidate();
    ClearMiniPlayerRefs();
}
static bool UpdateTrackText(TextBlock const& tb, std::wstring const& text, bool show, bool scrollEnabled,
                            TextScrollState& scroll, const wchar_t* viewName, const wchar_t* cloneName,
                            winrt::Windows::UI::Color color, bool& textChanged) {
    bool visible = show && !text.empty();
    try {
        if (std::wstring(tb.Text()) != text) textChanged = true;
        tb.Text(winrt::hstring(text));
        tb.Foreground(MakeBrush(color));
        tb.Visibility(visible ? Visibility::Visible : Visibility::Collapsed);
        ToolTipService::SetToolTip(tb, nullptr);
        if (scrollEnabled && visible) {
            try {
                if (auto viewFe = FindChildByName(g_playerGrid, viewName))
                    viewFe.Visibility(Visibility::Visible);
            } catch (...) {}
            if (auto panelFe = FindChildByName(g_playerGrid, kPanelGridName)) {
                panelFe.UpdateLayout();
            }
            tb.UpdateLayout();
            double textW = tb.DesiredSize().Width;
            if (auto viewFe = FindChildByName(g_playerGrid, viewName)) {
                if (auto viewCanvas = viewFe.try_as<Canvas>()) {
                    double minW = (double)g_settings.textAreaMinWidth;
                    double maxW = (double)g_settings.textAreaMaxWidth;
                    double viewW = textW;
                    if (maxW > 0 && viewW > maxW) viewW = maxW;
                    double availW = GetAvailableScrollTextAreaWidth();
                    if (availW > 0.0 && viewW > availW) {
                        viewW = (minW > 0.0) ? std::max(availW, minW) : availW;
                    }
                    if (minW > 0 && viewW < minW) viewW = minW;
                    if (std::abs(viewCanvas.Width() - viewW) > 0.5) {
                        viewCanvas.Width(viewW);
                        try {
                            if (auto geo = viewCanvas.Clip().try_as<winrt::Windows::UI::Xaml::Media::RectangleGeometry>()) {
                                auto r = geo.Rect();
                                geo.Rect({0, 0, (float)viewW, r.Height});
                            }
                        } catch (...) {}
                    }
                    bool wasActive = scroll.active;
                    scroll.textWidth = textW;
                    scroll.viewWidth = viewW;
                    scroll.active = (textW > viewW + 2.0);
                    if (!scroll.active) {
                        scroll.offset = 0.0;
                        scroll.forward = true;
                        Canvas::SetLeft(tb, 0.0);
                    } else if (!wasActive) {
                        scroll.offset = 0.0;
                        scroll.forward = true;
                        if (g_settings.scrollMode == L"loop") {
                            scroll.pausing  = false;
                            scroll.pauseTick = 0;
                        } else {
                            scroll.pausing  = true;
                            scroll.pauseTick = g_settings.scrollPauseDuration;
                        }
                    }
                    if (auto cloneFe = FindChildByName(g_playerGrid, cloneName)) {
                        if (auto clone = cloneFe.try_as<TextBlock>()) {
                            clone.Text(tb.Text());
                            clone.Foreground(tb.Foreground());
                            clone.Visibility(g_settings.scrollMode == L"loop" && scroll.active
                                ? Visibility::Visible : Visibility::Collapsed);
                        }
                    }
                }
            }
        } else {
            scroll.active = false;
            scroll.offset = 0.0;
            if (scrollEnabled) {
                try {
                    if (auto viewFe = FindChildByName(g_playerGrid, viewName))
                        viewFe.Visibility(Visibility::Collapsed);
                } catch (...) {}
            }
        }
    } catch (...) {}
    return visible;
}
static void ApplyButtonSupport(Button const& btn, bool supported) {
    btn.IsEnabled(supported);
    btn.Visibility(supported || !g_settings.hideUnsupportedButtons ? Visibility::Visible : Visibility::Collapsed);
}
static Border FindEmptyIconBorder(Grid const& artInnerGrid) {
    for (uint32_t i = 0; i < artInnerGrid.Children().Size(); ++i) {
        if (auto border = artInnerGrid.Children().GetAt(i).try_as<Border>()) {
            if (border.Name() == L"EmptyIconBorder") return border;
        }
    }
    return nullptr;
}
static void RefreshPlayerContentsInstance() {
    if (!g_playerGrid || g_unloading || g_applyingSettings) return;
    MediaState media;
    {
        std::lock_guard<std::mutex> lk(g_mediaMtx);
        media = g_media;
    }
    bool hasSession = false;
    { std::lock_guard<std::mutex> lk(g_sessionMtx); hasSession = (g_currentSession != nullptr); }
    bool audioAppSource = false;
    if (!media.hasMedia &&
        ApplyAudioAppToDisplay(media.title, media.artist, media.thumbnailBytes, media.thumbnailHash, media.isPlaying)) {
        audioAppSource = true;
        hasSession     = true;
        media.hasMedia = true;
        media.canSkipPrevious = media.canSkipNext = media.canShuffle = media.canRepeat = media.canSeek = false;
    }
    g_playerGrid.UpdateLayout();
    if (media.title != g_scrollCachedTitle || media.artist != g_scrollCachedArtist) {
        g_scrollCachedTitle  = media.title;
        g_scrollCachedArtist = media.artist;
        ResetScrollState(g_titleScroll);
        ResetScrollState(g_artistScroll);
        for (const auto& cloneName : {kTitleCloneName, kArtistCloneName}) {
            try {
                if (auto fe = FindChildByName(g_playerGrid, cloneName))
                    if (auto cl = fe.try_as<TextBlock>())
                        cl.Visibility(Visibility::Collapsed);
            } catch (...) {}
        }
        for (const auto& blockName : {kTitleBlockName, kArtistBlockName}) {
            try {
                if (auto fe = FindChildByName(g_playerGrid, blockName))
                    if (auto tb = fe.try_as<TextBlock>())
                        Canvas::SetLeft(tb, 0.0);
            } catch (...) {}
        }
    }
    bool titleVisible = false;
    bool artistVisible = false;
    bool trackTextChanged = false;
    if (auto fe = FindChildByName(g_playerGrid, kTitleBlockName))
        if (auto tb = fe.try_as<TextBlock>())
            titleVisible = UpdateTrackText(
                tb,
                !hasSession ? g_settings.noMediaTitleText : media.title.empty() ? g_settings.emptyTitleText : media.title,
                g_settings.showTrackTitle, g_settings.enableTitleScrolling, g_titleScroll,
                kTitleScrollViewName, kTitleCloneName, TextColor(), trackTextChanged);
    if (auto fe = FindChildByName(g_playerGrid, kArtistBlockName))
        if (auto ab = fe.try_as<TextBlock>())
            artistVisible = UpdateTrackText(
                ab,
                !hasSession ? g_settings.noMediaArtistText : media.artist.empty() ? g_settings.emptyArtistText : media.artist,
                g_settings.showTrackArtist, g_settings.enableArtistScrolling, g_artistScroll,
                kArtistScrollViewName, kArtistCloneName, ArtistColor(), trackTextChanged);
    if ((g_titleScroll.active || g_artistScroll.active) &&
        (g_settings.enableTitleScrolling || g_settings.enableArtistScrolling)) {
        if (g_scrollTimer.timer && !g_scrollTimer.timer.IsEnabled()) {
            try { g_scrollTimer.timer.Start(); } catch (...) {}
        }
    }
    try {
        if (auto stackFe = FindChildByName(g_playerGrid, kTextStackName)) {
            bool anyTextVisible = titleVisible || artistVisible;
            stackFe.Visibility(anyTextVisible ? Visibility::Visible : Visibility::Collapsed);
            if (anyTextVisible && trackTextChanged) {
                AnimateContentSwap(stackFe, kTextFadeMs, 1.0);
            }
        }
    } catch (...) {}
    if (auto fe = FindChildByName(g_playerGrid, kPlayBtnName))
        if (auto btn = fe.try_as<Button>())
            try {
                if (auto ct = btn.Content().try_as<TextBlock>()) {
                    const wchar_t* glyph = audioAppSource
                        ? (media.isPlaying ? L"\uE767" : L"\uE74F")
                        : GetGlyph(kCmdPlayPause, media.isPlaying);
                    ct.Text(winrt::hstring(glyph));
                    ct.Foreground(MakeBrush(ButtonColor()));
                }
            } catch (...) {}
    if (auto fe = FindChildByName(g_playerGrid, kPrevBtnName))
        if (auto btn = fe.try_as<Button>())
            try {
                bool supported = media.canSkipPrevious;
                ApplyButtonSupport(btn, supported);
                if (auto ct = btn.Content().try_as<TextBlock>()) {
                    ct.Text(GetGlyph(kCmdPrevious));
                    ct.Opacity(supported ? 1.0 : 0.35);
                    ct.Foreground(MakeBrush(ButtonColor()));
                }
            } catch (...) {}
    if (auto fe = FindChildByName(g_playerGrid, kNextBtnName))
        if (auto btn = fe.try_as<Button>())
            try {
                bool supported = media.canSkipNext;
                ApplyButtonSupport(btn, supported);
                if (auto ct = btn.Content().try_as<TextBlock>()) {
                    ct.Text(GetGlyph(kCmdNext));
                    ct.Opacity(supported ? 1.0 : 0.35);
                    ct.Foreground(MakeBrush(ButtonColor()));
                }
            } catch (...) {}
    if (auto fe = FindChildByName(g_playerGrid, kRewindBtnName))
        if (auto btn = fe.try_as<Button>())
            try {
                bool supported = media.canSeek;
                ApplyButtonSupport(btn, supported);
                if (auto ct = btn.Content().try_as<TextBlock>()) {
                    ct.Text(GetGlyph(kCmdRewind));
                    ct.Opacity(supported ? 1.0 : 0.35);
                    ct.Foreground(MakeBrush(ButtonColor()));
                }
            } catch (...) {}
    if (auto fe = FindChildByName(g_playerGrid, kForwardBtnName))
        if (auto btn = fe.try_as<Button>())
            try {
                bool supported = media.canSeek;
                ApplyButtonSupport(btn, supported);
                if (auto ct = btn.Content().try_as<TextBlock>()) {
                    ct.Text(GetGlyph(kCmdForward));
                    ct.Opacity(supported ? 1.0 : 0.35);
                    ct.Foreground(MakeBrush(ButtonColor()));
                }
            } catch (...) {}
    if (auto fe = FindChildByName(g_playerGrid, kShuffleBtnName))
        if (auto btn = fe.try_as<Button>())
            try {
                bool supported = media.canShuffle;
                ApplyButtonSupport(btn, supported);
                if (auto ct = btn.Content().try_as<TextBlock>()) {
                    ct.Text(GetGlyph(kCmdToggleShuffle));
                    if (!supported && !g_settings.hideUnsupportedButtons) {
                        ct.Opacity(0.35);
                    } else {
                        ct.Opacity(g_shuffleEnabled.load() ? 1.0 : 0.4);
                    }
                    ct.Foreground(MakeBrush(ButtonColor()));
                }
            } catch (...) {}
    if (auto fe = FindChildByName(g_playerGrid, kRepeatBtnName))
        if (auto btn = fe.try_as<Button>())
            try {
                bool supported = media.canRepeat;
                ApplyButtonSupport(btn, supported);
                if (auto ct = btn.Content().try_as<TextBlock>()) {
                    ct.Text(GetGlyph(kCmdCycleRepeat));
                    ct.Foreground(MakeBrush(ButtonColor()));
                    if (!supported && !g_settings.hideUnsupportedButtons) {
                        ct.Opacity(0.35);
                    } else {
                        ct.Opacity(1.0);
                    }
                }
            } catch (...) {}
    if (auto fe = FindChildByName(g_playerGrid, kSwitchSessionsBtnName))
        if (auto btn = fe.try_as<Button>())
            try {
                bool supported = g_sessionCount.load() > 1;
                ApplyButtonSupport(btn, supported);
                if (auto ct = btn.Content().try_as<TextBlock>()) {
                    ct.Opacity(supported ? 1.0 : 0.35);
                    ct.Foreground(MakeBrush(ButtonColor()));
                }
            } catch (...) {}
    const bool emptyState = !(hasSession && media.hasMedia);
    const bool emptyStateOwnsAlbumArt = emptyState && g_settings.emptyStateHideAlbumArt;
    {
        auto applyEmptyState = [emptyState](FrameworkElement const& el, bool hideWhenEmpty) {
            if (!el) return;
            try {
                bool shouldHide = emptyState && hideWhenEmpty;
                bool isHidden = (el.Visibility() == Visibility::Collapsed);
                if (shouldHide == isHidden) return;
                if (shouldHide) {
                    AnimatePlayerHide(el);
                    CollapseAfterHideAnim(el);
                } else {
                    el.Visibility(Visibility::Visible);
                    AnimatePlayerShow(el);
                }
            } catch (...) {}
        };
        applyEmptyState(FindChildByName(g_playerGrid, kControlsPanelName),
                        g_settings.emptyStateHideButtons);
        applyEmptyState(FindChildByName(g_playerGrid, kVizContainerName),
                        g_settings.emptyStateHideVisualizer);
        applyEmptyState(FindChildByName(g_playerGrid, kArtContainerName),
                        g_settings.emptyStateHideAlbumArt);
    }
    if (g_settings.showPauseOverlay && g_settings.showAlbumArt) {
        if (auto fe = FindChildByName(g_playerGrid, kPauseOverlayName))
            if (auto overlay = fe.try_as<Border>()) {
                try {
                    bool showPause = !media.isPlaying && media.hasMedia && !audioAppSource;
                    overlay.Visibility(showPause ? Visibility::Visible : Visibility::Collapsed);
                    if (auto pauseIcon = overlay.Child().try_as<TextBlock>()) {
                        pauseIcon.Text(GetGlyph(kCmdPlayPause, true));
                        pauseIcon.FontFamily(Media::FontFamily(IsFluentIconStyle(g_settings.iconStyle) ? L"Segoe Fluent Icons" : L"Segoe MDL2 Assets"));
                        pauseIcon.FontSize((double)g_settings.pauseOverlayIconSize);
                    }
                    if (showPause) {
                        if (auto artImg = FindChildByName(g_playerGrid, kArtImageName)) {
                            if (auto parent = VisualTreeHelper::GetParent(artImg)) {
                                if (auto artInnerGrid = parent.try_as<Grid>()) {
                                    if (auto border = FindEmptyIconBorder(artInnerGrid)) {
                                        border.Visibility(Visibility::Collapsed);
                                    }
                                }
                            }
                        }
                    }
                } catch (...) {}
            }
    }
    bool paletteChanged = false;
    if (auto fe = FindChildByName(g_playerGrid, kArtImageName))
        if (auto img = fe.try_as<Controls::Image>()) {
            if (!media.thumbnailBytes.empty() && g_settings.showAlbumArt) {
                bool isSameAlbum = (!g_cachedThumbnailBytes.empty() &&
                                media.title == g_cachedAlbumTitle &&
                                media.artist == g_cachedAlbumArtist &&
                                media.thumbnailBytes == g_cachedThumbnailBytes);
                size_t newHash = (size_t)media.thumbnailHash;
                if (newHash != g_cachedPaletteHash && newHash != 0) {
                    g_cachedAlbumPalette = ExtractAlbumPalette(media.thumbnailBytes);
                    g_cachedPaletteHash = newHash;
                    g_vizPaletteColorsDirty = true;
                    paletteChanged = true;
                }
                if (!isSameAlbum) {
                    try {
                        if (auto rasStream = StreamFromBytes(media.thumbnailBytes)) {
                            BitmapImage bmp;
                            if (g_settings.albumArtQuality == L"low") {
                                int baseHeight = g_settings.albumArtMaxHeight > 0 ? g_settings.albumArtMaxHeight : 64;
                                int decodeHeight = baseHeight / 2;
                                if (decodeHeight < 16) decodeHeight = 16;
                                bmp.DecodePixelHeight(decodeHeight);
                            } else if (g_settings.albumArtQuality == L"medium") {
                                if (g_settings.albumArtMaxHeight > 0) {
                                    bmp.DecodePixelHeight(g_settings.albumArtMaxHeight);
                                }
                            }
                            bmp.ImageOpened([img](auto const&, auto const&) {
                                if (g_unloading || g_applyingSettings || !g_playerGrid) return;
                                try {
                                    if (auto panelFe = FindChildByName(g_playerGrid, kPanelGridName)) {
                                        panelFe.UpdateLayout();
                                    }
                                    AnimateContentSwap(img, kArtCrossfadeMs);
                                    g_needsUiUpdate = true;
                                    if (g_timerUpdateEvent) SetEvent(g_timerUpdateEvent);
                                } catch (...) {}
                            });
                            img.Source(bmp);
                            bmp.SetSourceAsync(rasStream);
                            img.Visibility(Visibility::Visible);
                            g_cachedAlbumTitle = media.title;
                            g_cachedAlbumArtist = media.artist;
                            g_cachedThumbnailBytes = media.thumbnailBytes;
                            if (auto artContainer = FindChildByName(g_playerGrid, kArtContainerName)) {
                                artContainer.Visibility(Visibility::Visible);
                            }
                            if (auto parent = VisualTreeHelper::GetParent(img)) {
                                if (auto artInnerGrid = parent.try_as<Grid>()) {
                                    if (auto border = FindEmptyIconBorder(artInnerGrid)) {
                                        border.Visibility(Visibility::Collapsed);
                                    }
                                }
                            }
                        }
                    } catch (...) { try { img.Source(nullptr); } catch (...) {} }
                } else {
                    img.Visibility(Visibility::Visible);
                    if (auto artContainer = FindChildByName(g_playerGrid, kArtContainerName)) {
                        artContainer.Visibility(Visibility::Visible);
                    }
                }
                if (auto bgFe = FindChildByName(g_playerGrid, kBackgroundName)) {
                    if (auto bgBorder = bgFe.try_as<Border>()) {
                        if (g_settings.backgroundType == L"album_art_blur") {
                            try {
                                bgBorder.Visibility(Visibility::Visible);
                                bgBorder.Opacity(g_settings.blurOpacity / 100.0);
                                auto applyBlur = [bgBorder, thumbBytesSnap = media.thumbnailBytes]() {
                                    try {
                                        int w = (int)bgBorder.ActualWidth();
                                        int h = (int)bgBorder.ActualHeight();
                                        if (w <= 0 || h <= 0) return;
                                        bgBorder.Background(MakeAlbumBlurBrush(thumbBytesSnap, w, h));
                                        bgBorder.Opacity(g_settings.blurOpacity / 100.0);
                                        bgBorder.Visibility(Visibility::Visible);
                                    } catch (...) {}
                                };
                                if (bgBorder.ActualWidth() > 0 && bgBorder.ActualHeight() > 0) {
                                    applyBlur();
                                } else {
                                    auto tokenHolder = std::make_shared<winrt::event_token>();
                                    *tokenHolder = bgBorder.SizeChanged(
                                        [applyBlur, bgBorder, tokenHolder](auto const&, auto const&) mutable {
                                            applyBlur();
                                            try { bgBorder.SizeChanged(*tokenHolder); } catch (...) {}
                                        });
                                }
                            } catch (...) {}
                        } else if (UsesBackgroundBrush()) {
                            try {
                                ApplyBrushBackground(bgBorder);
                            } catch (...) {}
                        }
                    }
                }
            } else {
                g_cachedAlbumTitle.clear();
                g_cachedAlbumArtist.clear();
                g_cachedThumbnailBytes.clear();
                g_cachedPaletteHash = 0;
                g_blurBgCache.Invalidate();
                if (auto bgFe = FindChildByName(g_playerGrid, kBackgroundName)) {
                    if (auto bgBorder = bgFe.try_as<Border>()) {
                        try {
                            if (UsesBackgroundBrush()) {
                                ApplyBrushBackground(bgBorder);
                            } else {
                                bgBorder.Background(nullptr);
                                bgBorder.Visibility(Visibility::Collapsed);
                            }
                        } catch (...) {}
                    }
                }
                try {
                    img.Source(nullptr);
                    img.Visibility(Visibility::Collapsed);
                    if (g_settings.albumArtEmptyBehavior == L"hide" && media.thumbnailBytes.empty()) {
                        if (auto artContainer = FindChildByName(g_playerGrid, kArtContainerName)) {
                            artContainer.Visibility(Visibility::Collapsed);
                        }
                    } else if (g_settings.albumArtEmptyBehavior == L"show_icon" && media.thumbnailBytes.empty()) {
                        if (auto parent = VisualTreeHelper::GetParent(img)) {
                            if (auto artInnerGrid = parent.try_as<Grid>()) {
                                if (!emptyStateOwnsAlbumArt) {
                                    if (auto artContainer = FindChildByName(g_playerGrid, kArtContainerName)) {
                                        artContainer.Visibility(Visibility::Visible);
                                    }
                                }
                                Border iconBorder = FindEmptyIconBorder(artInnerGrid);
                                if (!iconBorder) {
                                    iconBorder = Border();
                                    iconBorder.Name(L"EmptyIconBorder");
                                    iconBorder.Background(MakeBrush({0x00, 0x00, 0x00, 0x00}));
                                    iconBorder.HorizontalAlignment(HorizontalAlignment::Stretch);
                                    iconBorder.VerticalAlignment(VerticalAlignment::Stretch);
                                    Canvas::SetZIndex(iconBorder, 5);
                                    TextBlock iconText = TextBlock();
                                    iconText.Name(L"EmptyIconText");
                                    iconText.HorizontalAlignment(HorizontalAlignment::Center);
                                    iconText.VerticalAlignment(VerticalAlignment::Center);
                                    iconBorder.Child(iconText);
                                    artInnerGrid.Children().InsertAt(0, iconBorder);
                                }
                                if (auto textBlock = iconBorder.Child().try_as<TextBlock>()) {
                                    std::wstring glyphStr;
                                    try {
                                        unsigned long cp = std::stoul(g_settings.emptyIconGlyph, nullptr, 16);
                                        if (cp <= 0xFFFF) {
                                            glyphStr = std::wstring(1, (wchar_t)cp);
                                        } else {
                                            cp -= 0x10000;
                                            glyphStr += (wchar_t)(0xD800 + (cp >> 10));
                                            glyphStr += (wchar_t)(0xDC00 + (cp & 0x3FF));
                                        }
                                    } catch (...) {
                                        glyphStr = L"\uE189";
                                    }
                                    textBlock.Text(glyphStr);
                                    bool useFluent = (g_settings.emptyIconFont == L"segoe_fluent");
                                    textBlock.FontFamily(Media::FontFamily(
                                        useFluent ? L"Segoe Fluent Icons" : L"Segoe MDL2 Assets"));
                                    textBlock.FontSize((double)g_settings.emptyIconSize);
                                    BYTE alpha = (BYTE)std::clamp((int)std::round(g_settings.emptyIconOpacity * 255.0 / 100.0), 0, 255);
                                    auto iconClr = ParseColorWithThemeSupport(g_settings.emptyIconColor, alpha);
                                    textBlock.Foreground(MakeBrush(iconClr));
                                }
                                iconBorder.Visibility(Visibility::Visible);
                            }
                        }
                    }
                } catch (...) {}
            }
        }
    if (paletteChanged) {
        try {
            if (UsesBackgroundBrush()) {
                if (auto bgFe = FindChildByName(g_playerGrid, kBackgroundName)) {
                    if (auto bgBorder = bgFe.try_as<Border>()) {
                        bgBorder.Background(MakeBackgroundBrush());
                    }
                }
            }
            if (auto titleFe = FindChildByName(g_playerGrid, kTitleBlockName)) {
                if (auto titleBlock = titleFe.try_as<TextBlock>()) {
                    titleBlock.Foreground(MakeBrush(TextColor()));
                }
            }
            if (auto artistFe = FindChildByName(g_playerGrid, kArtistBlockName)) {
                if (auto artistBlock = artistFe.try_as<TextBlock>()) {
                    artistBlock.Foreground(MakeBrush(ArtistColor()));
                }
            }
            auto buttonClr = ButtonColor();
            for (const auto& btnName : {kPlayBtnName, kPrevBtnName, kNextBtnName,
                                        kRewindBtnName, kForwardBtnName, kShuffleBtnName, kRepeatBtnName}) {
                if (auto btnFe = FindChildByName(g_playerGrid, btnName)) {
                    if (auto btn = btnFe.try_as<Button>()) {
                        if (auto content = btn.Content()) {
                            if (auto icon = content.try_as<TextBlock>()) {
                                icon.Foreground(MakeBrush(buttonClr));
                            }
                        }
                    }
                }
            }
        } catch (...) {}
    }
    if (g_settings.showAppIcon) {
        if (auto fe = FindChildByName(g_playerGrid, kAppIconImageName))
            if (auto img = fe.try_as<Controls::Image>()) {
                if (!media.appIconBytes.empty()) {
                    try {
                        int iconSz = g_settings.appIconSize;
                        size_t expectedBytes = (size_t)iconSz * iconSz * 4;
                        if (media.appIconBytes.size() != expectedBytes) {
                            int computed = (int)std::sqrt((double)media.appIconBytes.size() / 4.0);
                            if (computed > 0 && (size_t)computed * computed * 4 == media.appIconBytes.size())
                                iconSz = computed;
                        }
                        img.Width(iconSz);
                        img.Height(iconSz);
                        size_t bytesNeeded = (size_t)iconSz * iconSz * 4;
                        winrt::Windows::UI::Xaml::Media::Imaging::WriteableBitmap wb(iconSz, iconSz);
                        auto buf = wb.PixelBuffer();
                        auto bufferByteAccess = buf.as<Windows::Storage::Streams::IBufferByteAccess>();
                        BYTE* pixels = nullptr;
                        bufferByteAccess->Buffer(&pixels);
                        if (media.appIconBytes.size() >= bytesNeeded && pixels) {
                            memcpy(pixels, media.appIconBytes.data(), bytesNeeded);
                        }
                        buf.Length(static_cast<uint32_t>(bytesNeeded));
                        wb.Invalidate();
                        img.Source(wb);
                        img.Visibility(Visibility::Visible);
                    } catch (...) {
                        try { img.Source(nullptr); img.Visibility(Visibility::Collapsed); } catch (...) {}
                    }
                } else {
                    try { img.Source(nullptr); img.Visibility(Visibility::Collapsed); } catch (...) {}
                }
            }
    }
    try {
        if (g_settings.showFullTitleOnHover && hasSession && (!media.title.empty() || !media.artist.empty())) {
            std::wstring tooltipText;
            if (!media.title.empty())  tooltipText += media.title;
            if (!media.title.empty() && !media.artist.empty()) tooltipText += L"\n\n";
            if (!media.artist.empty()) tooltipText += media.artist;
            if (g_playerToolTip) {
                try {
                    auto content = g_playerToolTip.Content();
                    if (auto ttText = content.try_as<TextBlock>()) {
                        ttText.Text(winrt::hstring(tooltipText));
                    }
                    g_playerToolTip.IsEnabled(true);
                } catch (...) {}
                try { ToolTipService::SetToolTip(g_playerGrid, g_playerToolTip); } catch (...) {}
            }
        } else {
            if (g_playerToolTip) {
                try {
                    auto content = g_playerToolTip.Content();
                    if (auto ttText = content.try_as<TextBlock>()) {
                        ttText.Text(L"");
                    }
                    g_playerToolTip.IsEnabled(false);
                } catch (...) {}
            }

            try { ToolTipService::SetToolTip(g_playerGrid, nullptr); } catch (...) {}
        }
    } catch (...) {}
}
static void RefreshPlayerContents() {
    ForEachPlayerInstance(&RefreshPlayerContentsInstance);
    RefreshMiniPlayerFlyoutUI();
}
static bool IsFullscreenActive() {
    QUERY_USER_NOTIFICATION_STATE state;
    return SUCCEEDED(SHQueryUserNotificationState(&state)) &&
           (state == QUNS_BUSY || state == QUNS_RUNNING_D3D_FULL_SCREEN || state == QUNS_PRESENTATION_MODE);
}
static bool g_anyPlayerVisible = false;
static bool g_anyVisualizerVisible = false;
static void UpdateVisibilityInstance() {
    if (!g_playerGrid || g_unloading || g_applyingSettings) return;
    bool hide = false;
    if (g_settings.hideFullscreen && IsFullscreenActive()) hide = true;
    if (!hide && g_hiddenByIdle) hide = true;
    if (!hide) {
        bool hasMedia = false, hasSession = false;
        { std::lock_guard<std::mutex> lk(g_mediaMtx); hasMedia = g_media.hasMedia; }
        { std::lock_guard<std::mutex> lk(g_sessionMtx); hasSession = (g_currentSession != nullptr); }
        if (!hasMedia && AudioAppIsCurrentSource()) {
            hasMedia   = true;
            hasSession = true;
        }
        if (hasMedia) {
            g_lastMediaTime = std::chrono::steady_clock::now();
        }

        if (g_settings.hideWhenNoMedia && !g_miniPlayerFlyoutOpen) {
            if (!hasSession) {
                hide = true;
            }
            else if (!hasMedia) {
                auto now = std::chrono::steady_clock::now();
                auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - g_lastMediaTime).count();
                if (elapsed > 2500) {
                    hide = true;
                } else {
                    g_needsUiUpdate = true;
                }
            }
        }
    }
    try {
        if (g_playerColumn == -1) {
            bool wasVisible = (g_playerGrid.Visibility() == Visibility::Visible &&
                               g_playerGrid.Opacity() > 0.01);
            if (hide) {
                if (wasVisible) {
                    AnimatePlayerHide(g_playerGrid);
                    CollapseAfterHideAnim(g_playerGrid);
                } else {
                    g_playerGrid.Visibility(Visibility::Collapsed);
                }
            } else {
                g_playerGrid.Visibility(Visibility::Visible);
                if (!wasVisible) AnimatePlayerShow(g_playerGrid);
            }
        } else {
            if (hide && IsTaskbarTrackingPosition(g_settings.position) && g_settings.enableSmoothPositionAnimation) {
                AnimatePlayerHide(g_playerGrid);
                PlayerInstanceState* owner = g_currentInstance;
                SpawnTrackedWorker([owner]() {
                    std::this_thread::sleep_for(
                        std::chrono::milliseconds(kPlayerHideAnimMs));
                    try {
                        RunFromWindowThread(g_taskbarWnd, [](void* param) {
                            auto* inst = reinterpret_cast<PlayerInstanceState*>(param);
                            if (!IsLivePlayerInstance(inst)) return;
                            WithPlayerInstance(inst, []() {
                                try {
                                    if (g_playerGrid) {
                                        g_playerGrid.Visibility(Visibility::Collapsed);
                                        if (g_injectionParent) {
                                            if (auto targetGrid = g_injectionParent.try_as<Grid>()) {
                                                if (g_playerColumn < (int)targetGrid.ColumnDefinitions().Size()) {
                                                    auto colDef = targetGrid.ColumnDefinitions().GetAt(g_playerColumn);
                                                    colDef.Width({0.0, GridUnitType::Pixel});
                                                }
                                            }
                                        }
                                        g_playerGrid.MinWidth(0);
                                        g_playerGrid.MaxWidth(0);
                                        g_playerGrid.Width(0);
                                    }
                                } catch (...) {}
                            });
                        }, owner);
                    } catch (...) {}
                });
            } else {
                bool wasVisible = (g_playerGrid.Visibility() == Visibility::Visible &&
                                   g_playerGrid.Opacity() > 0.01);
                g_playerGrid.Visibility(hide ? Visibility::Collapsed : Visibility::Visible);
                if (hide) {
                    g_playerGrid.Opacity(0.0);
                } else if (!wasVisible) {
                    AnimatePlayerShow(g_playerGrid);
                } else {
                    g_playerGrid.Opacity(1.0);
                }
                if (g_injectionParent) {
                    if (auto targetGrid = g_injectionParent.try_as<Grid>()) {
                        if (g_playerColumn < (int)targetGrid.ColumnDefinitions().Size()) {
                            auto colDef = targetGrid.ColumnDefinitions().GetAt(g_playerColumn);
                            if (hide) {
                                colDef.Width({0.0, GridUnitType::Pixel});
                            } else {
                                colDef.Width({1.0, GridUnitType::Auto});
                            }
                        }
                    }
                }
                if (hide) {
                    g_playerGrid.MinWidth(0);
                    g_playerGrid.MaxWidth(0);
                    g_playerGrid.Width(0);
                } else {
                    bool hasTextOrButtons = g_settings.showTrackTitle || g_settings.showTrackArtist || (g_settings.showMediaButtons && !g_mediaButtons.empty());
                    if (hasTextOrButtons && g_settings.playerMinWidth > 0) {
                        g_playerGrid.MinWidth((double)g_settings.playerMinWidth);
                    } else {
                        g_playerGrid.MinWidth(0);
                    }
                    if (g_settings.playerMaxWidth > 0) {
                        g_playerGrid.MaxWidth((double)g_settings.playerMaxWidth);
                    } else {
                        g_playerGrid.ClearValue(FrameworkElement::MaxWidthProperty());
                    }
                    g_playerGrid.ClearValue(FrameworkElement::WidthProperty());
                }
            }
        }
        g_playerGrid.UpdateLayout();
        if (!hide) {
            g_anyPlayerVisible = true;
            if (!(g_settings.emptyStateHideVisualizer && !HasMediaToControl())) {
                g_anyVisualizerVisible = true;
            }
        }
    } catch (...) {}
}
static void UpdateVisibility() {
    g_anyPlayerVisible = false;
    g_anyVisualizerVisible = false;
    ForEachPlayerInstance(&UpdateVisibilityInstance);
    try {
        if (g_settings.vizEnabled) {
            if (g_anyVisualizerVisible && !g_vizCurrentlyVisible) {
                g_vizCurrentlyVisible = true;
                StartVizCaptureThread();
                StartTickTimer(g_vizTimer);
            } else if (!g_anyVisualizerVisible && g_vizCurrentlyVisible) {
                g_vizCurrentlyVisible = false;
                StopTickTimer(g_vizTimer);
                SpawnTrackedWorker([]() { StopVizCaptureThread(true); });
            }
        }

        if (g_settings.enableTitleScrolling || g_settings.enableArtistScrolling) {
            if (g_anyPlayerVisible) StartTickTimer(g_scrollTimer);
            else                    StopTickTimer(g_scrollTimer);
        }
    } catch (...) {}
}
static void ApplySettings() {
    g_idleSinceTick = 0;
    g_hiddenByIdle = false;
    try { RemovePlayerGrid(); } catch (...) { Wh_Log(L"ApplySettings: Exception in RemovePlayerGrid"); }
    if (!g_unloading) {
        try { InjectPlayerGrid(); } catch (...) { Wh_Log(L"ApplySettings: Exception in InjectPlayerGrid"); }
    }
}
[[clang::no_destroy]] static winrt::Windows::UI::Xaml::DispatcherTimer g_applyRetryTimer{nullptr};
static void ApplySettingsWithRetry(FrameworkElement xamlRootContent, int retryCount = 0) {
    static constexpr int kMaxRetries = 50;
    auto retry = [&]() {
        if (retryCount >= kMaxRetries) {
            Wh_Log(L"ApplySettingsWithRetry: giving up after %d retries, SystemTray.SystemTrayFrame not found", kMaxRetries);
            return;
        }
        auto timer = DispatcherTimer();
        timer.Interval(winrt::Windows::Foundation::TimeSpan{
            std::chrono::milliseconds(100)});
        auto tickToken = std::make_shared<winrt::event_token>();
        *tickToken = timer.Tick(
            [timer, tickToken, xamlRootContent, retryCount](
                winrt::Windows::Foundation::IInspectable const&,
                winrt::Windows::Foundation::IInspectable const&) {
                timer.Stop();
                timer.Tick(*tickToken);
                ApplySettingsWithRetry(xamlRootContent, retryCount + 1);
            });
        g_applyRetryTimer = timer;
        timer.Start();
    };
    if (g_unloading) {
        return;
    }
    auto systemTrayFrame = FindChildByClassName(xamlRootContent, L"SystemTray.SystemTrayFrame");
    if (!systemTrayFrame) {
        retry();
        return;
    }
    auto systemTrayFrameGrid = FindChildByName(systemTrayFrame, L"SystemTrayFrameGrid");
    if (!systemTrayFrameGrid) {
        retry();
        return;
    }
    ApplySettings();
}
using TrayUI_StartTaskbar_t = void(WINAPI*)(void*);
static TrayUI_StartTaskbar_t TrayUI_StartTaskbar_Original = nullptr;
static void WINAPI TrayUI_StartTaskbar_Hook(void* pThis) {
    TrayUI_StartTaskbar_Original(pThis);
    if (g_unloading) {
        return;
    }
    HWND hWnd = FindCurrentProcessTaskbarWnd();
    if (!hWnd) {
        Wh_Log(L"TrayUI_StartTaskbar_Hook: Taskbar window not found");
        return;
    }
    SetCurrentPlayerInstance(nullptr);
    g_playerInstances.clear();
    g_taskbarWnd = hWnd;
    g_curTaskbarWnd = hWnd;
    g_blurBgCache.Invalidate();
    StopTickTimer(g_vizTimer);
    g_vizTimer.timer = nullptr;
    g_vizTimer.token = {};
    StopTickTimer(g_scrollTimer);
    g_scrollTimer.timer = nullptr;
    g_scrollTimer.token = {};
    if (g_settings.vizEnabled) {
        SpawnTrackedWorker([]() {
            StopVizCaptureThread();
            StartVizCaptureThread();
        });
        StartTickTimer(g_vizTimer);
    }
    if (g_settings.enableTitleScrolling || g_settings.enableArtistScrolling) {
        StartTickTimer(g_scrollTimer);
    }
    auto xamlRoot = GetTaskbarXamlRoot(hWnd);
    if (!xamlRoot) {
        Wh_Log(L"TrayUI_StartTaskbar_Hook: Failed to get XAML root");
        return;
    }
    auto xamlRootContent = xamlRoot.Content().try_as<FrameworkElement>();
    if (!xamlRootContent) {
        Wh_Log(L"TrayUI_StartTaskbar_Hook: Failed to get XAML root content");
        return;
    }
    ApplySettingsWithRetry(xamlRootContent);
}
static bool HookTaskbarDllSymbols() {
    HMODULE h = LoadLibraryExW(L"taskbar.dll", nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);
    if (!h) return false;
    WindhawkUtils::SYMBOL_HOOK taskbarDllHooks[] = {
        {{LR"(const CTaskBand::`vftable'{for `ITaskListWndSite'})"},
        &CTaskBand_ITaskListWndSite_vftable},
        {{LR"(const CSecondaryTaskBand::`vftable'{for `ITaskListWndSite'})"},
        &CSecondaryTaskBand_ITaskListWndSite_vftable},
        {{LR"(public: virtual class std::shared_ptr<class TaskbarHost> __cdecl CTaskBand::GetTaskbarHost(void)const )"},
        &CTaskBand_GetTaskbarHost_Original},
        {{LR"(public: virtual class std::shared_ptr<class TaskbarHost> __cdecl CSecondaryTaskBand::GetTaskbarHost(void)const )"},
        &CSecondaryTaskBand_GetTaskbarHost_Original},
        {{LR"(public: int __cdecl TaskbarHost::FrameHeight(void)const )"},
        &TaskbarHost_FrameHeight_Original},
        {{LR"(public: void __cdecl std::_Ref_count_base::_Decref(void))"},
        &Std_Ref_Decref_Original},
        {{LR"(public: virtual void __cdecl TrayUI::StartTaskbar(void))"},
        &TrayUI_StartTaskbar_Original,
        TrayUI_StartTaskbar_Hook},
    };
    return WindhawkUtils::HookSymbols(h, taskbarDllHooks, ARRAYSIZE(taskbarDllHooks));
}
BOOL Wh_ModInit() {
    LoadSettings();
    if (!HookTaskbarDllSymbols()) {
        Wh_Log(L"Wh_ModInit: HookTaskbarDllSymbols failed");
        return FALSE;
    }
    return TRUE;
}
void Wh_ModAfterInit() {
    g_taskbarWnd = FindCurrentProcessTaskbarWnd();
    g_curTaskbarWnd = g_taskbarWnd;
    StartMediaThread();
    StartTimerThread();
    StartAudioAppThread();
    if (g_taskbarWnd) {
        RunFromWindowThread(g_taskbarWnd, [](void*) {
            ApplySettings();
            if (PlayerInstanceCount() > 0) {
                RefreshPlayerContents();
                UpdateVisibility();
                g_needsUiUpdate = true;
                if (g_timerUpdateEvent) {
                    SetEvent(g_timerUpdateEvent);
                }
            }
        }, nullptr);
    }
}
static void ReleaseSharedBrushes() {
    g_mediaHoverBrush   = nullptr;
    g_mediaPressedBrush = nullptr;
    g_playerHoverBrush  = nullptr;
    g_playerPressedBrush = nullptr;
    g_playerBorderBrush  = nullptr;
    g_playerBorderPressedBrush = nullptr;
    g_vizBars.reset();
    g_vizBrushes.reset();
}
void Wh_ModUninit() {
    g_unloading = true;
    StopTimerThread();
    StopAudioAppThread();
    StopMediaThread();
    WaitForTrackedWorkers();
    if (g_taskbarWnd)
        RunFromWindowThread(g_taskbarWnd, [](void*) {
            if (g_applyRetryTimer) {
                g_applyRetryTimer.Stop();
                g_applyRetryTimer = nullptr;
            }
            RemovePlayerGrid();
            ReleaseSharedBrushes();
            g_fluentMediaButtonStyle      = nullptr;
        }, nullptr);
    else {
        ReleaseSharedBrushes();
    }
    CleanupAudioDeviceEnumerator();
}
void Wh_ModSettingsChanged() {
    g_applyingSettings = true;
    g_vizBaseColorDirty = true;
    g_vizPaletteColorsDirty = true;
    g_vizCurrentlyVisible = false;
    StopTimerThread();
    StopAudioAppThread();
    StopMediaThread();
    WaitForTrackedWorkers();
    LoadSettings();
    HWND hWnd = FindCurrentProcessTaskbarWnd();
    if (!hWnd) hWnd = g_taskbarWnd;
    if (hWnd) {
        g_taskbarWnd = hWnd;
        bool ok = RunFromWindowThread(hWnd, [](void*) {
            try {
                RemovePlayerGrid();
                if (!g_unloading) {
                    g_applyingSettings = false;
                    InjectPlayerGrid();
                    UpdateVisibility();
                    g_needsUiUpdate = true;
                }
            } catch (...) {
                Wh_Log(L"Wh_ModSettingsChanged: Exception during RemovePlayerGrid/InjectPlayerGrid");
                SetCurrentPlayerInstance(nullptr);
                g_playerInstances.clear();
            }
        }, nullptr);
        if (!ok) {
            Wh_Log(L"Wh_ModSettingsChanged: RunFromWindowThread failed");
        }
    }
    g_applyingSettings = false;
    StartMediaThread();
    StartTimerThread();
    StartAudioAppThread();
}

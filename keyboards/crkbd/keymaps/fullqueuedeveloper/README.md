# The `fullqueuedeveloper` Layout

This layout offers Miryoku with a plain layer for gaming (no tap-mods).

This layout is based on Miryoku, the default Sofle layout, and other tricks.

    make crkbd:fullqueuedeveloper && make crkbd:fullqueuedeveloper:dfu

## The `ADJUST` Layer

Each base layer offers quick access to the `ADJUST` layer to easily swap
between the three modes. The `ADJUST` layer also offers a button to swap
between "Windows" and "Mac" mode. The modes differ by swapping the "GUI" key
and the "Control" key, and how they send "Copy", "Paste", "end-of-line", and
other commands.

## The OLED

The OLED displays the current base layer along with the currently active
sublayer. It highlights `SGAC` (`SCAG` on Windows) for active modifier keys.
It displays whether capslock is activated. It also displays the current OS
mode: `Mac` or `Win`

## Volume

The "touch bar" on MacBook Pros taught me that I vales quick volume access.
Therefore, the far-right column on each layer is for volume control. To easily
quiet loud noises, mute is on the top row and volume-down is on the bottom row.
Volume-up usually isn't an emergency button compared to the other two, and is
on the middle row.

# Dactyl LightCycle

See https://github.com/adereth/dactyl-keyboard
The LightCycle version is a smaller version of the normal Dactyl keyboard, see https://github.com/adereth/dactyl-keyboard/blob/master/things/lightcycle-cherry-top-left.stl

The Dactyl LightCycle uses the [Teensy Loader](https://www.pjrc.com/teensy/loader.html).

Linux users need to modify udev rules as described on the [Teensy
Linux page].  Some distributions provide a binary, maybe called
`teensy-loader-cli`.

[Teensy Linux page]: https://www.pjrc.com/teensy/loader_linux.html

To flash the firmware:

  - Build the firmware with `make handwired/dactyl_lightcycle:<keymapname>`, for example `make handwired/dactyl_lightcycle:default`
  - This will result in a hex file called `handwired_dactyl_lightcycle_<keymapname>.hex`, e.g.
    `handwired_dactyl_lightcycle_default.hex`

  - Start the teensy loader.

  - Load the .hex file into it.

  - Put the Teensy in firmware-loading mode:
    * If your current layout has a RESET key, press it.
    * If you lack a RESET key, press the reset button on the Teensy board itself.

  - Click the button in the Teensy app to download the firmware.

To flash with ´teensy-loader-cli´:

  - Build the firmware as above

  - Run `<path/to/>teensy_loader_cli -mmcu=atmega32u4 -w handwired_dactyl_lightcycle_<keymapname>.hex`

  - If you like, you can do both at once: `make handwired/dactyl_lightcycle:<keymapname>:teensy`

  - Put the Teensy in firmware-loading mode:
    * If your current layout has a RESET key, press it.
    * If you lack a RESET key, press the reset button on the Teensy board itself.

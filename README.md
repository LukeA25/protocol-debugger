# Bare-Metal Protocol Debugger

## Building and Flashing

1. Clone submodules:

    ```bash
    git clone --recurse-submodules ...
    ```

2. Build `picotool`:

    ```bash
    cd external/picotool
    mkdir build && cd build
    cmake .. -DPICO_SDK_PATH=../../pico-sdk && make
    ```

3. Build project:

    ```bash
    cd bare-metal
    make
    ```

4. Flash:

    ```bash
    make flash
    ```

Make sure your Pico is in BOOTSEL mode or already running valid firmware.

# Installation

git clone https://github.com/qmk/qmk_firmware.git

cd qmk-firmware

git submodule add https://github.com/lgranie/qmk-satan-lge.git keyboards/satan/keymaps/lge

# Build

sudo make gh60/satan:lge:dfu


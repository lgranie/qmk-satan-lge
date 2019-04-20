# Installation

git clone https://github.com/qmk/qmk-firmware.git

cd qmk-firmware

git submodule add https://github.com/lgranie/qmk-satan-lge.git keyboards/satan/keymaps/lge

# Build

sudo make satan:lge:dfu


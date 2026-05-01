Import("env")

def merge_bin(source, target, env):
    env.Execute(
        "esptool.py --chip esp32 merge_bin -o $BUILD_DIR/firmware_merged.bin "
        "--flash_mode dio --flash_freq 40m --flash_size 4MB "
        "0x1000 $BUILD_DIR/bootloader.bin "
        "0x8000 $BUILD_DIR/partitions.bin "
        "0x10000 $BUILD_DIR/firmware.bin"
    )

env.AddPostAction("$BUILD_DIR/firmware.bin", merge_bin)

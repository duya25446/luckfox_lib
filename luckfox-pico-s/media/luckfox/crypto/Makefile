TOOLCHAIN_PREBUILTS := "./"
TOOLCHAIN_PATH_ARM32 := "gcc-arm-8.3-2019.03-x86_64-arm-linux-gnueabihf/bin/"
TOOLCHAIN_PATH_AARCH64 := "gcc-arm-10.3-2021.07-x86_64-aarch64-none-linux-gnu/bin/"
CROSS_COMPILE32 := "arm-linux-gnueabihf-gcc"
CROSS_COMPILE64 := "aarch64-none-linux-gnu-gcc"
ARM32_TOOLCHAIN_GCC := "${TOOLCHAIN_PREBUILTS}${TOOLCHAIN_PATH_ARM32}${CROSS_COMPILE32}"
AARCH64_TOOLCHAIN_GCC := "${TOOLCHAIN_PREBUILTS}${TOOLCHAIN_PATH_AARCH64}${CROSS_COMPILE64}"

# Entry "$make 64" for build arm64 binary, otherwise build arm binary by default.
ifeq (${bit},64)
	ARM_PLATFORM := "arm64"
	CC := ${AARCH64_TOOLCHAIN_GCC}
else
	ARM_PLATFORM := "arm"
	CC := ${ARM32_TOOLCHAIN_GCC}
endif

INCLUDE := -I./ -I./include
LIBS    := -L./lib/${ARM_PLATFORM} -lrkcrypto
CFLAGS  := -g -Wall -O2

SOURCE  := $(wildcard *.c ./src/*c)
OBJS    := $(patsubst %.c,%.o,$(SOURCE))

TARGET  := rk_crypto_test

$(TARGET): $(OBJS)
	$(CC) -o $@ $(notdir $(OBJS)) $(LIBS)
%.o:%.c
	$(CC) -c $^ $(INCLUDE) $(CFLAGS)

clean:
	rm -f $(OBJS) $(TARGET)

64:
	make bit=64

32:
	make bit=32
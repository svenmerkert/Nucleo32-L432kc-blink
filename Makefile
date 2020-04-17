PROJECT    = Blink
BOARD      = nucleo-stm32l432
CORE_DIR   = stm32core
CFLAGS    += -Os -ggdb3
CFLAGS    += -I./
OBJS      += ./blink.o

#WITH_FREERTOS = true

include stm32core/setup.mk

clean:
	cd $(OPENCM3_DIR); make clean; cd -; $(Q)$(RM) -rf binary.* *.o *.d generated.* $(FREERTOS_DIR)/*.a $(FREERTOS_DIR)/*.o $(FREERTOS_DIR)/*.d; rm -f $(OBJS)

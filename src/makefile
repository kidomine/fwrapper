include localfiles.mk

APP_NAME=ftmain
TST_NAME=fttest
LIB_NAME=ftwrapper

CC=gcc
RM=rm
AR=ar

#CCOPTS=-g -c --save-temps
CCOPTS=-g -c
RMOPTS=-fr
AROPTS=q
LNOPTS=-B static

H_INC_DIR=-I./include -I/usr/include/freetype2
L_INC_DIR=-L./ -L/usr/lib/

S_LIB_DEPS=-l$(LIB_NAME)
D_LIB_DEPS=-lfreetype

_OSRC=$(patsubst %.c, %.o, $(SRCS))
_TSRC=$(patsubst %.c, %.o, $(TSRC))
_ASRC=$(patsubst %.c, %.o, $(ASRC))

LIBRARY=lib$(LIB_NAME).a

%.o : %.c
	$(CC) $(CCOPTS) $(H_INC_DIR) -o $@ $<

$(LIBRARY) : $(_OSRC)
	$(AR) $(AROPTS) $@ $(_OSRC)

$(TST_NAME) : $(LIBRARY) $(_TSRC)
	$(CC) $(L_INC_DIR) -lcunit $(D_LIB_DEPS) -o $@ $(_TSRC) \
	$(LIBRARY) -B static $(S_LIB_DEPS)

$(APP_NAME) : $(LIBRARY) $(_ASRC)
	$(CC) $(L_INC_DIR) $(D_LIB_DEPS) -o $@ $< \
	-B static $(S_LIB_DEPS)

test: $(TST_NAME)

app: $(APP_NAME)

all: $(LIBRARY)

clean:
	$(RM) $(RMOPTS) $(TST_NAME) $(_TSRC)
	$(RM) $(RMOPTS) $(APP_NAME) $(_ASRC)
	$(RM) $(RMOPTS) $(LIBRARY)  $(_OSRC)


BUILD_DIR := bin
OBJ_DIR := obj

# Needs to be set by the caller.
# ASSEMBLY := engine

DEFINES :=

# Detect OS and architecture.
ifeq ($(OS),Windows_NT)
    # WIN32
	BUILD_PLATFORM := windows
	EXTENSION := .exe
	COMPILER_FLAGS := -Wall -Werror -Wvla -Werror=vla -Wgnu-folding-constant -Wno-missing-braces -fdeclspec -Wstrict-prototypes
	INCLUDE_FLAGS := -I$(ASSEMBLY)\src $(ADDL_INC_FLAGS)
	LINKER_FLAGS := -L$(BUILD_DIR) $(ADDL_LINK_FLAGS)
	DEFINES += -D_CRT_SECURE_NO_WARNINGS

# Make does not offer a recursive wildcard function, and Windows needs one, so here it is:
	rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))
	DIR := $(subst /,\,${CURDIR})
	
	# .c files
	C_SRC_FILES := $(call rwildcard,$(ASSEMBLY)/,*.c)
	# .cpp files
	CPP_SRC_FILES := $(call rwildcard,$(ASSEMBLY)/,*.cpp)
	# directories with .h files
	DIRECTORIES := \$(ASSEMBLY)\src $(subst $(DIR),,$(shell dir $(ASSEMBLY)\src /S /AD /B | findstr /i src)) 
	C_OBJ_FILES := $(C_SRC_FILES:%=$(OBJ_DIR)/%.obj)
	CPP_OBJ_FILES := $(CPP_SRC_FILES:%=$(OBJ_DIR)/%.obj)
    ifeq ($(PROCESSOR_ARCHITEW6432),AMD64)
        # AMD64
    else
        ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
            # AMD64
        endif
        ifeq ($(PROCESSOR_ARCHITECTURE),x86)
            # IA32
        endif
    endif
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        # LINUX
		BUILD_PLATFORM := linux
		EXTENSION := 
		
		# NOTE: -fvisibility=hidden hides all symbols by default, and only those that explicitly say
		# otherwise are exported (i.e. via HAPI).
		COMPILER_FLAGS :=-fvisibility=hidden -fpic -Wall -Werror -Wvla -Wno-missing-braces -fdeclspec
		
		INCLUDE_FLAGS := -I./$(ASSEMBLY)/src $(ADDL_INC_FLAGS)
		
		# NOTE: --no-undefined and --no-allow-shlib-undefined ensure that symbols linking against are resolved.
		# These are linux-specific, as the default behaviour is the opposite of this, allowing code to compile 
		# here that would not on other platforms from not being exported (i.e. Windows)
		# Discovered the solution here for this: https://github.com/ziglang/zig/issues/8180
		LINKER_FLAGS :=-Wl,-rpath,'$$ORIGIN',--no-undefined,--no-allow-shlib-undefined -L./$(BUILD_DIR) $(ADDL_LINK_FLAGS) -Wl,-rpath
		
		# .c files
		C_SRC_FILES := $(shell find $(ASSEMBLY) -name *.c)
		CPP_SRC_FILES := $(shell find $(ASSEMBLY) -name *.cpp)
		# directories with .h files
		DIRECTORIES := $(shell find $(ASSEMBLY) -type d)
		C_OBJ_FILES := $(C_SRC_FILES:%=$(OBJ_DIR)/%.obj)
		CPP_OBJ_FILES := $(CPP_SRC_FILES:%=$(OBJ_DIR)/%.obj)
    endif
    
    UNAME_P := $(shell uname -p)
    ifeq ($(UNAME_P),x86_64)
        # AMD64
    endif
    ifneq ($(filter %86,$(UNAME_P)),)
        # IA32
    endif	
    ifneq ($(filter arm%,$(UNAME_P)),)
        # ARM
    endif
endif

# Defaults to debug unless release is specified.
ifeq ($(TARGET),release)
# release
DEFINES += -DHRELEASE
COMPILER_FLAGS += -MD -O2
else
# debug
DEFINES += -D_DEBUG
COMPILER_FLAGS += -g -MD
LINKER_FLAGS += -g -O0

ifeq ($(BUILD_PLATFORM),windows)
LINKER_FLAGS += -lmsvcrtd -llibcmt
else
LINKER_FLAGS += -lstdc++ -lm
endif
endif

all: scaffold compile link gen_compile_flags

.PHONY: scaffold
scaffold: # create build directory
ifeq ($(BUILD_PLATFORM),windows)
	-@setlocal enableextensions enabledelayedexpansion && mkdir $(addprefix $(OBJ_DIR), $(DIRECTORIES)) 2>NUL || cd .
	-@setlocal enableextensions enabledelayedexpansion && mkdir $(BUILD_DIR) 2>NUL || cd .
else
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(addprefix $(OBJ_DIR)/,$(DIRECTORIES))
endif

.PHONY: link
link: scaffold $(C_OBJ_FILES) $(CPP_OBJ_FILES) # link
	@echo Linking "$(ASSEMBLY)"...
ifeq ($(BUILD_PLATFORM),windows)
	@clang++ $(C_OBJ_FILES) $(CPP_OBJ_FILES) -o $(BUILD_DIR)\$(COMPILED_NAME)$(EXTENSION) $(LINKER_FLAGS)
else
	@clang++ $(C_OBJ_FILES) $(CPP_OBJ_FILES) -o $(BUILD_DIR)/$(COMPILED_NAME)$(EXTENSION) $(LINKER_FLAGS)
endif

.PHONY: compile
compile:
	@echo --- Performing "$(ASSEMBLY)" $(TARGET) build ---
-include $(C_OBJ_FILES:.obj=.d) $(CPP_OBJ_FILES:.obj=.d)

.PHONY: clean
clean: # clean build directory
	@echo --- Cleaning "$(ASSEMBLY)" ---
ifeq ($(BUILD_PLATFORM),windows)
	@if exist $(BUILD_DIR)\$(COMPILED_NAME)$(EXTENSION) del $(BUILD_DIR)\$(COMPILED_NAME)$(EXTENSION)
# Windows builds include a lot of files... get them all.
	@if exist $(BUILD_DIR)\$(COMPILED_NAME).* del $(BUILD_DIR)\$(COMPILED_NAME).*
	@if exist $(OBJ_DIR)\$(ASSEMBLY) rmdir /s /q $(OBJ_DIR)\$(ASSEMBLY)
else
	@rm -rf $(BUILD_DIR)/$(COMPILED_NAME)$(EXTENSION)
	@rm -rf $(OBJ_DIR)/$(ASSEMBLY)
endif

# compile .c to .obj object for windows and linux
$(OBJ_DIR)/%.c.obj: %.c 
	@echo   $<...
	@clang $< -std=c23 $(COMPILER_FLAGS) -c -o $@ $(DEFINES) $(INCLUDE_FLAGS)

-include $(C_OBJ_FILES:.obj=.d)

# compile .cpp to .obj object for windows and linux
$(OBJ_DIR)/%.cpp.obj: %.cpp 
	@echo   $<...
	@clang++ $< -std=c++23 $(COMPILER_FLAGS) -c -o $@ $(DEFINES) $(INCLUDE_FLAGS)

-include $(CPP_OBJ_FILES:.obj=.d)

.PHONY: gen_compile_flags
gen_compile_flags:
ifeq ($(BUILD_PLATFORM),windows)
	$(shell powershell \"$(INCLUDE_FLAGS) $(DEFINES)\".replace('-I', '-I..\').replace(' ', \"`n\") > $(ASSEMBLY)/compile_flags.txt)
else
	@echo $(INCLUDE_FLAGS) $(DEFINES) | tr " " "\n" | sed "s/\-I\.\//\-I\.\.\//g" > $(ASSEMBLY)/compile_flags.txt
endif
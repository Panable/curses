.PHONY: clean build

clean:
	@echo "Cleaning..."
	@rm -rf build

build: clean
	@echo "Building..."
	@mkdir -p build
	@./build.sh

run: build
	@build/./curse

all: build

.DEFAULT_GOAL := all

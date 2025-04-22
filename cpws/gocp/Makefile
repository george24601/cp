# Makefile for the gocp project

# The Go source file containing the main function
MAIN_GO=main.go

# The desired name for the compiled binary (optional, used for build)
# Defaults to the directory name if not set, or you can set it explicitly:
# BINARY_NAME=myprogram
BINARY_NAME ?= $(notdir $(CURDIR))


# --- Targets ---

# Default target: Build the project (can be changed if desired)
all: build

# 'r' command: Run the main Go file directly
r:
	@echo "Running $(MAIN_GO)..."
	go run $(MAIN_GO)

# 'build' command: Compile the Go program into an executable
build:
	@echo "Building $(BINARY_NAME) from $(MAIN_GO)..."
	go build -o $(BINARY_NAME) $(MAIN_GO)
	@echo "Build successful: ./$(BINARY_NAME)"

# 'clean' command: Remove the built executable
clean:
	@echo "Cleaning..."
	rm -f $(BINARY_NAME)

# Declare targets that do not correspond to actual files
.PHONY: all r build clean


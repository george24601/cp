.PHONY: all clean

# Set the name of the executable
EXECUTABLE := main.out
FILES := *.go

# Set the default goal
all: $(EXECUTABLE) run

# Compile the Go program into an executable
$(EXECUTABLE):
	go build -o $(EXECUTABLE) $(FILES)

# Run the executable
run:
	./$(EXECUTABLE)

test:
	go test -coverprofile=coverage.out

html:
	go tool cover -html=coverage.out

th: test html


# Clean up by removing the executable
clean:
	rm -f $(EXECUTABLE)
# Use an official base image with a C compiler (e.g., gcc)
FROM gcc:latest

# Set the working directory to /app
WORKDIR /app

# Copy the source code into the container
COPY src /app/src
COPY Makefile /app
COPY bmake.spec /app
COPY bmake.6 /app

# Build the C application
RUN make bmake

# Install the application (you may need to use sudo)
RUN make install

# Expose any necessary ports (if applicable)
# EXPOSE 80

# Define the command to run your C application
CMD ["bmake"]

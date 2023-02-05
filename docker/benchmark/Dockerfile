FROM ubuntu:latest

# Install dependencies
RUN apt-get update -y && apt-get install -y make clang bc
RUN mkdir /Luz

# Copy source files
COPY ./srcs /Luz/srcs
COPY ./includes /Luz/includes
COPY ./Makefile /Luz

# Copy scripts
COPY ./docker/benchmark/benchmark.sh /
RUN chmod +x /benchmark.sh

CMD /benchmark.sh

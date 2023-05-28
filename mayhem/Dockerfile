FROM --platform=linux/amd64 ubuntu:22.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential clang cmake libx11-dev libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev freeglut3-dev

COPY . /repo
WORKDIR /repo/build

RUN cmake ..
RUN make -j8
RUN make install
RUN clang++ /repo/mayhem/fuzz_has_edge_property.cpp -I /repo/external/eigen/ -std=c++17 /usr/local/lib/libpmp.so -fsanitize=fuzzer,address -o /fuzz

FROM ubuntu:22.04 as package

COPY --from=builder /usr/local/lib/libpmp* /deps/
COPY --from=builder /fuzz /fuzz_has_edge_property
ENV LD_LIBRARY_PATH=/deps

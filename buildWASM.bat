emcmake cmake -S . -B "build\WASM" -G "Ninja" && cmake --build "build\WASM"

rem python -m http.server 8080
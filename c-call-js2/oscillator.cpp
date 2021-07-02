#include <emscripten/val.h>

#include <stdio.h>
#include <math.h>

using namespace emscripten;

int main() {
    val AudioContext = val::global("AudioContext");
    if(!AudioContext.as<bool>()) {
        printf("No global AudioContext");
    }

    printf("Got an AudioContext");
    val context = AudioContext.new_();
    val oscillator = context.call<val>("createOscillator");

    printf("Configuring oscillator\n");
    oscillator.set("type", val("triangle"));
    oscillator["frequency"].set("value", val(261.63)); // Middle C

    printf("Playing\n");
    oscillator.call<void>("connect", context["destination"]);
    oscillator.call<void>("start", 0);

    printf("All done!\n");
}


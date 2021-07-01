
#include <emscripten/bind.h>
#include <algorithm>

using namespace emscripten;

struct ProcessMessageOpts
{
    bool reverse;
    bool exclaim;
    int repeat;
};

std::string processMessage(std::string message, ProcessMessageOpts opts) {
    std::string copy = std::string(message);
    if (opts.reverse) {
        std::reverse(copy.begin(), copy.end());
    }
    if (opts.exclaim) {
        copy += "!";
    }
    std::string acc = std::string("");
    for(int i = 0; i < opts.repeat; i++) {
        acc += copy;
    }
    return acc;
}

EMSCRIPTEN_BINDINGS(my_module) {
    value_object<ProcessMessageOpts>("ProcessMessageOpts")
    .field("reverse", &ProcessMessageOpts::reverse)
    .field("exclaim", &ProcessMessageOpts::exclaim)
    .field("repeat", &ProcessMessageOpts::repeat);

    function("processMessage", &processMessage);
}

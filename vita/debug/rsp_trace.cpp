// Debugging: records, at every label of the traced audio microcode, a hash of the
// scalar and vector registers, to compare a task's run on the Vita with a native one.
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>

static std::vector<uint32_t> trace;
static std::vector<uint8_t> vu_states;

static uint32_t fnv(const void* data, size_t size, uint32_t h = 0x811C9DC5u) {
    const uint8_t* p = (const uint8_t*)data;
    for (size_t i = 0; i < size; i++) h = (h ^ p[i]) * 0x01000193u;
    return h;
}

void rsp_trace_record(uint32_t label, const uint32_t* regs, const void* vu, size_t) {
    if (trace.size() > 6000000) return;
    trace.push_back(label);
    trace.push_back(fnv(regs, 31 * 4));
    // The vector unit's registers, accumulators and flags: 41 128-bit values.
    vu_states.insert(vu_states.end(), (const uint8_t*)vu, (const uint8_t*)vu + 41 * 16);
    trace.push_back(fnv(vu, 32 * 16)); trace.push_back(fnv((const uint8_t*)vu + 32 * 16, 3 * 16)); trace.push_back(fnv((const uint8_t*)vu + 35 * 16, 6 * 16));
}

void rsp_trace_write(const char* path) {
    if (FILE* f = std::fopen(path, "wb")) {
        std::fwrite(trace.data(), 4, trace.size(), f);
        std::fclose(f);
    }
    std::string vp = std::string(path) + ".vu";
    if (FILE* f = std::fopen(vp.c_str(), "wb")) {
        std::fwrite(vu_states.data(), 1, vu_states.size(), f);
        std::fclose(f);
    }
}


// outputs a c++ const int32 array containing a linearly decaying sine wave to stdout.

#include <iostream>
#include <string>
#include <math.h>
#include <limits>

float samplerate = 48000.f;
float freq = 2000.f;
float lengthSeconds = 0.05f;

float lengthSamples = lengthSeconds * samplerate;
float samplesPerPeriod = samplerate / freq;
float delta = 6.2831853072 / samplesPerPeriod; 

int main()
{
    std::cout << "const int32_t ping[" << lengthSamples << "] = \n{";
    for(uint32_t i=0;i<lengthSamples;i++)
    {
        if(i % 8 == 0)
            std::cout << "\n\t";
        
        float amplitude = (lengthSamples - i) / lengthSamples;
        std::cout << std::fixed << (int32_t)(sin(i * delta) * std::numeric_limits<int32_t>::max() * amplitude) << ", ";
    }
    std::cout << "\n};\n";
}

#include "functions.h"

namespace Interpolators
{
    double lerp(double start, double end, double progress)
    {
        return start + (end - start) * progress;
    }

    double easeInQuad(double progress)
    {
        return progress * progress;
    }

    double easeOutQuad(double progress)
    {
        return 1.0 - (1.0 - progress) * (1.0 - progress);
    }
}

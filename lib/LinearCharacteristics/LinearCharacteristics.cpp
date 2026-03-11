#include "LinearCharacteristics.h"

using namespace std;

LinearCharacteristics::LinearCharacteristics(float gain, float offset)
{
    m_gain = gain;
    m_offset = offset;
    m_ulim = 999999.0f;  // a large number
    m_llim = -999999.0f; // a large neg. number
}

LinearCharacteristics::~LinearCharacteristics() {}

float LinearCharacteristics::evaluate(float x)
{
    // calculate result as y(x) = gain * (x - offset)
    // Aufgabe 1.3
    float ret_val = m_gain * (x - m_offset);
    
    //Aufgabe 1.4: check limits
    if (ret_val > m_ulim) {
        return m_ulim;
    } else if (ret_val < m_llim) {
        return m_llim;
    }

    return ret_val;
}

void LinearCharacteristics::set_limits(float ll, float ul)
{
    m_llim = ll;
    m_ulim = ul;
}

// Aufgabe 1.5: constructor with limits
LinearCharacteristics::LinearCharacteristics(float x_min, float x_max, float y_min, float y_max)
{
    m_gain = (y_max - y_min) / (x_max - x_min);
    m_offset = x_min - y_min / m_gain;
    m_ulim = y_max;
    m_llim = y_min;
}

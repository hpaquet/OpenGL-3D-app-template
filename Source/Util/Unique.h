
#ifndef WAVEINTERFERENCE_UNIQUE_H
#define WAVEINTERFERENCE_UNIQUE_H


struct Unique
{
    Unique() = default;
    Unique(const Unique&) = delete;
    Unique& operator=(const Unique&) = delete;
};


#endif //WAVEINTERFERENCE_UNIQUE_H

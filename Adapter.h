#ifndef ADAPTER_H
#define ADAPTER_H

#include <iostream>

class Scales
{
public:
    Scales(){}
    virtual ~Scales(){}
    virtual float *getWeight() = 0;
};

class PoundScales : public Scales
{
private:
    float *currentWeight;

public:
    PoundScales(float *cw) : currentWeight(cw) {}
    ~PoundScales() override
    {
        currentWeight = nullptr;
    }
    virtual float* getWeight() override
    {
        return currentWeight;
    }
};

class KiloScales : public Scales
{
private:
    float *currentWeight;

public:
    KiloScales(float *cw) : currentWeight(cw){}
    ~KiloScales() override
    {
        currentWeight = nullptr;
    }
    virtual float *getWeight() override
    {
        return currentWeight;
    }
};

class Adapter : public Scales
{
public:
    Adapter(PoundScales* pund) : pundWeight(pund), currentWeight(0) {}
    ~Adapter()
    {
//        delete pundWeight;
//        delete currentWeight;
    }

    virtual float *getWeight() override
    {
        currentWeight = pundWeight->getWeight();
        *currentWeight = *currentWeight * 0.453;
        return currentWeight;
    }

private:
    PoundScales *pundWeight;
    float *currentWeight;
};

void runAdapter()
{
    float kg {55.f};
    float pnd {55.f};

    Scales *kgScales = new KiloScales(&kg);
    Scales *pnScales = new Adapter(new PoundScales(&pnd));

    std::cout << *kgScales->getWeight() << std::endl;
    std::cout << *pnScales->getWeight() << std::endl;

    delete kgScales;
    delete pnScales;
}

#endif // ADAPTER_H

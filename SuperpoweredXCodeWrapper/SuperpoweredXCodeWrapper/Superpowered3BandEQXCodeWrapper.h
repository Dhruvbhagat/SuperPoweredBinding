//
//  SuperpoweredFXXCodeWrapper.h
//  SuperpoweredXCodeWrapper
//
//  Created by Administrator on 5/15/18.
//  Copyright © 2018 Bryon Baker. All rights reserved.
//

#ifndef SuperpoweredFXXCodeWrapper_h
#define SuperpoweredFXXCodeWrapper_h

#include <stdio.h>
#include "Superpowered3BandEQ.h"

extern "C" Superpowered3BandEQ* Superpowered3BandEQ_Create(unsigned int samplerate);

extern "C" void Superpowered3BandEQ_Enable(Superpowered3BandEQ* pObject, bool flag);

extern "C" void Superpowered3BandEQ_SetSamplerate(Superpowered3BandEQ* pObject, unsigned int samplerate);

extern "C" void Superpowered3BandEQ_Reset(Superpowered3BandEQ* pObject);

extern "C" bool Superpowered3BandEQ_Process(Superpowered3BandEQ* pObject, float *input, float *output, unsigned int numberOfSamples);

extern "C" void Superpowered3BandEQ_Dispose(Superpowered3BandEQ* pObject);

#endif /* SuperpoweredFXXCodeWrapper_h */

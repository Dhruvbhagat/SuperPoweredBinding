//
//  SuperpoweredSimpleXCodeWrapper.cpp
//  SuperpoweredXCodeWrapper
//
//  Created by Bryon on 6/09/2015.
//  Copyright (c) 2015 Bryon Baker. All rights reserved.
//

#include "SuperpoweredWrapperUtilities.h"
#include "SuperpoweredSimpleXCodeWrapper.h"

void SuperpoweredSimple_SuperpoweredVolume(float input[], float output[], float volumeStart, float volumeEnd, unsigned int numberOfSamples)
{
    try
    {
        // Number of samples must be divisible by 4.
        if( numberOfSamples % 4 != 0 )
        {
            WriteErrorToSyslog( "ERROR: numberOfSamples must be divisible by 4 in SuperpoweredSimple_SuperpoweredInterleave()\n" );
            
            return;
        }
        
        SuperpoweredVolume(input, output, volumeStart, volumeEnd, numberOfSamples);
        
        return;
    }
    catch ( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredSimple_SuperpoweredVolume().\n" );
    }
    return;
}

void SuperpoweredSimple_SuperpoweredChangeVolume(float input[], float output[], float volumeStart, float volumeChange, unsigned int numberOfSamples)
{
    try
    {
        // Number of samples must be divisible by 4.
        if( numberOfSamples % 4 != 0 )
        {
            WriteErrorToSyslog( "ERROR: numberOfSamples must be divisible by 4 in SuperpoweredSimple_SuperpoweredInterleave()\n" );
            
            return;
        }
        
        SuperpoweredChangeVolume(input, output, volumeStart, volumeChange, numberOfSamples);
        
        return;
    }
    catch ( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredSimple_SuperpoweredChangeVolume().\n" );
    }
    return;
}

void SuperpoweredSimple_SuperpoweredVolumeAdd(float input[], float output[], float volumeStart, float volumeEnd, unsigned int numberOfSamples)
{
    try
    {
        // Number of samples must be divisible by 4.
        if( numberOfSamples % 4 != 0 )
        {
            WriteErrorToSyslog( "ERROR: numberOfSamples must be divisible by 4 in SuperpoweredSimple_SuperpoweredInterleave()\n" );
            
            return;
        }
        
        SuperpoweredVolumeAdd(input, output, volumeStart, volumeEnd, numberOfSamples);
        
        return;
    }
    catch ( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredSimple_SuperpoweredVolumeAdd().\n" );
    }
    return;
}

void SuperpoweredSimple_SuperpoweredChangeVolumeAdd(float input[], float output[], float volumeStart, float volumeChange, unsigned int numberOfSamples)
{
    try
    {
        // Number of samples must be divisible by 4.
        if( numberOfSamples % 4 != 0 )
        {
            WriteErrorToSyslog( "ERROR: numberOfSamples must be divisible by 4 in SuperpoweredSimple_SuperpoweredInterleave()\n" );
            
            return;
        }
        
        SuperpoweredChangeVolumeAdd(input, output, volumeStart, volumeChange, numberOfSamples);
        
        return;
    }
    catch ( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredSimple_SuperpoweredChangeVolumeAdd().\n" );
    }
    return;
}

float SuperpoweredSimple_SuperpoweredPeak(float input[], unsigned int numberOfValues)
{
    try
    {
        return SuperpoweredPeak(input, numberOfValues);
    }
    catch ( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredSimple_SuperpoweredPeak().\n" );
    }
    return 0;
}

void SuperpoweredSimple_SuperpoweredCharToFloat(signed char input[], float output[], unsigned int numberOfSamples, unsigned int numChannels)
{
    try
    {
        // Number of samples must be divisible by 4.
        if( numberOfSamples % 4 != 0 )
        {
            WriteErrorToSyslog( "ERROR: numberOfSamples must be divisible by 4 in SuperpoweredSimple_SuperpoweredInterleave()\n" );
            
            return;
        }
        
        SuperpoweredCharToFloat(input, output, numberOfSamples, numChannels);
        
        return;
    }
    catch ( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredSimple_SuperpoweredCharToFloat().\n" );
    }
    return;
}

void SuperpoweredSimple_SuperpoweredFloatToChar(float input[], signed char output[], unsigned int numberOfSamples, unsigned int numChannels)
{
    try
    {
        // Number of samples must be divisible by 4.
        if( numberOfSamples % 4 != 0 )
        {
            WriteErrorToSyslog( "ERROR: numberOfSamples must be divisible by 4 in SuperpoweredSimple_SuperpoweredFloatToChar()\n" );
            
            return;
        }
        
        SuperpoweredFloatToChar(input, output, numberOfSamples, numChannels);
        
        return;
    }
    catch ( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredSimple_SuperpoweredFloatToChar().\n" );
    }
    return;
}

void SuperpoweredSimple_Superpowered24bitToFloat(float input[], float output[], unsigned int numberOfSamples, unsigned int numChannels)
{
    try
    {
        // Number of samples must be divisible by 4.
        if( numberOfSamples % 4 != 0 )
        {
            WriteErrorToSyslog( "ERROR: numberOfSamples must be divisible by 4 in SuperpoweredSimple_Superpowered24bitToFloat()\n" );
            
            return;
        }
        
        Superpowered24bitToFloat(input, output, numberOfSamples, numChannels);
        
        return;
    }
    catch ( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredSimple_Superpowered24bitToFloat().\n" );
    }
    return;
}

void SuperpoweredSimple_SuperpoweredFloatTo24bit(float input[], float output[], unsigned int numberOfSamples, unsigned int numChannels)
{
    try
    {
        // Number of samples must be divisible by 4.
        if( numberOfSamples % 4 != 0 )
        {
            WriteErrorToSyslog( "ERROR: numberOfSamples must be divisible by 4 in SuperpoweredSimple_SuperpoweredFloatTo24bit()\n" );
            
            return;
        }
        
        SuperpoweredFloatTo24bit(input, output, numberOfSamples, numChannels);
        
        return;
    }
    catch ( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredSimple_SuperpoweredFloatTo24bit().\n" );
    }
    return;
}

void SuperpoweredSimple_SuperpoweredIntToFloat(int input[], float output[], unsigned int numberOfSamples, unsigned int numChannels)
{
    try
    {
        // Number of samples must be divisible by 4.
        if( numberOfSamples % 4 != 0 )
        {
            WriteErrorToSyslog( "ERROR: numberOfSamples must be divisible by 4 in SuperpoweredSimple_SuperpoweredIntToFloat()\n" );
            
            return;
        }
        
        SuperpoweredIntToFloat(input, output, numberOfSamples, numChannels);
        
        return;
    }
    catch ( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredSimple_SuperpoweredIntToFloat().\n" );
    }
    return;
}

void SuperpoweredSimple_SuperpoweredFloatToInt(float input[], int output[], unsigned int numberOfSamples, unsigned int numChannels)
{
    try
    {
        // Number of samples must be divisible by 4.
        if( numberOfSamples % 4 != 0 )
        {
            WriteErrorToSyslog( "ERROR: numberOfSamples must be divisible by 4 in SuperpoweredSimple_SuperpoweredFloatToInt()\n" );
            
            return;
        }
        
        SuperpoweredFloatToInt(input, output, numberOfSamples, numChannels);
        
        return;
    }
    catch ( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredSimple_SuperpoweredFloatToInt().\n" );
    }
    return;
}

void SuperpoweredSimple_SuperpoweredFloatToShortInt(float input[], short int output[], unsigned int numberOfSamples, unsigned int numChannels)
{
    try
    {
        // Number of samples must be divisible by 4.
        if( numberOfSamples % 4 != 0 )
        {
            WriteErrorToSyslog( "ERROR: numberOfSamples must be divisible by 4 in SuperpoweredSimple_SuperpoweredFloatToShortInt()\n" );
            
            return;
        }
        
        SuperpoweredFloatToShortInt(input, output, numberOfSamples, numChannels);
        
        return;
    }
    catch ( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredSimple_SuperpoweredFloatToShortInt().\n" );
    }
    return;
}

void SuperpoweredSimple_SuperpoweredFloatToShortIntInterleave(float inputLeft[], float inputRight[], short int output[], unsigned int numberOfSamples)
{
    try
    {
        // Number of samples must be divisible by 4.
        if( numberOfSamples % 4 != 0 )
        {
            WriteErrorToSyslog( "ERROR: numberOfSamples must be divisible by 4 in SuperpoweredSimple_SuperpoweredFloatToShortIntInterleave()\n" );
            
            return;
        }
        
        SuperpoweredFloatToShortIntInterleave(inputLeft, inputRight, output, numberOfSamples);
        
        return;
    }
    catch ( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredSimple_SuperpoweredFloatToShortIntInterleave().\n" );
    }
    return;
}

void SuperpoweredSimple_SuperpoweredShortIntToFloat(short int input[], float output[], unsigned int numberOfSamples, float peaks[])
{
    try
    {
        // Number of samples must be divisible by 4.
        if( numberOfSamples % 4 != 0 )
        {
            WriteErrorToSyslog( "ERROR: numberOfSamples must be divisible by 4 in SuperpoweredSimple_SuperpoweredShortIntToFloat()\n" );
            
            return;
        }
        
        SuperpoweredShortIntToFloat(input, output, numberOfSamples, peaks);
        
        return;
    }
    catch ( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredSimple_SuperpoweredShortIntToFloat().\n" );
    }
    return;
}

void SuperpoweredSimple_SuperpoweredInterleave(float left[], float right[], float output[], unsigned int numberOfSamples)
{
    try
    {        
        // Number of samples must be divisible by 4.
        if( numberOfSamples % 4 != 0 )
        {
            WriteErrorToSyslog( "ERROR: numberOfSamples must be divisible by 4 in SuperpoweredSimple_SuperpoweredInterleave()\n" );
            
            return;
        }
        
        SuperpoweredInterleave(left, right, output, numberOfSamples);
        
        return;
    }
    catch ( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredSimple_SuperpoweredInterleave().\n" );
    }

    return;
}

void SuperpoweredSimple_SuperpoweredInterleaveAdd(float left[], float right[], float output[], unsigned int numberOfSamples)
{
    try
    {
        // Number of samples must be divisible by 4.
        if( numberOfSamples % 4 != 0 )
        {
            WriteErrorToSyslog( "ERROR: numberOfSamples must be divisible by 4 in SuperpoweredSimple_SuperpoweredInterleaveAdd()\n" );
            
            return;
        }
        
        SuperpoweredInterleaveAdd(left, right, output, numberOfSamples);
        
        return;
    }
    catch ( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredSimple_SuperpoweredInterleaveAdd().\n" );
    }
    
    return;
}

void SuperpoweredSimple_SuperpoweredInterleaveAndGetPeaks(float left[], float right[], float output[], unsigned int numberOfSamples, float peaks[])
{
    try
    {
        // Number of samples must be divisible by 4.
        if( numberOfSamples % 4 != 0 )
        {
            WriteErrorToSyslog( "ERROR: numberOfSamples must be divisible by 4 in SuperpoweredSimple_SuperpoweredInterleaveAndGetPeaks()\n" );
            
            return;
        }
        
        SuperpoweredInterleaveAndGetPeaks(left, right, output, numberOfSamples, peaks);
        
        return;
    }
    catch ( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredSimple_SuperpoweredInterleaveAndGetPeaks().\n" );
    }
    
    return;
}

void SuperpoweredSimple_SuperpoweredDeInterleave(float input[], float left[], float right[], unsigned int numberOfSamples)
{
    try
    {
        // Number of samples must be divisible by 4.
        if( numberOfSamples % 4 != 0 )
        {
            WriteErrorToSyslog( "ERROR: numberOfSamples must be divisible by 4 in SuperpoweredSimple_SuperpoweredDeInterleave()\n" );
            
            return;
        }
        
        SuperpoweredDeInterleave(input, left, right, numberOfSamples);
        
        return;
    }
    catch ( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredSimple_SuperpoweredDeInterleave().\n" );
    }
    
    return;
}

void SuperpoweredSimple_SuperpoweredDeInterleaveAdd(float input[], float left[], float right[], unsigned int numberOfSamples)
{
    try
    {
        // Number of samples must be divisible by 4.
        if( numberOfSamples % 4 != 0 )
        {
            WriteErrorToSyslog( "ERROR: numberOfSamples must be divisible by 4 in SuperpoweredSimple_SuperpoweredDeInterleaveAdd()\n" );
            
            return;
        }
        
        SuperpoweredDeInterleaveAdd(input, left, right, numberOfSamples);
        
        return;
    }
    catch ( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredSimple_SuperpoweredDeInterleaveAdd().\n" );
    }
    
    return;
}

bool SuperpoweredSimple_SuperpoweredHasNonFinite(float buffer[], unsigned int numberOfValues)
{
    
    return false;
}

void SuperpoweredSimple_SuperpoweredStereoToMono(float input[], float output[], float leftGainStart, float leftGainEnd, float rightGainStart, float rightGainEnd, unsigned int numberOfSamples)
{
    try
    {
        // Number of samples must be divisible by 4.
        if( numberOfSamples % 4 != 0 )
        {
            WriteErrorToSyslog( "ERROR: numberOfSamples must be divisible by 4 in SuperpoweredSimple_SuperpoweredStereoToMono()\n" );
            
            return;
        }
        
        SuperpoweredStereoToMono(input, output, leftGainStart, leftGainEnd, rightGainStart, rightGainEnd, numberOfSamples);
        
        return;
    }
    catch ( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredSimple_SuperpoweredStereoToMono().\n" );
    }
    
    return;
}


void SuperpoweredSimple_SuperpoweredStereoToMono2(float input[], float output0[], float output1[], float leftGainStart, float leftGainEnd, float rightGainStart, float rightGainEnd, unsigned int numberOfSamples)
{
    try
    {
        // Number of samples must be divisible by 4.
        if( numberOfSamples % 4 != 0 )
        {
            WriteErrorToSyslog( "ERROR: numberOfSamples must be divisible by 4 in SuperpoweredSimple_SuperpoweredStereoToMono2()\n" );
            
            return;
        }
        
        SuperpoweredStereoToMono2(input, output0, output1, leftGainStart, leftGainEnd, rightGainStart, rightGainEnd, numberOfSamples);
        
        return;
    }
    catch ( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredSimple_SuperpoweredStereoToMono2().\n" );
    }
    
    return;
}


void SuperpoweredSimple_SuperpoweredCrossMono(float left[], float right[], float output[], float leftGainStart, float leftGainEnd, float rightGainStart, float rightGainEnd, unsigned int numberOfSamples)
{
    try
    {
        // Number of samples must be divisible by 4.
        if( numberOfSamples % 4 != 0 )
        {
            WriteErrorToSyslog( "ERROR: numberOfSamples must be divisible by 4 in SuperpoweredSimple_SuperpoweredCrossMono()\n" );
            
            return;
        }
        
        SuperpoweredCrossMono(left, right, output, leftGainStart, leftGainEnd, rightGainStart, rightGainEnd, numberOfSamples);
        
        return;
    }
    catch ( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredSimple_SuperpoweredCrossMono().\n" );
    }
    
    return;
}

void SuperpoweredSimple_SuperpoweredCrossMono2(float left[], float right[], float output0[], float output1[], float leftGainStart, float leftGainEnd, float rightGainStart, float rightGainEnd, unsigned int numberOfSamples)
{
    try
    {
        // Number of samples must be divisible by 4.
        if( numberOfSamples % 4 != 0 )
        {
            WriteErrorToSyslog( "ERROR: numberOfSamples must be divisible by 4 in SuperpoweredSimple_SuperpoweredCrossMono2()\n" );
            
            return;
        }
        
        SuperpoweredCrossMono2(left, right, output0, output1, leftGainStart, leftGainEnd, rightGainStart, rightGainEnd, numberOfSamples);
        
        return;
    }
    catch ( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredSimple_SuperpoweredCrossMono2().\n" );
    }
    
    return;
}

void SuperpoweredSimple_SuperpoweredCrossStereo(float inputA[], float inputB[], float output[], float gainStart[4], float gainEnd[4], unsigned int numberOfSamples)
{
    try
    {
        // Number of samples must be divisible by 4.
        if( numberOfSamples % 4 != 0 )
        {
            WriteErrorToSyslog( "ERROR: numberOfSamples must be divisible by 4 in SuperpoweredSimple_SuperpoweredCrossStereo()\n" );
            
            return;
        }
        
        SuperpoweredCrossStereo(inputA, inputB, output, gainStart, gainEnd, numberOfSamples);
        
        return;
    }
    catch ( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredSimple_SuperpoweredCrossStereo().\n" );
    }
    
    return;
}

void SuperpoweredSimple_SuperpoweredAdd1(float input[], float output[], unsigned int numberOfValues)
{
    try
    {
        SuperpoweredAdd1(input, output, numberOfValues);
        
        return;
    }
    catch ( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredSimple_SuperpoweredAdd1().\n" );
    }
    
    return;
}

void SuperpoweredSimple_SuperpoweredAdd2(float inputA[], float inputB[], float output[], unsigned int numberOfValues)
{
    try
    {
        SuperpoweredAdd2(inputA, inputB, output, numberOfValues);
        
        return;
    }
    catch ( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredSimple_SuperpoweredAdd2().\n" );
    }
    
    return;
}

void SuperpoweredSimple_SuperpoweredAdd4(float inputA[], float inputB[], float inputC[], float inputD[], float output[], unsigned int numberOfValues)
{
    try
    {
        SuperpoweredAdd4(inputA, inputB, inputC, inputD, output, numberOfValues);
        
        return;
    }
    catch ( ... ) // You cannot allow an exception to propagate from unmanaged code into managed code.
    
    {
        WriteErrorToSyslog( "Exception thrown in unmanaged code SuperpoweredSimple_SuperpoweredAdd4().\n" );
    }
    
    return;
}



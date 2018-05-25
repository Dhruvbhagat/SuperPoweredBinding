//
//  SuperpoweredWrapperUtilities.cpp
//  SuperpoweredXCodeWrapper
//
//  Created by Bryon on 6/09/2015.
//  Copyright (c) 2015 Bryon Baker. All rights reserved.
//

#include "SuperpoweredWrapperUtilities.h"
#include <stdio.h>

/**
 @brief Writes an error message to syslog.
 
 @param input Pointer to the message to write.
 */
void WriteErrorToSyslog( const char *msg )
{
    // REVISIT: Write an error to the syslog.
    fprintf( stderr, "%s", msg );
    
    return;
}
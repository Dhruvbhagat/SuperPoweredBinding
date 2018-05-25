//
//  SuperpoweredFrequencies.h
//  SuperpoweredXCodeWrapper
//
//  Created by Bryon on 16/09/2015.
//  Copyright (c) 2015 Bryon Baker. All rights reserved.
//

#ifndef SuperpoweredXCodeWrapper_SuperpoweredFrequencies_h
#define SuperpoweredXCodeWrapper_SuperpoweredFrequencies_h

#import <Foundation/Foundation.h>

@interface SuperpoweredFrequencies: NSObject

- (void)getFrequencies:(float *)freqs;

- (void)offlineFilter:(NSURL *)url outputs:(NSString *) outputFile progress:(double *)progress;

- (void)offlineTimeStretching:(NSURL *)url outputs:(NSString *) outputFile progress:(double *)progress;

- (void)offlineAnalyze:(NSURL *)url progress:(double *)progress;

@end

#endif

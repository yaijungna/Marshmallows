/**
 \addtogroup Marshmallows
 \author     Created by Hari Karam Singh on 14/08/2012.
 \copyright  Copyright (c) 2012. All rights reserved.
 @{
 */
/// \file AUMUnitProtocol.h

#import <Foundation/Foundation.h>
#import <AudioToolbox/AudioToolbox.h>


/** \brief Semi-private protocol for AUMUnits.  Used internally and for those wishing to make custom AUMUnits. Should be THREAD SAFE
 
 Underscore props are considered AUM Lib package scope, which includes if you subclass but doesnt include client public access.
 
 \section Stream Formats
 These are specified by the units for two reason: first, to simplify implementation by the client, and second because some of the AUM units which use their own RCB's need to mandate the I/O formats as we don't want to mimick Apple's auto-conversion (which we still leverage to get from/to the hardware I/O).  
 
 Clients can simply read the property and enforce their related streams (eg from a file) to match.
 */
@protocol AUMUnitProtocol <NSObject>

@required

@property (atomic, setter=_setGraphRef:) AUGraph _graphRef;       ///< The containing graph
@property (atomic, setter=_setNodeRef:) AUNode _nodeRef;         ///< The node in the graph
@property (atomic, setter=_setAudioUnitRef:) AudioUnit _audioUnitRef; ///< The audio unit opened from the graph

/// \name AUcompDesc Unit Component Description consts
/// @{

@property (atomic, readonly) const AudioComponentDescription _audioComponentDescription;

/** Number of the max bus. ie 0 for 1 bus, 9 for 10 busses.  -1 for none (eg an AU with external no input) */
@property (atomic, readonly) const NSInteger maxInputBusNum;
@property (atomic, readonly) const NSInteger maxOutputBusNum;

/** Stream formats required by the internal code of the AUMUnit */
@property (atomic, readonly) const AudioStreamBasicDescription inputStreamFormat;
@property (atomic, readonly) const AudioStreamBasicDescription outputStreamFormat;

/// @}


@optional

/** Event notification called by AUMGraph when added to the graph.  At this point, _nodeReg and _audioUnitRef have been set */
- (void)_nodeWasAddedToGraph;


@end

/// @}
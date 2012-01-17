//
//  MAImageLayer.m
//  AirPluckHarp
//
//  Created by Hari Karam Singh on 13/01/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "MAImageLayer.h"

@implementation MAImageLayer

@synthesize image;


/** ********************************************************************************************************************/
#pragma mark -
#pragma mark Class Methods

+ (id)layerWithImage:(UIImage *)theImage 
{
    MAImageLayer *newLayer = [[self alloc] initWithImage:theImage];
    return newLayer;
}


/** ********************************************************************************************************************/
#pragma mark -
#pragma mark Life Cycle

- (id)initWithImage:(UIImage *)theImage
{
    if (self = [super init]) {
        image = theImage;
        
        // Draw the image 
        self.contentsScale = 2.0;
        
        UIGraphicsBeginImageContextWithOptions(image.size, NO, 0.0);
        [image drawAtPoint:CGPointMake(0, 0)];
        
        self.bounds = CGRectMake(0, 0, image.size.width, image.size.height);
        self.contents = (__bridge id)UIGraphicsGetImageFromCurrentImageContext().CGImage;
        
        UIGraphicsEndImageContext();
    }
    return self;
}

/** ********************************************************************/

/// Overide to copy additional fields
- (id)initWithLayer:(MAImageLayer *)layer
{
    if (self = [super initWithLayer:layer]) {
        image = layer.image;
    }
    return self;
}

@end
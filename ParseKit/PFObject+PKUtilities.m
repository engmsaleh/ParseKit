//
//  PFObject+PKUtilities.m
//  ParseKit
//
//  Created by Ashkon Farhangi on 2/25/14.
//  Copyright (c) 2014 Ashkon Farhangi. All rights reserved.
//

#import "PFObject+PKUtilities.h"

@implementation PFObject (PKUtilities)

- (BOOL)pk_equalTo:(PFObject *)object
{
    return [self.objectId isEqualToString:object.objectId];
}

@end

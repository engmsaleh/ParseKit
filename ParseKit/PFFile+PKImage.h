//
//  PFFile+PKImage.h
//  ParseKit
//
//  Created by Ashkon Farhangi on 2/25/14.
//  Copyright (c) 2014 Ashkon Farhangi. All rights reserved.
//

#import <Parse/Parse.h>

@interface PFFile (PKImage)

// Calling the completion block "block" is consistent with Parse's style
- (void)pk_getImageWithBlock:(void (^)(UIImage *image))block;

@end

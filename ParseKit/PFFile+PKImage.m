//
//  PFFile+PKImage.m
//  ParseKit
//
//  Created by Ashkon Farhangi on 2/25/14.
//  Copyright (c) 2014 Ashkon Farhangi. All rights reserved.
//

#import "PFFile+PKImage.h"

@implementation PFFile (PKImage)

- (void)pk_getImageWithBlock:(void (^)(UIImage *image))block
{
    [self getDataInBackgroundWithBlock:^(NSData *imageData, NSError *error) {
        UIImage *image = nil;
        if (!error) {
            image = [UIImage imageWithData:imageData];
        }

        if (block) {
            block(image);
        }
    }];
}

@end

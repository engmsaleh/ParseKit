//
//  UIView+_PKPrivate.m
//  ParseKit
//
//  Created by Ashkon Farhangi on 2/25/14.
//  Copyright (c) 2014 Ashkon Farhangi. All rights reserved.
//

#import "UIView+_PKPrivate.h"

#import "PFFile+PKImage.h"

@implementation UIView (_PKPrivate)

- (void)pk_setImageWithFile:(PFFile *)file adjustment:(UIImage * (^)(UIImage *image))adjustment showActivityIndicator:(BOOL)showActivityIndicator setter:(void (^)(UIImage *image))setter
{
    if (setter && file) {
        UIActivityIndicatorView *activityIndicator = nil;
        if (showActivityIndicator) {
            activityIndicator = [[UIActivityIndicatorView alloc] init];
            activityIndicator.tintColor = [UIColor blackColor];
            activityIndicator.frame = self.bounds;
            activityIndicator.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight; //it's interesting that if auto layout didn't exist we would have to keep instance of activity indicator so we could alter its frame as necessary, which would require storage that categories don't provide
            [activityIndicator startAnimating];
            [self addSubview:activityIndicator];
        }

        [file pk_getImageWithBlock:^ (UIImage *image) {
            if (adjustment) {
                image = adjustment(image);
            }

            setter(image);

            [activityIndicator stopAnimating]; // May not exist, but that doesn't matter
        }];
    }
}

@end

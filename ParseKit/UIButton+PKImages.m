//
//  UIButton+PKImages.m
//  ParseKit
//
//  Created by Ashkon Farhangi on 2/25/14.
//  Copyright (c) 2014 Ashkon Farhangi. All rights reserved.
//

#import "UIButton+PKImages.h"

#import "UIView+_PKPrivate.h"

@implementation UIButton (PPImages)


- (void)pk_setImageWithFile:(PFFile *)file
{
    [self pk_setImageWithFile:file showActivityIndicator:NO];
}

- (void)pk_setImageWithFile:(PFFile *)file showActivityIndicator:(BOOL)showActivityIndicator
{
    [self pk_setImageWithFile:file adjustment:nil showActivityIndicator:showActivityIndicator];
}

- (void)pk_setImageWithFile:(PFFile *)file adjustment:(UIImage * (^)(UIImage *image))adjustment showActivityIndicator:(BOOL)showActivityIndicator
{
    [self pk_setImageWithFile:file adjustment:adjustment showActivityIndicator:showActivityIndicator setter:^ (UIImage *image) {
        [self setBackgroundImage:image forState:UIControlStateNormal];
    }];
}

@end

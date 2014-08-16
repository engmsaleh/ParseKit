//
//  UIView+_PPPrivate.h
//  ParseKit
//
//  Created by Ashkon Farhangi on 2/25/14.
//  Copyright (c) 2014 Ashkon Farhangi. All rights reserved.
//

#import <Parse/Parse.h>

@interface UIView (_PPPrivate)

- (void)pk_setImageWithFile:(PFFile *)file adjustment:(UIImage * (^)(UIImage *image))adjustment showActivityIndicator:(BOOL)showActivityIndicator setter:(void (^)(UIImage *image))setter;

@end

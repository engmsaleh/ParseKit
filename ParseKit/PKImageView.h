//
//  PKImageView.h
//  ParseKit
//
//  Created by Ashkon Farhangi on 2/25/14.
//  Copyright (c) 2014 Ashkon Farhangi. All rights reserved.
//

@class PFFile;

@interface PKImageView : UIImageView

@property (nonatomic) PFFile *imageFile;

- (void)setImageWithFile:(PFFile *)file placeholder:(UIImage *)placeholder;

@end

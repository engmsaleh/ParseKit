//
//  UIImage+PKUtilities.m
//  ParseKit
//
//  Created by Ashkon Farhangi on 2/25/14.
//  Copyright (c) 2014 Ashkon Farhangi. All rights reserved.
//

#import "UIImage+PKUtilities.h"

#import "ParseConstants.h"

@implementation UIImage (PKUtilities)

- (UIImage *)pk_imageFittingInFile
{
    UIImage *imageFittingInFile = self;

    NSUInteger imageSize = [UIImagePNGRepresentation(self) length];
    if (imageSize > PARSE_FILE_MAXIMUM_SIZE_IN_BYTES) {
        return [self pk_shrinkToSize:PARSE_FILE_MAXIMUM_SIZE_IN_BYTES];
    }

    return imageFittingInFile;
}

/**
 * Taken from:
 * https://stackoverflow.com/questions/20458558/change-nsdata-size-of-a-uiimage-compress-and-resize-uiimage-with-a-maximum-meg 
 * Slightly modified to improve style and readibility.
 */
- (UIImage *)pk_shrinkToSize:(NSUInteger)size
{
    float compressionVal = 1.0;
    float maxMegaBytes = size * 2^20;

    UIImage *compressedImage = self;

    int iterations = 0;
    int totalIterations = 0;

    float initialCompressionVal = 0.0;

    while ((((float)UIImageJPEGRepresentation(compressedImage, compressionVal).length) / 1048576.0) > maxMegaBytes && totalIterations < 1024) {

        compressionVal = ((compressionVal + (compressionVal * ((float)((float)maxMegaBytes / ((float)(((float)(UIImageJPEGRepresentation(compressedImage, compressionVal).length))/ 1048576.0)))))) / 2);
        compressionVal *= 0.97;//subtracts 3% of it's current value just incase above algorithm limits at just above maxMegaBytes and while loop becomes infinite.

        if (initialCompressionVal == 0.0) {
            initialCompressionVal = compressionVal;
        }

        iterations ++;

        if (iterations >= 3 || compressionVal < 0.1) {
            iterations = 0;

            compressionVal = 1.0;


            compressedImage = [UIImage imageWithData:UIImageJPEGRepresentation(compressedImage, compressionVal)];



            float resizeAmount = 1.0;
            resizeAmount = resizeAmount+initialCompressionVal / 2; // percentage
            resizeAmount *= 0.97; // 3% boost just incase image compression algorithm reaches a limit.
            resizeAmount = 1 / resizeAmount;
            initialCompressionVal = 0.0;


            UIView *imageHolder = [[UIView alloc] initWithFrame:CGRectMake(0,0,(int)floorf((float)(compressedImage.size.width/(resizeAmount))), (int)floorf((float)(compressedImage.size.height/(resizeAmount))))]; // round down to ensure frame isnt larger than image itself

            UIImageView *theResizedImage = [[UIImageView alloc] initWithFrame:CGRectMake(0,0,(int)ceilf((float)(compressedImage.size.width/(resizeAmount))), (int)ceilf((float)(compressedImage.size.height/(resizeAmount))))]; // round up to ensure image fits
            theResizedImage.image = compressedImage;


            [imageHolder addSubview:theResizedImage];


            UIGraphicsBeginImageContextWithOptions(CGSizeMake(imageHolder.frame.size.width, imageHolder.frame.size.height), YES, 1.0);
            CGContextRef resize_context = UIGraphicsGetCurrentContext();
            [imageHolder.layer renderInContext:resize_context];
            compressedImage = UIGraphicsGetImageFromCurrentImageContext();
            UIGraphicsEndImageContext();


            // after 3 compressions, if we still haven't shrunk down to maxMegaBytes size, apply the maximum compression we can, then resize the image (90%?), then re-start the process, this time compressing the compressed version of the image we were checking.
        }

        totalIterations ++;

    }

    if (totalIterations < 1024) {
        NSData *imageData = UIImageJPEGRepresentation(compressedImage, compressionVal);
        return [UIImage imageWithData:imageData];
    }

    return nil;
}

@end


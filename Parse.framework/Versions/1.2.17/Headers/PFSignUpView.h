//
//  PFLogInView.h
//  Parse
//
//  Created by Qian Wang on 3/9/12.
//  Copyright (c) 2012. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum {
    PFSignUpFieldsUsernameAndPassword = 0,
    PFSignUpFieldsEmail = 1 << 0,
    PFSignUpFieldsAdditional = 1 << 1, // this field can be used for something else
    PFSignUpFieldsSignUpButton = 1 << 2,
    PFSignUpFieldsDismissButton = 1 << 3,
    PFSignUpFieldsDefault = PFSignUpFieldsUsernameAndPassword | PFSignUpFieldsEmail | PFSignUpFieldsSignUpButton | PFSignUpFieldsDismissButton
} PFSignUpFields;

/*!
 The class provides a standard sign up interface for authenticating a PFUser.
 */
@interface PFSignUpView : UIScrollView

/*! @name Creating Sign Up View */
/*!
 Initializes the view with the specified sign up elements.
 @param fields A bitmask specifying the sign up elements which are enabled in the view
 */
- (id)initWithFields:(PFSignUpFields) fields;

@property (nonatomic, retain) UIViewController *presentingViewController;

/*! @name Customizing the Logo */

@property (nonatomic, retain) UIView *logo;

/*! @name Accessing Sign Up Elements */

@property (nonatomic, readonly, assign) PFSignUpFields fields;

@property (nonatomic, readonly, retain) UITextField *usernameField;

@property (nonatomic, readonly, retain) UITextField *passwordField;

@property (nonatomic, readonly, retain) UITextField *emailField;

@property (nonatomic, readonly, retain) UITextField *additionalField;

@property (nonatomic, readonly, retain) UIButton *signUpButton;

@property (nonatomic, readonly, retain) UIButton *dismissButton;
@end



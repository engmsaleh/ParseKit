//
//  PFLogInView.h
//  Parse
//
//  Created by Qian Wang on 3/9/12.
//  Copyright (c) 2012. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum {
    PFLogInFieldsNone = 0,
    PFLogInFieldsUsernameAndPassword = 1 << 0,
    PFLogInFieldsPasswordForgotten = 1 << 1,
    PFLogInFieldsLogInButton = 1 << 2,
    PFLogInFieldsFacebook = 1 << 3,
    PFLogInFieldsTwitter = 1 << 4,
    PFLogInFieldsSignUpButton = 1 << 5,
    PFLogInFieldsDismissButton = 1 << 6,
    
    PFLogInFieldsDefault = PFLogInFieldsUsernameAndPassword | PFLogInFieldsLogInButton | PFLogInFieldsSignUpButton | PFLogInFieldsPasswordForgotten | PFLogInFieldsDismissButton
} PFLogInFields;

/*!
 The class provides a standard log in interface for authenticating a PFUser.
 */
@interface PFLogInView : UIView

/*! @name Creating Log In View */
/*!
 Initializes the view with the specified log in elements.
 @param fields A bitmask specifying the log in elements which are enabled in the view
 */
- (id)initWithFields:(PFLogInFields) fields;

@property (nonatomic, retain) UIViewController *presentingViewController;

/*! @name Customizing the Logo */

@property (nonatomic, retain) UIView *logo;

/*! @name Accessing Log In Elements */

@property (nonatomic, readonly, assign) PFLogInFields fields;

@property (nonatomic, readonly, retain) UITextField *usernameField;

@property (nonatomic, readonly, retain) UITextField *passwordField;

@property (nonatomic, readonly, retain) UIButton *passwordForgottenButton;

@property (nonatomic, readonly, retain) UIButton *logInButton;

@property (nonatomic, readonly, retain) UIButton *facebookButton;

@property (nonatomic, readonly, retain) UIButton *twitterButton;

@property (nonatomic, readonly, retain) UIButton *signUpButton;

@property (nonatomic, readonly, retain) UIButton *dismissButton;

@property (nonatomic, readonly, retain) UILabel *externalLogInLabel;

@property (nonatomic, readonly, retain) UILabel *signUpLabel;

@end



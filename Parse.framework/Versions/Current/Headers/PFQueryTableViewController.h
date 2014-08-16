//
//  PFUITableViewController.h
//  Posse
//
//  Created by James Yu on 11/20/11.
//  Copyright (c) 2011 Parse Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PFQuery.h"
#import "PFTableViewCell.h"
#import "PF_EGORefreshTableHeaderView.h"

@interface PFQueryTableViewController : UITableViewController <UITableViewDataSource, UITableViewDelegate, PF_EGORefreshTableHeaderDelegate>

/*! @name Creating a PFQueryTableViewController */

/*! 
 The designated initializer.
 Initializes with a class name of the PFObjects that will be associated with this table.
 @param style The UITableViewStyle for the table
 @param aClassName The class name of the PFObjects that this table will display
 @result The initialized PFQueryTableViewController
 */
- (id)initWithStyle:(UITableViewStyle)style className:(NSString *)aClassName;

/*! 
 Initializes with a class name of the PFObjects that will be associated with this table.
 @param aClassName The class name of the PFObjects that this table will display
 @result The initialized PFQueryTableViewController
 */
- (id)initWithClassName:(NSString *)aClassName;

/*! @name Configuring Behavior */

@property (nonatomic, retain) NSString *parseClassName;

@property (nonatomic, retain) NSString *textKey;

@property (nonatomic, retain) NSString *imageKey;

@property (nonatomic, retain) UIImage *placeholderImage;

@property (nonatomic, assign) BOOL loadingViewEnabled;

@property (nonatomic, assign) BOOL pullToRefreshEnabled;

@property (nonatomic, assign) BOOL paginationEnabled;

@property (nonatomic, assign) NSUInteger objectsPerPage;

@property (nonatomic, assign) BOOL isLoading;

/*! @name Responding to Events */

/*! 
 Called when objects have loaded from Parse. If you override this method, you must
 call [super objectsDidLoad:] in your implementation.
 @param error The Parse error from running the PFQuery, if there was any.
*/
- (void)objectsDidLoad:(NSError *)error;

/*! 
 Called when objects will loaded from Parse. If you override this method, you must
 call [super objectsWillLoad] in your implementation.
*/
- (void)objectsWillLoad;

/*! @name Accessing Results */

@property (nonatomic, retain, readonly) NSArray *objects;

/*!
 Returns an object at a particular indexPath. The default impementation returns
 the object at indexPath.row. If you want to return objects in a different
 indexPath order, like for sections, override this method.
 @param     indexPath   The indexPath
 @result    The object at the specified index
*/
- (PFObject *)objectAtIndexPath:(NSIndexPath *)indexPath;

/*! @name Querying */

/*!
 Override to construct your own custom PFQuery to get the objects.
 @result PFQuery that loadObjects will use to the objects for this table.
*/
- (PFQuery *)queryForTable;

/*!
 Clears the table of all objects.
*/
- (void)clear;

/*! 
 Clears the table and loads the first page of objects.
 */
- (void)loadObjects;

/*! 
 Loads the objects of the className at the specified page and appends it to the
 objects already loaded and refreshes the table.
 @param     page    The page of objects to load.
 @param     clear   Whether to clear the table after receiving the objects.
 */
- (void)loadObjects:(NSInteger)page clear:(BOOL)clear;

/*! 
 Loads the next page of objects, appends to table, and refreshes.
 */
- (void)loadNextPage;

/*! @name Data Source Methods */

/*!
 Override this method to customize each cell given a PFObject that is loaded. If you
 don't override this method, it will use a default style cell and display either
 the first data key from the object, or it will display the key as specified
 with keyToDisplay.
 
 The cell should inherit from PFTableViewCell which is a subclass of UITableViewCell.
 
 @param tableView   The table view object associated with this controller.
 @param indexPath   The indexPath of the cell.
 @param object      The PFObject that is associated with the cell.
 @result            The cell that represents this object.
*/
- (PFTableViewCell *)tableView:(UITableView *)tableView
         cellForRowAtIndexPath:(NSIndexPath *)indexPath
                        object:(PFObject *)object;

/*! 
 Override this method to customize the cell that allows the user to load the 
 next page when pagination is turned on.
 @param tableView   The table view object associated with this controller.
 @param indexPath   The indexPath of the cell.
 @result            The cell that allows the user to paginate.
 */
- (PFTableViewCell *)tableView:(UITableView *)tableView cellForNextPageAtIndexPath:(NSIndexPath *)indexPath;


@end

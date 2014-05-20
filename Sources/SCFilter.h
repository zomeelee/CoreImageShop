//
//  SCFilter.h
//  CoreImageShop
//
//  Created by Simon CORSIN on 16/05/14.
//
//

#import <Foundation/Foundation.h>
#import "SCFilterDescription.h"

@class SCFilter;
@protocol SCFilterDelegate <NSObject>

- (void)filter:(SCFilter *)filter didChangeParameter:(SCFilterParameterDescription *)parameterDescription;
- (void)filterDidResetToDefaults:(SCFilter *)filter;

@end

@interface SCFilter : NSObject

@property (weak, nonatomic) id<SCFilterDelegate> delegate;
@property (readonly, nonatomic) CIFilter *coreImageFilter;
@property (readonly, nonatomic) SCFilterDescription *filterDescription;
@property (assign, nonatomic) BOOL enabled;

+ (SCFilter *)filterWithFilterDescription:(SCFilterDescription *)filterDescription;
- (id)initWithFilterDescription:(SCFilterDescription *)filterDescription;

- (id)parameterValueForParameterDescription:(SCFilterParameterDescription *)parameterDescription;

- (void)setParameterValue:(id)value forParameterDescription:(SCFilterParameterDescription *)parameterDescription;

- (void)resetToDefaults;

@end

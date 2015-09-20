//
//  SKLabelNodePlus.h
//
//  Created by Max Kargin on 8/10/15.
//  Copyright (c) 2014 Max Kargin. All rights reserved.
//

#import <SpriteKit/SpriteKit.h>

@interface SKLabelNodePlus : SKSpriteNode

+ (instancetype)labelNodeWithFontNamed:(NSString *)fontName;
+ (instancetype)labelNodeWithText:(NSString *)text;
- (instancetype)initWithFontNamed:(NSString *)fontName;

- (void)drawLabel;

@property (nonatomic, strong) NSString *text;
@property (nonatomic, strong) SKColor *fontColor;
@property (nonatomic, strong) NSString *fontName;
@property (nonatomic, setter=setHorizontalAlignment:) SKLabelHorizontalAlignmentMode horizontalAlignmentMode;
@property (nonatomic, setter=setVerticalAlignnment:) SKLabelVerticalAlignmentMode verticalAlignmentMode;
@property (nonatomic) NSInteger lineSpacing;
@property (nonatomic, strong) NSShadow *shadow;
@property (nonatomic) NSTextAlignment textAlignmentMode;
@property (nonatomic) CGFloat fontSize;
@property (nonatomic) NSInteger labelWidth;

@end

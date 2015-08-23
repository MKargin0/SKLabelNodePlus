# SKLabelNodePlus
**version 1.1** This is the repo of the official [SKAToolKit](https://github.com/SpriteKitAlliance/SKAToolKit) label node.
<br><br>
###The Original SKLabelNode
The traditional `SKLabelNode` poses many limitations and over the years Sprite Kit developpers have been forced to employ clever hacks to use even the most basic effects with text in their applications. For instance, to have multiple lines of text, one would use a label node for each line. To have shadows, developpers would initialize a second label node to offset their original. As for setting the anchor point of a label, there simply was no way beyond the limitations of the alignment modes.

**The SKLabelNodePlus does away with these limitations.**
###Tecnical Details
**Important:** You must call the label's `drawLabel` method whenever you want to display or update the label.
<br>This is related the label's design, which is optimized for performance by using draws to display the label's text.
<br>An initialization will always look similar to:
````
SKLabelNodePlus *label;
//perform initialization and setup
[label drawLabel];
[self addChild:label];
````
Another thing to keep in mind is that although you will see all methods and properties of `SKLabelNode`, the class `SKLabelNodePlus` actually inherits from `SKSpriteNode`, thus giving you access to all the methods and properties of sprite nodes as well. 

##Functionality

###multi-line labels
With the `SKLabelNodePlus` you can now use multi-line text within Sprite Kit. Simply write a newline character "\n" every time you need a new line of text.
````
SKLabelNodePlus *multiLineLabelNode = [SKLabelNodePlus labelNodeWithText:@"SpriteKit\nMultiLine\nLabel!!!"];

multiLineLabelNode.position = CGPointMake(CGRectGetMidX(self.frame), CGRectGetMidY(self.frame));
multiLineLabelNode.fontSize = 20;
[multiLineLabelNode drawLabel];
[self addChild:multiLineLabelNode];
````
####line spacing
Use the `lineSpacing` property to control distance between lines.
````
multiLineLabelNode.lineSpacing = 10;
````
####text alignment
The properties `verticalAlignmentMode` and `horizontalAlignmentMode` from `SKLabelNode` retain their functionality. These **will not** align multi-line text, as they only give general adjustments to the `anchorPoint`. Instead, use the new `SKLabelNodePlus` property `textAlignmentMode`, which takes values of the type `NSTextAlignment`.
<br><br>The possible values are: `NSTextAlignmentLeft`, `NSTextAlignmentRight`, `NSTextAlignmentCenter`, `NSTextAlignmentJustified`, and `NSTextAlignmentNatural`

For example
````
multiLineLabelNode.textAlignmentMode = NSTextAlignmentRight;
````

###Text Shadows
You can create text with a shadow using `SKLabelNodePlus`. Simply use Apple's existing `NSShadow` class and set the `shadow` property on your label likewise:
````
NSShadow *myShadow = [NSShadow new];
[myShadow setShadowColor:[UIColor redColor]];
[myShadow setShadowBlurRadius:3.0];
[myShadow setShadowOffset:CGSizeMake(1, 1)];

SKLabelNodePlus *shadowLabelNode = [SKLabelNodePlus labelNodeWithText:@"shadow\nlabel"];
shadowLabelNode.position = CGPointMake(CGRectGetMidX(self.frame), CGRectGetMidY(self.frame));
shadowLabelNode.fontName = @"Futura-Medium";
shadowLabelNode.fontSize = 35;
shadowLabelNode.shadow = myShadow;
[shadowLabelNode drawLabel];
[self addChild:shadowLabelNode];
````
###Sprite Node versatility
Because `SKLabelNodePlus` is a subclass of `SKSpriteNode`, your label will have its own methods and parameters while retaining the versatility of the sprite node. This gives you *complete freedom and control* over your text and special effects.
####anchor point
You can set the anchor point however you choose with the `anchorPoint` property
####textures and actions
The text of the label itself is a texture, so you can perform any actions that are possible with a sprite node.
<br>Example:
````
SKLabelNodePlus *effectLabel = [SKLabelNodePlus labelNodeWithText:@"Le Happy Face"];
  effectLabel.position = CGPointMake(CGRectGetMidX(self.frame), CGRectGetMidY(self.frame));
  effectLabel.fontSize = 35;
  [effectLabel drawLabel];
  [self addChild:effectLabel];
  
  SKTexture *labelTexture = effectLabel.texture;
  SKTexture *faceTexture = [SKTexture textureWithImageNamed:@"LeHappyFace"];
  SKAction *changeToFace = [SKAction runBlock:^{
    effectLabel.xScale = 0.5;
      effectLabel.yScale = 2.0;
      effectLabel.anchorPoint = CGPointMake(0.5, 0.3);
      effectLabel.texture = faceTexture;
  }];
  SKAction *changeToLabel = [SKAction runBlock:^{
      [effectLabel setScale:1.0];
      effectLabel.anchorPoint = CGPointMake(0.5, 0);
      effectLabel.texture = labelTexture;
  }];
  SKAction *keepblinking = [SKAction repeatActionForever:[SKAction sequence:@[changeToFace, [SKAction waitForDuration:0.8],changeToLabel,[SKAction waitForDuration:0.8]]]];
  [effectLabel runAction:keepblinking];
````
####lighting
The `SKLabelNodePlus` can also be combined with an `SKLightNode` by using sprite node bitmasks.
<br>Example:
````
SKLabelNodePlus *lightLabel = [SKLabelNodePlus labelNodeWithText:@"Example Lighted Node"];
lightLabel.position = CGPointMake(CGRectGetMidX(self.frame), CGRectGetMidY(self.frame));
lightLabel.fontName = @"Futura-CondensedExtraBold";
lightLabel.fontSize = 35;
lightLabel.lightingBitMask = 1;
lightLabel.alpha = 0.5;
[lightLabel drawLabel];
[self addChild:lightLabel];
 
SKLightNode *lightNode = [SKLightNode new];
lightNode.categoryBitMask = 1;
lightNode.falloff = 0.5;
lightNode.ambientColor = [UIColor whiteColor];
lightNode.lightColor = [[UIColor alloc] initWithRed:1.0 green:0.7 blue:0 alpha:1];
lightNode.position = CGPointMake(30, 0);
lightNode.enabled = YES;
[lightLabel addChild:lightNode];
````
####custom shaders
Custom shaders are compatible with `SKLabelNodePlus`. Use your own shaders with your label nodes!
##Using SKLabelNodePlus
###CocoaPods
coming soon to cocoa pods...
###Manually importing
Download this repo and add inside of your XCode project the SKLabelNodePlus.h and SKLabelNodePlus.m files using file > addFiles
#####For Objective-C:
Whenever you need to use the label node, simply import at the beginning of the file: `#import "SKLabelNodePlus.h"`
#####For Swift:
If after adding the label node implementation and header files XCode prompts to create a bridging header file, click to create and you will be able to use the `SKLabelNodePlus` class everywhere in your project. Make sure that inside of the bridging header there is the import statement `#import "SKLabelNodePlus.h"`.
<br>If XCode does not automatically create the bridging header, then to manually create it go to file > new > file. Choose to create a header file. Name this file however you would like but make sure to add the phrase `-Bridging-Header` at the end of the name. After creating, add inside of the file the import statement `#import "SKLabelNodePlus.h"`. Then, go to the project settings by clicking on the project name in the left hand project file navigation bar. In Project search in Build Settings for Bridging Header. If you aren't seeing it, make sure you are searching in the All tab and not Basic. Then, double click next to the Objective-C Bridging Header and type in the location of your Bridging Header in the project tree. For example, if you project is named sampleProject and you added the header "sampleHeader-Bridging-Header.h" inside of the main project folder, you would type "sampleProject/sampleHeader-Bridging-Header.h".
You will now be able to use `SKLabelNodePlus` in your Swift project.
##Contact
If you have any questions, suggestions, or just comments, feel free to email me at maksym.kargin@gmail.com

##Licence
The MIT License (MIT)

Copyright (c) 2015 Max Kargin

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

//
//  YYPMainViewController.h
//  YYPAuthSDK
//
//  Created by yangyuanpeng on 2019/4/29.
//  Copyright © 2019 yyp. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RootViewController.h"
typedef void (^AuthBlock)(NSString *result);

NS_ASSUME_NONNULL_BEGIN

@interface YYPMainViewController : RootViewController
@property (nonatomic, strong) UIViewController *delegate;
@property (nonatomic, copy) AuthBlock renlianBlock;

- (void)goCertificationBasicInfo:(AuthBlock)block;
- (void)phoneAuthentication:(AuthBlock)block;
- (void)bankCardAuthentication;
- (void)taoBaoAuthentication;

- (void)goRenlianshibie:(AuthBlock)block;
- (void)goBank:(AuthBlock)block;
- (void)goXYPhoneAuth:(AuthBlock)block;
@end

NS_ASSUME_NONNULL_END

//
//  LaunchView.h
//  LaunchView
//
//  Created by MOYO on 2019/7/18.
//  Copyright © 2019年 MOYO. All rights reserved.
//

#import <UIKit/UIKit.h>

static NSString *adImageName = @"adLaunchImage";
#define PATH_DIRECTORY [[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0]stringByAppendingPathComponent:adImageName]


@interface LaunchView : UIView
//图片链接
@property(nonatomic,copy)NSString *imageUrl;

//展示图片
-(void)show;

-(void)downLoadAndSaveImage;


@end



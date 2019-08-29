//
//  TheGlobalMethod.h
//  FamilyTreasure
//
//  Created by apple on 16/4/12.
//  Copyright © 2016年 wypMIFAN. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

//获取当前设备的宽、高
#define WIDTH_K [[UIScreen mainScreen] bounds].size.width
#define HEIGHT_K [[UIScreen mainScreen] bounds].size.height

#define KBackGroudColor NAVCOLOR_C(244.0, 244.0, 244.0)

//设置RGB
#define NAVCOLOR_C(_RED_,_GREEN_,_BLUE_) [UIColor colorWithRed:(_RED_)/255.0 green:(_GREEN_)/255.0 blue:(_BLUE_)/255.0 alpha:1]

#define NAVCOLOR_A(_RED_,_GREEN_,_BLUE_,_ALPHA_) [UIColor colorWithRed:(_RED_)/255.0 green:(_GREEN_)/255.0 blue:(_BLUE_)/255.0 alpha:_ALPHA_]

//右划返回
#define kPop if ([self.navigationController respondsToSelector:@selector(interactivePopGestureRecognizer)]) { self.navigationController.interactivePopGestureRecognizer.delegate = nil; }

#define kNavPop [self.navigationController popViewControllerAnimated:YES];//返回

#define kWidth [UIScreen mainScreen].bounds.size.width//屏幕宽
#define kHeight [UIScreen mainScreen].bounds.size.height//屏幕高
#define kSp kWidth/375 //适配

//tableView代理
#define kTableViewDelegateData <UITableViewDelegate, UITableViewDataSource>

#define KClearColor [UIColor clearColor]//透明色


#define K333Color [UIColor colorWithRed:66.0/255 green:66.0/255 blue:66.0/255 alpha:1]
#define K666Color [UIColor colorWithRed:121.0/255 green:121.0/255 blue:121.0/255 alpha:1]
#define K999Color [UIColor colorWithRed:169.0/255 green:169.0/255 blue:169.0/255 alpha:1]


//#pragma mark tableViewCell
//#define loadingCell(_CellName_) *cell = [tableView dequeueReusableCellWithIdentifier:@(_CellName_)];\
//cell.selectionStyle=UITableViewCellSelectionStyleNone;\
//if (cell == nil) {\
//cell= [[[NSBundle mainBundle]loadNibNamed:@(_CellName_) owner:self options:nil]objectAtIndex:0];\
//cell.selectionStyle=UITableViewCellSelectionStyleNone;\
//}

#define loadingTableViewCell(_CellName_, pieceCode) *cell = [tableView dequeueReusableCellWithIdentifier:[NSString stringWithFormat:@"%ld,%ld",(long)indexPath.section,(long)indexPath.row]];\
cell.selectionStyle=UITableViewCellSelectionStyleNone;\
if (cell == nil) {\
[tableView registerNib:[UINib nibWithNibName:@(_CellName_) bundle:SDK_BUNDLE] forCellReuseIdentifier:[NSString stringWithFormat:@"%ld,%ld",(long)indexPath.section,(long)indexPath.row]];\
cell = [tableView dequeueReusableCellWithIdentifier:[NSString stringWithFormat:@"%ld,%ld",(long)indexPath.section,(long)indexPath.row]];\
cell.selectionStyle=UITableViewCellSelectionStyleNone;\
pieceCode;\
}

#define loadingCell(_CellName_) *cell = [tableView dequeueReusableCellWithIdentifier:[NSString stringWithFormat:@"%ld,%ld",(long)indexPath.section,(long)indexPath.row]]; \
cell.selectionStyle=UITableViewCellSelectionStyleNone; \
if (cell == nil) { \
    [tableView registerClass:_CellName_ forCellReuseIdentifier:[NSString stringWithFormat:@"%ld,%ld",(long)indexPath.section,(long)indexPath.row]]; \
    cell = [tableView dequeueReusableCellWithIdentifier:[NSString stringWithFormat:@"%ld,%ld",(long)indexPath.section,(long)indexPath.row]]; \
    cell.selectionStyle=UITableViewCellSelectionStyleNone; \
}


//#define loadingCell(_CellName_) *cell = [tableView dequeueReusableCellWithIdentifier:@"cellID"];\
//cell.selectionStyle=UITableViewCellSelectionStyleNone;\
//if (cell == nil) {\
//[tableView registerNib:[UINib nibWithNibName:@(_CellName_) bundle:nil] forCellReuseIdentifier:@"cellID"];\
//cell = [tableView dequeueReusableCellWithIdentifier:@"cellID"];\
//}


#pragma mark collectionViewCell
#define loadingCollectionCell(_CellName_)  *cell = [collectionView dequeueReusableCellWithReuseIdentifier:@"cellID" forIndexPath:indexPath];\
if (cell == nil) {\
[collectionView registerNib:[UINib nibWithNibName:@(_CellName_) bundle:nil] forCellWithReuseIdentifier:@"cellID"];\
cell = [collectionView dequeueReusableCellWithReuseIdentifier:@"cellID" forIndexPath:indexPath];\
}

#define loadingTCell(_CellName_, pieceCode)  *cell = [tableView dequeueReusableCellWithReuseIdentifier:@"cellID" forIndexPath:indexPath];\
if (cell == nil) {\
[tableView registerNib:[UINib nibWithNibName:@(_CellName_) bundle:nil] forCellWithReuseIdentifier:@"cellID"];\
cell = [tableView dequeueReusableCellWithReuseIdentifier:@"cellID" forIndexPath:indexPath];\
pieceCode;\
}



typedef void (^SelectAlertViewBlock)();

@interface TheGlobalMethod : NSObject


+ (TheGlobalMethod *)main;//单例
@property (nonatomic, strong) NSString *pushString;
@property (nonatomic, strong) UIColor *appColor;

/// 获取手机型号名称
+ (NSString *)deviceModelName;

/// 获取总储存大小
+ (long long)getTotalDiskSize;
/// 获取可以存储大小
+ (long long)getAvailableDiskSize;
/// 获取内存大小
+ (long long)getTotalMemorySize;
/// KB - MB - GB
+ (NSString *)fileSizeToString:(unsigned long long)fileSize;
/// 是否越狱
+ (BOOL)isJailBreak;

//注册cell
+ (id)setCell:(NSString *)cellName;

//注册storyboard
+ (id)setstoryboard:(NSString *)vcName controller:(UIViewController *)vc;

//时间戳转换字符串
+ (NSString *)dateStr:(NSString *)str666;

+ (NSString *)dateStrss:(NSString *)str666;


+ (NSString *)dateWithStr:(NSString *)string Format:(NSString *)Format;
+ (NSString *)timeStamp:(NSString *)str;

// 获取
+ (id)getUserDefault:(NSString *)userMessage;
// 插入
+ (void)insertUserDefault:(id)userMessage Key:(NSString *)key;
// 删除
+ (void)removeObjectForKey:(NSString *)key;


/** 挑战到登录界面 */
+ (void)popToLoginAlertView:(NSString *)xinxiStr controller:(UIViewController *)controller;

/** 显示系统提示框 */
+ (void)xianShiAlertView:(NSString *)xinXiStr controller:(UIViewController *)controller;
/** 显示点击pop界面提示框 */
+ (void)popAlertView:(NSString *)xinxiStr controller:(UIViewController *)controller;
+ (void)popAlertView2:(NSString *)xinxiStr controller:(UIViewController *)controller;

/** 显示选择事件提示框 */
+ (void)selectAlertView:(NSString *)xinXiStr controller:(UIViewController *)controller select:(SelectAlertViewBlock)block;
/** 显示window提示框 */
+ (void)InWindowAlertView:(NSString *)xinXiStr;

/** 弹簧效果 */
+ (void)SpringAnimation:(UIView *)Controls;
/** 上下动画 */
+ (void)SprTopBottom:(UIView *)Controls value:(CGFloat)value;
/** 展示信息在window */
+ (BOOL)showMessageReturn:(id)Controls text:(NSString *)text vc:(UIViewController *)vc;
/** 根据一个时间戳获取距离当前时间的间隔 */
+ (NSString *)distanceTimeWithBeforeTime:(double)beTime;
//展示center view
+ (void)showMessage:(NSString *)message alpha:(CGFloat)alphaValue time:(CGFloat)time;


@end

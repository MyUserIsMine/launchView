//
//  HttpUrl.h
//  BS
//
//  Created by ike on 16/7/15.
//  Copyright © 2016年 mc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface HttpUrl : NSObject


//传值 POST请求
+ (void)POST:(NSString *)httpUrl dict:(id)dict hud:(UIView *)hud vc:(UIViewController *)vc isShow:(BOOL)isShow WithSuccessBlock:(void(^)(id data))successBlock failureBlock:(void(^)(NSURLSessionDataTask *task, NSError *error))failureBlock;

+ (void)POSTPing:(NSString *)httpUrl dict:(id)dict hud:(UIView *)hud vc:(UIViewController *)vc isShow:(BOOL)isShow WithSuccessBlock:(void(^)(id data))successBlock failureBlock:(void (^)(NSURLSessionDataTask *, NSError *))failureBlock;

//GET请求
// 适应老版本
+ (void)GET:(NSString *)httpUrl dict:(id)dict hud:(UIView *)hud isShow:(BOOL)isShow WithSuccessBlock:(void(^)(id data))successBlock;

//GET请求

+ (void)GET:(NSString *)httpUrl dict:(id)dict hud:(UIView *)hud vc:(UIViewController *)vc isShow:(BOOL)isShow WithSuccessBlock:(void(^)(id data))successBlock failureBlock:(void(^)(NSURLSessionDataTask *task, NSError *error))failureBlock;


//个别网络加载失败POST处理
+ (void)NetErrorPOST:(NSString *)httpUrl dict:(id)dict hud:(UIView *)hud isShow:(BOOL)isShow WithSuccessBlock:(void(^)(id data))successBlock WithFailBlock:(void(^)(id data))FailBlock;
//个别网络加载失败GET处理
+ (void)NetErrorGET:(NSString *)httpUrl dict:(NSDictionary*)dict hud:(UIView *)hud isShow:(BOOL)isShow WithSuccessBlock:(void(^)(id data))successBlock WithFailBlock:(void(^)(id data))FailBlock;

+ (void)GETRej:(NSString *)httpUrl dict:(id)dict hud:(UIView *)hud isShow:(BOOL)isShow WithSuccessBlock:(void(^)(id data))successBlock ;


#pragma mark 上传图片
+ (void)upLoadImage:(UIImage *)image hud:(UIView *)hud isShow:(BOOL)isShow WithSuccessBlock:(void(^)(id data))successBlock;

#pragma mark 临洮
//临洮
+(void)LTPOST:(NSString *)httpUrl dict:(NSDictionary *)dict WithSuccessBlock:(void(^)(id data))successBlock;
+(void)POST:(NSString *)httpUrl dict:(NSDictionary *)dict sign:(NSString *)sign WithSuccessBlock:(void(^)(id data))successBlock;

@end

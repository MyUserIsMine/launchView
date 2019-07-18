//
//  AppDelegate.m
//  LaunchView
//
//  Created by MOYO on 2019/7/18.
//  Copyright © 2019年 MOYO. All rights reserved.
//

#import "AppDelegate.h"
#import "ViewController.h"
#import "LaunchView.h"
@interface AppDelegate ()

@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    self.window = [[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];

    ViewController *vc = [[ViewController alloc]init];
    self.window.rootViewController = vc;
    [self.window makeKeyAndVisible];

//自己判断是否是第一次启动，就不用那么麻烦了，第一次启动还没有广告图，直接下载就行了
//    BOOL isExist = [self isFileExistWithFilePath:PATH_DIRECTORY];
//    if (isExist) {// 图片存在
        [self.window addSubview:({
            LaunchView *view = [[LaunchView alloc]initWithFrame:self.window.bounds];
            view.backgroundColor = [UIColor redColor];
            view.imageUrl = @"http://5b0988e595225.cdn.sohucs.com/images/20170920/a178a278fdc84b95894cbfbdd4313451.jpeg";
            [view show];
            view;
        })];
//    } else {
//        LaunchView *view = [[LaunchView alloc]init];
//        view.imageUrl = @"http://5b0988e595225.cdn.sohucs.com/images/20170920/a178a278fdc84b95894cbfbdd4313451.jpeg";
//        [view downLoadAndSaveImage];
//    }
    // Override point for customization after application launch.
    return YES;
}

//- (BOOL)isFileExistWithFilePath:(NSString *)filePath
//{
//    NSFileManager *fileManager = [NSFileManager defaultManager];
//    BOOL isDirectory = FALSE;
//    return [fileManager fileExistsAtPath:filePath isDirectory:&isDirectory];
//}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end

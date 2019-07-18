//
//  ViewController.m
//  LaunchView
//
//  Created by MOYO on 2019/7/18.
//  Copyright © 2019年 MOYO. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor lightGrayColor];
    UILabel *label = [[UILabel alloc]initWithFrame:CGRectMake(100, 400, 100, 30)];
    label.text = @"首页";
    label.textAlignment = NSTextAlignmentCenter;
    [self.view addSubview:label];
    // Do any additional setup after loading the view, typically from a nib.
}


@end

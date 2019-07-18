//
//  LaunchView.m
//  LaunchView
//
//  Created by MOYO on 2019/7/18.
//  Copyright © 2019年 MOYO. All rights reserved.
//

#import "LaunchView.h"
#import <QuartzCore/CADisplayLink.h>

#define W_screenWidth [UIScreen mainScreen].bounds.size.width
#define W_screenHeight [UIScreen mainScreen].bounds.size.height
#define W_UserDefaults [NSUserDefaults standardUserDefaults]


static NSInteger showTime = 5;

@interface LaunchView()

@property (nonatomic, strong) UIImageView *adView;

@property (nonatomic, strong) UIButton *countBtn;

@property (nonatomic, strong) NSTimer *countTimer;

@property (nonatomic, assign) NSInteger count;

@property (nonatomic,strong)CADisplayLink *displaylink;
@property (nonatomic,assign)NSInteger showtime;

@end

@implementation LaunchView

-(instancetype)initWithFrame:(CGRect)frame{
    self = [super initWithFrame:frame];
    if (self) {
        
        _showtime = showTime;
        //添加广告图片
        [self addSubview:({
            _adView = [[UIImageView alloc] initWithFrame:frame];
            _adView.userInteractionEnabled = YES;
            _adView.contentMode = UIViewContentModeScaleAspectFill;
            _adView.clipsToBounds = YES;
            UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(pushToAd)];
            [_adView addGestureRecognizer:tap];
            _adView;
        })];
        //添加按钮
        [self addSubview:({
            CGFloat btnW = 50;
            CGFloat btnH = 50;
            _countBtn = [[UIButton alloc] initWithFrame:CGRectMake(W_screenWidth - btnW - 24, btnH, btnW, btnH)];
            [_countBtn addTarget:self action:@selector(dismiss) forControlEvents:UIControlEventTouchUpInside];
            [_countBtn setTitle:[NSString stringWithFormat:@"%ld", _showtime] forState:UIControlStateNormal];
            _countBtn.titleLabel.font = [UIFont systemFontOfSize:15];
            [_countBtn setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
            _countBtn.backgroundColor = [UIColor colorWithRed:38 /255.0 green:38 /255.0 blue:38 /255.0 alpha:0.6];
            _countBtn.layer.cornerRadius = 4;
            _countBtn;
        })];
       
    }
   
    return self;
}

#pragma mark - 链接赋值，下载
- (void)setImageUrl:(NSString *)imageUrl
{
    _imageUrl = imageUrl;
    NSString *oldUrl = [[NSUserDefaults standardUserDefaults]objectForKey:@"adOldImageUrl"];
    if ([oldUrl isEqualToString:imageUrl]) {
        
    }else{
        //可以判断网络，什么WiFi预加载
        [[NSUserDefaults standardUserDefaults]setObject:imageUrl forKey:@"adOldImageUrl"];
        [self downLoadAndSaveImage];
    }
    _adView.image = [UIImage imageWithContentsOfFile:PATH_DIRECTORY];
    
}


#pragma mark -- display
-(CADisplayLink*)display{
    if (!_displaylink) {
        _displaylink = [CADisplayLink displayLinkWithTarget:self selector:@selector(displayCount)];
    }
    _displaylink.frameInterval = 60;
    _count = _showtime;
    return _displaylink;
}

-(void)displayCount{
    [self.displaylink addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSRunLoopCommonModes];
    _count --;
    [_countBtn setTitle:[NSString stringWithFormat:@"%ld",_count] forState:UIControlStateNormal];
    if (_count == 0) {
        [self.displaylink invalidate];
        self.displaylink = nil;
        [self dismiss];
    }
}


#pragma mark -- timer

- (NSTimer *)countTimer
{
    if (!_countTimer) {
        _countTimer = [NSTimer scheduledTimerWithTimeInterval:1.0 target:self selector:@selector(timeDown) userInfo:nil repeats:YES];
        
    }
    return _countTimer;
}

- (void)startTimer
{
    _count = _showtime;
    [[NSRunLoop mainRunLoop] addTimer:self.countTimer forMode:NSRunLoopCommonModes];
}

- (void)timeDown
{
    _count --;
    [_countBtn setTitle:[NSString stringWithFormat:@"%ld",_count] forState:UIControlStateNormal];
    if (_count == 0) {
        [self.countTimer invalidate];
        self.countTimer = nil;
        [self dismiss];
    }
}



#pragma mark -- GCD
- (void)startCoundown
{
    __block NSInteger timeout = _showtime + 1; //倒计时时间 + 1
    dispatch_queue_t queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
    dispatch_source_t _timer = dispatch_source_create(DISPATCH_SOURCE_TYPE_TIMER, 0, 0,queue);
    dispatch_source_set_timer(_timer,dispatch_walltime(NULL, 0),1.0 * NSEC_PER_SEC, 0); //每秒执行
    dispatch_source_set_event_handler(_timer, ^{
        if(timeout <= 0){ //倒计时结束，关闭
            dispatch_source_cancel(_timer);
            dispatch_async(dispatch_get_main_queue(), ^{
                
                [self dismiss];
                
            });
        }else{
            
            dispatch_async(dispatch_get_main_queue(), ^{
                [self.countBtn setTitle:[NSString stringWithFormat:@"%ld",timeout] forState:UIControlStateNormal];
            });
            timeout--;
        }
    });
    dispatch_resume(_timer);
}


-(void)pushToAd{
    [self dismiss];
    [[NSNotificationCenter defaultCenter]postNotificationName:@"pushToAd" object:nil];
}


-(void)show{
    [self startTimer];

    [[UIApplication sharedApplication].keyWindow addSubview:self];
}


-(void)dismiss{
    [UIView animateWithDuration:0.5 animations:^{
        self.alpha = 0.0;
    } completion:^(BOOL finished) {
        if (finished) {
            [self removeFromSuperview];
        }
    }];
}




-(void)downLoadAndSaveImage{
    if (!_imageUrl) {
        return;
    }
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        UIImage *image = [[UIImage alloc]initWithData:[NSData dataWithContentsOfURL:[NSURL URLWithString:self.imageUrl]]];
       //NSString *filePath = [self getFilePathWithImageName:adImageName];// 保存文件的名称
        if ([UIImagePNGRepresentation(image) writeToFile:PATH_DIRECTORY atomically:YES]) {//保存成功
           // NSLog(@"保存成功");
            [self deleteOldImage];// 保存成功后删除旧图片
            [[NSUserDefaults standardUserDefaults] setValue:adImageName forKey:adImageName];
            [[NSUserDefaults standardUserDefaults] synchronize];
            // 如果有广告链接，需要将广告链接也保存下来
        }else{
            NSLog(@"保存失败");
        }
    });
}



- (void)deleteOldImage
{
    NSString *imageName = [[NSUserDefaults standardUserDefaults] valueForKey:adImageName];
    if (imageName) {
        NSFileManager *fileManager = [NSFileManager defaultManager];
        [fileManager removeItemAtPath:PATH_DIRECTORY error:nil];
    }
}



@end

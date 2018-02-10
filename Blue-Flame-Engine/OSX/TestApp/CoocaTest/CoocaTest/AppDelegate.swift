//
//  AppDelegate.swift
//  CoocaTest
//
//  Created by Mustafa Sibai on 2/10/18.
//  Copyright © 2018 TT. All rights reserved.
//

import Cocoa

@NSApplicationMain
class AppDelegate: NSObject, NSApplicationDelegate {

    @IBOutlet weak var window: NSWindow!

    func Test(inputA : Int, inputB : Int) -> Int{
        return inputB + inputA;
    }
    
    func applicationDidFinishLaunching(_ aNotification: Notification) {
        // Insert code here to initialize your application
        
        let bar = ABCpp();
        var num : Int = Int(bar.addTwoNumbersWrapper(10, toY: 20))
        print("Hello !")
    }

    func applicationWillTerminate(_ aNotification: Notification) {
        // Insert code here to tear down your application
    }


}
